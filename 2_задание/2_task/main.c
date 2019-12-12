#include "stdio.h"
#include "locale.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "math.h"

#define _CRT_SECURE_NO_WARNINGS

//1 �������
void dec_to_bin(int dec) { //������� �������� �� 10 ������� � �������� � �������������� ��������
	if (dec / 2 != 0) {
		dec_to_bin(dec / 2);
	}
	else { 
		printf("%d", dec % 2);//������ ����� ��������� �����
		return;
	}
	printf("%d", dec % 2); //���������� ����������� �����
}

//2 �������
int recursive_power(int number, int power)
{
	return power == 0 ? 1 : number * recursive_power(number, --power);
}

//3 �������
int recursive_power_improved(int number, int power) 
{
		if (power == 0)					{ return 1; }
		int result = recursive_power_improved (number, power / 2);
		if (power % 2 == 0)				{ return result * result; }
		else							{ return number * result * result; }
}

//5 �������
int recursion(int firstNumber, int lastNumber, int temp, int i, int j, int counter)
{	temp = lastNumber - firstNumber;
	printf("\n\n%d = ", temp);
	
	if (i <= temp / 2 ) {
		printf("%d", i * 2);
		i++;
	}

	for (j = 0; j <= temp-i; j++) 
	{
		printf(" + %d", 1);
	}
	counter++;
	if (i <= temp / 2) { 
		recursion(firstNumber, lastNumber, temp, i, j, counter); 
	}
	else { 
		return counter;
	}
	
}
int calc(int from, int to) {
	if (from < to)
		return calc(from + 1, to) + calc(from * 2, to);
	else if (from == to)
		return 1;
	else
		return 0;
}


int main() {

	setlocale(LC_ALL, "");
	printf("1 �������: "); dec_to_bin(10);
	printf("\n2.1 �������: %d", recursive_power(2, 7));
	printf("\n2.2 �������: %d\n", recursive_power_improved(2, 7));
	//printf ("\n\n������� 4: ������� %d �������:", recursion(3, 20, 0, 0, 0, 0));
	printf("\n%d \n", calc(3, 20));
	return 0;
}