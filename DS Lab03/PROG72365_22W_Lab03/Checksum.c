#include <stdio.h>
#include "Checksum.h"

unsigned int Checksum(void* buf, int iBufLen, CHECKSUM iType) {

	unsigned char* buffer_8;
	unsigned short* buffer_16;
	unsigned int* buffer_32;

	long long int sum = 0;
	int checkSum = 0;

	switch (iType)
	{
	case(CHK_8BIT):

		buffer_8 = (unsigned char*)buf;

		for (int i = 0; i < iBufLen; i++)
		{
			sum += *buffer_8;
			buffer_8++;
		}

		checkSum = sum % (0x01 + 0xFF);
		return checkSum;


	case(CHK_16BIT):
		buffer_16 = (unsigned short*)buf;

		for (int i = 0; i < iBufLen; i++)
		{
			sum += *buffer_16;
			buffer_16++;
		}
		
		checkSum = sum % (0x0001 + 0xFFFF);
		return checkSum;

	case(CHK_32BIT):

		buffer_32 = (unsigned int*)buf;

		for (int i = 0; i < iBufLen; i++)
		{
			sum += *buffer_32;
			buffer_32++;
		}

		checkSum = sum % (0x100000000);	
		return checkSum;

	default:
		printf("\nOnly 8-bit, 16-bit and 32-bit checksums are supported");
		return CHK_ERROR;
	}
}