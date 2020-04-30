//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<assert.h>
//1
//int max(int a,int b,int c)
//{
//	int max=0;
//	if(a>=b && a>=c)
//	{
//		max=a;
//	}
//	if(b>=a && b>=c)
//	{
//		max=b;
//	}
//	if(c>=b && c>=a)
//	{
//		max=c;
//	}
//	return max;
//}
//
//int main()
//{
//	int a=1,b=2,c=3;
//	printf("%d",max(a,b,c));
//	return 0;
//}


//2
//void reverse()
//{
//      char ch;
//      ch = getchar();
//      if(ch!='\n')
//      {
//        reverse();
//        putchar(ch);
//    	}
//}
//
//int main()
//{
//      reverse();
//     printf("\n");
//    return 0;
//}


//3 
//typedef struct Student
//{
//	char name[24];
//	int  score;
//}Student;
////第一问 
//void input(struct Student* p, int len, int flag)
//{
//	assert(p);
//	int i = 0;
//	for (i = flag; i < len; i++)
//	{
//		printf("请输入姓名:");
//		scanf("%s", &p[i].name);
//		printf("请输入成绩:");
//		scanf("%d", &p[i].score);
//	}
//}
////第二问 
//void output(struct Student* p, int len)
//{
//	assert(p);
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		printf("name:%s score:%d", p[i].name, p[i].score);
//		printf("\n");
//	}
//}
////第三问 
//int cmpfunc(const void* a, const void* b)
//{
//	return (*(int*)a - *(int*)b);
//}
//
//void sort(struct contact* p, int len)
//{
//	assert(p);
//	qsort(p, len, sizeof(struct Student), cmpfunc);
//
//}

//int main()
//{
//	int i, j;
//	char s[80], t[80];
//	scanf_s("%s%s", &s, &t);
//	for (i = 0; s[i] == '\0'; i++)
//		;
//	for (j = 0; t[j] != '\0';)
//	{
//		s[i] = t[j];
//		j++;
//	}
//
//	printf("%s\n", s);
//	return 0;
//}

#include<stdio.h>
#define M 3
#define N 3
int MaxScore(int s[][N], int m, int n);
int main()
{
	int score[M][N], max, i, j;
	for (i = 0; i < M; i++)
		for (j = 0; j < M; j++)
			scanf_s("%d", &score[i][j]);//scanf("%d",&score[i][j]);
	max = MaxScore(score, M, N);//
	printf("max score=%d\n", max);
	return 0;
}

int MaxScore(int s[][N], int m, int n)
{
	int max = s[0][0], i, j;
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
		{
			if (max < s[i][j])//
				max = s[i][j];
			
		}
	return max;
}
