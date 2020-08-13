#include <avr/io.h>
#include "main.h"

void port_ini(void) {
	PORTB = 0x00;
	DDRB = 0b10000000;
}

int main(void)
{
	unsigned char pwm_state = 0;
	port_ini();
	init_PWM_timer();
	
	OCR2 = 31;
	
    while (1) 
    {

    }
}