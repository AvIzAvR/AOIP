#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "RUS");
	while (1)
	{
		printf("������� ����������� ��� ���� ��������:\n��� ��������� ��������� ����������� ������� \"r\"\n");
		int mass[100];
		int mass2[100];
		int true, raz = 10;
		int temp = -1;
		int torf = 0;
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
			printf("������� %d-� ����� 1-��� �������\n", i);
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
		for (int i = 0; i <= raz; i++)
		{
			printf("������� %d-� ����� 2-��� �������\n", i);
			scanf_s("%d", &true);
			if (true >= 0 || true < 0)
			{
				mass2[i] = true;
			}
			else
			{
				printf("������� �������� ��� ������.");
				exit(0);
			}
		}


		for (int i = 0; i < raz; ++i)
		{
			torf = 0;
			for (int j = 0; j < raz; ++j)
			{
				if (mass[i] == mass2[j])
				{
					torf = 1;
				}
			}
			if (torf == 0)
			{
				if (temp == -1 || temp > mass[i])
				{
					temp = mass[i];
				}
			}
		}
		printf("���������: %d", temp);
	}
}