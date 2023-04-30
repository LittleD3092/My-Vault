#include "helper_functions.h"

int read_gpio(GPIO_TypeDef* gpio, int pin){
	return (gpio->IDR >> pin) & 1;
}
void set_gpio(GPIO_TypeDef* gpio, int pin){
	gpio->BSRR |= (1 << pin);
}
void reset_gpio(GPIO_TypeDef* gpio, int pin){
	gpio->BRR |= (1 << pin);
}
void toggle_output(GPIO_TypeDef* gpio, int pin){
	if(read_gpio(gpio, pin)==0){
		set_gpio(gpio, pin);
	}
	else{
		reset_gpio(gpio, pin);
	}
}

void FPU_init(){
	// Setup FPU
	SCB->CPACR |= (0xF << 20);
	__DSB();
	__ISB();
}

void delay_without_interrupt(float msec){
	int loop_cnt = 500*msec;
	while(loop_cnt){
		loop_cnt--;
	}
	return;
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

int gcd(int a, int b){
	while((a %= b) && (b %= a));
	return a + b;
}
int lcm(int a, int b){
	return a / gcd(a, b) * b;
}
