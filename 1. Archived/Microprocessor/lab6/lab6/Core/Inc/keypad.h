#ifndef __keypad__H__
#define __keypad__H__

#include "stm32l476xx.h"

extern const int keypad[4][4];

int init_keypad(GPIO_TypeDef* ROW_gpio, GPIO_TypeDef* COL_gpio, int ROW_pin, int COL_pin);

int check_keypad_input_one(GPIO_TypeDef* ROW_gpio, GPIO_TypeDef* COL_gpio, int ROW_pin, int COL_pin, int x, int y);
int check_keypad_input_multiple(GPIO_TypeDef* ROW_gpio, GPIO_TypeDef* COL_gpio, int ROW_pin, int COL_pin);

typedef struct Keypad {
    GPIO_TypeDef* ROW_gpio;
    GPIO_TypeDef* COL_gpio;
    int ROW_pin;
    int COL_pin;

    int buttons[4][4];
    int last_buttons[4][4];
} Keypad;

void Keypad__construct(Keypad* self, GPIO_TypeDef* ROW_gpio, GPIO_TypeDef* COL_gpio, int ROW_pin, int COL_pin);
int Keypad__init(Keypad* self);
void Keypad__refresh(Keypad* self);
char Keypad__getChar(Keypad* self);
char Keypad__getCharPressed(Keypad* self);
char Keypad__getCharReleased(Keypad* self);

typedef struct KeypadInterrupt
{
    Keypad base;
    int EXTI_IRQn;
    int currentOutputCol;
} KeypadInterrupt;

// Note that EXTI_IRQn is the index of interrupt used.
// EXTI_IRQn + 1, EXTI_IRQn + 2, EXTI_IRQn + 3 are also used.
void KeypadInterrupt__construct(KeypadInterrupt* self, GPIO_TypeDef* ROW_gpio, GPIO_TypeDef* COL_gpio, int ROW_pin, int COL_pin, int EXTI_IRQn);
int KeypadInterrupt__init(KeypadInterrupt* self);
void KeypadInterrupt__shiftOutput(KeypadInterrupt* self);
void KeypadInterrupt__callbackRefresh(KeypadInterrupt* self);
char KeypadInterrupt__getChar(KeypadInterrupt* self);
char KeypadInterrupt__getCharPressed(KeypadInterrupt* self);
char KeypadInterrupt__getCharReleased(KeypadInterrupt* self);

#endif
