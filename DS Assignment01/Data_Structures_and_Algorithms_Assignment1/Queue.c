#include "Queue.h"

int isEmpty(PQUEUE queue)
{
	if (queue->first == NULL && queue->last == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
USER dequeue(PQUEUE queue)
{
	USER tempUser = { 0 };
	PUSER pUserNode = queue->first;

	if (pUserNode != NULL)
	{
		tempUser = *pUserNode;
		queue->first = queue->first->next;
		free(pUserNode);
	}
	if(queue->first == NULL)
	{
		queue->last = NULL;
	}

	return tempUser;
}
int enqueue(int toAdd, PQUEUE queue)
{
	srand((unsigned int)time(NULL));
	char newName[N];
	PUSER newUser = NULL;

	for (int i = 0; i < toAdd; i++)
	{
		randomName(newName);
		newUser = createUser(newName, randomLevel(), randomFaction());
		if (newUser)
		{
			if (queue->first == NULL)
			{
				queue->first = newUser;
				queue->last = newUser;
			}
			else
			{
				queue->last->next = newUser;
				queue->last = newUser;
			}
		}
		else
		{
			return 0;
		}
	}

	return 1;
}
PQUEUE createList()
{
	PQUEUE queueList = NULL;
	queueList = (PQUEUE)malloc(sizeof(QUEUE));
	if (!queueList)
	{
		printf("Failed to allocate memory for a queue\n");
		return NULL;
	}
	else
	{
		queueList->first = NULL;
		queueList->last = NULL;
	}
	
	return queueList;
}

void displayQueue(PQUEUE queue)
{
	PUSER pTempUser = queue->first;
	USER user;
	while (pTempUser)
	{
		user = *pTempUser;
		displayNode(user);
		pTempUser = pTempUser->next;
	}
}

void freeQueue(PQUEUE userQueue)
{
	while (!isEmpty(userQueue))
	{
		dequeue(userQueue);
	}
	free(userQueue);
}
