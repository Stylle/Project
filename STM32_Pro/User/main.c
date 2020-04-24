/**********************************

		  作者：stylle
		  修改日期：2020-4-1
		  说明：主程序的调用的主文件
		  版本：V1.0

**********************************/

#include "stm32f10x.h"
#include "delay.h"
#include "LED.h"
//#include "BEEP.h"
#include "KEY.h"
//#include "ESP8266.h"
//#include "KEY4X4.h"
//#include "TTP223.h"
//#include "SG90.h"
//#include "ULN2003.h"
//#include "m7seg.h"
#include "L298N.h"
#include "oled.h"

int main(void)
{	
	//BEEP_Task(10);			//蜂鸣器的测试程序
	//LED_Task();				//LED的测试程序
	//KEY_TaskLed();			//按键控制LED灯
	//Uart_LED_Task();			//串口与led
	//ESP_LED_Control();		//ESP8266控制led
	//KEY4x4_LEDControl();		//偶数按键开灯
	//IC_KEY_LED();				//触摸开关开灯实验
	//LEDBreathing_Lamp();		//呼吸灯实验
	//SG90_KEYControl();		//按键控制舵机转向
	//ULN2003_Task();			//按键控制步进电机
	//IRQ_M7SEG_Clock();		//定时器刷新数码管显示时钟
	//Car_Task_temp();			//小车实验 ERROR ERROR ERROR ERROR ERROR
	//Oled_Task();				//OLED显示实验
	KEY_UART();				//发送按键状态到串口
}
