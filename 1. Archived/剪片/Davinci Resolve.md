標籤: #剪片 

---

一款剪片軟體，免費，對於顏色調整的效果比較好

# 設定畫質與FPS

右下角齒輪

# 工作流程

下面有一排工具列，由左到右就是工作流程，通常都是照著這個流程

## Media

### Scene Cut Detection

在匯入媒體時，對素材右鍵點擊 [[#Scene Cut Detection]] 可以設定場景轉換，把一個素材分成多個素材

素材庫中可以用資料夾分類素材

> 裡面有一個 Auto Scene Detect 可以自動偵測

## Cut

按兩下素材預覽

`F9` 加入時間軸

`I` 在素材預覽設定擷取起點

`O` 在素材擷取設定擷取終點

## Edit

這裡也可以做到前兩頁的功能

在音軌檔上面可以直接用拉的調整背景音大小

`Delete` 將片段刪除並把縫隙填起來(或點縫隙把中間的縫隙刪除)

`Backspace` 將片段刪除，不會填補片段

`Ctrl + B` 分割素材

`Ctrl + Shift + [` 刪除播放頭以左素材

`Ctrl + Shift + ]` 刪除播放頭以右素材

`Ctrl + Shift + 滑鼠拖曳素材` 將素材調換順序

`Alt + 點擊音訊素材` 加入節點，可以控制部分音量等 

素材左上右上白點: 淡入淡出

### Trim Edit Mode

方便剪輯的模式，剪素材時會自動補上缺口，也可以調整已經剪裁的素材

`Ctrl + R` 開啟速度控制(慢動作)
> 慢動作會導致影片卡頓不順暢，要在右上角 inspector -> video -> retime and scaling -> retime process -> optical flow 開啟光流

### 預覽左下角選單

調整素材縮放與位置、素材剪裁、動態縮放

### Effects Library

可以加入文字，Text 和 Text + 的不同在於靜態和動態

包含一些轉場特效(溶)

## Fusion

採用節點的觀念，有一個輸出，經過各個節點的特效調整後才會變成輸出的樣子

特效資料庫 -> 平面追蹤器: 追蹤平面，適合修改螢幕顯示內容

## Color

調色，`Alt + S` 可以新增調色節點，每個節點負責調一次色

右下角的波形圖可以讓我們知道缺乏什麼樣的顏色

調好一個素材可以右鍵 Grab still ，再套用在其他素材

## Fairlight

進一步的混音可以使用

## Deliver

輸出

---

參考資料:

[Davinci Resolve 快速上手 (papaya) - youtube](https://www.youtube.com/watch?v=x-mQDWMAnb8)