標籤: #linux 

sodoers的設定檔位於`/etc/sudoers`，因為[[sudo command]]不需要[[root account| root]]的密碼，因此需要一個表來管理可以使用這個指令的使用者

> 在更改sudoers的檔案時，可以使用`visudo`來編輯，這樣[[vi]]文字編輯器就會在最後檢查是否可以使用，避免出錯而無法使用

# 單一帳號設定

設定檔格式: `帳號名稱   來源主機=(可切換帳號)   可執行的命令`
1. **帳號名稱**: 可以使用sudo的帳號名稱
2. **來源主機**: 從哪個網路主機才可以使用sudo，若設為`ALL`則不限制網路主機
3. **可切換帳號**: 可以切換為哪些帳號的權限，若設為`ALL`則不限制可以切換的帳號
4. **可執行的命令**: 可以執行哪些命令，若設為`ALL`則所有命令都可以使用

範例1: `littled3092   ALL=(ALL)    ALL`

範例2: `accmgr        ALL=(root)   /usr/bin/passwd`
> 假設accmgr是專門修改使用者密碼的使用者，這個設定檔可以讓accmgr使用更改密碼的指令，但是這有一個漏洞，因為這個帳號同時也可以更改[[root account| root]]的密碼，從而獲取更高的權限，因此應該這樣寫:
`accmgr   ALL=(root)   !/usr/bin/passwd, /usr/bin/passwd [A-Za-z]*, !usr/bin/passwd root`

這樣一來可以禁止accmgr直接使用`/usr/bin/passwd`，並且限制他只能用這個指令加上一般使用者帳號，然後不能更改[[root account|root]]帳號的密碼


# 群組設定

設定檔格式: `%群組名稱    來源主機=(可切換帳號) 可執行的指令`
這個設定檔可以對群組下的使用者一次設定

範例: `%wheel  ALL=(ALL) ALL`



# 不用輸入密碼

如果需要讓特定的使用者不用輸入密碼，可以用以下寫法:
`littled3092  ALL=(ALL) NOPASSWD:ALL`

就算沒有加入`NOPASSWD`的設定，五分鐘內的同一帳號也不需要再次輸入密碼，並且會被當作是同一個帳號使用指令，不過超過五分鐘就會需要重新輸入密碼了


# 使用別名
當需要管理的使用者或指令太多的時候，可以利用別名來方便管理: 
```
User_Alias MYACC = accmgr, gtwang, seal
Cmnd_Alias MYEXE = !/usr/bin/passwd, /usr/bin/passwd [A-Za-z]*, !/usr/bin/passwd root
MYACC   ALL=(root)  MYEXE
```