#ifndef CHECKSUM_H
#define CHECKSUM_H

// Define enumerated data type

typedef enum checkSum {CHK_8BIT, CHK_16BIT, CHK_32BIT, CHK_ERROR}CHECKSUM;

// Function prototypes

unsigned int Checksum(void* buf, int iBufLen, CHECKSUM iType);

#endif //CHECKSUM_H