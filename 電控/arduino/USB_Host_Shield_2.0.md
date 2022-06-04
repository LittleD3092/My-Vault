標籤: #arduino 

---

# 支援的板子

- 全部的 AVR 板子([[Arduino UNO]], Duemilanove, [[Arduino Mega]], [[Arduino Mega]] 2560...)
- Arduino Due, Intel Galileo, Intel Galileo 2, Intel Edison
- Teensy
- Balanduino
- Sanguino
- Black Widdow
- RedBearLab nRF51822
- Adafruit Feather nRF52840 Express
- Digilent chipKIT
- STM32F4
- ESP8266
- ESP32

> 使用前先閱讀[USB_Host_Shield_2.0 - github](https://github.com/felis/USB_Host_Shield_2.0)，有可能需要額外函式庫或設定

---

# 藍芽功能

`BTD.cpp` 和 `BTHID.cpp` 分別支援藍芽和 HID 藍芽裝置，其他的函式庫如ps3, ps4, wii 等也是使用這個函式庫達成藍芽

---

# SPP Library

SPP([[Serial]] Port Profile)，可以和手機或電腦用藍芽通訊，在Windows, Mac OS X, Linux, Android 已經被測試過可以用

---

# 直接支援的裝置

- ps5
- ps4
- ps3
- xbox
  - xbox
  - xbox 360
  - xbox one
  - xbox one s
- wii
- switch pro
- ps buzz
- HID
- MIDI
- amBX

> 使用方式在範裡中可以找到

---

參考資料:

[USB_Host_Shield_2.0 - github](https://github.com/felis/USB_Host_Shield_2.0)
[USB_Hsot_Shield_2.0 documentation](https://felis.github.io/USB_Host_Shield_2.0/)