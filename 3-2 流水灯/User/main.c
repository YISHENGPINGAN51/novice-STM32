#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	while (1)
	{
		GPIO_Write(GPIOA, ~0x0001);	//0000 0000 0000 0001
		Delay_ms(500);
		GPIO_Write(GPIOA, ~0x0002);	//0000 0000 0000 0010
		Delay_ms(500);
		GPIO_Write(GPIOA, ~0x0004);	//0000 0000 0000 0100
		Delay_ms(500);
		GPIO_Write(GPIOA, ~0x0008);	//0000 0000 0000 1000
		Delay_ms(500);
		GPIO_Write(GPIOA, ~0x0010);	//0000 0000 0001 0000
		Delay_ms(500);
		GPIO_Write(GPIOA, ~0x0020);	//0000 0000 0010 0000
		Delay_ms(500);
		GPIO_Write(GPIOA, ~0x0040);	//0000 0000 0100 0000
		Delay_ms(500);
		GPIO_Write(GPIOA, ~0x0080);	//0000 0000 1000 0000
		Delay_ms(500);
		
//		GPIO_ResetBits(GPIOA, GPIO_Pin_0);
//		Delay_ms(500);
//		GPIO_SetBits(GPIOA, GPIO_Pin_0);
//		Delay_ms(500);
//		
//		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
//		Delay_ms(500);
//		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
//		Delay_ms(500);
//		
//		GPIO_WriteBit(GPIOA, GPIO_Pin_0, (BitAction)0);
//		Delay_ms(500);
//		GPIO_WriteBit(GPIOA, GPIO_Pin_0, (BitAction)1);
//		Delay_ms(500);
	}
}

//总结：推挽输出PP：低电平高电平点亮都OK	开漏输出OD：低电平点亮OK，高电平点亮不OK
