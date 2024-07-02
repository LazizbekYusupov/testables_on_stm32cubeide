#include "stm32f4xx_hal.h"

int main()
{
	HAL_Init();

	while(1)
	{

	}
}

void SysTick_Handler(void)
{
	HAL_IncTick();
}
