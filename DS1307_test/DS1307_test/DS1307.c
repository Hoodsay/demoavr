#include "DS1307.h"

unsigned char DS1307_ConvertToBinDec(unsigned char c) {
	
	return ((c / 10) << 4) | (c % 10);
}

unsigned char DS1307_convertToDec(unsigned char c) {
	
	return ((c >> 4) * 10 + (0b00001111 & c));
}