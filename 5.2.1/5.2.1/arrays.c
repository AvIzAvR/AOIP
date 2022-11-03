#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>


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

int* rem_element(int* arr, int pos, int size) 
{
	int* temp = (int*)malloc((size - 1) * sizeof(int));
	memmove(temp, arr, (pos) * sizeof(int));
	memmove(temp + pos, (arr)+(pos + 1), (size - pos) * sizeof(int));
	free(arr);
	arr = temp;
	return temp;
}

int* rem_element_matrix(int* arr, int pos, int size)
{
	int* temp = (int*)malloc((size - 1) * sizeof(int));
	memmove(temp, arr, (pos) * sizeof(int));
	memmove(temp + pos, (arr)+(pos + 1), (size - pos) * sizeof(int));
	arr = temp;
	return temp;
}

int** init_matrix(int x)
{
	int** arr = (int**)(malloc(x * sizeof(int*)));
	return arr;
}

int** init_matrix_2x2(int x)
{
	int** arr = (int**)(malloc(x * sizeof(int*)));
	for (int i = 0; i < x; i++) 
	{
		arr[i] = (int*)(malloc(x * sizeof(int)));
	}
	return arr;
}

void print_matrix(int row, int col, int **arr)
{
	for (int i = 0; i < row; i++)
	{
		printf("\n");
		for (int n = 0; n < col; n++)
		{
			printf("%d;\t", arr[i][n]);
		}
	}
}

int* write_until_number(int number, int* size)
{
	*size = 0;
	int* temp = (int*)malloc(sizeof(int));
	int i = 0;
	while (1) {
		int entered;
		printf_s("Введите элемент массива\n");
		while (!scanf_s("%d", &entered) || getchar() != '\n') {
			printf_s("Неверный тип данных\n");
			rewind(stdin);
		}
		if (entered == number) break;
		temp[i] = entered;
		(*size)++;
		i++;
		temp = (int*)realloc(temp, (i + 1) * sizeof(int));
	}
	return temp;
}

void paste_2x2(int **arr, int razmer, int random)
{
	for (int i = 0; i < razmer; i++)
		for (int n = 0; n < razmer; n++)
			arr[i][n] = rand() % 300 + random;
}
int** down(int **arr,int razmer)
{
	arr = (int**) realloc(arr, sizeof(int*) * (razmer - 1));
	return arr;
}

int** up(int** arr, int razmer)
{
	for (int i = 0; i < razmer - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	arr = (int**)realloc(arr, (razmer - 1) * sizeof(int*));
	return arr;
}

int** right(int** arr, int razmer)
{
	for (int i = 0; i < razmer; i++)
	{
		arr[i] = (int*)realloc(arr[i], (razmer - 1) * sizeof(int));;
	}
	return arr;
}

int** left(int** arr, int razmer)
{
	for (int i = 0; i < razmer; i++) {
		for (int n = 0; n < razmer - 1; n++)
		{
			arr[i][n] = arr[i][n + 1];
		}
		arr[i] = (int*)realloc(arr[i], (razmer - 1) * sizeof(int));
	}
	return arr;
}