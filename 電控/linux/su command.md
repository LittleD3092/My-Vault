標籤: #raspberryPi #linux

- `$ su`: 需要做更改檔案等小動作時，就可以使用這個，不會更改到環境變數

- `$ su -`: 多加了一個減號，代表以[[root account | root]]權限登入，會模仿[[root account| root]]權限開機並產生一個新的shell
上述兩者都會開啟一個新的shell，要離開的話可以使用`$ exit`或者用`Ctrl + d`

- `$ su - -c`: 只執行後面接著的一行指令就馬上跳出root
例子: `su - -c "service nginx reload"`，注意要加雙引號

- `$ su -l`: 這個指令可以取得別的帳號的權限，後面的密碼就要打需要取得權限帳號的密碼
例子: `$ su -l littled3092`代表取得`littled3092`這個帳號的權限，後面輸入的也是這個帳號的密碼

---

> 參考資料: [Linux sudo 與 su 教學](https://blog.gtwang.org/linux/sudo-su-command-tutorial-examples/)