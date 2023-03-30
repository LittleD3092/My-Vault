#include "stm32l476xx.h"
#include "helper_functions.h"
#include "led_button.h"
#include "7seg.h"

// Define pins for 4 leds
#define LED_gpio GPIOB
#define LED1_pin 3
#define LED2_pin 4
#define LED3_pin 5
#define LED4_pin 6

// Define pins for button (default use on-board button PC13)
#define BUTTON_gpio GPIOC
#define BUTTON_pin 13

// Define pins for 7seg
//#define SEG_gpio GPIOB
//#define DIN_pin 3
//#define CS_pin 4
//#define CLK_pin 5

// Use to decide which part of the code will run
// Use define & ifdef to control
//#define lab_led
#define lab_led_button
//#define lab_7seg_non_decode
//#define lab_7seg_decode

int main(){

#ifdef lab_led

	if(init_led(LED_gpio, LED1_pin) != 0 || init_led(LED_gpio, LED2_pin) != 0 || init_led(LED_gpio, LED3_pin) != 0 || init_led(LED_gpio, LED4_pin) != 0){
		// Fail to init LED
		return -1;
	}

	// Direction to shift 0=left, 1=right
	int shift_direction = 0;
	int led_data = 0b000011;
	int leds[4] = {LED1_pin, LED2_pin, LED3_pin, LED4_pin};

	while(1){
		// Set or Reset Leds
		for(int a=0;a<4;a++){
			// Active Low
			if((led_data>>(a+1))&0x1){
				reset_gpio(LED_gpio, leds[a]);
			}
			else{
				set_gpio(LED_gpio, leds[a]);
			}
		}

		// Shift led_data
		if(shift_direction==0){
			led_data = (led_data<<1);
		}
		else{
			led_data = (led_data>>1);
		}

		// Check to see if change shift direction
		if(led_data==0b000011 || led_data==0b110000){
			shift_direction = 1-shift_direction;
		}

		// Delay for 1 sec
		delay_without_interrupt(1000);
	}

#endif

#ifdef lab_led_button

	if(init_led(LED_gpio, LED1_pin) != 0 || init_led(LED_gpio, LED2_pin) != 0 || init_led(LED_gpio, LED3_pin) != 0 || init_led(LED_gpio, LED4_pin) != 0 ||
	   init_button(BUTTON_gpio, BUTTON_pin) != 0){
		// Fail to init LED
		return -1;
	}

	// Direction to shift 0=left, 1=right
	int shift_direction = 0;
	int led_data = 0b000011;
	int leds[4] = {LED1_pin, LED2_pin, LED3_pin, LED4_pin};
	int stop = 0; // 0=run, 1=stop

	while(1){
		// Set or Reset Leds
		for(int a=0;a<4;a++){
			// Active Low
			if((led_data>>(a+1))&0x1){
				reset_gpio(LED_gpio, leds[a]);
			}
			else{
				set_gpio(LED_gpio, leds[a]);
			}
		}

		// Shift led_data
		if(shift_direction==0 && stop==0){
			led_data = (led_data<<1);
		}
		else if(shift_direction==1 && stop==0){
			led_data = (led_data>>1);
		}

		// Check to see if change shift direction
		if(led_data==0b000011 || led_data==0b110000){
			shift_direction = 1-shift_direction;
		}

		// Check to see if button is pressed
		if(read_gpio(BUTTON_gpio, BUTTON_pin)==0){
			stop = 1-stop;
		}

		// Delay for 1 sec
		delay_without_interrupt(500);
	}

#endif


	while(1){}

	return 0;
}
