如果某个IO口没有连接到定时器的通道上，那就无法使用定时器的通道来调节PWM脉冲信号，那此时可以选择使用**延时**来模拟脉冲信号，通过控制高电平和低电平的延时时间的长短来实现PWM调节。

```c
int main()
{
	//1.硬件的初始化
	LED_Config();
	
	//可以看到一个脉冲信号的周期是20ms，其中高电平持续19ms，所以占空比高，由于LED灯是低电平亮，所以占空比越高LED越暗
	while(1)
	{
		GPIO_ResetBits(GPIOF,GPIO_Pin_9);//LED亮
        delay_ms(1);
        GPIO_SetBits(GPIOF,GPIO_Pin_9);//LED不亮
        delay_ms(19);
	}
}
```

