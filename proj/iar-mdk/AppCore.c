#include "main.h"

#define FSM_TIMEOUT_1S      100
uint16_t g_uiDelay1S = FSM_TIMEOUT_1S;

/****状态机*****/
volatile xTGlobalFsm_t g_FSM;

/***初始化芯片内部资源***/
static void InitChipInternal(void)
{
  vGPIO_Configure();

  USB_Configure();
}

/***初始化外围设备***/
static void InitBoardPeripheral(void)
{ 
}


static void AppTargetInit(void)
{
  vStartUpConfigure();
}

/*
 ============================================================================
		初始化
 ============================================================================
 */
void AppTaskInit(void)
{
  AppTargetInit();
  
  /***初始化芯片内部资源***/
  InitChipInternal();
  
  /***初始化外围设备***/
  InitBoardPeripheral();  
  
}

/*
 ============================================================================
		轮训任务
 ============================================================================
 */
/*******************10MSTask**************************/
void vDelay10MSTask(void)
{
  if(FSM_IsOff(g_FSM.FSM_TASK_DELAY10MS)){
    return;
  }  
  FSM_SetOff(g_FSM.FSM_TASK_DELAY10MS);
	
  if((g_uiDelay1S >0 )&&(--g_uiDelay1S == 0)){
    FSM_SetOn(g_FSM.FSM_TASK_DELAY1S);
    g_uiDelay1S = FSM_TIMEOUT_1S;
  }
  
  if((g_AppCommBfrMnt.mTimeOut > 0) && (--g_AppCommBfrMnt.mTimeOut == 0)){
    g_AppCommBfrMnt.mRxLen = g_AppCommBfrMnt.mCnt;
    g_AppCommBfrMnt.mCnt = 0;
    g_AppCommBfrMnt.mTimeOut = 0;
    FSM_SetOn(g_FSM.FLAG_USART1RXED);	
  }

}


/*********************1STask****************************/
void vDelay1STask(void)
{
  if(FSM_IsOff(g_FSM.FSM_TASK_DELAY1S)){
    return;
  }  
  FSM_SetOff(g_FSM.FSM_TASK_DELAY1S);
  #if defined (UART_TRACE) || defined (JLINK_RTT_TRACE)
  dbgTRACE_FUNCTION();
  #endif   
}

/***************MainTask*************************/

void vMainTask(void)
{
  uint8_t USBRcvBfr[CustomHID_RXMAXLEN];
  if(FSM_IsOn(g_FSM.FLAG_USART1RXED)){
    FSM_SetOff(g_FSM.FLAG_USART1RXED);	
    #if defined (UART_TRACE) || defined (JLINK_RTT_TRACE)
    dbgTRACE("RxBuffer[0]:%c\n", g_AppCommBfrMnt.pRxBfr[0]);
    #endif 
  }
  if(FSM_IsOn(g_FSM.FLAG_USB_CustomHIDRXED)){	
    FSM_SetOff(g_FSM.FLAG_USB_CustomHIDRXED);
    USBCustomHID_GetRecvBufferData(USBRcvBfr, sizeof(USBRcvBfr));
    USBCustomHID_SendBufferData(USBRcvBfr, CustomHID_RXMAXLEN);
  }
}

/**任务**/
const pfnFsmFUNCTION_t g_fnAppTaskAry = {
  vDelay10MSTask,
  vDelay1STask,
  vMainTask
};