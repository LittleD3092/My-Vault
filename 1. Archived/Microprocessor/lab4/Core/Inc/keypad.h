#ifndef __keypad__H__
#define __keypad__H__

#include "stm32l476xx.h"

extern const int keypad[4][4];

int init_keypad(GPIO_TypeDef* ROW_gpio, GPIO_TypeDef* COL_gpio, int ROW_pin, int COL_pin);

int check_keypad_input_one(GPIO_TypeDef* ROW_gpio, GPIO_TypeDef* COL_gpio, int ROW_pin, int COL_pin, int x, int y);
int check_keypad_input_multiple(GPIO_TypeDef* ROW_gpio, GPIO_TypeDef* COL_gpio, int ROW_pin, int COL_pin);

#endif
