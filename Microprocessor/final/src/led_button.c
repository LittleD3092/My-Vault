#include "led_button.h"
#include "helper_functions.h"

// Only allow GPIOA and GPIOB for now
// Can easily extended by adding "else if" cases
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

// A simple way to read on board button
int user_press_button(int debounce){
	int cnt=0;
	for(int a=0;a<debounce;a++){
		if(read_gpio(GPIOC, 13)==0){
			cnt++;
		}
	}
	// Use 0.5 for threshold just to make it easier
	if(cnt>(debounce>>1)){
		return 1;
	}
	return 0;
}

void Led__construct(Led* led, GPIO_TypeDef* gpio, int pin){
	led->gpio = gpio;
	led->pin = pin;
}

int Led__init(Led* led){
	if(init_led(led->gpio, led->pin) != 0){
		// Fail to init led
		return -1;
	}
	return 0;
}

void Led__write(Led* led, int state){
	if(state==0){
		reset_gpio(led->gpio, led->pin);
	}
	else{
		set_gpio(led->gpio, led->pin);
	}
}

void Led__toggle(Led* led){
	toggle_output(led->gpio, led->pin);
}

void Button__construct(Button* button, GPIO_TypeDef* gpio, int pin){
	button->gpio = gpio;
	button->pin = pin;
	button->state = 0;
	button->last_state = 0;

	button->debounce_cycles = 100;
	button->debounce_threshold = button->debounce_cycles * 0.7;
}

int Button__init(Button* button){
	if(init_button(button->gpio, button->pin) != 0){
		// Fail to init button
		return -1;
	}
	return 0;
}

int Button__read(Button* button){
	int cnt=0;
	for(int a=0;a<button->debounce_cycles;a++){
		if(read_gpio(button->gpio, button->pin)==0){
			cnt++;
		}
		delay_without_interrupt(1);
	}
	if(cnt>button->debounce_threshold)
		return 1;
	else
		return 0;
}

int Button__is_pressed(Button* button){
	button->last_state = button->state;
	button->state = Button__read(button);
	return button->state && !button->last_state;
}

int Button__is_released(Button* button){
	button->last_state = button->state;
	button->state = Button__read(button);
	return !button->state && button->last_state;
}

void ButtonInterrupt__construct(ButtonInterrupt* button, GPIO_TypeDef* gpio, int pin, int EXTI_IRQn){
	Button__construct(&button->base, gpio, pin);
	button->EXTI_IRQn = EXTI_IRQn;
}

int ButtonInterrupt__init(ButtonInterrupt* button)
{
	Button__init(&button->base);
	// Enable SYSCFG Clock
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

	int gpioData = (&button->base)->gpio == GPIOA ? 0b0000 :
	               (&button->base)->gpio == GPIOB ? 0b0001 :
				   (&button->base)->gpio == GPIOC ? 0b0010 :
				   (&button->base)->gpio == GPIOD ? 0b0011 :
				   (&button->base)->gpio == GPIOE ? 0b0100 :
				   (&button->base)->gpio == GPIOF ? 0b0101 :
				   (&button->base)->gpio == GPIOG ? 0b0110 : 0b0111;

	// select output gpio
	int registerIndex = button->EXTI_IRQn / 4;
	int offset = (button->EXTI_IRQn % 4) * 4;
	SYSCFG->EXTICR[registerIndex] &= ~(0b0111 << offset);
	SYSCFG->EXTICR[registerIndex] |= (gpioData << offset);

	// enable interrupt
	EXTI->IMR1 |= (1 << button->EXTI_IRQn);
	
	// enable falling edge trigger
	// EXTI->FTSR1 |= (1 << button->EXTI_IRQn);

	// enable rising edge trigger
	EXTI->RTSR1 |= (1 << button->EXTI_IRQn);

	// enable NVIC
	if(button->EXTI_IRQn == 0)                                  NVIC_EnableIRQ(EXTI0_IRQn);
	else if(button->EXTI_IRQn == 1)                             NVIC_EnableIRQ(EXTI1_IRQn);
	else if(button->EXTI_IRQn == 2)                             NVIC_EnableIRQ(EXTI2_IRQn);
	else if(button->EXTI_IRQn == 3)                             NVIC_EnableIRQ(EXTI3_IRQn);
	else if(button->EXTI_IRQn == 4)                             NVIC_EnableIRQ(EXTI4_IRQn);
	else if(button->EXTI_IRQn >= 5 && button->EXTI_IRQn <= 9)   NVIC_EnableIRQ(EXTI9_5_IRQn);
	else if(button->EXTI_IRQn >= 10 && button->EXTI_IRQn <= 15) NVIC_EnableIRQ(EXTI15_10_IRQn);
	else                                                        return -1;

	return 0;
}

int ButtonInterrupt__is_pressed(ButtonInterrupt* button){
	return button->base.state && !button->base.last_state;
}

int ButtonInterrupt__is_released(ButtonInterrupt* button){
	return !button->base.state && button->base.last_state;
}

void ButtonInterrupt__callbackRefresh(ButtonInterrupt* button){
	button->base.last_state = button->base.state;
	button->base.state = Button__read(&button->base);
}
