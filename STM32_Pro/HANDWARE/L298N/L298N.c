#include "L298N.h"
#include "delay.h"
#include "LED.h"


/*初始化端口*/
void L298N_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//使能时钟GPIOA
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//设置输出模式这里“推挽输出”
	GPIO_InitStructure.GPIO_Pin = IN4_PIN | IN4_PIN | IN4_PIN | IN4_PIN;  //设置指定IO口
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //设置速率
	
	GPIO_Init(IN1_PORT,&GPIO_InitStructure);//端口选择
	//GPIO_SetBits(IN1_PORT,IN4_PIN | IN4_PIN | IN4_PIN | IN4_PIN);//设置端口PB7默认为高电平
	//GPIO_ResetBits(GPIOB,GPIO_Pin_7);//设置端口PB7默认为低电平
}
void CAR_1_STOP(void)
{
	CAR_IN1 = 1;CAR_IN2 = 1;
}
void CAR_1_PSTART(void)
{
	CAR_IN1 = 1;CAR_IN2 = 0;
}
void CAR_1_NSTART(void)
{
	CAR_IN1 = 0;CAR_IN2 = 1;
}
void CAR_2_STOP(void)
{
	CAR_IN3 = 1; CAR_IN4 = 1;
}
void CAR_2_PSTART(void)
{
	CAR_IN3 = 1; CAR_IN4 = 0;
}
void CAR_2_NSTART(void)
{
	CAR_IN3 = 0; CAR_IN4 = 1;
}

void Car_Task_temp(void)
{
	delay_init();
	L298N_Init();
	LED_Init();
	while(1)
	{

		CAR_1_PSTART();
		CAR_2_PSTART();
	
	}
}
