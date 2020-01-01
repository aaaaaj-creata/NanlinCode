//#include<iostream>
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//	void replaceSpace(char* str, int length)
//	{
//		for (int i = 0; i < length; i++)
//		{
//			if (arr[i] == '\0')
//			{
//				arr[i] = '%20';
//			}
//		}
//	}
//};
//
//int main()
//{
//
//
//	char arr[] = "We Are Happy";
//	len = strlen(arr);
//	replaceSpace(arr, len);
//	cout << arr[] << endl;
//	return 0;
//}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>




//int main()
//	{
//		int a, b, c, m, t;
//		scanf_s("%d%d", &a, &b);
//		if (a < b)
//		{
//			t = a;
//			a = b;
//			b = t;
//		}
//		m = a * b;
//		c = a % b;
//		while (c != 0)
//		{
//			a = b;
//			b = c;
//			c = a % b;
//		}
//		printf( "%d\n",m/b);
//		return 0;
//}


#include<stdio.h>
#include<string.h>

//将字符数组ch中n个字符逆置
void invert(char* ch, int n)
{
	int i;
	char temp;
	for (i = 0; i < n / 2; i++)
	{
		temp = ch[i];
		ch[i] = ch[n - 1 - i];
		ch[n - 1 - i] = temp;
	}
}

//现将字符串全部逆置，将逆置后的字符串部分字符串再逆置。部分字符串的划分依据为是否有空格
void wordInvertInSentence(char* ch)
{
	int i = 0;
	int len;
	len = strlen(ch);
	invert(ch, len);//将字符串全部逆置
	while (ch[i] != '\0')//从字符串起始位置开始遍历，直到访问到结束符
	{
		i = 0;
		while (ch[i] != ' ' && ch[i] != '\0') { i++; }//如果当前的字符不为空格并且没有访问到结束标志，让指针后移，直到当前字符为空格。
		invert(ch, i);//字符串ch中i个字符进行逆置
		if (ch[i] != '\0')//如果没有访问到结束标志，要跳过空格字符，继续访问下个单词
			ch = ch + i + 1;
		else           //如果当前字符已经是结束标志了，不需要再跳过空格字符，外循坏结束。
			ch = ch + i;
	}
}

int main()
{
	char str[100] = "I like beijing.";//
	wordInvertInSentence(str);
	printf("%s", str);
	printf("\n");
}
