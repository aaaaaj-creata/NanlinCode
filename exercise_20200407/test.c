#include<stdio.h>

//int main()
//{
//	int a = 0, b = 0;
//	scanf_s("%d %d", &a, &b);
//	while (a != 0 && b != 0)
//	{
//
//		if (a % 2 == 0)
//		{
//			a = 0;
//			b = b + a / 2;
//		}
//		else if (a % 2 != 0)
//		{
//			a = 1;
//			b = b + (a - 1) / 2;
//		}
//
//		if (b % 2 == 0)
//		{
//			b = 0;
//			a = a + b / 2;
//		}
//		else if (b % 2 != 0)
//		{
//			b = 1;
//			a = a + (b - 1) / 2;
//		}
//	}
//
//	if (b == 0)
//	{
//		printf("Yes");
//	}
//	else if (a == 0)
//	{
//		printf("No");
//	}
//
//	return 0;
//}

//int main()
//{
//	int a = 0, b = 0;
//	while (scanf_s("%d%d", &a, &b) != EOF)
//	{
//		if (a % 2 == 0 && b % 2 == 0)
//		{
//			printf("Yes");
//		}
//		if (a % 2 == 0 && b % 2 != 0)
//		{
//			printf("No");
//
//		}
//		if (a % 2 != 0 && b % 2 == 0)
//		{
//			printf("Yes");
//
//		}
//		if (a % 2 != 0 && b % 2 != 0)
//		{
//			printf("Yes");
//		}
//	}
//	return 0;
//}

int main()
{
	int sum = 0, n = 0, m = 0;
	while (scanf_s("%d %d", &n, &m) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				scanf_s("%d", &dst[i][j]);
			}
		}
	}


	return 0;
}