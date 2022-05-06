#include "hash.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ZERO 0

int main(void) {

	int input[] = { 764, 35954, 8683, 41, 11004, 1362, 77, 1, 448, 118, 5507 };
	int M = sizeof(input) / sizeof(input[0]);
	int R = 7;
	int* hashTable = (int*)calloc(M, sizeof(int));

	if (hashTable != NULL) {

		hashInit(hashTable, input, M, R);

		puts("Hash Table : ");

		for (int i = 0; i < M; i++) {
			printf("Hashtable[%d]: %d\n",i,  hashTable[i]);
		}

		free(hashTable);
	}
	else {
		exit(EXIT_FAILURE);
	}
	
	return 0;
}