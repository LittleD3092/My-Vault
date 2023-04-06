# 微處理機 LAB 3 7-segment

## PART 1. 實作題

### Lab 3.2 學號顯示 use code-B decode mode

`src/main.c`:

```c
#include "stm32l476xx.h"
#include "helper_functions.h"
#include "led_button.h"
#include "7seg.h"

// Define pins for 4 leds
//#define LED_gpio GPIOA
//#define LED1_pin 5
//#define LED2_pin 6
//#define LED3_pin 7
//#define LED4_pin 8

// Define pins for button (default use on-board button PC13)
#define BUTTON_gpio GPIOC
#define BUTTON_pin 13

// Define pins for 7seg
#define SEG_gpio GPIOB
#define DIN_pin 3
#define CS_pin 4
#define CLK_pin 5

// Use to decide which part of the code will run
// Use define & ifdef to control
// #define lab_led
// #define lab_led_button
// #define lab_7seg_non_decode
// #define lab_7seg_decode
#define lab_7seg_student_id

int main(){


#ifdef lab_7seg_non_decode

	if(init_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin) != 0){
		// Fail to init 7seg
		return -1;
	}

	// Set Decode Mode to non-decode mode
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_DECODE_MODE, 0x00);
	// Set Scan Limit to digit 0 only
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_SCAN_LIMIT, 0x00);
	// Wakeup 7seg
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_SHUTDOWN, 0x01);

	int SEG_DATA_NON_DECODE_LOOP[17] = {
		SEG_DATA_NON_DECODE_0,
		SEG_DATA_NON_DECODE_1,
		SEG_DATA_NON_DECODE_2,
		SEG_DATA_NON_DECODE_3,
		SEG_DATA_NON_DECODE_4,
		SEG_DATA_NON_DECODE_5,
		SEG_DATA_NON_DECODE_6,
		SEG_DATA_NON_DECODE_7,
		SEG_DATA_NON_DECODE_8,
		SEG_DATA_NON_DECODE_9,
		SEG_DATA_NON_DECODE_0,
		SEG_DATA_NON_DECODE_A,
		SEG_DATA_NON_DECODE_B,
		SEG_DATA_NON_DECODE_C,
		SEG_DATA_NON_DECODE_D,
		SEG_DATA_NON_DECODE_E,
		SEG_DATA_NON_DECODE_F
	};

	// Loop through all elements
	int current=0;
	while(1){
		// Write to digit 0
		send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_DIGIT_0, SEG_DATA_NON_DECODE_LOOP[current]);
		current = (current+1)%17;
		delay_without_interrupt(1000);
	}

#endif

#ifdef lab_7seg_student_id

	// constant for student id
	// DONT enter non-numeric character
	char student_id[9] = "09611066";

	// setup 7seg
	if(init_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin) != 0){
		// Fail to init 7seg
		return -1;
	}
	// Set all digits to decode mode
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_DECODE_MODE, 0xFF);
	// Set Scan Limit to all digits (digit 0 to digit 7)
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_SCAN_LIMIT, 0x07);
	// Wakeup 7seg
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_SHUTDOWN, 0x01);
	// Set brightness to 5/15
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_INTENSITY, 0x05);

	// Print student id
	for(int i = 0; i < 8; i++)
	{
		send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_DIGIT_7-i, SEG_DATA_DECODE_0+student_id[i]-'0');
	}

#endif

	while(1){}

	return 0;
}
```

因為 `inc/7seg.h` 中的常數 `SEG_ADDRESS_INTENSITY` 誤拼成 `SEG_ADDRESS_ITENSITY`，因此在這裡附上修正的版本：

```c
#ifndef __7seg__H__
#define __7seg__H__

#include "stm32l476xx.h"

// Define a lot of Non-Decode Mode Constants
#define SEG_DATA_NON_DECODE_0		0b1111110
#define SEG_DATA_NON_DECODE_1		0b0110000
#define SEG_DATA_NON_DECODE_2		0b1101101
#define SEG_DATA_NON_DECODE_3		0b1111001
#define SEG_DATA_NON_DECODE_4		0b0110011
#define SEG_DATA_NON_DECODE_5		0b1011011
#define SEG_DATA_NON_DECODE_6		0b1011111
#define SEG_DATA_NON_DECODE_7		0b1110000
#define SEG_DATA_NON_DECODE_8		0b1111111
#define SEG_DATA_NON_DECODE_9		0b1111011
#define SEG_DATA_NON_DECODE_A		0b1110111
#define SEG_DATA_NON_DECODE_B		0b0011111
#define SEG_DATA_NON_DECODE_C		0b1001110
#define SEG_DATA_NON_DECODE_D		0b0111101
#define SEG_DATA_NON_DECODE_E		0b1001111
#define SEG_DATA_NON_DECODE_F		0b1000111
#define SEG_DATA_NON_DECODE_DASH	0b0000001
#define SEG_DATA_NON_DECODE_BLANK	0b0000000

// Define ADDRESS Constants for 7seg commands
#define SEG_ADDRESS_NOP				0
#define SEG_ADDRESS_DIGIT_0			1
#define SEG_ADDRESS_DIGIT_1			2
#define SEG_ADDRESS_DIGIT_2			3
#define SEG_ADDRESS_DIGIT_3			4
#define SEG_ADDRESS_DIGIT_4			5
#define SEG_ADDRESS_DIGIT_5			6
#define SEG_ADDRESS_DIGIT_6			7
#define SEG_ADDRESS_DIGIT_7			8
#define SEG_ADDRESS_DECODE_MODE		9
#define SEG_ADDRESS_INTENSITY		10
#define SEG_ADDRESS_SCAN_LIMIT		11
#define SEG_ADDRESS_SHUTDOWN		12
#define SEG_ADDRESS_DISPLAY_TEST	15

// Define DATA Constants for 7seg commands
#define SEG_DATA_DECODE_0		0
#define SEG_DATA_DECODE_1		1
#define SEG_DATA_DECODE_2		2
#define SEG_DATA_DECODE_3		3
#define SEG_DATA_DECODE_4		4
#define SEG_DATA_DECODE_5		5
#define SEG_DATA_DECODE_6		6
#define SEG_DATA_DECODE_7		7
#define SEG_DATA_DECODE_8		8
#define SEG_DATA_DECODE_9		9
#define SEG_DATA_DECODE_DASH	10
#define SEG_DATA_DECODE_E		11
#define SEG_DATA_DECODE_H		12
#define SEG_DATA_DECODE_L		13
#define SEG_DATA_DECODE_P		14
#define SEG_DATA_DECODE_BLANK	15

// Init all GPIOs for 7seg
int init_7seg(GPIO_TypeDef* gpio, int DIN, int CS, int CLK);

// Send commands to 7seg controller
void send_7seg(GPIO_TypeDef* gpio, int DIN, int CS, int CLK, int address, int data);


#endif

```

成果如下：

109611066:

![[109611066.jpg|400]]

109611030:

![[109611030.jpg|400]]

## PART 2. 實作題

### Lab 3.3顯示Fibonacci數

`src/main.c`:

```c
#include "stm32l476xx.h"
#include "helper_functions.h"
#include "led_button.h"
#include "7seg.h"

// Define pins for 4 leds
//#define LED_gpio GPIOA
//#define LED1_pin 5
//#define LED2_pin 6
//#define LED3_pin 7
//#define LED4_pin 8

// Define pins for button (default use on-board button PC13)
#define BUTTON_gpio GPIOC
#define BUTTON_pin 13

// Define pins for 7seg
#define SEG_gpio GPIOB
#define DIN_pin 3
#define CS_pin 4
#define CLK_pin 5

// Use to decide which part of the code will run
// Use define & ifdef to control
// #define lab_led
// #define lab_led_button
// #define lab_7seg_non_decode
// #define lab_7seg_decode
// #define lab_7seg_student_id
#define lab_7seg_fibonacci

int main(){


#ifdef lab_7seg_non_decode

	if(init_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin) != 0){
		// Fail to init 7seg
		return -1;
	}

	// Set Decode Mode to non-decode mode
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_DECODE_MODE, 0x00);
	// Set Scan Limit to digit 0 only
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_SCAN_LIMIT, 0x00);
	// Wakeup 7seg
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_SHUTDOWN, 0x01);

	int SEG_DATA_NON_DECODE_LOOP[17] = {
		SEG_DATA_NON_DECODE_0,
		SEG_DATA_NON_DECODE_1,
		SEG_DATA_NON_DECODE_2,
		SEG_DATA_NON_DECODE_3,
		SEG_DATA_NON_DECODE_4,
		SEG_DATA_NON_DECODE_5,
		SEG_DATA_NON_DECODE_6,
		SEG_DATA_NON_DECODE_7,
		SEG_DATA_NON_DECODE_8,
		SEG_DATA_NON_DECODE_9,
		SEG_DATA_NON_DECODE_0,
		SEG_DATA_NON_DECODE_A,
		SEG_DATA_NON_DECODE_B,
		SEG_DATA_NON_DECODE_C,
		SEG_DATA_NON_DECODE_D,
		SEG_DATA_NON_DECODE_E,
		SEG_DATA_NON_DECODE_F
	};

	// Loop through all elements
	int current=0;
	while(1){
		// Write to digit 0
		send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_DIGIT_0, SEG_DATA_NON_DECODE_LOOP[current]);
		current = (current+1)%17;
		delay_without_interrupt(1000);
	}

#endif

#ifdef lab_7seg_student_id

	// constant for student id
	// DONT enter non-numeric character
	char student_id[9] = "09611030";

	// setup 7seg
	if(init_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin) != 0){
		// Fail to init 7seg
		return -1;
	}
	// Set all digits to decode mode
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_DECODE_MODE, 0xFF);
	// Set Scan Limit to all digits (digit 0 to digit 7)
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_SCAN_LIMIT, 0x07);
	// Wakeup 7seg
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_SHUTDOWN, 0x01);
	// Set brightness to 5/15
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_INTENSITY, 0x05);

	// Print student id
	for(int i = 0; i < 8; i++)
	{
		send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_DIGIT_7-i, SEG_DATA_DECODE_0+student_id[i]-'0');
	}

#endif

#ifdef lab_7seg_fibonacci

	// setup 7seg
	if(init_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin) != 0){
		// Fail to init 7seg
		return -1;
	}
	// Set all digits to decode mode
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_DECODE_MODE, 0xFF);
	// Set Scan Limit to all digits (digit 0 to digit 7)
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_SCAN_LIMIT, 0x07);
	// Wakeup 7seg
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_SHUTDOWN, 0x01);
	// Set brightness to 5/15
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_INTENSITY, 0x05);

	// setup button
	if(init_button(BUTTON_gpio, BUTTON_pin) != 0){
		// Fail to init button
		return -1;
	}

	// loop. when button is pressed, print the next fibonacci number
	int a = 0, b = 0, c = 1;
	int button_state = 0;
	// Print first fibonacci number
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_DIGIT_7, SEG_DATA_DECODE_0+c%10);
	while(1){
		if(button_state == 0 && read_gpio(BUTTON_gpio, BUTTON_pin) == 1){
			// Button is pressed
			button_state = 1;

			// update fibonacci number
			a = b;
			b = c;
			c = a+b;

			// overflow
			if(c > 99999999)
			{
				// print -1
				print_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, -1);
				break;
			}
			
			// TODO: print c
			print_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, c);
		}
		else if(button_state == 1 && read_gpio(BUTTON_gpio, BUTTON_pin) == 0){
			// Button is released
			button_state = 0;
		}
		delay_without_interrupt(50);
	}

#endif

	while(1){}

	return 0;
}

```

由於印出一串數字相對繁瑣，因此我們將其封裝成一個函式，參數為要印出的數字，並且將其寫在`print_7seg`函式中。此函式包含在 `src/7seg.c` 中

```c
#include "7seg.h"
#include "helper_functions.h"


// Only allow GPIOA and GPIOB for now
// Can easily extended by adding "else if" cases
int init_7seg(GPIO_TypeDef* gpio, int DIN, int CS, int CLK){
	// Enable AHB2 Clock
	if(gpio==GPIOA){
		RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	}
	else if(gpio==GPIOB){
		RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
	}
	else{
		// Error! Add other cases to suit other GPIO pins
		return -1;
	}

	// Set GPIO pins to output mode (01)
	// First Clear bits(&) then set bits(|)
	gpio->MODER &= ~(0b11 << (2*DIN));
	gpio->MODER |= (0b01 << (2*DIN));
	gpio->MODER &= ~(0b11 << (2*CS));
	gpio->MODER |= (0b01 << (2*CS));
	gpio->MODER &= ~(0b11 << (2*CLK));
	gpio->MODER |= (0b01 << (2*CLK));

	// Close display test
	send_7seg(gpio, DIN, CS, CLK, SEG_ADDRESS_DISPLAY_TEST, 0x00);

	return 0;
}

void send_7seg(GPIO_TypeDef* gpio, int DIN, int CS, int CLK, int address, int data){
	// The payload to send
	int payload = ((address&0xFF)<<8)|(data&0xFF);

	// Start the sending cycles
	// 16 data-bits + 1 CS signal
	int total_cycles = 16+1;

	for(int a=1;a<=total_cycles;a++){
		// Reset CLK when enter
		reset_gpio(gpio, CLK);

		// Set DIN according to data except for last cycle(CS)
		if(((payload>>(total_cycles-1-a))&0x1) && a!=total_cycles){
			set_gpio(gpio, DIN);
		}
		else{
			reset_gpio(gpio, DIN);
		}

		// Set CS at last cycle
		if(a==total_cycles){
			set_gpio(gpio, CS);
		}
		else{
			reset_gpio(gpio, CS);
		}

		// Set CLK when leaving (7seg set data at rising edge)
		set_gpio(gpio, CLK);
	}

	return;
}

// use only if 7seg is in decode mode and only if scan limit is set to 7
// print data to the 7seg display
// return -1 if overflow
int print_7seg(GPIO_TypeDef* gpio, int DIN, int CS, int CLK, int number){
	// overflow
	if(number > 99999999 || number < -9999999)
		return -1;
	
	// negative
	int negative = 0;
	if(number < 0)
	{
		negative = 1;
		number = -number;
	}

	// print digits
	int current_digit = 0;
	while(number != 0)
	{
		int digit = number % 10;
		send_7seg(gpio, DIN, CS, CLK, SEG_ADDRESS_DIGIT_0+current_digit, SEG_DATA_DECODE_0+digit);
		number /= 10;
		current_digit++;
	}

	// print negative sign
	if(negative)
	{
		send_7seg(gpio, DIN, CS, CLK, SEG_ADDRESS_DIGIT_0+current_digit, SEG_DATA_DECODE_DASH);
		current_digit++;
	}

	// clear remaining digits
	while(current_digit <= 7)
	{
		send_7seg(gpio, DIN, CS, CLK, SEG_ADDRESS_DIGIT_0+current_digit, SEG_DATA_DECODE_BLANK);
		current_digit++;
	}

	return 0;
}
```

因為新定義了函式，相對的也要在`inc/7seg.h`中加入函式的宣告

```c
#ifndef __7seg__H__
#define __7seg__H__

#include "stm32l476xx.h"

// Define a lot of Non-Decode Mode Constants
#define SEG_DATA_NON_DECODE_0		0b1111110
#define SEG_DATA_NON_DECODE_1		0b0110000
#define SEG_DATA_NON_DECODE_2		0b1101101
#define SEG_DATA_NON_DECODE_3		0b1111001
#define SEG_DATA_NON_DECODE_4		0b0110011
#define SEG_DATA_NON_DECODE_5		0b1011011
#define SEG_DATA_NON_DECODE_6		0b1011111
#define SEG_DATA_NON_DECODE_7		0b1110000
#define SEG_DATA_NON_DECODE_8		0b1111111
#define SEG_DATA_NON_DECODE_9		0b1111011
#define SEG_DATA_NON_DECODE_A		0b1110111
#define SEG_DATA_NON_DECODE_B		0b0011111
#define SEG_DATA_NON_DECODE_C		0b1001110
#define SEG_DATA_NON_DECODE_D		0b0111101
#define SEG_DATA_NON_DECODE_E		0b1001111
#define SEG_DATA_NON_DECODE_F		0b1000111
#define SEG_DATA_NON_DECODE_DASH	0b0000001
#define SEG_DATA_NON_DECODE_BLANK	0b0000000

// Define ADDRESS Constants for 7seg commands
#define SEG_ADDRESS_NOP				0
#define SEG_ADDRESS_DIGIT_0			1
#define SEG_ADDRESS_DIGIT_1			2
#define SEG_ADDRESS_DIGIT_2			3
#define SEG_ADDRESS_DIGIT_3			4
#define SEG_ADDRESS_DIGIT_4			5
#define SEG_ADDRESS_DIGIT_5			6
#define SEG_ADDRESS_DIGIT_6			7
#define SEG_ADDRESS_DIGIT_7			8
#define SEG_ADDRESS_DECODE_MODE		9
#define SEG_ADDRESS_INTENSITY		10
#define SEG_ADDRESS_SCAN_LIMIT		11
#define SEG_ADDRESS_SHUTDOWN		12
#define SEG_ADDRESS_DISPLAY_TEST	15

// Define DATA Constants for 7seg commands
#define SEG_DATA_DECODE_0		0
#define SEG_DATA_DECODE_1		1
#define SEG_DATA_DECODE_2		2
#define SEG_DATA_DECODE_3		3
#define SEG_DATA_DECODE_4		4
#define SEG_DATA_DECODE_5		5
#define SEG_DATA_DECODE_6		6
#define SEG_DATA_DECODE_7		7
#define SEG_DATA_DECODE_8		8
#define SEG_DATA_DECODE_9		9
#define SEG_DATA_DECODE_DASH	10
#define SEG_DATA_DECODE_E		11
#define SEG_DATA_DECODE_H		12
#define SEG_DATA_DECODE_L		13
#define SEG_DATA_DECODE_P		14
#define SEG_DATA_DECODE_BLANK	15

// Init all GPIOs for 7seg
int init_7seg(GPIO_TypeDef* gpio, int DIN, int CS, int CLK);

// Send commands to 7seg controller
void send_7seg(GPIO_TypeDef* gpio, int DIN, int CS, int CLK, int address, int data);

// Display a number on 7seg
void display_7seg(GPIO_TypeDef* gpio, int DIN, int CS, int CLK, int number);

#endif

```

執行的成果截圖如下：

![[fibonacci.jpg|400]]

執行的成果錄影放在 `media/fibonacci.mp4` 中

## PART 3. 問答題

### 學號為 109611066，模式為 decode

學號十位數為6，除8的餘數也為6，address應該設為7(`0b0111`)
個位數為6，decode data應該設為6(`0b00000110`)

![109611066 decode](pics/109611066%20decode.png)

### 學號為 109611066，模式為 non-decode

學號十位數為6，除8的餘數也為6，address應該設為7(`0b0111`)
個位數為6，decode data應該設為 `0b01011111`

![109611066 non-decode](pics/109611066%20non-decode.png)

### 學號為 109611030，模式為 decode

學號十位數為3，除8的餘數為3，address應該設為4(`0b0100`)
個位數為0，decode data應該設為0 `0b00000000`

![109611030 decode](pics/109611030%20decode.png)

### 學號為 109611030，模式為 non-decode

學號十位數為3，除8的餘數為3，address應該設為4(`0b0100`)
個位數為0，decode data應該設為 `0b01111110`

![109611030 non-decode](pics/109611030%20non-decode.png)