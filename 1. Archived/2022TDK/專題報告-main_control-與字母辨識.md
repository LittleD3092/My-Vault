# 專題報告 - `main_control` 與字母辨識

作者: 吳典謀

---

## `main_control`

[//]: # (node 與其他 node 的連接)

`main_control` 可以說是主要決定機器動作的程式，這個程式會指揮其他程式，決定下一個移動的目的地為何與接下來要做哪些動作。為了做出這些決策，此程式也會詢問其他程式目前的機器狀態與周遭環境。

[//]: # (將每個其他 node 的連接用 class 包裝)

因為 `main_control` 程式需要做到多樣化的功能，並且在開發過程中可能會決定需要與更多程式溝通或者溝通方式可能會變更，因此 `main_control` 需要以可擴展、易修改與腳本式的方法撰寫。為了達成以上三個條件， `main_control` 主要分成了兩個部分。第一個部分是溝通方法，第二個部分是腳本的撰寫。對於溝通方法的部分，每個溝通方法都使用了一個 class 物件來定義，因此只需要建立物件並且呼叫 `request` 函式即可與相對應的 node 溝通。腳本撰寫的部分，我們在 main 中直接呼叫溝通方法的 `request` 函式，因此當要修改時只要修改原始碼 main 中的程式撰寫即可達成。此外，利用這種方法撰寫腳本可以直接利用迴圈，更可以方便的註解測試用的腳本。

以下為使用到的 class 列表與相對應的溝通 node:

| class name          | node                 | 用途                                          |
| ------------------- | -------------------- | --------------------------------------------- |
| `AlphabetRecognize` | `alphabet_recognize` | 回傳鏡頭前的字母、字母牌與鏡頭的距離             |
| `ColorDetect`       | `color_detect`       | 回傳球的顏色、球與鏡頭的距離                    |
| `DotRecognize`      | `dot_recognize`      | 回傳點字相對應的數字、點字牌與鏡頭的距離         |
| `Navigation`        | `navigation`         | 使用 `move` 函式溝通，用參數 `req` 傳遞位置資訊 |
| `UpperMechanism`    | `upper_mechanism`    | 使用 `move` 函式溝通，用餐數 `cmd` 傳遞指令編號 |

以下是比賽時將會使用的腳本:

```python
if __name__ == '__main__':
	#####################################################################################
	# main loop: This is the main loop that will be running on the race.
	
	# go to I
	baseNode.move(POSE_I)

	# take basketball three times
	basketballStack = [] # record the stack of basketballs on the robot
	basketballOptions = ("T", "D", "K") # the options of basketballs
	for i in range(3):
		basketballStack.append(basketballOptions[ballNode.request() - 1])
		upperNode.move(1)
	assert basketballStack.count("T") == 1, "There should be one T in the stack."
	assert basketballStack.count("D") == 1, "There should be one D in the stack."
	assert basketballStack.count("K") == 1, "There should be one K in the stack."
	assert len(basketballStack) == 3, "There should be three basketballs in the stack."

	# go to G
	baseNode.move(POSE_G)

	# throw the basketballs to three baskets marked T, D, K
	for i in range(3):
		baseNode.move(POSE_BASKET[i])
		chr = AlphabetRecognize.request()
		assert type(chr) == str, "The character should be a string."
		assert chr[0] in ('T', 'D', 'K'), "The character should be T, D, or K."
		basketballStack[basketballStack.index(chr)] = i

	for i in range(-1, -4, -1):
		baseNode.move(POSE_BASKET[ basketballStack[i] ])
		upperNode.move(2)


	# go to B (checkpoint)
	baseNode.move(POSE_B)

	# go to J
	baseNode.move(POSE_J)

	# take bowling three times
	for i in range(3):
		upperNode.move(3)

	# go to H
	baseNode.move(POSE_H)

	# release bowling to three goals marked in dot numbers
	dic = {}
	for i in range(6):
		baseNode.move(POSE_GOAL[i])
		num = DotRecognize.request()
		if num in range(1, 4):
			dic[num] = POSE_GOAL[i]

	for i in range(3, 0, -1):
		baseNode.move(dic[i])
		upperNode.move(4)

	# End of main loop
	#############################################################
```

[//]: # (未來可以再改進的地方: 利用文本來寫腳本，而不是使用原始碼修改。可以減少出錯的機率。)

在開發時我們發現利用這種方式寫腳本會發生 class 中的原始碼會被一些人修改。腳本與 class 定義放在同一個文本內可以方便管理，但是也代表修改文本的人會直接看到 class 的原始碼，並且如果使用者不小心修改到那些原始碼的話可能會造成功能損壞。因此未來應該要將腳本的文檔與 class 的定義獨立，達成物件導向中封裝 (Encapsulation) 的定義。

## 字母辨識

[//]: # (service 資料型態)

字母辨識的功能利用 ROS 架設名稱為 `alphabet_recognize` 的 node，方便其他使用者使用。只要發送 request 給這個 node ，node 就會開啟攝影機並且辨識前方字牌的字母。與 node 溝通的訊息資料結構如下:

```
# This is the file /src/alphabet_recognize/srv/alphabetSrv.srv

int16 position_req

---

int16 alphabet_srv
int16 distance_srv
int16 x_diff_srv
```

[//]: # (使用的外部 library)

字母辨識主要使用到了以下的 library (部分次要的 library 未列出):

- `cv2`: 用於處理影像
- `numpy`: 用於處理影像
- `rospy`: 用於架設 node 與溝通
- `pytesseract`: 用於辨識字母

[//]: # (分成兩個部分，得到板子的邊與透過板子辨識字母)

字母辨識在得到照片後分為兩個主要步驟，首先會偵測板子並將板子周圍的部分裁減，然後從板子辨識字母。

[//]: # (TODO: 利用到了哪些函式?)
[//]: # (TODO: 流程圖為何?)
[//]: # (TODO: 各函式演算法)

[//]: # (未來可以再改進的地方: 將邊框的程式修改，使一部分的邊框漏洞可以修復)

在測試時，我們發現偵測板子邊框的演算法非常注重邊框的完整性。這代表若板子的邊框有任何部分被遮蔽的情況下就會偵測失敗。因此未來我們希望可以將這個部分修復。