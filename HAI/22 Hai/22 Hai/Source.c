// Отсортировать русские слова по алфавиту

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <Windows.h>
#include <malloc.h>
#define MAXLENGTH 1000
#define LENGTHPTR 300

int8_t compare(char *ptr[], int8_t i, int8_t j);

int main()
{
	int16_t c = ' ';
	int8_t num_w = 0, i = 0, j = 0;
	char *in_c, *buf;
	bool flag = 0;
	char arr[MAXLENGTH];
	char *ptr[LENGTHPTR];
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	gets_s(arr, MAXLENGTH);
	in_c = arr;
	while (c != '\0')
	{
		c = *in_c;
		if (c == ' ' || c == '\0')
		{
			if (flag == 1)
				num_w++;
			flag = 0;
		}
		else
		{
			if (flag == 0)
			{
				ptr[i++] = in_c;
			}
			flag = 1;
		}
		in_c++;
	}
	for (i = 0; i < num_w - 1; i++)
	{
		for (j = i + 1; j < num_w; j++)
		{
			if (compare(ptr, i, j) > 0)							// 1>2
			{
				buf = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = buf;
			}
		}
	}
	for (i = 0; i < num_w; i++)
	{
		j = 0;
		c = *(ptr[i] + j);
		do
		{
			printf("%c", c);
			j++;
			c = *(ptr[i] + j);
		} while (c != ' ' && c != '\0');
		printf(" ");
	}
	printf("\n");
	system("pause");
	return 0;
}

int8_t compare(char *ptr[], int8_t i, int8_t j)
{
	int8_t found = 0, k = 0;
	char c_1, c_2;
	do
	{
		c_1 = *(ptr[i] + k);
		c_2 = *(ptr[j] + k);
		if (c_1 == c_2)
		{
			found = 1;
		}
		else
		{
			found = 0;
			break;
		}
		k++;
	} while (c_1 != ' ');
	found = (c_1 == ' ' && c_2 != ' ') ? -1 : (c_2 == ' ' && found == 1) ? 0 :
		((c_1 > c_2) || (c_1 != ' ' && (c_2 == ' ' || c_2 == '\0'))) ? 1 : -2;
	return found;
}