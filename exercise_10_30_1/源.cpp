#include<iostream>
using namespace std;
int main() {
	double x,y ;
	cout << "请输入一个常数x" << endl;
	cin >> x;
	if (x < 1) 
	{
		y = x;
	}	
	else if (1 <= x && x < 10)
	{
		y = 2 * x - 1;
	}
	else 
	{
		y = 3 * x - 11;
	}
	cout << "y=" << y << endl;
	return 0;
}