#include <REGX52.H>
#include <Delay.h>
//引脚定义
sbit DS1302_SCLK = P3^6;
sbit DS1302_IO = P3^4;
sbit DS1302_CE = P3^5;

//定义
#define DS1302_SECOND 0X80
#define DS1302_MINUTE 0X82
#define DS1302_HOUR 0X84
#define DS1302_DATE 0X86
#define DS1302_MONTH 0X88
#define DS1302_DAY 0X8A
#define DS1302_YEAR 0X8C
#define DS1302_WP 0X8E

unsigned char DS1302_Time[] = {22,5,15,23,20,20,7};
/**
   *  @brief 对DS1302初始化
   *  @param 无
   *  @retval 无
   */
void DS1302_Init(void)		//初始化DS1302
{
	DS1302_CE = 0;
	DS1302_SCLK = 0;


}
/**
   *  @brief 朝DS1302中写时间
   *  @param command命令字/地址
   *  @param Data要写入的数据
   *  @retval 无
   */
void DS1302_WriteByte(unsigned char Command,Data)
{
	unsigned char i=0;
	DS1302_CE = 1;		//打开使能
	for(i=0;i<8;i++)		//在IO前8位写上command
	{
		DS1302_IO = Command&(0x01<<i);  //把command中的每一项写到IO口上
		DS1302_SCLK = 1;
		DS1302_SCLK = 0;
	}
	for(i=0;i<8;i++)		//在IO后8位写上Data
	{
		DS1302_IO = Data&(0x01<<i);
		DS1302_SCLK = 1;
		DS1302_SCLK = 0;
	}
		DS1302_CE = 0;
	
}

unsigned char DS1302_ReadByte(unsigned char Command)
{
	unsigned char i=0,Data = 0x00;		//要把IO口上的数据读出来
	Command|=0x01;		//看芯片手册可知，command|=0x01后写指令就变成了读指令
	DS1302_CE = 1;
	for(i=0;i<8;i++)		//在IO前8位写上command
	{
		DS1302_IO = Command&(0x01<<i);
		DS1302_SCLK = 0;
		Delay(1);
		DS1302_SCLK = 1;
	}
	for(i=0;i<8;i++)		//在IO前8位写上command
	{
		DS1302_SCLK=1;	
		Delay(1);//这样后面就是如此操作8次
		DS1302_SCLK=0;
		if(DS1302_IO)
		{
			Data|=(0x01<<i);
		
		}
			
	}
	DS1302_CE=0;
	DS1302_IO=0;	//????IO???0,??????????
	return Data;
	

}

/**
   *  @brief 把数组中的时间设置到DS1302中
   *  @param
   *  @retval
   */
void DS1302_SetTime(void)
{
		DS1302_WriteByte(DS1302_WP,0x00);//关闭写保护
		DS1302_WriteByte(DS1302_YEAR,DS1302_Time[0]/10*16+DS1302_Time[0]%10);//DS1302这边只要BCD码
		DS1302_WriteByte(DS1302_MONTH,DS1302_Time[1]/10*16+DS1302_Time[1]%10);
		DS1302_WriteByte(DS1302_DATE,DS1302_Time[2]/10*16+DS1302_Time[2]%10);
		DS1302_WriteByte(DS1302_HOUR,DS1302_Time[3]/10*16+DS1302_Time[3]%10);
		DS1302_WriteByte(DS1302_MINUTE,DS1302_Time[4]/10*16+DS1302_Time[4]%10);
		DS1302_WriteByte(DS1302_SECOND,DS1302_Time[5]/10*16+DS1302_Time[5]%10);
		DS1302_WriteByte(DS1302_DAY,DS1302_Time[6]/10*16+DS1302_Time[6]%10);
		DS1302_WriteByte(DS1302_WP,0x80);			//打开写保护
}

/**
   *  @brief 上面那个函数的反向（即将DS1302中的数据提取至数组中）
   *  @param
   *  @retval
   */
void DS1302_ReadTime(void)
{
	unsigned char Temp;
	Temp = DS1302_ReadByte(DS1302_YEAR);
	DS1302_Time[0] = Temp/16*10+Temp%16;		//BCD转10进制放入数组
	Temp = DS1302_ReadByte(DS1302_MONTH);
	DS1302_Time[1] = Temp/16*10+Temp%16;
	Temp = DS1302_ReadByte(DS1302_DATE);
	DS1302_Time[2] = Temp/16*10+Temp%16;
	Temp = DS1302_ReadByte(DS1302_HOUR);
	DS1302_Time[3] = Temp/16*10+Temp%16;	
	Temp = DS1302_ReadByte(DS1302_MINUTE);
	DS1302_Time[4] = Temp/16*10+Temp%16;	
	Temp = DS1302_ReadByte(DS1302_SECOND);
	DS1302_Time[5] = Temp/16*10+Temp%16;
	Temp = DS1302_ReadByte(DS1302_DAY);
	DS1302_Time[6] = Temp/16*10+Temp%16;


}
