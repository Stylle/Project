#ifndef __ULN2003_H
#define __ULN2003_H

#include "sys.h"

/**********************************

		  ���ߣ�stylle
		  �޸����ڣ�2020-4-1
		  ˵����ULN2003������������Ķ����ʼ��
		  �汾��V1.0

**********************************/

#define ULN2003_PIN 		GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3
#define ULN2003_GPIO_PORT	GPIOC

#define IN1 PCout(0) 
#define IN2 PCout(1) 
#define IN3 PCout(2) 
#define IN4 PCout(3) 

void ULN2003_Init(void);//��ʼ��
void ULN2003_Task(void);//������������ת
void ULN2003_Left(void);
void ULN2003_Right(void);

#endif

