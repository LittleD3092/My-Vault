#include "7seg.h"
#include "helper_functions.h"

// Only allow GPIOA and GPIOB and GPIOC for now
// Can easily extended by adding "else if" cases
int init_7seg(GPIO_TypeDef* gpio, int DIN, int CS, int CLK){
	// Enable AHB2 Clock
	if(gpio==GPIOA){
		RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	}
	else if(gpio==GPIOB){
		RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
	}
	else if(gpio==GPIOC){
		RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
	}
	else{
		// Error! Add other cases to suit other GPIO pins
		return -1;
	}

	// Set GPIO pins to output mode (01)
	// First Clear bits(&) then set bits(|)
	gpio->MODER &= ~(0b11 << (2*DIN));
	gpio->MODER |= (0b01 << (2*DIN));
	gpio->MODER &= ~(0b11 << (2*CS));
	gpio->MODER |= (0b01 << (2*CS));
	gpio->MODER &= ~(0b11 << (2*CLK));
	gpio->MODER |= (0b01 << (2*CLK));

	// Close display test
	send_7seg(gpio, DIN, CS, CLK, SEG_ADDRESS_DISPLAY_TEST, 0x00);

	return 0;
}

void send_7seg(GPIO_TypeDef* gpio, int DIN, int CS, int CLK, int address, int data){
	// The payload to send
	int payload = ((address&0xFF)<<8)|(data&0xFF);

	// Start the sending cycles
	// 16 data-bits + 1 CS signal
	int total_cycles = 16+1;

	for(int a=1;a<=total_cycles;a++){
		// Reset CLK when enter
		reset_gpio(gpio, CLK);

		// Set DIN according to data except for last cycle(CS)
		if(((payload>>(total_cycles-1-a))&0x1) && a!=total_cycles){
			set_gpio(gpio, DIN);
		}
		else{
			reset_gpio(gpio, DIN);
		}

		// Set CS at last cycle
		if(a==total_cycles){
			set_gpio(gpio, CS);
		}
		else{
			reset_gpio(gpio, CS);
		}

		// Set CLK when leaving (7seg set data at rising edge)
		set_gpio(gpio, CLK);
	}

	return;
}

int display_number(GPIO_TypeDef* gpio, int DIN, int CS, int CLK, int num, int num_digs){
	for(int i=1;i<=num_digs;i++){
		send_7seg(gpio, DIN, CS, CLK, i, num % 10);
		num /= 10;
	}
	for(int i=num_digs+1;i<=8;i++){
		num /= 10;
		send_7seg(gpio, DIN, CS, CLK, i, 15);
	}
	if(num != 0)
		return -1;
	return 0;
}

// Functions for implementing fractions
struct fraction add(struct fraction x, struct fraction y){
	struct fraction res;
	res.b = lcm(x.b, y.b);
	res.a = x.a * res.b / x.b + y.a * res.b / y.b;
	return res;
}
struct fraction sub(struct fraction x, struct fraction y){
	struct fraction res;
	res.b = lcm(x.b, y.b);
	res.a = x.a * res.b / x.b - y.a * res.b / y.b;
	return res;
}
struct fraction mul(struct fraction x, struct fraction y){
	struct fraction res;
	res.a = x.a * y.a;
	res.b = x.b * y.b;
	int d = gcd(res.a, res.b);
	res.a /= d, res.b /= d;
	return res;
}
struct fraction div(struct fraction x, struct fraction y){
	struct fraction tmp = {.a=y.b, .b=y.a};
	return mul(x, tmp);
}
struct fraction calc(int *data, int n){
	int stk[128], stk_idx = 0;
	int output[128], output_idx = 0;
	for(int i=0;i<n;i++){
		if(1010 <= data[i] && data[i] <= 1013){ //op
			while(stk_idx && stk[stk_idx - 1] >= data[i]){
				output[output_idx++] = stk[--stk_idx];
			}
			stk[stk_idx++] = data[i];
		}else{
			output[output_idx++] = data[i];
		}
	}
	while(stk_idx){
		output[output_idx++] = stk[--stk_idx];
	}
	struct fraction op1, op2, invalid = {.a=-1, .b=1};
	struct fraction ans_stk[128];
	int ans_stk_idx = 0;
	for(int i=0;i<n;i++){
		if(output[i] == 1010){
			if(ans_stk_idx < 2) return invalid;
			op2 = ans_stk[--ans_stk_idx];
			op1 = ans_stk[--ans_stk_idx];
			ans_stk[ans_stk_idx++] = add(op1, op2);
		}else if(output[i] == 1011){
			if(ans_stk_idx < 2) return invalid;
			op2 = ans_stk[--ans_stk_idx];
			op1 = ans_stk[--ans_stk_idx];
			ans_stk[ans_stk_idx++] = sub(op1, op2);
		}else if(output[i] == 1012){
			if(ans_stk_idx < 2) return invalid;
			op2 = ans_stk[--ans_stk_idx];
			op1 = ans_stk[--ans_stk_idx];
			ans_stk[ans_stk_idx++] = mul(op1, op2);
		}else if(output[i] == 1013){
			if(ans_stk_idx < 2) return invalid;
			op2 = ans_stk[--ans_stk_idx];
			op1 = ans_stk[--ans_stk_idx];
			if(op2.a == 0) return invalid;
			ans_stk[ans_stk_idx++] = div(op1, op2);
		}else{
			op1.a = output[i], op1.b = 1;
			ans_stk[ans_stk_idx++] = op1;
		}
	}
	if(ans_stk_idx != 1){
		return invalid;
	}
	return ans_stk[0];
}

void display_fraction(GPIO_TypeDef* gpio, int DIN, int CS, int CLK, struct fraction x){
	int sign = (x.a * x.b) >= 0 ? 0 : 1;
	x.a = abs(x.a);
	x.b = abs(x.b);
	if(x.b == 1){
		int digits = num_digits(x.a);
		display_number(gpio, DIN, CS, CLK, x.a, digits);
		if(sign){
			send_7seg(gpio, DIN, CS, CLK, digits + 1, 10);
		}
	}
	else{
		int a = x.a / x.b, b = 0, a_digits = num_digits(a), b_digits = 0;
		int digits = a_digits + sign;
		x.a %= x.b;
		for(;digits<8&&x.a;digits++,b_digits++){
			x.a *= 10;
			b = b * 10 + x.a / x.b;
			x.a %= x.b;
		}
		for(int i=0;i<b_digits;i++){
			send_7seg(gpio, DIN, CS, CLK, i + 1, b % 10);
			b /= 10;
		}
		for(int i=0;i<a_digits;i++){
			send_7seg(gpio, DIN, CS, CLK, i + b_digits + 1, (a % 10) | (i ? 0 : (1 << 7)));
			a /= 10;
		}
		for(int i=digits+1;i<=8;i++){
			send_7seg(gpio, DIN, CS, CLK, i, 15);
		}
	}
}

