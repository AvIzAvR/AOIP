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
	printf("������� ������, � ������� ������ ������������� ��� ������ ����� ������� ����� � ��������:\n");
	char* string = getstringWithFirstUp();
	printf("%s", string);
}


void Task2(int argc, char** argv)
{
	int N1 = 0, N2 = 0;
	printf("������� N1:\n"); 
	raz(&N1);
	printf("������� N2:\n");
	raz(&N2);
	printf("������� ������ ������:\n");
	char* string = getstring();
	printf("������� ������ ������:\n");
	char* string1 = getstring();
	char* string3 = newString(N1, N2, string, string1);
	printf("���������:");
	printf("%s", string3);
}

void Task3(int argc, char** argv)
{
	if (argc == 1) {
		printf_s("\n�������� ���-�� �����\n");
		return;
	}
	char** strings = (char**)calloc(argc - 1, sizeof(char*));
	printf("%s", strings);
}