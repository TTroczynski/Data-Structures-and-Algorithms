#include "Sort.h"
#include <stdio.h>

int randomInt() {

	return rand() % INT_MAX;
}

int main(void) {

	srand(time(NULL));

	int rand_Array_Bubble[ARRSIZE] = {-1 };
	int rand_Array_HeapSort[ARRSIZE] = { -1 };
	int out_Arr[ARRSIZE] = { -1 };
	int randomValue = 0;

	for (int i = 0; i < ARRSIZE; i++) {
		randomValue = randomInt();
		rand_Array_Bubble[i] = randomValue;
		rand_Array_HeapSort[i] = randomValue;
	}

	double sortTime = 0;
	clock_t bubbleSortTime_Start = clock();
	bubbleSort(rand_Array_Bubble, ARRSIZE);
	clock_t bubbleSortTime_End = clock();
	sortTime = (double)(bubbleSortTime_End - bubbleSortTime_Start) / CLOCKS_PER_SEC;

	printf("Bubble sort time: %lf\n", sortTime);
	
	clock_t heapSortTime_Start = clock();
	heapSort(rand_Array_HeapSort, ARRSIZE);
	clock_t heapSortTime_End = clock();
	sortTime = (double)(heapSortTime_End - heapSortTime_Start) / CLOCKS_PER_SEC;

	printf("Heap sort time: %lf", sortTime);

	return 0;
}

