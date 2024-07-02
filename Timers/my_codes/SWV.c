/*
 * SWV.c
 *
 *  Created on: Jun 5, 2024
 *      Author: pcbden
 */
#include "SWV.h"

/* @note   Enable SWO on cubeMX first (SYS->Debug->Trace Asynchronous SW)
 * @brief  Prints string data to SWV
 * @param  data -> String data to be printed
 * @param  port -> SWV port number (0-31)
 * @retval none
 */
void printS(char* data, int port)
{

	for(int i = 0; i < strlen(data); i++)
	{
		ITM->PORT[port].u8 = data[i];

		HAL_Delay(1);
	}

	ITM->PORT[port].u8 = '\n';
}

/* @note   Enable SWO on cubeMX first (SYS->Debug->Trace Asynchronous SW)
 * @brief  Prints Integer data to SWV
 * @param  data -> Integer to be printed (32 bit signed)
 * @param  port -> SWV port number (0-31)
 * @retval none
 */
void printD(int data, int port)
{
	char temp_A[32];

	itoa(data, temp_A, 10);

	printS(temp_A, port);
}
