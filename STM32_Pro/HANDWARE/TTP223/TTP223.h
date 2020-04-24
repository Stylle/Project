#ifndef __TTP223_H
#define __TTP223_H

/**********************************

		  作者：stylle
		  修改日期：2020-4-1
		  说明：TTP2223模块定义初始化
		  版本：V1.0

**********************************/

#include "stm32f10x.h"
#include "sys.h"

#define IC_KEY_PIN 		GPIO_Pin_14
#define ICKEY_GPIO_PORT GPIOC

#define IC_EKY PCin(14) 

void TTP223_Init(void);
u8 	 TTP223_Scan(void);//触摸按键返回值
void IC_KEY_LED(void);

#endif
