#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "RUS");
	while(1)
	{
		int choice;
		printf("������� ����������� �������:\n��� ��������� ��������� ����������� ������� \"r\"\n");
		int mass[100];
		int raz, nul1, nul2, pred, true, rands;
		int brain = 1;
		scanf_s("%d", &raz);
		if (raz > 0)
		{
			mass[raz];
		}
		else if (raz = 'r')
		{
			printf("������� ������������ ��������� �����:");
			int random;
			rewind(stdin);
			scanf_s("%d", &random);
			if (random > 0)
			{
				raz = rand() % random;
				printf("��� ������ �����: %d\n", raz);
			}
			else
			{
				printf("������� �������� ��� ������.");
				exit(0);
			}
		}
		else
		{
			printf("������� �������� ��� ������.");
			exit(0);
		}

		for (int i = 0; i <= raz; i++)
		{
			printf("������� %d-� ����� �������\n", i);
			scanf_s("%d", &true);
			if (true >= 0 || true < 0)
			{
				mass[i] = true;
			}
			else
			{
				printf("������� �������� ��� ������.");
				exit(0);
			}
		}
		if (raz > 2)
		{
			for (int i = raz; i != 0; i--)
			{
				if (i % 2 == 0 && i != 0)
				{
					raz++;
					mass[raz];
					for (int retry = 0, kolvosdvig = raz - i - 1; retry != kolvosdvig; retry++)
					{
						mass[raz - retry] = mass[raz - retry - 1];
						mass[raz - retry - 1] = 0;
					}
				}
			}
			mass[raz] = 0;
			for (int i = 0; i <= raz; i++)
			{
				printf("%d; ", mass[i]);
			}
			printf("\n");
		}
		else
			for (int i = 0; i <= raz; i++)
			{
				printf("%d; ", mass[i]);
			}
		printf("\n");
	}
}