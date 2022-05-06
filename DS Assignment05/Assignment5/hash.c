#include "hash.h"

void hashInit(int* hashTable, int* input, int M, int R)
{
	int i = 1;
	int h = 0;
	int h1 = 0;
	int h2 = 0;

	for (int k = 0; k < M; k++) {

		h2 = R - (input[k] % R);
		h1 = input[k] % M;

		if (hashTable[h1] > 0) {
			do {
				h = (h1 + h2 * i) % M;
				i++;
			} while (hashTable[h] > 0);

			hashTable[h] = input[k];
		}
		else {
			hashTable[h1] = input[k];
		}

		i = 1;
	}

	return;
}
