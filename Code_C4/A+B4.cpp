#include<stdio.h>
int main() 
{
	int N, sum=0, i, a;//sum要初始化为0
	while (1) 
	{
		scanf("%d", &N);
		if (N == 0) break;
		for (i = 1; i <= N; i++) 
		{
			scanf("%d", &a);
			sum += a;
		}
		printf("%d\n", sum);
		sum = 0;//每组输入后sum清零
	}
	return 0;
}


