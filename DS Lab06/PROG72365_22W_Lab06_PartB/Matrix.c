#include "Matrix.h"

/*
 * MultiplyAx()
 * Compute the product of y = Ax in an m x n matrix and x is an n x 1 vector
 * y is the output which will be an m x 1 vector
 * E.g.	(a b c d) (u) = (au + bv + cw + dz) = (r1)
 *		(e f g h) (v) = (eu + fv + gw + hz) = (r2)
 *		(i j k l) (w) = (iu + jv + kw + lz) = (r3)
 *				  (z)
 *          A      x                           y
 *
 */

void MultiplyAx(float* A, int mRows, int nCols, float* x, float* y) {

	float sum;
	for (int i = 0; i < mRows; ++i) {
		sum = 0;
		for (int j = 0; j < nCols; ++j) {
			sum += A[(i * nCols) + j] * x[j];
		}
		y[i] = sum;
	}
}

