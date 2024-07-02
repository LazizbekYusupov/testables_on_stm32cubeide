/*
 * gpio_exti.c
 *
 *  Created on: May 24, 2024
 *      Author: User
 */

//led toggles slower, after interrupt i.e. one click,
//it toggles super-fast several tens of times
//(to be defined), sending messages to
//uart about interrupted button press
//and returns control to the function
//to again blinking casually

//repeat it with potentiometer and uart connection and diode.
//try to go further with the interrupt

#include <stdio.h>
#include <string.h>
#include "stm32f4xx_hal.h"
#include "gpio.h"
#include "uart.h"
#include "adc.h"
#include "gpio_exti.h"

static void gpio_exti_k0_init(void);
static void gpio_exti_k1_init(void);
static void gpio_exti_init(void);

void gpio_exti_game(void)
{
	HAL_Init();

	//led no difference from ordinary led, load gpio lib.
	pa6_d2_init();
	pa7_d3_init();

	usart1_rxtx_init_polling();

	gpio_exti_k0_init();
	gpio_exti_k1_init();

	gpio_exti_init();

	while(1)
	{
//		HAL_GPIO_TogglePin(D3_PORT, D3);
//		HAL_Delay(DELAY_EXTI/10);
	}
}

//initialize led and button specially for interrupt
//button diff = mode = it_rising!!!!!!!!!!!!!
	//enable clock to rcc
	//init struct
static void gpio_exti_k0_init(void)
{
	GPIO_InitTypeDef	GPIO_InitStruct = {0};

	__HAL_RCC_GPIOE_CLK_ENABLE();

	//#define K0_PORT GPIOE
	//#define K0 GPIO_PIN_4
	//#define D2_PORT GPIOA
	//#define D2 GPIO_PIN_6

	GPIO_InitStruct.Pin   = K0;
	GPIO_InitStruct.Mode  = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull  = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init (K0_PORT, &GPIO_InitStruct);
}

static void gpio_exti_k1_init(void)
{
	GPIO_InitTypeDef	GPIO_InitStruct = {0};

	__HAL_RCC_GPIOE_CLK_ENABLE();

	//#define K0_PORT GPIOE
	//#define K0 GPIO_PIN_4
	//#define D2_PORT GPIOA
	//#define D2 GPIO_PIN_6

	GPIO_InitStruct.Pin   = K1;
	GPIO_InitStruct.Mode  = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull  = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init (K1_PORT, &GPIO_InitStruct);
}

//************************************
//initialize interrupt****************
static void gpio_exti_init(void)
{
	//set interrupt priority for exact pin
	 HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0);
	//enable for that exact exti line
	 HAL_NVIC_EnableIRQ(EXTI4_IRQn);
	//EXTI4_IRQn = 6,

	//set interrupt priority for exact pin
	HAL_NVIC_SetPriority(EXTI3_IRQn, 0, 0);
	//enable for that exact exti line
	HAL_NVIC_EnableIRQ(EXTI3_IRQn);
	//EXTI3_IRQn = 9,

}

//implement interrupt nvic function, call callback func inside
void EXTI4_IRQHandler(void)
{
	 HAL_GPIO_EXTI_IRQHandler(K0);
}

void EXTI3_IRQHandler(void)
{
	 HAL_GPIO_EXTI_IRQHandler(K1);
}

//implement interrupt callback function,  EXTI0_IRQHandler
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	static uint32_t toggle = 0;

	if(GPIO_Pin == K0)
	{
		HAL_GPIO_TogglePin(D2_PORT, D2);
		printf("Button K0 pressed! %ld\n\r", toggle++);
	}

	if(GPIO_Pin == K1)
	{
		HAL_GPIO_TogglePin(D3_PORT, D3);
		printf("Button K1 pressed! %ld\n\r", toggle++);
	}

}








































