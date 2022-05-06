/*
 * Parity.c
 * Description: Defines the ParityOnBytes() function
 * 
 */
#include "Parity.h"

PARITY ParityOnBytes(char* buf, int iBufLen)
{

	int comparator = 1;
	int integer_Value = 0;
	int index = iBufLen - 1;
	int placeholder = 1;

	//Scans through buf and converts binary input as a string to an integer value.
	//then compare integer_Value against the value: 1 (00000000000000000000000000000001)
	//using the bitwise & operation to check parity by evaluating the last or least significant digit.

	while (index >= 0)
	{
		if (*(buf + index) == '1')
			integer_Value += placeholder;
		else if(*(buf + index) != '1' && *(buf + index) != '0') //Returns if the user inputs characters other than '0' or '1'
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