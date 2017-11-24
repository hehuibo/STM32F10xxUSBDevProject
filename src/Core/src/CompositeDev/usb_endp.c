/**
  ******************************************************************************
  * @file    usb_endp.c
  * @author  MCD Application Team
  * @version V4.0.0
  * @date    21-January-2013
  * @brief   Endpoint routines
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


/* Includes ------------------------------------------------------------------*/
#include "hw_config.h"
#include "usb_lib.h"
#include "usb_istr.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

#if defined (_LOADER) || defined (_NoRTOSKernel) 
#include "FSM.h"
#endif

uint8_t CustomHIDRecvBuffer[CustomHID_RXMAXLEN];
uint8_t CustomHIDSendBuffer[CustomHID_TXMAXLEN];

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
* Function Name  : EP1_IN_Callback.
* Description    : EP1 IN Callback Routine.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void EP1_IN_Callback(void)
{
  #if defined (UART_TRACE) || defined (JLINK_RTT_TRACE)
  dbgTRACE_FUNCTION();
  #endif
}

void EP2_OUT_Callback(void)
{
  #if defined (UART_TRACE) || defined (JLINK_RTT_TRACE)
  dbgTRACE_FUNCTION();
  #endif
}

void EP2_IN_Callback(void)
{
  #if defined (UART_TRACE) || defined (JLINK_RTT_TRACE)
  dbgTRACE_FUNCTION();
  #endif
}

/*******************************************************************************
* Function Name  : EP1_OUT_Callback.
* Description    : EP1 OUT Callback Routine.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void EP1_OUT_Callback(void)
{
  /* Read received data */  
  #if defined (UART_TRACE) || defined (JLINK_RTT_TRACE)
  dbgTRACE("EPRxCount:%d\r\n", GetEPRxCount(ENDP1));
  #endif
#if 1
  USB_SIL_Read(EP1_OUT, CustomHIDRecvBuffer);
#else
  PMAToUserBufferCopy(CustomHIDRecvBuffer, ENDP1_RXADDR, CustomHID_RXMAXLEN);
#endif
  SetEPRxStatus(ENDP1, EP_RX_VALID);
#if defined (_LOADER) || defined (_NoRTOSKernel) 
  FSM_SetOn(g_FSM.FLAG_USB_CustomHIDRXED);
#endif
 
}




/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

