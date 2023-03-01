標籤: #linux 

這個指令可以更改現有帳號的設定
而[[adduser]]是新增帳號並進行設定，兩者差不多

語法: 
```bash
$ usermod [-cdegGlsuLU] username

[-c comment]
[-d home_dir [-m]]
[-e expire_date]
[-f inactive_time]
[-g initial_group]
[-G group[,...]]
[-l login_name]
[-s shell]
[-u uid [-o]]
```

---

# -c

更新[[/etc/passwd]]中的註解欄，通常用[[chfn]]來變更，不會用這個
註解欄中可以包含使用者的聯絡方式等資料
```bash
$ usermod -c "manager" littled3092
```

# -d

將使用者的家目錄變更，若加上 `-m` ，則會將舊家目錄的檔案一起搬到新家目錄
```bash
$ usermod -d /home/new_dir littled3092
$ usermod -d /home/new_dir -m littled3092
```

# -e

設定帳號到期日
```bash
$ usermod -e 2025-07-28
```

# -f

在使用者密碼過期後幾天內停用帳號。若是 `0` 則立即停用，若是 `-1` 則關閉此功能。
```bash
$ usermod -f 30 littled3092
```

# -g

更改使用者登入群組[[/etc/group]]
```bash
$ usermod -g group littled3092
```

# -G

定義使用者為以下群組的成員。若使用者本來的群組沒有填，他會被移除。
加上 `-a` 可以避免被退出
```bash
$ usermod -G group1,group2 littled3092
$ usermod -a -G group littled3092
```

# -l

變更使用者帳號名稱，目錄銘也會跟著更動
```bash
$ usermod -l new-login old-login
```

# -s

指定登入的shell，若空白則使用預設的
```bash
$ usermod -s /usr/bin/ksh littled3092
```

# -u

更改使用者id，不能小於0，且預設不可為0~999，因為這個範圍預設給系統使用
```bash
$ usermod -u 1002 littled3092
```

---

[[sudoers設定檔]]
[[root account]]