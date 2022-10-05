#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "RUS");
	for (int retry = 0; retry < 1000000; retry++)
	{
		printf("Введите размерность массива:\nДля случайной генерации размерности введите \"r\"\n");
		int mass[100];
		int raz, nul1, nul2, pred, true, rands;
		int brain = 1;
		scanf_s("%d", &raz);
		if (raz > 0)
		{
			mass[raz];
		}
		else if (raz = 'r')
		{
			printf("Введите максимальное случайное число:");
			int random;
			rewind(stdin);
			scanf_s("%d", &random);
			if (random > 0)
			{
				raz = rand() % random;
			}
			else
			{
				printf("Неверно введённый тип данных.");
				exit(0);
			}
		}
		else
		{
			printf("Неверно введённый тип данных.");
			exit(0);
		}

		printf("Если хотите продолжить ввод чисел с клавиатуры введите \"1\"\nЕсли хотите сгенерировать %d случайных чисел введите \"2\"\n", raz);
		scanf_s("%d", &rands);
		if (rands == 1)
		{
			for (int i = 0; i <= raz; i++)
			{
				printf("Введите %d-е число массива\n", i);
				scanf_s("%d", &true);
				if (true >= 0 || true < 0)
				{
					mass[i] = true;
				}
				else
				{
					printf("Неверно введённый тип данных.");
					exit(0);
				}
			}
		}
		else if (rands == 2)
		{
			printf("Введите максимальный предел для всех чисел:\n");
			scanf_s("%d", &pred);
			if (pred > 0)
			{
				for (int i = 0; i <= raz; i++)
				{
					mass[i] = rand() % pred;
					printf("%d; ", mass[i]);
				}
			}
			else
			{
				printf("Неверно введённый тип данных.");
				exit(0);
			}
		}
		else
		{
			printf("Неверно введённый тип данных.");
			exit(0);
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
			for (int i = 0; i <= raz; i++)
			{
				if (mass[i] == 0)
				{
					nul1 = mass[i + 1];
					for (int ii = raz; ii > 0; ii--)
					{
						if (mass[ii] == 0)
						{
							nul2 = mass[ii - 1];
							printf("Сумму элементов массива, расположенных между первым и последним нулевыми элементами: %d\n", (nul1 + nul2));
							break;
						}
					}
					break;
				}
			}
		}
		else
		{
			printf("Двух и более нулей в массиве не обнаружено\n");
		}
	}
}
