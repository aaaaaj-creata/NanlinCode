int TestAuto()
{
	return 10;
}
int main()
{
	int a = 10;
	auto b = a; //推导出b为int
	auto c = 'a'; //推导出c为char
	auto d = TestAuto(); //和TestAuto返回的类型一样，即int
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;

	//auto e; 无法通过编译，使用auto定义变量时必须对其进行初始化

	return 0;
}
