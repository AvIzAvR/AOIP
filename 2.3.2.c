#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	int C = 0;
	float A = 0, B = 0;
	printf("������� ������� ������� A:\n");
	scanf_s("%f", &A);
	printf("������� ������� ������� B:\n");
	scanf_s("%f", &B);
	if (A > B)
	{
		for (; A >= B; A -= B)
		{
			++C;
		}
		printf("���������� ��������, ������� ������� ����������: %d\n��������� ����� ������� A �����: %f", C, A);
	}
	else
	{
		printf("�������� ��� ������");
	}
	return 0;
}