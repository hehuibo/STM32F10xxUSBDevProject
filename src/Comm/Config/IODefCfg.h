/*
 * IODefCfg.h
 *  板级IO口配置
 *  Created on: 20IODefCfg年x月x日
 *      Author: HeHuiBo
 */

#ifndef IODefCfg_H_
#define IODefCfg_H_

#include "stm32f10x.h"

/*LED引脚配置*/
#define LED0_PORT_CLK    RCC_APB2Periph_GPIOA
#define LED0_PORT        GPIOA
#define LED0_PIN_BIT     GPIO_Pin_0

#define LED0_PORT_CLK    RCC_APB2Periph_GPIOA
#define LED0_PORT        GPIOA
#define LED0_PIN_BIT     GPIO_Pin_1

#define BEEP_PORT_CLK    RCC_APB2Periph_GPIOA
#define BEEP_PORT        GPIOA
#define BEEP_PIN_BIT     GPIO_Pin_8

#endif /* IODefCfg_H_ */
