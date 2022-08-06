/*
 * led_button.c
 *
 *  Created on: 06-Aug-2022
 *      Author: vishnunair
 */


#include "stm32f411x.h"


#define GPIO_BUTTON_PRESSED HIGH
void delay()
{
	for(uint32_t i = 0; i < 500000/2; i++);
}

int main(void)
{

	GPIO_Handle_t GPIOLed;
	GPIO_Handle_t GPIOBtn;


	GPIOLed.pGPIOx = GPIOD;
	GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GPIOLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GPIOLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OTYPE_PP;
	GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIOBtn.pGPIOx = GPIOA;
	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;


	GPIO_PClk_Ctl(GPIOD, ENABLE);
	GPIO_PClk_Ctl(GPIOA, ENABLE);

	GPIO_Init(&GPIOLed);

	GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	GPIO_Init(&GPIOLed);

	GPIO_Init(&GPIOBtn);

	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == GPIO_BUTTON_PRESSED)
		{
			delay();
			GPIO_TogglePin(GPIOD, GPIO_PIN_NO_12);
			GPIO_TogglePin(GPIOD, GPIO_PIN_NO_14);
		}

	}
	return 0;
}
