#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<time.h>
#include"arrays.h"

void T1();
void T2();
void T3();

int main()
{
	while(1)
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
		case 3:
		{
			T3();
			break;
		}
		}
		printf("\n");
	}
}

void T1()
{
	int rands = -1;
	int elem = 0;
	int* array = NULL;
	setlocale(LC_ALL, "");
	int razmer = 0;
	printf("Введите размерность массива:\n");
	raz(&razmer);
	array = malloc(sizeof(int) * razmer);
	printf("Если вы хотите продолжить ввод с клавиатуры введите '0'\nЕсли вы хотите случайно сгенерировать числа введите '1'\n");
	rands = random();
	if (rands == 0)
	{
		elem_write(elem, razmer, array);
	}
	else if (rands == 1)
	{
		rand_elem(array, razmer);
		printf("Ваш массив: ");
		printArray(razmer, array);
	}
	while (elem < razmer)
	{
		if (*(array + elem) < 0)
		{
			array = rem_element(array, elem, razmer);
			razmer--;
			elem = 0;
		}
		else
			elem++;
	}
	printf("\nПолученный массив:\n");
	printArray(razmer, array);
	free(array);
}


void T2()
{
	int low = 0, row, razmer, stop;
	int** array = NULL;
	setlocale(LC_ALL, "");
	printf("Введите количество строк массива:");
	raz(&row);
	array = init_matrix(row);
	for (int i = 0; i < row; i++)
	{
		printf("Введите элементы %d-ой строки\n", i);
		array[i] = write_num(0, &razmer);
		if (i % 2 != 0)
		{
			low = search_low(array, razmer, low, i);
			array[i] = rem_element_matrix(array[i], low, razmer);
		}
	}
	printf("Результат:\n");
	print_low(row, array);
	free(array);
}


void T3()
{
	int pos;
	int razmer = 0;
	int** array = NULL;
	printf("Введите размер квадратной матрицы:");
	raz(&razmer);
	int row = razmer, col = razmer;
	array = init_matrix_2x2(razmer);
	paste_2x2(array, razmer, 200);
	printf("\nВаша матрица:");
	print_matrix(razmer, razmer, array);
	printf("\nВведите сторону, в которую хотите сдвинуть массив\n1 - влево;\n2 - вправо;\n3 - вверх;\n4 - вниз\n");
	write_side(&pos);
	switch (pos)
	{
	case 1:
		array = left(array, col);
		break;
	case 2:
		array = right(array, col);
		break;
	case 3:
		array = up(array, row);
		break;
	case 4:
		array = down(array, row);
		break;
	}
	printf("Результат:\n");
	print_matrix(row, col, array);
	free(array);
}
