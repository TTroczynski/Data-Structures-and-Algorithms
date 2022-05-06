#ifndef PARITY_H
#define PARITY_H

/*
 * Parity.h: Header file for parity calculations
 */
typedef enum PARITY { PAR_EVEN, PAR_ODD, PAR_ERROR } PARITY;

/*
 * Computes parity on a buffer having 1 data bit for every byte.
 * Returns 1 if sum of bits in the byte is odd, else 0.
 */

PARITY ParityOnBytes(char* buf, int iBufLen);

#endif /* PARITY_H */