/*
 * buttons_n_leds_game.c
 *
 *  Created on: May 21, 2024
 *      Author: User
 */
#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "uart.h"
#include "gpio.h"
#include "buttons_n_leds_game.h"

GPIO_PinState buttonState1;
GPIO_PinState buttonState0;

uint32_t counter0;
uint32_t counter1;
uint32_t counter_idle;
uint32_t counter_both;
uint32_t counter_toggle;

void buttons_n_leds_game(void)
{
	HAL_Init();

		usart1_rxtx_init_polling();

		pe4_k0_init();
		pa6_d2_init();

		pe3_k1_init();
		pa7_d3_init();

		while(1)
		{
				if(counter_toggle == 0)
				{
					HAL_GPIO_WritePin(D2_PORT, D2, GPIO_PIN_SET);
					HAL_GPIO_WritePin(D3_PORT, D3, GPIO_PIN_RESET);
					HAL_Delay(DELAY);
				}

				HAL_GPIO_TogglePin(D2_PORT, D2);
				HAL_GPIO_TogglePin(D3_PORT, D3);

				printf("Idle both, LEDs toggling %ld\n", counter_idle++);
				HAL_Delay(DELAY);

				counter_toggle++;
				buttonState0 = HAL_GPIO_ReadPin(K0_PORT, K0);
				buttonState1 = HAL_GPIO_ReadPin(K1_PORT, K1);

			while(buttonState0 && !buttonState1)
			{
				if(counter1 == 0)
				{
					HAL_GPIO_WritePin(D3_PORT, D3, GPIO_PIN_SET);
				}

				HAL_GPIO_TogglePin(D2_PORT, D2);

				printf("K1 pressed && D2 toggling = %ld\n", counter1++);
				HAL_Delay(DELAY);

				buttonState1 = HAL_GPIO_ReadPin(K1_PORT, K1);
				counter_toggle = 0;
			}

			counter1 = 0;

			while(!buttonState0 && buttonState1)
			{
				if(counter1 == 0)
				{
					HAL_GPIO_WritePin(D2_PORT, D2, GPIO_PIN_SET);
				}

				HAL_GPIO_TogglePin(D3_PORT, D3);
				printf("K0 pressed and D3 toggling = %ld\n", counter0++);

				HAL_Delay(DELAY);
				buttonState0 = HAL_GPIO_ReadPin(K0_PORT, K0);
				counter_toggle = 0;
			}

			counter0 = 0;

			while(!buttonState0 && !buttonState1)
			{
				if(counter_both == 0)
				{
					HAL_GPIO_WritePin(D3_PORT, D3, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(D2_PORT, D2, GPIO_PIN_RESET);
				}

				HAL_GPIO_TogglePin(D3_PORT, D3);
				HAL_GPIO_TogglePin(D2_PORT, D2);

				printf("K0 & K1 pressed && D2 & D3 toggling = %ld\n", counter_both++);

				HAL_Delay(DELAY);
				buttonState0 = HAL_GPIO_ReadPin(K0_PORT, K0);
				buttonState1 = HAL_GPIO_ReadPin(K1_PORT, K1);
				counter_toggle = 0;
			}

			counter_both = 0;
		}
}
