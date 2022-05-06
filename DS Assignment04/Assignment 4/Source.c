#include "RunLengthEncoding.h"

int main(void) {

	char test[BUFFLEN] = "AAAAAAAAAAAAAAAAAAAAAAAABBAABBBBBBBAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABBABABA";
	char output[BUFFLEN] = { 0 };
	char original[BUFFLEN] = { 0 };
	int result = encode(test, output);
	int check = decode(output, original);

	printf("Original character count: %d\n", result);
	printf("input string: %s\n\n", test);

	printf("Encoded output character count: %d\n", (int)strnlen_s(output, BUFFLEN));
	printf("encoded output: %s\n\n", output);
	
	printf("Decode character count: %d\n", check);
	printf("output string: %s\n", original);


	return 0;
}