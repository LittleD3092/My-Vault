標籤: #arduino 

函式庫，可以用ps2搭配arduino 使用

![[ps2x_lib.h 手把按鍵對應圖.png]]

```arduino
#include <PS2X_lib.h>           //include ps2 console library 

//ps2 port setting
//from left to right
#define dataPort 8                     //port 1: data
#define commandPort 9                  //port 2: command
                                        //port 3: shock motor power

//goundPort GND                         //port 4: ground
//Vcc(3.3V) Vin                         //port 5: 3.3V power
#define attPort 10                      //port 6: attribute select

#define clockPort 11                    //port 7: clock
                                        //port 8: NULL
                                        //port 9: ACK response

//feature setting
#define supportAnalogJoystick true      //does it support anolog joystick?
#define supportVibration true           //does it support vibration?

//initializing data
PS2X ps2x;                      //create object ps2 console
int error = 0;
byte type = 0;
byte vibrate = 0;

//dead area set
#define deadArea 5







//define car wheel motor
//Left wheel
//const int wheelLeft1 = 2;
//const int wheelLeft2 = 3;
//const int wheelLeftS = 3;
const int wheelLeftSpeed = 200;

//Right wheel
//const int wheelRight1 = 4;
//const int wheelRight2 = 5;
//const int wheelRightS = 11;
const int wheelRightSpeed = 200;





void setup()
{
  	Serial.begin(9600);
  	Serial.println();
  	Serial.println("start");

  	//test ps2 console is connected or not
  	do
  	{  
    	error = ps2x.config_gamepad(clockPort, commandPort, attPort, dataPort, supportAnalogJoystick, supportVibration);
    	if(error == 0)            Serial.println("Controller found");
    	else if(error == 1)       Serial.println("ERROR: No Controller found");
    	else if(error == 2)       Serial.println("ERROR: Controller not accepting command");  
    	else if(error == 3)       Serial.println("ERROR: Controller refusing to enter Pressures Mode, may not support it");
	}while(error != 0);

  	//determine controller type
  	type = ps2x.readType();
  	switch(type)
  	{
  	  	case 0:   Serial.println("Unknown controller type");      break;
  	  	case 1:   Serial.println("DualShock controller found");   break;
    	case 2:   Serial.println("GuitarHero controller found");    break;
  	}

}

void loop()
{
	//if no controller found, stop arduino
  	if(error == 1)    return;

  	//read_gamepad( small motor(boolean), big motor(byte) )
  	//you should at least do this once for one second
  	ps2x.read_gamepad(false, vibrate);

  	//read ps2 gamepad
  	int ps2_left_analog_Y = 255 - ps2x.Analog(PSS_LY);
  	int ps2_right_analog_X = ps2x.Analog(PSS_RX);
  	Serial.print("ps2 left y = ");				Serial.println(ps2_left_analog_Y);
  	Serial.print("ps2 right x = ");				Serial.println(ps2_right_analog_X);

  	bool front = (ps2_left_analog_Y  > 256/2 + deadArea/2);
  	bool back  = (ps2_left_analog_Y  < 256/2 - deadArea/2);
  	bool right = (ps2_right_analog_X > 256/2 + deadArea/2);
  	bool left  = (ps2_right_analog_X < 256/2 - deadArea/2);

  	if( front && !back && !right && !left)			//foward
  	{
  		Serial.print("right motor speed = ");	Serial.println(wheelRightSpeed * 0.8);
  		Serial.print("left  motor speed = ");	Serial.println(wheelLeftSpeed  * 0.8);
	}
	if(!front &&  back && !right && !left)			//backward
  	{
  		Serial.print("right motor speed = ");	Serial.println(wheelRightSpeed * (-0.8));
  		Serial.print("left  motor speed = ");	Serial.println(wheelLeftSpeed  * (-0.8));
	}
	if(!front && !back &&  right && !left)			//turn right
  	{
  		Serial.print("right motor speed = ");	Serial.println(wheelRightSpeed * (-0.5));
  		Serial.print("left  motor speed = ");	Serial.println(wheelLeftSpeed  * 0.5);
	}
	if(!front && !back && !right &&  left)			//turn left
  	{
  		Serial.print("right motor speed = ");	Serial.println(wheelRightSpeed * 0.5);
  		Serial.print("left  motor speed = ");	Serial.println(wheelLeftSpeed  * (-0.5));
	}
	if( front && !back &&  right && !left)			//front right
  	{
  		Serial.print("right motor speed = ");	Serial.println(wheelRightSpeed * 0.6);
  		Serial.print("left  motor speed = ");	Serial.println(wheelLeftSpeed  * 1);
	}
	if( front && !back && !right &&  left)			//front left
  	{
  		Serial.print("right motor speed = ");	Serial.println(wheelRightSpeed * 1);
  		Serial.print("left  motor speed = ");	Serial.println(wheelLeftSpeed  * 0.6);
	}
	if(!front &&  back &&  right && !left)			//back right
  	{
  		Serial.print("right motor speed = ");	Serial.println(wheelRightSpeed * (-0.6));
  		Serial.print("left  motor speed = ");	Serial.println(wheelLeftSpeed  * (-1));
	}
	if(!front &&  back && !right &&  left)			//back left
  	{
  		Serial.print("right motor speed = ");	Serial.println(wheelRightSpeed * (-1));
  		Serial.print("left  motor speed = ");	Serial.println(wheelLeftSpeed  * (-0.6));
	}
	if(!front && !back && !right && !left)			//stop
  	{
  		Serial.println("right motor speed = 0");
  		Serial.println("left  motor speed = 0");
	}

	Serial.println("");

  	delay(500);
}
```

```arduino
#include <ps2x_lib.h>  // 目前是1.6版

PS2X ps2x; // 建立PS2控制器的類別實體

/*
此程式庫不支援熱插拔，亦即，你必須在連接控制器後重新啟動Arduino，
或者在連接控制器之後再次呼叫config_gamepad()函數。
*/
int error = 0; 
byte type = 0;
byte vibrate = 0;

void setup(){
 Serial.begin(57600);

 // ********注意！******** 1.6版的新語法：
 // 控制器接腳設置並驗證是否有錯誤:  GamePad(時脈腳位, 命令腳位, 選取腳位, 資料腳位, 是否支援類比按鍵, 是否支援震動) 
 error = ps2x.config_gamepad(13,11,10,12, true, true);
 
 if(error == 0) { // 如果控制器連接沒有問題，就顯示底下的訊息。
   Serial.println("Found Controller, configured successful");
   Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder;");
   Serial.println("holding L1 or R1 will print out the analog stick values.");
   Serial.println("Go to www.billporter.info for updates and to report bugs.");
 }
   
  else if(error == 1) // 找不到控制器，顯示底下的錯誤訊息。
   Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");
   
  else if(error == 2)  // 發現控制器，但不接受命令，請參閱程式作者網站的除錯說明。
   Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");
   
  else if(error == 3) // 控制器拒絕進入類比感測壓力模式，或許是此控制器不支援的緣故。
   Serial.println("Controller refusing to enter Pressures mode, may not support it. ");
   
   type = ps2x.readType();  // 偵測控制器器的類型
     switch(type) {
       case 0:
        Serial.println("Unknown Controller type");   // 未知的控制器類型
       break;
       case 1:
        Serial.println("DualShock Controller Found");  // 發現DualShock控制器
       break;
       case 2:
         Serial.println("GuitarHero Controller Found");  // 發現吉他英雄控制器
       break;
     }
}

void loop(){
   /* 
   你必須執行ps2x.read_gamepad()方法來獲取新的按鍵值，語法格式：
   ps2x.read_gamepad(小馬達開或關, 大馬達強度值從0~255)
   如果不啟用震動功能，請執行
   ps2x.read_gamepad();
   不需要任何參數。
   
   你應該至少一秒鐘執行一次這個方法。
   */
 if(error == 1) // 如果沒發現任何控制器，則跳出迴圈。
  return; 
  
 if(type == 1) { // 這是標準的DualShock控制器
    ps2x.read_gamepad(false, vibrate);			// 讀取控制器並且命令大的震動馬達以"vibrate"變數值的速度旋轉
    
    if(ps2x.Button(PSB_START))					// 查看「開始」鍵是否被按住
      Serial.println("Start is being held");
    if(ps2x.Button(PSB_SELECT))				// 查看「選擇」鍵是否被按住
      Serial.println("Select is being held");
         
    if(ps2x.Button(PSB_PAD_UP)) {         // 若「上」按鍵被按著
      Serial.print("Up held this hard: ");
      Serial.println(ps2x.Analog(PSAB_PAD_UP), DEC);
    }
    if(ps2x.Button(PSB_PAD_RIGHT)){
      Serial.print("Right held this hard: ");
      Serial.println(ps2x.Analog(PSAB_PAD_RIGHT), DEC);
    }
    if(ps2x.Button(PSB_PAD_LEFT)){
      Serial.print("LEFT held this hard: ");
      Serial.println(ps2x.Analog(PSAB_PAD_LEFT), DEC);
    }
    if(ps2x.Button(PSB_PAD_DOWN)){
      Serial.print("DOWN held this hard: ");
      Serial.println(ps2x.Analog(PSAB_PAD_DOWN), DEC);
    }   
  
    vibrate = ps2x.Analog(PSAB_BLUE);	// 依據你按著X按鍵的力道來調整馬達的震動強度 

    if (ps2x.NewButtonState())        	// 若「按下」或「放開」任何按鈕
    {
      if(ps2x.Button(PSB_L3))
        Serial.println("L3 pressed");
        if(ps2x.Button(PSB_R3))
         Serial.println("R3 pressed");
        if(ps2x.Button(PSB_L2))
         Serial.println("L2 pressed");
        if(ps2x.Button(PSB_R2))
         Serial.println("R2 pressed");
        if(ps2x.Button(PSB_GREEN))    // 若被按下的是三角按鍵
         Serial.println("Triangle pressed"); 
    } 
    
    if(ps2x.ButtonPressed(PSB_RED))             // 若「按下」圈圈按鍵
         Serial.println("Circle just pressed");
         
    if(ps2x.ButtonReleased(PSB_PINK))           // 若「放開」方塊按鍵
         Serial.println("Square just released");     
    
    if(ps2x.NewButtonState(PSB_BLUE))            // 若「按下」或「放開」叉叉按鍵
         Serial.println("X just changed");    
    
    if(ps2x.Button(PSB_L1) || ps2x.Button(PSB_R1)) //　若按著PSB_L1或PSB_R1按鍵
    {  // 顯示左右類比搖桿的值
        Serial.print("Stick Values:");
        Serial.print(ps2x.Analog(PSS_LY), DEC);
        Serial.print(",");
        Serial.print(ps2x.Analog(PSS_LX), DEC); 
        Serial.print(",");
        Serial.print(ps2x.Analog(PSS_RY), DEC); 
        Serial.print(",");
        Serial.println(ps2x.Analog(PSS_RX), DEC); 
    }   
 }
 delay(50);
}
```

---

> 參考資料:
> [ps2 arduino 教學](https://swf.com.tw/?p=435)
> [[類比搖桿模組]]
> [[TDK2021電路圖]]
> [[Keypad]]
> [[IMU]]