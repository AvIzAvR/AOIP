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
		printf("������� ����� �������:\n");
		while (!scanf_s("%d", &T) && T != 1)
		{
			printf("�������� ��� ������");
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
	printf("������� ����������� �������:\n��� ��������� ��������� ������� '0'\n");
	raz(&razmer);
	if (razmer == 0)
	{
		razmer = rand() % (200 + 100);
		printf("����������� ������ �������: %d\n", razmer);
	}
	array = malloc(sizeof(int) * razmer);
	printf("���� �� ������ ���������� ���� � ���������� ������� '0'\n���� �� ������ �������� ������������� ����� ������� '1'\n");
	while (!scanf_s("%d", &rands) && rands != 0 && rands != 1)
	{
		rewind(stdin);
		printf("�������� ��� ������\n");
	}
	if (rands == 0)
	{
		for (int i = 0; i < razmer; i++)
		{
			printf("������� %d-�� ������� �������\n", i);
			element(&array[i]);
		}
	}
	else if (rands == 1)
	{
		for (int i = 0; i < razmer; i++)
		{
			*(array + i) = rand() % 300 - 150;
		}
		printf("��� ������: ");
		PrintArray(razmer, array);
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
	printf("\n���������� ������:\n");
	for (int i = 0; i < razmer; i++)
		printf("%d; ", array[i]);
	free(array);
}


void T2()
{
	int low = 0, row, razmer;
	int** array = NULL;
	setlocale(LC_ALL, "");
	printf("������� ���������� ����� �������:");
	raz(&row);
	int *mass = NULL;
	mass = malloc(sizeof(int) * row);
	array = init_matrix(row);
	for (int i = 0; i < row; i++)
	{
		printf("������� �������� %d-�� ������\n", i);
		array[i] = write_until_number(0, &razmer);
		if (i % 2 != 0)
		{
			int min = array[i][0];
			for (int n = 0; n < razmer; n++) 
			{
				if (array[i][n] < low)
					low = n;
			}
			array[i] = rem_element_matrix(array[i], low, razmer);
			razmer--;
		}
		*(mass + i) = razmer;
	}
	printf("���������:\n");

	for (int i = 0; i < row; i++)
	{
		printf("\n");
		for (int n = 0; n < mass[i]; n++)
		{
			printf("%d;\t", array[i][n]);
		}
	}
	free(array);
	free(mass);
}


void T3()
{
	int pos;
	int razmer = 0;
	int** array = NULL;
	printf("������� ������ ���������� �������:");
	raz(&razmer);
	int row = razmer, col = razmer;
	array = init_matrix_2x2(razmer);
	paste_2x2(array, razmer, 200);
	print_matrix(razmer, razmer, array);
	printf("\n������� �������, � ������� ������ �������� ������\n1 - �����;\n2 - ������;\n3 - �����;\n4 - ����\n");
	while(!scanf_s("%d", &pos) && pos != 1 && pos != 1 && pos != 2 && pos != 3 && pos != 4)
	{
		printf("������� �������� ��� ������!");
	}
	switch (pos)
	{
	case 1:
		array = left(array, col);
		col--;
		break;
	case 2:
		array = right(array, col);
		col--;
		break;
	case 3:
		array = up(array, row);
		row--;
		break;
	case 4:
		array = down(array,row);
		row--;
		break;
	}
	printf("���������:\n");
	print_matrix(row, col, array);

	free(array);
}