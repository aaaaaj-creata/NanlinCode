//字符集合

#include <stdio.h>
int main()
{
	char str[101];
	while (scanf("%s", &str) != EOF)
	{
		int a[256] = { 0 };
		for (int i = 0; str[i] != '\0'; i++)
		{
			a[str[i]] ++;
			if (a[str[i]] == 1)
				printf("%c", str[i]);
		}
		printf("\n");
	}
	return 0;
}

//元素查找
int findElement(vector<int> A, int n, int x) {
	int i = 0, j = n - 1, mid;
	while (i <= j) {
		mid = (i + j) / 2;
		if (A[mid] == x)
			return mid;
		if (A[mid] < x) {
			if (A[mid]<A[i] && x>A[j]) j = mid - 1;
			else i = mid + 1;
		}
		else {
			if (A[mid] > A[i] && x < A[i]) i = mid + 1;
			else j = mid - 1;
		}
	}
	return -1;
}