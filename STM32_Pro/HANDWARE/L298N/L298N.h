#ifndef _L298N_H
#define _L298N_H

/**********************************

		  ���ߣ�stylle
		  �޸����ڣ�2020-4-1
		  ˵����L298N˫�������ģ�鶨���ʼ��
		  �汾��V1.0

**********************************/

#include "sys.h"
#include "stm32f10x.h"

#define IN1_PORT  GPIOA
#define IN1_PIN   GPIO_Pin_0
#define IN2_PORT  GPIOA
#define IN2_PIN   GPIO_Pin_1
#define IN3_PORT  GPIOA
#define IN3_PIN   GPIO_Pin_2
#define IN4_PORT  GPIOA
#define IN4_PIN   GPIO_Pin_3

#define CAR_IN1 PAout(0)
#define CAR_IN2 PAout(1)
#define CAR_IN3 PAout(2)
#define CAR_IN4 PAout(3)

/**�˿ڷֱ���PB5-8**/

void CAR_1_STOP(void);		//����ֹͣ

void CAR_1_PSTART(void);	//����1��ת

void CAR_1_NSTART(void);	//����1��ת

void CAR_2_STOP(void);		//����2ֹͣ

void CAR_2_PSTART(void);	//����2��ת

void CAR_2_NSTART(void);	//����2��ת

void Car_Task_temp(void);		//����

#endif

