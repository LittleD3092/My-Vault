#include "7seg.h"
#include "helper_functions.h"


// Only allow GPIOA and GPIOB for now
// Can easily extended by adding "else if" cases
int init_7seg(GPIO_TypeDef* gpio, int DIN, int CS, int CLK){
	// Enable AHB2 Clock
	if(gpio==GPIOA){
		RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	}
	else if(gpio==GPIOB){
		RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
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

// use only if 7seg is in decode mode and only if scan limit is set to 7
// print data to the 7seg display
// return -1 if overflow
int print_7seg(GPIO_TypeDef* gpio, int DIN, int CS, int CLK, int number){
	// overflow
	if(number > 99999999 || number < -9999999)
		return -1;
	
	// negative
	int negative = 0;
	if(number < 0)
	{
		negative = 1;
		number = -number;
	}

	// print digits
	int current_digit = 0;
	while(number != 0)
	{
		int digit = number % 10;
		send_7seg(gpio, DIN, CS, CLK, SEG_ADDRESS_DIGIT_0+current_digit, SEG_DATA_DECODE_0+digit);
		number /= 10;
		current_digit++;
	}

	// print negative sign
	if(negative)
	{
		send_7seg(gpio, DIN, CS, CLK, SEG_ADDRESS_DIGIT_0+current_digit, SEG_DATA_DECODE_DASH);
		current_digit++;
	}

	// clear remaining digits
	while(current_digit <= 7)
	{
		send_7seg(gpio, DIN, CS, CLK, SEG_ADDRESS_DIGIT_0+current_digit, SEG_DATA_DECODE_BLANK);
		current_digit++;
	}

	return 0;
}