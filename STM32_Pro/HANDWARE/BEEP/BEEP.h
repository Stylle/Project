#ifndef __BEEP_H
#define __BEEP_H

/**********************************

		  ���ߣ�stylle
		  �޸����ڣ�2020-4-1
		  ˵�����������Ķ����ʼ��
		  �汾��V1.0

**********************************/
#define BEEP_PIN  		GPIO_Pin_7
#define BEEP_GPIO_PORT  GPIOB

#define BEEP PBout(7) //�����Ϳ���ֱ�Ӳ���led1

void BEEP_Init(void);//��������ʼ��
void BEEP_Task(unsigned int nums);//���������Գ���

#endif
