
#include <stdio.h>
#include "Matrix.h"



void MultiplyHx(int* H, int mRows, int nCols, int* x, int* y) {

	int sum;
	for (int i = 0; i < mRows; ++i) {
		sum = 0;
		for (int j = 0; j < nCols; ++j) {
			sum += H[(i * nCols) + j] * x[j];
		}
		y[i] = sum % 2;
	}

	return 0;
}

void extractParity(int* R, int nBits, int pBits, int * p) {

	for (int i = nBits - pBits; i < nBits; ++i) {
		p[i - pBits - 1] = R[i];
	}

	return 0;
}

void extractIdentity(int* R, int idBits, int * p) {

	for (int i = 0; i < idBits; ++i) {
		p[i] = R[i];
	}

	return 0;
}

void displayMatrix(int* M, int mRows, int nCols) {

	int* parity[PARITY] = { 0 };
	int* identity[IDENTITY] = { 0 };
	char temp = ' ';

	for (int i = 0; i < mRows; ++i) {
		printf("|");
		for (int j = 0; j < nCols; ++j) {
			printf("%d ", M[(i * nCols) + j]);
		}
		printf("%c", '\n');
	}

	return 0;
}

void showEncode(int* H, int* p, int* r) {

	char temp;

	for (int i = 0; i < ENCROWS; ++i) {
		printf("|");
		for (int j = 0; j < ENCCOLUMNS; ++j) {
			printf("%d ", H[(i * ENCCOLUMNS) + j]);
		}
		if (i < 4) {
			printf("|| %d |", p[i]);
		}
		else {
			printf("|     ");
		}
		temp = ' ';
		if (i == (ENCROWS / 2)) {
			temp = '=';
		}

		printf("%c |%d|\n", temp, r[i]);
	}
	return 0;
}
void showDecode(int* H, int* r, int* s) {

	char temp;

	for (int i = 0; i < DECCOLUMNS; ++i) {
		if (i < 3) {
			printf("|");
			for (int j = 0; j < DECCOLUMNS; ++j) {
				printf("%d ", H[(i * DECCOLUMNS) + j]);
			}
			printf("|");
		}
		else {
			printf("                ");
		}
		printf(" | %d |", r[i]);

		if (i >= 3) {
			printf("\n");
		}
		temp = ' ';
		if (i == (DECROWS / 2)) {
			temp = '=';
		}
		if (i < 3) {
			printf("%c |%d|\n", temp, s[i]);
		}
	}
	return 0;
}