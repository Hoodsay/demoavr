#include "main.h"

unsigned char x = 0;
unsigned char y = 0;
int stringIn[42];
int *stringEnd = stringIn + 41;
int *pntrStringIn = stringIn;
int flag = 1;

int isTransmitStop(void) {
	int t = UDR0;
	_delay_ms(1);
	if (t == UDR0) return 1;
	else return 0;
}

void port_ini(void) {
	DDRD = 0xFC;
	PORTD = 0x00;
}

ISR(USART0_RX_vect) {
	int b = UDR0;
	*pntrStringIn = b;
	++pntrStringIn;
	if (pntrStringIn > stringEnd) {
		pntrStringIn = stringIn;
	}
	flag = 0;
}

int main(void){
	
	port_ini();
	LCD_ini();
	USART_Init(16);
	sei();
	USART_Transmit('O');
	USART_Transmit('k');
	USART_Transmit('!');
	USART_Transmit(0x0d);
	USART_Transmit(0x0a);
	
	
	
	while (1) {
		if (isTransmitStop() && flag == 0) {
			clearLCD();
			setpos(0, 0);
			sendString(stringIn);
			flag = 1;
		}
	}
}