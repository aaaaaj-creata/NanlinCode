//最难的问题
#include <iostream>
#include <string>
using namespace std;

const string s = "VWXYZABCDEFGHIJKLMNOPQRSTU";

int main()
{
    string key;
    while (getline(cin, key))
    {
        int len = key.size();
        for (int i = 0; i < len; i++)
        {
            if (key[i] == ' ')
            {
                i++;
            }
            if (key[i] >= 'A')
            {
                key[i] = 'E' < key[i] ? (key[i] - 5) : (key[i] + 21);
            }
        }
        cout << key << endl;
    }
    return 0;
}