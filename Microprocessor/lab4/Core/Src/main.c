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

int main(){

#ifdef lab_keypad_single_key

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

	while(1){
		int input = 0;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(check_keypad_input_one(ROW_gpio, COL_gpio, ROW_pin, COL_pin, i, j)){
					input = 1;
					display_number(SEG_gpio, DIN_pin, CS_pin, CLK_pin, keypad[i][j], num_digits(keypad[i][j]));
				}
			}
		}
		if(input == 0){
			display_number(SEG_gpio, DIN_pin, CS_pin, CLK_pin, 0, 0);
		}
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

	display_number(SEG_gpio, DIN_pin, CS_pin, CLK_pin, 0, 0);
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
					   keypad[i][j] >= 0 && keypad[i][j] <= 9){
						hasInput = 1;
						operand1 = operand1 * 10 + keypad[i][j];
						break;
					}
					else if(check_keypad_input_one(ROW_gpio, COL_gpio, ROW_pin, COL_pin, i, j) &&
							keypad[i][j] == 10){
						hasInput = 1;
						doneFlag = 1;
						operator = '+';
						break;
					}
					else if(check_keypad_input_one(ROW_gpio, COL_gpio, ROW_pin, COL_pin, i, j) &&
							keypad[i][j] == 11){
						hasInput = 1;
						doneFlag = 1;
						operator = '-';
						break;
					}
					else if(check_keypad_input_one(ROW_gpio, COL_gpio, ROW_pin, COL_pin, i, j) &&
							keypad[i][j] == 12){
						hasInput = 1;
						doneFlag = 1;
						operator = '*';
						break;
					}
					else if(check_keypad_input_one(ROW_gpio, COL_gpio, ROW_pin, COL_pin, i, j) &&
							keypad[i][j] == 13){
						hasInput = 1;
						doneFlag = 1;
						operator = '/';
						break;
					}
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
					   keypad[i][j] >= 0 && keypad[i][j] <= 9){
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

	while(1){}

	return 0;
}
