#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str,temp;
	getline(cin, str);
	int i = 0,start;
	while (i<str.size())
	{
		if (isdigit(str[i]) || str[i] == '-' || str[i] == '+')
		{
			start = i;
			while (isdigit(str[i]))
			{
				i++;
			}
			cout << str.substr(start, i - start) << " ";
		}
		i++;
	}
	return 0;
}