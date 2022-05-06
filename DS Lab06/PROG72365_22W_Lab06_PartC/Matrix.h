#ifndef MATRIX_H
#define MATRIX_H
#define ENCCOLUMNS 4
#define ENCROWS 7
#define DECCOLUMNS 7
#define DECROWS 3
#define PARITY 3
#define IDENTITY 4
/* Matrix.h : Header file for Matrix Multiplication implementation*/

// Function declarations
void MultiplyAx(float* A, int mRows, int nCols, float* x, float* y);
void MultiplyHx(int* H, int mRows, int nCols, int* x, int* y);
void showEncode(int* H, int* p, int* r);
void showDecode(int* H, int* r, int* s);

#endif //MATRIX_H