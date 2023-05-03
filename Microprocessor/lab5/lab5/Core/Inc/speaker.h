#include "stm32l476xx.h"
#include "timer.h"

#ifndef __SPEAKER_H__
#define __SPEAKER_H__

typedef struct ToneFrequency
{
    double C4;
    double D4;
    double E4;
    double F4;
    double G4;
    double A4;
    double B4;
    double C5;
}ToneFrequency;

void ToneFrequency__construct(ToneFrequency* self);

typedef struct Speaker
{
    GPIO_TypeDef *gpio;
    int pin;
    TIM_TypeDef *timer;
}Speaker;

void Speaker__construct(Speaker *self, GPIO_TypeDef *gpio, int pin, TIM_TypeDef *timer);
int Speaker__init(Speaker *self);
void Speaker__play(Speaker *self, double freq);
void Speaker__stop(Speaker *self);

#endif