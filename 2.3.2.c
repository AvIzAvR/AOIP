#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	int C = 0;
	float A = 0, B = 0;
	printf("Введите больший отрезок A:\n");
	scanf_s("%f", &A);
	printf("Введите меньший отрезок B:\n");
	scanf_s("%f", &B);
	if (A > B)
	{
		for (; A >= B; A -= B)
		{
			++C;
		}
		printf("Количество отрезков, которое удалось разместить: %d\nНезанятая часть отрезка A равна: %f", C, A);
	}
	else
	{
		printf("Неверный тип данных");
	}
	return 0;
}
