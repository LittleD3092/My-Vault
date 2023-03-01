標籤: #raspberryPi

# 裝系統

1. **在網站上安裝裝系統的應用程式(exe)**
[下載點](https://www.raspberrypi.org/software/)
![[樹梅派下載畫面.png]]

2. **將SD卡插入電腦**

3. **安裝並執行裝系統的應用程式**
[教學影片](https://youtu.be/ntaXWS8Lk34)

4. 移除SD卡，插回Raspberry Pi 上面

5. 接上電源、hdmi與滑鼠
![[image.jpg]]

6. 開機後照著提示設定

7. 在終端機打`sudo apt-get update`和`sudo apt-get upgrade`以更新系統

密碼: `danielw888`
#密碼

---

# VNC安裝(遠端遙控)
1. 輸入`sudo raspi-config`

2. 選擇interfacing options
![[Pasted image 20210726165534.png]]

3. 選擇VNC並開啟他，之後會安裝一連串東西，在raspberry pi的狀態列就會出現vnc server的標誌

4. 確保raspberry pi 和電腦連上的是同一個網路(經測試手機網路不行，因此推薦在筆電中設定網路共享，已經過證實可使用)，並記錄下ip(可以在raspberry pi 的vnc server 的應用程式中找到，若是用電腦開熱點的也可以在設定中找到)

5. 在電腦上安裝vnc viewer

6. 打開他，在上面的欄位填入raspberry pi的 ip
![[VNC樹梅派遠端操控選單.png]]

7. 使用者名稱是`pi`，密碼是裝系統時設定的密碼

---

> [參考資料 控制系統建置](https://chtseng.wordpress.com/2015/11/27/diy-%E6%A9%9F%E6%88%BF%E7%92%B0%E6%8E%A7%E7%B3%BB%E7%B5%B1%E5%BB%BA%E7%BD%AE-raspberry-pi%EF%BC%88%E4%B8%83%EF%BC%89/)
> [參考資料 遠端控制](https://ithelp.ithome.com.tw/articles/10235452)
> [[su command]]