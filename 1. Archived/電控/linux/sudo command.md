標籤: #linux 

`sudo`類似[[su command]]，也是可以取得[[root account| root]]權限的指令，但是使用它輸入密碼時是使用自己的密碼，而不是[[root account | root]]的密碼，因此使用上比較方便

> ubuntu 在預設之下因為安全考量並不會啟用[[root account | root]]帳號，所有的系統管理工作會用`sudo`完成

---

# 用法

`sudo`類似`su -c`，執行完後就會離開

- `sudo`: 執行後面接著的指令

- `sudo -u`: 切換到另一使用者的權限，並執行後面的指令
例子: `sudo -u littled3092 ls ~littled3092`可以顯示littled3092家目錄的內容

- `sudo -g`: 取得某個群組的權限，並執行後面的指令
例子: `sudo -g adm view /var/log/syslog`可以取得adm群組的權限，並瀏覽系統紀錄

- `sudo su -`: 在ubuntu中常用，可以藉由`su`取得一個新的shell

---

[[sudoers設定檔]]