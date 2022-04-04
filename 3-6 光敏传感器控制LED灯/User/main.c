#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "LightSensor.h"

uint8_t KeyNum;

int main(void)
{
	LED_Init();
	LightSensor_Init();
	
	while (1)
	{
		if (LightSensor_Get() == 1)
		{
			LED1_ON();
		}
		else
		{
			LED1_OFF();
		}
	}
}
