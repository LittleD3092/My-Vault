#include "stm32l476xx.h"
#include "helper_functions.h"
#include "7seg.h"
#include "keypad.h"
#include "led_button.h"
#include "timer.h"
#include "speaker.h"

// Define pins for 7seg
#define SEG_gpio GPIOC
#define DIN_pin 3
#define CS_pin 4
#define CLK_pin 5

// Define pins for keypad
// If need to change need to also change EXTI_Setup and IRQHandler
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

// Buzzer is fixed to PA0 due to its need for PWM signal
// Can change to other ports if needed, but need to look up the reference
#define SPEAKER_gpio GPIOA
#define SPEAKER_pin 0

// Use to decide which part of the code will run
// Use define & ifdef to control
// #define lab_systick_blink
// #define lab_systick_blink_change_freq
// #define lab_interrupt_keypad
#define lab_alarm

// Remember to use correct "startup_stm32.s"

#ifdef lab_interrupt_keypad
void (*KeypadInterrupt__callback)(KeypadInterrupt*);
KeypadInterrupt* KeypadInterrupt__self;
#endif

#ifdef lab_alarm
// for alarm countdown
int remainingTime = 0;
// for music playing
double musicCounterMs = 0;
// callback function for keypad
void (*KeypadInterrupt__callback)(KeypadInterrupt*);
KeypadInterrupt* KeypadInterrupt__self;
// callback function for button
void (*ButtonInterrupt__callback)(ButtonInterrupt*);
ButtonInterrupt* ButtonInterrupt__self;
#endif

void SysTick_Handler() {

#ifdef lab_systick_blink
	if(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk){
		// Toggle LED display
		toggle_output(LED_gpio, LED_pin);
	}
#endif

#ifdef lab_systick_blink_change_freq
	if(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk){
		// Toggle LED display
		toggle_output(LED_gpio, LED_pin);
	}
#endif

#ifdef lab_interrupt_keypad
	if(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)
		KeyboardInterrupt__shiftOutput(KeypadInterrupt__self);
#endif

#ifdef lab_alarm
	if(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk){
		// Update remaining time
		remainingTime--;
		if(remainingTime <= 0){
			remainingTime = 0;
		}
	}
	musicCounterMs += 1000.0 / 4000000.0;
	if(musicCounterMs >= 60000){
		musicCounterMs = 0;
	}
#endif
}

#if defined(lab_interrupt_keypad) || defined(lab_alarm)
void EXIT3_IRQHandler()
{
	// Check if interrupt is from EXTI3
	if(EXTI->PR1 & EXTI_PR1_PIF3){
		// Clear interrupt
		EXTI->PR1 |= EXTI_PR1_PIF3;

		// Call callback
		KeypadInterrupt__callback(KeypadInterrupt__self);
	}
}

void EXIT4_IRQHandler()
{
	// Check if interrupt is from EXTI4
	if(EXTI->PR1 & EXTI_PR1_PIF4){
		// Clear interrupt
		EXTI->PR1 |= EXTI_PR1_PIF4;

		// Call callback
		KeypadInterrupt__callback(KeypadInterrupt__self);
	}
}

void EXIT9_5_IRQHandler()
{
	// Check if interrupt is from EXTI5
	if(EXTI->PR1 & EXTI_PR1_PIF5){
		// Clear interrupt
		EXTI->PR1 |= EXTI_PR1_PIF5;

		// Call callback
		KeypadInterrupt__callback(KeypadInterrupt__self);
	}
	// Check if interrupt is from EXTI6
	if(EXTI->PR1 & EXTI_PR1_PIF6){
		// Clear interrupt
		EXTI->PR1 |= EXTI_PR1_PIF6;

		// Call callback
		KeypadInterrupt__callback(KeypadInterrupt__self);
	}
}
#endif

#ifdef lab_alarm
void EXIT0_IRQHandler()
{
	// Check if interrupt is from EXTI0
	if(EXTI->PR1 & EXTI_PR1_PIF0){
		// Clear interrupt
		EXTI->PR1 |= EXTI_PR1_PIF0;

		// Call callback
		ButtonInterrupt__callback(ButtonInterrupt__self);
	}
}
#endif

int main(){
	// Cause we want to use floating points we need to init FPU
	FPU_init();

#ifdef lab_systick_blink

	if(init_led(LED_gpio, LED_pin) != 0){
		// Fail to init led
		return -1;
	}
	if(init_button(BUTTON_gpio, BUTTON_pin) != 0){
		// Fail to init button
		return -1;
	}

	// Configure SysTick clk to 10 Mhz and interrupt every 0.5s
	SystemClock_Config_Interrupt(10, 5000000);

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
					SysTick->CTRL ^= (1 << SysTick_CTRL_ENABLE_Pos);
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
					// Do nothing
				}
				last_button_state = 0;
			}
		}
	}

#endif

#ifdef lab_systick_blink_change_freq

	Led led;
	Led__construct(&led, LED_gpio, LED_pin);
	Led__init(&led);

	Button button;
	Button__construct(&button, BUTTON_gpio, BUTTON_pin);
	Button__init(&button);

	SystemClock systemClock;
	SystemClock__construct(&systemClock, 10000000, 5000000);
	SystemClock__init(&systemClock);

	SevenSeg sevenSeg;
	SevenSeg__construct(&sevenSeg, SEG_gpio, DIN_pin, CS_pin, CLK_pin);
	SevenSeg__init(&sevenSeg);
	SevenSeg__printNum(&sevenSeg, 2);

	const double interrupt_freq[3] = {2, 10, 3.3333333333333333};
	int freq_index = 0;

	while(1)
	{
		if(Button__is_pressed(&button))
		{
			freq_index = (freq_index + 1) % 3;
			SystemClock__setInterruptFrequency(&systemClock, interrupt_freq[freq_index]);
			struct fraction currentFreq = {interrupt_freq[freq_index] * 100, 100};
			SevenSeg__printFraction(&sevenSeg, currentFreq);
		}
	}

#endif

#ifdef lab_interrupt_keypad
	SystemClock SystemClock;
	SystemClock__construct(&SystemClock, 10000000, 10000); // interrupt every 0.001s
	SystemClock__init(&SystemClock);

	SevenSeg SevenSeg;
	SevenSeg__construct(&SevenSeg, SEG_gpio, DIN_pin, CS_pin, CLK_pin);
	SevenSeg__init(&SevenSeg);

	KeypadInterrupt keypad;
	KeypadInterrupt__construct(&keypad, ROW_gpio, COL_gpio, ROW_pin, COL_pin, 3);
	KeypadInterrupt__init(&keypad);
	// for interrupt callback
	KeypadInterrupt__self = &keypad;
	KeypadInterrupt__callback = &KeypadInterrupt__callbackRefresh;

	while(1)
	{
		char c = KeypadInterrupt__getChar(&keypad);
		SevenSeg__printNum(&SevenSeg, c == '0' ? 0 :
		                              c == '1' ? 1 :
									  c == '2' ? 2 :
									  c == '3' ? 3 :
									  c == '4' ? 4 :
									  c == '5' ? 5 :
									  c == '6' ? 6 :
									  c == '7' ? 7 :
									  c == '8' ? 8 :
									  c == '9' ? 9 : 
									  c == 'A' ? 10 :
									  c == 'B' ? 11 :
									  c == 'C' ? 12 :
									  c == 'D' ? 13 :
									  c == '#' ? 14 :
									  c == '*' ? 15 : -1
		);
	}

#endif
#ifdef lab_alarm
	SystemClock SystemClock;
	SystemClock__construct(&SystemClock, 4000000, 4000000); // interrupt every 1s
	SystemClock__init(&SystemClock);

	Speaker speaker;
	Speaker__construct(&speaker, SPEAKER_gpio, SPEAKER_pin, TIM2, 0.5);
	Speaker__init(&speaker);
	ToneFrequency toneFrequency;
	ToneFrequency__construct(&toneFrequency);

	SevenSeg sevenSeg;
	SevenSeg__construct(&sevenSeg, SEG_gpio, DIN_pin, CS_pin, CLK_pin);
	SevenSeg__init(&sevenSeg);

	KeypadInterrupt keypad;
	KeypadInterrupt__construct(&keypad, ROW_gpio, COL_gpio, ROW_pin, COL_pin, 3);
	KeypadInterrupt__init(&keypad);
	// for interrupt callback
	KeypadInterrupt__self = &keypad;
	KeypadInterrupt__callback = &KeypadInterrupt__callbackRefresh;

	ButtonInterrupt button;
	ButtonInterrupt__construct(&button, BUTTON_gpio, BUTTON_pin, 0);
	ButtonInterrupt__init(&button);
	// for interrupt callback
	ButtonInterrupt__self = &button;
	ButtonInterrupt__callback = &ButtonInterrupt__callbackRefresh;

	while(1)
	{
		// enter number of seconds
		int seconds = 0;
		while(1)
		{
			if(ButtonInterrupt__is_pressed(&button))
				break;
			char c = KeypadInterrupt__getCharPressed(&keypad);
			if(c >= '0' && c <= '9')
				seconds = seconds * 10 + c - '0';
			if(seconds > 99999999)
				seconds = 99999999;
			SevenSeg__printNum(&sevenSeg, seconds);
		}

		// start alarm
		remainingTime = seconds;
		SystemClock__reset(&SystemClock);
		while(remainingTime > 0)
			SevenSeg__printNum(&sevenSeg, remainingTime);

		// ring alarm
		musicCounterMs = 0;
		while(1)
		{
			if(ButtonInterrupt__is_pressed(&button))
				break;
			else
				Speaker__playIphoneRingtone(&speaker, musicCounterMs);
		}
	}
#endif

	while(1){}

	return 0;
}
