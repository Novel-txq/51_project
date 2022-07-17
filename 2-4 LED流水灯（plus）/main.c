#include <REGX52.H>
#include <INTRINS.H>
void Delay1ms(int s)		//@12.000MHz
{
	int i = 0;
	for(i = 0;i < s;i++)
	{
			unsigned char i, j;

		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}

	
	
}


void main()
{

	while(1)
	{
		P2 = 0xFE;//1111 1110
		Delay1ms(100);
		P2 = 0xFD;//1111 1101
		Delay1ms(200);
		P2 = 0xFB;//1111 1011
		Delay1ms(300);
		P2 = 0xF7;//1111 0111
		Delay1ms(400);
		P2 = 0xEF;//1110 1111
		Delay1ms(500);
		P2 = 0xDF;//1101 1111
		Delay1ms(600);
		P2 = 0xBF;//1011 1111
		Delay1ms(700);
		P2 = 0X7F;
		Delay1ms(800);
		
	
	
	
	
	
	
	}



}