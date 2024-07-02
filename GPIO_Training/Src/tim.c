/*
 * tim.c
 *
 *  Created on: Jun 10, 2024
 *      Author: User
 */
#include "stm32f4xx_hal.h"
#include "tim.h"

TIM_HandleTypeDef tim_handle;

void tim_base_init(void)
{
	TIMx_CLK_ENABLE();

	//input 16 000 000
	//prescaler1 -> 16 000 000 / 1600
	//prescaler2 -> 10 000 / 10 000 = 1 Hz

	tim_handle.Instance = TIMx;
	tim_handle.Init.Prescaler = 1600 - 1;
	tim_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	tim_handle.Init.Period = 10000 - 1;
	tim_handle.Init.ClockDivision = 0;
	tim_handle.Init.RepetitionCounter = 0;
	tim_handle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

	HAL_TIM_Base_Init(&tim_handle);

/*
 *  Interrupt shit start 1
 */
	//Priority shit
	HAL_NVIC_SetPriority(TIMx_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(TIMx_IRQn);
/*
*  Interrupt shit end 1
*/

/*
*  Interrupt shit start 2
*/
	//Ignite start init shit
	HAL_TIM_Base_Start_IT(&tim_handle);
/*
*  Interrupt shit end 2
*/
}

/*
 *  Interrupt shit start 3
 */
//irq handler shit
void TIM3_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&tim_handle);
}
/*
 *  Interrupt shit end 3
 */





