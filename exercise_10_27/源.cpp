#include<iostream>
using namespace std;
int main() {
	int ch;
	int nline = 0, nword = 0, nch = 0;
	int isword = 0;
	cout << "输入一个文本(无空行):" << endl;
	do {
		ch = cin.get();
		if (ch == '\n') nline++;
		if (ch != ' ' && ch != '\t' && ch != '\n' && ch != EOF) {
			if (!isword) nword++;
			nch++;
			isword = 1;
		}
		else isword = 0;
	} while (ch != EOF);
	cout << "行数:" << nline << endl;
	cout << "单词数:" << nword << endl;
	cout << "字符数:" << nch << endl;
	return 0;
}
