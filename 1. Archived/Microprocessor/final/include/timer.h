#ifndef __timer__H__
#define __timer__H__

#include "stm32l476xx.h"

void SystemClock_Config(int speed);
void SystemClock_Config_Interrupt(int speed, int load);

void timer_enable(TIM_TypeDef *timer);
void timer_disable(TIM_TypeDef *timer);
void timer_init(TIM_TypeDef *timer, int psc, int arr);
void timer_reload(TIM_TypeDef *timer);
void timer_start(TIM_TypeDef *timer);
void timer_stop(TIM_TypeDef *timer);

void GPIO_init_AF();
void PWM_channel_init();

typedef struct SystemClock {
    int speed; // in Hz
    int counterMax;
}SystemClock;

void SystemClock__construct(SystemClock* self, int speed, int counterMax);
void SystemClock__init(SystemClock* self);
void SystemClock__setSpeed(SystemClock* self, int speed);
void SystemClock__setCounterMax(SystemClock* self, int counterMax);
void SystemClock__setInterruptFrequency(SystemClock* self, double frequency);
int SystemClock__getSpeed(SystemClock* self);
int SystemClock__getCounterMax(SystemClock* self);
double SystemClock__getInterruptFrequency(SystemClock* self);
void SystemClock__reset(SystemClock* self);

#endif