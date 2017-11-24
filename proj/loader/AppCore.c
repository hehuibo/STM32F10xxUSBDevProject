#include "main.h"

#define FSM_TIMEOUT_1S      100
uint16_t g_uiDelay1S = FSM_TIMEOUT_1S;

/****状态机*****/
volatile xTGlobalFsm_t g_FSM;

/***初始化芯片内部资源***/
static void InitChipInternal(void)
{
  vGPIO_Configure();

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

}
/*********************1STask****************************/
void vDelay1STask(void)
{
  if(FSM_IsOff(g_FSM.FSM_TASK_DELAY1S)){
    return;
  }  
  FSM_SetOff(g_FSM.FSM_TASK_DELAY1S);
}

/***************MainTask*************************/
void vMainTask(void)
{
 
}

/**任务**/
const pfnFsmFUNCTION_t g_fnAppTaskAry = {
  vDelay10MSTask,
  vDelay1STask,
  vMainTask
};