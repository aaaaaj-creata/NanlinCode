#include<stdio.h>

int main()
{
	int sum = 0, R = 0, a = 0, i = 0;
	int num[10000] = { 0 };
	scanf("%d\n", &sum);
	scanf("%d", &R);
	while (sum >= R)
	{
		a = sum % R;
		sum = sum / R;
		
		num[i] = a;
		i++;
	}
	num[i] = sum;
	for (; i>=0; i--)
	{
		printf("%d", num[i]);
	}
	return 0;
}
