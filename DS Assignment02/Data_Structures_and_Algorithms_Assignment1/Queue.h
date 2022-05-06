#pragma once
#include <string.h>
#include "Node.h"
#include "Randomize.h"
#include <stdio.h>
#include <time.h>

typedef struct list {
	PUSER first;
	PUSER last;
}QUEUE, * PQUEUE;



int isEmpty(PQUEUE);
USER dequeue(PQUEUE);
int enqueue(int, PQUEUE);
PQUEUE createList();
PUSER getFirstUser(PQUEUE);
void freeQueue(PQUEUE);

