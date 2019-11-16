#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int line = 13;
	int i = 0;
	int j = 0;
	int k = 0;
	//打印上半部分（正三角）
	for (i = 0; i < line; i++)
	{
		//打印开始的空格
		for (j = 0; j < line - 1 - i; j++)
		{
			printf(" ");
		}
		//打印*
		for (k = 0; k < i * 2 + 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	//打印下半部分（倒三角）
	for (i = 0; i < line; i++)
	{
		//打印开始的空格
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		//打印*
		for (k = 0; k < 2 * (line - 2 - i) + 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}


int main()

{
	int i = 0;

	int a = 0;

	int sum = 0;

	int num = 0;

	scanf("%d", &num);

	for (i = 0; i < 5; i++)

	{

		a = a * 10 + num;

		sum = sum + a;

	}

	printf("%d", sum);
	system("pause");

	return 0;

}



int main()
{
	int i = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	for (i = 100;i <= 999;i++)
	{
		a = i % 10;       //个位
		c = i / 10 % 10;  //十位
		b = i / 100;      //百位
		if (i == a * a*a + b * b*b + c * c*c)
		{
			printf("%d ", i);
		}
	}
	system("pause");
	return 0;
}