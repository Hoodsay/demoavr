#include "main.h"


int main(void){
	
	USART_Init(8);
	
	unsigned char string[] = "That will does not kill us, makes us stronger.";
	unsigned char *start = string;
	
    while (1) 
    {
		while (*start != 0) {
			USART_Transmit(*start);
			++start;
			_delay_ms(10);
		}
		USART_Transmit(0x0d);
		USART_Transmit(0x0a);
		
		start = string;

		_delay_ms(1000);
    }
}