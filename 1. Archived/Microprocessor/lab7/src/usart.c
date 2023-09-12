#include "usart.h"
#include <string.h>

void USARTSetBaudRate(USART_TypeDef *usart, int clk, int baudrate){
	clk = clk * 1000000;
	usart->BRR = (clk + baudrate / 2) / baudrate;
}

void USARTSetWordLength(USART_TypeDef *usart, int bits){
	if(bits == 8){
		usart->CR1 &= ~USART_CR1_M1;
		usart->CR1 &= ~USART_CR1_M0;
	}
	else if(bits == 9){
		usart->CR1 &= ~USART_CR1_M1;
		usart->CR1 |= USART_CR1_M0;
	}
	else if(bits == 7){
		usart->CR1 |= USART_CR1_M1;
		usart->CR1 &= ~USART_CR1_M0;
	}
}

void USARTSetStopBit(USART_TypeDef *usart, int bits){
	// 0 -> 1
	// 1 -> 0.5
	// 2 -> 2
	// 3 -> 1.5
	usart->CR2 &= ~USART_CR2_STOP_Msk;
	usart->CR2 |= bits << USART_CR2_STOP_Pos;
}

void USARTEnableRXTX(USART_TypeDef *usart, int rx, int tx){
	usart->CR1 &= ~USART_CR1_RE_Msk;
	usart->CR1 |= rx << USART_CR1_RE_Pos;
	usart->CR1 &= ~USART_CR1_TE_Msk;
	usart->CR1 |= tx << USART_CR1_TE_Pos;
}

void USARTEnable(USART_TypeDef *usart){
	usart->CR1 |= USART_CR1_UE;
}

int USARTGetFlagStatus(USART_TypeDef *usart, int flag){
	return usart->ISR & flag;
}

void USARTSendData(USART_TypeDef *usart, int data){
	while(!USARTGetFlagStatus(usart, USART_ISR_TXE));
	usart->TDR = data & 0x1FF;   // For 9 bit
	while(!USARTGetFlagStatus(usart, USART_ISR_TC));
}

int USARTGetData(USART_TypeDef *usart){
	while(!USARTGetFlagStatus(usart, USART_ISR_RXNE));
	return usart->RDR & 0x1FF;   // For 9 bit
}

void USARTPrintString(USART_TypeDef *usart, const char *ptr){
	while(*ptr){
		USARTSendData(usart, *(ptr++));
	}
}

int USARTGetLine(USART_TypeDef *usart, char *ptr, int maxx){
	char x;
	for(int i=0;i<maxx-1;i++){
		x = USARTGetData(usart);
		if(i==0 && x==27){
			char first = USARTGetData(usart);
			char second = USARTGetData(usart);
			if(first=='[' && second=='A'){
				USARTPrintString(usart, ptr);
				i = strlen(ptr)-1;
			}
			else{
				i--;
			}
		}
		else if(x==27){
			char first = USARTGetData(usart);
			char second = USARTGetData(usart);
			i--;
			continue;
		}
		else if(x == '\n' || x == '\r'){
			ptr[i] = 0;
			USARTPrintString(usart, "\r\n");
			return i;
		}
		else if(x == 127){
			if(i){
				i--;
				USARTSendData(usart, x);
			}
			i--;
		}
		else{
			USARTSendData(usart, x);
			ptr[i] = x;
		}
	}
	USARTPrintString(USART1, "Buffer Exceeded\r\n");
	return -1;
}
