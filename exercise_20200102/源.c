#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)

//第1题
//int main()
//{
//	float a = 0, b = 0, c = 0;
//	float temp = 0;//计算b*b-4*a*c
//	float num = 0;//开根号
//	float x1 = 0, x2 = 0;//方程的根
//	printf("Enter a,b,c:");
//	scanf_s("%f %f %f", a, b, c);
//	temp = b * b - 4 * a * c;
//	num = sqrt(temp);
//
//	if (temp > 0) //两个不同实根
//	{
//		x1 = (-b + num) / (2 * a);
//		x2 = (-b - num) / (2 * a);
//		printf("x1=%0.2f, x2=%0.2f\n", x1, x2);//保留两位输出
//	}
//	if (temp == 0)//一个相同实根
//	{
//		x1 = x2 = (-b) / (2 * a);
//		printf("x1=x2=%0.2f\n", x1);//保留两位输出
//	}
//	if (temp < 0)//共轭复数，无实根
//	{
//		float n;
//		float m;
//		n = sqrt(-temp);
//		m = 2 * a;
//		printf("x1=-%0.2f+(%0.2fi)/%0.2f%s\n", b, n, m);
//		printf("x1=-%0.2f-(%0.2fi)/%0.2f%s\n", b, n, m);//保留两位输出
//	}
//}

//第2题
//void turn(int num)
//{
//	if (num <= 9)
//	{
//		printf("%d",num);
//	}
//	else
//	{
//		printf("%d", num % 10);
//		turn(num / 10);
//	}
//}
//
//int main()
//{
//	int number;
//	printf("Enter a number:");
//	scanf_s("%d", &number);
//	turn(number);
//	return 0;
//}

//第3题
void input(int* str, int len)
{
	int sum = 0;
	printf("请输入成绩个数（小于50个）：");
	scanf("%d\n", &len);
	for (int i = 0; i < len; i++)
	{
		scanf("%d\n", &sum);//输入分数
		str[i] = sum;
	}
	return str;
}

void swap(int* a, int* b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

int sort(int* str,int len)//冒泡排序
{
	int i=0,j=0;
	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (str[i] < str[j])//降序
			{
				swap(&str[i], &str[j]);
			}
		}
	}

	return str;
}

void search(int* a,int len,int key)
{
		int  low, high, mid;
		low = 1;					
		high = len;				
		while (low <= high)
		{
			mid = (low + high) / 2;		

			if (key < a[mid])			
			{
				high = mid - 1;			
			}
			else if (key > a[mid])		
			{
				low = mid + 1;			
			}
			else
			{
				printf("找到了下标为%d",mid);

			}
		}
		
		return 0;					
}

int main()
{
	int arr[50] = { 0 };//初始化数组
	int num = 0;//待查找的分数
	int n = 0;
	input(arr, n);
	sort(arr,n);
	search(arr,n,num);

	return 0;
}