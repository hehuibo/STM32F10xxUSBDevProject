/****************************************************************************************
*
*               È«¾Ö×´Ì¬»ú
*/
#ifndef _FSM_H
#define _FSM_H

#include "TypesCfg.h"

#if defined (_LOADER) || defined (_NoRTOSKernel)
typedef struct _tag_GlobalFsmTYPE
{
  unsigned int FSM_TASK_DELAY10MS           : 1;
  unsigned int FSM_TASK_DELAY1S             : 1;
  unsigned int FLAG_USART1RXED              : 1;
  unsigned int FLAG_USB_CustomHIDRXED       : 1;
  unsigned int FLAG_USB_VCPRecved           : 1;
  unsigned int FLAG_USB_VCPTxed             : 1;
  
}xTGlobalFsm_t;

extern volatile xTGlobalFsm_t g_FSM;

#define FSM_IsOn(x)     x==true ? true : false  
#define FSM_IsOff(x)    x==true ? false :true	

#define FSM_SetOn(x)    x = true
#define FSM_SetOff(x)   x = false

#endif

enum tag_eAppCommMsgIDTYPE
{
  eAppCommMsgID_NONE,
  eAppCommMsgID_USART3,
  eAppCommMsgID_UART4,
};

#define APPDATABUF_MAX_LEN     256+16
struct _tag_AppCommBufferTYPE
{
  uint16_t mCnt;
  uint16_t mRxLen;
  uint16_t mRxMax;
  uint16_t mTxLen;
  uint8_t mTimeOut;
  uint8_t *pRxBfr;
  uint8_t *pTxBfr;
  enum tag_eAppCommMsgIDTYPE mMsgID;
};
extern struct _tag_AppCommBufferTYPE    g_AppCommBfrMnt;

void AppCommBufferInit(void);

uint16_t getAppCommBufferMaxLen(void);

#endif
