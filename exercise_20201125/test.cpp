#include<iostream>
#include<vector>
using namespace std;

#if 0
int main()
{
	int A=0, B=0, C=0, D=0;
	vector<int> v(4,0);
	for (int i = 0; i < 4; i++)
	{
		cin >> v[i];
	}
	A = (v[0] + v[2]) / 2;
	B = (v[1] + v[3]) / 2;
	C = (v[3] - v[1]) / 2;
	cout << A << " " << B << " " << C << endl;

	return 0;
}
#endif


#include <iostream>
using namespace std;
int main() {
	string s = "", table = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;
	while (m) {
		if (m < 0) {
			m = -m;
			cout << "-";
		}
		s = table[m % n] + s;
		m /= n;
	}
	cout << s << endl;
	return 0;
}