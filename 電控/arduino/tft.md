標籤: #arduino 

---

![[arduino TFT screen.png]]

# 螢幕座標

螢幕用一個座標來表示每個像素位置
- 左上: (0, 0)
- 右上: (0, 159)
- 左下: (127, 0)
- 右下: (127, 159)

> 也可以將螢幕直向放置，這時需要使用 `setRotation(0)` ，然後程式就會把 x y 軸調換

# Hardware vs. Software SPI

這兩個都可以使用，但是在 hardware interface 繪圖速度會比較快，並且如果要使用到 SD 卡就一定要使用 hardware interface

# 腳位

![[arduino tft screen pins.png]]

`5V`, `BL` : 接 arduino `5V`
`MISO`, `SCK`, `MOSI` : 接 arduino 相應腳位
`LCD CS` : LCD 訊號線，接任意 digital
`SD CS` : SD 卡讀卡機，接任意 digital
`D/C` : 訊號線，接任意 digital
`RESET` : reset 跳線，接任意 digital
`GROUND` : 接 arduino `GND`

# include

```arduino
#include <TFT.h>
#include <SPI.h>
```

# 物件定義

```arduino
TFT myScreen = TFT(CS, DC, RESET)
```

`CS` : `LCD CS`
`DC` : `D/C`
`RESET` : `RESET`

# setup

```arduino
void setup(){

  myScreen.begin();

  myScreen.background(0,0,0);  // clear the screen with black

  delay(1000);  // pause for dramatic effect
}
```

# 畫圖

- `myScreen.line(start_x, start_y, end_x, end_y)` : 在兩個座標間劃一條線
- `myScreen.rect(start_x, start_y, end_x, end_y)` : 給兩個座標，左上和右下，劃一個長方形
- `myScreen.point(x, y)` : 在 (x, y) 畫一個點
- `myScreen.stroke(R, G, B)` : 設定外框線或線條顏色(RGB)，三個參數都是十進位
- `myScreen.noStroke()` : 設定無外框
- `myScreen.fill(R, G, B)` : 設定填滿色彩(RGB)，三個參數都是十進位
- `myScreen.background(R, G, B)` : 把整個螢幕設為同一個顏色，通常用來清除螢幕

# 動態物件範例程式

因為 arduino 運算能力不強，因此不能時常呼叫 `myScreen.background(0, 0, 0)` 來清空螢幕並製作動態效果
下面是範例(一個會彈來彈去的點)，利用把上一幀物件的地方塗黑來製造動態效果

```arduino
void loop(){

  // update the location of the dot

  xPos = xPos + xDir;

  yPos = yPos + yDir;

  // check if the current location is different than the previous

  if(xPos != xPrev || yPos != yPrev){

    myScreen.stroke(0,0,0); // set the stroke color to black

    myScreen.point(xPrev, yPrev); // color in the previous point

  }

  // draw a point in the current location

  myScreen.stroke(255,255,255);

  myScreen.point(xPos, yPos);

  // if the x or x position is at the screen edges, reverse direction

  if(xPos >= 160 || xPos <= 0){

    xDir = xDir*-1;

  }

  if(yPos >= 128 || yPos <= 0){

    yDir = yDir*-1;

  }

  // update the point's previous location

  xPrev=xPos;

  yPrev=yPos;

  // a 33ms delay means the screen updates 30 times a second

  delay(33);

}
```

# 文字

預設大小是 5 pixel 寬， 8 pixel 高，可以調整大小為這個大小的倍數
底下是計時器範例，通常不會變動的字會放在 `setup` ，會變動的字則放在 `loop`

```arduino
#include <TFT.h> // Hardware-specific library
#include <SPI.h>

#define CS   10
#define DC   9
#define RESET  8

// pin definition for the Leonardo
// #define CS   7
// #define DC   0
// #define RESET  1

TFT myScreen = TFT(CS, DC, RESET);

// variable to keep track of the elapsed time
int counter = 0;
// char array to print time
char printout[4];

void setup(){

  myScreen.begin();

  myScreen.background(0,0,0); // clear the screen

  myScreen.stroke(255,0,255);

  // static text

  myScreen.text("Running for",0,0);

  myScreen.text("seconds",0,30);

  // increase font size for text in loop()

  myScreen.setTextSize(3);
}

void loop(){

    // get elapsed time

    counter = millis();

    // convert to a string

    String elapsedTime = String(counter/1000);

    // add to an array

    elapsedTime.toCharArray(printout,4);

    // print out and erase

    myScreen.stroke(255,255,255);

    myScreen.text(printout,0,10);

    delay(1000);

    myScreen.stroke(0,0,0);

    myScreen.text(printout,0,10);
}
```

# 從 SD 卡印出圖片

注意要印出的圖片尺寸要對， arduino 不會調整圖片大小

```arduino
// include the necessary libraries
#include <SPI.h>
#include <SD.h>
#include <TFT.h> // Hardware-specific library

// pin definition for the Uno
#define SD_CS  11
#define LCD_CS 10
#define DC    9
#define RESET    8

// pin definition for the Leonardo
// #define SD_CS  8
// #define LCD_CS 7
// #define DC   0
// #define RESET  1

TFT myScreen = TFT(LCD_CS, DC, RESET);

// this variable represents the image to be drawn on screen

PImage image;

void setup() {

  // initialize the serial port

  Serial.begin(9600);

  while (!Serial) {

    // wait for serial line to be ready

    // needed for the Leonardo

  }

  // try to access the SD card

  Serial.print("Initializing SD card...");

  if (!SD.begin(SD_CS)) {

    Serial.println("failed!");

    return;

  }

  Serial.println("OK!");

  // initialize and clear the GLCD screen

  myScreen.begin();

  myScreen.background(255, 255, 255);

  // load the image from the SD card

  image = myScreen.loadImage("arduino.bmp");

  // check if the image loaded properly

  if (image.isValid() != true) {

    Serial.println("error while loading arduino.bmp");

  }

  //write the image on screen

  myScreen.image(image, 0, 0);
}

void loop(){
// nothing happening here
}
```

# 更多資訊

[TFT library - arduino](https://www.arduino.cc/en/Reference/TFTLibrary)

---

參考資料:

[TFT guide - arduino](https://www.arduino.cc/en/Guide/TFT)
[[SSD1306]]