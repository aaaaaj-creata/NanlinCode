#include "contact.h"

//int main()
//{
//	ContactBook cb;
//	ContactBookInit(&cb);
//	Contact con1;
//	strcpy(con1._name, "peter");
//	strcpy(con1._address, "西安未央区浐灞半岛");
//	strcpy(con1._tel, "18241321212");
//	con1._age = 18;
//	ContactBookAppend(&cb, &con1);
//
//	Contact con2;
//	strcpy(con2._name, "小时");
//	strcpy(con2._address, "西安未央区浐灞半岛");
//	strcpy(con2._tel, "18241321214");
//	con2._age = 19;
//	ContactBookAppend(&cb, &con2);
//
//	ContactPrint(&cb);
//	ContactBookSave(&cb, "contactbookbin.txt");
//
//	ContactBookDestory(&cb);
//
//	return 0;
//}
void menu()
{
	printf("********************************************\n");
	printf("1.添加联系人， 2.删除联系人\n");
	printf("3.查找联系人， 4.修改联系人\n");
	printf("5.保存到文件， 6.从文件加载\n");
	printf("7.打印通讯录， 0.退出\n");
	printf("********************************************\n");
}

int main()
{
	ContactBook cb;
	ContactBookInit(&cb);
	Contact con;
	//ContactBookLoad(&cb, "contactbookbin.txt");
	ContactBookLoad(&cb, "53.txt");
	int option = -1;
	while (option != 0)
	{
		menu();
		scanf("%d", &option);
		if (option == 1)
		{
			printf("请依次输入姓名，电话，家庭住址，年龄:\n");
			scanf("%s", con._name);
			scanf("%s", con._tel);
			scanf("%s", con._address);
			scanf("%d", &con._age);
			ContactBookAppend(&cb, &con);
		}
		else if (option == 2)
		{
			const char name[24];
			printf("请输入联系人的名字:");
			scanf("%s", name);
			ContactBookDelete(&cb, name);
		}
		else if (option == 3)
		{
			const char name[24];
			printf("请输入联系人的名字:");
			scanf("%s", name);
			Contact* pcon = ContactBookFind(&cb, name);
			if (pcon == NULL)
			{
				printf("没有找到联系人\n");
			}
			else
			{
				printf("姓名:%s,电话:%s,家庭住址:%s,年龄:%d\n", pcon->_name, pcon->_tel, pcon->_address, pcon->_age);
			}
		}
		else if (option == 5)
		{
			ContactBookSave(&cb, "53.txt");
		}
		else if (option == 6)
		{
			ContactBookLoad(&cb, "53.txt");
		}
		else if (option == 7)
		{
			ContactPrint(&cb);
		}
		else if (option == 0)
		{
			break;
		}
	}

	ContactBookDestory(&cb);

	return 0;
}