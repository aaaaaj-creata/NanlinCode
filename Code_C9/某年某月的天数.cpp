#include <stdio.h>
int main()
{
	int year,month;
	scanf("%d\\%d",&year,&month);
	if(year%2==0 && year%100!=0||year%400==0)
	{
		switch(month)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:printf("31");break;
			case 4:
			case 6:
			case 9:
			case 11:printf("30");break;
			case 2:printf("29");break;
		}
	}
	else
	{
		switch(month)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:printf("31");break;
			case 4:
			case 6:
			case 9:
			case 11:printf("30");break;
			case 2:printf("28");break;
		}
	}
	return 0;
}
