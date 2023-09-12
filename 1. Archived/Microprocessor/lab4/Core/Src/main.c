#include "stm32l476xx.h"
#include "helper_functions.h"
#include "7seg.h"
#include "keypad.h"
#include <math.h>

// Define pins for 7seg
#define SEG_gpio GPIOC
#define DIN_pin 3  // left pins, last row, first column
#define CS_pin 4   // right pins, last 3rd row, last column
#define CLK_pin 5  // right pins, 3rd row, last column

// Define pins for keypad
#define COL_gpio GPIOA
#define COL_pin 5       // 5 6 7 8
                        // GPIO_A5: arduino pin D13
						// GPIO_A6: arduino pin D12
						// GPIO_A7: arduino pin D11
						// GPIO_A8: arduino pin D7
#define ROW_gpio GPIOB
#define ROW_pin 3       // 3 4 5 6
						// GPIO_B3: arduino pin D3
						// GPIO_B4: arduino pin D5
						// GPIO_B5: arduino pin D4
						// GPIO_B6: arduino pin D10

// Use to decide which part of the code will run
// Use define & ifdef to control
// #define lab_keypad_single_key
// #define lab_keypad_calculator_2_operands
// #define lab_keypad_calculator_multi_operands
#define lab_keypad_multi_key

typedef struct SevenSegDisplay SevenSegDisplay;
struct SevenSegDisplay
{
	GPIO_TypeDef *gpio;
	int din_pin;
	int cs_pin;
	int clk_pin;
};

SevenSegDisplay SevenSegDisplay__construct(GPIO_TypeDef *gpio, int din_pin, int cs_pin, int clk_pin)
{
	SevenSegDisplay display;
	display.gpio = gpio;
	display.din_pin = din_pin;
	display.cs_pin = cs_pin;
	display.clk_pin = clk_pin;
	return display;
}

int SevenSegDisplay__init(SevenSegDisplay self)
{
	if(init_7seg(self.gpio, self.din_pin, self.cs_pin, self.clk_pin) != 0){
		// Fail to init 7seg
		return -1;
	}

	// Set Decode Mode to Code B decode mode
	send_7seg(self.gpio, self.din_pin, self.cs_pin, self.clk_pin, SEG_ADDRESS_DECODE_MODE, 0xFF);
	// Set Scan Limit to all digits
	send_7seg(self.gpio, self.din_pin, self.cs_pin, self.clk_pin, SEG_ADDRESS_SCAN_LIMIT, 0x07);
	// Wakeup 7seg
	send_7seg(self.gpio, self.din_pin, self.cs_pin, self.clk_pin, SEG_ADDRESS_SHUTDOWN, 0x01);

	return 0;
}

int SevenSegDisplay__print(SevenSegDisplay self, int number)
{
	// overflow
	if(number > 99999999 || number < -9999999)
		return -1;

	int current_digit = 0;
	// exact zero
	if(number == 0)
	{
		send_7seg(self.gpio, self.din_pin, self.cs_pin, self.clk_pin, SEG_ADDRESS_DIGIT_0, SEG_DATA_DECODE_0);
		current_digit++;
	}
	
	// negative
	int negative = 0;
	if(number < 0)
	{
		negative = 1;
		number = -number;
	}

	// print digits
	while(number != 0)
	{
		int digit = number % 10;
		send_7seg(self.gpio, self.din_pin, self.cs_pin, self.clk_pin, SEG_ADDRESS_DIGIT_0+current_digit, SEG_DATA_DECODE_0+digit);
		number /= 10;
		current_digit++;
	}

	// print negative sign
	if(negative)
	{
		send_7seg(self.gpio, self.din_pin, self.cs_pin, self.clk_pin, SEG_ADDRESS_DIGIT_0+current_digit, SEG_DATA_DECODE_DASH);
		current_digit++;
	}

	// clear remaining digits
	while(current_digit <= 7)
	{
		send_7seg(self.gpio, self.din_pin, self.cs_pin, self.clk_pin, SEG_ADDRESS_DIGIT_0+current_digit, SEG_DATA_DECODE_BLANK);
		current_digit++;
	}

	return 0;
}

typedef struct Keypad Keypad;
struct Keypad
{
	GPIO_TypeDef *row_gpio;
	int row_pin;
	GPIO_TypeDef *col_gpio;
	int col_pin;

	int buttons[4][4];
	int last_buttons[4][4];
};

Keypad Keypad__construct(GPIO_TypeDef *row_gpio, int row_pin, GPIO_TypeDef *col_gpio, int col_pin)
{
	Keypad keypad;

	keypad.row_gpio = row_gpio;
	keypad.row_pin = row_pin;
	keypad.col_gpio = col_gpio;
	keypad.col_pin = col_pin;

	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
		{
			keypad.buttons[i][j] = 0;
			keypad.last_buttons[i][j] = 0;
		}

	return keypad;
}

int Keypad__init(Keypad self)
{
	if(init_keypad(self.row_gpio, self.col_gpio, self.row_pin, self.col_pin) != 0){
		// Fail to init keypad
		return -1;
	}
	return 0;
}

Keypad Keypad__refresh(Keypad self)
{
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
		{
			self.last_buttons[i][j] = self.buttons[i][j];
			self.buttons[i][j] = check_keypad_input_one(self.row_gpio, self.col_gpio, self.row_pin, self.col_pin, i, j);
		}

	return self;
}

Keypad Keypad__accumulateRefresh(Keypad self)
{
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
		{
			self.last_buttons[i][j] = self.buttons[i][j];
			self.buttons[i][j] |= check_keypad_input_one(self.row_gpio, self.col_gpio, self.row_pin, self.col_pin, i, j);
		}

	return self;
}

int Keypad__button(Keypad self, int row, int col)
{
	return self.buttons[row][col];
}

int Keypad__buttonPressed(Keypad self, int row, int col)
{
	return self.buttons[row][col] && !self.last_buttons[row][col];
}

int Keypad__buttonReleased(Keypad self, int row, int col)
{
	return !self.buttons[row][col] && self.last_buttons[row][col];
}

char Keypad__getChar(Keypad self)
{
	char chars[4][4] = {
		{'1', '2', '3', 'A'},
		{'4', '5', '6', 'B'},
		{'7', '8', '9', 'C'},
		{'*', '0', '#', 'D'}
	};

	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			if(self.buttons[i][j])
				return chars[i][j];

	return 0;
}

char Keypad__getCharPressed(Keypad self)
{
	char chars[4][4] = {
		{'1', '2', '3', 'A'},
		{'4', '5', '6', 'B'},
		{'7', '8', '9', 'C'},
		{'*', '0', '#', 'D'}
	};

	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			if(self.buttons[i][j] && !self.last_buttons[i][j])
				return chars[i][j];

	return 0;
}

char Keypad__getCharReleased(Keypad self)
{
	char chars[4][4] = {
		{'1', '2', '3', 'A'},
		{'4', '5', '6', 'B'},
		{'7', '8', '9', 'C'},
		{'*', '0', '#', 'D'}
	};

	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			if(!self.buttons[i][j] && self.last_buttons[i][j])
				return chars[i][j];

	return 0;
}

void Keypad__getMulti(Keypad self, int multi[4][4])
{
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			multi[i][j] = self.buttons[i][j];
}

void Keypad__getMultiPressed(Keypad self, int multiPressed[4][4])
{
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			multiPressed[i][j] = self.buttons[i][j] && !self.last_buttons[i][j];
}

void Keypad__getMultiReleased(Keypad self, int multiReleased[4][4])
{
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			multiReleased[i][j] = !self.buttons[i][j] && self.last_buttons[i][j];
}

int Keypad__buttonOR(Keypad self)
{
	int buttonOR = 0;
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			buttonOR |= self.buttons[i][j];

	return buttonOR;
}

int Keypad__prevButtonOR(Keypad self)
{
	int prevButtonOR = 0;
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			prevButtonOR |= self.last_buttons[i][j];

	return prevButtonOR;
}

int main(){

#ifdef lab_keypad_single_key

	SevenSegDisplay sevenSegDisplay = SevenSegDisplay__construct(SEG_gpio, DIN_pin, CS_pin, CLK_pin);
	if(SevenSegDisplay__init(sevenSegDisplay) != 0)    return -1;

	Keypad keypad = Keypad__construct(ROW_gpio, ROW_pin, COL_gpio, COL_pin);
	if(Keypad__init(keypad) != 0)    return -1;

	while(1){
		keypad = Keypad__refresh(keypad);
		char c = Keypad__getChar(keypad);

		if(c >= '0' && c <= '9')
			SevenSegDisplay__print(sevenSegDisplay, c-'0');
		else if(c >= 'A' && c <= 'D')
			SevenSegDisplay__print(sevenSegDisplay, c-'A'+10);
		else if(c == '*')
			SevenSegDisplay__print(sevenSegDisplay, 15);
		else if(c == '#')
			SevenSegDisplay__print(sevenSegDisplay, 14);
		else
			SevenSegDisplay__print(sevenSegDisplay, -1);
	}

#endif

#ifdef lab_keypad_calculator_2_operands

	SevenSegDisplay sevenSegDisplay = SevenSegDisplay__construct(SEG_gpio, DIN_pin, CS_pin, CLK_pin);
	if(SevenSegDisplay__init(sevenSegDisplay) != 0)    return -1;

	Keypad keypad = Keypad__construct(ROW_gpio, ROW_pin, COL_gpio, COL_pin);
	if(Keypad__init(keypad) != 0)    return -1;

	SevenSegDisplay__print(sevenSegDisplay, 0);

	while(1)
	{
		int operand1 = 0;
		int operand2 = 0;
		char operator = ' ';

		int clearFlag = 0;
		// Get operand1
		while(1)
		{
			keypad = Keypad__refresh(keypad);
			char c = Keypad__getCharPressed(keypad);
			if(c >= '0' && c <= '9' && num_digits(operand1) <= 2)
			{
				operand1 = operand1 * 10 + c - '0';
				SevenSegDisplay__print(sevenSegDisplay, operand1);
			}
			else if(c == 'A')
			{
				operator = '+';
				break;
			}
			else if(c == 'B')
			{
				operator = '-';
				break;
			}
			else if(c == 'C')
			{
				operator = '*';
				break;
			}
			else if(c == 'D')
			{
				operator = '/';
				break;
			}
			else if(c == '#')
			{
				clearFlag = 1;
				break;
			}
		}
	
		if(clearFlag)
		{
			SevenSegDisplay__print(sevenSegDisplay, 0);
			continue;
		}

		// Get operand2
		while(1)
		{
			keypad = Keypad__refresh(keypad);
			char c = Keypad__getCharPressed(keypad);
			if(c >= '0' && c <= '9' && num_digits(operand2) <= 2)
			{
				operand2 = operand2 * 10 + c - '0';
				SevenSegDisplay__print(sevenSegDisplay, operand2);
			}
			else if(c == '#')
			{
				clearFlag = 1;
				break;
			}
			else if(c == '*')
				break;
		}

		if(clearFlag)
		{
			SevenSegDisplay__print(sevenSegDisplay, 0);
			continue;
		}

		// Calculate result
		int result = 0;
		switch(operator)
		{
			case '+':
				result = operand1 + operand2;
				break;
			case '-':
				result = operand1 - operand2;
				break;
			case '*':
				result = operand1 * operand2;
				break;
			case '/':
				result = operand1 / operand2;
				break;
		}

		SevenSegDisplay__print(sevenSegDisplay, result);
	}

#endif

#ifdef lab_keypad_calculator_multi_operands

	SevenSegDisplay sevenSegDisplay = SevenSegDisplay__construct(SEG_gpio, DIN_pin, CS_pin, CLK_pin);
	if(SevenSegDisplay__init(sevenSegDisplay) != 0)    return -1;

	Keypad keypad = Keypad__construct(ROW_gpio, ROW_pin, COL_gpio, COL_pin);
	if(Keypad__init(keypad) != 0)    return -1;

	SevenSegDisplay__print(sevenSegDisplay, 0);

	while(1)
	{
		// Initialize parameters
		int input[100] = {0};
		int input_index = 0;
		int resetPressed = 0;

		// Get input
		while(1)
		{
			keypad = Keypad__refresh(keypad);
			char c = Keypad__getCharPressed(keypad);

			if(c >= '0' && c <= '9')
			{
				if(input[input_index] < 0) // if previous input is operator
					input_index++;
				input[input_index] = input[input_index] * 10 + c - '0';
				SevenSegDisplay__print(sevenSegDisplay, input[input_index]);
			}
			else if(c == 'A') // plus
			{
				input_index++;
				input[input_index] = -('+');
				SevenSegDisplay__print(sevenSegDisplay, 0);
			}
			else if(c == 'B') // minus
			{
				input_index++;
				input[input_index] = -('-');
				SevenSegDisplay__print(sevenSegDisplay, 0);
			}
			else if(c == 'C') // multiply
			{
				input_index++;
				input[input_index] = -('*');
				SevenSegDisplay__print(sevenSegDisplay, 0);
			}
			else if(c == 'D') // divide
			{
				input_index++;
				input[input_index] = -('/');
				SevenSegDisplay__print(sevenSegDisplay, 0);
			}
			else if(c == '*') // equal
				break;
			else if(c == '#') // reset
			{
				resetPressed = 1;
				break;
			}
		}

		if(resetPressed)
		{
			SevenSegDisplay__print(sevenSegDisplay, 0);
			continue;
		}


		// Convert input to postfix
		int postfix[100] = {0};
		int postfix_index = 0;
		int stack[100] = {0};
		int stack_index = 0;

		// push '#'
		stack[stack_index] = -('#');
		stack_index++;

		for(int i = 0; i <= input_index; i++)
		{
			if(input[i] >= 0) // number
			{
				postfix[postfix_index] = input[i];
				postfix_index++;
			}
			else // operator
			{
				while((input[i] == -('+') || input[i] == -('-')) && 
					  (stack[stack_index - 1] == -('*') || stack[stack_index - 1] == -('/')))
				{
					postfix[postfix_index] = stack[stack_index - 1];
					postfix_index++;
					stack_index--;
				}
				stack[stack_index] = input[i];
				stack_index++;
			}
		}
		
		// empty operators in stack
		while(stack[stack_index - 1] != -('#'))
		{
			postfix[postfix_index] = stack[stack_index - 1];
			postfix_index++;
			stack_index--;
		}

		// Calculate postfix
		int evalStack[100] = {0};
		int evalStack_index = 0;
		int expressionErrorFlag = 0;
		for(int i = 0; i < postfix_index; i++)
		{
			if(postfix[i] >= 0) // operand
			{
				evalStack[evalStack_index] = postfix[i];
				evalStack_index++;
			}
			else // operator
			{
				if(evalStack_index < 2)
				{
					expressionErrorFlag = 1;
					break;
				}
				else if(postfix[i] == -('+'))
				{
					evalStack[evalStack_index - 2] = evalStack[evalStack_index - 2] + 
					                                 evalStack[evalStack_index - 1];
					evalStack_index--;
				}
				else if(postfix[i] == -('-'))
				{
					evalStack[evalStack_index - 2] = evalStack[evalStack_index - 2] -
					                                 evalStack[evalStack_index - 1];
					evalStack_index--;
				}
				else if(postfix[i] == -('*'))
				{
					evalStack[evalStack_index - 2] = evalStack[evalStack_index - 2] *
					                                 evalStack[evalStack_index - 1];
					evalStack_index--;
				}
				else if(postfix[i] == -('/'))
				{
					evalStack[evalStack_index - 2] = evalStack[evalStack_index - 2] /
					                                 evalStack[evalStack_index - 1];
					evalStack_index--;
				}
			}
		}

		if(expressionErrorFlag == 1)
		{
			SevenSegDisplay__print(sevenSegDisplay, -1);
		}
		else
		{
			SevenSegDisplay__print(sevenSegDisplay, evalStack[0]);
		}
	}


#endif

#ifdef lab_keypad_multi_key

	SevenSegDisplay sevenSegDisplay = SevenSegDisplay__construct(SEG_gpio, DIN_pin, CS_pin, CLK_pin);
	SevenSegDisplay__init(sevenSegDisplay);

	Keypad keypadObj = Keypad__construct(ROW_gpio, ROW_pin, COL_gpio, COL_pin);
	Keypad__init(keypadObj);

	int currentDisplay = 0;
	SevenSegDisplay__print(sevenSegDisplay, currentDisplay);
	while(1)
	{
		int multiPressed[4][4] = {0};

		while(1)
		{
			keypadObj = Keypad__refresh(keypadObj);
			for(int i = 0; i < 4; i++)
				for(int j = 0; j < 4; j++)
					multiPressed[i][j] |= keypadObj.buttons[i][j];

			if(Keypad__buttonOR(keypadObj) == 0 && Keypad__prevButtonOR(keypadObj) == 0)
				break;
		}

		int result = 0;
		int hasPressed = 0;
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				if(multiPressed[i][j] == 1)
				{
					hasPressed = 1;
					result += keypad[i][j];
				}
			}
		}

		if(result == 14)
		{
			currentDisplay = 0;
			SevenSegDisplay__print(sevenSegDisplay, currentDisplay);
			continue;
		}

		if(num_digits(result) + num_digits(currentDisplay) <= 8 && hasPressed == 1)
		{
			currentDisplay = pow(10, num_digits(result)) * currentDisplay + result;
			SevenSegDisplay__print(sevenSegDisplay, currentDisplay);
		}
	}

#endif

	while(1){}

	return 0;
}
