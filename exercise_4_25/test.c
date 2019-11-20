//#include <stdio.h>
////将数组A中的内容和数组B中的内容进行交换(数组一样大)
//int main()
//{
//	int arr1[] = { 1, 3, 5, 7, 9 };
//	int arr2[] = { 3, 4, 5, 6 ,7 };
//	int tmp;
//	int i = 0;
//	for (i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
//	{
//		tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//	for (i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	for (i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值。
//int main()
//{
//	int i, flag = 1;
//	float sum = 0.0;
//	for (i = 1; i <= 100; i++)
//	{
//		sum = sum + flag * (1.0 / i);
//		flag = -flag;
//	}
//	printf("sum is %f\n", sum);
//	system("pause");
//	return 0;
//}

int main() {
	int i = 0;
	int k = 0;
	for (i = 1; i < 100; i++)
	{
		if (i % 10 == 9)
		{
			k++;
		}
		if (i / 10 == 9)
		{
			k++;
		}
	}
	printf("%d\n", k);
	return 0;
}