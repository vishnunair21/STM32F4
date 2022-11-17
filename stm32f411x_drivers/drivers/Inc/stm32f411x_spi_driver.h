/*
 * stm32f411x_spi_driver.h
 *
 *  Created on: 18-Aug-2022
 *      Author: vishnunair
 */

#ifndef INC_STM32F411X_SPI_DRIVER_H_
#define INC_STM32F411X_SPI_DRIVER_H_

#include "stm32f411x.h"



/*
 *  Structure for SPIx configurations
 */

typedef struct {

	uint8_t SPI_DeviceMode;
	uint8_t SPI_BusCOnfig;
	uint8_t SPI_SClkSpeed;
	uint8_t SPI_DFF;
	uint8_t SPI_CPOL;
	uint8_t SPI_CPHA;
	uint8_t SPI_SSM;

}SPI_Config_t;


/*
 *  Structur for SPIx Peripheral
 */

typedef struct {

	SPI_RegDef_t *pSPIx;
	SPI_Config_t SPIConfig;

}SPI_Handle_t;


#endif /* INC_STM32F411X_SPI_DRIVER_H_ */
