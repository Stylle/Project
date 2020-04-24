#ifndef __KEY_H
#define __KEY_H

/**********************************

		  作者：stylle
		  修改日期：2020-4-1
		  说明：独立按键的定义初始化
		  版本：V1.0

**********************************/
#include "sys.h"

#define KEY_IPU_PIN GPIO_Pin_8|GPIO_Pin_6							//上拉输入按键
#define KEY_IPD_PIN GPIO_Pin_12|GPIO_Pin_14							//下拉输入按键

#define KEY0 GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6)				//读取按键状态
#define KEY1 GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_8)
#define KEY2 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)
#define KEY3 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14)

void KEY_Init(void);	//独立按键初始化
u8 KEY_Scan(void);		//按键读取
void KEY_TaskLed(void);	//按键控制led灯
void KEY_UART(void); 	//发送按键状态到串口

#endif
