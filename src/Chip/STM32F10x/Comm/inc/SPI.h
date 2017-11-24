#ifndef _SPI_H
#define _SPI_H

#if defined (STM32F40_41xxx)
#include "stm32f4xx.h"
#else
#include "stm32f10x.h"
#endif

void vSPI1_Configure(void);

void vSPI1_SetSpeed(u8 SPI_BaudRatePrescaler);

u8 SPI1_TxRxByte(u8 Dat);

void vSPI2_Configure(void);

void vSPI2_SetSpeed(u8 SPI_BaudRatePrescaler);

u8 SPI2_TxRxByte(u8 Dat);



#if defined (_FreeRTOS_Kernel)
void spi_lock(void);
void spi_unlock(void);
void spi_wait(void);
#else
#define	spi_lock()
#define spi_unlock()
#define spi_wait()
#endif

#endif
