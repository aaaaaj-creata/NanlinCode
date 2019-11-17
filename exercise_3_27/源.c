#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

//交换两个变量的值
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 0;
//	printf("%d %d\n",a,b);
//	c = a;
//	a = b;
//	b = c;
//	printf("%d %d\n",a,b);
//	return 0;
//}
//不创建变量的方法
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 0;
//	printf("%d %d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("%d %d\n", a, b);
//	return 0;
//}

//求10个整数中最大值
//int main()
//{
//	int a[10];
//	int i = 0;
//	int max=0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	max = a[0];
//	for (i = 0; i < 10; i++)
//	{
//		if (max < a[i])
//		{
//			max = a[i];
//		}
//	}
//	printf("%d", max);
//	
//	return 0;
//}

//将三个数按从大到小输出
//int main()
//{
//	int a, b, c, t;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a < b)
//	{
//		t = a;
//		a = b;
//		b = t;
//	}
//	if (a < c)
//	{
//		t = a;
//		a = c;
//		c = t;
//	}
//	if (b < c)
//	{
//		t = b;
//		b = c;
//		c = t;
//	}
//	printf("%d %d %d\n", a, b, c);
//
//	system("pause");
//	return 0;
//}

//求两个数的最大公约数
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int temp = 0;
//	int c = 0;
//	scanf("%d %d", &a, &b);
//	if (b > a)
//	{
//		temp = b;
//		b = a;
//		a = temp;
//	}
//	c = a % b;
//	while (c!=0)
//	{
//		a = b;
//		b = c;
//		c = a % b;
//	}
//	printf("%d", b);
//	return 0;
//}