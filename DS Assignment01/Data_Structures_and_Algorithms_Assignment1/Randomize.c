#include "Randomize.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

void randomName(char newName[N])
{
	int randomIndexMax = rand() % (N-5) + 5;				//generate between 5 and 25 characters
	int randomCharacter;
	char TERMINATOR = '\0';
	int index = 0;
	for (index; index < randomIndexMax; index++)
	{
		randomCharacter = rand() % (123 - 97) + 97;			//character codes 97 to 122 are lowercase alphabetical
		newName[index] = randomCharacter;
	}
	newName[index] = TERMINATOR;
}

int randomLevel()
{
	int randomLevel = rand() % (61 - 1) + 1;				//levels 1 to 60

	return randomLevel;
}

FACTION randomFaction()
{
	FACTION randomFaction = rand() % 3;

	return randomFaction;
}