#include "adc.h"
#include "helper_functions.h"

void ADCResolution(ADC_TypeDef *adc, int resolution){
	// 0 -> 12
	// 1 -> 10
	// 2 -> 8
	// 3 -> 6
	adc->CFGR &= ~ADC_CFGR_RES;
	adc->CFGR |= resolution << ADC_CFGR_RES_Pos;
}

void ADCContinuousConversion(ADC_TypeDef *adc, int enable){
	if(enable){
		adc->CFGR |= ADC_CFGR_CONT;
	}else{
		adc->CFGR &= ~ADC_CFGR_CONT;
	}
}

void ADCDataAlign(ADC_TypeDef *adc, int dir){
	// 0 -> right
	// 1 -> left
	if(dir == 0){
		adc->CFGR &= ~ADC_CFGR_ALIGN;
	}else{
		adc->CFGR |= ADC_CFGR_ALIGN;
	}
}

void ADCWakeup(ADC_TypeDef *adc){
	adc->CR &= ~ADC_CR_DEEPPWD;
	adc->CR |= ADC_CR_ADVREGEN;
	delay_us(20);
}

void ADCEnable(ADC_TypeDef *adc){
	adc->CR |= ADC_CR_ADEN;
	while(!(ADC1->ISR & ADC_ISR_ADRDY));
}

int ADCGetValue(ADC_TypeDef *adc){
	return adc->DR;
}

void ADCStartConversion(ADC_TypeDef *adc){
	adc->CR |= ADC_CR_ADSTART;
}

void ADCInterrupt(ADC_TypeDef *adc, int it, int enable){
	if(enable){
		adc->IER |= it;
	}else{
		adc->IER &= ~it;
	}
}

void ADCCommonDualMode(int mode){
	ADC123_COMMON->CCR &= ~ADC_CCR_DUAL;
	ADC123_COMMON->CCR |= mode << ADC_CCR_DUAL_Pos;
}

void ADCCommonClockMode(int clkMode){
	ADC123_COMMON->CCR &= ~ADC_CCR_CKMODE;
	ADC123_COMMON->CCR |= clkMode << ADC_CCR_CKMODE_Pos;
}

void ADCCommonPrescaler(int psc){
	ADC123_COMMON->CCR &= ~ADC_CCR_PRESC;
	ADC123_COMMON->CCR |= psc << ADC_CCR_PRESC_Pos;
}

void ADCCommonDMAMode(int mode){
	ADC123_COMMON->CCR &= ~ADC_CCR_MDMA;
	ADC123_COMMON->CCR |= mode << ADC_CCR_MDMA_Pos;
}

void ADCCommonDelayTwoSampling(int clk){
	ADC123_COMMON->CCR &= ~ADC_CCR_DELAY;
	ADC123_COMMON->CCR |= clk << ADC_CCR_DELAY_Pos;
}

void ADCChannel(ADC_TypeDef *adc, int channel, int rank, int sampleTime){
	if(rank <= 4){
		adc->SQR1 &= ~(ADC_SQR1_SQ1 << (rank * 6));
		adc->SQR1 |= (channel << (rank * 6));
	}
	if(channel <= 9){
		adc->SMPR1 &= ~(ADC_SMPR1_SMP0 << (channel * 3));
		adc->SMPR1 |= (sampleTime << (channel * 3));
	}
}

void ADC__construct(ADC *adc, ADC_TypeDef *adc_, GPIO_TypeDef *gpio, int pin, int use_interrupt, int channel, int rank){
	adc->adc = adc_;
	adc->gpio = gpio;
	adc->pin = pin;
	adc->use_interrupt = use_interrupt;
	adc->channel = channel;
	adc->rank = rank;
}

int ADC__init(ADC *adc)
{

	RCC->AHB2ENR |= RCC_AHB2ENR_ADCEN;
	
	if(adc->gpio == GPIOC)
	{
		GPIOC->MODER &= ~(3 << (adc->pin * 2));
		GPIOC->MODER |= 3 << (adc->pin * 2);
		GPIOC->ASCR |= 1 << adc->pin;
	}
	else
	{
		return -1;
	}

	ADCResolution(adc->adc, 0);              // 12 bits
	ADCContinuousConversion(adc->adc, 0);    // enable continuous conversion
	ADCDataAlign(adc->adc, 0);               // set right align
	ADCCommonDualMode(0);                    // independent mode
	ADCCommonClockMode(1);                   // hclk / 1
	ADCCommonPrescaler(0);                   // div 1
	ADCCommonDMAMode(0);                     // disable dma
	ADCCommonDelayTwoSampling(0b0100);       // 5 adc clk cycle
	ADCChannel(adc->adc, adc->channel, adc->rank, 2);
	ADCWakeup(adc->adc);
	if(adc->use_interrupt)    ADCInterrupt(adc->adc, ADC_IER_EOCIE, 1);
	else					  ADCInterrupt(adc->adc, ADC_IER_EOCIE, 0);
	NVIC_EnableIRQ(ADC1_2_IRQn);
	ADCEnable(adc->adc);

	return 0;
}

int ADC__read(ADC *adc)
{
	while (!(ADC1->ISR & ADC_ISR_ADRDY)) ADC1->CR |= ADC_CR_ADEN; // TURN ON
	delay_us(5000);
	ADC1->ISR = ADC_ISR_EOC | ADC_ISR_EOS | ADC_ISR_OVR; // Clear flags
	ADC1->CR |= ADC_CR_ADSTART; // START CONV
	
	while (!(ADC1->ISR & ADC_ISR_EOC));

	return ADC1->DR;
}