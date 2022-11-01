#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>
#include"arrays.h"


int main()
{
	srand(time(NULL));
	int rands = -1;
	int* array = NULL;
	setlocale(LC_ALL, "");
	int razmer = 0;
	printf("Введите размерность массива:\nДля рандомной генерации введите '0'\n");
	raz(&razmer);
	if (razmer == 0)
	{
		razmer = rand() % (200 + 100);
		printf("Размерность вашего массива: %d\n", razmer);
	}
	array = malloc(sizeof(int) * razmer);
	printf("Если вы хотите продолжить ввод с клавиатуры введите '0'\nЕсли вы хотите случайно сгенерировать числа введите '1'\n");
	while (!scanf_s("%d", &rands) && rands != 0 || rands != 1)
	{
		rewind(stdin);
		printf("Неверный тип данных\n");
	}
		if (rands == 0)
		{
			for (int i = 0; i < razmer; i++)
			{
				printf("Введите %d-ый элемент массива", i);
				element(&array[i]);
			}
		}
		else if (rands == 1)
		{
			for (int i = 0; i < razmer; i++)
			{
				*(array+i) = rand() % 300 - 150;
			}
			printf("Ваш массив:");
			PrintArray(razmer, array);
		}
		for (int i = 0; i < razmer; i++)
		{
			if (*(array + i) < 0)
			{
				*(array + i) = 0;
			}
		}
		printf("\nПолученный массив:\n");
		PrintArray(razmer, array);

}