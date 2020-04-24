#ifndef __KEY_H
#define __KEY_H

/**********************************

		  ���ߣ�stylle
		  �޸����ڣ�2020-4-1
		  ˵�������������Ķ����ʼ��
		  �汾��V1.0

**********************************/
#include "sys.h"

#define KEY_IPU_PIN GPIO_Pin_8|GPIO_Pin_6							//�������밴��
#define KEY_IPD_PIN GPIO_Pin_12|GPIO_Pin_14							//�������밴��

#define KEY0 GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6)				//��ȡ����״̬
#define KEY1 GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_8)
#define KEY2 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)
#define KEY3 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14)

void KEY_Init(void);	//����������ʼ��
u8 KEY_Scan(void);		//������ȡ
void KEY_TaskLed(void);	//��������led��
void KEY_UART(void); 	//���Ͱ���״̬������

#endif
