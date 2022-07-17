#include <REGX52.H>
#include "Delay.h"
#include "intrins.h"
sbit Buzzer = P1^5;

void Delay500us()		//@11.0592MHz
{
	unsigned char i;

	_nop_();
	i = 227;
	while (--i);
}

void Buzzer_Time(unsigned int ms)
{
	unsigned int i;
	for(i=0;i<ms*2;i++)
	{
		Buzzer=!Buzzer;  //2ms一个周期，频率就是500HZ.
		Delay500us();

			
			
	}


}
