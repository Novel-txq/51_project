#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"
#include "LCD1602.h"
unsigned int Sec ;				
unsigned int Min ;
unsigned int Hour ;
void main()
{
	LCD_Init();							//LCDҲҪ��ʼ��
	Timer0_Init();
	LCD_ShowString(1,1,"CLOCK");
	LCD_ShowString(2,3,":");				//:���ַ�������ʽ
	LCD_ShowString(2,6,":");
	while(1)
	{
		LCD_ShowNum(2,1,Hour,2);
		LCD_ShowNum(2,4,Min,2);
		LCD_ShowNum(2,7,Sec,2);
			
	
	}

}


void Timer0_Routine()   interrupt 1 
{
	static unsigned int count;					//����ڴ˴�����Sec��Min��Hour��ӡ����������������0
	TL0 = 0x18;		//??????
	TH0 = 0xFC;		//??????

	count++;
	if(count >= 1000)
	{
		count = 0;
		Sec++;
		if(Sec >= 60)
		{
			Sec = 0;
			Min++;
			if(Min >= 60)
			{
				
			
			}
		
		}
	}

}
