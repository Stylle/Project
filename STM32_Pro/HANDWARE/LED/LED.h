#ifndef __LED_H
#define __LED_H

/**********************************

		  ���ߣ�stylle
		  �޸����ڣ�2020-4-1
		  ˵����LED�Ķ����ʼ��
		  �汾��V1.0

**********************************/
#include "sys.h"

#define LED_PIN  		GPIO_Pin_5|GPIO_Pin_7
#define LED_GPIO_PORT   GPIOB

#define LED1 PBout(5) //�����Ϳ���ֱ�Ӳ���led1
#define LED2 PBout(7) //�����Ϳ���ֱ�Ӳ���led1

void LED_Init(void);//LED��ʼ��
void LED_Task(void);//����Ƴ���
void Uart_LED_Task(void);//����LED
void LED_ON(u16 ch);
void LED_OFF(u16 ch);
void LEDBreathing_Lamp(void);//������

#endif

