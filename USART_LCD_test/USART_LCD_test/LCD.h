#ifndef LCD_H_
#define LCD_H_

#include "main.h"

void LCD_ini(void);
void clearLCD(void);
void sendChar(unsigned char c);
void setpos(unsigned char x, unsigned char y);
void sendString(unsigned char *str);
void sendByte(unsigned char c, unsigned char mode);

#define Eto1 PORTD |= 0b00001000 //��������� ����� � � ������� �������
#define Eto0 PORTD &= 0b11110111 //��������� ����� � � ������ ������� (��� ���� ���������� ����� �������)
#define RSto1 PORTD |= 0b00000100 //��������� ����� RS � ������� ������� (������)
#define RSto0 PORTD &= 0b11111011 //��������� ����� RS � ������ ������� (�������)

#define NULL '\0'

#endif /* LCD_H_ */