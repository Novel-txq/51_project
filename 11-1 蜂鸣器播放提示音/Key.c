#include <REGX52.H>
#include "Delay.h"
unsigned char Key()
{
	unsigned char Keynumber=0;
	if(P3_1==0){Delay(20);while(P3_1==0);Delay(20);Keynumber = 1;}
	if(P3_0==0){Delay(20);while(P3_1==0);Delay(20);Keynumber = 2;}
	if(P3_2==0){Delay(20);while(P3_1==0);Delay(20);Keynumber = 3;}
	if(P3_3==0){Delay(20);while(P3_1==0);Delay(20);Keynumber = 4;}
	return Keynumber;



}