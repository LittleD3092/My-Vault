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
