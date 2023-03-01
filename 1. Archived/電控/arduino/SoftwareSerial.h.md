標籤: #arduino 

---

一種 Serial 的溝通方式

Arduino 內建有 0, 1 用來做[[Serial]]通訊(和 USB 連在一起)，注意不要用這兩個腳位

# 函式庫

```arduino
#include <SoftwareSerial.h>
```

# 限制

1. 如果有多於一個 Serial 通訊，同時只有一個可以接收訊號
2. Mega 板只有一些腳位可以用於RX: 
   - `10`
   - `11`
   - `12`
   - `13`
   - `14`
   - `15`
   - `50`
   - `51`
   - `52`
   - `53`
   - `A8` (`62`)
   - `A9` (`63`)
   - `A10` (`64`)
   - `A11` (`65`)
   - `A12` (`66`)
   - `A13` (`67`)
   - `A14` (`68`)
   - `A15` (`69`)
3. Leonardo 和 Micro 只有一些腳位可以用於RX:
   - `8`
   - `9`
   - `10`
   - `11`
   - `14` (`MISO`)
   - `15` (`SCK`)
   - `16` (`MOSI`)
4. Arduino 和 Genuino 101 上最大 RX 速率是 `57600bps`
5. Arduino 和 Genuino 101 上 RX 不能是腳位 `13`
6. 如果需要持續的資料傳輸，可以使用[[AltSoftSerial.h]]

# 可用函式

函式 | 功能
--- | ---
[[#SoftwareSerial]] | 製造物件
[[#available]] | 回傳可讀取 `byte` 數量
[[#begin]] | 設定通訊速度
[[#isListening]] | 回傳是否在聆聽
[[#overflow]] | 回傳是否暫存區超載
[[#peek]] | 回傳暫存區的第一個字元
[[#read]] | 將暫存區的第一個字元拿出來
[[#print]] | 傳送資料
[[#println]] | 傳送資料並換行
[[#listen]] | 切換聆聽的腳位
[[#write]] | 傳送 `byte` 型態資料

## SoftwareSerial

可以用來製造物件

```arduino
SoftwareSerial(rxPin, txPin, inverse_logic);
```

- `rxPin`: 接收資料的腳位
- `txPin`: 傳送資料的腳位
- `inverse_logic`: 當設定後會反轉接收進來的bit(`1`轉`0`，`0`轉`1`)

> 注意: 要注意 Arduino 的電壓不能混用，一個 `3.3V` 和一個 `5V` 的板子不能混用

### 範例

```arduino
#include <SoftwareSerial.h>  
  
const byte rxPin = 2;  
const byte txPin = 3;  
  
// set up a new serial object  
SoftwareSerial mySerial (rxPin, txPin);
```

## available

回傳可讀取 `byte` 數量

```arduino
mySerial.available();
```

- `mySerial`: `SoftwareSerial` 定義的物件

### 範例

```arduino
// include the SoftwareSerial library so you can use its functions:  
#include <SoftwareSerial.h>  
  
#define rxPin 10  
#define txPin 11  
  
// set up a new serial port  
SoftwareSerial mySerial = SoftwareSerial(rxPin, txPin);  
  
void setup() {  
 // define pin modes for tx, rx:  
 pinMode(rxPin, INPUT);  
 pinMode(txPin, OUTPUT);  
 // set the data rate for the SoftwareSerial port  
 mySerial.begin(9600);  
}  
  
void loop() {  
 if (mySerial.available()>0){  
 mySerial.read();  
 }  
}
```

## begin

設定通訊速度，有以下速度可以選擇
- `300`
- `600`
- `1200`
- `2400`
- `4800`
- `9600`
- `14400`
- `19200`
- `28800`
- `31250`
- `38400`
- `57600`
- `115200`

```arduino
mySerial.begin(speed);
```

- `mySerial`: `SoftwareSerial` 定義的物件
- `speed`: 通訊速度

### 例子

```arduino
// include the SoftwareSerial library so you can use its functions:  
#include <SoftwareSerial.h>  
  
#define rxPin 10  
#define txPin 11  
  
// set up a new serial port  
SoftwareSerial mySerial = SoftwareSerial(rxPin, txPin);  
  
void setup() {  
 // define pin modes for tx, rx:  
 pinMode(rxPin, INPUT);  
 pinMode(txPin, OUTPUT);  
 // set the data rate for the SoftwareSerial port  
 mySerial.begin(9600);  
}  
  
void loop() {  
 // ...  
}
```

## isListening

回傳是否有在主動接收資料，會回傳 `1` 或 `0`

```arduino
mySerial.isListening();
```

- `mySerial`: `SoftwareSerial` 定義的物件

### 範例

```arduino
#include <SoftwareSerial.h>  
  
// software serial : TX = digital pin 10, RX = digital pin 11  
SoftwareSerial portOne(10,11);  
  
void setup()  
{  
 // Start the hardware serial port  
 Serial.begin(9600);  
  
 // Start software serial port  
 portOne.begin(9600);  
}  
  
void loop()  
{  
 if (portOne.isListening()) {  
 Serial.println("Port One is listening!");  
}
```

## overflow

回傳暫存區是否超載布林值(暫存區最多可以存放 `64byte` 的資料)

> 注意: 這個呼叫後會把暫存區的超載記號歸零，因此一次超載只能呼叫一次

```arduino
mySerial.overflow();
```

- `mySerial`: `SoftwareSerial` 定義的物件

### 例子

```arduino
#include <SoftwareSerial.h>  
  
// software serial : TX = digital pin 10, RX = digital pin 11  
SoftwareSerial portOne(10,11);  
  
void setup()  
{  
 // Start the hardware serial port  
 Serial.begin(9600);  
  
 // Start software serial port  
 portOne.begin(9600);  
}  
  
void loop()  
{  
 if (portOne.overflow()) {  
 Serial.println("SoftwareSerial overflow!");  
}
```

## peek

回傳暫存區接收到的第一個字元，和 [[#read]] 差不多，但是 [[#read]] 會把暫存區清空，[[#peek]] 會把字元留在暫存區

如果沒有字元可以讀，會回傳 `-1`

> 注意: Arduino 一次只能聆聽一個 port

```arduino
mySerial.peek();
```

- `mySerial`: `SoftwareSerial` 定義的物件

### 例子

```arduino
SoftwareSerial mySerial(10,11);  
  
void setup()  
{  
 mySerial.begin(9600);  
}  
  
void loop()  
{  
 char c = mySerial.peek();  
}
```

## read

回傳第一個暫存區的字元，並把那個字元從暫存區刪除

如果沒有字元可以讀取，會回傳 `-1`

> 注意: Arduino 一次只能聆聽一個 port

```arduino
mySerial.read();
```

- `mySerial`: `SoftwareSerial` 定義的物件

### 例子

```arduino
SoftwareSerial mySerial(10,11);  
  
void setup()  
{  
 mySerial.begin(9600);  
}  
  
void loop()  
{  
 char c = mySerial.read();  
}
```

## print

從傳送資料角位印出資料，和 [[Serial]] 的 `Serial.print();` 類似

會回傳傳送資料的大小，單位 `byte`

```arduino
mySerial.print(data);
```

- `mySerial`: `SoftwareSerial` 定義的物件
- `data`: 要傳送的資料，很多變數型態都可以塞

### 例子

```arduino
SoftwareSerial serial(10,11);  
int analogValue;  
  
void setup()  
{  
  serial.begin(9600);  
}  
  
void loop()  
{  
  // read the analog input on pin 0:  
  analogValue = analogRead(A0);  
  
  // print it out in many formats:  
  serial.print(analogValue);         // print as an ASCII-encoded decimal  
  serial.print("\t");                // print a tab character  
  serial.print(analogValue, DEC);    // print as an ASCII-encoded decimal  
  serial.print("\t");                // print a tab character  
  serial.print(analogValue, HEX);    // print as an ASCII-encoded hexadecimal  
  serial.print("\t");                // print a tab character  
  serial.print(analogValue, OCT);    // print as an ASCII-encoded octal  
  serial.print("\t");                // print a tab character  
  serial.print(analogValue, BIN);    // print as an ASCII-encoded binary  
  serial.print("\t");                // print a tab character  
  serial.print(analogValue/4, BYTE); // print as a raw byte value (divide the  
                                     // value by 4 because analogRead() returns numbers  
                                     // from 0 to 1023, but a byte can only hold values  
                                     // up to 255)  
  serial.print("\t");                // print a tab character   
  serial.println();                  // print a linefeed character  
  
  // delay 10 milliseconds before the next reading:  
  delay(10);  
}
```

## println

和 [[#print]] 一樣，只是多了一個換行，原理和 [[Serial]] 的 `Serial.println()` 一樣

會回傳傳送資料的大小，單位 `byte`

```arduino
mySerial.println(data);
```

- `mySerial`: `SoftwareSerial` 定義的物件
- `data`: 要傳送的資料，有很多種變數型態可以放

### 例子

```arduino
SoftwareSerial serial(10,11);  
int analogValue;  
  
void setup()  
{  
  serial.begin(9600);  
}  
  
void loop()  
{  
  // read the analog input on pin 0:  
  analogValue = analogRead(A0);  
  
  // print it out in many formats:  
  serial.print(analogValue);         // print as an ASCII-encoded decimal  
  serial.print("\t");                // print a tab character  
  serial.print(analogValue, DEC);    // print as an ASCII-encoded decimal  
  serial.print("\t");                // print a tab character  
  serial.print(analogValue, HEX);    // print as an ASCII-encoded hexadecimal  
  serial.print("\t");                // print a tab character  
  serial.print(analogValue, OCT);    // print as an ASCII-encoded octal  
  serial.print("\t");                // print a tab character  
  serial.print(analogValue, BIN);    // print as an ASCII-encoded binary  
  serial.print("\t");                // print a tab character  
  serial.print(analogValue/4, BYTE); // print as a raw byte value (divide the  
                                     // value by 4 because analogRead() returns numbers  
                                     // from 0 to 1023, but a byte can only hold values  
                                     // up to 255)  
  serial.print("\t");                // print a tab character   
  serial.println();                  // print a linefeed character  
  
  // delay 10 milliseconds before the next reading:  
  delay(10);  
}
```

## listen

開始聆聽那個 `port` ，注意一次只能聆聽一個 `port` ，其他的 `port` 接收到的資料會消失，暫存區內的所有資料也會被清空(除非呼叫 `listen` 的 `port` 已經在聆聽)

如果有切換 `port` 會回傳 `true` ，反之會回傳 `false`

```arduino
mySerial.listen();
```

- `mySerial`: `SoftwareSerial` 定義的物件

### 例子

```arduino
#include <SoftwareSerial.h>  
  
// software serial : TX = digital pin 10, RX = digital pin 11  
SoftwareSerial portOne(10, 11);  
  
// software serial : TX = digital pin 8, RX = digital pin 9  
SoftwareSerial portTwo(8, 9);  
  
void setup()  
{  
 // Start the hardware serial port  
 Serial.begin(9600);  
  
 // Start both software serial ports  
 portOne.begin(9600);  
 portTwo.begin(9600);  
  
}  
  
void loop()  
{  
 portOne.listen();  
  
 if (portOne.isListening()) {  
 Serial.println("Port One is listening!");  
}else{  
 Serial.println("Port One is not listening!");  
}  
  
 if (portTwo.isListening()) {  
 Serial.println("Port Two is listening!");  
}else{  
 Serial.println("Port Two is not listening!");  
}  
  
}
```

## write

把資料用 `byte` 型態傳送，和 [[Serial]] 的 `Serial.write()` 一樣

會回傳傳送資料的 `byte` 數量

```arduino
mySerial.write(data);
```
- `mySerial`: `SoftwareSerial` 定義的物件
- `data`: 要傳送的資料

### 例子

```arduino
SoftwareSerial mySerial(10, 11);  
  
void setup()  
{  
 mySerial.begin(9600);  
}  
  
void loop()  
{  
 mySerial.write(45); // send a byte with the value 45  
  
 int bytesSent = mySerial.write(“hello”); //send the string “hello” and return the length of the string.  
}
```

# 例子

## 將 [[Serial]] 和 mySerial 的資料轉傳到對方

```arduino
/*
  Software serial multple serial test

 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.

 The circuit:
 * RX is digital pin 2 (connect to TX of other device)
 * TX is digital pin 3 (connect to RX of other device)

 Note:
 Not all pins on the Mega and Mega 2560 support change interrupts,
 so only the following can be used for RX:
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

 Not all pins on the Leonardo support change interrupts,
 so only the following can be used for RX:
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

 created back in the mists of time
 modified 25 May 2012
 by Tom Igoe
 based on Mikal Hart's example

 This example code is in the public domain.

 */
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }


  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(38400);
  mySerial.println("Hello, world?");
}

void loop() // run over and over
{
  if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());
}
```

## 同時接收兩個 port 的訊號

```arduino
/*

  Software serial multple serial test

 Receives from the two software serial ports,

 sends to the hardware serial port.

 In order to listen on a software port, you call port.listen().

 When using two software serial ports, you have to switch ports

 by listen()ing on each one in turn. Pick a logical time to switch

 ports, like the end of an expected transmission, or when the

 buffer is empty. This example switches ports when there is nothing

 more to read from a port

 The circuit:

 Two devices which communicate serially are needed.

 * First serial device's TX attached to digital pin 10(RX), RX to pin 11(TX)

 * Second serial device's TX attached to digital pin 8(RX), RX to pin 9(TX)

 Note:

 Not all pins on the Mega and Mega 2560 support change interrupts,

 so only the following can be used for RX:

 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

 Not all pins on the Leonardo support change interrupts,

 so only the following can be used for RX:

 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

 created 18 Apr. 2011

 modified 19 March 2016

 by Tom Igoe

 based on Mikal Hart's twoPortRXExample

 This example code is in the public domain.

 */

#include <SoftwareSerial.h>
// software serial #1: RX = digital pin 10, TX = digital pin 11

SoftwareSerial portOne(10, 11);

// software serial #2: RX = digital pin 8, TX = digital pin 9
// on the Mega, use other pins instead, since 8 and 9 don't work on the Mega

SoftwareSerial portTwo(8, 9);

void setup() {

  // Open serial communications and wait for port to open:

  Serial.begin(9600);

  while (!Serial) {

    ; // wait for serial port to connect. Needed for native USB port only

  }

  // Start each software serial port

  portOne.begin(9600);

  portTwo.begin(9600);
}

void loop() {

  // By default, the last intialized port is listening.

  // when you want to listen on a port, explicitly select it:

  portOne.listen();

  Serial.println("Data from port one:");

  // while there is data coming in, read it

  // and send to the hardware serial port:

  while (portOne.available() > 0) {

    char inByte = portOne.read();

    Serial.write(inByte);

  }

  // blank line to separate data from the two ports:

  Serial.println();

  // Now listen on the second port

  portTwo.listen();

  // while there is data coming in, read it

  // and send to the hardware serial port:

  Serial.println("Data from port two:");

  while (portTwo.available() > 0) {

    char inByte = portTwo.read();

    Serial.write(inByte);

  }

  // blank line to separate data from the two ports:

  Serial.println();
}
```

---

[SoftwareSerial.h arduino官方](https://www.arduino.cc/en/Reference/softwareSerial)
[SoftwareSerial.h example](https://www.arduino.cc/en/Tutorial/LibraryExamples/SoftwareSerialExample)
[SoftwareSerial.h constructor](https://www.arduino.cc/en/Reference/SoftwareSerialConstructor)
[SoftwareSerial.h available](https://www.arduino.cc/en/Reference/SoftwareSerialAvailable)
[SoftwareSerial.h begin](https://www.arduino.cc/en/Reference/SoftwareSerialAvailable)
[SoftwareSerial.h isListening](https://www.arduino.cc/en/Reference/SoftwareSerialIsListening)
[SoftwareSerial.h overflow](https://www.arduino.cc/en/Reference/SoftwareSerialOverflow)
[SoftwareSerial.h peek](https://www.arduino.cc/en/Reference/SoftwareSerialPeek)
[SoftwareSerial.h read](https://www.arduino.cc/en/Reference/SoftwareSerialRead)
[SoftwareSerial.h print](https://www.arduino.cc/en/Reference/SoftwareSerialPrint)
[SoftwareSerial.h println](https://www.arduino.cc/en/Reference/SoftwareSerialPrint)
[SoftwareSerial.h listen](https://www.arduino.cc/en/Reference/SoftwareSerialListen)
[SoftwareSerial.h write](https://www.arduino.cc/en/Reference/SoftwareSerialWrite)
[[Arduino 和 樹莓派一起使用]]