#include "Sort.h"

//swapping as it moves to i = 0
//scans size -1 times
//looping n - 1 times each time
//checks adjacent elements
//brings smallest forward in the array
void bubbleSort(int intArray[], int size)
{
	int i, j, tmp;
	
	for ( i = 0; i < ARRSIZE - 1; i++) {
		for (j = 0; j < ARRSIZE - 1 - i; j++) {
			if (intArray[j] > intArray[j + 1]) {
				swap(&intArray[j], &intArray[j + 1]);
			}
		}
	}
}

//makes a Max heap by heapifying recursively 
//sorts largest to smallest in level order
void makeHeap(int inArray[], int size) {
	int lastNonLeaf = (size / 2) -1;
	
	for (int i = lastNonLeaf; i >= 0; i--) {
		heapify(inArray, size, i);
	}
}

//heapifies the array...then....
//repeats: swapping, heapifying then reducing the heap size
//since the tree is already heapified, the heap size is max size on the first loop
//so we swap first to move the largest value to the last node of the heap, and the smallest to the root
//We heapify to maintain the Max heap condition. This reorganizes the heap so Largest value is in root
//the swap keeps the unsorted nodes in the tree, each time moving the largest to a place in the heap
//that the subsequent reduction in heap size prevents the heapify function from reaching afterwards
//This way the largest is always heapified to the top (found) and swapped with a value that is smallest
//and reduces the heap size keeping the sorted values at the end of the heap untouched, while breaking the
//max heap condition so that a new largest is found.
void heapSort(int arr[], int size)
{
	int heapSize = size - 1;

	makeHeap(arr, size);
	for (int i = heapSize; i >= 0; i--) {
		swap(&arr[ROOT], &arr[i]);
		heapify(arr, i, ROOT);
	}
}
void heapify(int arr[ARRSIZE], int size, int root)
{
	int parent = root;
	int leftChild = (2 * parent) + 1;
	int rightChild = (2 * parent) + 2;
	int largest = root;

	if (arr[leftChild] > arr[largest] && leftChild < size) {
		largest = leftChild;
	}
	if (arr[rightChild] > arr[largest] && rightChild < size) {
		largest = rightChild;
	}

	if (largest != root) {
		swap(&arr[parent], &arr[largest]);
		heapify(arr, size, largest);
	}
}

void swap(int* intA, int* intB) {
	int temp = *intA;
	*intA = *intB;
	*intB = temp;
}
