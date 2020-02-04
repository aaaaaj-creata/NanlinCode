#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>     // for rand() and srand() and exit()
#include <time.h>       // for time()
#include <conio.h>      // for getch()
#include <windows.h>    // for system()

void board(void);
void init(void);
void control(void);
void to_up(void);
void to_down(void);
void to_left(void);
void to_right(void);
void add_number(void);