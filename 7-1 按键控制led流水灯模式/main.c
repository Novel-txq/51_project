#include <REGX52.H>
#include "Timer0.h"
#include "Key.h"
#include <INTRINS.H>
unsigned char KeyNumber;
unsigned char LEDMode = 0;

void main()
{
	P2 = 0xFE;
	Timer0_Init();
	while(1)
	{
		KeyNumber = Key();						//通过LEDMode改变流水灯流向
		if(KeyNumber)
		{
			if(KeyNumber==1)
			{
				LEDMode++;
				if(LEDMode >= 2)
				{
					LEDMode = 0;
				
				}
			
			}
		
		}
	
	
	
	}


}
unsigned int count = 0;
void Timer0_Routine()   interrupt 1
{
	TL0 = 0x18;		
	TH0 = 0xFC;		

	count++;
	if(count >= 500)	//间隔500ms
	{
		count = 0;
		if(LEDMode==0)
		{
			P2 = _crol_(P2,1);
		}
		if(LEDMode==1)
		{
			P2 = _cror_(P2,1);
		}
		
	}
		


}
