#include "main.h"

void port_ini(void) {
	DDRD = 0xFC;
	PORTD = 0x00;
}

int main(void) {
	
	port_ini();
	LCD_ini();
	setpos(0, 0);
	sendString("Pavel Krasnoperov =)");

	unsigned char c = 0b00100001;
	
    while (1) 
    {
		setpos(0, 1);
		sendString("You are the best!");
		setpos(0, 1);
		_delay_ms(500);
		sendString("                    ");
		setpos(19, 1);
		sendByte(c, 1);
		++c;
		if (c > 0b01111111) c = 0b00100001;
		_delay_ms(500);
    }
}