#include "stm32l476xx.h"
#include "helper_functions.h"

void toggle_output(GPIO_TypeDef* gpio, int pin){
	if(read_gpio(gpio, pin)==0){
		set_gpio(gpio, pin);
	}
	else{
		reset_gpio(gpio, pin);
	}
}

void set_push(GPIO_TypeDef* gpio, int pin){
	gpio->OTYPER |= (1 << pin);
}
void reset_push(GPIO_TypeDef* gpio, int pin){
	gpio->OTYPER &= ~(1 << pin);
}

void timer_set_interrupt(TIM_TypeDef *timer){
	timer->DIER |= TIM_DIER_UIE;
}

int gcd(int a, int b){
	while((a %= b) && (b %= a));
	return a + b;
}
int lcm(int a, int b){
	return a / gcd(a, b) * b;
}

int num_digits(int x){
	if(x == 0){
		return 1;
	}
	int res = 0;
	while(x){
		res++;
		x /= 10;
	}
	return res;
}

void delay_without_interrupt(float msec){
	int loop_cnt = 500*msec;
	while(loop_cnt){
		loop_cnt--;
	}
	return;
}