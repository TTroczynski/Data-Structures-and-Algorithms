/* main() : Testing for matrix multiplication function - LAB 6
 *				Michael Galle & Jack Cole, 2016
 */

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#include "Matrix.h"

 // a testing mainline 
int main(int argc, char* argv[])
{
	int		r, c, n = 3, m = 4;
	/*
	* Example of converting a 2D array into a 1D array
	*/
	//                COL  0    1    2    3
	float	A[3][4] = { { 1.0, 2.0, 3.0, 4.0 },     //ROW 0
						{ 2.0, 1.0, 1.0, 2.0 },     //ROW 1
						{ 3.0, -3.0, 2.0, -2.0 } }; //ROW 2
	/*

						// (row# * #ofCols) + col#
						[1][0] = 2.0 equal index 4

						1 * 4 + 0 = 4

						[2][2] = 2.0 equal index 10

						2 * 4 + 2 = 10
	*/
	// float	A[12] = { 1.0, 2.0, 3.0, 4.0, 2.0, 1.0, 1.0, 2.0, 3.0, -3.0, 2.0, -2.0 };
	//      ARRAY INDEX    0    1    2    3    4    5    6    7    8     9    10    11


	float	x1[4] = { -1.0, 2.0, -1.0, 2.0 };
	float	y1[3];

	// multiply A times x1
	MultiplyAx(A, n, m, x1, y1);

	// show the results as y = Ax.
	for (r = 0; r < n; ++r) {
		printf("  [ % 6.3f ] %c [ ", y1[r], (r == 0) ? '=' : ' ');
		for (c = 0; c < m; ++c) {
			printf("% 6.3f ", A[r][c]);
		}
		printf(" ] [ % 6.3f ]\n", x1[r]);
	}

	// If m > n, then x has more rows to display
	if (n < m) {
		for (r = n; r < m; ++r) {
			printf("                ");
			for (c = 0; c < m; ++c) {
				printf("       ");
			}
			printf("    [ % 6.3f ]\n", x1[r]);
		}
	}

	printf("Press enter to continue ...");
	getchar();

	return(1);
}