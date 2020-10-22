#include<bits/stdc++.h> 

int Binarysearch(int arr[], int len, int k)
{
	int low = 0, high = len - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (k == arr[mid])
		{
			return mid;
		}
		if (k > arr[mid])
		{
			low = mid + 1;
		}
		else high = mid - 1;
	}

	return -1;
}

void Bubblesort(int arr[], int len)
{
	int i, j, temp;
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}



int main()
{
	int arr[] = { 2,1,3,6,5,4,10,9,8,7 };
	int k = 3, addr = 0, len = 0;
	len = sizeof(arr) / sizeof(arr[0]);
	Bubblesort(arr, len);
	addr = Binarysearch(arr, len, k);
	printf("%d", addr);

	return 0;

}