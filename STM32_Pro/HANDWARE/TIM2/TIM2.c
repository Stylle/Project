#include "TIM2.h"
#include "stm32f10x.h"
#include "LED.h"


//定时器2中断服务程序		    
void TIM2_IRQHandler(void)
{ 	
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)//是更新中断
	{	 
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update  );  //清除TIM2更新中断标志    
		//TIM_Cmd(TIM2, DISABLE);  //关闭TIM7 
	}	    
}
//通用定时器2中断初始化，这里时钟选择为APB1的2倍
//arr：自动重装值 psc：时钟预分频数
//定时器溢出时间计算方法:Tout=((arr+1)*(psc+1))/Ft us.
//Ft=定时器工作频率,单位:Mhz 
//通用定时器中断初始化 

void TIM2_Init(u16 arr,u16 psc)
{	
//	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	TIM_OCInitTypeDef TIM_OCInitStructure;//根据TIM_OCInitStruct中指定的参数初始化外设TIMx

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);//TIM2时钟使能    
	
	//定时器TIM2初始化
	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //根据指定的参数初始化TIMx的时间基数单位
 
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE ); //使能指定的TIM2中断,允许更新中断
	
	TIM_Cmd(TIM2,ENABLE);//开启定时器2
	
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM2,ENABLE);//改变指定管脚的映射	//pC6

	//PWM初始化	  //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;//PWM输出使能
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_Low;

	TIM_OC1Init(TIM2,&TIM_OCInitStructure);
	//注意此处初始化时TIM_OC1Init而不是TIM_OCInit，否则会出错。因为固件库的版本不一样。
	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);//使能或者失能TIMx在CCR1上的预装载寄存器
	TIM_Cmd(TIM2,ENABLE);//使能或者失能TIMx外设	
}



