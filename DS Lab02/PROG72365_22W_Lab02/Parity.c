/*
 * Parity.c
 * Description:	Defines the ParityOnBytes() function and
 * the Parity() function.
 */

#include "Parity.h"

PARITY ParityOnBytes(char* buf, int iBufLen) {
	//Insert your code from Lab 01 here

	int comparator = 1;
	int integer_Value = 0;
	int index = iBufLen - 1;
	int placeholder = 1;


	while (index >= 0)
	{
		if (*(buf + index) == '1')
			integer_Value += placeholder;
		else if (*(buf + index) != '1' && *(buf + index) != '0')
			return PAR_ERROR;
		index--;
		placeholder *= 2;
	}
	if (integer_Value & comparator)
	{
		return PAR_ODD;
	}
	else
	{
		return PAR_EVEN;
	}
}

PARITY Parity(unsigned char* buf, int iBufLen) {

	//moves bit shifts the mask to compare against and the position of the pointer in memory for the char array (input)

	//The result of the OR assign is 1 at the bit address relative to iMask in pCur if there is a 1 in either
	//iMask OR at pCur's current address. In other words, 
	//if there is a char '1', then assign a 1 to the same bit address where there is a 1 within iMask. Each iteration
	//shifts the binary 1 within iMask. 
	//Calloc assigned enough memory for an unisgned char and set the bit field to 0, allowing us to create an exact
	//copy of buf.

	//iMask must have a matching type (unsigned char) because pCur points to multiples of unsigned char's in memory. 
	//it is assigned 0x80 (128 dec) because the binary representation is 1000 0000 - a single 1 within 8 bits(1 byte)
	//so that it can be used to evaluate each individual unsigned char bit by bit.
	//when the 1 bit within iMask is shifted out of the 8 bit field and equals 0, it is reset, and 
	//pCur is shifted to the next byte.

	//Upon calling Parity(), the function is passed the unsigned char pointer to the same address pCur pointed to.


	PARITY default_Parity = PAR_ERROR;
	unsigned char mask = 0x01;		//mask binary: 0000 0001

	int byte_Count = 1;
	for (byte_Count; byte_Count < iBufLen; byte_Count++)		//move to last byte
		buf++;

	if (*buf & mask)				//AND comparing the mask to the value pointed to by buf 
	{
		return PAR_ODD;				//If the last bit is 1, odd
	}
	else
	{
		return PAR_EVEN;			//if the last bit is 0, even.
	}

	return default_Parity;
}

