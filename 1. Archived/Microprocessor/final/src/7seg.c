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

int init_7seg_number(GPIO_TypeDef* gpio, int DIN, int CS, int CLK){
	if(init_7seg(gpio, DIN, CS, CLK) != 0){
		// Fail to init 7seg
		return -1;
	}
	// Set Decode Mode to Code B decode mode
	send_7seg(gpio, DIN, CS, CLK, SEG_ADDRESS_DECODE_MODE, 0xFF);
	// Set Scan Limit to all digits
	send_7seg(gpio, DIN, CS, CLK, SEG_ADDRESS_SCAN_LIMIT, 0x07);
	// Wakeup 7seg
	send_7seg(gpio, DIN, CS, CLK, SEG_ADDRESS_SHUTDOWN, 0x01);
	// Clear the digits
	for(int i=1;i<=8;i++){
		send_7seg(gpio, DIN, CS, CLK, i, 15);
	}

	return 0;
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

int display_two_decimal(GPIO_TypeDef* gpio, int DIN, int CS, int CLK, double num){
	// Set two decimal points
	int dec_1=(int)(num*10)%10, dec_2=(int)(num*100)%10;
	send_7seg(gpio, DIN, CS, CLK, 2, dec_1);
	send_7seg(gpio, DIN, CS, CLK, 1, dec_2);

	int number=num;
	// Set third digit, add a decimal dot
	send_7seg(gpio, DIN, CS, CLK, 3, 0x80+number%10);
	number = number/10;

	for(int i=4;i<=8;i++){
		if(number>0){
			send_7seg(gpio, DIN, CS, CLK, i, number%10);
			number = number/10;
		}
		else{
			send_7seg(gpio, DIN, CS, CLK, i, 15);
		}
	}

	return 0;
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

// Constructor of SevenSeg
void SevenSeg__construct(SevenSeg* self, GPIO_TypeDef* gpio, int DIN, int CS, int CLK)
{
	self->gpio = gpio;
	self->DIN = DIN;
	self->CS = CS;
	self->CLK = CLK;
}

void SevenSeg__init(SevenSeg* self)
{
	init_7seg_number(self->gpio, self->DIN, self->CS, self->CLK);
}

// Print member function
// Precondition: self is a valid pointer to a SevenSeg object
//               num is an integer
// Postcondition: num is displayed on the SevenSeg, then return 0
//                if num exceeds the range of the SevenSeg, return 1
int SevenSeg__printNum(SevenSeg* self, int num)
{
	// overflow
	if(num > 99999999 || num < -9999999)    return -1;

	int current_digit = 0;
	// exact zero
	if(num == 0)
	{
		send_7seg(self->gpio, self->DIN, self->CS, self->CLK, SEG_ADDRESS_DIGIT_0, SEG_DATA_DECODE_0);
		current_digit++;
	}

	// negative
	int negative = 0;
	if(num < 0)
	{
		negative = 1;
		num = -num;
	}

	// print digits
	while(num != 0)
	{
		int digit = num % 10;
		send_7seg(self->gpio, self->DIN, self->CS, self->CLK, SEG_ADDRESS_DIGIT_0+current_digit, SEG_DATA_DECODE_0+digit);
		num /= 10;
		current_digit++;
	}

	// print negative sign
	if(negative)
	{
		send_7seg(self->gpio, self->DIN, self->CS, self->CLK, SEG_ADDRESS_DIGIT_0+current_digit, SEG_DATA_DECODE_DASH);
		current_digit++;
	}

	// clear remaining digits
	while(current_digit <= 7)
	{
		send_7seg(self->gpio, self->DIN, self->CS, self->CLK, SEG_ADDRESS_DIGIT_0+current_digit, SEG_DATA_DECODE_BLANK);
		current_digit++;
	}

	return 0;
}

void SevenSeg__printFraction(SevenSeg* self, struct fraction x){
	display_fraction(self->gpio, self->DIN, self->CS, self->CLK, x);
}
