/*
 * gpio.h
 *
 *  Created on: May 21, 2024
 *      Author: User
 */

#ifndef GPIO_H_
#define GPIO_H_

//BUTTON1||KEY0||K0 == PE4, BUS == AHB1EN, BIT 4
//BUTTON2||KEY1||K1 == PE3, BUS == AHB1EN, BIT 4
#define K0_PORT GPIOE
#define K0 GPIO_PIN_4
#define K1_PORT GPIOE
#define K1 GPIO_PIN_3

//LED1||D2 == PA6, BUS == AHB1EN, BIT 0
//LED2||D3 == PA7, BUS == AHB1EN, BIT 0
#define D2_PORT GPIOA
#define D2 GPIO_PIN_6
#define D3_PORT GPIOA
#define D3 GPIO_PIN_7

//buttons and LEDs
void pe4_k0_init(void);
void pa6_d2_init(void);

void pe3_k1_init(void);
void pa7_d3_init(void);

#endif /* GPIO_H_ */
