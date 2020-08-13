#include "main.h"

unsigned char dt;
uint16_t dt16;
uint32_t dt32;

int main(void) {
	
	USART_Init(8);
	asm("nop");
	
	dt = EEPROM_read(1);
	USART_Transmit(dt);
	USART_Transmit(0x0d);
	USART_Transmit(0x0a);
	
	dt16 = EEPROM_read_word(3);
	USART_Transmit((unsigned char) (dt16 >> 8));
	USART_Transmit((unsigned char) dt16);
	USART_Transmit(0x0d);
	USART_Transmit(0x0a);
	
	dt32 = EEPROM_read_dword(7);
	USART_Transmit((unsigned char) (dt32 >> 24));
	USART_Transmit((unsigned char) (dt32 >> 16));
	USART_Transmit((unsigned char) (dt32 >> 8));
	USART_Transmit((unsigned char) dt32);
	USART_Transmit(0x0d);
	USART_Transmit(0x0a);
	
	const char *buff = EEPROM_read_string(16, 13);
	for (int i = 0; i < 13; ++i) {
		USART_Transmit(buff[i]);
	}
	USART_Transmit(0x0d);
	USART_Transmit(0x0a);
	
	while (1) 
    {
    }
}