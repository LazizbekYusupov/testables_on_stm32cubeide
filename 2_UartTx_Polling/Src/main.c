#include "stm32f4xx_hal.h"

void uart_init(void);

UART_HandleTypeDef huart1;
char message[20] = "Hello from STM32\r\n";

int main()
{
	HAL_Init();
	uart_init();

	while(1)
	{
		HAL_UART_Transmit(&huart1, (uint8_t*)message, 20, 10000);
		HAL_Delay(1000);
	}
}

void SysTick_Handler(void)
{
	HAL_IncTick();
}

void uart_init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	//Enable UART pins clock access
	__HAL_RCC_GPIOA_CLK_ENABLE();

	//Enable UART module clock access
	__HAL_RCC_USART1_CLK_ENABLE();

	//USART1_TX PA9 AF7
	//USART1_RX PA10 AF7
	//Configure pins to act as alternate function pins (UART)

	GPIO_InitStruct.Pin = GPIO_PIN_9 | GPIO_PIN_10;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	//Configure UART module
	huart1.Instance = USART1;
	huart1.Init.BaudRate = 115200;
	huart1.Init.WordLength = UART_WORDLENGTH_8B;
	huart1.Init.StopBits = UART_STOPBITS_1;
	huart1.Init.Parity = UART_PARITY_NONE;
	huart1.Init.Mode = UART_MODE_TX_RX;
	huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart1.Init.OverSampling = UART_OVERSAMPLING_16;

	HAL_UART_Init(&huart1);
}










