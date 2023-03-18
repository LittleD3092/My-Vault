標籤: #arduino 

---

模擬更多 [[Serial]] 腳位供使用

較適合連續的資料傳輸

在 16MHz 的 AVR 處理器上速度可以到 31250baud ，在 96MHz Teensy 3.2 速度可以達到 400000baud

---

# 限制

不同的板子會有不同限制

Board | Transmit Pin | Receive Pin | Unusable PWM
--- | --- | --- | ---
Teensy 3.5 / 3.6 | 21 | 20 | 22
Teensy 3.0 / 3.1 / 3.2 | 21 | 20 | 22
Teensy 2.0 | 9 | 10 | (none)
Teensy++ 2.0 | 25 | 4 | 26, 27
[[Arduino UNO]], Duemilanove, LilyPad, Mini, (& other ATMEGA328) | 9 | 8 | 10
Arduino Leonardo, Yun, Micro | 5 | 13 | (none)
[[Arduino Mega]] | 46 | 48 | 44, 45
Wiring S | 5 | 6 | 4
Sanguino | 13 | 14 | 12

Unusable PWM 代表那些腳位不能使用類比訊號輸出，數位的還是可以的

---

# 程式

## AltSoftSerial

```arduino
AltSoftSerial mySerial;
```
創造名為 `mySerial` 的物件

## begin

```arduino
mySerial.begin(baud);
```
設定鮑率

- `mySerial`: `AltSoftSerial` 定義的物件

## print

```arduino
mySerial.print(anything);
```
傳送訊息，這和 [[Serial]] 裡的 `print` 一模一樣

- `mySerial`: `AltSoftSerial` 定義的物件
- `anything`: 數字或文字

## available

```arduino
mySerial.available();
```
回傳可以讀取的 `bytes` 數量

- `mySerial`: `AltSoftSerial` 定義的物件

## read

```arduino
mySerial.read();
```
讀取一個 `byte` 並回傳，如果沒有可以讀取的資料會回傳 `-1`

# 範例

```arduino
#include <AltSoftSerial.h>

AltSoftSerial altSerial;

void setup() {
  Serial.begin(9600);
  Serial.println("AltSoftSerial Test Begin");
  altSerial.begin(9600);
  altSerial.println("Hello World");
}

void loop() {
  char c;

  if (Serial.available()) {
    c = Serial.read();
    altSerial.print(c);
  }
  if (altSerial.available()) {
    c = altSerial.read();
    Serial.print(c);
  }
}
```

---

[AltSoftSerial Library](https://www.pjrc.com/teensy/td_libs_AltSoftSerial.html)
[[Arduino 和 樹莓派一起使用]]