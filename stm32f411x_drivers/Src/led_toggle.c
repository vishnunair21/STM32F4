/*
 * led_toggle.c
 *
 *  Created on: 06-Aug-2022
 *      Author: vishnunair
 */


#include "stm32f411x.h"

void delay()
{
	for(uint32_t i = 0; i < 500000; i++);
}

int main(void)
{

	GPIO_Handle_t GPIOLed;

	GPIOLed.pGPIOx = GPIOD;
	GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GPIOLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GPIOLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OTYPE_PP;
	GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PClk_Ctl(GPIOD, ENABLE);

	GPIO_Init(&GPIOLed);

	GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	GPIO_Init(&GPIOLed);

	while(1)
	{
		GPIO_TogglePin(GPIOD, GPIO_PIN_NO_12);
		GPIO_TogglePin(GPIOD, GPIO_PIN_NO_14);
		delay();

	}
	return 0;
}

