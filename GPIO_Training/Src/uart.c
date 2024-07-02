/*
 * uart.c
 *
 *  Created on: May 21, 2024
 *      Author: User
 */
#include "stm32f4xx_hal.h"
#include "uart.h"
#include <stdio.h>

//extern UART_HandleTypeDef uart_handle1;
UART_HandleTypeDef uart_handle1;

int __io_putchar(int ch)
{
	HAL_UART_Transmit(&uart_handle1, (uint8_t*)&ch, 1, 10);
	return ch;
}

void usart1_rxtx_init_polling(void)
{
	//Enable clock for gpio
	__HAL_RCC_GPIOA_CLK_ENABLE();

	//create structure for gpio
	GPIO_InitTypeDef GPIO_InitStructUART = {0};

	//fill it in with uart1 configuration
	GPIO_InitStructUART.Pin = TX1_PIN_PA9 | RX1_PIN_PA10; //just pins
	GPIO_InitStructUART.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStructUART.Pull = GPIO_NOPULL;
	GPIO_InitStructUART.Alternate = GPIO_AF7_USART1;
	GPIO_InitStructUART.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

	HAL_GPIO_Init(UART1_PORT, &GPIO_InitStructUART);

	//enable clock for usart1 (special func for that)
	__HAL_RCC_USART1_CLK_ENABLE();

	//create structure (globally) for that
	//fill in it with required parameters
	uart_handle1.Instance = USART1;
	uart_handle1.Init.BaudRate = 115200;
	uart_handle1.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle1.Init.StopBits = UART_STOPBITS_1;
	uart_handle1.Init.Parity = UART_PARITY_NONE;
	uart_handle1.Init.Mode = UART_MODE_TX_RX;
	uart_handle1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle1.Init.OverSampling = UART_OVERSAMPLING_16;

	HAL_UART_Init (&uart_handle1);
}

//Interrupt uart rx tx configuration initialization
void usart1_rxtx_init_it(void)
{
	//Enable clock for gpio
	__HAL_RCC_GPIOA_CLK_ENABLE();

	//create structure for gpio
	GPIO_InitTypeDef GPIO_InitStructUART = {0};

	//fill it in with uart1 configuration
	GPIO_InitStructUART.Pin = TX1_PIN_PA9 | RX1_PIN_PA10;
	GPIO_InitStructUART.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStructUART.Pull = GPIO_NOPULL;
	GPIO_InitStructUART.Alternate = GPIO_AF7_USART1;
	GPIO_InitStructUART.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

	HAL_GPIO_Init (UART1_PORT, &GPIO_InitStructUART);

	//enable clock for usart1 (special func for that)
	__HAL_RCC_USART1_CLK_ENABLE();

	//create structure (globally) for that
	//fill in it with required parameters
	uart_handle1.Instance = USART1;
	uart_handle1.Init.BaudRate = 115200;
	uart_handle1.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle1.Init.StopBits = UART_STOPBITS_1;
	uart_handle1.Init.Parity = UART_PARITY_NONE;
	uart_handle1.Init.Mode = UART_MODE_TX_RX;
	uart_handle1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle1.Init.OverSampling = UART_OVERSAMPLING_16;

	HAL_UART_Init (&uart_handle1);

	HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(USART1_IRQn);
}

void USART1_IRQHandler(void)
{
	HAL_UART_IRQHandler(&uart_handle1);
}















































