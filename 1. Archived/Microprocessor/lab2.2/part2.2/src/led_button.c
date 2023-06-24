#include "led_button.h"

// Only allow GPIOA and GPIOB for now
// Can easily extended by adding "else if" cases
// Precondition: gpio is a valid GPIO port (GPIOA, GPIOB, etc.)
//               LED_pin is a valid pin number (0-15)
// Postcondition: GPIO pin is set to output mode
//                if gpio is not a valid GPIO port, return -1
//                otherwise, return 0
int init_led(GPIO_TypeDef* gpio, int LED_pin){
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
	gpio->MODER &= ~(0b11 << (2*LED_pin));
	gpio->MODER |= (0b01 << (2*LED_pin));

	return 0;
}

// Only allow GPIOC for now
// Can easily extended by adding "else if" cases
int init_button(GPIO_TypeDef* gpio, int button_pin){
	// Enable AHB2 Clock
	if(gpio==GPIOC){
		RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
	}
	else{
		// Error! Add other cases to suit other GPIO pins
		return -1;
	}

	// Set GPIO pins to input mode (00)
	// First Clear bits(&) then set bits(|)
	gpio->MODER &= ~(0b11 << (2*button_pin));
	gpio->MODER |= (0b00 << (2*button_pin));

	return 0;
}
