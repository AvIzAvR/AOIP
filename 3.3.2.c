#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "RUS");
	int mass[100];
	int raz, nul1, nul2, pred, true, rands;
	int brain = 1;
	int choice;
	int mass2[100];
	int temp = 'a';
	int torf = 0;
	while (1)
	{
		printf("Введите размерность для двух массивов:\nДля случайной генерации размерности введите \"0\"\n");
		scanf_s("%d", &raz);
		if (raz < 0 && raz != 0)
		{
			while (raz < 0 && raz != 0)
			{
				rewind(stdin);
				printf("Неверно введённый тип данных.\n");
				printf("Введите размерность для двух массивов:\nДля случайной генерации размерности введите \"0\"\n");
				scanf_s("%d", &raz);
			}
			mass[raz];
			mass2[raz];
		}
		else if (raz > 0)
		{
			mass[raz];
			mass2[raz];
		}
		else if (raz == 0)
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
				mass[raz];
				mass2[raz];
			}
			if (random > 0)
			{
				raz = rand() % random;
				mass[raz];
				mass2[raz];
			}
		}
		printf("Если хотите продолжить ввод чисел с клавиатуры введите \"1\"\nЕсли хотите сгенерировать %d случайных чисел для двух массивов введите \"2\"\n", raz);
		scanf_s("%d", &rands);
		if (rands != 1 && rands != 2)
		{
			while (rands != 1 && rands != 2)
			{
				printf("Неверно введённый тип данных.\n");
				printf("Если хотите продолжить ввод чисел с клавиатуры введите \"1\"\nЕсли хотите сгенерировать %d случайных чисел для двух массивов введите \"2\"\n", raz);
				rewind(stdin);
				scanf_s("%d", &rands);
			}
		}
		if (rands == 1)
		{
			for (int i = 0; i <= raz; i++)
			{
				printf("Введите %d-е число 1-ого массива\n", i);
				while (!scanf_s("%d", &true))
				{
					printf_s("Неверно введённый тип данных.\n");
					printf("Введите %d-е число 1-ого массива\n", i);
					rewind(stdin);
				}
				mass[i] = true;
			}
			for (int i = 0; i <= raz; i++)
			{
				printf("Введите %d-е число 2-ого массива\n", i);
				while (!scanf_s("%d", &true))
				{
					printf_s("Неверно введённый тип данных.\n");
					printf("Введите %d-е число 2-ого массива\n", i);
					rewind(stdin);
				}
				mass2[i] = true;
			}
		}
		else if (rands == 2)
		{
			printf("Введите максимальный предел для всех чисел 1ого массива:\n");
			scanf_s("%d", &pred);
			if (pred < 0)
			{
				while (pred < 0)
				{
					printf("Неверно введённый тип данных.\n");
					printf("Введите максимальный предел для всех чисел 1ого массива:\n");
					rewind(stdin);
					scanf_s("%d", &pred);
				}
			}
			if (pred > 0)
			{
				printf("Первый массив:");
				for (int i = 0; i <= raz; i++)
				{
					mass[i] = rand() % pred;
					printf("%d; ", mass[i]);
				}
			}
			printf("\nВведите максимальный предел для всех чисел 2ого массива:\n");
			scanf_s("%d", &pred);
			if (pred < 0)
			{
				while (pred < 0)
				{
					printf("Неверно введённый тип данных.\n");
					printf("Введите максимальный предел для всех чисел 2ого массива:\n");
					rewind(stdin);
					scanf_s("%d", &pred);
				}
			}
			if (pred > 0)
			{
				printf("\nВторой массив:");
				for (int i = 0; i <= raz; i++)
				{
					mass2[i] = rand() % pred;
					printf("%d; ", mass2[i]);
				}
			}
		}
			for (int i = 0; i < raz; ++i)
			{
				torf = 0;
				for (int j = 0; j < raz; ++j)
				{
					if (mass[i] == mass2[j])
					{
						torf = 1;
					}
				}
				if (torf == 0)
				{
					if (temp == 'a' || temp > mass[i])
					{
						temp = mass[i];
					}
				}
			}
			if (temp != 'a')
			{
				printf("\nРезультат: %d\n", temp);
			}
			else if (temp = 'a')
			{
				printf("Все числа совпадают!\n");
			}
	}
}
