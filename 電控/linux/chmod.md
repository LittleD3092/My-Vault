標籤: #linux 

---

chmod 可以控制文件的存取權

![[linux chmod type.png]]

一般使用三個數字：
第一個數字代表檔案所有者許可權
第二個數字表示同 group 的許可權
第三個數字表示其他使用者許可權

```bash
$ chmod 777 file
```

代表檔案在三種情況都可以讀寫與執行(`4 + 2 + 1 = 7`)

---

有時會加上第一位數字，代表執行時的權限

`0`: 沒有效果
`4`: 具有與所有者一樣的權限

> 有些檔案執行時會需要其他檔案的 dependency ，因此需要在前面加上 `4` 確保執行的時候可以順利
> ```bash
> $ chmod 4755 file
> ```
> 上面的指令代表其他使用者可以以作者身份順利執行程式

---

參考資料:

[chmod 命令 - blog](https://www.runoob.com/linux/linux-comm-chmod.html)
[chmod 四個數字的意義 - blog](https://codertw.com/%E7%A8%8B%E5%BC%8F%E8%AA%9E%E8%A8%80/420803/)

---

link:

