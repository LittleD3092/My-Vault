#include "speaker.h"

void ToneFrequency__construct(ToneFrequency* self)
{
    self->C4 = 261.6;
    self->D4 = 293.7;
    self->E4 = 329.6;
    self->F4 = 349.2;
    self->G4 = 392.0;
    self->A4 = 440.0;
    self->B4 = 493.9;
    self->C5 = 523.3;
}

void Speaker__construct(Speaker *self, GPIO_TypeDef *gpio, int pin, TIM_TypeDef *timer, double dutyCycle)
{
    self->gpio = gpio;
    self->pin = pin;
    self->timer = timer;
    self->dutyCycle = dutyCycle;
}

int Speaker__init(Speaker *self)
{
    // config system clock
    SystemClock_Config(40);

    // // init gpio
    // if(self->gpio == GPIOA)
    // {
    //     RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
        
    //     if(self->pin == 0)
    //     {
    //         // Set to Alternate function mode
    //         GPIOA->MODER &= ~GPIO_MODER_MODE0_Msk;
    //         GPIOA->MODER |= (2 << GPIO_MODER_MODE0_Pos);
    //         // Set AFRL
    //         GPIOA->AFR[0] &= ~GPIO_AFRL_AFSEL0_Msk;
    //         GPIOA->AFR[0] |= (1 << GPIO_AFRL_AFSEL0_Pos);
    //         return 0;
    //     }
    //     else
    //     {
    //         // undefined pin
    //         return -1;
    //     }
    // }
    // else
    // {
    //     // undefined gpio
    //     return -1;
    // }

    // // timer init
    // timer_enable(self->timer);
    // timer_init(self->timer, 1, 20);

    // // pwm init
    // self->timer->CCMR1 &= ~TIM_CCMR1_OC1M_Msk;
    // self->timer->CCMR1 |= (6 << TIM_CCMR1_OC1M_Pos);
    // self->timer->CCMR1 &= ~TIM_CCMR1_OC1PE_Msk;
    // self->timer->CCMR1 |= (1 << TIM_CCMR1_OC1PE_Pos);
    // self->timer->CCER &= ~TIM_CCER_CC1P_Msk;
    // self->timer->CCER |= (0 << TIM_CCER_CC1P_Pos);
    // self->timer->CCER &= ~TIM_CCER_CC1E_Msk;
    // self->timer->CCER |= (1 << TIM_CCER_CC1E_Pos);
    // self->timer->CCR1 = 10;
    // self->timer->PSC = 0;

    // // timer start
    // timer_start(self->timer);

    GPIO_init_AF();
    timer_enable(self->timer);
    timer_init(self->timer, 1, 20);
    PWM_channel_init();
    timer_start(self->timer);

    return 0;
}

void Speaker__play(Speaker *self, double freq)
{
    self->timer->ARR = (int)(40000000.0 / freq);
    self->timer->CCR1 = (int)(self->dutyCycle * 40000000.0 / freq);
}

void Speaker__stop(Speaker *self)
{
    self->timer->CCR1 = 0;
}

void Speaker__adjustDutyCycle(Speaker *self, double offset)
{
    self->dutyCycle += offset;
    self->dutyCycle += 0.0000001;
    if(self->dutyCycle > 0.9)
    {
        self->dutyCycle = 0.9;
    }
    else if(self->dutyCycle < 0.1)
    {
        self->dutyCycle = 0.1;
    }
}

double Speaker__getDutyCycle(Speaker *self)
{
    return self->dutyCycle;
}