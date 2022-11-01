#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


void raz(int* x)
{
	while (!scanf_s("%d", x) || getchar() != '\n' || *x < 0)
	{
		rewind(stdin);
		printf("Неверный тип данных\n");
	}
}

void element(int* x)
{
	while (!scanf_s("%d", x) || getchar() != '\n')
	{
		rewind(stdin);
		printf("Неверный тип данных\n");
	}
}

void PrintArray(int* x,int*y)
{
	for (int i = 0; i < x; i++)
		printf("%d; ", y[i]);
}
