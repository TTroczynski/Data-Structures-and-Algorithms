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

void getFaction(char* destination, PUSER userNode) {
	char redFaction[] = "red";
	char blueFaction[] = "blue";
	char greenFaction[] = "green";
	switch (userNode->userFaction)
	{
	case 0:
		strcpy_s(destination, (rsize_t)sizeof(redFaction), redFaction);
		break;
	case 1:
		strcpy_s(destination, (rsize_t)sizeof(blueFaction), blueFaction);
		break;
	case 2:
		strcpy_s(destination, (rsize_t)sizeof(greenFaction), greenFaction);
		break;
	default:
		break;
	}
	return;
}

void displayNode(PUSER userNode)
{
	char color[FACTIONLENGTH];
	getFaction(color, userNode);

	printf("Name: %s, Level: %d, Faction: %s\n", userNode->userName, userNode->level, color);
}

void traverse(PUSER pUser) {
	if (!pUser) {
		return 0;
	}
	displayNode(pUser);
	traverse(pUser->next);

	return 0;
}

void traverseR(PUSER pUser) {
	if (!pUser) {
		return 0;
	}
	traverseR(pUser->next);
	displayNode(pUser);

	return 0;
}