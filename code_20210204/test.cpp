#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main()
{
	static int monthday[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	static int num[13] = { 0,2,1,1,2,1,2,1,2,2,2,1,2 };
	int yearmoney = 579;
	int fromyear, frommonth, fromday;
	int toyear, tomonth, today;
	int sum = 0;
	while (cin >> fromyear >> frommonth >> fromday >> toyear >> tomonth >> today)
	{
		if ((fromyear % 4 == 0 && fromyear % 100 != 0) || fromyear % 400 == 0)
		{
			while (frommonth <= 12)
			{
				(monthday[frommonth] - fromday + 1);
			}
		}
	}
}



#if 0
//ì³²¨ÄÇÆõ·ïÎ²
int main()
{
	int n = 0;
	int fibnum[100001];
	fibnum[0] = 1;
	fibnum[1] = 1;
	for (int i = 2; i <= 100000; i++)
	{
		fibnum[i] = fibnum[i - 1] + fibnum[i - 2];
		fibnum[i] = fibnum[i] % 1000000;
	}
	while (cin >> n)
	{
		cout  << fibnum[n] << endl;
	}
	return 0;
}
#endif