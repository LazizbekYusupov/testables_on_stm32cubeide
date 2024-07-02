/*
 * rtc_it.c
 *
 *  Created on: Jun 18, 2024
 *      Author: User
 */
#include "stm32f4xx_hal.h"
#include "rtc_it.h"

/*
 * I have several questions accumulated during lecture 43.
 * RTC section.
 * RTC is actually the very core of the project code base
 * I am receiving in my new job place.
 *
 * 1) Why exactly LSI is used? Can we use LSE instead and have the same effect?
 * 2) Why would you use the following:
 *  RTC_TimeTypeDef RTC_TimeInitStruct = {0};
 *  RTC_TimeInitStruct.TimeFormat = RTC_HOURFORMAT12_AM;
 *  if you have this:
 *  RTC_HandleTypeDef RTC_InitStruct;
 *  RTC_InitStruct.Init.HourFormat = RTC_HOURFORMAT_24;
 *
 *  Why not, let us say, 'RTC_HOURFORMAT12_PM'?
 * 3)RTC_TimeInitStruct.StoreOperation = RTC_STOREOPERATION_RESET;
 * In the code above, why would you use '_RESET'? Is
 * it somehow related to backup register?
 * 4)void rtc_calendar_show(uint8_t *show_time, uint8_t *show_date)
{
	RTC_DateTypeDef RTC_DateGetStruct = {0};
	RTC_TimeTypeDef RTC_TimeGetStruct = {0};

	HAL_RTC_GetDate(&RTC_InitStruct, &RTC_DateGetStruct, RTC_FORMAT_BIN);
	HAL_RTC_GetTime(&RTC_InitStruct, &RTC_TimeGetStruct, RTC_FORMAT_BIN);

	why did you use BCD previously in setting but _BIN in getting?
 * 5)__HAL_RTC_RESET_HANDLE_STATE;
 * why is it done? Analogy from other modules?
 */

extern RTC_HandleTypeDef RTC_InitStruct;

void rtc_init(void)
{
	//Configure RCC for RTC

	RCC_OscInitTypeDef Osc_InitStruct = {0};

	Osc_InitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE | RCC_OSCILLATORTYPE_LSI;
	Osc_InitStruct.LSEState = RCC_LSE_OFF;
	Osc_InitStruct.LSIState = RCC_LSI_ON;

	HAL_RCC_OscConfig(&Osc_InitStruct);

	RCC_PeriphCLKInitTypeDef Perif_ClkInitStruct = {0};

	Perif_ClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC;
	Perif_ClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;

	HAL_RCCEx_PeriphCLKConfig(&Perif_ClkInitStruct);

	 __HAL_RCC_RTC_ENABLE();

	 //Configure RTC itself
	 //Handle is global variable outside function

	 RTC_InitStruct.Instance = RTC;
	 RTC_InitStruct.Init.HourFormat = RTC_HOURFORMAT_24;
	 RTC_InitStruct.Init.AsynchPrediv = RTC_ASYNCH_PREDIV;
	 RTC_InitStruct.Init.SynchPrediv = RTC_SYNCH_PREDIV;
	 RTC_InitStruct.Init.OutPut = RTC_OUTPUT_DISABLE;

	 HAL_RTC_Init(&RTC_InitStruct);
}

void rtc_calendar_config(void)
{
	RTC_DateTypeDef RTC_DateInitStruct = {0};
	RTC_TimeTypeDef RTC_TimeInitStruct = {0};

	//Date configure for Sunday July 14th 2019
	RTC_DateInitStruct.Year = 0x24;
	RTC_DateInitStruct.Month = RTC_MONTH_JUNE;
	RTC_DateInitStruct.Date = 0x18;
	RTC_DateInitStruct.WeekDay = RTC_WEEKDAY_SUNDAY;

	HAL_RTC_SetDate(&RTC_InitStruct, &RTC_DateInitStruct, RTC_FORMAT_BCD);

	//Time configure for 19:30:30 (editable by time)
	RTC_TimeInitStruct.Hours = 0x19;
	RTC_TimeInitStruct.Minutes = 0x30;
	RTC_TimeInitStruct.Seconds = 0x25;
	RTC_TimeInitStruct.TimeFormat = RTC_HOURFORMAT12_AM;
	RTC_TimeInitStruct.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	RTC_TimeInitStruct.StoreOperation = RTC_STOREOPERATION_RESET;

	HAL_RTC_SetTime(&RTC_InitStruct, &RTC_TimeInitStruct, RTC_FORMAT_BCD);

	HAL_RTCEx_BKUPWrite(&RTC_InitStruct, RTC_BKP_DR0, BKP_FLAG);
}

void rtc_calendar_show(uint8_t *show_time, uint8_t *show_date)
{
	RTC_DateTypeDef RTC_DateGetStruct = {0};
	RTC_TimeTypeDef RTC_TimeGetStruct = {0};

	HAL_RTC_GetDate(&RTC_InitStruct, &RTC_DateGetStruct, RTC_FORMAT_BIN);
	HAL_RTC_GetTime(&RTC_InitStruct, &RTC_TimeGetStruct, RTC_FORMAT_BIN);

	sprintf((char*)show_date, "Date = %d-%d-%d weekday no = %d\n", RTC_DateGetStruct.Date, RTC_DateGetStruct.Month, RTC_DateGetStruct.Year, RTC_DateGetStruct.WeekDay);
	sprintf((char*)show_time, "Time = %02d:%02d:%02d\n", RTC_TimeGetStruct.Hours, RTC_TimeGetStruct.Minutes, RTC_TimeGetStruct.Seconds);

	printf("Date = %02d-%02d-02%d weekday no = %d\r\n", RTC_DateGetStruct.Date, RTC_DateGetStruct.Month, 2000 + RTC_DateGetStruct.Year, RTC_DateGetStruct.WeekDay);
	printf("Time = %02d:%02d:%02d\r\n", RTC_TimeGetStruct.Hours, RTC_TimeGetStruct.Minutes, RTC_TimeGetStruct.Seconds);
}





















































