#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "math.h"

#define numberElements 10

void swapFunc(int* first, int* second) {
	* first ^= * second;
	* second ^= * first;
	* first ^= * second;
}

void printArray(int* arr) {
	for (int i = 0; i < numberElements; i++) {
		printf("%d ", *(arr+i));
	}
	}

void fillArray(int* arr) {
	for (int i = 0; i < numberElements; i++) {
		printf("array[%d] = ", i); 
		scanf("%d", &arr[i]);
	}
	
}

void mySort(int* arr, int lowest, int highest) {
	int i = lowest;
	int j = highest;
	int middle = arr[(lowest - highest) / 2];
	do {
		while (arr[i] < middle) i++;
		while (arr[j] > middle) j--;
		if (i <= j) {
			swapFunc(&arr[i], &arr[j]);
			//i++;
			//j--;
		}
	} while (i <= j);

	if (lowest < j) mySort(arr, lowest, j);
	if (i < highest) mySort(arr, i, highest);
}
int main(int argc, const char** argv) {
	
	int array[numberElements];

	fillArray(array);
	mySort(array, 0, numberElements - 1);
	printArray(array);

	return 0;
}