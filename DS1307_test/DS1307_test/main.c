#include "main.h"

unsigned char sec, min, hour, dayOfWeek, day, month, year;

int main(void) {
	
	I2C_Init();
	USART_Init(8);
// 	
// 	I2C_StartCondition();
// 	I2C_SendByte(0b11010000);
// 	I2C_SendByte(0);
// 	
// 	I2C_SendByte(DS1307_ConvertToBinDec(0));
// 	I2C_SendByte(DS1307_ConvertToBinDec(14));
// 	I2C_SendByte(DS1307_ConvertToBinDec(18));
// 	I2C_SendByte(DS1307_ConvertToBinDec(4));
// 	I2C_SendByte(DS1307_ConvertToBinDec(23));
// 	I2C_SendByte(DS1307_ConvertToBinDec(4));
// 	I2C_SendByte(DS1307_ConvertToBinDec(20));
// 	
// 	I2C_StopCondition();
	
    while (1) {
		
		I2C_SendByteByADDR(0, 0b11010000);
		_delay_ms(1000);
		I2C_StartCondition();
		I2C_SendByte(0b11010001);
		sec = I2C_ReadByte();
		min = I2C_ReadByte();
		hour = I2C_ReadByte();
		dayOfWeek = I2C_ReadByte();
		day = I2C_ReadByte();
		month = I2C_ReadByte();
		year = I2C_ReadLastByte();
		I2C_StopCondition();
		
		sec = DS1307_convertToDec(sec);
		min = DS1307_convertToDec(min);
		hour = DS1307_convertToDec(hour);
		dayOfWeek = DS1307_convertToDec(dayOfWeek);
		day = DS1307_convertToDec(day);
		month = DS1307_convertToDec(month);
		year = DS1307_convertToDec(year);
		
		 USART_Transmit(day/10+0x30);
		 USART_Transmit(day%10+0x30);
		 USART_Transmit('.');
		 USART_Transmit(month/10+0x30);
		 USART_Transmit(month%10+0x30);
		 USART_Transmit('.');
		 USART_Transmit(year/10+0x30);
		 USART_Transmit(year%10+0x30);
		 USART_Transmit(' ');
		 USART_Transmit('-');
		 USART_Transmit(day+0x30);
		 USART_Transmit('-');
		 USART_Transmit(' ');
		 USART_Transmit(' ');
		 USART_Transmit(hour/10+0x30);
		 USART_Transmit(hour%10+0x30);
		 USART_Transmit(':');
		 USART_Transmit(min/10+0x30);
		 USART_Transmit(min%10+0x30);
		 USART_Transmit(':');
		 USART_Transmit(sec/10+0x30);
		 USART_Transmit(sec%10+0x30);
		 USART_Transmit(0x0d);
		 USART_Transmit(0x0a);
	}
}