/* main.c : Testing mainline for Lab #02
*           By: Michael Galle & Jack Cole
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include "Parity.h"  // Header file includes Prototypes defined in Parity.cpp


/* PackToBits() : Utility function to convert the ASCII form to packed binary
 *
 *		NOTE: malloc()'s the buffer to hold the packed binary, and
 *		returns the pointer. CALLER SHOULD FREE THE BUFFER WHEN DONE.
 *		Returns NULL if malloc() fails, or if string contains bad characters.
 *		Returns the output length (rounded up) via pOutLen;
 *
 *		NOTE2: Policy is that output buffer and length are rounded up to even bytes.
 *		E.g. If buf of char is 101011101, then iBufLen = 9, pOutLen = 2
 * 
 *		iBufLen is the number of Bytes given by the user, that is the number of characters. Each ASCII character takes 1 byte.
 *		pOutLen is the number of Bytes needed to store the converted ASCII Bytes to bits
 *		E.g.	'1' '0'
 *				8 bits, 8 bits
 */
static unsigned char* PackToBits(char* buf, int iBufLen, int* pOutLen)
// static: in local variables, this is used to store the variable in statically allocated memory instead of automatically allocated memory
// static: in global variables and functions, this is used to set the scope to the containing file
{
	unsigned char* p, * pCur;
	int				iOutLen;
	unsigned char	iMask;
	int				i;

	// The packed form will be 1/8th as long as the ASCII form (one bit per char vs one byte), taken to the next largest integer
	iOutLen = (iBufLen + 7) / 8; 										  // iOutLen is the number of elements to be allocated
	
	
	// Allocating a space in memory and setting it to zero
	p = (unsigned char*)calloc(iOutLen, sizeof(unsigned char));           // p is an unsigned char pointer --> Notice it is (casted) as an unsigned char pointer
																		  // calloc() allocates the requested memory (and sets it to zero - unlike malloc() ) and returns a pointer to it, returns NULL if request fails
																		  // Declaration of calloc():   void * calloc(nitems, size)  --> nitems = number of elements to allocate, size = size of each element
	pCur = p;

	
	//p points to the start: 0				000 0000
	//pCur allows us to walk through 

	// Example
	// x054 = buf
	// *buf = '1'	...		'0' '1' '0' '0' '1' '1' '1' '0'

	// pCur  = 1010 0110
	// iMask = 1000 0000
	// OR    = 


	// Shift iMask once to the right and then save that over iMask
	// iMask = 1000 0000 becomes
	// iMask = 0100 0000

	// Walk through the input string setting the bitset
	for (i = 0, iMask = 0x80; i < iBufLen; ++i, ++buf) {
		// Check for a '1' or a '0' or something illegal
		if (*buf == '1') { *pCur |= iMask; }							  // *pCur dereferences pCur so indicates/sets the value it points to in memory

		else if (*buf != '0') {    // calloc() sets allocated memory to zero so if not 0 then we have a buffer overrun 
			// ERROR: Must free p or we have a memory leak
			free(p);
			return(NULL);
		}

		// Prepare mask for next time, and check for start of new byte
		iMask >>= 1;	// Shift all bits by one position to the right
		if (iMask == 0) {
			// Mask must be reset, and new data processed
			iMask = 0x80;
			++pCur;
		}
	}

	// Done, we don't have to clear the rest of the final byte, because it was done in calloc().
	*pOutLen = iOutLen; 												  // Store the value of iOutLen in the memory location pointed to by pOutLen (* dereferences pointer)
	return(p);
}


int main(int argc, char* argv[])
{
	int					i, rc, iPackedLen; //i is a counter, rc is the parity value 0,1,2. iPackedLen is the number of BYTES needed when you convert Bytes to Bits
	unsigned char* bPackedString; //Is the location in memory where you stored the bits that you have converted. We have to store them somewhere.
	unsigned char		bZeros[6] = { 0 };

	unsigned char		iMask; //Mask for toggling, looking at indivudal bits within the Byte.

	// Ensure there is at least one argument supplied by user
	if (argc < 2) {
		fprintf(stderr, "Usage: Parity <string1> <string2> ..., where strings must be a series of 1's and 0's.\n");
		return(0);
	}

	// Test the byte-oriented (ASCII) version - 'ParityOnBytes' (LAB 01)
	printf("Byte Oriented ASCII version - Lab 01 results: \n");
	for (i = 1; i < argc; ++i) {
		rc = ParityOnBytes(argv[i], strlen(argv[i]));
		printf("For %s, ParityOnBytes() is %s.\n", argv[i], (rc == PAR_EVEN) ? "even" : ((rc == PAR_ODD) ? "odd" : "ERROR"));
	}
	printf("\n\n");

	// Test the bit-oriented version - 'Parity' (LAB 02)
	// To do this we first need to convert the ASCII characters to bits - Not trivial since the length could be ANYTHING ( need to use PackToBits() )
	printf("Bit-oriented version - Lab 02 results: \n");
	for (i = 1; i < argc; ++i) {
		// Convert from string to packed bits
		bPackedString = PackToBits(argv[i], strlen(argv[i]), &iPackedLen);   // argv[i] is the ith char string input by user (i.e. 1100 ), i elements are separated by spaces
																			// &iPackedLen is the memory location of the int iPackedLen which is passed to PackToBits() and stores the value iOutLen (length of buf in bits)
		//bPackedString points to the bits in memory. Passing reference of iPackedLen so we can write to it
		if (bPackedString) {  // i.e. if not NULL. It is NULL if an error occurs in PackToBits, i.e. if a non 0 or 1 is passed to it
			rc = Parity(bPackedString, iPackedLen);
			printf("For %s, Parity() is %s. \n", argv[i], (rc == PAR_EVEN) ? "even" : ((rc == PAR_ODD) ? "odd" : "ERROR"));
			free(bPackedString);
		}
		else {
			fprintf(stderr, "Bad test string, or unable to allocate space for %s. \n", argv[i]);
		}
	}

	printf("Press any key to end program ...");
	getchar();  // Keep console open until user presses enter 
	return(0);
}