/**********************************

		  ���ߣ�stylle
		  �޸����ڣ�2020-4-1
		  ˵����������ĵ��õ����ļ�
		  �汾��V1.0

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
	//BEEP_Task(10);			//�������Ĳ��Գ���
	//LED_Task();				//LED�Ĳ��Գ���
	//KEY_TaskLed();			//��������LED��
	//Uart_LED_Task();			//������led
	//ESP_LED_Control();		//ESP8266����led
	//KEY4x4_LEDControl();		//ż����������
	//IC_KEY_LED();				//�������ؿ���ʵ��
	//LEDBreathing_Lamp();		//������ʵ��
	//SG90_KEYControl();		//�������ƶ��ת��
	//ULN2003_Task();			//�������Ʋ������
	//IRQ_M7SEG_Clock();		//��ʱ��ˢ���������ʾʱ��
	//Car_Task_temp();			//С��ʵ�� ERROR ERROR ERROR ERROR ERROR
	//Oled_Task();				//OLED��ʾʵ��
	KEY_UART();				//���Ͱ���״̬������
}
