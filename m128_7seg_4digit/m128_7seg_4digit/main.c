#define F_CPU 8000000L

#include <avr/io.h>
#include <util/delay.h>

int displayOut (int number);

int main(void)
{
    unsigned char segDigit[10] =	{
										~0b00111111,
										~0b00000110,
										~0b01011011,
										~0b01001111,
										~0b01100110,
										~0b01101101,
										~0b01111101,
										~0b00000111,
										~0b01111111,
										~0b01101111
													};
	unsigned char segCategory =		{
										0b00000001,
										0b00000010,
										0b00000100,
										0b00001000
													};
    while (1) 
    {
    }
}

int displayOut(int number) {
	
	
}