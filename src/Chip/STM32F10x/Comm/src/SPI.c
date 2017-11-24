#include "SPI.h"

void vSPI1_Configure(void)
{
  SPI_InitTypeDef  SPI_InitStructure;
  GPIO_InitTypeDef  GPIO_InitStructure;
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE );
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,  ENABLE );  
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  GPIO_SetBits(GPIOA,GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7);

  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;  
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;		
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;		
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;		
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;	
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;	
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;		
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;	
  SPI_InitStructure.SPI_CRCPolynomial = 7;	
  SPI_Init(SPI1, &SPI_InitStructure);  

  SPI_Cmd(SPI1, ENABLE); 
}

void vSPI1_SetSpeed(u8 SPI_BaudRatePrescaler)
{
  SPI1->CR1&=0XFFC7;
  SPI1->CR1|=SPI_BaudRatePrescaler;	
  SPI_Cmd(SPI1,ENABLE); 
}

u8 SPI1_TxRxByte(u8 Dat)
{
  u8 t=0;				 	
  while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET)
  {
    t++;
    if(t>250)return 0;
  }			  
  SPI_I2S_SendData(SPI1, Dat); 
  
  t=0;
  while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET) 
  {
    t++;
    if(t>250)return 0;
  }	  						    
  return SPI_I2S_ReceiveData(SPI1); 			    
}


void vSPI2_Configure(void)
{
  SPI_InitTypeDef  SPI_InitStructure;
  GPIO_InitTypeDef  GPIO_InitStructure;
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE );
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2,  ENABLE );  
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  GPIO_SetBits(GPIOB,GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);

  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;  
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;		
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;		
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;		
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;	
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;	
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;		
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;	
  SPI_InitStructure.SPI_CRCPolynomial = 7;	
  SPI_Init(SPI2, &SPI_InitStructure);  

  SPI_Cmd(SPI2, ENABLE); 
}

void vSPI2_SetSpeed(u8 SPI_BaudRatePrescaler)
{
  SPI2->CR1&=0XFFC7;
  SPI2->CR1|=SPI_BaudRatePrescaler;	
  SPI_Cmd(SPI2,ENABLE); 
}

u8 SPI2_TxRxByte(u8 Dat)
{
  u8 t=0;				 	
  while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET)
  {
    t++;
    if(t>250)return 0;
  }			  
  SPI_I2S_SendData(SPI2, Dat); 
  
  t=0;
  while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET) 
  {
    t++;
    if(t>250)return 0;
  }	  						    
  return SPI_I2S_ReceiveData(SPI2); 			    
}


