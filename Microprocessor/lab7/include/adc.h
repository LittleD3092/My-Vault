#ifndef __adc__H__
#define __adc__H__

#include "stm32l476xx.h"

void ADCResolution(ADC_TypeDef *adc, int resolution);
void ADCContinuousConversion(ADC_TypeDef *adc, int enable);
void ADCDataAlign(ADC_TypeDef *adc, int dir);
void ADCChannel(ADC_TypeDef *adc, int channel, int rank, int sampleTime);
void ADCWakeup(ADC_TypeDef *adc);
void ADCEnable(ADC_TypeDef *adc);
int ADCGetValue(ADC_TypeDef *adc);
void ADCStartConversion(ADC_TypeDef *adc);
void ADCInterrupt(ADC_TypeDef *adc, int it, int enable);
void ADCCommonDualMode(int mode);
void ADCCommonClockMode(int clkMode);
void ADCCommonPrescaler(int psc);
void ADCCommonDMAMode(int mode);
void ADCCommonDelayTwoSampling(int clk);

typedef struct
{
    ADC_TypeDef *adc;
    GPIO_TypeDef *gpio;
    int pin;
    int use_interrupt;
    int channel;
    int rank;
} ADC;

enum Direction
{
    RIGHT = 0,
    LEFT = 1
};

void ADC__construct(ADC *adc, ADC_TypeDef *adc_, GPIO_TypeDef *gpio, int pin, int use_interrupt, int channel, int rank);
int ADC__init(ADC *adc);
int ADC__read(ADC *adc);
void ADC__setTotalConversion(ADC *adc, int total);

#endif