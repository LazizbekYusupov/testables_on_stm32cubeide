#include "stm32f4xx_hal.h"

#define K0_PORT GPIOE
#define K0 GPIO_PIN_4
#define D2_PORT GPIOA
#define D2 GPIO_PIN_6

void pe4_k0_init (void);
void pa6_d2_init (void);

uint8_t buttonState;

//BUTTON||KEY0||K0 == PE4, BUS == AHB1EN, BIT 4
//LED||D2 == PA6, BUS == AHB1EN, BIT 0

int main ()
{
	HAL_Init ();
	pe4_k0_init ();
	pa6_d2_init ();

	while (1)
	{
		buttonState = HAL_GPIO_ReadPin (K0_PORT, K0);

		HAL_GPIO_WritePin (D2_PORT, D2, buttonState);
	}
}

void pe4_k0_init (void)
{
	GPIO_InitTypeDef	GPIO_InitStruct = {0};

	__HAL_RCC_GPIOE_CLK_ENABLE();

	//#define K0_PORT GPIOE
	//#define K0 GPIO_PIN_4
	//#define D2_PORT GPIOA
	//#define D2 GPIO_PIN_6

	GPIO_InitStruct.Pin   = K0;
	GPIO_InitStruct.Mode  = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull  = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init (K0_PORT, &GPIO_InitStruct);
}

void pa6_d2_init (void)
{
	GPIO_InitTypeDef	GPIO_InitStruct = {0};

	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitStruct.Pin   = D2;
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull  = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init (D2_PORT, &GPIO_InitStruct);
}

void SysTick_Handler(void)
{
	HAL_IncTick();
}













