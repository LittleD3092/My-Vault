#include "keypad.h"
#include "helper_functions.h"

// Mapping for key-press
const int keypad[4][4] = {
	{1, 2, 3, 10},
	{4, 5, 6, 11},
	{7, 8, 9, 12},
	{15, 0, 14, 13}
};

// Only allow GPIOA and GPIOB for now
// Can easily extended by adding "else if" cases
int init_keypad(GPIO_TypeDef* ROW_gpio, GPIO_TypeDef* COL_gpio, int ROW_pin, int COL_pin){
	// Enable AHB2 Clock
	if(ROW_gpio==GPIOA || COL_gpio==GPIOA){
		RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	}
	if(ROW_gpio==GPIOB || COL_gpio==GPIOB){
		RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
	}

	// First Clear bits(&) then set bits(|)
	for(int a=0;a<4;a++){
		// Set GPIO pins to output mode (01)
		COL_gpio->MODER &= ~(0b11 << (2*(COL_pin+a)));
		COL_gpio->MODER |= (0b01 << (2*(COL_pin+a)));
		// Set GPIO pins to open drain mode (1)
		COL_gpio->OTYPER &= ~(0b1 << (COL_pin+a));
		COL_gpio->OTYPER |= (0b1 << (COL_pin+a));
		// Set Output to high
		set_gpio(COL_gpio, COL_pin+a);
	}

	// First Clear bits(&) then set bits(|)
	for(int a=0;a<4;a++){
		// Set GPIO pins to input mode (00)
		ROW_gpio->MODER &= ~(0b11 << (2*(ROW_pin+a)));
		ROW_gpio->MODER |= (0b00 << (2*(ROW_pin+a)));
		// Set GPIO pins to Pull-Down mode (10)
		ROW_gpio->PUPDR &= ~(0b11 << (2*(ROW_pin+a)));
		ROW_gpio->PUPDR |= (0b10 << (2*(ROW_pin+a)));
	}

	return 0;
}

int check_keypad_input_one(GPIO_TypeDef* ROW_gpio, GPIO_TypeDef* COL_gpio, int ROW_pin, int COL_pin, int x, int y){
	int cycles = 400;
	// Set Column to push-pull mode
	COL_gpio->OTYPER &= ~(1 << (COL_pin+y));
	// Count the total number of time it is pressed in a certain period
	int cnt = 0;
	for(int a=0;a<cycles;a++){
		cnt += read_gpio(ROW_gpio, ROW_pin+x);
	}
	// Set Column back to open drain mode
	COL_gpio->OTYPER |= (1 << (COL_pin+y));
	// return if the key is pressed(1) or not(0)
	return (cnt > (cycles*0.7));
}

int check_keypad_input_multiple(GPIO_TypeDef* ROW_gpio, GPIO_TypeDef* COL_gpio, int ROW_pin, int COL_pin){
	// Count the total number of time each input is pressed in a certain period
	int cnt[4][4];
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cnt[i][j] = 0;
		}
	}
	int cycles = 400;
	for(int a=0;a<cycles;a++){
		for(int j=0;j<4;j++){
			// Set Column to push-pull mode
			COL_gpio->OTYPER &= ~(1 << (COL_pin+j));
			// Read the whole row
			for(int i=0;i<4;i++){
				cnt[i][j] += read_gpio(ROW_gpio, ROW_pin+i);
			}
			// Set Column back to open drain mode
			COL_gpio->OTYPER |= (1 << (COL_pin+j));
		}
	}
	// Use a int to represent a bitmap of 16 bits
	int res = 0;
	for(int i=3;i>=0;i--){
		for(int j=3;j>=0;j--){
			res = (res << 1) | (cnt[i][j] >= 300);
		}
	}
	return res;
}

void Keypad__construct(Keypad* self, GPIO_TypeDef* ROW_gpio, GPIO_TypeDef* COL_gpio, int ROW_pin, int COL_pin){
	self->ROW_gpio = ROW_gpio;
	self->COL_gpio = COL_gpio;
	self->ROW_pin = ROW_pin;
	self->COL_pin = COL_pin;

	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			self->buttons[i][j] = 0;
			self->last_buttons[i][j] = 0;
		}
	}
}

int Keypad__init(Keypad* self)
{
	if(init_keypad(self->ROW_gpio, self->COL_gpio, self->ROW_pin, self->COL_pin) != 0){
		return -1;
	}
	return 0;
}

void Keypad__refresh(Keypad* self)
{
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			self->last_buttons[i][j] = self->buttons[i][j];

	int input = check_keypad_input_multiple(self->ROW_gpio, self->COL_gpio, self->ROW_pin, self->COL_pin);

	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			self->buttons[i][j] = (input >> (i*4+j)) & 1;
}

char Keypad__getChar(Keypad* self)
{
	char chars[4][4] = {
		{'1', '2', '3', 'A'},
		{'4', '5', '6', 'B'},
		{'7', '8', '9', 'C'},
		{'*', '0', '#', 'D'}
	};

	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			if(self->buttons[i][j])
				return chars[i][j];

	return 0;
}

char Keypad__getCharPressed(Keypad* self)
{
	char chars[4][4] = {
		{'1', '2', '3', 'A'},
		{'4', '5', '6', 'B'},
		{'7', '8', '9', 'C'},
		{'*', '0', '#', 'D'}
	};

	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			if(self->buttons[i][j] && !self->last_buttons[i][j])
				return chars[i][j];

	return 0;
}

char Keypad__getCharReleased(Keypad* self)
{
	char chars[4][4] = {
		{'1', '2', '3', 'A'},
		{'4', '5', '6', 'B'},
		{'7', '8', '9', 'C'},
		{'*', '0', '#', 'D'}
	};
	
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			if(!self->buttons[i][j] && self->last_buttons[i][j])
				return chars[i][j];

	return 0;
}

void KeypadInterrupt__construct(KeypadInterrupt* self, GPIO_TypeDef* ROW_gpio, GPIO_TypeDef* COL_gpio, int ROW_pin, int COL_pin, int EXTI_IRQn)
{
	Keypad__construct(&self->base, ROW_gpio, COL_gpio, ROW_pin, COL_pin);
	self->EXTI_IRQn = EXTI_IRQn;
	self->currentOutputCol = 0;
}

int KeypadInterrupt__init(KeypadInterrupt* self)
{
	int statusCode = Keypad__init(&self->base);

	// enable SYSCFG clock
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	
	int gpioData = (&self->base)->ROW_gpio == GPIOA ? 0b0000 :
	                           				  GPIOB ? 0b0001 :
											  GPIOC ? 0b0010 :
											  GPIOD ? 0b0011 :
											  GPIOE ? 0b0100 :
											  GPIOF ? 0b0101 :
											  GPIOG ? 0b0110 : 0b0111;
	for(int interruptIndex = self->EXTI_IRQn; interruptIndex < self->EXTI_IRQn + 4; interruptIndex++)
	{
		// select output gpio
		int registerIndex = interruptIndex / 4;
		int offset = (interruptIndex % 4) * 4;
		SYSCFG->EXTICR[registerIndex] &= ~(0b0111 << offset);
		SYSCFG->EXTICR[registerIndex] |= (gpioData << offset);

		// enable interrupt
		EXTI->IMR1 |= (1 << interruptIndex);
		
		// enable falling edge trigger
		// EXTI->FTSR1 |= (1 << interruptIndex);

		// enable rising edge trigger
		EXTI->RTSR1 |= (1 << interruptIndex);

		// enable NVIC
		if(interruptIndex == 0)                               NVIC_EnableIRQ(EXTI0_IRQn);
		else if(interruptIndex == 1)                          NVIC_EnableIRQ(EXTI1_IRQn);
		else if(interruptIndex == 2)                          NVIC_EnableIRQ(EXTI2_IRQn);
		else if(interruptIndex == 3)                          NVIC_EnableIRQ(EXTI3_IRQn);
		else if(interruptIndex == 4)                          NVIC_EnableIRQ(EXTI4_IRQn);
		else if(interruptIndex >= 5 && interruptIndex <= 9)   NVIC_EnableIRQ(EXTI9_5_IRQn);
		else if(interruptIndex >= 10 && interruptIndex <= 15) NVIC_EnableIRQ(EXTI15_10_IRQn);
		else                                                  return -1;
	}
	return statusCode;
}

void KeypadInterrupt__shiftOutput(KeypadInterrupt* self)
{
	reset_push(self->base.COL_gpio, self->currentOutputCol + self->base.COL_pin);
	self->currentOutputCol = (self->currentOutputCol + 1) % 4;
	set_push(self->base.COL_gpio, self->currentOutputCol + self->base.COL_pin);
}

void KeypadInterrupt__callbackRefresh(KeypadInterrupt* self)
{
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
		{
			self->base.last_buttons[i][j] = self->base.buttons[i][j];
			self->base.buttons[i][j] = 0;
		}
	for(int i = 0; i < 4; i++)
	{
		self->base.buttons[i][self->currentOutputCol] = read_gpio(self->base.ROW_gpio, self->base.ROW_pin + i);
	}
}

char KeypadInterrupt__getChar(KeypadInterrupt* self)
{
	return Keypad__getChar(&self->base);
}

char KeypadInterrupt__getCharPressed(KeypadInterrupt* self)
{
	return Keypad__getCharPressed(&self->base);
}

char KeypadInterrupt__getCharReleased(KeypadInterrupt* self)
{
	return Keypad__getCharReleased(&self->base);
}
