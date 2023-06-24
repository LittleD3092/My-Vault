#ifndef __helper_function__H__
#define __helper_function__H__

#include "stm32l476xx.h"

int read_gpio(GPIO_TypeDef* gpio, int pin);
void set_gpio(GPIO_TypeDef* gpio, int pin);
void reset_gpio(GPIO_TypeDef* gpio, int pin);
void toggle_output(GPIO_TypeDef* gpio, int pin);

void delay_without_interrupt(int msec);

#endif
