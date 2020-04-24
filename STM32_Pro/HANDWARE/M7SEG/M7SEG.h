#ifndef _M7SEG_H
#define _M7SEG_H

/**********************************

		  作者：stylle
		  修改日期：2020-4-1
		  说明：四位数码管定义初始化
		  版本：V1.0

**********************************/
#include "sys.h"
//数码管段PIN与GPIOx设置
#define M7SEG_PORT_PIN		GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7
#define M7SEG_GPIO_PORT		GPIOA

//数码管位选PIN与GPIOx设置
#define M7SEG_BIT_PIN		GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_10|GPIO_Pin_11
#define M7SEG_BIT_PORT		GPIOB

#define M7SEG_PORT GPIOA->ODR

#define M7SEG_BIT1 PBout(0)
#define M7SEG_BIT2 PBout(1)
#define M7SEG_BIT3 PBout(10)
#define M7SEG_BIT4 PBout(11)

void M7SEG_Port_Init(void);//段led初始化
void M7SEG_Bit_Init(void);//位选初始化
void M7SEG_Init(void);//数码管初始化
void M7SEG_Display(void);//数码管显示
void IRQ_M7SEG_Clock(void);//时钟

#endif

