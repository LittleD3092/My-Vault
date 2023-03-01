標籤: #arduino #raspberryPi

> 需要先進行[[Raspberry Pi 設定]]

1. 下載arduino IDE(linux 32bit)到 樹莓派上
2. 解壓縮並執行`install.sh`
3. 在終端機內`$ sudo usermod -a -G dialout pi`將自己加入群組，才可以存取USB
[[sudo command]]
[[usermod]]
4. 重新開機
5. 插上arduino USB線並試試看能不能上傳程式碼
6. 打開arduino範例檔案`File > Examples > Firmata > StandardFirmata`並上傳
7. 在樹莓派輸入以下指令安裝python與arduino函式庫
```bash
$ sudo pip3 install pyfirmata
```
[[pyfirmata]]
8. 接線路
![[Pasted image 20210727230241.png]]
9. 在樹梅派上執行閃爍燈程式
```python
from pyfirmata import Arduino, util
from time import sleep
board = Arduino('/dev/ttyUSB0')
led = 12
while True:
        board.digital[led].write(1)
 	sleep(0.2)
 	board.digital[led].write(0)
 	sleep(0.2)
```

[參考資料](https://www.tomshardware.com/how-to/use-raspberry-pi-with-arduino)