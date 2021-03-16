
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//int  binarysearch(vector<int> arr, int x)
//{
//	sort(arr.begin(), arr.end()); //arr 1 3 4 7 9
//	int right = 0, left = arr.size() - 1;
//	while (right < left)
//	{
//		int dex = (right + left) / 2;
//		if (x == arr[dex])
//		{
//			return dex;
//		}
//		if (x > arr[dex])
//		{
//			right = dex + 1;
//		}
//		else
//		{
//			left = dex;
//		}
//	}
//}
//
//int main()
//{
//	vector<int> arr = { 3, 4, 1 , 7, 9 };
//	int dex = binarysearch(arr, 3);//ÆÚÍû·µ»Ø1
//	return 0;
//}

void reverse(string& s)
{
	int len = s.size();
	int right = 0;
	int left = len - 1;
	while (right < left)
	{
		swap(s[right], s[left]);
		right++, left--;
	}
}


int main()
{
	string s = "abcde";
	reverse(s);
	cout << s << endl;
	return 0;
}