/*
 * uart.h
 *
 *  Created on: May 21, 2024
 *      Author: User
 */

//1) buttons_n_leds_game();

#ifndef UART_H_
#define UART_H_

//uart defines
#define UART1_PORT GPIOA
#define TX1_PIN_PA9 GPIO_PIN_9
#define RX1_PIN_PA10 GPIO_PIN_10

void usart1_rxtx_init_polling(void);

void usart1_rxtx_init_it(void);

#endif /* UART_H_ */

//
////GPIO Training
//#include <stdio.h>
//#include "stm32f4xx_hal.h"
//#include "uart.h"
//#include "gpio.h"
//#include "buttons_n_leds_game.h"
//#include "adc.h"
//#include "gpio_exti.h"
//
////coding plans:
////-read a bit of a book, until the end of the chapter
////-check if | operator possible to use with the buttons and leds game in gpio.c file
////do practice of uart interrupt, get the very deep idea - didn't get the nature, ask the Mentor
//
//ADC_HandleTypeDef handle_adc;//this is for adc library not to cry
////uart polling vars
//UART_HandleTypeDef uart_handle1;
//uint8_t message[50] = "Button K1 is pressed\r\n";
//uint32_t counter;
//
//uint32_t rx_counter;
//uint32_t tx_counter;
//
////text to send - 0x55 0x41 0x52 0x54
//uint8_t receive[10];
//
//void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
//{
//	tx_counter++;
//}
//
//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
//{
//	rx_counter++;
//}
//
//int main()
//{
//	HAL_Init();
//
//	//init uart
//	usart1_rxtx_init_it();
//
//	//hal transmit
//	//hal receive
//	HAL_UART_Receive_IT(&uart_handle1, receive, 10);
//
//	while(1)
//	{
//		//HAL_UART_Transmit(&uart_handle1, message, 50, 10);
//		//HAL_UART_Receive(&uart_handle1, receive, 10, 10);
//
//		//counter++;
//	}
//
//	return 0;
//}
//
//void SysTick_Handler(void)
//{
//	HAL_IncTick();
//}
//
