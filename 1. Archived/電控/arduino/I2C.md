標籤: #arduino 

# 接線

![[Pasted image 20210812184926.png]]

---

指令 | 使用位置 | 作用
--- | --- | ---
[[#Wire h]] | | 標頭檔
[[#Wire begin]] | master / slave | 啟動Wire
[[#Wire requestFrom]] | master | 向 slave 要求資料
[[#Wire beginTransmition]] | master | 開始對 slave 的連線
[[#Wire endTransmission]] | master | 結束連線
[[#Wire write]] | master / slave | 向對方傳送資料
[[#Wire available]] | master / slave | 回傳可以讀取的 bytes 數量
[[#Wire read]] | master / slave | 讀取傳送的資料
[[#Wire setClock]] | master / slave | 設定時脈
[[#Wire onReceive]] | slave | 設定 slave 接收到資料時的函式
[[#Wire onRequest]] | slave | 設定 slave 的函式，用來回應請求

[[#例子 接收資料]]

---

# Wire.h

```arduino
#include <Wire.h>
```
使用 `Wire.h`

---

# Wire.begin

```arduino
Wire.begin(address)
```
啟動i2c，括號中放slave編號，如果是master就不用放
- `address`: 一個 7-bit 以內的數字

---

# Wire.requestFrom

```arduino
Wire.requestFrom(address, quantity)  
Wire.requestFrom(address, quantity, stop)
```
向編號 `address` 的 slave 要求 `quantity` byte 的回覆， `stop` 如果是 `true` 在要求與接收完會空出 bus
之後可以用 `Wire.available()` 和 `Wire.read()` 取得回覆內容
- `address`: 7-bit 的數字，代表 slave 的地址
- `quantity`: 要求的 byte 數量
- `stop`: 布林值，如果是 `true` 在執行完會空出 bus

> **回傳值:**
> byte，內容是 slave 回覆的長度，單位為 byte

---

# Wire.beginTransmition

```arduino
Wire.beginTransmission(address)
```
開始對編號 `address` slave 傳輸，通常配合 `Wire.write` 和 `Wire.endTransmition`
- `address`: 7-bit 的數字，代表 slave 的地址

---

# Wire.endTransmission

```arduino
Wire.endTransmission()  
Wire.endTransmission(stop)
```
結束傳輸，如果 `stop` 為 `false` 會重新啟用傳輸
- `stop`: 布林值，如果是 `false` 會重新啟用傳輸，預設為 `true`

> **回傳值:**
> byte，內容是傳輸的狀態
> `0`: 成功
> `1`: 檔案長度過長
> `2`: 收到對 address 的 [[NACK]]
> `3`: 收到對 data 的 [[NACK]]

---

# Wire.write

```arduino
Wire.write(value)  
Wire.write(string)  
Wire.write(data, length)
```
傳輸括號內檔案給對方(master 或 slave 都可以使用)
- `value`: 傳輸資料，大小 1 byte
- `string`: 傳輸資料，一個字串
- `data`: 傳輸資料，一個 byte 陣列
- `length`: `data` 陣列的長度

> **回傳值:**
> 回傳寫入資料的長度

## example

```arduino
#include <Wire.h>  
  
byte val = 0;  
  
void setup()  
{  
 Wire.begin(); // join i2c bus  
}  
  
void loop()  
{  
 Wire.beginTransmission(44); // transmit to device #44 (0x2c)  
 // device address is specified in datasheet  
 Wire.write(val); // sends value byte   
 Wire.endTransmission(); // stop transmitting  
  
 val++; // increment value  
 if(val == 64) // if reached 64th position (max)  
 {  
 val = 0; // start over from lowest value  
 }  
 delay(500);  
}
```

---

# Wire.available

```arduino
Wire.available()
```

須在 master 中 `requestFrom()` 後面，或者在 slave 中 `onReceive` 後面。回傳可以讀取的 byte 數量。

---

# Wire.read

```arduino
Wire.read()
```
寫在 `requestFrom()` 後面，讀取從 slave 傳給 master 的下一個 byte，或者寫在 slave ，讀取從 master 傳給 slave 的資料

> **回傳值**
> 回傳下一個 byte

## example

```arduino
#include <Wire.h>  
  
void setup()  
{  
 Wire.begin(); // join i2c bus (address optional for master)  
 Serial.begin(9600); // start serial for output  
}  
  
void loop()  
{  
 Wire.requestFrom(2, 6); // request 6 bytes from slave device #2  
  
 while(Wire.available()) // slave may send less than requested  
 {  
 char c = Wire.read(); // receive a byte as character  
 Serial.print(c); // print the character  
 }  
  
 delay(500);  
}
```

---

# Wire.setClock

```arduino
Wire.setClock(clockFrequency)
```
設定i2c的通訊時脈

- `clockFrequency`: 時脈，單位Hz。標準的時脈是 `100000` (standard mode) 和 `400000` (fast mode)。有些處理器支援其他時脈。

---

# Wire.onReceive

```arduino
Wire.onReceive(handler)
```
設定當 slave 接收到來自 master 的資料時呼叫的函式

- `handler`: 當 slave 接收到來自 master 的資料時呼叫的函式。函式必須長這樣 `void myHandler(int numBytes)` ，不能有回傳值且接收一個 `int` 變數。 `numBytes` 通常是向 master 讀取的 bytes 數量

---

# Wire.onRequest

```arduino
Wire.onRequest(handler)
```
設定 master 向 slave 要求資料時呼叫的函式

- `handler`: 呼叫的函式，沒有回傳值和變數，像 `void myHandler()`

---

# 例子(接收資料)

## master

```arduino
#include <Wire.h>

#define SLAVE_ADDRESS 0x12
#define SERIAL_BAUD 57600 
#define DATA_SIZE 8

void setup()
{
  Wire.begin();
 
  Serial.begin(SERIAL_BAUD);
  Serial.println("I2C Master.04 started");
  Serial.println();
}
 
 
void loop()
{
  if (Serial.available()) {

    Wire.requestFrom(SLAVE_ADDRESS, DATA_SIZE);
    Wire.beginTransmission(SLAVE_ADDRESS);
    if (Wire.available()) {
      Serial.print("Data returned: ");
      while (Wire.available()) Serial.print((char) Wire.read());
      Serial.println();
    }
    Wire.endTransmission();
    while(Serial.available()) Serial.read();  // Clear the serial buffer, in this example, just request data from slave
  }

}
```

## slave

```arduino
#include <Wire.h>

#define SLAVE_ADDRESS 0x12
#define SERIAL_BAUD 57600 

#define I2C_BUFFER_SIZE 32  
uint8_t i2cBuffer[I2C_BUFFER_SIZE];
uint8_t i2cBufferCnt = 0;

void setup() {
  Wire.begin(SLAVE_ADDRESS);    // join I2C bus as a slave with address 1
  Wire.onRequest(requestEvent); // register event
 
  Serial.begin(SERIAL_BAUD);
  Serial.println("I2C Slave.04 started\n");
}

void loop() {
}

void requestEvent()
{
  Wire.write("Super169",8);
}
```

---

[[Serial]]

> 參考資料: 
> [Arduino Wire.h](https://www.arduino.cc/en/reference/wire)
> [[Arduino 和 樹莓派一起使用]]