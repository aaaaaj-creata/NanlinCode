#include<stdio.h>
int main()
{
	int arr[4][4] = {
		1,2,8,9,
		2,4,9,12,
		4,7,10,13,
		6,8,11,15
	};
	int N = 0,i=0,j=3;
	scanf_s("%d", &N);
	while (i < 4 && j >=0)
	{
		if (N == arr[i][j])
		{
			printf("找到了");
			break;
		}
		if (N > arr[i][j])
		{
			i++;
		}
		if (N < arr[i][j])
		{
			j--;
		}
	}
	printf("找不到");
	return 0;
}