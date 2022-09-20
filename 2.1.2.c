#include <stdio.h>
#include <locale.h>
int main() 
{
	setlocale(LC_ALL, "Rus");
	int year = 0;
	float summa = 0, procent = 0;
	scanf_s("%f", &summa);
	procent = summa;
	if(summa > 0)
	{
		for (; procent <= summa * 2; procent *= 1.03)
		{
			++year;
		}
		printf("Сумма увеличиться в 2 раза через %d год((а), лет).", year);
	}
	else
	{
		printf("Неправильно введён тип данных.");
	}
	return 0;
}
