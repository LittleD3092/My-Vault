#include "stm32l476xx.h"
#include "helper_functions.h"
#include "7seg.h"
#include "keypad.h"

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
#define lab_keypad_single_key
// #define lab_keypad_calculator_2_operands
// #define lab_keypad_calculator_multi_operands
// #define lab_keypad_multi_key

class SevenSegDisplay
{
public:
    SevenSegDisplay(GPIO_TypeDef *gpio, int din_pin, int cs_pin, int clk_pin)
	{
		this->gpio = gpio;
		this->din_pin = din_pin;
		this->cs_pin = cs_pin;
		this->clk_pin = clk_pin;
	}

	int init()
	{
		if(init_7seg(this->gpio, this->din_pin, this->cs_pin, this->clk_pin) != 0){
			// Fail to init 7seg
			return -1;
		}

		// Set Decode Mode to Code B decode mode
		send_7seg(this->gpio, this->din_pin, this->cs_pin, this->clk_pin, SEG_ADDRESS_DECODE_MODE, 0xFF);
		// Set Scan Limit to all digits
		send_7seg(this->gpio, this->din_pin, this->cs_pin, this->clk_pin, SEG_ADDRESS_SCAN_LIMIT, 0x07);
		// Wakeup 7seg
		send_7seg(this->gpio, this->din_pin, this->cs_pin, this->clk_pin, SEG_ADDRESS_SHUTDOWN, 0x01);
	}

	// use only if 7seg is in decode mode and only if scan limit is set to 7
	// print data to the 7seg display
	// return -1 if overflow
	int print(int number){
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
			send_7seg(this->gpio, this->din_pin, this->cs_pin, this->clk_pin, SEG_ADDRESS_DIGIT_0+current_digit, SEG_DATA_DECODE_0+digit);
			number /= 10;
			current_digit++;
		}

		// print negative sign
		if(negative)
		{
			send_7seg(gpio, this->din_pin, this->cs_pin, this->clk_pin, SEG_ADDRESS_DIGIT_0+current_digit, SEG_DATA_DECODE_DASH);
			current_digit++;
		}

		// clear remaining digits
		while(current_digit <= 7)
		{
			send_7seg(gpio, this->din_pin, this->cs_pin, this->clk_pin, SEG_ADDRESS_DIGIT_0+current_digit, SEG_DATA_DECODE_BLANK);
			current_digit++;
		}

		return 0;
	}

private:
    GPIO_TypeDef *gpio;
	int din_pin;
	int cs_pin;
	int clk_pin;
};

class Keypad
{
public:
    Keypad(GPIO_TypeDef *row_gpio, int row_pin, GPIO_TypeDef *col_gpio, int col_pin)
	{
		this->row_gpio = row_gpio;
		this->row_pin = row_pin;
		this->col_gpio = col_gpio;
		this->col_pin = col_pin;

		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
			{
				this->buttons[i][j] = 0;
				this->last_buttons[i][j] = 0;
			}
	}

	int init()
	{
		if(init_keypad(this->row_gpio, this->col_gpio, this->row_pin, this->col_pin) != 0){
			// Fail to init keypad
			return -1;
		}
	}

	void refresh()
	{
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				this->last_buttons[i][j] = this->buttons[i][j];
				this->buttons[i][j] = check_keypad_input_one(this->row_gpio, this->col_gpio, this->row_pin, this->col_pin, i, j);
			}
		}
	}

	int button(int row, int col)
	{
		return this->buttons[row][col];
	}

	int buttonPressed(int row, int col)
	{
		return this->buttons[row][col] && !this->last_buttons[row][col];
	}

	int buttonReleased(int row, int col)
	{
		return !this->buttons[row][col] && this->last_buttons[row][col];
	}

	char getChar()
	{
		char chars[4][4] = {
			{'1', '2', '3', 'A'},
			{'4', '5', '6', 'B'},
			{'7', '8', '9', 'C'},
			{'*', '0', '#', 'D'}
		};

		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
				if(this->button(i, j))
					return chars[i][j];

		return 0;
	}

private:
    GPIO_TypeDef *row_gpio;
	int row_pin;
	GPIO_TypeDef *col_gpio;
	int col_pin;

	int buttons[4][4];
	int last_buttons[4][4];
};

int main(){

#ifdef lab_keypad_single_key

	SevenSegDisplay sevenSegDisplay(SEG_gpio, DIN_pin, CS_pin, CLK_pin);
	if(sevenSegDisplay.init() != 0)    return -1;

	Keypad keypad(ROW_gpio, ROW_pin, COL_gpio, COL_pin);
	if(keypad.init() != 0)    return -1;

	while(1){
		keypad.refresh();
		char c = keypad.getChar();

		if(c >= '0' && c <= '9')
			sevenSegDisplay.print(c-'0');
		else if(c >= 'A' && c <= 'D')
			sevenSegDisplay.print(c-'A'+10);
		else if(c == '*')
			sevenSegDisplay.print(15);
		else if(c == '#')
			sevenSegDisplay.print(14);
		else
			sevenSegDisplay.print(0);
	}

#endif

#ifdef lab_keypad_calculator_2_operands

	if(init_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin) != 0){
		// Fail to init 7seg
		return -1;
	}

	// Set Decode Mode to Code B decode mode
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_DECODE_MODE, 0xFF);
	// Set Scan Limit to all digits
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_SCAN_LIMIT, 0x07);
	// Wakeup 7seg
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_SHUTDOWN, 0x01);

	if(init_keypad(ROW_gpio, COL_gpio, ROW_pin, COL_pin) != 0){
		// Fail to init keypad
		return -1;
	}

	display_number(SEG_gpio, DIN_pin, CS_pin, CLK_pin, 0, num_digits(0));
	while(1)
	{
		int operand1 = 0;
		int operand2 = 0;
		char operator = ' ';

		int doneFlag = 0;
		int clearFlag = 0;
		// Get operand1
		while(1)
		{
			int hasInput = 0;
			for(int i=0;i<4;i++){
				for(int j=0;j<4;j++){
					if(check_keypad_input_one(ROW_gpio, COL_gpio, ROW_pin, COL_pin, i, j) &&
					   keypad[i][j] >= 0 && keypad[i][j] <= 9 && num_digits(operand1) <= 3){ // number
						hasInput = 1;
						operand1 = operand1 * 10 + keypad[i][j];
						break;
					}
					else if(check_keypad_input_one(ROW_gpio, COL_gpio, ROW_pin, COL_pin, i, j) &&
							keypad[i][j] == 10){ // plus
						hasInput = 1;
						doneFlag = 1;
						operator = '+';
						break;
					}
					else if(check_keypad_input_one(ROW_gpio, COL_gpio, ROW_pin, COL_pin, i, j) &&
							keypad[i][j] == 11){ // minus
						hasInput = 1;
						doneFlag = 1;
						operator = '-';
						break;
					}
					else if(check_keypad_input_one(ROW_gpio, COL_gpio, ROW_pin, COL_pin, i, j) &&
							keypad[i][j] == 12){ // multiply
						hasInput = 1;
						doneFlag = 1;
						operator = '*';
						break;
					}
					else if(check_keypad_input_one(ROW_gpio, COL_gpio, ROW_pin, COL_pin, i, j) &&
							keypad[i][j] == 13){ // divide
						hasInput = 1;
						doneFlag = 1;
						operator = '/';
						break;
					}
					else if(check_keypad_input_one(ROW_gpio, COL_gpio, ROW_pin, COL_pin, i, j) &&
							keypad[i][j] == 14){ // clear
						hasInput = 1;
						doneFlag = 1;
						clearFlag = 1;
						break;
					}
				}
			}
			if(hasInput == 1){
				display_number(SEG_gpio, DIN_pin, CS_pin, CLK_pin, operand1, num_digits(operand1));
			}
			if(doneFlag == 1){
				break;
			}
		}
		if(clearFlag == 1){
			continue;
		}

		doneFlag = 0;
		display_number(SEG_gpio, DIN_pin, CS_pin, CLK_pin, 0, num_digits(0));

		// Get operand2
		while(1)
		{
			int hasInput = 0;
			for(int i = 0; i < 4; i++)
			{
				for(int j = 0; j < 4; j++)
				{
					// case 1: a number is pressed
					if(check_keypad_input_one(ROW_gpio, COL_gpio, ROW_pin, COL_pin, i, j) &&
					   keypad[i][j] >= 0 && keypad[i][j] <= 9 && num_digits(operand2) <= 3){
						hasInput = 1;
						operand2 = operand2 * 10 + keypad[i][j];
						break;
					}
					// case 2: equal is pressed
					else if(check_keypad_input_one(ROW_gpio, COL_gpio, ROW_pin, COL_pin, i, j) &&
							keypad[i][j] == 15){
						hasInput = 1;
						doneFlag = 1;
						break;
					}
					// case 3: clear is pressed
					else if(check_keypad_input_one(ROW_gpio, COL_gpio, ROW_pin, COL_pin, i, j) &&
							keypad[i][j] == 14){
						hasInput = 1;
						doneFlag = 1;
						clearFlag = 1;
						break;
					}
				}
			}
			if(hasInput == 1){
				display_number(SEG_gpio, DIN_pin, CS_pin, CLK_pin, operand2, num_digits(operand2));
			}
			if(doneFlag == 1){
				break;
			}
		}
		if(clearFlag == 1){
			continue;
		}

		doneFlag = 0;
		
		// Calculate result and display
		int result = operand1;
		switch(operator){
			case '+':
				result += operand2;
				break;
			case '-':
				result -= operand2;
				break;
			case '*':
				result *= operand2;
				break;
			case '/':
				result /= operand2;
				break;
			default:
				break;
		}
		display_number(SEG_gpio, DIN_pin, CS_pin, CLK_pin, result, num_digits(result));
	}

#endif

#ifdef lab_keypad_calculator_multi_operands

	if(init_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin) != 0){
		// Fail to init 7seg
		return -1;
	}

	// Set Decode Mode to Code B decode mode
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_DECODE_MODE, 0xFF);
	// Set Scan Limit to all digits
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_SCAN_LIMIT, 0x07);
	// Wakeup 7seg
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_SHUTDOWN, 0x01);

	if(init_keypad(ROW_gpio, COL_gpio, ROW_pin, COL_pin) != 0){
		// Fail to init keypad
		return -1;
	}

	display_number(SEG_gpio, DIN_pin, CS_pin, CLK_pin, 0, num_digits(0));
	while(1)
	{
		// Initialize parameters
		int input[100] = {0};
		int input_index = 0;
		int resetPressed = 0;
		int equalPressed = 0;

		// Get input
		while(1)
		{
			int hasInput = 0;
			for(int i = 0; i < 4; i++)
			{
				for(int j = 0; j < 4; j++)
				{
					if(check_keypad_input_one(ROW_gpio, COL_gpio, ROW_pin, COL_pin, i, j) &&
					   keypad[i][j] >= 0 && keypad[i][j] <= 9)
					{
						hasInput = 1;
						input[input_index] = input[input_index] * 10 + keypad[i][j];
						break;
					}
					else if(check_keypad_input_one(ROW_gpio, COL_gpio, ROW_pin, COL_pin, i, j) &&
					        keypad[i][j] == 10) // plus
					{
						hasInput = 1;
						input_index++;
						input[input_index] = -('+');
						break;
					}
					else if(check_keypad_input_one(ROW_gpio, COL_gpio, ROW_pin, COL_pin, i, j) &&
					        keypad[i][j] == 11) // minus
					{
						hasInput = 1;
						input_index++;
						input[input_index] = -('-');
						break;
					}
					else if(check_keypad_input_one(ROW_gpio, COL_gpio, ROW_pin, COL_pin, i, j) &&
					        keypad[i][j] == 12) // multiply
					{
						hasInput = 1;
						input_index++;
						input[input_index] = -('*');
						break;
					}
					else if(check_keypad_input_one(ROW_gpio, COL_gpio, ROW_pin, COL_pin, i, j) &&
					        keypad[i][j] == 13) // divide
					{
						hasInput = 1;
						input_index++;
						input[input_index] = -('/');
						break;
					}
					else if(check_keypad_input_one(ROW_gpio, COL_gpio, ROW_pin, COL_pin, i, j) &&
					        keypad[i][j] == 14) // clear
					{
						hasInput = 1;
						resetPressed = 1;
						break;
					}
					else if(check_keypad_input_one(ROW_gpio, COL_gpio, ROW_pin, COL_pin, i, j) &&
					        keypad[i][j] == 15) // equal
					{
						hasInput = 1;
						equalPressed = 1;
						break;
					}
				}
			}
			if(hasInput == 1)
			{
				display_number(SEG_gpio, DIN_pin, CS_pin, CLK_pin, input[input_index], num_digits(input[input_index]));
			}
			if(resetPressed == 1 || equalPressed == 1)
			{
				break;
			}
		}

		if(resetPressed == 1)
		{
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
				while(input[i] == -('*') || input[i] == -('/') ||
				      (input[i] == -('+') || input[i] == -('-')) && 
					  (stack[stack_index - 1] == -('+') || stack[stack_index - 1] == -('-')))
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
			display_number(SEG_gpio, DIN_pin, CS_pin, CLK_pin, -1, num_digits(-1));
		}
		else
		{
			display_number(SEG_gpio, DIN_pin, CS_pin, CLK_pin, evalStack[0], num_digits(evalStack[0]));
		}
	}

#endif

#ifdef lab_keypad_multi_key

	if(init_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin) != 0){
		// Fail to init 7seg
		return -1;
	}

	// Set Decode Mode to Code B decode mode
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_DECODE_MODE, 0xFF);
	// Set Scan Limit to all digits
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_SCAN_LIMIT, 0x07);
	// Wakeup 7seg
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_SHUTDOWN, 0x01);

	if(init_keypad(ROW_gpio, COL_gpio, ROW_pin, COL_pin) != 0){
		// Fail to init keypad
		return -1;
	}

	int currentDisplay = 0;
	display_number(SEG_gpio, DIN_pin, CS_pin, CLK_pin, currentDisplay, num_digits(currentDisplay));
	while(1)
	{
		int input = check_keypad_input_multiple(ROW_gpio, COL_gpio, ROW_pin, COL_pin);
		if(input > 0) // has input
		{
			int result = 0;
			for(int i = 0; i < 4; i++)
			{
				for(int j = 0; j < 4; j++)
				{
					int pressed = 1 & (input >> (i * 4 + j));
					if(pressed == 1)
					{
						result += keypad[i][j];
					}
				}
			}

			if(result == 14)
			{
				currentDisplay = 0;
				display_number(SEG_gpio, DIN_pin, CS_pin, CLK_pin, currentDisplay, num_digits(currentDisplay));
				continue;
			}
			
			if(num_digits(result) + num_digits(currentDisplay) <= 8)
			{
				// currentDisplay = pow(10, num_digits(result)) * currentDisplay + result;
				for(int i = 0; i < num_digits(result); i++)
				{
					currentDisplay *= 10;
				}
				currentDisplay += result;

				display_number(SEG_gpio, DIN_pin, CS_pin, CLK_pin, currentDisplay, num_digits(currentDisplay));
			}
		}
	}

#endif

	while(1){}

	return 0;
}
