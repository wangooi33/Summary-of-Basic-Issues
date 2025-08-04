模式0：

```c
uint8_t SPI3_Send(u8 val)  
{ 
	int i = 0; 
	uint8_t data = 0;
	
	 //1.SCK引脚输出低电平
	 MFRC522_SCK(0);
	 delay_us(5);
		
	 //2.循环发送8次，每次发送一个bit  遵循MSB 高位先出
	 for(i=0;i<8;i++)
	 {
		 //3.判断待发送的字节的最高位  ???? ???? & 1000 0000
		 if( val & 0x80 )
		 {
				MFRC522_MOSI(1);
		 }
		 else
				MFRC522_MOSI(0);
		 
		 val <<= 1;
		 delay_us(5);
		 
		 //4.SCK引脚输出高电平，此时第一个边沿出现
		 MFRC522_SCK(1);
		 delay_us(5);
		 
		 //6.此时从机会响应一个bit，主机需要接收！
		 data <<= 1;
		 data |= MFRC522_MISO;
		 delay_us(5);	
		 
		 //7.SCK引脚输出低电平，此时第二个边沿出现
		 MFRC522_SCK(0);
		 delay_us(5);
	 }
		
	 return data;
}
```

