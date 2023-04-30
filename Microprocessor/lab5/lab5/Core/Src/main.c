#include "stm32l476xx.h"
#include "helper_functions.h"
#include "7seg.h"
#include "keypad.h"
#include "led_button.h"
#include "timer.h"

// Define pins for 7seg
#define SEG_gpio GPIOC
#define DIN_pin 3
#define CS_pin 4
#define CLK_pin 5

// Define pins for keypad
#define COL_gpio GPIOA
#define COL_pin 6       // 6 7 8 9
#define ROW_gpio GPIOB
#define ROW_pin 3       // 3 4 5 6

// Define pins for led (default use on-board led PA5)
#define LED_gpio GPIOA
#define LED_pin 5

// Define pins for button (default use on-board button PC13)
#define BUTTON_gpio GPIOC
#define BUTTON_pin 13

// Define Counter timer
#define COUNTER_timer TIM2
#define TIME_SEC 10000 // maximum time displayed on 7seg
// Buzzer is fixed to PA0 due to its need for PWM signal
// Can change to other ports if needed, but need to look up the reference

// Use to decide which part of the code will run
// Use define & ifdef to control
// #define lab_modify_system_clock
#define lab_counter
//#define lab_music_keyboard
//#define lab_music_song

int main(){
	// Cause we want to use floating points we need to init FPU
	FPU_init();

#ifdef lab_modify_system_clock

	SevenSeg seg7;
	SevenSeg__init(&seg7, SEG_gpio, DIN_pin, CS_pin, CLK_pin);

	if(init_led(LED_gpio, LED_pin) != 0){
		// Fail to init led
		return -1;
	}
	if(init_button(BUTTON_gpio, BUTTON_pin) != 0){
		// Fail to init button
		return -1;
	}

	int speed=0, trans[6]={1, 6, 10, 16, 20, 40};
	SystemClock_Config(trans[speed]);
	SevenSeg__printNum(&seg7, trans[speed]);

	// Used to indicate led state: un-lit(0) or lit(1)
	int state=0;
	// button_press_cycle_per_second (How many button press segments in a second)
	int button_press_cycle_per_second = 10;
	// Use to state how many cycles to check per button_press_cycle
	int debounce_cycles = 100;
	// Use to state the threshold when we consider a button press
	int debounce_threshold = debounce_cycles*0.7;
	// Used to implement negative edge trigger 0=not-presses 1=pressed
	int last_button_state=0;

	while(1){
		for(int a=0;a<button_press_cycle_per_second;a++){
			// Simple Debounce without interrupt
			int pos_cnt=0;
			for(int a=0;a<debounce_cycles;a++){
				// If button press add count
				if(read_gpio(BUTTON_gpio, BUTTON_pin)==0){
					pos_cnt++;
				}
				delay_without_interrupt(1000/(button_press_cycle_per_second*debounce_cycles));
			}
			// Check if need to change state
			if(pos_cnt>debounce_threshold){
				if(last_button_state==0){
					// Pressed button - Pos edge
					// Do nothing
				}
				else{
					// Pressed button - Continued pressing
					// Do nothing
				}
				last_button_state = 1;
			}
			else{
				if(last_button_state==0){
					// Released button - Not pressing
					// Do nothing
				}
				else{
					// Released button - Neg edge
					// Change speed and change system clock
					speed = (speed+1)%6;
					SystemClock_Config(trans[speed]);
					SevenSeg__printNum(&seg7, trans[speed]);
				}
				last_button_state = 0;
			}
		}
		if(state==1){
			reset_gpio(LED_gpio, LED_pin);
		}
		else{
			set_gpio(LED_gpio, LED_pin);
		}
		state = 1-state;
	}

#endif

#ifdef lab_counter

	SevenSeg seg7;
	SevenSeg__init(&seg7, SEG_gpio, DIN_pin, CS_pin, CLK_pin);

	Timer timer;
	Timer__init(&timer, COUNTER_timer);
	
	while(1)
	{
		int time_msecs = Timer__get_msecs(&timer);
		struct fraction num = {time_msecs/10, 100};
		SevenSeg__printFraction(&seg7, num);
	}

#endif

	// Leave a empty while loop in order to stop it from
	// jumping back to startup script's LoopForever
	//
	// Useful when debugging using debugger:
	//   If jump to "LoopForever" means unexpected error happens
	//   Else, the code has ended
	while(1){}

	return 0;
}
