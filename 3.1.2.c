#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "RUS");
	int mass[100];
	int raz, nul1, pred, true, rands;
	int brain = 1;
	while(1)
	{

		printf("Введите размерность массива:\nДля случайной генерации размерности введите \"0\"\n");
		scanf_s("%d", &raz);
		if (raz < 0 && raz != 0)
		{
			while (raz < 0 && raz != 0)
			{
				rewind(stdin);
				printf("Неверно введённый тип данных.\n");
				printf("Введите размерность массива:\nДля случайной генерации размерности введите \"0\"\n");
				scanf_s("%d", &raz);
			}
		}
		else if (raz > 0)
		{
			mass[raz];
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
			}
			if (random > 0)
			{
				raz = rand() % random;
				mass[raz];
			}
		}
		printf("Если хотите продолжить ввод чисел с клавиатуры введите \"1\"\nЕсли хотите сгенерировать %d случайных чисел введите \"2\"\n", raz);
		scanf_s("%d", &rands);
		if (rands != 1 && rands != 2)
		{
			while (rands != 1 && rands != 2)
			{
				printf("Неверно введённый тип данных.\n");
				printf("Если хотите продолжить ввод чисел с клавиатуры введите \"1\"\nЕсли хотите сгенерировать %d случайных чисел введите \"2\"\n", raz);
				rewind(stdin);
				scanf_s("%d", &rands);
			}
		}
		if (rands == 1)
		{
			for (int i = 0; i <= raz; i++)
			{
				printf("Введите %d-е число массива\n", i);
				while (!scanf_s("%d", &true))
				{
					printf_s("Неверно введённый тип данных.\n");
					printf("Введите %d-е число массива\n", i);
					rewind(stdin);
				}
				mass[i] = true;
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
				for (int i = 0; i <= raz; i++)
				{
					mass[i] = rand() % pred;
					printf("%d; ", mass[i]);
				}
			}
		}
		for (int i = 1; i <= raz; i++)
		{
			if (i % 2 == 0)
			{
				brain *= mass[i];
			}
		}
		printf("\nПроизведение элементов массива с четными номерами: %d\n", brain);
		int nul = 0;
		for (int i = 0; i <= raz; i++)
		{
			if (mass[i] == 0)
			{
				nul++;
			}
		}
		if (nul > 1)
		{
			int open = 0, close = 0, nul2 = 0;
			for (int i = 0; i < raz; i++)
			{
				if (mass[i] == 0)
				{
					open = i;
					break;
				}
			}
			for (int i = raz--; i >= 0; i--)
			{
				if (mass[i] == 0)
				{
					close = i;
					break;
				}
			}
			for(int i = open; i <= close; i++)
			{
				nul2 += mass[i];
			}
			printf("Сумма между первым и последним нулевыми элементами массива: %d\n", nul2);
		}
		else
		{
			printf("Двух и более нулей в массиве не обнаружено\n");
		}
	}
}
