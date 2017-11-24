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
#include <string.h>

extern uint8_t CustomHIDRecvBuffer[CustomHID_RXMAXLEN];
extern uint8_t CustomHIDSendBuffer[CustomHID_TXMAXLEN];

uint32_t USBCustomHID_SendBufferData(uint8_t *pData, uint32_t TxLen)
{
  USB_SIL_Write(EP1_IN, pData, CustomHID_TXMAXLEN);  
  SetEPTxValid(ENDP1);
  return TxLen;
}

uint32_t USBCustomHID_GetRecvBufferData(uint8_t *pData, uint32_t count)
{
  if(count > sizeof(CustomHIDRecvBuffer)){
    count = sizeof(CustomHIDRecvBuffer);
  }
  memcpy(pData, CustomHIDRecvBuffer, count);
  
  return count;
}

/*******************************************************************************
* Function Name : USBKeyBoard_SendData
* Description   : prepares buffer to be sent containing Joystick event infos.
* Input         : Keys: keys received from terminal.
* Output        : None.
* Return value  : None.
*******************************************************************************/
/*
0-9, Enter
*/
const uint8_t KBCodeTBL[11] = {0x27, 0x1E, 0x1F,
                             0x20, 0x21, 0x22, 
                             0x23, 0x24, 0x25, 
                             0x26, 0x28};
void USBKeyBoard_SendData(uint8_t data)
{
  uint8_t kbBuffer[KEYBOARD_TXMAXLEN] = {0, 0, 0, 0, 0, 0, 0, 0};
    
  kbBuffer[2]= data;

  USB_SIL_Write(EP2_IN, kbBuffer, KEYBOARD_TXMAXLEN);  
  SetEPTxValid(ENDP2);
  while(GetEPTxStatus(ENDP2) == EP_TX_VALID);
}


void USBKeyBoard_SendCardSnr(uint32_t mCardNoSnr)
{
  uint8_t CardCodeTbl[PUTNUMMAX_CARDSNR + 2];
  uint32_t value = mCardNoSnr;
  for(int i=9; i>=0 ;i--){
    CardCodeTbl[i] = KBCodeTBL[(value%10)];
    value = value/10;
  }
  
  CardCodeTbl[PUTNUMMAX_CARDSNR] = KBCodeTBL[PUTNUMMAX_CARDSNR];//Enter
  CardCodeTbl[PUTNUMMAX_CARDSNR+1] = 0;

  for(int i=0; i<(PUTNUMMAX_CARDSNR + 2); i++){
    USBKeyBoard_SendData(CardCodeTbl[i]);
  }
}

