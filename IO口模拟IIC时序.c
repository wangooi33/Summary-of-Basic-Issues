

/************************************************************
	利用IO口模拟IIC时序，需要使用2个IO口(SDA和SCL)

	SCL时钟线只能由主器件进行控制，所以SCL引脚必须为输出模式
	SDA数据线，在主器件发送数据时，SDA引脚为输出模式
	SDA数据线，在主器件接收数据时，SDA引脚为输入模式

************************************************************/

#define  SDA_SET(n)  (n) ? GPIO_SetBits(GPIO?,GPIO_Pin_?) : GPIO_ResetBits(GPIO?,GPIO_Pin_?) 
#define  SCL_SET(n)  (n) ? GPIO_SetBits(GPIO?,GPIO_Pin_?) : GPIO_ResetBits(GPIO?,GPIO_Pin_?) 

#define  SDA_READ    GPIO_ReadInputDataBit(GPIO?,GPIO_Pin_?)


//SCL引脚设置
void IIC_SCLConfig(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	//打开GPIO端口的时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIO?,ENABLE);

	//SCL
	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_OUT;					//输出模式
	GPIO_InitStructure.GPIO_Speed 	= GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType 	= GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  	= GPIO_PuPd_DOWN;
	GPIO_InitStructure.GPIO_Pin 	= GPIO_Pin_?;
	GPIO_Init(GPIO?, &GPIO_InitStructure);
}

//SDA引脚设置
void IIC_SDAConfig(GPIOMode_TypeDef GPIO_Mode)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	//打开GPIO端口的时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIO?,ENABLE);

	//SCL
	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode;					
	GPIO_InitStructure.GPIO_Speed 	= GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType 	= GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  	= GPIO_PuPd_DOWN;
	GPIO_InitStructure.GPIO_Pin 	= GPIO_Pin_?;
	GPIO_Init(GPIO?, &GPIO_InitStructure);
}

//IIC的初始化
void IIC_Config(void)
{
	//1.设置SDA和SCL为输出模式
	IIC_SCLConfig();
	IIC_SDAConfig(GPIO_Mode_OUT);

	//2.确保SDA和SCL处于空闲状态
	SDA_SET(1);
	SCL_SET(1);
	delay_us(5);
}



//IIC的开始信号
void IIC_Start(void)
{
	//1.设置SDA引脚为输出模式
	IIC_SDAConfig(GPIO_Mode_OUT);

	//2.确保SDA和SCL处于空闲状态
	SDA_SET(1);
	SCL_SET(1);
	delay_us(5);

	//3.把SDA引脚电平拉低
	SDA_SET(0);
	delay_us(5);

	//4.把SCL引脚电平拉低，此时准备数据
	SCL_SET(0);
	delay_us(5);
	
}

//IIC的发送字节
void IIC_SendByte(uint8_t Byte)   //1011 0110
{
	//1.设置SDA引脚为输出模式
	IIC_SDAConfig(GPIO_Mode_OUT);

	//2.把SCL引脚电平拉低，此时主机准备数据
	SCL_SET(0);
	delay_us(5);

	//3.循环发送8bit，遵循MSB高位先出
	for(i=0;i<8;i++)
	{
		//4.判断待发送的字节的最高位
		if( Byte & 0x80 )
		{
			SDA_SET(1);
		}
		else
			SDA_SET(0);

		Byte <<= 1;
		delay_us(5);

		//5.把SCL电平拉高，此时从机读取bit
		SCL_SET(1);
		delay_us(5);

		//6.把SCL引脚电平拉低，此时主机准备下一个bit
		SCL_SET(0);
		delay_us(5);
	}
}

//判断从机是否应答
bool  IIC_IsSlaveACK(void)
{
	//1.设置SDA引脚为输入模式
	IIC_SDAConfig(GPIO_Mode_IN);

	//2.把SCL引脚电平拉低，此时为第9个脉冲的低电平，从机准备bit
	SCL_SET(0);
	delay_us(5);

	//3.把SCL引脚电平拉高，此时为第9个脉冲的高电平，主机读取状态
	SCL_SET(1);
	delay_us(5);

	//4.主机读取状态  1 表示未应答  0  表示已应答
	if(SDA_READ)
		return false;
	else
		return true;

}


//IIC读取字节
uint8_t IIC_ReadByte(void)
{
	uint8_t i = 0,data = 0;

	//1.设置SDA引脚为输入模式
	IIC_SDAConfig(GPIO_Mode_IN);

	//2.把SCL引脚电平拉低，此时从机准备数据
	SCL_SET(0);
	delay_us(5);

	//3.循环读取8bit，遵循MSB高位先出
	for (i = 0; i < 8; ++i)
	{
		//4.把SCL电平拉高，此时主机读取bit
		SCL_SET(1);
		delay_us(5);

		//5.主机读取bit
		data <<= 1;
		data |= SDA_READ;
		delay_us(5);

		//6.把SCL引脚电平拉低，此时从机准备下一个bit数据
		SCL_SET(0);
		delay_us(5);
	}

	//7.返回结果
	return data;
}

//ack=1 表示不应答  ack=0 表示要应答
void IIC_MasterACK(uint8_t ack)
{
	//1.设置SDA引脚为输出模式
	IIC_SDAConfig(GPIO_Mode_OUT);

	//2.把SCL引脚电平拉低，此时主机准备
	SCL_SET(0);
	delay_us(5);

	//3.判断ack的状态，从而对SDA操作
	if(ack)
		SDA_SET(1);
	else
		SDA_SET(0);

	delay_us(5);

	//4.把SCL电平拉高，此时从机读取bit
	SCL_SET(1);
	delay_us(5);
}

//IIC的停止信号
void IIC_Stop(void)
{
	//1.设置SDA引脚为输出模式
	IIC_SDAConfig(GPIO_Mode_OUT);

	//2.设置SDA和SCL均为低电平
	SDA_SET(0);
	SCL_SET(0);
	delay_us(5);

	//3.把SCL电平拉高
	SCL_SET(1);
	delay_us(5);

	//4.把SDA电平拉高
	SDA_SET(1);
	delay_us(5);
}

int main()
{
	IIC_Config();

}