

#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

int main(void) {

	int p[4] = { 1, 0, 1, 1 };
	int r[7] = { 0 };
	int s[3] = { 0 };
	int hammingsEnc[ENCROWS][ENCCOLUMNS] = {
										{ 1, 0, 0, 0 },
										{ 0, 1, 0, 0 },
										{ 0, 0, 1, 0 },
										{ 0, 0, 0, 1 },
										{ 0, 1, 1, 1 },
										{ 1, 0, 1, 1 },
										{ 1, 1, 0, 1 }
	};
	int hammingsDec[DECROWS][DECCOLUMNS] = { 
										{ 0, 1, 1, 1, 1, 0, 0 },
										{ 1, 0, 1, 1, 0, 1, 0 },
										{ 1, 1, 0, 1, 0, 0, 1 } 
	};



	MultiplyHx(hammingsEnc, ENCROWS, ENCCOLUMNS, p, r);

	printf("Encode: \n");
	showEncode(hammingsEnc, p, r);

	MultiplyHx(hammingsDec, DECROWS, DECCOLUMNS, r, s);

	printf("Decode: \n");
	showDecode(hammingsDec, r, s);

	r[0] = 0;

	MultiplyHx(hammingsDec, DECROWS, DECCOLUMNS, r, s);

	printf("Decode after bit flip: \n");
	showDecode(hammingsDec, r, s);

	return 0;

}