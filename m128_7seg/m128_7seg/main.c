#define F_CPU 8000000L

#define delay 6

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

unsigned char segchar(unsigned char number);
void timer_ini(void);
void numberToDigits(unsigned int n, unsigned char *pntr);

unsigned char digitsArray[11] =	{
									0b11000000, //0
									0b11111001, //1
									0b10100100, //2
									0b10110000, //3
									0b10011001, //4
									0b10010010, //5
									0b10000010, //6
									0b11111000, //7
									0b10000000, //8
									0b10010000, //9
									0b01111111  //.(dot)
								};
unsigned char *pntrSeg = digitsArray;
unsigned char nCount = 0;
unsigned char digitsOfNumber[4] = {0, 0, 0, 0};
unsigned char *pntrDigitsOfNumber = digitsOfNumber;
unsigned int number;

int main(void)
{
    DDRC = 0xFF;
	PORTC = 0b11111111;
	DDRA = 0b00001111;
	
	sei();
	
	timer_ini();
	

	while(1) {
		
		for (number = 0; number < 10000; ++number) {
			numberToDigits(number, digitsOfNumber);
			_delay_ms(100);
		}
		number = 0;
	}
}

void numberToDigits(unsigned int n, unsigned char *pntr) {
	
	unsigned char i;
	
	for (i = 0; i < 4; ++i) {
		*pntr = n % 10;
		n /= 10;
		++pntr;
	}
}

unsigned char segchar(unsigned char number) {
	
	return digitsArray[number];
}

void timer_ini(void) {
	TCCR1B |= 1 << WGM12;
	TIMSK |= 1 << OCIE1A;
	OCR1AH = 0b00001100;
	OCR1AL = 0b00110101;
	TCCR1B |= 1 << CS11;
}

ISR(TIMER1_COMPA_vect) {
	switch (nCount) {
		case 0:
			PORTA = 0b00000001;
			PORTC = digitsArray[*pntrDigitsOfNumber];
			break;
		case 1:
			if (number > 9) PORTA = 0b00000010;
			else PORTA = 0b00000000;
			PORTC = digitsArray[*(pntrDigitsOfNumber + 1)] & digitsArray[10];
			break;
		case 2:
			if (number > 99) PORTA = 0b00000100;
			else PORTA = 0b00000000;
			PORTC = digitsArray[*(pntrDigitsOfNumber + 2)];
			break;
		case 3:
			if (number > 999) PORTA = 0b00001000;
			else PORTA = 0b00000000;
			PORTC = digitsArray[*(pntrDigitsOfNumber + 3)];
			break;
		default:
			break;
	}
	++nCount;
	if (nCount > 3) {
		nCount = 0;
	}
}