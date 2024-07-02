/*
 * gpio.c
 *
 *  Created on: May 21, 2024
 *      Author: User
 */

#include "stm32f4xx_hal.h"
#include "gpio.h"

void pe4_k0_init(void)
{
	GPIO_InitTypeDef	GPIO_InitStruct = {0};

	__HAL_RCC_GPIOE_CLK_ENABLE();

	//#define K0_PORT GPIOE
	//#define K0 GPIO_PIN_4
	//#define D2_PORT GPIOA
	//#define D2 GPIO_PIN_6

	GPIO_InitStruct.Pin   = K0;
	GPIO_InitStruct.Mode  = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull  = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init (K0_PORT, &GPIO_InitStruct);
}

void pe3_k1_init(void)
{
	GPIO_InitTypeDef	GPIO_InitStruct = {0};

	__HAL_RCC_GPIOE_CLK_ENABLE();

	//#define K0_PORT GPIOE
	//#define K0 GPIO_PIN_4
	//#define D2_PORT GPIOA
	//#define D2 GPIO_PIN_6

	GPIO_InitStruct.Pin   = K1;
	GPIO_InitStruct.Mode  = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull  = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(K1_PORT, &GPIO_InitStruct);
}

void pa6_d2_init(void)
{
	GPIO_InitTypeDef	GPIO_InitStruct = {0};

	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitStruct.Pin   = D2;
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull  = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(D2_PORT, &GPIO_InitStruct);
}

void pa7_d3_init(void)
{
	GPIO_InitTypeDef	GPIO_InitStruct = {0};

	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitStruct.Pin   = D3;
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull  = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(D3_PORT, &GPIO_InitStruct);
}
