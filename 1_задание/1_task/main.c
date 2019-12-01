//������� � 1. ������ �������
//������� ��������������

#include "stdio.h"
#include "locale.h"
#include "math.h"
#include "windows.h"

//������� ���������������� �������:
double massIndex(double weight, double height); //1 �������
int exchange_by_3_var(int first, int second); // 2 �������
int exchange_by_2_var(int first, int second); // 2 ������� �� ����������
void squareRootFunc(double a, double b, double c); // 3 �������
void age(int year); // 4 �������
void chess(int x1, int y1, int x2, int y2); // 5 �������
void automorth(int number); // 6 �������

enum CHESS_WORDS {
		A, B, C, D, E, F, G, H
	};
	enum CHESS_WORDS word_var;

//�������� ����
int main() {
	//����������� ���������:
	setlocale(LC_ALL, "");
	printf("\n1 ����. ��������: ������� ������.\n");
	//���� ����������:
	double height = 181; //���� ��
	double weight = 67; // ��� ��
	//��������� 1 �������:
	massIndex(weight, height);
	//���� ����������:
	int first = 12;
	int second = 45;
	//��������� 2 �������:
	exchange_by_3_var(first, second);
	exchange_by_2_var(first, second);
	//��������� 3 �������:
	squareRootFunc(1, -5, 6);
	//��������� 4 �������:
	age(1);
	age(12);
	age(4);
	age(10);
	age(133);
	age(150);
	//��������� 5 �������
	chess(E, 2, E, 4);
	chess(E, 2, H, 8);
	// ��������� 6 �������
	automorth(10000);
	return 0;
}

//������� ����������� �������:
/*
������� 1 ������ ������: 
������ ��� � ���� ��������. ���������� � ������� ������ ����� ���� �� ������� I=m/(h*h);
��� m-����� ���� � �����������, h - ���� � ������.
*/
double massIndex(double weight, double height)
{	
	double metres = height * 0.01;
	printf("1 ������: \n");
	printf("���� �������� ����� (�): %2.2f\n", metres);
	printf("����� �������� ����� (��): %2.2f\n", weight);
	double index = weight / (metres*metres);
	printf("������ ����� ���� �����: %2.2f\n\n", index);
	return index;
}

/*
������� 2 ������ ������:
�������� ��������� ������ ���������� ���� ������������� ����������:
b. *��� ������������� ������� ����������.
*/
int exchange_by_3_var(int first, int second)
{	
	printf("2 ������: \n");
	printf("������ ���������� �����: %d\n", first);
	printf("������ ���������� �����: %d\n", second);
	printf("�������� ��������: \n");
	int c;
	c = first;
	first = second;
	second = c;
	printf("������ ������ ���������� �����: %d\n", first);
	printf("������ ������ ���������� �����: %d\n\n", second);
	return 0;
}

int exchange_by_2_var(int first, int second)
{
	printf("2 ������ �� ����������: \n");
	printf("������ ���������� �����: %d\n", first);
	printf("������ ���������� �����: %d\n", second);
	printf("�������� ��������. \n");
	first ^= second;
	second ^= first;
	first ^= second;
	printf("������ ������ ���������� �����: %d\n", first);
	printf("������ ������ ���������� �����: %d\n\n", second);
	return 0;
}

/*
������� 3 ������ ������:
�������� ��������� ���������� ������ ��������� ����������� ���������.
*/
void squareRootFunc(double a, double b, double c)
{
	printf("3 ������: \n");
	printf("� ��� ������� ���������: y=x^2*(%.1f)+x*(%.1f)+(%.1f).\n", a, b, c);
	double discriminant = pow(b, 2) - 4 * a * c;
	if (discriminant > 0) {
		printf("������ ������ ��������� �����: %2.2f\n", ((-b + pow(discriminant, (1 / 2))) / (2 * a)));
		printf("������ ������ ��������� �����: %2.2f\n\n", ((-b - pow(discriminant, (1 / 2))) / (2 * a)));
	}
	else if (discriminant == 0)
	{
		printf("������ ��������� �����: %2.2f\n\n", (-b / (2 * a)));
	}
	else {
		printf("��������� �� ����� �������.\n\n");
	}
}

/*
������� 4 ������ ������:
������ ������� �������� (�� 1 �� 150 ���) � ������� ��� ������ � �����������
������ ����, ����� ��� ����.
*/
void age(int year)
{
	printf("4 ������: ");
	printf("%d ", year);
	if (year % 10 == 1) {
		printf("���.\n");
	}
	else if (year % 10 >= 2 && year % 10 <= 4 && year % 100 != 12 && year % 100 != 13 && year % 100 != 14) {
		printf("����.\n");
	}
	else { 
		printf("���.\n");
	}
	return 0;
}

/*
������ 5.
���������� �������� ���������� ���� ����� ��������� ����� (x1,y1,x2,y2).
��������� ����������, ��������� �� ���� � ������ ����� ��� ���.
*/
void chess(int x1, int y1, int x2, int y2) {
	printf("\n5 �������.\n");
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
		printf("������ [%s%d] � [%s%d]: ����������� �����.\n", words[x1], y1, words[x2], y2);
	}
	else
	{
		printf("������ [%s%d] � [%s%d]: ������� �����.\n", words[x1], y1, words[x2], y2);
	}
}
/*
6 �������
����������� �����. ����������� ����� ���������� �����������,
���� ��� ����� ��������� ������ ������ ��������. ��������, 25 ^ 2 = 625. 
�������� ���������, ������� ������ ����������� ����� N � ������� �� ����� ��� ����������� �����, �� ������������� N.
*/
void automorth(int number) {
	printf("\n6 �������.\n");
	for (int i = 1; i <= number; i++) {
		if (((i * i) % i == 0) && ((i * i) % 10 == i) || ((i * i) % 100 == i) || ((i * i) % 1000 == i) || ((i * i) % 10000 == i)) {
			printf("%d*%d = %d\n", i, i, i);
		}
	}
}






