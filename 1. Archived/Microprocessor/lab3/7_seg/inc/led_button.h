#ifndef __led_button__H__
#define __led_button__H__

#include "stm32l476xx.h"

int init_led(GPIO_TypeDef* gpio, int LED_pin);
int init_button(GPIO_TypeDef* gpio, int button_pin);

#endif
