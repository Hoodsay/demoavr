#ifndef LCD_H_
#define LCD_H_

#include "main.h"

void LCD_ini(void);
void clearLCD(void);
void sendChar(unsigned char c);
void setpos(unsigned char x, unsigned char y);
void sendString(unsigned char *str);
void sendByte(unsigned char c, unsigned char mode);

#define Eto1 PORTD |= 0b00001000 //установка линии Е в высокий уровень
#define Eto0 PORTD &= 0b11110111 //установка линии Е в низкий уровень (при этом происходит обмен данными)
#define RSto1 PORTD |= 0b00000100 //установка линии RS в высокий уровень (данные)
#define RSto0 PORTD &= 0b11111011 //установка линии RS в низкий уровень (команда)

#define NULL '\0'

#endif /* LCD_H_ */