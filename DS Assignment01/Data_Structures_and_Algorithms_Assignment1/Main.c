/*
Data Structures and Algorithms
Assignment 1 - Queue
Created by: Tom Troczynski
Created on: Feb 07 2022
Revision: 1	Feb 07 2022
*/

#include "Queue.h"
#define ARGS 2

int main(int argc, char* argv[])
{
	if (argc > ARGS)
	{
		printf("Exiting....\n");
		printf("use: userqueue [number of users]");
		exit(EXIT_FAILURE);
	}

	int numberToCreate = atoi(argv[argc - 1]);
	PQUEUE userQueue = NULL;

	userQueue = createList();

	if (userQueue)
	{
		if (enqueue(numberToCreate, userQueue) == 0)
		{
			printf("Failed to create a queue of users\n");
		}
	}
	else
	{
		printf("Failed to create a list\n");
	}

	printf("After Enqueue:\n");
	displayQueue(userQueue);

	while (!isEmpty(userQueue))
	{
		printf("\nDequeued this node:\n");
		displayNode(dequeue(userQueue));
	}
	
	freeQueue(userQueue);
	
	return 0;
}