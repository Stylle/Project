#ifndef __TTP223_H
#define __TTP223_H

/**********************************

		  ���ߣ�stylle
		  �޸����ڣ�2020-4-1
		  ˵����TTP2223ģ�鶨���ʼ��
		  �汾��V1.0

**********************************/

#include "stm32f10x.h"
#include "sys.h"

#define IC_KEY_PIN 		GPIO_Pin_14
#define ICKEY_GPIO_PORT GPIOC

#define IC_EKY PCin(14) 

void TTP223_Init(void);
u8 	 TTP223_Scan(void);//������������ֵ
void IC_KEY_LED(void);

#endif
