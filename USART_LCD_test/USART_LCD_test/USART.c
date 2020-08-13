#include "USART.h"

void USART_Init(unsigned int speed) {
	UBRR0H = (unsigned char) (speed >> 8);
	UBRR0L = (unsigned char) speed;
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
	UCSR0B |= (1 << RXCIE0);
	UCSR0A |= (1 << U2X0);
	UCSR0C = (1 << USBS0) | (3 << UCSZ00);
}

void USART_Transmit(unsigned char data) {
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}