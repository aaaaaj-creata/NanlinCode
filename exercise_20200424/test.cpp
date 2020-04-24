//前提：
const int a = 10;
const int b = 10;
int c = 10;
double d = 1.11;

//下面这些代码谁对谁错？？
int& r1 = a;
const int& r2 = b;
int r3 = b;
int* p1 = &b;
const int* p2 = &b;
int* p3 = &c;
const* p4 = &c;
int& r4 = d;
const int& r4 = d;


void swap(&a, &b)
{
	int c = a;
	a = b;
	b = c;
}

int main()
{
	int x1 = 10, x2 = 20;
	swap(x1, x2);

	cout << x1 << endl;
	cout << x2 << endl;
	return 0;
}

int Arr（int i）//改成int &Arr(int i)
{
	static int a[10] = {0,1,2,3,4,5};
	return a[i];
}

int main()
{
	Arr(3) = 10;
	cout << Arr(3) << endl;

	return 0;
}

