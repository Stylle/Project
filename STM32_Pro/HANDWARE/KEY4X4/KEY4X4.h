#ifndef __KEY4X4_H
#define __KEY4X4_H

/**********************************

		  作者：stylle
		  修改日期：2020-4-1
		  说明：矩阵键盘的定义初始化
		  版本：V1.0

**********************************/

#include "sys.h"
#include "delay.h"

//行的GPPIO_PIN和GPIOx设置
#define KEY4X4_H_PIN 			GPIO_Pin_1 | GPIO_Pin_3 | GPIO_Pin_13 | GPIO_Pin_15
#define KEY4X4_H_GPIO_PORT 		GPIOC

//列的GPPIO_PIN和GPIOx设置
#define KEY4X4_L_PIN 			GPIO_Pin_1 | GPIO_Pin_3 | GPIO_Pin_5 | GPIO_Pin_7
#define KEY4X4_L_GPIO_PORT 		GPIOA

//行线
#define KEY4X4_H0	PCout(13) 
#define KEY4X4_H1	PCout(15)
#define KEY4X4_H2	PCout(1)     
#define KEY4X4_H3	PCout(3)     
//列线
#define KEY4X4_L0	PAin(1)     
#define KEY4X4_L1	PAin(3)      
#define KEY4X4_L2	PAin(5)     
#define KEY4X4_L3	PAin(7)//上拉输入读取时应用PXin（x）

#define KEY4X4_NOPRESS  0XFF//没有按键按下的时候返回的值

void KEY4X4_Init(void);//独立按键初始化
u8 	 KEY4X4_Scan(void);//按键读取
//void KEY4X4_WaitUp(void);//检测按键弹起（消抖）
void KEY4x4_LEDControl(void);//按键控制led开关

#endif

