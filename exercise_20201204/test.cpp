#include<iostream>
#include<vector>
#include<string>
using namespace std;

//¾®×ÖÆå
class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		int sum = 0,num=0;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == 1)
				{
					sum++;
				}
				if (board[i][j] == -1)
				{
					num++;
				}
				if (sum >= 5)
				{
					return true;
				}
			}
		}

		if (sum > num)
		{
			return true;
		}
		else return false;
	}
};

int score = 0;

int length(string s)
{
	if (s.size() >= 8)
	{
		return 25;
	}
	if (s.size() >= 5 && s.size() <= 7)
	{
		return 10;
	}
	if (s.size() <= 4)
	{
		return 5;
	}
}

int main()
{

}

