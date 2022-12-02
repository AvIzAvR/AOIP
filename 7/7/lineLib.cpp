#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include <malloc.h>
#include "lineLib.h"

void getInt(int* x)
{
	while (!scanf_s("%d", x) || getchar() != '\n' || *x <= 0)
	{
		rewind(stdin);
		printf("Неверный тип данных!\n");
	}
}

void getIntfortask(int* task)
{
	printf("\n");
	while (!scanf_s("%d", task) || *task > 4 || *task < 1 || getchar() != '\n') {
		printf_s("Неверный тип данных!\n");
		rewind(stdin);
	}
}


void menu()
{
	printf("-----------------------------------------");
	printf("\n|\tДля выбора задания введите:\t|\n|\t\t\t\t\t|\n|\t1 - первое задание\t\t|\n|\t\t\t\t\t|\n|\t2 - второе задание\t\t|\n|\t\t\t\t\t|\n|\t3 - третье задание\t\t|\n|\t\t\t\t\t|\n|\t4 - закрыть программу\t\t|\n");
	printf("-----------------------------------------");
}

char* newString(int N1, int N2, char* string, char* string1)
{
	int pos = 0;
	char* string3 = (char*)calloc(10, sizeof(char));
	int size = getSize(string1);
	int size1 = getSize(string);
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
	free(string3);
}


char* downFirst(char* string)
{
	int size = getSize(string);
	for (int i = 0; i < size; i++)
		if (string[i] == ' ')
		{
			i++;
			if (string[i] >= 'A' && string[i] <= 'Z')
			{
				string[i] = string[i] - 'A' + 'a';
			}
		}
		else if (i == 0)
		{
			if (string[i] >= 'A' && string[i] <= 'Z')
				string[i] = string[i] - 'A' + 'a';
		}
	return string;
}
char* getString()
{
	int num = 256;
	char* string = (char*)calloc(num, sizeof(char));
	char ch;
	int pos = 0;
	while (true)
	{
		ch = getchar();
		if (ch == '\n')
		{
			string[pos] = '\0';
			string = (char*)realloc(string, (pos + 1) * sizeof(char));
			return string;
		}

		string[pos] = ch;
		pos++;
		if (pos == 256)
			string = (char*)realloc(string, (pos + 1) * sizeof(char));
	}
}
int getSize(char* string)
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


void quickSort(int*& arr, char**& sort, int start, int end)
{
	int i = start;
	int j = end;
	int tmp;
	char* sort_tmp;
	int x = arr[(start + end) / 2];

	do
	{
		while (arr[i] > x)
			i++;
		while (arr[j] < x)
			j--;
		if (i <= j) {
			if (i < j) {

				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;

				sort_tmp = sort[i];
				sort[i] = sort[j];
				sort[j] = sort_tmp;
			}
			i++;
			j--;
		}
	} while (i <= j);

	if (i < end)
		quickSort(arr, sort, i, end);
	if (start < j)
		quickSort(arr, sort, start, j);
}


void copyString(char* argv, char*& string)
{
	int size = getSize(argv);
	int i = 0;
	string = (char*)calloc(size + 1, sizeof(char));
	while (argv[i] != '\0') {
		string[i] = argv[i];
		i++;
	}
	string[i] = '\0';
}
char* strSub(char* str1, int start, int length)
{
	int i = start;
	char* str2 = (char*)calloc(length + 1, sizeof(char));
	for (int i = 0; i < length; i++)
	{
		if (str1[i + start] == '\0') break;
		str2[i] = str1[i + start];
	}
	str2[length] = '\0';
	return str2;
}

int getSizeword(char* str, char letter)
{
	int i = 0;
	int prev_pos = 0;
	int max = 0;
	while (str[i] != '\0') {
		if (str[i] == letter) {
			int strlen = getSize(strSub(str, prev_pos, i - prev_pos));
			if (strlen > max)
				max = strlen;
			prev_pos = i + 1;
		}
		i++;
	}
	if (str[i] == '\0') {
		int strlen = getSize(strSub(str, prev_pos, i - prev_pos));
		if (strlen > max)
			max = strlen;
	}
	return max;
}

void getSizeString(int argc, int*& sizestring, char** strings)
{
	for (int i = 0; i < argc - 1; i++)
	{
		int size = getSizeword(strings[i], ' ');
		sizestring[i] = size;
	}
}

void printStrings(int argc, char** strings)
{
	for (int i = 0; i < argc - 1; i++)
		printf("%s\n", strings[i]);
}

void free_strings(char** strings, int argc)
{
	for (int i = 0; i < argc - 1; i++)
		free(strings[i]);
	free(strings);
}
