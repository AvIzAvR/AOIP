#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>


void raz(int* x)
{
	while (!scanf_s("%d", x) || getchar() != '\n' || *x <= 0)
	{
		rewind(stdin);
		printf("Неверный тип данных\n");
	}
}

void printArray(int* x,int*y)
{
	for (int i = 0; i < x; i++)
		printf("%d; ", y[i]);
}

int* rem_element(int* arr, int pos, int razmer)
{
	int* temp = (int*)malloc((razmer - 1) * sizeof(int));
	memmove(temp, arr, (pos) * sizeof(int));
	memmove(temp + pos, (arr)+(pos + 1), (razmer - pos) * sizeof(int));
	free(arr);
	arr = temp;
	return temp;
}

int* rem_element_matrix(int* arr, int pos, int razmer)
{
	int* temp = (int*)malloc((razmer - 1) * sizeof(int));
	memmove(temp, arr, (pos) * sizeof(int));
	memmove(temp + pos, (arr)+(pos + 1), (razmer - pos) * sizeof(int));
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
	printf("\n");
}

int* write_num(int number, int* razmer)
{
	*razmer = 0;
	int* temp = (int*)malloc(sizeof(int));
	int i = 0;
	while (1) {
		int entered;
		printf_s("Введите элемент массива\n");
		while (!scanf_s("%d", &entered) || getchar() != '\n') {
			printf_s("Неверный тип данных\n");
			rewind(stdin);
		}
		temp[i] = entered;
		(*razmer)++;
		i++;
		temp = (int*)realloc(temp, (i + 1) * sizeof(int));
		if (entered == number) break;
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
	int* oldArr = (int*)malloc(razmer * sizeof(int));
	for (int j = 0; j < razmer; j++)
	{
		oldArr[j] = arr[razmer - 1][j];
	}
	for (int n = 0; n < razmer; n++)
		for (int i = razmer - 1; i != 0; i--)
			arr[i][n] = arr[i - 1][n];
	for (int j = 0; j < razmer; j++) {
		arr[0][j] = oldArr[j];
	}
	return arr;
}

int** up(int** arr, int razmer)
{
	int* oldArr = (int*)malloc(razmer * sizeof(int));
	for (int j = 0; j < razmer; j++) 
	{
		oldArr[j] = arr[0][j];
	}
	for (int n = 0; n < razmer; n++)
		for (int i = 0; i < razmer - 1; i++)
			arr[i][n] = arr[i + 1][n];
	for (int j = 0; j < razmer; j++) 
	{
		arr[razmer - 1][j] = oldArr[j];
	}
	return arr;
}

int** right(int** arr, int razmer)
{
	int* oldArr = (int*)malloc(razmer * sizeof(int));
	for(int j = 0; j < razmer; j++) 
	{
		oldArr[j] = arr[j][razmer - 1];
	}
	for(int i = razmer - 1; i >= 0; i--)
	{
		for(int n = razmer - 1; n >= 0; n--)
		{
			arr[i][n] = arr[i][n - 1];
		}
	}
	for (int j = 0; j < razmer; j++)
	{
		arr[j][0] = oldArr[j];
	}
	return arr;
}

int** left(int** arr, int razmer)
{
	int* oldArr = (int*)malloc(razmer * sizeof(int));
	for (int j = 0; j < razmer; j++) 
	{
		oldArr[j] = arr[j][0];
	}
	for (int i = 0; i < razmer; i++)
	{
		for (int n = 0; n < razmer - 1; n++)
		{
			arr[i][n] = arr[i][n + 1];
		}
	}
	for (int j = 0; j < razmer; j++)
	{
		arr[j][razmer - 1] = oldArr[j];
	}
	return arr;
}

int random()
{
	int x;
	while (!scanf_s("%d", &x) || x != 0 && x != 1)
	{
		printf("Неверный тип данных\n");
		rewind(stdin);
	}
	return x;
}


void rand_elem(int* arr, int razmer)
{
	for (int i = 0; i < razmer; i++)
	{
		*(arr + i) = rand() % 300 - 150;
	}
}

void rand_gen_raz(int *razmer)
{
	*razmer = rand() % (200 + 100);
	printf("Размерность вашего массива: %d\n", *razmer);
}

int** search_low(int** arr, int razmer, int low, int num)
{
	int min = arr[num][0];
	for (int n = 0; n < razmer; n++)
	{
		if (arr[num][n] < min && arr[num][n] != 0)
		{
			low = n;
			min = arr[num][n];
		}
	}
	return low;
}


void write_side(int* pos)
{
		while (!scanf_s("%d", pos) || *pos != 1 && *pos != 2 && *pos != 3 && *pos != 4)
	{
		rewind(stdin);
		printf("Неверно введённый тип данных!");
	}
}

void elem_write(int element, int razmer, int* arr)
{
	for (int i = 0; i < razmer; i++)
	{
		printf("Введите %d-ый элемент массива\n", i);
		while (!scanf_s("%d", &arr[i]) || getchar() != '\n')
		{
			rewind(stdin);
			printf("Неверный тип данных\n");
		}
	}
}

void print_low(int row, int** arr)
{
	for (int i = 0; i < row; i++)
	{
		printf("\n");
		for (int n = 0; arr[i][n] != 0; n++)
			printf("%d; ", arr[i][n]);
	}
}
