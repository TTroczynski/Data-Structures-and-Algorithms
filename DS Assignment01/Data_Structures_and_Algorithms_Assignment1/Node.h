#pragma once
#include <stdlib.h>
#include <stdio.h>

#define N 25

typedef enum faction { RED, BLUE, GREEN } FACTION;

typedef struct node
{
	char userName[N];
	int level;
	FACTION userFaction;
	struct node* next;

}USER, *PUSER;

PUSER createUser(char[N], int, FACTION);

void displayNode(USER);

