// 3_task.cpp: ���������� ����� ����� ��� ����������� ����������.
#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "math.h"
//#include "stdafx.h"
#include "locale.h"

#define numberElements 10

void swapFunc(int* first, int* second) {
	*first ^= *second;
	*second ^= *first;
	*first ^= *second;
}
void printArray(int* arr) {
	for (int i = 0; i < numberElements; i++) {
		printf("%d ", *(arr + i));
	}
	printf("\n");
}
void fillArray(int* arr) {
	for (int i = 0; i < numberElements; i++) {
		printf("array[%d] = ", i);
		scanf_s("%d", &arr[i]);
	}
}
void myBubbleSort(int* arr) {
	int operation = 0;
	for (int i = 0; i < numberElements; i++) {
		short boolVar = 1;
		for (int j = 0; j < numberElements - (i + 1); j++) {
			if (arr[j] > arr[j + 1]) {
				boolVar = 0;
				swapFunc(&arr[j], &arr[j + 1]);
				operation++; // 2 task
			}
		}
		if (boolVar == 1) {
			printf("��������� ��������: [%d]\n", operation);
			break;
		}
	}
}

void myShakeSort(int* arr) {
	short boolVar = 1;
	int fromRight = numberElements;
	int fromLeft = 1;
	do {
		boolVar = 1;
		for (int i = fromLeft; i < fromRight; i++) {
			if (arr[i - 1] > arr[i]) {
				swapFunc(&arr[i - 1], &arr[i]);
				boolVar = 0;
			}
		}
		fromRight--;
		for (int i = fromRight; i >= fromLeft; i--) {
			if (arr[i] < arr[i - 1]) {
				swapFunc(&arr[i - 1], &arr[i]);
				boolVar = 0;
			}
		}
		fromLeft++;
	} while (boolVar == 0);
}

void myListSearch(int* arr) {
	printf("�������� ������ �� 10 ���������:\n");
	fillArray(arr);
	int keyNumber = 0;
	int jIndex = 0;
	int resultIndexes[numberElements] = { 0 };
	printf("������� �������� ��� ������: ");
	scanf_s("%d", &keyNumber);
	for (int i = 0; i < numberElements; i++) {
		if (arr[i] == keyNumber) {
			resultIndexes[jIndex++] = i;
		}
	}
	if (jIndex != 0) {
		for (int j = 0; j < jIndex; j++) {
			printf("����� %d ��������� � ������� �������: [%d]\n", keyNumber, resultIndexes[j]);
		}
	}
	else {
		printf("����� %d ����������� � ������!\n", keyNumber);
	}

}


void myLineSearchRecursive(int* arr, int * resultIndexes, int keyNumber, int i, int jIndex) {
	
	if (i < numberElements-1) {
		if (arr[i] == keyNumber) {
			resultIndexes[jIndex++] = i;
		}
		myLineSearchRecursive(arr, resultIndexes, keyNumber, i++, jIndex);
	}
	else {
		if (jIndex != 0) {
			for (int j = 0; j < jIndex; j++) {
				printf("����� %d ��������� � ������� �������: [%d]\n", keyNumber, resultIndexes[j]);
			}
		}
		else {
			printf("����� %d ����������� � ������!\n", keyNumber);
		}
	}

}


void myListSearch(int *rawArr, int *sortedArr)
{
	int orderIndex;
	for (int i = 0; i < numberElements; i++)
	{
		orderIndex = 0;
		for (int j = 0; j < numberElements; j++)
		{
			if (* (rawArr + i) > * (rawArr + j))
				orderIndex++;
		}
		sortedArr[orderIndex] = rawArr[i];
	}
}

int main(int argc, const char** argv) {
	setlocale(LC_ALL, "rus");
	int array[numberElements];
	int array2[numberElements] = {0};
	//1+2 task (����������� ���������� - ����������������) + ������� ���������� �������� swap
	/*fillArray(array);
	printArray(array);
	myBubbleSort(array);
	printArray(array);*/

	//3 task (��������� ����������)
	/*fillArray(array);
	printArray(array);
	myShakeSort(array);
	printArray(array);*/

	// 4.1 �������� �����
	myListSearch(array);

	//4.2 task (�������� ����� ���������)
	/*printf("�������� ������ �� 10 ���������:\n");
	fillArray(array);
	int keyNumber = 0;
	int i = 0;
	int jIndex = 0;
	int resultIndexes[numberElements] = { 0 };
	printf("������� �������� ��� ������: ");
	scanf_s("%d", &keyNumber);
	myLineSearchRecursive(array, resultIndexes, keyNumber, i, jIndex);*/
	
	//5 task (���������� ���������)
	/*fillArray(array);
	printArray(array);
	myListSearch(array, array2);
	printArray(array2);*/
	//_gettch();
	return 0;
}
