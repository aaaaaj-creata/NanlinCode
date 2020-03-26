#include"student.h"
int num = 0;
int i = 0;
student st[100];    //学生个数

/*****************************
*   学生通讯录信息的输入    *
*****************************/

void student::input()
{
	fstream file;
	char ch = 'y';
	//以输出方式打开文件，如果已经有此名字的文件，则其原有内容全部删除。
	file.open("d://student.txt", ios::out);
	while (ch == 'y' || ch == 'Y')
	{
		cout << "please input student's message!" << endl;
		cout << "\t请输入姓名：\t";
		cin >> st[i].name;
		cout << "\t请输入性别：\t";
		cin >> st[i].sex;
		cout << "\t请输入出生年月(如199109):";
		cin >> st[i].birth;
		cout << "\t请输入学校：\t";
		cin >> st[i].school;
		cout << "\t请输入班级(数字):\t";
		cin >> st[i].Class;
		cout << "\t请输入电话号码:\t";
		cin >> st[i].tel;
		cout << "\t请输入邮政编码:\t";
		cin >> st[i].box;
		cout << "\t请输入QQ号:\t";
		cin >> st[i].qq;
		cout << "\t请输入家庭住址:\t";
		cin >> st[i].address;
		file << st[i].name << "  " << st[i].sex << "    " << st[i].birth << "    "
			<< st[i].school << "  " << st[i].Class << "   " << st[i].tel << "   "
			<< st[i].box << "   " << st[i].qq << "   " << st[i].address << endl;
		cout << "\t☆继续输入?(Y/N):";
		cin >> ch;
		num += 1;
		i++;
	}
	cout << "\t您一共输入了" << num << "个人学生的记录。\n";
	file.close();
	menu();
}

/*****************************
*      学生通讯录的修改     *
*****************************/

void student::modify()
{
	fstream file;
	cout << "修改需密码，请输入(1):";
	int p;
	cin >> p;
	if (p != 1)
	{
		cout << "\t***密码错误!***" << endl;
		return;
	}
	else
	{
		cout << "请输入要修改的学生的姓名：\t";
		char pName[20];
		cin >> pName;
		for (i = 0; i < num; i++)
		{
			if (strcmp(st[i].name, pName) == 0)
				break;
			else
			{
				cout << "\t要修改的学生不存在！\n"; return;
			}
		}
		cout << "请输入修改后的姓名：\t"; cin >> name;
		cout << "请输入修改后的性别：\t"; cin >> sex;
		cout << "请输入修改后的出生年月："; cin >> birth;
		cout << "请输入修改后的学校：\t"; cin >> school;
		cout << "请输入修改后的班级(数字)：\t"; cin >> Class;
		cout << "请输入修改后的电话号码："; cin >> tel;
		cout << "请输入修改后的邮政编码："; cin >> box;
		cout << "请输入修改后的QQ号：\t"; cin >> qq;
		cout << "请输入修改后的家庭住址："; cin >> address;
		strcpy(st[i].name, name);
		strcpy(st[i].sex, sex);
		strcpy(st[i].birth, birth);
		strcpy(st[i].school, school);
		st[i].Class = Class;
		strcpy(st[i].tel, tel);
		strcpy(st[i].box, box);
		strcpy(st[i].qq, qq);
		strcpy(st[i].address, address);
	}
	file.open("d://student.txt", ios::out);
	for (i = 0; i < num; i++)
	{
		file << st[i].name << "  " << st[i].sex << "    " << st[i].birth << "    "
			<< st[i].school << "  " << st[i].Class << "   " << st[i].tel << "   "
			<< st[i].box << "   " << st[i].qq << "   " << st[i].address << endl;
	}
	cout << "\t***修改成功***\n";
	menu();
	file.close();
}

/*****************************
*      学生通讯录的查询     *
*****************************/

void student::search()
{
	char* inputname = new char[20];
	fstream file;
	file.open("d:\\student.txt", ios::in | ios::out);//以读的方式打开文件
	cout << "\t1.按姓名查询 " << "☆2.按班级查询" << endl;
	int a;
	cin >> a;
	if (a == 1)
	{
		cout << "\t请输入您要查询的学生的姓名:";
		cin >> inputname;
		int flag = 0;
		for (i = 0; i <= num; i++)
		{
			if (strcmp(st[i].name, inputname) == 0)
			{
				cout << "\t姓名为" << inputname << "的学生的信息如下:" << endl;
				biaotou();
				cout << st[i].name << "  " << st[i].sex << "    " << st[i].birth << "    "
					<< st[i].school << "  " << st[i].Class << "   " << st[i].tel << "   "
					<< st[i].box << "   " << st[i].qq << "   " << st[i].address << endl;
				flag = 1;
			}
		}
		if (flag != 1)
			cout << "\t对不起，您要查找的数据不存在！";
		return;
	}
	else if (a == 2)
	{
		int flag2 = 0;
		cout << "\t请输入您要查询的学生的班级:";
		int inputClass;
		cin >> inputClass;
		for (i = 0; i < num; i++)
		{
			if (st[i].Class == inputClass)
			{
				cout << "\t班级为" << inputClass << "的学生的信息如下:" << endl;
				biaotou();
				cout << st[i].name << "  " << st[i].sex << "    " << st[i].birth << "    "
					<< st[i].school << "  " << st[i].Class << "   " << st[i].tel << "   "
					<< st[i].box << "   " << st[i].qq << "   " << st[i].address << endl;
				flag2 = 1;
			}
		}
		if (flag2 != 1)
			cout << "\t对不起，您要查找的数据不存在！" << endl;
	}
	file.close();
	menu();
}

/*****************************
*      学生通讯录的输出     *
*****************************/

void student::display()
{
	fstream file;
	cout << "\t学生通讯录信息统计如下：" << endl;
	biaotou();
	//以输入输出方式打开文件，文件可读可写
	file.open("d:\\student.txt", ios::in | ios::out);
	for (i = 0; i < num; i++)
		file >> st[i].name >> st[i].sex >> st[i].birth >> st[i].school >> st[i].Class >> st[i].tel >> st[i].box >> st[i].qq >> st[i].address;
	file.close();
	for (i = 0; i < num; i++)
	{
		cout << st[i].name << "  " << st[i].sex << "    " << st[i].birth << "    "
			<< st[i].school << "  " << st[i].Class << "   " << st[i].tel << "   "
			<< st[i].box << "   " << st[i].qq << "   " << st[i].address << endl;
	}
	menu();
}

/*****************************
*      学生通讯录的删除     *
*****************************/

void student::deletes()
{
	fstream file;
	cout << "\t需删除的学生的姓名是：";
	char pName[20];
	cin >> pName;
	for (int i = 0; i < num; i++)
	{
		if (strcmp(st[i].name, pName) == 0)
			break;
	}
	for (int j = i; j < num; j++)//将要删除的学生调至数组最后一位
	{
		student temp = st[j];
		if (j < num - 1)
		{
			st[j] = st[j + 1];
			st[j + 1] = temp;
		}
	}
	file.open("d:\\student.txt", ios::out);
	if (i < num)
	{
		num -= 1;
		cout << "\t\t姓名为" << pName << "的学生已删除！\n";
	}
	else
	{
		cout << "\t要删除的学生不存在！\n";
	}
	for (i = 0; i < num; i++)
	{
		file << st[i].name << "  " << st[i].sex << "    " << st[i].birth << "    "
			<< st[i].school << "  " << st[i].Class << "   " << st[i].tel << "   "
			<< st[i].box << "   " << st[i].qq << "   " << st[i].address << endl;
	}
}

void student::qingkong()
{
	fstream file;
	file.open("d://student.txt", ios::out);
	num = 0;
	cout << "\t**通讯录已清空！**\n";
}

//********表头**********
void student::biaotou()
{
	cout << "姓名    " << "性别  " << "出生年月  " << "学校    " << "班级  "
		<< "电话号码     " << "邮政编码  " << "QQ号      " << "家庭住址" << endl;
}

/*****************************
*      菜 单 选 择 函 数    *
*****************************/
void student::menu()
{

	while (1)
	{
		cout << endl;
		cout << "\t=zzia=zzia=zzia=zzia=zzia=zzia=\n";
		cout << "\t||      制作者：王南蔺       ||\n";
		cout << "\t||      ◇录入纪录（I/i）    ||\n";
		cout << "\t||      ◇查询纪录（S/s）    ||\n";
		cout << "\t||      ◇修改纪录（M/m）    ||\n";
		cout << "\t||      ◇显示纪录（D/d）    ||\n";
		cout << "\t||      ◇删除纪录（X/x）    ||\n";
		cout << "\t||      ◇清空纪录（Q/q）    ||\n";
		cout << "\t||      ◇退出操作（E/e）    ||\n";
		cout << "\t||      班级：网络1802       ||\n";
		cout << "\t||        欢迎您的使用       ||\n";
		cout << "\t=zzia=zzia=zzia=zzia=zzia=zzia=\n";
		cout << "☆ 请输入您的选择（I/i，S/s，M/m，D/d，X/x，Q/q，E/e，不区分大小写）：";
		char ch;
		cin >> ch;
		switch (ch)
		{
		case'i':
		case'I':
			input(); break;
		case's':
		case'S':
			search(); break;
		case'm':
		case'M':
			modify(); break;
		case'd':
		case'D':
			display(); break;
		case'x':
		case'X':
			deletes(); break;
		case'q':
		case'Q':
			qingkong(); break;
		case'e':
		case'E':
			cout << "\t谢谢您的使用!" << endl;
			exit(0); break;
		default:
			cout << "\t您的选择有误!\n"; break;
		}
	}
}




