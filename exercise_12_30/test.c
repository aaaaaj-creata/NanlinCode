#include<stdio.h>
int main()
{
	int v = 0;
	//v >= 0 && v <= 500;
	while (scanf_s("%d", &v) != EOF)
	{
		if (v > 60)
			printf("Speed£º%d - Speeding\n", v);
		else
			printf("Speed: %d - OK\n", v);
	}
	return 0;
}

//#include<stdio.h>
//int main()
//{
//	int desk=0;
//	int	chair=0;
//	int x = 0, y = 0;
//	while (scanf_s("%d %d", &x, &y) != EOF)
//	{
//		chair  = y/ (x - 1);
//		desk = chair * x;
//		printf("%d %d", desk, chair);
//	}
//	return 0;
//}

//#include <stdio.h>
//int main() {
//	int num = 0;
//	int j = 0, k = 0;
//	while (scanf_s("%d",&num) != EOF) 
//	{
//		//if (k != 0) 
//		//{    
//		//	printf("\n");
//		//}
//		k++;
//		for (int i = 1; i < num; i++) 
//		{
//			for (j = 0; j < num - i; j++) 
//			{
//				
//				printf(" ");
//			}
//			printf("*");
//			
//
//			if (i != 1) 
//			{
//				for (j = 0; j < 2 * i - 3; j++) 
//				{
//					printf(" ");
//				}
//				printf("*\n");
//			}
//
//			else 
//			{
//				printf("\n");
//			}
//
//		}
//
//		for (j = 0; j < 2 * num - 1; j++) 
//		{
//			printf("*");
//		}
//
//		printf("\n");
//	}
//	return 0;
//}

