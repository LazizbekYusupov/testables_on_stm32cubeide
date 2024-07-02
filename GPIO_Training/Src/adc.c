/*
 * adc.c
 *
 *  Created on: May 23, 2024
 *      Author: User
 */
#include "stm32f4xx_hal.h"
#include "adc.h"

static void cont_adc_pa0_init(void);
//create adc handle structure
ADC_HandleTypeDef handle_adc;
//extern ADC_HandleTypeDef handle_adc;

void single_adc_pa0_init(void)
{
	//init hal
	HAL_Init();

	//************************
	//GPIO stuff**************
	//gpio clock
	__HAL_RCC_GPIOA_CLK_ENABLE();

	//declare initTypeDef
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	//initialize configuration handle
	ADC_ChannelConfTypeDef sConfig = {0};
	//fill in and init it

	GPIO_InitStruct.Pin = GPIO_PIN_0;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;

	HAL_GPIO_Init(ADC1_PA0, &GPIO_InitStruct);
	//****************************
	//ACD stuff*******************
	//enable adc clock
	__HAL_RCC_ADC1_CLK_ENABLE();

	//fill in the structure members
	handle_adc.Instance = ADC1;
	handle_adc.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV8;
	handle_adc.Init.Resolution = ADC_RESOLUTION_12B;
	handle_adc.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	handle_adc.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	handle_adc.Init.ContinuousConvMode = DISABLE;
	handle_adc.Init.DiscontinuousConvMode = DISABLE;
	handle_adc.Init.NbrOfConversion = 1;
	handle_adc.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	handle_adc.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	handle_adc.Init.DMAContinuousRequests = DISABLE;

	HAL_ADC_Init(&handle_adc);


	//fill in the structure
	sConfig.Channel = ADC_CHANNEL_0;
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;

	//init up both adc handle and configuration handle structures
	 HAL_ADC_ConfigChannel(&handle_adc, &sConfig);
}

static void cont_adc_pa0_init(void)
{
	//init hal
	HAL_Init();

	//************************
	//GPIO stuff**************
	//gpio clock
	__HAL_RCC_GPIOA_CLK_ENABLE();

	//declare initTypeDef
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	//initialize configuration handle
	ADC_ChannelConfTypeDef sConfig = {0};
	//fill in and init it

	GPIO_InitStruct.Pin = GPIO_PIN_0;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;

	HAL_GPIO_Init(ADC1_PA0, &GPIO_InitStruct);
	//****************************
	//ACD stuff*******************
	//enable adc clock
	__HAL_RCC_ADC1_CLK_ENABLE();

	//fill in the structure members
	handle_adc.Instance = ADC1;
	handle_adc.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV8;
	handle_adc.Init.Resolution = ADC_RESOLUTION_12B;
	handle_adc.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	handle_adc.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	handle_adc.Init.ContinuousConvMode = ENABLE;
	handle_adc.Init.NbrOfConversion = 1;
	handle_adc.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	handle_adc.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	handle_adc.Init.DMAContinuousRequests = DISABLE;

	HAL_ADC_Init(&handle_adc);

	//fill in the structure
	sConfig.Channel = ADC_CHANNEL_0;
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;

	//init up both adc handle and configuration handle structures
	 HAL_ADC_ConfigChannel(&handle_adc, &sConfig);
}

//continuous conversion interrupt initialization

void adc_pa0_start(void)
{
	cont_adc_pa0_init();
	HAL_ADC_Start(&handle_adc);
}

//interrupt single conversion version adc init
void it_single_adc_pa0_init(void)
{
	//init hal
	HAL_Init();

	//************************
	//GPIO stuff**************
	//gpio clock
	__HAL_RCC_GPIOA_CLK_ENABLE();

	//declare initTypeDef
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	//initialize configuration handle
	ADC_ChannelConfTypeDef sConfig = {0};
	//fill in and init it

	GPIO_InitStruct.Pin = GPIO_PIN_0;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;

	HAL_GPIO_Init(ADC1_PA0, &GPIO_InitStruct);
	//****************************
	//ACD stuff*******************
	//enable adc clock
	__HAL_RCC_ADC1_CLK_ENABLE();

	//fill in the structure members
	handle_adc.Instance = ADC1;
	handle_adc.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV8;
	handle_adc.Init.Resolution = ADC_RESOLUTION_12B;
	handle_adc.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	handle_adc.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	handle_adc.Init.ContinuousConvMode = DISABLE;
	handle_adc.Init.DiscontinuousConvMode = DISABLE;
	handle_adc.Init.NbrOfConversion = 1;
	handle_adc.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	handle_adc.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	handle_adc.Init.DMAContinuousRequests = DISABLE;

	HAL_ADC_Init(&handle_adc);

	//fill in the structure
	sConfig.Channel = ADC_CHANNEL_0;
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;

	//init up both adc handle and configuration handle structures
	 HAL_ADC_ConfigChannel(&handle_adc, &sConfig);

	 //Enable NVICs for init
	 HAL_NVIC_SetPriority(ADC_IRQn, 0, 0);
	 HAL_NVIC_EnableIRQ(ADC_IRQn);
}

//interrupt single conversion version adc init
void it_cont_adc_pa0_init(void)
{
	//init hal
	HAL_Init();

	//************************
	//GPIO stuff**************
	//gpio clock
	__HAL_RCC_GPIOA_CLK_ENABLE();

	//declare initTypeDef
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	//initialize configuration handle
	ADC_ChannelConfTypeDef sConfig = {0};
	//fill in and init it

	GPIO_InitStruct.Pin = GPIO_PIN_0;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;

	HAL_GPIO_Init(ADC1_PA0, &GPIO_InitStruct);
	//****************************
	//ACD stuff*******************
	//enable adc clock
	__HAL_RCC_ADC1_CLK_ENABLE();

	//fill in the structure members
	handle_adc.Instance = ADC1;
	handle_adc.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV8;
	handle_adc.Init.Resolution = ADC_RESOLUTION_12B;
	handle_adc.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	handle_adc.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	handle_adc.Init.ContinuousConvMode = ENABLE;
	handle_adc.Init.DiscontinuousConvMode = DISABLE;
	handle_adc.Init.NbrOfConversion = 1;
	handle_adc.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	handle_adc.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	handle_adc.Init.DMAContinuousRequests = DISABLE;

	HAL_ADC_Init(&handle_adc);

	//fill in the structure
	sConfig.Channel = ADC_CHANNEL_0;
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;

	//init up both adc handle and configuration handle structures
	 HAL_ADC_ConfigChannel(&handle_adc, &sConfig);

	 //Enable NVICs for init
	 HAL_NVIC_SetPriority(ADC_IRQn, 0, 0);
	 HAL_NVIC_EnableIRQ(ADC_IRQn);
}

//make use of adc functionality
uint32_t read_pa0_data(void)
{
	return HAL_ADC_GetValue(&handle_adc);
}

//ADC IRQ Handler stuff
void ADC_IRQHandler(void)
{
	HAL_ADC_IRQHandler(&handle_adc);
}


























