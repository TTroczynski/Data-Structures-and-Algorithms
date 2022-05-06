#pragma once
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#define ARRSIZE 20000
#define EMPTY -1
#define ROOT 0

void bubbleSort(int[], int);

void heapSort(int[], int index);

void heapify(int arr[ARRSIZE], int size, int root);

void makeHeap(int inArray[], int size);

void swap(int*, int*);

bool less(int, int);





