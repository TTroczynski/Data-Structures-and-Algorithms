#include "Tree.h"
#include <time.h>
#define INPUTMAX 20
#define INPUTMIN 11
#define ASCIIHIGH 123
#define ASCIILOW 97

int generateSet(char* destination);

int main(void) {

	TREE treeRoot = NULL;
	char randomSet[INPUTMAX + 1];
	
	srand(time(0));
	int setLength = generateSet(randomSet);

	for (int i = 0; i < setLength; i++) {

		insert(&treeRoot, randomSet[i]);
	}

	printf("Generated set: %s\n", randomSet);
	displayTree(treeRoot);
	printf("Node count: %d\n", countNodes(treeRoot));
	printf("Tree height: %d\n", treeHeight(treeRoot));

	removeNodes(treeRoot);
	free(treeRoot);

	return 0;
}

int generateSet(char* destination) {

	int randomIndexMax = (rand() % (INPUTMAX - INPUTMIN)) + INPUTMIN;
	int randomCharacter;
	char TERMINATOR = '\0';
	int index = 0;

	for (index; index < randomIndexMax; index++)
	{
		randomCharacter = rand() % (ASCIIHIGH - ASCIILOW) + ASCIILOW;
		destination[index] = randomCharacter;
	}
	destination[index] = TERMINATOR;

	return index;
}