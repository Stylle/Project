#ifndef __BEEP_H
#define __BEEP_H

/**********************************

		  作者：stylle
		  修改日期：2020-4-1
		  说明：蜂鸣器的定义初始化
		  版本：V1.0

**********************************/
#define BEEP_PIN  		GPIO_Pin_7
#define BEEP_GPIO_PORT  GPIOB

#define BEEP PBout(7) //这样就可以直接操作led1

void BEEP_Init(void);//蜂鸣器初始化
void BEEP_Task(unsigned int nums);//蜂鸣器测试程序

#endif
