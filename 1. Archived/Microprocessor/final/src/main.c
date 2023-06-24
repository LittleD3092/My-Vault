#include "stm32l476xx.h"
#include "helper_functions.h"
#include "7seg.h"
#include "keypad.h"
#include "led_button.h"
#include "timer.h"
#include "speaker.h"

// #define QUESTION6
// #define QUESTION7
#define QUESTION8

#ifdef QUESTION6
// define seven segment gpio
#define SEVENSEG_GPIO GPIOC
#define SEVENSEG_DIN 3
#define SEVENSEG_CS 4
#define SEVENSEG_CLK 5

// Define pins for led (default use on-board led PA5)
#define LED_gpio GPIOA
#define LED_pin 5

// Define pins for button (default use on-board button PC13)
#define BUTTON_gpio GPIOC
#define BUTTON_pin 13

// custom object for button and built-in led
Led built_in_led;
ButtonInterrupt button;

int state = 0; // 0: display HAHA 1: flash LED
int seconds = 0;

// check button interrupt
void EXTI3_IRQHandler()
{
	// Check if interrupt is from EXTI3
	if(EXTI->PR1 & EXTI_PR1_PIF3){
		// Clear interrupt
		EXTI->PR1 = 0;

		// Display "HAHA"
        send_7seg(SEVENSEG_GPIO, SEVENSEG_DIN, SEVENSEG_CS, SEVENSEG_CLK, SEG_ADDRESS_DIGIT_3, SEG_DATA_NON_DECODE_H);
        send_7seg(SEVENSEG_GPIO, SEVENSEG_DIN, SEVENSEG_CS, SEVENSEG_CLK, SEG_ADDRESS_DIGIT_2, SEG_DATA_NON_DECODE_A);
        send_7seg(SEVENSEG_GPIO, SEVENSEG_DIN, SEVENSEG_CS, SEVENSEG_CLK, SEG_ADDRESS_DIGIT_1, SEG_DATA_NON_DECODE_H);
        send_7seg(SEVENSEG_GPIO, SEVENSEG_DIN, SEVENSEG_CS, SEVENSEG_CLK, SEG_ADDRESS_DIGIT_0, SEG_DATA_NON_DECODE_A);
        state = 0;
        seconds = 0;
	}
}

// check systick interrupt
void SysTick_Handler()
{
    if(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)
    {
        if(state == 0)
            seconds++;
        else if(state == 1)
            Led__toggle(&built_in_led);

        if(seconds == 3)
        {
            state = 1;
            seconds = 0;
            send_7seg(SEVENSEG_GPIO, SEVENSEG_DIN, SEVENSEG_CS, SEVENSEG_CLK, SEG_ADDRESS_DIGIT_3, SEG_DATA_NON_DECODE_BLANK);
            send_7seg(SEVENSEG_GPIO, SEVENSEG_DIN, SEVENSEG_CS, SEVENSEG_CLK, SEG_ADDRESS_DIGIT_2, SEG_DATA_NON_DECODE_BLANK);
            send_7seg(SEVENSEG_GPIO, SEVENSEG_DIN, SEVENSEG_CS, SEVENSEG_CLK, SEG_ADDRESS_DIGIT_1, SEG_DATA_NON_DECODE_BLANK);
            send_7seg(SEVENSEG_GPIO, SEVENSEG_DIN, SEVENSEG_CS, SEVENSEG_CLK, SEG_ADDRESS_DIGIT_0, SEG_DATA_NON_DECODE_0);
        }
    }
}

int main()
{
    // initialize seven segment
    if(init_7seg(SEVENSEG_GPIO, SEVENSEG_DIN, SEVENSEG_CS, SEVENSEG_CLK) != 0){
		// Fail to init 7seg
		return -1;
	}

	// Set Decode Mode to non-decode mode
	send_7seg(SEVENSEG_GPIO, SEVENSEG_DIN, SEVENSEG_CS, SEVENSEG_CLK, SEG_ADDRESS_DECODE_MODE, 0x00);
	// Set Scan Limit to four digits
	send_7seg(SEVENSEG_GPIO, SEVENSEG_DIN, SEVENSEG_CS, SEVENSEG_CLK, SEG_ADDRESS_SCAN_LIMIT, 0x03);
	// Wakeup 7seg
	send_7seg(SEVENSEG_GPIO, SEVENSEG_DIN, SEVENSEG_CS, SEVENSEG_CLK, SEG_ADDRESS_SHUTDOWN, 0x01);

    // initialize system clock, led, and button
    SystemClock sys_clock;
    SystemClock__construct(&sys_clock, 4000000, 4000000);
    SystemClock__init(&sys_clock);

    Led__construct(&built_in_led, LED_gpio, LED_pin);
    Led__init(&built_in_led);

    ButtonInterrupt__construct(&button, BUTTON_gpio, BUTTON_pin, 3);
    ButtonInterrupt__init(&button);

    while(1)
    {
    }
}
#endif

#ifdef QUESTION7
#define SEVENSEG_GPIO GPIOC
#define SEVENSEG_DIN 3
#define SEVENSEG_CS 4
#define SEVENSEG_CLK 5

// Define pins for keypad
// If need to change need to also change EXTI_Setup and IRQHandler
#define COL_gpio GPIOA
#define COL_pin 6       // 6 7 8 9
#define ROW_gpio GPIOB
#define ROW_pin 3       // 3 4 5 6

// The code for each number. For display purpose.
const int seven_seg_encoding[16] = {
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
    SEG_DATA_NON_DECODE_A,
    SEG_DATA_NON_DECODE_B,
    SEG_DATA_NON_DECODE_C,
    SEG_DATA_NON_DECODE_D,
    SEG_DATA_NON_DECODE_E,
    SEG_DATA_NON_DECODE_F
};

Keypad keypad1;

int main()
{
    if(init_7seg(SEVENSEG_GPIO, SEVENSEG_DIN, SEVENSEG_CS, SEVENSEG_CLK) != 0){
		// Fail to init 7seg
		return -1;
	}

	// Set Decode Mode to non-decode mode
	send_7seg(SEVENSEG_GPIO, SEVENSEG_DIN, SEVENSEG_CS, SEVENSEG_CLK, SEG_ADDRESS_DECODE_MODE, 0x00);
	// Set Scan Limit to four digits
	send_7seg(SEVENSEG_GPIO, SEVENSEG_DIN, SEVENSEG_CS, SEVENSEG_CLK, SEG_ADDRESS_SCAN_LIMIT, 0x03);
	// Wakeup 7seg
	send_7seg(SEVENSEG_GPIO, SEVENSEG_DIN, SEVENSEG_CS, SEVENSEG_CLK, SEG_ADDRESS_SHUTDOWN, 0x01);

    // initialize keypad
    Keypad__construct(&keypad1, ROW_gpio, COL_gpio, ROW_pin, COL_pin);
    Keypad__init(&keypad1);

    // print "   0" on 7seg
    send_7seg(SEVENSEG_GPIO, SEVENSEG_DIN, SEVENSEG_CS, SEVENSEG_CLK, SEG_ADDRESS_DIGIT_3, SEG_DATA_NON_DECODE_BLANK);
    send_7seg(SEVENSEG_GPIO, SEVENSEG_DIN, SEVENSEG_CS, SEVENSEG_CLK, SEG_ADDRESS_DIGIT_2, SEG_DATA_NON_DECODE_BLANK);
    send_7seg(SEVENSEG_GPIO, SEVENSEG_DIN, SEVENSEG_CS, SEVENSEG_CLK, SEG_ADDRESS_DIGIT_1, SEG_DATA_NON_DECODE_BLANK);
    send_7seg(SEVENSEG_GPIO, SEVENSEG_DIN, SEVENSEG_CS, SEVENSEG_CLK, SEG_ADDRESS_DIGIT_0, seven_seg_encoding[0]);
    while(1)
    {
        // state 1: input first operand
        int operand1[2] = {0, 0};
        char operator = ' ';
        int reset = 0;
        while(1)
        {
            Keypad__refresh(&keypad1);
            char key = Keypad__getCharPressed(&keypad1);
            if(key >= '0' && key <= '9' && operand1[0] == 0)
            {
                operand1[0] = operand1[1];
                operand1[1] = key - '0';
                send_7seg(SEVENSEG_GPIO, SEVENSEG_DIN, SEVENSEG_CS, SEVENSEG_CLK, SEG_ADDRESS_DIGIT_1, seven_seg_encoding[operand1[1]]);
                send_7seg(SEVENSEG_GPIO, SEVENSEG_DIN, SEVENSEG_CS, SEVENSEG_CLK, SEG_ADDRESS_DIGIT_0, seven_seg_encoding[operand1[0]]);
            }
            else if(key == 'A')
                operator = '+';
            else if(key == 'B')
                operator = '-';
            else if(key == 'C')
                operator = '*';
            else if(key == 'D')
                operator = '/';
            else if(key == '*')
                reset = 1;

            if(reset == 1 || operator != ' ')    break;
        }
        // continue while loop on reset
        if(reset == 1)    continue;

        // print operator on 7seg
        send_7seg(SEVENSEG_GPIO, SEVENSEG_DIN, SEVENSEG_CS, SEVENSEG_CLK, SEG_ADDRESS_DIGIT_1, SEG_DATA_DECODE_BLANK);
        send_7seg(SEVENSEG_GPIO, SEVENSEG_DIN, SEVENSEG_CS, SEVENSEG_CLK, SEG_ADDRESS_DIGIT_0, seven_seg_encoding[0]);

        // state 2: input second operand
        int operand2[2] = {0, 0};
        int result = 0;
        while(1)
        {
            Keypad__refresh(&keypad1);
            char key = Keypad__getCharPressed(&keypad1);
            if(key >= '0' && key <= '9' && operand2[0] == 0)
            {
                operand2[0] = operand2[1];
                operand2[1] = key - '0';
            }
            else if(key == '#')
            {
                if(operator == '+')
                    result = operand1[0] + operand1[1] * 16 + operand2[0] + operand2[1] * 16;
                else if(operator == '-')
                    result = operand1[0] + operand1[1] * 16 - operand2[0] - operand2[1] * 16;
                else if(operator == '*')
                    result = (operand1[0] + operand1[1] * 16) * (operand2[0] + operand2[1] * 16);
                else if(operator == '/')
                    result = (operand1[0] + operand1[1] * 16) / (operand2[0] + operand2[1] * 16);
                break;
            }
        }

        // state 3: output
        int result_digit[4] = {result, 0, 0, 0};
        
        for(int i = 1; i <= 3; i++)
        {
            result_digit[i] = result_digit[i - 1] / 16;
            result_digit[i - 1] %= 16;
        }

        send_7seg(SEVENSEG_GPIO, SEVENSEG_DIN, SEVENSEG_CS, SEVENSEG_CLK, SEG_ADDRESS_DIGIT_3, seven_seg_encoding[result_digit[3]]);
        send_7seg(SEVENSEG_GPIO, SEVENSEG_DIN, SEVENSEG_CS, SEVENSEG_CLK, SEG_ADDRESS_DIGIT_2, seven_seg_encoding[result_digit[2]]);
        send_7seg(SEVENSEG_GPIO, SEVENSEG_DIN, SEVENSEG_CS, SEVENSEG_CLK, SEG_ADDRESS_DIGIT_1, seven_seg_encoding[result_digit[1]]);
        send_7seg(SEVENSEG_GPIO, SEVENSEG_DIN, SEVENSEG_CS, SEVENSEG_CLK, SEG_ADDRESS_DIGIT_0, seven_seg_encoding[result_digit[0]]);
    }
}
#endif

#ifdef QUESTION8
#define LED_GPIO GPIOA
#define LED_PIN 0
#define LED_COUNT 4

#define SEVENSEG_GPIO GPIOC
#define SEVENSEG_DIN 3
#define SEVENSEG_CS 4
#define SEVENSEG_CLK 5

SevenSeg sevenseg;

// Define pins for keypad
// If need to change need to also change EXTI_Setup and IRQHandler
#define COL_gpio GPIOA
#define COL_pin 6       // 6 7 8 9
#define ROW_gpio GPIOB
#define ROW_pin 3       // 3 4 5 6

// Declare led array, score and lighting index
Led ledarray[4];
int score = 0;
int lighting_index = 0; // which led is now lighting

// custom rand function
int rand()
{
    static int seed = 0;
    seed = (seed * 1103515245 + 12345) % 2147483647;
    return seed;
}

// clear all leds, then light up one random led
void SysTick_Handler()
{
    if(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)
    {
        for(int i = 0; i < LED_COUNT; i++)
            Led__write(&ledarray[i], 0);
        lighting_index = rand() % LED_COUNT;
        Led__write(&ledarray[lighting_index % LED_COUNT], 1);
    }
}

// add score if correct button is pressed
// update lights
void EXTI3_IRQHandler()
{
	// Check if interrupt is from EXTI3
	if(EXTI->PR1 & EXTI_PR1_PIF3){
		// Clear interrupt
		EXTI->PR1 = EXTI_PR1_PIF3;

		// Call callback
		if(lighting_index == 0)
            score+=5;

        lighting_index = rand() % LED_COUNT;
        Led__write(&ledarray[lighting_index % LED_COUNT], 1);

        SevenSeg__printNum(&sevenseg, score);
	}
}

// add score if correct button is pressed
// update lights
void EXTI4_IRQHandler()
{
	// Check if interrupt is from EXTI4
	if(EXTI->PR1 & EXTI_PR1_PIF4){
		// Clear interrupt
		EXTI->PR1 = EXTI_PR1_PIF4;

		// Call callback
		if(lighting_index == 1)
            score+=5;

        lighting_index = rand() % LED_COUNT;
        Led__write(&ledarray[lighting_index % LED_COUNT], 1);

        SevenSeg__printNum(&sevenseg, score);
	}
}

// add score if correct button is pressed
// update lights
void EXTI9_5_IRQHandler()
{
	// Check if interrupt is from EXTI5
	if(EXTI->PR1 & EXTI_PR1_PIF5){
		// Clear interrupt
		EXTI->PR1 = EXTI_PR1_PIF5;

		// Call callback
		if(lighting_index == 2)
            score+=5;

        lighting_index = rand() % LED_COUNT;
        Led__write(&ledarray[lighting_index % LED_COUNT], 1);

        SevenSeg__printNum(&sevenseg, score);
	}
	// Check if interrupt is from EXTI6
	if(EXTI->PR1 & EXTI_PR1_PIF6){
		// Clear interrupt
		EXTI->PR1 = EXTI_PR1_PIF6;

		// Call callback
		if(lighting_index == 3)
            score+=5;

        lighting_index = rand() % LED_COUNT;
        Led__write(&ledarray[lighting_index % LED_COUNT], 1);

        SevenSeg__printNum(&sevenseg, score);
	}
}

int main()
{
    // Setup system clock, interrupt on each second.
    SystemClock clock;
    SystemClock__construct(&clock, 4000000, 4000000);

    // Setup keypad and interrupt parameters
    KeypadInterrupt keypad1;
    KeypadInterrupt__construct(&keypad1, ROW_gpio, COL_gpio, ROW_pin, COL_pin, 3);
    KeypadInterrupt__init(&keypad1);

    // Setup each led
    for(int i = 0; i < LED_COUNT; i++)
    {
        Led__construct(&ledarray[i], LED_GPIO, LED_PIN + i);
        Led__init(&ledarray[i]);
    }

    while(1)
    {}
}
#endif