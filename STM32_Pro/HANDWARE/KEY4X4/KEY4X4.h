#ifndef __KEY4X4_H
#define __KEY4X4_H

/**********************************

		  ���ߣ�stylle
		  �޸����ڣ�2020-4-1
		  ˵����������̵Ķ����ʼ��
		  �汾��V1.0

**********************************/

#include "sys.h"
#include "delay.h"

//�е�GPPIO_PIN��GPIOx����
#define KEY4X4_H_PIN 			GPIO_Pin_1 | GPIO_Pin_3 | GPIO_Pin_13 | GPIO_Pin_15
#define KEY4X4_H_GPIO_PORT 		GPIOC

//�е�GPPIO_PIN��GPIOx����
#define KEY4X4_L_PIN 			GPIO_Pin_1 | GPIO_Pin_3 | GPIO_Pin_5 | GPIO_Pin_7
#define KEY4X4_L_GPIO_PORT 		GPIOA

//����
#define KEY4X4_H0	PCout(13) 
#define KEY4X4_H1	PCout(15)
#define KEY4X4_H2	PCout(1)     
#define KEY4X4_H3	PCout(3)     
//����
#define KEY4X4_L0	PAin(1)     
#define KEY4X4_L1	PAin(3)      
#define KEY4X4_L2	PAin(5)     
#define KEY4X4_L3	PAin(7)//���������ȡʱӦ��PXin��x��

#define KEY4X4_NOPRESS  0XFF//û�а������µ�ʱ�򷵻ص�ֵ

void KEY4X4_Init(void);//����������ʼ��
u8 	 KEY4X4_Scan(void);//������ȡ
//void KEY4X4_WaitUp(void);//��ⰴ������������
void KEY4x4_LEDControl(void);//��������led����

#endif

