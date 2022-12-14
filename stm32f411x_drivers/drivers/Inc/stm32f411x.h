/*
 * stm32f411x.h
 *
 *  Created on: Aug 6, 2022
 *      Author: vishnunair
 */

#ifndef INC_STM32F411X_H_
#define INC_STM32F411X_H_


#include <stdint.h>
#define __vo volatile

/*
 * ARM Cortex-Mx NVIC ISERx Register Addresses
 */

#define NVIC_ISER0							(*((__vo uint32_t *)0xE000E100))
#define NVIC_ISER1							(*((__vo uint32_t *)0xE000E104))
#define NVIC_ISER2							(*((__vo uint32_t *)0xE000E108))
#define NVIC_ISER3							(*((__vo uint32_t *)0xE000E10C))
#define NVIC_ISER4							(*((__vo uint32_t *)0xE000E110))
#define NVIC_ISER5							(*((__vo uint32_t *)0xE000E114))
#define NVIC_ISER6							(*((__vo uint32_t *)0xE000E118))
#define NVIC_ISER7							(*((__vo uint32_t *)0xE000E11C))



/*
 * ARM Cortex-Mx NVIC ISERx Register Addresses
 *
 */

#define NVIC_ICER0							(*((__vo uint32_t *)0xE000E180))
#define NVIC_ICER1							(*((__vo uint32_t *)0xE000E184))
#define NVIC_ICER2							(*((__vo uint32_t *)0xE000E188))
#define NVIC_ICER3							(*((__vo uint32_t *)0xE000E18C))
#define NVIC_ICER4							(*((__vo uint32_t *)0xE000E190))
#define NVIC_ICER5							(*((__vo uint32_t *)0xE000E194))
#define NVIC_ICER6							(*((__vo uint32_t *)0xE000E198))
#define NVIC_ICER7							(*((__vo uint32_t *)0xE000E19C))



/*
 * ARM Cortex-Mx NVIC Interrupt priority register
 * Address : 0xE000E400- 0xE000E4EF
 *
 * note - only 4 bits are implemented in each section of IPR register
 */

#define NVIC_IPR(x)							(*( (__vo uint32_t *) (0xE000E400 + (x * 4) )))
#define NVIC_IPR_BITS_IMPLEMENTED			4
/*
 * Base addresses of Flash and SRAM
 */

#define FLASH_BASEADDR						0x080000000U		/*	Embedded Flash memory in STM32F411x Start Address. Flash memory size : 512Kb	*/
#define SRAM_BASEADDR						0x200000000U		/*	Embedded SRAM Start Address. SRAM Size : 128Kb	*/
#define ROM_BASEADDR						0x01FFF0000U		/*	System memory Start Address. System Memory Size : 30Kb	*/



/*
 * AHBx and APBx Bus Peripheral Addresses
 */

#define PERIPHERAL_BASEADDR					0x40000000U				/*	Base Address for Peripheral	*/
#define APB1_BASEADDR						PERIPHERAL_BASEADDR		/*	APB1 Bus start address 	*/
#define APB2_BASEADDR						0x40010000U				/*	APB2 Bus start address		*/
#define AHB1_BASEADDR						0x40020000U				/*	AHB1 Bus start address		*/
#define AHB2_BASEADDR						0x50000000U				/*	AHB2 Bus start address		*/



/*
 * Base addresses for peripherals on AHB1 Bus
 */

#define GPIOA_BASEADDR						(AHB1_BASEADDR + 0x0000)		/*	Base address for GPIO Port A	*/
#define GPIOB_BASEADDR						(AHB1_BASEADDR + 0x0400)		/*	Base address for GPIO Port B	*/
#define GPIOC_BASEADDR						(AHB1_BASEADDR + 0x0800)		/*	Base address for GPIO Port C	*/
#define GPIOD_BASEADDR						(AHB1_BASEADDR + 0x0C00)		/*	Base address for GPIO Port D	*/
#define GPIOE_BASEADDR						(AHB1_BASEADDR + 0x1000)		/*	Base address for GPIO Port E	*/
#define GPIOH_BASEADDR						(AHB1_BASEADDR + 0x1C00)		/*	Base address for GPIO Port H	*/

#define RCC_BASEADDR						(AHB1_BASEADDR + 0x3800)		/*	Base address for Reset and Clock Control	*/

/*
 * Base addresses for peripherals of APB1 Bus
 */

#define SPI2_BASEADDR						(APB1_BASEADDR + 0x3800)		/*	Base address for SPI2	*/
#define SPI3_BASEADDR						(APB1_BASEADDR + 0x3C00)		/*	Base address for SPI3	*/

#define USART2_BASEADDR						(APB1_BASEADDR + 0x4400)		/*	Base address for USART2	*/

#define I2C1_BASEADDR						(APB1_BASEADDR + 0x5400)		/*	Base address for I2C1	*/
#define I2C2_BASEADDR						(APB1_BASEADDR + 0x5800)		/*	Base address for I2C2	*/
#define I2C3_BASEADDR						(APB1_BASEADDR + 0x5C00)		/*	Base address for I2C3	*/



/*
 * Base addresses for peripherals of APB2 Bus
 */

#define USART1_BASEADDR						(APB2_BASEADDR + 0x1000)		/*	Base address for USART1	*/
#define USART6_BASEADDR						(APB2_BASEADDR + 0x1400)		/*	Base address for USART6	*/

#define SPI1_BASEADDR						(APB2_BASEADDR + 0x3000)		/*	Base address for SPI1	*/
#define SPI4_BASEADDR						(APB2_BASEADDR + 0x3400)		/*	Base address for SPI4	*/
#define SPI5_BASEADDR						(APB2_BASEADDR + 0x5000)		/*	Base address for SPI5	*/

#define SYSCFG_BASEADDR						(APB2_BASEADDR + 0x3800)		/*	Base address for System configuration	*/

#define EXTI_BASEADDR						(APB2_BASEADDR + 0x3C00)		/*	Base address for External Interrupt	*/



/*
 * Peripheral definition structure for GPIOx
 */

typedef struct{

	__vo uint32_t MODER;					/*	GPIO port mode register. Address offset: 0x00	*/
	__vo uint32_t OTYPER;					/*	GPIO port output type register. Address offset: 0x04	*/
	__vo uint32_t OSPEEDR;					/*	GPIO port output speed register. Address offset: 0x08	*/
	__vo uint32_t PUPDR;					/*	GPIO port pull-up/pull-down register. Address offset: 0x0C	*/
	__vo uint32_t IDR;						/*	GPIO port input data register. Address offset: 0x10	*/
	__vo uint32_t ODR;						/*	GPIO port output data register. Address offset: 0x14	*/
	__vo uint32_t BSRR;						/*	GPIO port bit set/reset register. Address offset: 0x18	*/
	__vo uint32_t LCKR;						/*	GPIO port configuration lock register. Address offset: 0x1C	*/
	__vo uint32_t AFR[2];					/*	AFR[0] : GPIO alternate function low register. Address offset: 0x20, AFR[1] : GPIO alternate function high register. Address offset: 0x24	*/

}GPIO_RegDef_t;


/*
 *Peripheral definition structure for RCC (Reset and Clock Control)
 */

typedef struct{

	__vo uint32_t CR;						/*	RCC clock control register. Address offset: 0x00	*/
	__vo uint32_t PLLCFGR;					/*	RCC PLL configuration register. Address offset: 0x04	*/
	__vo uint32_t CFGR;						/*	RCC clock configuration register. Address offset: 0x08	*/
	__vo uint32_t CIR;						/*	RCC clock interrupt register. Address offset: 0x0C	*/
	__vo uint32_t AHB1RSTR;					/*	RCC AHB1 peripheral reset register. Address offset: 0x10	*/
	__vo uint32_t AHB2RSTR;					/*	RCC AHB2 peripheral reset register. Address offset: 0x14	*/
	__vo uint32_t RESERVED0[2];				/*	RESERVED */
	__vo uint32_t APB1RSTR;					/*	RCC APB1 peripheral reset register. Address offset: 0x20	*/
	__vo uint32_t APB2RSTR;					/*	RCC APB2 peripheral reset register. Address offset: 0x24	*/
	__vo uint32_t RESERVED1[2];				/*	RESERVED */
	__vo uint32_t AHB1ENR;					/*	RCC AHB1 peripheral clock enable register. Address offset: 0x30 */
	__vo uint32_t AHB2ENR;					/*	RCC AHB2 peripheral clock enable register. Address offset: 0x34	*/
	__vo uint32_t RESERVED2[2];				/*	RESERVED */
	__vo uint32_t APB1ENR;					/*	RCC APB1 peripheral clock enable register. Address offset: 0x40	*/
	__vo uint32_t APB2ENR;					/*	RCC APB2 peripheral clock enable register. Address offset: 0x44	*/
	__vo uint32_t RESERVED3[2];				/*	RESERVED */
	__vo uint32_t AHB1LPENR;				/*	RCC AHB1 peripheral clock enable in low power mode register. Address offset: 0x50	*/
	__vo uint32_t AHB2LPENR;				/*	RCC AHB2 peripheral clock enable in low power mode register. Address offset: 0x54	*/
	__vo uint32_t RESERVED4[2];				/*	RESERVED */
	__vo uint32_t APB1LPENR;				/*	RCC APB1 peripheral clock enable in low power mode register. Address offset: 0x60	*/
	__vo uint32_t APB2LPENR;				/*	RCC APB2 peripheral clock enabled in low power mode register. Address offset: 0x64	*/
	__vo uint32_t RESERVED5[2];				/*	RESERVED */
	__vo uint32_t BDCR;						/*	RCC Backup domain control register. Address offset: 0x70	*/
	__vo uint32_t CSR;						/*	RCC clock control & status register. Address offset: 0x74 */
	__vo uint32_t RESERVED6[2];				/*	RESERVED */
	__vo uint32_t SSCGR;					/*	RCC spread spectrum clock generation register. Address offset: 0x80	*/
	__vo uint32_t PLLI2SCFGR;				/*	RCC PLLI2S configuration register. Address offset: 0x84	*/
	__vo uint32_t DCKCFGR;					/*	RCC Dedicated Clocks Configuration Register. Address offset: 0x8C	*/


}RCC_RegDef_t;



/*
 * Peripheral definition structure for EXTI
 */

typedef struct{

	__vo uint32_t IMR;				/*	Interrupt mask register. Address offset: 0x00	*/
	__vo uint32_t EMR;				/*	Event mask register. Address offset: 0x04	*/
	__vo uint32_t RTSR;				/*	Rising trigger selection register. Address offset: 0x08	*/
	__vo uint32_t FTSR;				/*	Falling trigger selection register. Address offset: 0x0C	*/
	__vo uint32_t SWIER;			/*	Software interrupt event register. Address offset: 0x10	*/
	__vo uint32_t PR;				/*	Pending register. Address offset: 0x14	*/

}EXTI_RegDef_t;


/*
 *  Peripheral definition structure for SYSCFG
 */

typedef struct{

	__vo uint32_t MEMRMP;			/*	SYSCFG memory re-map register. Address offset: 0x00	*/
	__vo uint32_t PMC;				/*	SYSCFG peripheral mode configuration register. Address offset: 0x04	*/
	__vo uint32_t EXTICR[4];		/*	SYSCFG external interrupt configuration register. EXTICR[0] - Address offset: 0x08	EXTICR[1] - Address offset: 0x0C	EXTICR[2] - Address offset: 0x10	EXTICR[3] - Address offset: 0x14	*/
	__vo uint32_t CMPCR;			/*	Compensation cell control register. Address offset: 0x20*/

}SYSCFG_RegDef_t;



/*
 * Peripheral definitions
 */

#define GPIOA					((GPIO_RegDef_t *)GPIOA_BASEADDR)
#define GPIOB					((GPIO_RegDef_t *)GPIOB_BASEADDR)
#define GPIOC					((GPIO_RegDef_t *)GPIOC_BASEADDR)
#define GPIOD					((GPIO_RegDef_t *)GPIOD_BASEADDR)
#define GPIOE					((GPIO_RegDef_t *)GPIOE_BASEADDR)
#define GPIOH					((GPIO_RegDef_t *)GPIOH_BASEADDR)

#define RCC						((RCC_RegDef_t *)RCC_BASEADDR)

#define EXTI					((EXTI_RegDef_t *)EXTI_BASEADDR)

#define SYSCFG					((SYSCFG_RegDef_t *)SYSCFG_BASEADDR)

/*
 * Clock Enable Macros for GPIOx Peripherals
 */

#define GPIOA_PCLK_EN()				( RCC->AHB1ENR |= ( 1 << 0) )
#define GPIOB_PCLK_EN()				( RCC->AHB1ENR |= ( 1 << 1) )
#define GPIOC_PCLK_EN()				( RCC->AHB1ENR |= ( 1 << 2) )
#define GPIOD_PCLK_EN()				( RCC->AHB1ENR |= ( 1 << 3) )
#define GPIOE_PCLK_EN()				( RCC->AHB1ENR |= ( 1 << 4) )
#define GPIOH_PCLK_EN()				( RCC->AHB1ENR |= ( 1 << 7) )



/*
 *  Clock Enable Macros for I2Cx Peripherals
 */

#define I2C1_PCLK_EN()				( RCC->APB1ENR |= ( 1 << 21) )
#define I2C2_PCLK_EN()				( RCC->APB1ENR |= ( 1 << 22) )
#define I2C3_PCLK_EN()				( RCC->APB1ENR |= ( 1 << 23) )



/*
 *  Clock Enable Macros for SPIx Peripherals
 */

#define SPI1_PCLK_EN()				( RCC->APB2ENR |= ( 1 << 12) )
#define SPI2_PCLK_EN()				( RCC->APB1ENR |= ( 1 << 14) )
#define SPI3_PCLK_EN()				( RCC->APB1ENR |= ( 1 << 15) )
#define SPI4_PCLK_EN()				( RCC->APB2ENR |= ( 1 << 13) )
#define SPI5_PCLK_EN()				( RCC->APB2ENR |= ( 1 << 20) )


/*
 * Clock Enable Macros for USARTx Peripherals
 */

#define USART1_PCLK_EN()				( RCC->APB2ENR |= ( 1 << 4) )
#define USART2_PCLK_EN()				( RCC->APB1ENR |= ( 1 << 17) )
#define USART6_PCLK_EN()				( RCC->APB2ENR |= ( 1 << 5) )


/*
 * Clock Enable Macros for SYSCFG
 */

#define SYSCFG_PCLK_EN()				( RCC->APB2ENR |= ( 1 << 14) )





/*
 * Clock Disable Macros for GPIOx Peripherals
 */

#define GPIOA_PCLK_DI()				( RCC->AHB1ENR |= ( 1 << 0) )
#define GPIOB_PCLK_DI()				( RCC->AHB1ENR |= ( 1 << 1) )
#define GPIOC_PCLK_DI()				( RCC->AHB1ENR |= ( 1 << 2) )
#define GPIOD_PCLK_DI()				( RCC->AHB1ENR |= ( 1 << 3) )
#define GPIOE_PCLK_DI()				( RCC->AHB1ENR |= ( 1 << 4) )
#define GPIOH_PCLK_DI()				( RCC->AHB1ENR |= ( 1 << 7) )



/*
 *  Clock Disable Macros for I2Cx Peripherals
 */

#define I2C1_PCLK_DI()				( RCC->APB1ENR &= ~( 1 << 21) )
#define I2C2_PCLK_DI()				( RCC->APB1ENR &= ~( 1 << 22) )
#define I2C3_PCLK_DI()				( RCC->APB1ENR &= ~( 1 << 23) )



/*
 *  Clock Disable Macros for SPIx Peripherals
 */

#define SPI1_PCLK_DI()				( RCC->APB2ENR &= ~( 1 << 12) )
#define SPI2_PCLK_DI()				( RCC->APB1ENR &= ~( 1 << 14) )
#define SPI3_PCLK_DI()				( RCC->APB1ENR &= ~( 1 << 15) )
#define SPI4_PCLK_DI()				( RCC->APB2ENR &= ~( 1 << 13) )
#define SPI5_PCLK_DI()				( RCC->APB2ENR &= ~( 1 << 20) )


/*
 * Clock Disable Macros for USARTx Peripherals
 */

#define USART1_PCLK_DI()				( RCC->APB2ENR &= ~( 1 << 4) )
#define USART2_PCLK_DI()				( RCC->APB1ENR &= ~( 1 << 17) )
#define USART6_PCLK_DI()			( RCC->APB2ENR &= ~( 1 << 5) )


/*
 * Clock Disable Macros for SYSCFG
 */

#define SYSCFG_PCLK_DI()				( RCC->APB2ENR &= ~( 1 << 14) )



/*
 * Macros to reset GPIOx registers
 */

#define GPIOA_REG_RESET()			do { ( RCC->AHB1RSTR |= ( 1 << 0)); ( RCC->AHB1RSTR &= ~( 1 << 0)); } while(0)
#define GPIOB_REG_RESET()			do { ( RCC->AHB1RSTR |= ( 1 << 1)); ( RCC->AHB1RSTR &= ~( 1 << 1)); } while(0)
#define GPIOC_REG_RESET()			do { ( RCC->AHB1RSTR |= ( 1 << 2)); ( RCC->AHB1RSTR &= ~( 1 << 2)); } while(0)
#define GPIOD_REG_RESET()			do { ( RCC->AHB1RSTR |= ( 1 << 3)); ( RCC->AHB1RSTR &= ~( 1 << 3)); } while(0)
#define GPIOE_REG_RESET()			do { ( RCC->AHB1RSTR |= ( 1 << 4)); ( RCC->AHB1RSTR &= ~( 1 << 4)); } while(0)
#define GPIOH_REG_RESET()			do { ( RCC->AHB1RSTR |= ( 1 << 7)); ( RCC->AHB1RSTR &= ~( 1 << 7)); } while(0)



/*
 * Macro for GPIOx Base Address to Code
 */
#define GPIO_BASEADDR_TO_CODE(x)	(	x == GPIOA ? 0 : \
									 	x == GPIOB ? 1 : \
										x == GPIOC ? 2 : \
										x == GPIOD ? 3 : \
										x == GPIOE ? 4 : \
										x == GPIOH ? 7 : 0	)



/*
 *	Interrupt Request Numbers for STM32F411x
 */
#define IRQ_NO_EXTI0				6
#define IRQ_NO_EXTI1				7
#define IRQ_NO_EXTI2				8
#define IRQ_NO_EXTI3				9
#define IRQ_NO_EXTI4				10
#define IRQ_NO_EXTI9_5				23
#define IRQ_NO_EXTI10_15			40
#define IRQ_NO_EXTI16				1
#define IRQ_NO_EXTI17				41
#define IRQ_NO_EXTI18				42
#define IRQ_NO_EXTI21				2
#define IRQ_NO_EXTI22				3



/*
 *  Interrupt Priority Number macros
 */

#define NVIC_IRQ_PRIO				0
#define NVIC_IRQ_PRI1				1
#define NVIC_IRQ_PRI2				2
#define NVIC_IRQ_PRI3				3
#define NVIC_IRQ_PRI4				4
#define NVIC_IRQ_PRI5				5
#define NVIC_IRQ_PRI6				6
#define NVIC_IRQ_PRI7				7
#define NVIC_IRQ_PRI8				8
#define NVIC_IRQ_PRI9				9
#define NVIC_IRQ_PRI1O				10
#define NVIC_IRQ_PRI11				11
#define NVIC_IRQ_PRI12				12
#define NVIC_IRQ_PRI13				13
#define NVIC_IRQ_PRI14				14
#define NVIC_IRQ_PRI15				15



/*
 *  some generic macros
 */

#define ENABLE 				1
#define DISABLE				0
#define SET					ENABLE
#define RESET				DISABLE
#define GPIO_PIN_SET		SET
#define GPIO_PIN_RESET		RESET
#define HIGH				GPIO_PIN_SET
#define LOW					GPIO_PIN_RESET

#include "stm32f411x_gpio_driver.h"

#endif /* INC_STM32F411X_H_ */
