#include<stdio.h>

int mian()
{
	int i;
	int t;
	int sum = 0;
	for (t = i = 1; i <= 10;)
	{
		sum += t;
		++i;
		if (i % 3 == 0) t = -i;
		else t = i;
	}
	printf("%d", sum);
	return 0;
}