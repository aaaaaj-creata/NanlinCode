#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

int a[4][4];
int empty;

void board(void)//4x4的表格
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 4; ++i)
	{          // 一个方格由三根竖线组成 
		for (j = 0; j < 4; ++j)  // 第一排竖线 每个竖线之间占5个格 
			printf("|    ");
		printf("|\n");

		for (j = 0; j < 4; ++j) 
		{   // 第二排竖线与数字 
			if (a[i][j] == 0)
				printf("|    ");
			else
				printf("|%4d", a[i][j]);
		}
		printf("|\n");

		for (j = 0; j < 4; ++j)     // 第三排竖线加底线 
			printf("|____");
		printf("|\n");
	}
}

void init(void)//初始数组并生成一个随机元素*
{
	int i, j;

	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
			a[i][j] = 0;
	srand(time(0));
	i = rand() % 4;
	j = rand() % 4;
	a[i][j] = 2;
}

void control(void) //控制移动*
{
	char ch;
	ch = getch();
	switch (ch)
	{
		case 'w':    // 向上移动 
		case 'W':
			to_up();
			system("cls"); //清屏
			add_number();
			board(); 
		break;
		case 's':    
		case 'S':
			to_down();
			system("cls"); 
			add_number();
			board();
			break;
		case 'a':    
		case 'A':
			to_left();
			system("cls");
			add_number();
			board();
			break;
		case 'd':   
		case 'D':
			to_right();
			system("cls");
			add_number();
			board();
			break;
	}
}

void to_up(void) //先合并再移动
{
	int x = 0;
	int y = 0;
	int i = 0;
	for (y = 0; y < 4; ++y)
	{     // 从上向下合并相同的方块 
		for (x = 0; x < 4; ++x) 
		{
			if (a[x][y] == 0)
				;
			else 
			{
				for (i = x + 1; i < 4; ++i)
				{
					if (a[i][y] == 0)
						;
					else if (a[x][y] == a[i][y]) 
					{
						a[x][y] += a[i][y];
						a[i][y] = 0;
						++empty;
						x = i;
						break;
					}
					else 
					{
						//x = i - 1;
						break;
					}
				}
			}
		}
	}

	for (y = 0; y < 4; ++y)    // 向上移动箱子
		for (x = 0; x < 4; ++x) 
		{
			if (a[x][y] == 0)
				;
			else 
			{
				for (i = x; (i > 0) && (a[i - 1][y] == 0); --i) 
				{
					a[i - 1][y] = a[i][y];
					a[i][y] = 0;
				}
			}
		}

}

void to_down(void) 
{
	int x, y, i;

	for (y = 0; y < 4; ++y)  // 向下合并相同的方格 
		for (x = 3; x >= 0; --x) {
			if (a[x][y] == 0)
				;
			else {
				for (i = x - 1; i >= 0; --i) {
					if (a[i][y] == 0)
						;
					else if (a[x][y] == a[i][y]) {
						a[x][y] += a[i][y];
						a[i][y] = 0;
						++empty;
						x = i;
						break;
					}
					else
						break;
				}
			}
		}

	for (y = 0; y < 4; ++y)  // 向下移动方格 
		for (x = 3; x >= 0; --x) {
			if (a[x][y] == 0)
				;
			else {
				for (i = x; (i < 3) && (a[i + 1][y] == 0); ++i) {
					a[i + 1][y] = a[i][y];
					a[i][y] = 0;
				}
			}
		}
}

void to_left(void)
{
	int x, y, i;

	for (x = 0; x < 4; ++x)   // 向左合并相同的方格 
		for (y = 0; y < 4; ++y) {
			if (a[x][y] == 0)
				;
			else {
				for (i = y + 1; i < 4; ++i) {
					if (a[x][i] == 0)
						;
					else if (a[x][y] == a[x][i]) {
						a[x][y] += a[x][i];
						a[x][i] = 0;
						++empty;
						y = i;
						break;
					}
					else
						break;
				}
			}
		}

	for (x = 0; x < 4; ++x)  // 向左移动方格 
		for (y = 0; y < 4; ++y) {
			if (a[x][y] == 0)
				;
			else {
				for (i = y; (i > 0) && (a[x][i - 1] == 0); --i) {
					a[x][i - 1] = a[x][i];
					a[x][i] = 0;
				}
			}
		}
}

void to_right(void)
{
	int x, y, i;

	for (x = 0; x < 4; ++x)  // 向右合并相同的方格 
		for (y = 3; y >= 0; --y) {
			if (a[x][y] == 0)
				;
			else {
				for (i = y - 1; i >= 0; --i) {
					if (a[x][i] == 0)
						;
					else if (a[x][y] == a[x][i]) {
						a[x][y] += a[x][i];
						a[x][i] = 0;
						++empty;
						y = i;
						break;
					}
					else
						break;
				}
			}
		}

	for (x = 0; x < 4; ++x)   // 向右移动方格 
		for (y = 3; y >= 0; --y) {
			if (a[x][y] == 0)
				;
			else {
				for (i = y; (i < 3) && (a[x][i + 1] == 0); ++i) {
					a[x][i + 1] = a[x][i];
					a[x][i] = 0;
				}
			}
		}
}

void add_number(void) //加新数
{
	int temp, number;
	int x, y;

	if (empty > 0) {     // 找出空格 
		srand(time(0));
		do {
			x = rand() % 4;
			y = rand() % 4;
		} while (a[x][y] != 0);

		number = rand();
		temp = number % 2;

		if (temp == 1) {  // 判断是生成数字2，还是数字4
			a[x][y] = 2;
			--empty;
		}
		if (temp == 0) {
			a[x][y] = 4;
			--empty;
		}
	}
}
