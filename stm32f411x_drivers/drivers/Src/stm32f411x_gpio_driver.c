/*
 * stm32f411x_gpio_driver.c
 *
 *  Created on: Aug 6, 2022
 *      Author: vishnunair
 */


#include "stm32f411x_gpio_driver.h"



/*********************************************************************************
 *
 * @fn			- GPIO_PClk_Ctl
 *
 * @brief		- This function Enables or Disables GPIOx Peripheral Clock
 *
 * @[param1]	- GPIOx Base Address
 * @[param2]	- Enable or Disable Macro
 *
 * @return		- none
 *
 * @Note		- none
 *
 */

void GPIO_PClk_Ctl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}
	}
	else
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DI();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_DI();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_DI();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_DI();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_DI();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_DI();
		}
	}

}



/*********************************************************************************
 *
 * @fn			- GPIO_Init
 *
 * @brief		- This function Initializes GPIOx
 *
 * @[param1]	- GPIOx Handle to configure GPIO
 *
 * @return		- none
 *
 * @Note		- none
 *
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp = 0;

	//1. Configure the GPIO Mode
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); //clearing
		pGPIOHandle->pGPIOx->MODER |= temp;	//setting
	}
	else
	{
		// this configuration is for interrupt modes
		if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FT)
		{
				// Enable FTSR register
			EXTI->FTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

			// clear the corresponding RTSR bit
			EXTI->RTSR &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);


		}
		else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RT)
		{
				// Enable RTSR register
			EXTI->RTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

				// clear the corresponding FTSR bit
			EXTI->FTSR &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}
		else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RFT)
		{
				// Enable FTSR and RTSR register
			EXTI->FTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			EXTI->RTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

		}

		// Configure SYSCFG_EXTICR register
		uint8_t temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 4;
		uint8_t temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 4;

		uint8_t portCode = GPIO_BASEADDR_TO_CODE(pGPIOHandle->pGPIOx);
		SYSCFG_PCLK_EN();
		SYSCFG->EXTICR[temp1] = portCode << (4 * temp2);

		// Configure IMR Register
		EXTI->IMR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	}

	temp = 0;

	//2. Configure the GPIO Speed
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);  //clearing
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;

	temp = 0;

	//3. Configure the Pull Up/Down Settings
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);  //clearing
	pGPIOHandle->pGPIOx->PUPDR |= temp;


	temp = 0;

	//4. Configure the Output Type
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);  //clearing
	pGPIOHandle->pGPIOx->OTYPER |= temp;



	temp = 0;

	//5. Configure the alternate function mode
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
	{
		uint8_t temp1 = 0;
		uint8_t temp2 = 0;

		temp1 = (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8);
		temp2 = (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8);

		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2));

		pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF <<  (4 * temp2));  //clearing
		pGPIOHandle->pGPIOx->AFR[temp1] |= temp;

	}
}



/*********************************************************************************
 *
 * @fn			- GPIO_DeInit
 *
 * @brief		- This function Resets GPIOx Registers
 *
 * @[param1]	- To reset GPIOx
 *
 * @return		- none
 *
 * @Note		- none
 *
 */

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
	if(pGPIOx == GPIOA)
			{
				GPIOA_REG_RESET();
			}
			else if(pGPIOx == GPIOB)
			{
				GPIOB_REG_RESET();
			}
			else if(pGPIOx == GPIOC)
			{
				GPIOC_REG_RESET();
			}
			else if(pGPIOx == GPIOD)
			{
				GPIOD_REG_RESET();
			}
			else if(pGPIOx == GPIOE)
			{
				GPIOE_REG_RESET();
			}
			else if(pGPIOx == GPIOH)
			{
				GPIOH_REG_RESET();
			}
}



/*********************************************************************************
 *
 * @fn			- GPIO_ReadFromInputPin
 *
 * @brief		- Read the bit from input data register for corresponding pin
 *
 * @[param1]	- GPIOx Base Address
 * @[param2]	- Pin Number to read
 *
 * @return		- 0 or 1
 *
 * @Note		- none
 *
 */

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value = ((pGPIOx->IDR >> PinNumber) & 0x00000001);

	return value;
}



/*********************************************************************************
 *
 * @fn			- GPIO_ReadFromInputPort
 *
 * @brief		- Read the bit from input data register for given GPIO Port
 *
 * @[param1]	- GPIOx Base Address
 *
 * @return		- 0 or 1
 *
 * @Note		- none
 *
 */

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;
	value = pGPIOx->IDR;

	return value;
}



/*********************************************************************************
 *
 * @fn			- GPIO_WriteToOutputPin
 *
 * @brief		- Write the bit to output data register for given GPIO Port
 *
 * @[param1]	- GPIOx Base Address
 * @[param2]	- Pin Number to write
 * @[param3]	- Value to be written 0 or 1
 *
 * @return		- none
 *
 * @Note		- none
 *
 */

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t value)
{
	if(value == GPIO_PIN_SET)
	{
		pGPIOx->ODR	|= (1 << PinNumber);
	}
	else
	{
		pGPIOx->ODR	&= ~(1 << PinNumber);
	}

}



/*********************************************************************************
 *
 * @fn			- GPIO_WriteToOutputPort
 *
 * @brief		- Write the bit to output data register for given GPIO Port
 *
 * @[param1]	- GPIOx Base Address
 * @[param2]	- Value to be written
 *
 * @return		- none
 *
 * @Note		- none
 *
 */

void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t value)
{
	pGPIOx->ODR	= value;

}

/*********************************************************************************
 *
 * @fn			- GPIO_TogglePin
 *
 * @brief		- Toggle the GPIO Pin
 *
 * @[param1]	- GPIOx Base Address
 * @[param2]	- Pin Number to toggle
 *
 * @return		- none
 *
 * @Note		- none
 *
 */

void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR	^= (1 << PinNumber);
}



/*********************************************************************************
 *
 * @fn			- GPIO_IRQConfig
 *
 * @brief		- Toggle the GPIO Pin
 *
 * @[param1]	- IRQ position
 * @[param2]	- Enable or Disable the IRQ
 *
 * @return		- none
 *
 * @Note		- none
 *
 */

void GPIO_IRQConfig(uint8_t IRQNumber,  uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(IRQNumber < 32)
		{
			NVIC_ISER0 |= (1 << IRQNumber);
		}
		else if(IRQNumber >=32 && IRQNumber < 64)
		{
			NVIC_ISER1 |= (1 << (IRQNumber % 32));
		}
		else if(IRQNumber >=64 && IRQNumber < 96)
		{
			NVIC_ISER2 |= (1 << (IRQNumber % 64));
		}

	}
	else
	{
		if(IRQNumber < 32)
		{
			NVIC_ICER0 |= (1 << IRQNumber);
		}
		else if(IRQNumber >=32 && IRQNumber < 64)
		{
			NVIC_ICER1 |= (1 << (IRQNumber % 32));
		}
		else if(IRQNumber >=64 && IRQNumber < 96)
		{
			NVIC_ICER2 |= (1 << (IRQNumber % 64));
		}
	}

}



/*********************************************************************************
 *
 * @fn			- GPIO_IRQPriorityConfig
 *
 * @brief		- Set Interrupt Priority for GPIO
 *
 * @[param1]	- IRQ position
 * @[param2]	- IRQ Priority
 *
 * @return		- none
 *
 * @Note		- none
 *
 */

void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority)
{
	// Find the IPRx Register
	uint8_t iprx = IRQNumber / 4;
	uint8_t iprx_section = IRQNumber % 4;

	uint8_t shift_amount = (iprx_section * 8) + (8 - NVIC_IPR_BITS_IMPLEMENTED);

	NVIC_IPR(iprx) |= (IRQPriority << shift_amount);
}



/*********************************************************************************
 *
 * @fn			- GPIO_IRQHandling
 *
 * @brief		- Set Interrupt Priority for GPIO
 *
 * @[param1]	- Interrupt generated at Pin Number
 *
 * @return		- none
 *
 * @Note		- none
 *
 */

void GPIO_IRQHandling(uint8_t PinNumber)
{

	// clear the exit PR bit for corresponding Pin Number
	if(EXTI->PR & (1 << PinNumber))
	{
		EXTI->PR |= (1 << PinNumber);
	}
}
