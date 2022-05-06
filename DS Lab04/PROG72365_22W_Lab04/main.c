/*
 * Write a client for crcSlow()
 * Calculate a CRC for a message
 * Introduce a change in the message (simulating an error) and calculate the CRC to see the effect
 * Append the CRC to the message so it is ready for transfer
 */
#include <stdlib.h>
#include <stdio.h>
#include "crc.h"
#include <time.h>;
#include <string.h>


int main(int argc, char* argv[])
{
	srand(time(NULL));

	int size = strnlen_s(argv[argc - 1], 256);

	if (argc != 2 || size > 256)
	{
		printf("Exiting. Use: program [message: \"message\"]\n");
		exit(EXIT_FAILURE);
	}

	unsigned short* pCRC;
	char randomCharacter;
	int randomByte = rand() % size;
	unsigned char* message = NULL;
	message = calloc((sizeof(unsigned char) * size) + sizeof(crc), sizeof(unsigned char));//		Size of message + size of crc
	int bitCount = sizeof(unsigned char) * 8 * size;


	if (!message)
	{
		printf("failed to allocate memory for the message buffer\n");
		exit(EXIT_FAILURE);
	}

	pCRC = message + size;

	for (int i = 0; i <= size; ++i)
	{
		*(message + i) = *((argv[argc - 1]) + i);
	}


	*pCRC ^= crcSlow(message, size);

	printf("Message and CRC Slow appended: %s\n", message);

	*pCRC = 0x0000;
	
	randomCharacter = message[randomByte];
	
	randomByte = rand() % size;
	
	message[randomByte] = randomCharacter;

	*pCRC ^= crcSlow(message, size);

	printf("Message after bit flip with CRC Slow appended: %s\n", message);


}
