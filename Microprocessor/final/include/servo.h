#include "stm32l476xx.h"
#include "timer.h"

#ifndef __SERVO_H__
#define __SERVO_H__

typedef struct
{
    GPIO_TypeDef *gpio;
    int pin;
    TIM_TypeDef *timer;
}Servo;

void Servo__construct(Servo *self, GPIO_TypeDef *gpio, int pin, TIM_TypeDef *timer);
int Servo__init(Servo *self);
void Servo__write(Servo *self, int angle);

#endif