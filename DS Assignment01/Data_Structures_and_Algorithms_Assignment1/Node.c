#include "Node.h"

PUSER createUser(char name[N], int level, FACTION playerFaction)
{
	PUSER newUser = NULL;
	newUser = (PUSER)malloc(sizeof(USER));
	if (!newUser)
	{
		printf("Failed to allocate memory for a new user\n");
	}
	else
	{
		strcpy_s(newUser->userName, (rsize_t)N, name);
		newUser->level = level;
		newUser->userFaction = playerFaction;
		newUser->next = NULL;
	}
	
	return newUser;
}

void displayNode(USER userNode)
{
	printf("Name: %s, Level: %d, Faction: %d\n", userNode.userName, userNode.level, userNode.userFaction);
}
