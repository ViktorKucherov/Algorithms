// 3_task.cpp: определяет точку входа для консольного приложения.
#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "math.h"
#include <stdlib.h>
#include <string.h>
#include <io.h>

//#include "stdafx.h"
#include "locale.h"

#define numberElements 10

int myBinarySearchMainFunc(int* arr, int searchingKey, int right, int left) {
	if (arr[right] > searchingKey || arr[left] < searchingKey) { //сразу проверяем на наличие элемента в списке
		return numberElements;
	}
	int middle;
	middle = (left+right) / 2; // определяем середину
	if (arr[middle] == searchingKey) {
		return middle;
	}
	else {
		if (arr[middle] > searchingKey) {
			return myBinarySearchMainFunc(arr, searchingKey, right, middle-1);
		}
		else {
			return myBinarySearchMainFunc(arr, searchingKey, middle+1, left);
		}
	} 

}

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
			printf("Проведено операций: [%d]\n", operation);
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
	printf("Создайте массив из 10 элементов:\n");
	fillArray(arr);
	int keyNumber = 0;
	int jIndex = 0;
	int resultIndexes[numberElements] = { 0 };
	printf("Введите значение для поиска: ");
	scanf_s("%d", &keyNumber);
	for (int i = 0; i < numberElements; i++) {
		if (arr[i] == keyNumber) {
			resultIndexes[jIndex++] = i;
		}
	}
	if (jIndex != 0) {
		for (int j = 0; j < jIndex; j++) {
			printf("Цифра %d находится в индексе массива: [%d]\n", keyNumber, resultIndexes[j]);
		}
	}
	else {
		printf("Цифра %d отсутствует в списке!\n", keyNumber);
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
				printf("Цифра %d находится в индексе массива: [%d]\n", keyNumber, resultIndexes[j]);
			}
		}
		else {
			printf("Цифра %d отсутствует в списке!\n", keyNumber);
		}
	}

}

void myLineSearch(int *rawArr, int *sortedArr)
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
	int arr[numberElements];
	int array2[numberElements] = {0};


	int s = 301, n = 0;
	while (s>0){
		s = s - 10;
		n = n + 2;
	}
	printf("%d\n\n", n);

	//4.3 Реализовать бинарный поиск.
	printf("Реализуем бинарный поиск в массиве.\nВведите элементы массива:\n");
	fillArray(&arr); // для начала создадим массив
	printArray(&arr); // выведем его в консоль

	printf("Отсортируем массив:\n");
	myShakeSort(&arr); //отсортируем шейкерной сортировкой
	printArray(&arr); // посмотрим что получилось

	int right, left;
	right = 0;
	left = numberElements-1;
	int searchingKey;
	printf("\nВведите число для поиска:\n");
	scanf_s("%d", &searchingKey);


	int result = myBinarySearchMainFunc(arr, searchingKey, right, left);
	searchingKey == arr[result] ? printf("Данное значение содержится в массиве под индексом %d", result) : printf("Данного числа в массиве нет!");


	
					   
					   
					   
					   
					   
					   
					   
					   
					   
					   
					   
					   
					   
					   
					   
	//1+2 task (Пузырьковая сортировка - модифицированная) + Подсчет количества операций swap
	/*fillArray(array);
	printArray(array);
	myBubbleSort(array);
	printArray(array);*/

	//3 task (Шейкерная сортировка)
	/*fillArray(array);
	printArray(array);
	myShakeSort(array);
	printArray(array);*/

	// 4.1 Линейный поиск
	//myListSearch(array);

	//4.2 task (Линейный поиск рекурсией)
	/*printf("Создайте массив из 10 элементов:\n");
	fillArray(array);
	int keyNumber = 0;
	int i = 0;
	int jIndex = 0;
	int resultIndexes[numberElements] = { 0 };
	printf("Введите значение для поиска: ");
	scanf_s("%d", &keyNumber);
	myLineSearchRecursive(array, resultIndexes, keyNumber, i, jIndex);*/
	
	//5 task (Сортировка подсчетом)
	/*fillArray(array);
	printArray(array);
	myListSearch(array, array2);
	printArray(array2);*/
	//_gettch();
	return 0;
}
