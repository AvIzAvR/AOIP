#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include <malloc.h>
#include<locale.h>
#include"lineLib.h"


void task1(int argc, char** argv);
void task2(int argc, char** argv);
void task3(int argc, char** argv);
void stop(int argc, char** argv);

int main(int argc, char** argv)
{
	int task = 0;
	setlocale(LC_ALL, "Rus");
		menu();
		getIntfortask(&task);
		void (*taskss[4]) (int, char**) = { task1, task2, task3, stop };
		((*taskss[task - 1])(argc, argv));
}

void stop(int argc, char** argv)
{
	exit(EXIT_SUCCESS);
}

void task1(int argc, char** argv)
{
	printf("Введите строку, в которой хотите преобразовать все первые буквы каждого слова в строчные:\n");
	char* string = getString();
	string = downFirst(string);
	printf("Результат:");
	printf("%s\n", string);
	free(string);
}


void task2(int argc, char** argv)
{
	int N1 = 0, N2 = 0;
	printf("Введите N1:\n");
	getInt(&N1);
	printf("Введите N2:\n");
	getInt(&N2);
	printf("Введите первую строку:\n");
	char* string = getString();
	printf("Введите вторую строку:\n");
	char* string1 = getString();
	int size = getSize(string);
	int size1 = getSize(string1);
	if (size < N1 || size1 < N2)
		printf("Неверный тип данных!\n");
	else
	{
		char* string3 = newString(N1, N2, string, string1);
		printf("Результат:\n");
		printf("%s\n", string3);
		free(string3);
	}
	free(string);
	free(string1);
}

void task3(int argc, char** argv)
{
	if (argc == 1)
	{
		printf_s("\nНеверное кол-во аргументов\n");
		return;
	}
	char** strings = (char**)calloc(argc - 1, sizeof(char*));
	int* sizestring = (int*)calloc((argc - 1), sizeof(int));
	for(int i = 1; i < argc; i++)
	copyString(argv[i], strings[i-1]);
	getSizeString(argc, sizestring, strings);
	quickSort(sizestring, strings, 0, (argc - 1));
	printStrings(argc, strings);
	free(sizestring);
	free_strings(strings, argc);
}
