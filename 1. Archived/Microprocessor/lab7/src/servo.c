#include "servo.h"

#define CCR1_UPPER_BOUND 7900
#define CCR1_LOWER_BOUND 1000

void Servo__construct(Servo *self, GPIO_TypeDef *gpio, int pin, TIM_TypeDef *timer)
{
    self->gpio = gpio;
    self->pin = pin;
    self->timer = timer;
}

int Servo__init(Servo *self)
{
    // config system clock
    SystemClock_Config(4);

    // config gpio
    // if(self->gpio == GPIOA)
    // {
    //     RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    //     // Set to Alternate function mode
    //     GPIOA->MODER &= ~(GPIO_MODER_MODE0_Msk << (self->pin * 2));
    //     GPIOA->MODER |= (2 << (self->pin * 2));
    //     // Set AFRL
    //     GPIOA->AFR[0] &= ~(GPIO_AFRL_AFSEL0_Msk << (self->pin * 4));
    //     GPIOA->AFR[0] |= (1 << (self->pin * 4));
    // }
    // else if(self->gpio == GPIOC)
    // {
    //     RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
    //     // Set to Alternate function mode
    //     GPIOC->MODER &= ~(GPIO_MODER_MODE0_Msk << (self->pin * 2));
    //     GPIOC->MODER |= (2 << (self->pin * 2));
    //     // Set AFRL
    //     GPIOC->AFR[0] &= ~(GPIO_AFRL_AFSEL0_Msk << (self->pin * 4));
    //     GPIOC->AFR[0] |= (1 << (self->pin * 4));
    // }
    GPIO_init_AF();
    timer_enable(self->timer);
    timer_init(self->timer, 1, 180);
    PWM_channel_init();
    timer_start(self->timer);

    return 0;
}

void Servo__write(Servo* self, int angle)
{
    if(angle < 0 || angle > 180)    return;
    self->timer->CCR1 = (int)(angle * (CCR1_UPPER_BOUND - CCR1_LOWER_BOUND) / 180 + CCR1_LOWER_BOUND);
    self->timer->ARR = 8000;
}