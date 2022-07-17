#include <REGX52.H>
#include <INTRINS.H>
void Delay200ms()		//@12.000MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 2;
	j = 134;
	k = 20;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void main()
{
	while(1)
	{
		P2 = 0xFE;//1111 1110
		Delay200ms();
		P2 = 0xFD;//1111 1101
		Delay200ms();
		P2 = 0xFB;//1111 1011
		Delay200ms();
		P2 = 0xF7;//1111 0111
		Delay200ms();
		P2 = 0xEF;//1110 1111
		Delay200ms();
		P2 = 0xDF;//1101 1111
		Delay200ms();
		P2 = 0xBF;//1011 1111
		Delay200ms();
		P2 = 0X7F;
		Delay200ms();
		
	
	
	
	
	
	
	}



}