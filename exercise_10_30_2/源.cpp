#include<iostream>
using namespace std;
class Cuboid {
	double length, width, height;
public:
	double volume() 
	{
		return length * width* height;
	}
	double area()
	{
		return 2 * (length * width + width * height + length * height);
	}
	Cuboid(double h = 0, double i = 0, double j = 0) :length(h), width(i), height(j) {}
};

int main() {
	double a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	Cuboid object(a, b, c);
	double vol = object.volume();
	double sum = object.area();
	cout << vol << endl;
	cout << sum << endl;
	return 0;
}
