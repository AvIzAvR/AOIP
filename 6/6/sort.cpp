#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<time.h>
#include"arrays.h"




void T1();
void T2();

int main()
{
	while (1)
	{
		srand(time(NULL));
		int T;
		setlocale(LC_ALL, "");
		printf("Введите номер задания:\n");
		while (!scanf_s("%d", &T))
		{
			printf("Неверный тип данных\n");
			rewind(stdin);
		}
		switch (T)
		{
		case 1:
		{
			T1();
			break;
		}
		case 2:
		{
			T2();
			break;
		}
		}
		printf("\n");
	}
}






//1.	В одномерном массиве выполнить сортировку нечетных элементов между первым и последним минимальными элементами методом вставок

void T1()
{
	setlocale(LC_ALL, "");
	int razmer = 0, elem = 0, rands = -1, low = 0, min_f = 0, min_l = 0;;
	printf("Введите размерность массива:\n");
	raz(&razmer);
	int* array = NULL;
	array = (int*)malloc(sizeof(int) * razmer);
	printf("Если вы хотите продолжить ввод с клавиатуры введите '0'\nЕсли вы хотите случайно сгенерировать числа введите '1'\n");
	rands = random();
	if (rands == 0)
	{
		elem_write(elem, razmer, array);
		printf("Ваш массив: ");
		printArray(razmer, array);
	}
	else if (rands == 1)
	{
		rand_elem(array, razmer);
		printf("Ваш массив: ");
		printArray(razmer, array);
	}
	min_f = search_low_first(array, razmer);
	min_l = search_low_last(array, razmer, min_f);
	printf("\nПервое: %d; Последнее: %d\n", min_f, min_l);
	if ((min_f / min_l) == 1)
	{
		printf("\nОбнаружен только 1 минимальный элемент.");
	}
	else
	{
		insertionSort(array, min_f, min_l);
		printf("Результат cортировки вставками: ");
		printArray(razmer, array);
		bubble(array, min_f, min_l);
		printf("\nРезультат cортировки пузырьком: ");
		printArray(razmer, array);
	}
	free(array);
}


//2.	В матрице размером NxM выполнить сортировку столбцов по убыванию суммы элементов методом Хоара

void T2()
{
	setlocale(LC_ALL, "");
	int row, col = 0;
	int** array = NULL;
	printf("Введите количество строк массива:\n");
	raz(&row);
	printf("Введите количество столбцов массива:\n");
	raz(&col);
	array = init_matrix_NxM(col, row);
	paste_NxM(array, row, col, 250);
	printf("\nВаша матрица:\n");
	print_matrix(row, col, array);
	int* sum_results = NULL;
	sum_results = (int*)malloc(sizeof(int) * col);
	printf("Сумма cтолбцов:\n");
	sumResult(col, row, sum_results, array);
	printArray(col, sum_results);
	printf("\n");
	quickSortMatrix(array, row, col);
	printf("Результат:\n");
	print_matrix(row, col, array);
}
