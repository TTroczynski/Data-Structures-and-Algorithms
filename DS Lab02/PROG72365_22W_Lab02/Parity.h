#ifndef PARITY_H
#define PARITY_H

/* Parity.h : Header file for parity calculations.*/

typedef enum PARITY { PAR_EVEN, PAR_ODD, PAR_ERROR } PARITY;

// function prototypes

PARITY  ParityOnBytes(char* buf, int iBufLen); // Lab 01
PARITY  Parity(char* buf, int iBufLen); // Lab 02

#endif /* PARITY_H */