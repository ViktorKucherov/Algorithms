//Задание № 1. Виктор Кучеров
//область препроцессоров

#include "stdio.h"
#include "locale.h"
#include "math.h"
#include "windows.h"

//область прототипирования функций:
double massIndex(double weight, double height); //1 задание
int exchange_by_3_var(int first, int second); // 2 задание
int exchange_by_2_var(int first, int second); // 2 задание со звездочкой
void squareRootFunc(double a, double b, double c); // 3 задание
void age(int year); // 4 задание
void chess(int x1, int y1, int x2, int y2); // 5 задание
void automorth(int number); // 6 задание

enum CHESS_WORDS {
		A, B, C, D, E, F, G, H
	};
	enum CHESS_WORDS word_var;

//основной блок
int main() {
	//настраиваем кодировку:
	setlocale(LC_ALL, "");
	printf("\n1 УРОК. ВЫПОЛНИЛ: КУЧЕРОВ ВИКТОР.\n");
	//блок переменных:
	double height = 181; //рост см
	double weight = 67; // вес кг
	//объявляем 1 функцию:
	massIndex(weight, height);
	//блок переменных:
	int first = 12;
	int second = 45;
	//объявляем 2 функцию:
	exchange_by_3_var(first, second);
	exchange_by_2_var(first, second);
	//объявляем 3 функцию:
	squareRootFunc(1, -5, 6);
	//объявляем 4 функцию:
	age(1);
	age(12);
	age(4);
	age(10);
	age(133);
	age(150);
	//объявляем 5 функцию
	chess(E, 2, E, 4);
	chess(E, 2, H, 8);
	// объявляем 6 функцию
	automorth(10000);
	return 0;
}

//область определения функций:
/*
Функция 1 решает задачу: 
Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h);
где m-масса тела в килограммах, h - рост в метрах.
*/
double massIndex(double weight, double height)
{	
	double metres = height * 0.01;
	printf("1 задача: \n");
	printf("Рост человека равен (м): %2.2f\n", metres);
	printf("Масса человека равна (кг): %2.2f\n", weight);
	double index = weight / (metres*metres);
	printf("Индекс массы тела равен: %2.2f\n\n", index);
	return index;
}

/*
Функция 2 решает задачу:
Написать программу обмена значениями двух целочисленных переменных:
b. *без использования третьей переменной.
*/
int exchange_by_3_var(int first, int second)
{	
	printf("2 задача: \n");
	printf("Первая переменная равна: %d\n", first);
	printf("Вторая переменная равна: %d\n", second);
	printf("Обменяем значения: \n");
	int c;
	c = first;
	first = second;
	second = c;
	printf("Теперь первая переменная равна: %d\n", first);
	printf("Теперь вторая переменная равна: %d\n\n", second);
	return 0;
}

int exchange_by_2_var(int first, int second)
{
	printf("2 задача со звездочкой: \n");
	printf("Первая переменная равна: %d\n", first);
	printf("Вторая переменная равна: %d\n", second);
	printf("Обменяем значения. \n");
	first ^= second;
	second ^= first;
	first ^= second;
	printf("Теперь первая переменная равна: %d\n", first);
	printf("Теперь вторая переменная равна: %d\n\n", second);
	return 0;
}

/*
Функция 3 решает задачу:
Написать программу нахождения корней заданного квадратного уравнения.
*/
void squareRootFunc(double a, double b, double c)
{
	printf("3 задача: \n");
	printf("У нас имеется уравнение: y=x^2*(%.1f)+x*(%.1f)+(%.1f).\n", a, b, c);
	double discriminant = pow(b, 2) - 4 * a * c;
	if (discriminant > 0) {
		printf("Первый корень уравнения равен: %2.2f\n", ((-b + pow(discriminant, (1 / 2))) / (2 * a)));
		printf("Второй корень уравнения равен: %2.2f\n\n", ((-b - pow(discriminant, (1 / 2))) / (2 * a)));
	}
	else if (discriminant == 0)
	{
		printf("Корень уравнения равен: %2.2f\n\n", (-b / (2 * a)));
	}
	else {
		printf("Уравнение не имеет решения.\n\n");
	}
}

/*
Функция 4 решает задачу:
Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим
словом «год», «года» или «лет».
*/
void age(int year)
{
	printf("4 задача: ");
	printf("%d ", year);
	if (year % 10 == 1) {
		printf("год.\n");
	}
	else if (year % 10 >= 2 && year % 10 <= 4 && year % 100 != 12 && year % 100 != 13 && year % 100 != 14) {
		printf("года.\n");
	}
	else { 
		printf("лет.\n");
	}
	return 0;
}

/*
Задача 5.
Существуют числовые координаты двух полей шахматной доски (x1,y1,x2,y2).
Требуется определить, относятся ли поля к одному цвету или нет.
*/
void chess(int x1, int y1, int x2, int y2) {
	printf("\n5 задание.\n");
	char* words[] = { "A","B","C","D","E","F","G","H" };
	enum SQUARES {
		WHITE,
		BLACK
	};
	const char* colours[] = { "WHITE","BLACK" };
	int desk[8][9] = { 0 };
	for (int i = 0; i < 8; i++) {
		for (int j = 1; j <= 8; j++) {
			if ((j-1) % 8 == 0) { printf("\n\n"); }
			if ((i + j) % 2 == 0) { desk[i][j] = WHITE; }
			else { desk[i][j] = BLACK; };
			printf("[%s%d]:%s ", words[i], j, colours[desk[i][j]]);
		}
	}
	printf("\n\n[%s%d] = %s  ", words[x1], y1, colours[desk[x1][y1]]);
	printf("\n[%s%d] = %s  \n", words[x2], y2, colours[desk[x2][y2]]);
	if (desk[x1][y1] == desk[x2][y2]) {
		printf("Клетка [%s%d] и [%s%d]: одинакового цвета.\n", words[x1], y1, words[x2], y2);
	}
	else
	{
		printf("Клетка [%s%d] и [%s%d]: разного цвета.\n", words[x1], y1, words[x2], y2);
	}
}
/*
6 задание
Автоморфные числа. Натуральное число называется автоморфным,
если оно равно последним цифрам своего квадрата. Например, 25 ^ 2 = 625. 
Напишите программу, которая вводит натуральное число N и выводит на экран все автоморфные числа, не превосходящие N.
*/
void automorth(int number) {
	printf("\n6 задание.\n");
	for (int i = 1; i <= number; i++) {
		if (((i * i) % i == 0) && ((i * i) % 10 == i) || ((i * i) % 100 == i) || ((i * i) % 1000 == i) || ((i * i) % 10000 == i)) {
			printf("%d*%d = %d\n", i, i, i);
		}
	}
}






