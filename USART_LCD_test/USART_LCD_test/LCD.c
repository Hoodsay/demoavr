#include "LCD.h"

void sendHalfByte(unsigned char c) {
	c <<= 4;
	Eto1;
	PORTD &= 0b00001111;
	PORTD |= c;
	_delay_us(50);
	Eto0;
	_delay_us(50);
}

void sendByte(unsigned char c, unsigned char mode) {
	
	unsigned char hc = c >> 4;
	
	if (mode == 0) {
		RSto0;
		} else {
		RSto1;
	}
	
	sendHalfByte(hc);
	sendHalfByte(c);
}

void sendChar(unsigned char c) {
	sendByte(c, 1);
}

void setpos(unsigned char x, unsigned char y) {
	char address;
	address = (0x40 * y + x) | 0b10000000;
	sendByte(address, 0);
}

void LCD_ini(void) {
	_delay_ms(20);
	sendHalfByte(0b00000011); //8 bit
	_delay_ms(5);
	sendHalfByte(0b00000011); //8 bit
	_delay_us(150);
	sendHalfByte(0b00000011); //8 bit
	_delay_us(40);
	sendHalfByte(0b00000010); //4 bit
	_delay_us(40);
	sendHalfByte(0b00000010); //4 bit
	sendHalfByte(0b00001100); //две строки, символ 5х7 точек
	_delay_us(40);
	sendHalfByte(0b00000000); //
	sendHalfByte(0b00001000); //отключение дисплея
	_delay_us(40);
	sendHalfByte(0b00000000); //
	sendHalfByte(0b00000001); //очистка дисплея
	_delay_us(1800);
	sendHalfByte(0b00000000); //
	sendHalfByte(0b00000110); //направление отрисовки символов
	_delay_us(40);
	sendHalfByte(0b00000000); //
	sendHalfByte(0b00001100); //включение дисплея
	_delay_us(40);
	// 	sendByte(0b00101000, 0);
	// 	_delay_ms(1);
	// 	sendByte(0b00001100, 0);
	// 	_delay_ms(1);
	// 	sendByte(0b00000110, 0);
	// 	_delay_ms(1);
}

void sendString(unsigned char *str) {
	while (*str != NULL) {
		sendChar(*str);
		str++;
	}
}

void clearLCD(void) {
	sendByte(0b00000001, 0);
	_delay_ms(2);
}