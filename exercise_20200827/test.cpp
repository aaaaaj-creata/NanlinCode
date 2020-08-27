#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
	string a, b;
	getline(cin, a);
	getline(cin, b);
	unordered_set<char> hash;
	for (int i = 0; i < b.size(); i++) {
		hash.insert(b[i]);
	}
	string res;
	for (int i = 0; i < a.size(); i++) {
		if (hash.count(a[i]) == 0) res += a[i];
	}
	for (int i = 0; i < res.size(); i++) {
		cout << res[i];
	}
	return 0;
}