標籤: #arduino 

在序列埠視窗中，可以監控arduino的情況

# 腳位數量

不同板子有不同腳位數量

BOARD | USB CDC NAME | SERIAL PINS | SERIAL1 PINS | SERIAL2 PINS | SERIAL3 PINS
--- | --- | --- | --- | --- | ---
Uno, Nano, Mini |  | 0(RX), 1(TX) |  |  | 
Mega |  | 0(RX), 1(TX) | 19(RX), 18(TX) | 17(RX), 16(TX) | 15(RX), 14(TX)
Leonardo, Micro, Yún | Serial |  | 0(RX), 1(TX) |  | 
Uno WiFi Rev.2 |  | Connected to USB | 0(RX), 1(TX) | Connected to NINA |
MKR boards | Serial | | 13(RX), 14(TX) | | 
Zero | SerialUSB(Native USB Port only) | Connected to Programming Port | 0(RX), 1(TX) | | 
Due | SerialUSB(Native USB Port only) | 0(RX), 1(TX) | 19(RX), 18(TX) | 17(RX), 16(TX) | 15(RX), 14(TX)
101 | Serial | | 0(RX), 1(TX) | | 

# 程式

- [[#在 setup 中]]
- [[#使用方式]]
  - [[#println]]
  - [[#print]]
  - [[#write]]
  - [[#available]]
  - [[#read]]

## 在`setup()`中

`Serial.begin(9600);`
設定序列埠頻率為`9600`

## 使用方式

### println
```arduino
Serial.println(str);
```
印出括號內文字並換行

### print
```arduino
Serial.print(str);
```
印出括號內文字，但不換行

### write

```arduino
Serial.write(val);
Serial.write(str);
Serial.write(buf, len);
```
將括號內的資訊以 `byte` 型態傳送

- `Serial`: `Serial` 端口物件
- `val`: 用一個 `byte` 傳送的數字
- `str`: 以 `byte` 陣列傳送的字串
- `buf`: 要以 `byte` 陣列傳送的陣列
- `len`: 陣列的 `byte` 大小

### available

```arduino
Serial.available();
```
回傳可讀取的 `byte` 數量

### read

```arduino
Serial.read();
```
將一個 `byte` 讀取並回傳出來，若沒有可以讀的資料回傳 `-1`

---

參考資料:

[arduino Serial](https://www.arduino.cc/reference/en/language/functions/communication/serial/)
[arduino Serial begin](https://www.arduino.cc/reference/en/language/functions/communication/serial/begin/)
[arduino Serial write](https://www.arduino.cc/reference/en/language/functions/communication/serial/write/)
[arduino Serial available](https://www.arduino.cc/reference/en/language/functions/communication/serial/available/)
[arduino Serial read](https://www.arduino.cc/reference/en/language/functions/communication/serial/read/)
[[TDK2021電路圖]]
[[Arduino 和 樹莓派一起使用]]
[[Arduino Nano]]
[[USB_Host_Shield_2.0]]