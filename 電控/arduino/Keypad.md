標籤: #arduino 

只是比較多按鈕的打包，並且用特殊的方式連接。每一排和列有一條導線連接該排或列所有按鈕，如下圖:
![[Pasted image 20210815154859.png]]

因此一個 4\*4 的鍵盤有 $4+4=8$ 條線接出

# 腳位

![[Pasted image 20210815154634.png]]
![[Pasted image 20210815155156.png]]

總共有八個角位，所有腳位都可以接Digital


# 程式

![[Pasted image 20210816162641.png]]
使用 Adafruit keypad

## 函式庫
```arduino
#include "Adafruit_Keypad.h"
```

## 物件
```arduino
Adafruit_Keypad keypad = Adafruit_Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS )
```

- `keys`: `char` 型態二維陣列，裡面紀錄按鍵對應的字元
- `rowPins`: `byte` 型態一維陣列，紀錄腳位
- `colPins`: `byte` 型態一維陣列，紀錄腳位
- `ROWS`: `byte` 型態整數，紀錄列數(橫的)
- `COLS`: `byte` 型態整數，紀錄行數(直的)

## 開始
```arduino
keypad.begin();
```
寫在setup裡面

## 紀錄事件
```arduino
keypad.tick();
```
寫在loop裡面的前面

## 有動靜
```arduino
keypad.available();
```
當有按鈕按下或鬆開時為true

## 讀取
```arduino
keypad.read();
```
回傳鍵盤的狀態，為 `keypadEvent` 型態，還需要處理

## 處理keypadEvent
```arduino
(char)event.bit.KEY;
event.bit.EVENT
```
上面的會回傳按下的按鍵，下面的會回傳是按下還是鬆開

上面的要改變成`char`的型態才方便使用
下面的有兩種常數:
- 按下，回傳`KEY_JUST_PRESSED`
- 放開，回傳`KEY_JUST_RELEASED`

## 範例

```arduino
//4x4薄膜鍵盤範例程式

#include "Adafruit_Keypad.h"

const byte ROWS = 4; // 列數(橫的)
const byte COLS = 4; // 行數(直的)
//鍵盤上每一個按鍵的名稱
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {11, 10, 9, 8}; //定義列的腳位
byte colPins[COLS] = {7, 6, 5, 4}; //定義行的腳位

//初始化鍵盤
Adafruit_Keypad customKeypad = Adafruit_Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  customKeypad.begin();
  Serial.println("KeyPad Test...");
}

void loop() {
  // 開始偵測使用者的按鍵狀態
  customKeypad.tick();

  //判斷按了哪一個鍵
  while(customKeypad.available()){
    keypadEvent e = customKeypad.read();
    Serial.print((char)e.bit.KEY);
    if(e.bit.EVENT == KEY_JUST_PRESSED) Serial.println(" pressed"); 
    //按下的狀態是KEY_JUST_PRESSED
    else if(e.bit.EVENT == KEY_JUST_RELEASED) Serial.println(" released");  
    //放開的狀態是KEY_JUST_RELEASED
  }

  delay(10);
}
```

---

> 參考資料:
> [keypad 教學(英文)](https://www.circuitbasics.com/how-to-set-up-a-keypad-on-an-arduino/)
> [keypad 教學(傑森創工)](https://blog.jmaker.com.tw/arduino-keypad-4x4/)