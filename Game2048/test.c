#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void  menu()//²Ëµ¥
{
	printf("************************\n");
	printf("******** 1.play ********\n");
	printf("******** 2.exit ********\n");
	printf("Control by:w/s/a/d or W/S/A/D\n");
	printf("************************\n");
}



int main()
{
		menu();
		getch();
		system("cls");
		init();
		board();
		while (1)
		{
			control();
		}
	return 0;
}


