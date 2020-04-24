#include "SG90.h"
#include "delay.h"
#include "stm32f10x.h"
#include "KEY.h"
#include "TIM3.h"
#include "usart.h"


void SG90_KEYControl(void)
{
	u8 key;
//	uint16_t num = 30;
	TIM3_Init();
//	Uart_Init(115200);
	delay_init();
	KEY_Init();
	while(1)
	{	
		key = KEY_Scan();
//		if(key == 0)
//		{
//			num+=10;
//			if(num == 200)	num = 0;
//			printf("num = %d\r\t\n",num);
//		}
//		else if(num == 1)
//		{
//			if(num>10)	num-=10;
//			printf("num = %d\r\t\n",num);
//		}
//		TIM_SetCompare2(TIM3, num);
		switch(key)
		{
			case 0:TIM_SetCompare2(TIM3, 237);delay_ms(2500);break;//90°
			case 1:TIM_SetCompare2(TIM3, 231);delay_ms(2500);break;//30°
			case 2:TIM_SetCompare2(TIM3, 225);delay_ms(2500);break;//控制不了不知道为啥
			case 3:TIM_SetCompare2(TIM3, 218);delay_ms(2500);break;//180
		}
		TIM_SetCompare2(TIM3, 242);//0度
//		delay_ms(1000);
//		TIM_SetCompare2(TIM3, 237);//45度
//		delay_ms(1000);
//		TIM_SetCompare2(TIM3, 231);//90度
//		delay_ms(1000);
//		TIM_SetCompare2(TIM3, 225);//135度
//		delay_ms(1000);
//		TIM_SetCompare2(TIM3, 218);//180度
//		delay_ms(1000);
	} 
}


