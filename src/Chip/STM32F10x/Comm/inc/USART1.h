/*
 * USART1.h
 *
 *  Created on: 20xxƒÍx‘¬x»’
 *      Author: HeHuiBo
 */

#ifndef USART1_H_
#define USART1_H_

#include "stm32f10x.h"



#define USART_MAX_BUF_LEN   256

struct _tag_SerBuf
{
  uint8_t mRxBuf[USART_MAX_BUF_LEN];
  unsigned short mRxLen;
};

extern struct _tag_SerBuf Ser1Buf;

void vUSART1_Configure(u32 nBaund);
#if 0
void vUSART1_RxDMA_Enable(void);
void vUSART1_SendStr(const char* pStr,unsigned int len);
#endif
void USART1_DMATxDat(const unsigned char *pStr, unsigned short len);

#endif /* USART1_H_ */
