#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include <malloc.h>
#include "lineLib.h"

void raz(int *x)
{
	while (!scanf_s("%d", x) || getchar() != '\n' || *x <= 0)
	{
		rewind(stdin);
		printf("Неверный тип данных!\n");
	}
}

void razfortask(int *task)
{
	printf("\n");
	while (!scanf_s("%d", task) || *task > 3 || *task < 1 || getchar() != '\n') {
		printf_s("Неверный тип данных!\n");
		rewind(stdin);
	}
}


void menu()
{
	printf("-----------------------------------------");
	printf("\n|\tДля выбора задания введите:\t|\n|\t\t\t\t\t|\n|\t1 - первое задание\t\t|\n|\t\t\t\t\t|\n|\t2 - второе задание\t\t|\n|\t\t\t\t\t|\n|\t3 - второе задание\t\t|\n|\t\t\t\t\t|\n");
	printf("-----------------------------------------");
}

char* newString(int N1, int N2, char* string, char* string1)
{
	int pos = 0;
	char* string3 = (char*)calloc(10, sizeof(char));
	int size = whensize(string1);
	int size1 = whensize(string);
	if (size < N1 || size1 < N2)
		printf("Неверный тип данных!");
	else
	{
		for (int i = 0; i < N1; i++)
		{
			if (string[i] == ' ')
				i++;
			string3[pos] = string[i];
			pos++;
		}
		for (int i = (size - 1); i >= (size - N2); i--)
		{
			if (string1[i] == ' ')
				i--;
			string3[pos] = string1[i];
			pos++;
		}
		return string3;
	}
}

char* getstringWithFirstUp()
{
	char* string = (char*)calloc(1, sizeof(char));
	char letter;
	int pos = 0;
	int key = 1;
	while (true)
	{
		letter = getchar();
		if (letter == '\n')
		{
			string[pos] = '\0';
			return string;
		}
		else if (key == 1)
		{
			if (letter >= 'a' && letter <= 'z')
				letter = letter - 'a' + 'A';
			key = 0;
		}
		else if (letter == ' ')
		{
			key = 1;
		}
		string[pos] = letter;
		pos++;
		string = (char*)realloc(string, (pos + 1) * sizeof(char));
	}
}

char* getstring()
{
	char* string = (char*)calloc(1, sizeof(char));
	char ch;
	int pos = 0;
	while (true)
	{
		ch = getchar();
		if (ch == '\n')
		{
			string[pos] = '\0';
			return string;
		}

		string[pos] = ch;
		pos++;
		string = (char*)realloc(string, (pos + 1) * sizeof(char));
	}
}
int whensize(char* string)
{
	int size = 0;
	int pos = 0;
	while (true)
	{
		if (string[pos] >= 'a' && string[pos] <= 'z' || string[pos] >= 'A' && string[pos] <= 'Z' || string[pos] == ' ')
		{
			size++;
			pos++;
		}
		else
			return size;
	}
}

