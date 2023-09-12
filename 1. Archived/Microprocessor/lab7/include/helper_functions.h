#include "stm32l476xx.h"

#define read_gpio(gpio, pin) ((gpio->IDR >> (pin)) & 1)

#define set_gpio(gpio, pin){                       \
	gpio->BSRR |= (1 << (pin));                    \
}
#define reset_gpio(gpio, pin){                     \
	gpio->BRR |= (1 << (pin));                     \
}

void toggle_output(GPIO_TypeDef* gpio, int pin);

void set_push(GPIO_TypeDef* gpio, int pin);
void reset_push(GPIO_TypeDef* gpio, int pin);

#define ENABLE_SYSTICK(){                       \
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;   \
}
#define DISABLE_SYSTICK(){                      \
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;  \
}

void timer_set_interrupt(TIM_TypeDef *timer);

#define delay_ms(x){                      \
	RCC->APB1ENR1 |= RCC_APB1ENR1_TIM2EN; \
	TIM2->PSC = (10000000/1000)-1;          \
	TIM2->ARR = UINT16_MAX-1;               \
	TIM2->EGR |= TIM_EGR_UG;              \
	TIM2->CR1 |= TIM_CR1_CEN;             \
	while(TIM2->CNT < x);                 \
	TIM2->CR1 &= ~TIM_CR1_CEN;            \
}

#define delay_us(x){                      \
	RCC->APB1ENR1 |= RCC_APB1ENR1_TIM2EN; \
	TIM2->PSC = (10000000/1000000)-1;       \
	TIM2->ARR = UINT16_MAX-1;               \
	TIM2->EGR |= TIM_EGR_UG;              \
	TIM2->CR1 |= TIM_CR1_CEN;             \
	while(TIM2->CNT < x);                 \
	TIM2->CR1 &= ~TIM_CR1_CEN;            \
}

int gcd(int a, int b);
int lcm(int a, int b);

#define abs(x) (((x) < 0) ? (-(x)) : (x))

int num_digits(int x);
void delay_without_interrupt(float msec);
