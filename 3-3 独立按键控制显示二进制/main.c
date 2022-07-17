#include <REGX52.H>
void Delay(unsigned int xms)		//@12.000MHz
{
	while(xms)
	{
		unsigned char i, j;

		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}
}

void main()
{
	int num = 0;
	while(1)
	{
		if(P3_0 == 0)
		{
			Delay(20);
			while(P3_0 == 0);
			Delay(20);
			num++;
			P2 = ~num;
			
		
		
		}
	
	
	}



}