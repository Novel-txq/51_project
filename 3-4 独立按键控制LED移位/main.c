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

//void main()
//{
//	int num = 1;
//	while(1)
//	{

//			if(P3_0 == 0)
//			{
//				Delay(20);
//				while(P3_0 == 0);
//				Delay(20);
//				P2 = ~num ;
//				num = num << 1;
//			}
//			if(num >= 256)
//			{
//				num = 1;
//			
//			
//			}
//			
//		
//		
//		}
//	
//	
//	



//}
void main()
{
	int num = 0;
	P2 = ~0x01;
	while(1)
	{
		if(P3_1 == 0)
		{
			Delay(20);
			while(P3_1 == 0);
			Delay(20);
			
			if(num == 8)
			{
				num = 0;
			
			
			}
			else
			{
				num++;
			
			}
			P2 = ~(0x01 << num);

		
		
		
		}
		if(P3_0 == 0)
		{
			Delay(20);
			while(P3_0 == 0);
			Delay(20);		
			if(num == 0)
			{
				num = 7;
			
			}
			else
			{
				num--;
			
			}
			P2 = ~(0x01 << num);

		
		
		
		}
	
	}
}