#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include <malloc.h>


void raz(int* x)
{
	while (!scanf_s("%d", x) || getchar() != '\n' || *x <= 0)
	{
		rewind(stdin);
		printf("Неверный тип данных\n");
	}
}

void printArray(int* razmer, int* arr)
{
	for (int i = 0; i < razmer; i++)
		printf("%d; ", arr[i]);
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

int** init_matrix_NxM(int col, int row)
{
	int** arr = (int**)(malloc(row * sizeof(int*)));
	for (int i = 0; i < row; i++)
	{
		arr[i] = (int*)(malloc(col * sizeof(int)));
	}
	return arr;
}

void print_matrix(int row, int col, int** arr)
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


void paste_NxM(int** arr, int row, int col, int random)
{
	for (int i = 0; i < row; i++)
		for (int n = 0; n < col; n++)
			arr[i][n] = rand() % 300 + random;
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

int search_low_first(int* arr, int razmer)
{
	int min = arr[0];
	int low = 0;
	for (int n = 0; n < razmer; n++)
	{
		if (arr[n] < min)
		{
			min = arr[n];
			low = n;
		}
	}
	return low;
}

int search_low_last(int* arr, int razmer, int low)
{
	int min = arr[low];
	int max = 0;
	for (int n = razmer-1; n >= 0; n--)
	{
		if (arr[n] == min)
		{
			max = n;
			break;
		}
	}
	return max;
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

void insertionSort(int* arr, int min_f, int min_l) 
{
	clock_t start_time = clock();
	int temp, temp_id;
	for (int i = (min_f + 2); i < min_l; i++)
	{
		temp = arr[i];
		temp_id = i - 1;
		while (temp_id >= (min_f + 1) && arr[temp_id] % 2 == 0)
		{
			arr[temp_id + 1] = arr[temp_id];
			arr[temp_id] = temp;
			temp_id = temp_id - 1;
		}
		arr[temp_id + 1] = temp;
	}
	clock_t end_time = clock();
	float insetionTime = end_time - start_time;
	printf("\nЗатраченное время: %.10f\n", insetionTime);
}

void bubble(int* arr, int min_f, int min_l)
{
	clock_t start_time1 = clock();
	int temp;
	int Swap;
	for (int i = min_l - 1; i >= (min_f + 1); i--)
	{
		Swap = 1;
		for (int j = (min_f + 1); j < i; j++)
		{
			if (arr[j] % 2 != 0)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				Swap = 0;
			}
		}
		if (Swap == 1)
			break;
	}
	clock_t end_time1 = clock();
	float bubbleTime = end_time1 - start_time1;
	printf("\nЗатраченное время: %.10f\n", bubbleTime);
}


void quickSort(int* arr, int down, int up)
{
	int pivot;
	int d_hold = down;
	int u_hold = up;
	pivot = arr[down];
	while (down < up)
	{
		while ((arr[up] >= pivot) && (down < up))
			up--;
		if (down != up)
		{
			arr[down] = arr[up];
			down++;
		}
		while ((arr[down] <= pivot) && (down < up))
			down++;
		if (down != up)
		{
			arr[up] = arr[down];
			up--;
		}
	}
	arr[down] = pivot;
	pivot = down;
	down = d_hold;
	up = u_hold;
	if (down < pivot)
		quickSort(arr, down, pivot - 1);
	if (up > pivot)
		quickSort(arr, pivot + 1, up);
}

int* SumRes(int col, int row,int** array, int* sum_results)
{

		for (int i = 0; i < col; i++)
	{
		int sum_col = 0;
		for (int j = 0; j < row; j++)
		{
			sum_col += array[j][i];
		}
		sum_results[i] = sum_col;
	}
		return sum_results;
}


int* sort_index(int col,int *sorted_sum_arr,int* sum_results,int* sorted_index)
{
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (sorted_sum_arr[i] == sum_results[j])
			{
				sorted_index[i] = j;
			}
		}
	}
	return sorted_index;
}

int** resultMatrix(int col, int row, int** array, int** result, int* sorted_index)
{
	int current_index;
	for (int i = 0; i < col; i++)
	{
		current_index = sorted_index[i];
		for (int j = 0; j < row; j++)
		{
			result[j][i] = array[j][current_index];
		}
	}
	return result;
}
