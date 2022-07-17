#include <REGX52.H>
#include "Delay.h"
/**
   *  @brief 串口初始化 
   *  @param 无
   *  @retval 无
   */
void Uart_Init()		//4800bps@11.0592MHz
{
	PCON |= 0x80;		//????????SMOD
	SCON = 0x40;		//8???,?????
	TMOD &= 0x0F;		//???????
	TMOD |= 0x20;		//???????
	TL1 = 0xF4;		//???????
	TH1 = 0xF4;		//???????
	ET1 = 0;		//?????%d??
	TR1 = 1;		//???1????
}
/**
   *  @brief 串口发送一个字节数据
   *  @param Byte要发送的一个字节数据
   *  @retval 无
   */
void SendByte(unsigned char Byte)
{
	SBUF = Byte ;
	while(TI==0);
	TI=0;


}
