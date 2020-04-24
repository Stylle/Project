#ifndef _L298N_H
#define _L298N_H

/**********************************

		  作者：stylle
		  修改日期：2020-4-1
		  说明：L298N双电机驱动模块定义初始化
		  版本：V1.0

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

/**端口分别是PB5-8**/

void CAR_1_STOP(void);		//车轮停止

void CAR_1_PSTART(void);	//车轮1正转

void CAR_1_NSTART(void);	//车轮1反转

void CAR_2_STOP(void);		//车轮2停止

void CAR_2_PSTART(void);	//车轮2正转

void CAR_2_NSTART(void);	//车轮2反转

void Car_Task_temp(void);		//测试

#endif

