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
		//case 3:
		//{
		//	T3();
		//	break;
		//}
		}
		printf("\n");
	}
}






//1.	� ���������� ������� ��������� ���������� �������� ��������� ����� ������ � ��������� ������������ ���������� ������� �������

void T1()
{
	setlocale(LC_ALL, "");
	int razmer = 0, elem = 0, rands = -1, low = 0, min_f = 0, min_l = 0;;
	printf("������� ����������� �������:\n");
	raz(&razmer);
	int* array = NULL;
	array = (int*)malloc(sizeof(int) * razmer);
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
	printf("\n������: %d; ���������: %d\n", min_f, min_l);
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
	int row, col = 0;
	int** array = NULL;
	printf("������� ���������� ����� �������:\n");
	raz(&row);
	printf("������� ���������� �������� �������:\n");
	raz(&col);
	array = init_matrix_NxM(col, row);
	paste_NxM(array, row, col, 250);
	printf("\n���� �������:\n");
	print_matrix(row, col, array);
	int* sum_results = NULL;
	sum_results = (int*)malloc(sizeof(int) * col);
	printf("����� ���:\n");
	sumResult(col, row, sum_results, array);
	printArray(col, sum_results);
	printf("\n");
	quickSortMatrix(array, row, col);
	printf("���������:\n");
	print_matrix(row, col, array);
}