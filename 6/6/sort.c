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
		printf("������� ����� �������:\n");
		while (!scanf_s("%d", &T))
		{
			printf("�������� ��� ������\n");
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






//1.	� ���������� ������� ��������� ���������� �������� ��������� ����� ������ � ��������� ������������ ���������� ������� �������


void T1()
{
	setlocale(LC_ALL, "");
	int razmer = 0, elem = 0, rands = -1, low = 0, min_f = 0, min_l = 0;;
	int* array = NULL;
	printf("������� ����������� �������:\n");
	raz(&razmer);
	array = malloc(sizeof(int) * razmer);
	printf("���� �� ������ ���������� ���� � ���������� ������� '0'\n���� �� ������ �������� ������������� ����� ������� '1'\n");
	rands = random();
	if (rands == 0)
	{
		elem_write(elem, razmer, array);
		printf("��� ������: ");
		printArray(razmer, array);
	}
	else if (rands == 1)
	{
		rand_elem(array, razmer);
		printf("��� ������: ");
		printArray(razmer, array);
	}
	min_f = search_low_first(array, razmer);
	min_l = search_low_last(array, razmer, min_f);
	if ((min_f / min_l) == 1)
	{
		printf("\n��������� ������ 1 ����������� �������.");
	}
	else
	{
		insertionSort(array, min_f, min_l);
		printf("��������� c��������� ���������: ");
		printArray(razmer, array);
		bubble(array, min_f, min_l);
		printf("\n��������� c��������� ���������: ");
		printArray(razmer, array);
	}
	free(array);
}




//2.	� ������� �������� NxM ��������� ���������� �������� �� �������� ����� ��������� ������� �����

void T2()
{
	setlocale(LC_ALL, "");
	int row, col;
	int** array = NULL;
	int** result = NULL;
	int* sum_results = NULL;
	int* sorted_sum_arr = NULL;
	int* sorted_index = NULL;
	printf("������� ���������� ����� �������:\n");
	raz(&row);
	printf("������� ���������� �������� �������:\n");
	raz(&col);
	sum_results = malloc(sizeof(int) * col);
	sorted_sum_arr = malloc(row * sizeof(int));
	sorted_index = malloc(col * sizeof(int));
	array = init_matrix_NxM(col, row);
	paste_NxM(array, row, col, 250);
	print_matrix(row, col, array);
	result = init_matrix_NxM(col, row);
	sum_results = SumRes(col, row, array, sum_results);
	printf("\nC���� ��������:\n");
	printArray(col, sum_results);
	printf("\n");
	sorted_sum_arr = (int*)realloc(sum_results, col * sizeof(int));
	quickSort(sorted_sum_arr, 0, col - 1);
	sorted_index = sort_index(col, sorted_sum_arr, sum_results, sorted_index);
	result = resultMatrix(col, row, array, result, sorted_index);
	printf("���������:\n");
	print_matrix(row, col, result);
	free(result);
	free(sorted_sum_arr);
	free(sorted_index);
}




