#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "Matrixkey.h"
unsigned char KeyNum;
unsigned int password;
unsigned int x;
unsigned int count = 0;
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"password");
	while(1)
	{
		KeyNum = Matrixkey();
		if(KeyNum)
		{
			if(count < 4)//如果输入次数小于4
			{
				if(KeyNum <= 10)
				{
					x = KeyNum%10;
					password = password*10+x;
					count++;
					LCD_ShowNum(2,1,password,4);
			
			
				}
			}
			if(KeyNum==11)
			{
				if(password==1234)
				{
					LCD_ShowString(1,10,"OK");
					password = 0;						//清零
					count = 0;
				
				}
				else
				{
					LCD_ShowString(1,10,"ERR");
					password = 0;
					count = 0;
				
				}
				
			
			
			}
			if(KeyNum==12)
			{
				password = 0;
				count = 0;
			
			}

		
		}
	
	
	}



}