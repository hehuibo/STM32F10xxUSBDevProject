/*
 ============================================================================
 Name        : USB²Ù×÷º¯Êý.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "usb_desc.h"
#include "usb_lib.h"
#include "usb_pwr.h"
#include "FSM.h"

extern uint32_t VCPRecvLength;
extern uint8_t VCPRecvBuffer[VIRTUAL_COM_PORT_DATA_SIZE];

/*******************************************************************************
* Function Name  : Send DATA .
* Description    : send the data received from the STM32 to the PC through USB  
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
uint32_t CDC_SendData(uint8_t *ptrBuffer, uint8_t slen)
{
  /*if max buffer is Not reached*/
  if(slen < VIRTUAL_COM_PORT_DATA_SIZE)     {
    /*Sent flag*/
    /* send  packet to PMA*/
    UserToPMABufferCopy((unsigned char*)ptrBuffer, ENDP1_TXADDR, slen);
    SetEPTxCount(ENDP1, slen);
    SetEPTxValid(ENDP1);
  }else{
    return 0;
  } 
  return 1;
}

/*******************************************************************************
* Function Name  : Receive DATA .
* Description    : receive the data from the PC to STM32 and send it through USB
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
uint32_t CDC_ReceiveData(void)
{ 
  /*Receive flag*/
  FSM_SetOff(g_FSM.FLAG_USB_VCPRecved);
  SetEPRxValid(ENDP3); 
  return 1 ;
}

void CDC_TestDemo(void)
{
    if (bDeviceState == CONFIGURED)
    {
      CDC_ReceiveData();
      /*Check to see if we have data yet */
      if (VCPRecvLength  != 0)
      {
        //if(FSM_IsOn(g_FSM.FLAG_USB_VCPTxed))
          CDC_SendData((unsigned char*)VCPRecvBuffer,VCPRecvLength);
          VCPRecvLength = 0;
      }
    }
}
