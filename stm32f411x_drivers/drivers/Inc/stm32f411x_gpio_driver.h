/*
 * stm32f411x_gpio_driver.h
 *
 *  Created on: Aug 6, 2022
 *      Author: vishnunair
 */

#ifndef INC_STM32F411X_GPIO_DRIVER_H_
#define INC_STM32F411X_GPIO_DRIVER_H_

#include "stm32f411x.h"



/*
 *  Structure for GPIOx Pin configurations
 */
typedef struct{

	uint8_t GPIO_PinNumber;					/* Possible Values : @GPIO_PIN_NO			*/
	uint8_t GPIO_PinMode;					/* Possible Values : @GPIO_MODER_MACROS		*/
	uint8_t GPIO_PinSpeed;					/* Possible Values : @GPIO_SPEEDR_MACROS	*/
	uint8_t GPIO_PinPuPdControl;			/* Possible Values : @GPIO_PUPDR_MACROS		*/
	uint8_t GPIO_PinOPType;					/* Possible Values : @GPIO_OTYPER_MACROS	*/
	uint8_t GPIO_PinAltFunMode;

}GPIO_PinConfig_t;



/*
 *  Handle Structure for GPIOx Pin
 */

typedef struct{

	GPIO_RegDef_t *pGPIOx;
	GPIO_PinConfig_t GPIO_PinConfig;

}GPIO_Handle_t;



/*
 * @GPIO_PIN_NO
 * macros for GPIO Pins 0-15
 */

#define GPIO_PIN_NO_0			0
#define GPIO_PIN_NO_1			1
#define GPIO_PIN_NO_2			2
#define GPIO_PIN_NO_3			3
#define GPIO_PIN_NO_4			4
#define GPIO_PIN_NO_5			5
#define GPIO_PIN_NO_6			6
#define GPIO_PIN_NO_7			7
#define GPIO_PIN_NO_8			8
#define GPIO_PIN_NO_9			9
#define GPIO_PIN_NO_10			10
#define GPIO_PIN_NO_11			11
#define GPIO_PIN_NO_12			12
#define GPIO_PIN_NO_13			13
#define GPIO_PIN_NO_14			14
#define GPIO_PIN_NO_15			15



/*
 * @GPIO_MODER_MACROS
 *  Modes of GPIO Pins
 */

#define GPIO_MODE_IN			0
#define GPIO_MODE_OUT			1
#define GPIO_MODE_ALTFN			2
#define GPIO_MODE_ANALOG		3
#define GPIO_MODE_IT_FT			4
#define GPIO_MODE_IT_RT			5
#define GPIO_MODE_IT_RFT		6



/*
 * @GPIO_OTYPER_MACROS
 *  Outype type macros for GPIO
 */

#define GPIO_OTYPE_PP			0
#define GPIO_OTYPE_OD			1



/*
 * @GPIO_SPEEDR_MACROS
 *  macros for output speed register
 */

#define GPIO_SPEED_LOW			0
#define GPIO_SPEED_MEDIUM		1
#define GPIO_SPEED_FAST			2
#define GPIO_SPEED_HIGH			3



/*
 * @GPIO_PUPDR_MACROS
 * macros for  pull-up/pull-down register
 */
#define GPIO_NO_PUPD			0
#define GPIO_PU					1
#define GPIO_PD					2



/*
 *
 */





/*
 *  GPIO APIs
 */

void GPIO_PClk_Ctl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

void GPIO_Init(GPIO_Handle_t *pGPIOHandle);

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t value);

void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t value);

void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t EnorDi);

void GPIO_IRQPriorityConfig(uint8_t IRQNumber,uint32_t IRQPriority);

void GPIO_IRQHandling(uint8_t PinNumber);


#endif /* INC_STM32F411X_GPIO_DRIVER_H_ */
