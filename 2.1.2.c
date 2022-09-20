#include <stdio.h>
#include <locale.h>
int main() 
{
	setlocale(LC_ALL, "Rus");
	int year = 0;
	float summa = 0, timer = 0, procent = 0;
	printf("Введите сумму, которую положили в банк:\n");
	scanf_s("%f", &summa);
	timer = summa;
	printf("Введите капитализированный годовой процент:\n");
	scanf_s("%f", &procent);
	if(summa > 0 && procent > 0)
	{
		for (; timer <= summa * 2; timer *= 1.00 + (procent * 0.01))
		{
			++year;
		}
		printf("Сумма увеличиться в 2 раза через %d год((а), лет).", year);
	}
	else
	{
		printf("Неверный тип данных.");
	}
	return 0;
}
