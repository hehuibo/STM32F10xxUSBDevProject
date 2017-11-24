#include "StartUpCfg.h"
#if  defined(_uCosII_Kernel) 
#include  <os.h>
#elif defined (_LOADER) || defined (_NoRTOSKernel)
#include "FSM.h"
#endif


void ReBoot(enum BOOTMODECMD Mode)
{
  //struct BootMessage *bootmsg = ();
  {
    //bootmsg->bootcmd = Mode;
  }
  
  __set_FAULTMASK(1);
  NVIC_SystemReset();
}

void vStartUpConfigure(void)
{

  /* Set the Vector Table base location */
#ifdef _LOADER
  NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0);
#else
  NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0);
#endif
  
  /* Set the NVIC PriorityGroup */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);

  /* Set the SysTick */
#if defined (_LOADER) || defined (_NoRTOSKernel)
  RCC_ClocksTypeDef  rcc_clocks;  
  RCC_GetClocksFreq(&rcc_clocks); 

  SysTick_Config(rcc_clocks.SYSCLK_Frequency / 1000); /*    1Ms      */
  
  AppCommBufferInit();

#endif
  
#if defined(STemWin_GUI)
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_CRC,ENABLE);    
#endif
     
}

#if defined (_LOADER) || defined (_NoRTOSKernel)

volatile static uint32_t SysTickCnt = 0;

void SysTick_Handler(void)
{
  static int tickCnt_10MS = 0;
  
  SysTickCnt ++;
  if(++tickCnt_10MS >= 10)
  {
    FSM_SetOn(g_FSM.FSM_TASK_DELAY10MS);
    tickCnt_10MS = 0;//10MS
  }  
}

uint32_t xGetTickCount(void)
{
  return SysTickCnt;
}

void SysTickDlyMs(uint32_t ms)
{
	uint32_t t,t1;
	
	t = xGetTickCount();
	while(1)
	{
		t1 = xGetTickCount() - t;
		if(t1 >= ms)
		{
			break;
		}
	}
	
}

#endif
