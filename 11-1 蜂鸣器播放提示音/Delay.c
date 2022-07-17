#include <intrins.h>
//延时子函数
void Delay(unsigned int xms)
{
	unsigned char i, j;
	while(xms--)
	{
		_nop_();
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}

