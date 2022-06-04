標籤: #arduino 

# 線路種類

1. 橘: 訊號線(digital)
2. 紅: VCC(5V)
3. 褐: GND

---

# 電路

## 針腳停用

在大部分Arduino 板(除了mega 之外的所有板子)在使用`<Servo.h>`時會停用pin 9, 10 的`analogWrite()` 功能。
在mega 板，若使用超過12 個伺服馬達會停用pin 11, 12。

## 接法

![[Pasted image 20210729140307.png]]

![[Pasted image 20210729140430.png]]
當需要使用多個Servo 時，需要外接電源，這時接法如上。
注意power source 和arduino 的GND必須接在一起。

---

# 程式

## servo.attach(pin)
### 語法

```arduino
servo.attach(pin) 
servo.attach(pin, min, max)
```

`servo`: 一個`Servo`定義的物件
`pin`: 針腳的數字
`min`: [[脈衝訊號寬度]]最小值(ms)，0度，預設為544
`max`: [[脈衝訊號寬度]]最大值(ms)，180度，預設為2400

### 範例

```arduino
#include <Servo.h> 

Servo myservo;

void setup() 
{ 
  myservo.attach(9);
} 

void loop() {} 
```

---

## servo.write(angle)

### 語法

```arduino
servo.write(angle)
```

`servo`: `Servo`型態的物件
`angle`: 一個0 到180 的數字。在一般伺服馬達上，這代表馬達轉向的角度。在[[Continuous Rotation Servo]]，這會是馬達的轉速，0反轉、180正轉、90停止。

### 範例

```arduino
#include <Servo.h> 

Servo myservo;

void setup() 
{ 
  myservo.attach(9);
  myservo.write(90);  // set servo to mid-point
} 

void loop() {} 
```

---

## servo.writeMicroseconds(us)

相比`servo.write(angle)`更精確。

一般合乎規定的伺服馬達在1000是0度，在1500是90度，在2000是180度，但是有許多伺服馬達並不按照這個標準，通常最大值和最小值會在700和2300之間。

[[Continuous Rotation Servo]]也可以用這個函式控制。

### 語法

```arduino
servo.writeMicroseconds(us)
```

`servo`: 一個`Servo`定義的物件
`us`: 一個整數，單位是毫秒

### 範例

```arduino
#include <Servo.h> 

Servo myservo;

void setup() 
{ 
  myservo.attach(9);
  myservo.writeMicroseconds(1500);  // set servo to mid-point
} 

void loop() {} 
```

---

## servo.read()

這個函式可以讀取目前伺服馬達的角度(這個數值紀錄自呼叫`servo.write(angle)`，因此可能與現實情況不符)

### 語法

```arduino
servo.read()
```

`servo`: 一個以`Servo`定義的物件

### 回傳值

一個角度，從0到180度

---

## servo.attached()

回傳`Servo`型態物件是否接上pin

### 語法

```arduino
servo.attached()
```

`servo`: `Servo`定義的物件

### 回傳值

如果有接上，就是`true`，反之`false`

---

## servo.detach()

將`Servo`型態的物件和腳位取消連接，若所有物件都取消連接，則pin 9、pin 10腳位可以使用`analogWrite()`

### 語法

```arduino
servo.detach()
```

`servo`: `Servo`定義的物件

---

## 實作程式


```arduino
#include <Servo.h>   //載入函式庫，這是內建的，不用安裝

Servo myservo;  // 建立SERVO物件


void setup() {
  myservo.attach(9);  // 設定要將伺服馬達接到哪一個PIN腳
}

void loop() {   
  myservo.write(0);  //旋轉到0度，就是一般所說的歸零
  delay(1000);
  myservo.write(90); //旋轉到90度
  delay(1000);
  myservo.write(180); //旋轉到180度
  delay(1000);
  myservo.write(90);
  delay(1000);
}
```

---

> 參考資料: 
> [Arduino Servo - attach()](https://www.arduino.cc/reference/en/libraries/servo/attach/)
> [Servo - write()](https://www.arduino.cc/reference/en/libraries/servo/write/)
> [Servo - writeMicroseconds()](https://www.arduino.cc/reference/en/libraries/servo/writemicroseconds/)
> [Servo - read()](https://www.arduino.cc/reference/en/libraries/servo/read/)
> [Servo - attached()](https://www.arduino.cc/reference/en/libraries/servo/attached/)
> [Servo - detach()](https://www.arduino.cc/reference/en/libraries/servo/detach/)
> 
> [Arduino範例 SG90 Servo伺服馬達](https://blog.jmaker.com.tw/arduino-servo-sg90/)
> [Arduino Servo Library](https://www.arduino.cc/reference/en/libraries/servo/)
> [[TDK2021電路圖]]
> [[tb6560步進馬達驅動板]]