#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include <malloc.h>
#include<locale.h>
#include"lineLib.h"


void Task1(int argc, char** argv);
void Task2(int argc, char** argv);
void Task3(int argc, char** argv);

int main(int argc, char** argv)
{
	char* tasks;
	int task = 0;
	setlocale(LC_ALL, "Rus");
	menu();
	razfortask(&task);
	void (*taskss[3]) (int, char**) = { Task1, Task2, Task3};
	((*taskss[task - 1])(argc, argv));
}


void Task1(int argc, char** argv)
{
	printf("Введите строку, в которой хотите преобразовать все первые буквы каждого слова в строчные:\n");
	char* string = getstringWithFirstUp();
	printf("%s", string);
}


void Task2(int argc, char** argv)
{
	int N1 = 0, N2 = 0;
	printf("Введите N1:\n"); 
	raz(&N1);
	printf("Введите N2:\n");
	raz(&N2);
	printf("Введите первую строку:\n");
	char* string = getstring();
	printf("Введите вторую строку:\n");
	char* string1 = getstring();
	char* string3 = newString(N1, N2, string, string1);
	printf("Результат:");
	printf("%s", string3);
}

void Task3(int argc, char** argv)
{
	if (argc == 1) {
		printf_s("\nНеверное кол-во аргов\n");
		return;
	}
	char** strings = (char**)calloc(argc - 1, sizeof(char*));
	printf("%s", strings);
}