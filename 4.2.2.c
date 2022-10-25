#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

int main()
{
	while (1)
	{
		setlocale(LC_ALL, "RUS");
		int row, col;
		int pred, true, rands, prin = 0;
		int first = 0, proverka = 0;
		int mass[100][100];
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
			for (int i = 0; i <= row; i++)
			{
				for (int k = 0; k <= col; k++)
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
			for (int i = 0; i <= row; i++)
			{
				for (int k = 0; k <= col; k++)
				{
					mass[i][k] = 100 - rand() % 300;
					prin++;
				}
			}
			printf("Полученный массив:\n");
			for (int i = 0; i < row; i++)
			{
				printf("\n");
				for (int k = 0; k < col; k++)
				{
					printf("%d ", mass[i][k]);
				}
			}
		}
		for (int i = 0; i < row; i++)//cтрока
		{
			proverka = 0;
			for (int k = 0; k < col; k++)//cтолбец
			{
				if (mass[i][k] < 0)
					proverka++;
			}
			if (proverka == row)
			{
				first = mass[i][0];
				printf("Номер минимальной строки: %d\n", i);
				printf("Значения в строке: ");
				for (int j = 0; j < col; j++)
				{
					printf("%d ", mass[i][j]);
				}
				break;
			}
		}
		if (proverka == row)
		{
			printf("\nГотовый массив: \n");
			for (int i = 0; i < row; i++)//cтрока
			{
				printf("\n");
				for (int k = 0; k < col; k++)//cтолбец
				{
					printf("%d ", mass[i][k] + first);
				}
			}
			printf("\n");
		}
		else
			printf("\nОтрицательных строк не найдено.\n");
	}
}
