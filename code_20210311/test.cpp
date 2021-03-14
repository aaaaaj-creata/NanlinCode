#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	void Bubble(vector<int> & list)
	{
		for (int i = 0; i < list.size() - 1; i++)
		{
			for (int j = 0; j < list.size() - 1 - i; j++)
			{
				if (list[j + 1] < list[j])
				{
					list[j+1] ^= list[j];
					list[j] ^=  list[j + 1];
					list[j + 1]  ^= list[j];
				}
			}
		}
	}

	void quicksort(vector<int>& list , int low, int high)
	{
		if (low < high)
		{
			int i = low;
			int j = high;
			int key = list[i];
			while (i < j)
			{
				while (i < j && list[j] >= key)
				{
					j--;
				}
				if (list[i] > list[j])
				{
					swap(list[i], list[j]);
				}
				while (i < j && list[i] <= key)
				{
					i++;
				}
				if (list[i] > list[j])
				{
					swap(list[i], list[j]);
				}
			}
			key = list[i];
			quicksort(list, low, i - 1);
			quicksort(list, i + 1, high);
		}
	}

	void Insertsort(vector<int>& list)
	{

	}
};

int main()
{
	Solution s;
	vector<int> list = { 4,7,2,5,6,1 };
	//s.Bubble(list);
	//s.Insertsort(list);
	s.quicksort(list,0,list.size()-1);
	for (auto e : list)
	{
		cout << e << " " ;
	}
	return 0;
}