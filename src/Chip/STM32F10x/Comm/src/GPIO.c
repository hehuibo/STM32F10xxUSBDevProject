#include "GPIO.h"
#include "stm32f10x.h"

//	GPIO_WriteBit(GPIOE, GPIO_Pin_5, (BitAction)(1-GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_5)));

void vGPIO_Configure(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOA,GPIO_Pin_0); 
	GPIO_SetBits(GPIOA,GPIO_Pin_1); 

}


