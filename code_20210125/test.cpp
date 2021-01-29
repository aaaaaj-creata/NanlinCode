#include <iostream>
#include <vector>
using namespace std;

#if 0
int zeronum(int n)//计算N!有多少个0
{
	int num = 0;
	int i, j;

	for (i = 5; i <= n; i += 5)
	{
		j = i;
		while (j % 5 == 0)
		{
			num++;
			j /= 5;
		}
	}
	return num;
}

int main()
{
	int n = zeronum(10000);
	cout << n << endl;
	return 0;
}
#endif

//年终奖问题
class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        int value = board[0][0];//拿走的物品总价值
        int i = 0, j = 0;
        while (i < 6 && j < 6)
        {
            if (i == 5)
            {
                value += board[i][j + 1];
                j++;
            }
            if (j == 5)
            {
                value += board[i + 1][j];
                i++;
            }
            if (i < 5 && j < 5 && board[i + 1][j] > board[i][j + 1])
            {
                value += board[i + 1][j];
                i++;
            }
            if (i < 5 && j < 5 && board[i + 1][j] < board[i][j + 1])
            {
                value += board[i][j + 1];
                j++;
            }
            if (j == 5 && i == 5)
            {
                break;
            }
        }
        return value;
    }
};


void test1()
{
    Bonus s;
    int value = 0;
    vector<vector<int>> b = { {564,448,654,186,490,699},
                              {487,444,563,228,365,261},
                              {429,505,612,564,715,726},
                              {464,617,234,647,702,263},
                              {245,249,231,462,453,646},
                              {669,510,492,512,622,135} };

    value = s.getMost(b);
    cout << value << endl;
}

//迷宫问题
void migong(vector<vector<int>> b,int N, int M)
{
    int i = 0, j = 0;
    while (i < N && j < M)
    {
        if (i == N)
        {
            if (b[i][j + 1] == 0)
            {
                j++;
            }
            
        }
    }
}


int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> b = {{0,1,0,0,0},
                             {0,1,0,1,0},
                             {0,0,0,0,0},
                             {0,1,1,1,0},
                             {0,0,0,1,0}};
    migong(b, N, M);
    return 0;
}


