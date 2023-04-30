#ifndef __timer__H__
#define __timer__H__

#include "stm32l476xx.h"

void SystemClock_Config(int speed);

void timer_enable(TIM_TypeDef *timer);
void timer_disable(TIM_TypeDef *timer);
void timer_init(TIM_TypeDef *timer, int psc, int arr);
void timer_reload(TIM_TypeDef *timer);
void timer_start(TIM_TypeDef *timer);
void timer_stop(TIM_TypeDef *timer);

void GPIO_init_AF();
void PWM_channel_init();

// ---

// Custom object Timer
struct Timer
{
    TIM_TypeDef *timer;
    int msecs;
};
typedef struct Timer Timer;

void Timer__init(Timer *timer, TIM_TypeDef *timer_type);
int Timer__get_msecs(Timer *timer);
void Timer__refresh(Timer *timer);

#endif
