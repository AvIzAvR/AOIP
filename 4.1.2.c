#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

int mass[100][100];
int proverka = 0;
int x, y;
int CheckRowMax(int row, int col) {
	int got = mass[col][row];
	int max = mass[col][row];
	for (int j = 0; j <= y; j++) {
		if (mass[col][j] > max) {
			max = mass[col][j];
		}
	}
	return got == max ? 1 : 0;
}

int CheckRowMin(int row, int col) {
	int got = mass[col][row];
	int min = mass[col][row];
	for (int j = 0; j <= y; j++) {
		if (mass[col][j] < min) {
			min = mass[col][j];
		}
	}
	return got == min ? 1 : 0;
}

int CheckcolMax(int row, int col) {
	int got = mass[col][row];
	int max = mass[col][row];
	for (int j = 0; j <= x; j++) {
		if (mass[j][row] > max) {
			max = mass[j][row];
		}
	}
	return got == max ? 1 : 0;
}

int CheckcolMin(int row, int col) {
	int got = mass[col][row];
	int min = mass[col][row];
	for (int j = 0; j <= x; j++) {
		if (mass[j][row] < min) {
			min = mass[j][row];
		}
	}
	return got == min ? 1 : 0;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int row, col;
	int pred, true, rands, prin = 0;
	int brain = 1;
	srand(time(NULL));
	printf("Введите количество строк массива(не более 100):\nДля случайной генерации количества строк введите \"0\"\n");
	scanf_s("%d", &row);
	if (row < 0 && row != 0 || row > 100)
	{
		while (row < 0 && row != 0 || row > 100)
		{
			rewind(stdin);
			printf("Неверно введённый тип данных.\n");
			printf("Введите количества строк массива:\nДля случайной генерации количества строк введите \"0\"\n");
			scanf_s("%d", &row);
		}
	}
	else if (row > 0)
	{
		mass[row--][100];
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
			mass[row][100];
		}
	}
	printf("Введите количество cтолбцов массива(не более 100):\nДля случайной генерации количества столбцов введите \"0\"\n");
	scanf_s("%d", &col);
	if (col < 0 && col != 0 || col > 100)
	{
		while (col < 0 && col != 0 || col > 100)
		{
			rewind(stdin);
			printf("Неверно введённый тип данных.\n");
			printf("Введите количества строк массива:\nДля случайной генерации количества строк введите \"0\"\n");
			scanf_s("%d", &col);
		}
	}
	else if (col > 0)
	{
		mass[row][col--];
	}
	else if (col == 0)
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
			col = rand() % random;
			mass[row][col];
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
		proverka = 2;
		for (int i = 0; i <= row; i++)
		{
			for (int k = 0; k <= col; k++)
			{
				printf("Введите элемент %d cтроки, %d столбца\n", i, k);
				while (!scanf_s("%d", &true))
				{
					printf("Неверно введённый тип данных.\n");
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
				for (int k = 0; k <= col; k++)
				{
					mass[i][k] = rand() % pred;
					prin++;
				}
			}
		}
	}
	x = row;
	y = col;
	int number = 0;
	while (proverka == 0)
	{
		number++;
		printf("Попытка №%d \n", number);
		printf("Ваш массив:");
		for (int i = 0; i <= row; i++)
		{
			printf("\n");
			for (int k = 0; k <= col; k++)
			{
				printf("%d; ", mass[i][k]);
			}
		}
		printf("\n");
		for (int i = 0; i <= row; i++) {
			for (int j = 0; j <= col; j++) {
				if ((CheckcolMax(j, i) && CheckRowMin(j, i)))
				{
					printf("(%d,%d) = %d (Collumn max, row min)\n", j, i, mass[i][j]);
					proverka = 1;
				}

				else if (CheckcolMin(j, i) && CheckRowMax(j, i))
				{
					printf("(%d,%d) = %d (Row max, Collumn min)\n", j, i, mass[i][j]);
					proverka = 1;
				}
			}
		}
		for (int i = 0; i <= row; i++)
		{
			for (int k = 0; k <= col; k++)
			{
				mass[i][k] = rand() % pred;
				prin++;
			}
		}
	}
	if (proverka == 2)
	{
		printf("Ваш массив:");
		for (int i = 0; i <= row; i++)
		{
			printf("\n");
			for (int k = 0; k <= col; k++)
			{
				printf("%d; ", mass[i][k]);
			}
		}
		printf("\n");
		for (int i = 0; i <= row; i++) {
			for (int j = 0; j <= col; j++) {
				if ((CheckcolMax(j, i) && CheckRowMin(j, i)))
				{
					printf("(%d,%d) = %d (Collumn max, row min)\n", j, i, mass[i][j]);
					proverka = 1;
				}

				else if (CheckcolMin(j, i) && CheckRowMax(j, i))
				{
					printf("(%d,%d) = %d (Row max, Collumn min)\n", j, i, mass[i][j]);
					proverka = 1;
				}
			}
		}
	}
	system("pause");
}

