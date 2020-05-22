void TestFor()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (auto e : array)//拷贝，不能修改
		e *= 2;

	for (auto& e : array)//别名+修改
		e *= 2;

	for (const auto& e : array)//别名+只读
		e *= 2;

	for (auto e : array)
		cout << e << " ";
	return 0;
}
