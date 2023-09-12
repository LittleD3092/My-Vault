#include "stm32l476xx.h"
#include "fpu.h"

void FPU__enable()
{
    SCB->CPACR |= (0xF << 20);
	__DSB();
	__ISB();
}