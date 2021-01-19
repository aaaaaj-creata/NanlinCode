//有序数组中出现次数超过25的元素
class Solution {
public:
	int findSpecialInteger(vector<int>& arr) {
		int count = 0;
		int i = 1;
		if (arr.size() == 1)
		{
			return arr[0];
		}
		while (i < arr.size())
		{
			count = 1;
			while (i < arr.size() - 1 && arr[i] == arr[i + 1])
			{
				count++;
				i++;
			}
			if (count > arr.size() / 4)
			{
				return arr[i];
			}
			i++;
		}

		return 0;
	}
};