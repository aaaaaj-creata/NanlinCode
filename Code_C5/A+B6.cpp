#include<stdio.h>
int main() 
{
	int N, a, i, sum = 0;
	while (scanf("%d", &N) != EOF) 
	{
		for (i = 1; i <= N; i++) 
		{
			scanf("%d", &a);
			sum += a;
		}
		printf("%d\n", sum);
		sum = 0;
	}
	return 0;
}

