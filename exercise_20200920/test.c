#include<stdio.h>
#include<string.h>

void replaceSpace(char* str, int length) 
{
	int i, j, sum = 0, tmp_len;
	for (i = 0; i < length; i++)
	{
		if (str[i] == ' ')
		{
			sum++;
		}
	}
	tmp_len = length + 2 * sum - 1;
	j = length - 1;
	while (j >= 0)
	{
		if (str[j] == ' ')
		{
			j--;
			str[tmp_len--] = '0';
			str[tmp_len--] = '2';
			str[tmp_len--] = '%';
		}
		else
		{
			str[tmp_len--] = str[j--];
		}
	}

	return str;
}
