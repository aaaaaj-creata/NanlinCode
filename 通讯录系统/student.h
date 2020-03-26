#if !defined _STUDENT_H_
#define _STUDENT_H_
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class student
{
public:
	void input();       //增加
	void search();      //查询
	void modify();      //修改
	void display();     //输出
	void deletes();     //删除
	void qingkong();    //清空
	void menu();        //菜单选择
	void biaotou();     //表头
private:
	char name[20];      //姓名  
	char sex[4];        //性别
	char birth[10];     //出生年月
	char school[20];    //学校
	int Class;          //班级
	char tel[15];       //电话号码
	char box[10];       //邮政编码
	char qq[15];        //QQ号
	char address[20];   //家庭住址
};
#endif
