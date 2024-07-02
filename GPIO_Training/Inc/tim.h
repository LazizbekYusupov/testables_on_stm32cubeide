/*
 * tim.h
 *
 *  Created on: Jun 10, 2024
 *      Author: User
 */

#ifndef TIM_H_
#define TIM_H_

#define TIMx TIM3
#define TIMx_CLK_ENABLE __HAL_RCC_TIM3_CLK_ENABLE
#define TIMx_IRQHandler TIM3_IRQHandler
#define TIMx_IRQn TIM3_IRQn

void tim_base_init(void);

#endif /* TIM_H_ */


//IN MAIN
//WITHIN MAIN()
//usart1_rxtx_init_polling();
//tim_base_init();

//OUTSIDE MAIN();
///*
// *  Interrupt shit start 4
// */
////employ it, callback shit
//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
//{
//	static int counter = 1;
//	printf("%d seconds elapsed\n\r", counter++);
//}
///*
// *  Interrupt shit end 4
// */























