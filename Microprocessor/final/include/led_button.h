#ifndef __led_button__H__
#define __led_button__H__

#include "stm32l476xx.h"

int init_led(GPIO_TypeDef* gpio, int LED_pin);
int init_button(GPIO_TypeDef* gpio, int button_pin);

int user_press_button(int debounce);

typedef struct Led
{
    GPIO_TypeDef* gpio;
    int pin;
} Led;

typedef struct Button
{
    GPIO_TypeDef* gpio;
    int pin;
    
    int state;
    int last_state;

    int debounce_cycles;
    int debounce_threshold;
} Button;

void Led__construct(Led* led, GPIO_TypeDef* gpio, int pin);
int Led__init(Led* led);
void Led__write(Led* led, int state);
void Led__toggle(Led* led);

void Button__construct(Button* button, GPIO_TypeDef* gpio, int pin);
int Button__init(Button* button);
int Button__read(Button* button);
int Button__is_pressed(Button* button);
int Button__is_released(Button* button);

typedef struct ButtonInterrupt
{
    Button base;
    int EXTI_IRQn;
} ButtonInterrupt;
void ButtonInterrupt__construct(ButtonInterrupt* button, GPIO_TypeDef* gpio, int pin, int EXTI_IRQn);
int ButtonInterrupt__init(ButtonInterrupt* button);
int ButtonInterrupt__is_pressed(ButtonInterrupt* button);
int ButtonInterrupt__is_released(ButtonInterrupt* button);
void ButtonInterrupt__callbackRefresh(ButtonInterrupt* button);

#endif
