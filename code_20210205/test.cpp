#include <iostream>
#include <string>
#include <vector>
using namespace std;

#if 0
//剪花布条
int main() {
	string str, s;
	int count = 0;
	while (cin >> str >> s) {
		count = 0;
		size_t pos = 0;
		while ((pos = str.find(s, pos)) != string::npos) {
			pos += s.size();
			++count;
		}
		cout << count << endl;
	}
	return 0;
}
#endif

//客似云来
int main()
{
    vector<long long> arr(81, 0);
    arr[1] = 1;
    arr[2] = 1;
    for (int i = 3; i < 81; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    int from, to;
    long long sum = 0;
    while (cin >> from >> to)
    {
        sum = 0;
        for (; from <= to; from++)
        {
            sum += arr[from];
        }
        cout << sum << endl;
    }
    return 0;
}
