/*
 * adc.h
 *
 *  Created on: May 23, 2024
 *      Author: User
 */
//POLLING VERSION ADC VERSION MAIN
//2) uint32_t sensor_data;
//adc_pa0_start();
//
//while(1)
//{
//	sensor_data = read_pa0_data();
//}

#ifndef ADC_H_
#define ADC_H_

#define ADC1_PA0 GPIOA
void adc_pa0_start(void);
uint32_t read_pa0_data(void);

void single_adc_pa0_init(void);

void it_single_adc_pa0_init(void);
void it_cont_adc_pa0_init(void);

#endif /* ADC_H_ */

//SINGLE CONVERSION VERSION MAIN
//
//ADC_HandleTypeDef handle_adc;
//
//uint32_t sensor_data;
//
//int main()
//{
//	//init uart
//	usart1_rxtx_init();
//
//	//0) init adc
//   	single_adc_pa0_init();
//
//    HAL_ADC_ConvCpltCallback()
//
//	while(1)
//	{
//		//1) start adc
//		HAL_ADC_Start(&handle_adc);
//		//2) poll for conversion
//		HAL_ADC_PollForConversion(&handle_adc, 10);
//		//3) read data
//		sensor_data = read_pa0_data();
//
//		printf("sensor_data = %ld\n\r", sensor_data);
//	}
//
//	return 0;
//}


//CONTINUOUS CONVERSION MAIN FILE
//
//char message[50] = "Button K1 is pressed\r\n";
//
//ADC_HandleTypeDef handle_adc;
//
//uint32_t sensor_data;
//
//int main()
//{
//	//interrupt adc init
//	it_cont_adc_pa0_init();
//
//	//init uart
//	usart1_rxtx_init_polling();
//
//	//start interrupt adc
//	HAL_ADC_Start_IT(&handle_adc);
//
//	while(1)
//	{
//		printf("sensor_data = %ld\n\r", sensor_data);
//	}
//
//	return 0;
//}
//
//void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
//{
//	//do something
//
//	sensor_data = read_pa0_data();
//
//
//	//HAL_ADC_Start_IT(&handle_adc);
//}














