#include <stdio.h> /*???????? ???????? ?????????? ????? C*/
#include <locale.h> /*???????? ?????????? ? ???????? ???????*/
int main()
{
	setlocale(LC_ALL, "Rus");  /*????????? ???????? ????? ??? ???????*/
	int a, b, c, num = 0; /*????????????? ??????????, ?, b, ? ??? ????? ?????????? ?? ???????????? ? ?????????? num ??? ????????? ??????????*/
	printf("??????? 3 ?????, ????? ??????? ????? ????????? Enter:\n"); /*????? ?????? ? ???????*/
	scanf_s("%d\n %d\n %d", &a, &b, &c); /*?????????? ????????? ?????????? ?? ????????????? ? ?????????? ?? ? ??????????*/
	if (a > 0)
		num++;
	if (b > 0)
		num++;
	if (c > 0)
		num++;
// ??????? ????????? ??????????, ????? ???????? ??, ??????? ?????? ????
	printf("?????????? ????????????? ?????: %d", num); /*????? ??????????*/
	return 0;
}