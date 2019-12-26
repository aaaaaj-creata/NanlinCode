#include<stdio.h>

int main()
{
	const int a = 10;
	const int b = 10;
	double d = 1.11;

	int* p1 = &b;
	//const int* p2 = &b;
	//int* p3 = &a;
	//const* p4 = &a;
	//int& rd = d;
	//const int& rd = d;

	return 0;
}