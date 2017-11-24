/**
  ******************************************************************************
  * @file    platform_config.h
  * @author  MCD Application Team
  * @version V4.0.0
  * @date    21-January-2013
  * @brief   Evaluation board specific configuration file.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PLATFORM_CONFIG_H
#define __PLATFORM_CONFIG_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Uncomment the line corresponding to the STMicroelectronics evaluation board
   used to run the example */


/*Unique Devices IDs register set*/

#if defined(STM32L1XX_MD) || defined(STM32L1XX_HD) || defined(STM32L1XX_MD_PLUS) 

#define         ID1          (0x1FF80050)
#define         ID2          (0x1FF80054)
#define         ID3          (0x1FF80064)

#elif defined (STM32F37X) || defined(STM32F30X)

#define         ID1          (0x1FFFF7AC)
#define         ID2          (0x1FFFF7B0)
#define         ID3          (0x1FFFF7B4)

#else /*STM32F1x*/

#define         ID1          (0x1FFFF7E8)
#define         ID2          (0x1FFFF7EC)
#define         ID3          (0x1FFFF7F0)

#endif


/* Define the STM32F10x hardware depending on the used evaluation board */
#define USB_SOFT_CTL_KEY 0 //软件方式控制

#if (USB_SOFT_CTL_KEY > 0) 
#define USB_DISCONNECT                      GPIOB  
#define USB_DISCONNECT_PIN                  GPIO_Pin_14
#define RCC_APB2Periph_GPIO_DISCONNECT      RCC_APB2Periph_GPIOB
#endif
  
#define  CustomHID_TXMAXLEN     32 /*发送数据长度*/
#define  CustomHID_RXMAXLEN     32 /*接收数据长度*/
#define  KEYBOARD_TXMAXLEN      8 /*接收数据长度*/
#define  PUTNUMMAX_CARDSNR          10 /*输出卡号位数*/

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __PLATFORM_CONFIG_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
