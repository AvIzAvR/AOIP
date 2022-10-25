#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

int mass[100][100];
int x, y;

int main()
{
	setlocale(LC_ALL, "RUS");
	int row;
	int pred, true, rands, prin = 0;
	int brain = 1;
	srand(time(NULL));
	printf("Введите размерность массива(NxN):\nДля случайной генерации размерности введите \"0\"\n");
	scanf_s("%d", &row);
	if (row < 0 && row != 0 || row > 100)
	{
		while (row < 0 && row != 0 || row > 100)
		{
			rewind(stdin);
			printf("Неверно введённый тип данных.\n");
			printf("Введите размерность массива(NxN):\nДля случайной генерации размерности введите \"0\"\n");
			scanf_s("%d", &row);
		}
	}
	else if (row > 0)
	{
		row--;
		mass[row][row];
	}
	else if (row == 0)
	{
		printf("Введите максимальное случайное число:");
		int random;
		rewind(stdin);
		scanf_s("%d", &random);
		if (random < 0 && random != 0)
		{
			while (random < 0 && random != 0)
			{
				printf("Неверно введённый тип данных.\n");
				printf("Введите максимальное случайное число:");
				rewind(stdin);
				scanf_s("%d", &random);
			}
		}
		if (random > 0)
		{
			row = rand() % random;
			mass[row][row];
		}
	}
	printf("Если хотите продолжить ввод чисел с клавиатуры введите \"1\"\nЕсли хотите сгенерировать числа случайно введите \"2\"\n");
	scanf_s("%d", &rands);
	if (rands != 1 && rands != 2)
	{
		while (rands != 1 && rands != 2)
		{
			printf("Неверно введённый тип данных.\n");
			printf("Если хотите продолжить ввод чисел с клавиатуры введите \"1\"\nЕсли хотите сгенерировать числа случайно введите  \"2\"\n");
			rewind(stdin);
			scanf_s("%d", &rands);
		}
	}
	if (rands == 1)
	{
		for (int i = 0; i <= row; i++)
		{
			for (int k = 0; k <= row; k++)
			{
				printf("Введите элемент %d столбца, %d строки\n", i, k);
				while (!scanf_s("%d", &true))
				{
					printf("Неверно введённый тип данных.\n");
					printf("Введите %d-е число массива\n", i);
					rewind(stdin);
				}
				mass[i][k] = true;
				printf("%d; ", mass[i][k]);
			}
		}
	}
	else if (rands == 2)
	{
		printf("Введите максимальный предел для всех чисел:\n");
		scanf_s("%d", &pred);
		if (pred < 0)
		{
			while (pred < 0)
			{
				printf("Неверно введённый тип данных.\n");
				printf("Введите максимальный предел для всех чисел:\n");
				rewind(stdin);
				scanf_s("%d", &pred);
			}
		}
		if (pred > 0)
		{
			for (int i = 0; i <= row; i++)
			{
				for (int k = 0; k <= row; k++)
				{
					mass[i][k] = rand() % pred;
					prin++;
				}
			}
			printf("Полученный массив:\n");
			for (int i = 0; i <= row; i++)
			{
				printf("\n");
				for (int k = 0; k <= row; k++)
				{
					printf("%d ", mass[i][k]);
				}
			}
		}
	}
	row += 1;
	int sum = 0;
	for (int y = 0; y < row / 2; y++)
	{
		for (int x = row - 1 - y; x < row; x++)
		{
			sum += mass[y][x];
		}
		for (int x = row - 1 - y; x < row; x++)
		{
			sum += mass[row - y - 1][x];
		}
	}
	if (row % 2 != 0) {
		for (int x = row / 2; x < row; x++)
		{
			sum += mass[row / 2][x];
		}
	}
	printf("\nСумма треугольника: %d", sum);
}
