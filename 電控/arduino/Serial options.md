標籤: #list #arduino #電路 

---

用於 [[Serial]] 的腳位有不同種類

# 1. HardwareSerial

最佳效能，如果可以盡量使用這些腳位。不包含與電腦連接的端口，在 [[Arduino Mega]] 上有三組，在 [[Arduino UNO]] 上沒有。

# 2. [[AltSoftSerial.h]]

較適合連續傳輸與接收資料，但是會占用一整個 16bit timer ，並且會停用一部分 PWM 腳位，而且對於其他函式庫占用運算資源十分敏感

# 3. [[SoftwareSerial.h]]

可以用在幾乎任何角位，並且可以開啟很多通訊腳位，但是一次只有一個可以運作

無法連續傳送和接收訊息

如果鮑率不高，可以與其他函式庫和 [[#1 HardwareSerial]] 一起使用

對其他函式庫占用運算資源十分敏感

# 4. Old SoftwareSerial

屎

---

[AltSoftSerial Library](https://www.pjrc.com/teensy/td_libs_AltSoftSerial.html#speed)
[[Arduino 和 樹莓派一起使用]]
[[NACK]]