#include "RunLengthEncoding.h"


/// @brief This is the encoding function
/// It encodes char arrays
/// @author Tom Troczynski
int encode(char* inputBuffer, char* outputBuffer) {

	char* currentLetter = inputBuffer;
	char checkEnd = "";
	int repetitions = 0;
	char countBuffer[ENCODESTR] = { 0 };
	char tempOutput[BUFFLEN] = { 0 };
	char escChar = ESCAPE;
	int bufferSize = 0;

	if (!inputBuffer) {
		return -1;
	}

	while (checkEnd != TERMINATOR) {

		repetitions = countRepetitions(currentLetter, *currentLetter);
		bufferSize += repetitions;

		if (bufferSize >= BUFFLEN) {
			return -1;
		}

		if (repetitions >= MINRUN) {
			_itoa_s(repetitions, countBuffer, sizeof(char) * ENCODESTR, RADIX);
			strncat_s(tempOutput, sizeof(char) * BUFFLEN, &escChar, sizeof(char));
			strncat_s(tempOutput, sizeof(char) * BUFFLEN, currentLetter, sizeof(char));
			strncat_s(tempOutput, sizeof(char) * BUFFLEN, countBuffer, strnlen_s(countBuffer, BUFFLEN));
		}
		else {
			strncat_s(tempOutput, sizeof(char) * BUFFLEN, currentLetter, repetitions);
		}
		currentLetter = (currentLetter + repetitions);
		checkEnd = *currentLetter;
	}

	if (strnlen_s(inputBuffer, BUFFLEN) == strnlen_s(tempOutput, BUFFLEN)) {
		return -1;
	}

	strncpy_s(outputBuffer, sizeof(char) * BUFFLEN, tempOutput, BUFFLEN);

	return bufferSize;

}

int decode(char* inputBuffer, char* outputBuffer) {
	char* currentLetter = inputBuffer;
	char checkEnd = "";
	int repetitions = 0;
	char tempOutput[BUFFLEN] = { 0 };
	char tempDigitBuff[BUFFLEN] = { 0 };
	char escChar = ESCAPE;
	char letter = "";
	int index = 0;
	int bufferCount = 0;

	if (!inputBuffer) {
		return -1;
	}

	while (checkEnd != TERMINATOR) {

		if (bufferCount >= BUFFLEN) {
			return -1;
		}
		
		if (*currentLetter == escChar) {

			currentLetter++;
			letter = *currentLetter;
			currentLetter++;

			while (*currentLetter != escChar) {

				if (isalpha(*currentLetter)) {
					break;
				}
				strncat_s(tempDigitBuff, BUFFLEN, currentLetter, sizeof(char));
				currentLetter++;
			}

			repetitions = atoi(tempDigitBuff);
			bufferCount += repetitions;

			memset(tempDigitBuff, 0, BUFFLEN);
			
			for (int i = 0; i < repetitions; i++) {
				tempOutput[index] = letter;
				index++;
			}
		}
		else {
			tempOutput[index] = *currentLetter;
			index++;
			currentLetter++;
			bufferCount++;
		}

		checkEnd = *currentLetter;
	}

	strncpy_s(outputBuffer, sizeof(char) * BUFFLEN, tempOutput, BUFFLEN);

	return bufferCount;
}

int countRepetitions(char* inputBuffer, char letter) {
	char* current = inputBuffer;
	int repetitions = 0;


	for (char* thisLetter = current; *thisLetter == letter; thisLetter++) {
		repetitions++;
		if (repetitions == 255) {
			break;
		}
	}

	return repetitions;
}