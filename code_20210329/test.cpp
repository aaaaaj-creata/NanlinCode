#include <iostream>
using namespace std;

class One
{
public:
	One() {
		cout << "constructor\n";
	}
private:
	~One() {
		cout << "destructor\n";
	}
	friend void Destroy(One* one);
};
void Destroy(One* one)
{
	if (one != nullptr) {
		delete one;
	}
}

int main()
{
	     //One one; // 这样是不行的，不能访问析构函数
		//One* one;//ok
		One* one = new One(); //ok
		return 0;
}
