#include "stm32l476xx.h"
#include "adc.h"
#include "fpu.h"
#include "led_button.h"
#include "7seg.h"
#include "timer.h"
#include "helper_functions.h"

// #define PART1
#define PART2

#ifdef PART1

#define LED_GPIO GPIOA
#define LED_PIN 5

#define BUTTON_GPIO GPIOC
#define BUTTON_PIN 13

#define ADC_ADC ADC1
#define ADC_GPIO GPIOC
#define ADC_PIN 0

#define SEVENSEG_GPIO GPIOC
#define SEVENSEG_DIN 3
#define SEVENSEG_CS 4
#define SEVENSEG_CLK 5

void SysTick_Handler() {
	if(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk){
		ADCStartConversion(ADC1);
	}
	return;
}

void ADC1_2_IRQHandler(){
	if(ADC1->ISR & ADC_ISR_EOC){
		ADC1->ISR &= ADC_ISR_EOC;
	}
}

int main()
{
	FPU__enable();

	SystemClock system_clock;
	SystemClock__construct(&system_clock, 4000000, 4000000);
	SystemClock__init(&system_clock);
	
	Led led;
	Led__construct(&led, LED_GPIO, LED_PIN);
	Led__init(&led);

	Button button;
	Button__construct(&button, BUTTON_GPIO, BUTTON_PIN);
	Button__init(&button);

	ADC adc;
	ADC__construct(
		&adc, 
		ADC_ADC, 
		ADC_GPIO, 
		ADC_PIN
	);
	ADC__init(&adc);

	SevenSeg seven_seg;
	SevenSeg__construct(
		&seven_seg, 
		SEVENSEG_GPIO, 
		SEVENSEG_DIN, 
		SEVENSEG_CS, 
		SEVENSEG_CLK
	);
	SevenSeg__init(&seven_seg);

	Timer timer;
	Timer__construct(&timer, TIM3);
	Timer__init(&timer);

	int last_time = 0;
	while(1)
	{
		int current_time = Timer__get_msecs(&timer);
		if(current_time - last_time > 1000)
		{
			last_time = current_time;
			SevenSeg__printNum(&seven_seg, ADC__read(&adc));
			// SevenSeg__printNum(&seven_seg, current_time);
		}
		delay_ms(1);
	}
}
#endif

#ifdef PART2
#define LED_GPIO GPIOA
#define LED_PIN 5

#define BUTTON_GPIO GPIOC
#define BUTTON_PIN 13

#define ADC1_ADC ADC1
#define ADC1_GPIO GPIOC
#define ADC1_PIN 0
#define ADC1_USE_INTERRUPT 0
#define ADC1_CHANNEL 1
#define ADC1_RANK 1

#define ADC2_ADC ADC1
#define ADC2_GPIO GPIOC
#define ADC2_PIN 1
#define ADC2_USE_INTERRUPT 0
#define ADC2_CHANNEL 2
#define ADC2_RANK 2

#define ADC3_ADC ADC1
#define ADC3_GPIO GPIOC
#define ADC3_PIN 2
#define ADC3_USE_INTERRUPT 0
#define ADC3_CHANNEL 3
#define ADC3_RANK 3

#define SEVENSEG_GPIO GPIOC
#define SEVENSEG_DIN 3
#define SEVENSEG_CS 4
#define SEVENSEG_CLK 5

void SysTick_Handler() {
	if(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk){
		ADCStartConversion(ADC1);
	}
	return;
}

int main()
{
	FPU__enable();

	SystemClock system_clock;
	SystemClock__construct(&system_clock, 4000000, 4000000);
	SystemClock__init(&system_clock);
	
	Led led;
	Led__construct(&led, LED_GPIO, LED_PIN);
	Led__init(&led);

	Button button;
	Button__construct(&button, BUTTON_GPIO, BUTTON_PIN);
	Button__init(&button);

	ADC adc1, adc2, adc3;
	ADC__construct(
		&adc1, 
		ADC1_ADC, 
		ADC1_GPIO, 
		ADC1_PIN,
		ADC1_USE_INTERRUPT,
		ADC1_CHANNEL,
		ADC1_RANK
	);
	ADC__init(&adc1);
	ADC__construct(
		&adc2, 
		ADC2_ADC, 
		ADC2_GPIO, 
		ADC2_PIN,
		ADC2_USE_INTERRUPT,
		ADC2_CHANNEL,
		ADC2_RANK
	);
	ADC__init(&adc2);
	ADC__construct(
		&adc3, 
		ADC3_ADC, 
		ADC3_GPIO, 
		ADC3_PIN,
		ADC3_USE_INTERRUPT,
		ADC3_CHANNEL,
		ADC3_RANK
	);
	ADC__init(&adc3);

	SevenSeg seven_seg;
	SevenSeg__construct(
		&seven_seg, 
		SEVENSEG_GPIO, 
		SEVENSEG_DIN, 
		SEVENSEG_CS, 
		SEVENSEG_CLK
	);
	SevenSeg__init(&seven_seg);

	Timer timer;
	Timer__construct(&timer, TIM3);
	Timer__init(&timer);

	while(1)
	{
		SevenSeg__printNumUpper(&seven_seg, 1);
		SevenSeg__printNumLower(&seven_seg, ADC__read(&adc1));
		delay_ms(1000);

		SevenSeg__printNumUpper(&seven_seg, 2);
		SevenSeg__printNumLower(&seven_seg, ADC__read(&adc2));
		delay_ms(1000);

		SevenSeg__printNumUpper(&seven_seg, 3);
		SevenSeg__printNumLower(&seven_seg, ADC__read(&adc3));
		delay_ms(1000);
	}
}
#endif