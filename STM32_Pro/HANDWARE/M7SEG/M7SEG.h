#ifndef _M7SEG_H
#define _M7SEG_H

/**********************************

		  ���ߣ�stylle
		  �޸����ڣ�2020-4-1
		  ˵������λ����ܶ����ʼ��
		  �汾��V1.0

**********************************/
#include "sys.h"
//����ܶ�PIN��GPIOx����
#define M7SEG_PORT_PIN		GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7
#define M7SEG_GPIO_PORT		GPIOA

//�����λѡPIN��GPIOx����
#define M7SEG_BIT_PIN		GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_10|GPIO_Pin_11
#define M7SEG_BIT_PORT		GPIOB

#define M7SEG_PORT GPIOA->ODR

#define M7SEG_BIT1 PBout(0)
#define M7SEG_BIT2 PBout(1)
#define M7SEG_BIT3 PBout(10)
#define M7SEG_BIT4 PBout(11)

void M7SEG_Port_Init(void);//��led��ʼ��
void M7SEG_Bit_Init(void);//λѡ��ʼ��
void M7SEG_Init(void);//����ܳ�ʼ��
void M7SEG_Display(void);//�������ʾ
void IRQ_M7SEG_Clock(void);//ʱ��

#endif

