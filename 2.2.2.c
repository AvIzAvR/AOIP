#include <stdio.h>
#include<math.h>
int main()
{
	int num;
	for (num = 100; num < 1000; num++)
	{
		float sq = sqrt(num);
		int sqr = sq;
		if (sqr == sq)
		{
		int n1, n2, n3;
		n1 = num / 100;
		n2 = (num - (n1 * 100)) / 10;
		n3 = (num - (n2 * 10) - (n1 * 100));
		if (n1 <= n2)
		{
			if (n2 <= n3)
			{
				printf("%d\n", num);
			}
		}
		}
	}
	return 0;
}



