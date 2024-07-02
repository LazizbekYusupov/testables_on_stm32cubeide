//GPIO Training
#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "uart.h"
#include "gpio.h"
#include "buttons_n_leds_game.h"
#include "adc.h"
#include "gpio_exti.h"
#include "tim.h"
#include "rtc_it.h"

//coding plans:
//-watch tajweed lecture 7.
//-read a bit of a book, at least a section from chapter 3.

//-remember errors you did:
//backup register func name and register
//mistaken in sprintf data formatting
//forgot adding millenia in sprintf formatting
//creating arrays for time and date
//-practice rtc lectures. End program - shows exact time like outside and works accurately.
//-repeat all the lectures and practice cube mx timers and pwm timers.
//-check if | operator possible to use with the buttons and leds game in gpio.c file
//do practice of uart interrupt, get the very deep idea - didn't get the nature, ask the Mentor

char show_time[15] = {0};
char show_date[15] = {0};

RTC_HandleTypeDef RTC_InitStruct;

int main()
{
	HAL_Init();
	usart1_rxtx_init_polling();

	__HAL_RTC_RESET_HANDLE_STATE;

	rtc_init();

	uint32_t backup_data = HAL_RTCEx_BKUPRead(&RTC_InitStruct, RTC_BKP_DR0);
	printf("backup_data = %x\r\n", backup_data);

	rtc_calendar_config();

	while(1)
	{
		rtc_calendar_show(show_time, show_date);
	}

	return 0;
}

void SysTick_Handler(void)
{
	HAL_IncTick();
}
































































