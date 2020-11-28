#include<iostream>
#include<assert.h>
#include<string.h>
#include<string>
#pragma warning(disable:4996)
using namespace std;

/*
//string类的实现
class string
{
public:

	string(const char* str = "")//构造
	{
		if (nullptr == str)//str为nullptr则判断为非法
		{
			assert(false);
			return;
		}
		//if (nullptr == str)
		//{
		//	 str = "";
		//}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	string(const string& s)//拷贝构造
		:_str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}

	//string(const string& s)//现代版拷贝构造
	//	:_str(nullptr)
	//{
	//	string strtmp(s._str);
	//	swap(_str, strtmp._str);
	//}

	string& operator=(const string& s)//赋值 //传递的是别名
	{
		if (this != &s)
		{
			char* pstr = new char[strlen(s._str) + 1];
			strcpy(pstr, s._str);
			delete[] _str;
			_str = pstr;
		}

		return *this;
	}

	
	//string& operator=(const string s)//传递形参,复用性更好
	//{
	//	swap(_str, s._str);
	//	return *this;
	//}
	

	~string()//析构
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

private:
	char* _str;
};

*/

/*125. 验证回文串
class Solution {
public:
	bool isPalindrome(string s) {
		if (s.empty())//空串也是回文串
		{
			return true;
		}
		if (s.size() == 1)
		{
			return true;
		}

		int left = 0;
		int right = s.size() - 1;
		while (left < right)
		{
			//1.判断是否为字母
			while (left != right)
			{
				if (isalpha(s[left])) break;

				++left;
			}

			while (left < right)
			{
				if (isalpha(s[right])) break;
				--right;
			}
			//2.比较是否相同
			if (left < right)
			{
				if ((s[left] + 32 - 'a') % 32 != (s[right] + 32 - 'a') % 32)//忽略字母大小写
				{
					return false;
				}

			}
			left++;
			right--;
		}
		//3.循环执行完后则证明是回文串
		return true;
	}
};
*/

/*
//给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
class Solution {
public:
	string reverseWords(string s) {
		int lenth = s.size();
		int i = 0;
		while (left < right)//使用循环翻转一个字符串里面的多个单词
		{
			int start = i;
			while (i < lenth && s[i] != ' ')//i移动到空格处
			{
				i++;
			}
			int left = start;
			int right = i - 1;
			while (left < right)//翻转一个单词
			{
				swap(s[left], s[right]);
				++left;
				--right;
			}
			while (i < lenth && s[i] == ' ')//将i移到下个单词初始处
			{
				i++;
			}
		}

		return s;
	}
};
*/

/*
//给定一个字符串 s 和一个整数 k，你需要对从字符串开头算起的每隔 2k 个字符的前 k 个字符进行反转
class Solution {
public:
	string reverseStr(string s, int k) {
		for (int i = 0; i < s.size(); i += (2 * k))//将字符串每隔2k个字符划分一块
		{
			if (i + k <= s.size())//大于等于k，小于2k就将该块前k个字符翻转
			{
				reverse(s.begin() + i, s.begin() + i + k);
				continue;
			}
			//少于k个字符则全部翻转
			reverse(s.begin() + i, s.begin() + s.size());
		}
		return s;
	}
};
*/

/*
//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和
class Solution {
public:
	string addStrings(string num1, string num2) {
		int size1 = num1.size();
		int size2 = num2.size();
		if (size1 < size2)
		{
			num1.swap(num2);
			swap(size1, size2);
		}
		string strRet;
		strRet.reserve(size1 + 1);//相加后的数最多比大的数多一位
		int cstep = 0;//进位1
		int cret = 0;//添加当前位到strRet

		for (size_t i = 0; i < size1; i++)
		{
			cret = num1[size1 - i - 1] - '0' + cstep;//加上之前进的位cstep
			cstep = 0;
			if (i < size2)
			{
				cret += num2[size2 - i - 1] - '0';//两个字符串相同位上的数相加
			}
			if (cret >= 10)
			{
				cret -= 10;//只留个位
				cstep = 1;//相加大于10则进一位
			}
			strRet += cret + '0';
		}
		if (cstep)
		{
			strRet += '1';
		}

		reverse(strRet.begin(), strRet.end());

		return strRet;
	}
};
*/

//将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
int main()
{
	Solution a;
	string s1("999");
	string s2("99");
	string s3 ;
	s3=a.addStrings(s1, s2);
	cout << s3 << endl;
	return 0;
}



