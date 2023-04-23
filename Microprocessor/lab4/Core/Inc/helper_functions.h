#ifndef __helper_function__H__
#define __helper_function__H__

#include "stm32l476xx.h"

#define abs(x) (((x) < 0) ? (-(x)) : (x))

int read_gpio(GPIO_TypeDef* gpio, int pin);
void set_gpio(GPIO_TypeDef* gpio, int pin);
void reset_gpio(GPIO_TypeDef* gpio, int pin);
void toggle_output(GPIO_TypeDef* gpio, int pin);

void delay_without_interrupt(int msec);

int num_digits(int x);

int gcd(int a, int b);
int lcm(int a, int b);

#endif
