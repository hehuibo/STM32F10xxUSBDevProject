#ifndef _MAIN_H
#define _MAIN_H


#if defined (_LOADER) || defined (_NoRTOSKernel) 
#include "FSM.h"
#else
#include "TypesCfg.h"
#endif

#include "stm32f10x.h"

#include "GPIO.h"
#include "hw_config.h"

#include "StartUpCfg.h"

#if defined (_LOADER) || defined (_NoRTOSKernel) 
#define MAX_FUNCITEM 3

typedef void(*pfnFsmFUNCTION_t[])(void);
extern const pfnFsmFUNCTION_t g_fnAppTaskAry;
/******Task******/
void AppTaskInit(void);
#endif

#endif
