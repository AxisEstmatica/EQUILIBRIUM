#pragma warning(disable : 4996) // отключение ошибки c4996
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define YES 1
#define NO 0
#define WR 50
#define STR 2000

int cmp(const void * a, const void * b) // функция сортироки по фамилии имени отчеству
{
	const char* aa = *((const char**)a);
	const char* bb = *((const char**)b);
	return strcmp(aa, bb);
}

int main(void)
{
	char c;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Введите строку: ");
	char **str = (char**)malloc(sizeof(char*));
	str[0] = (char*)malloc(WR*sizeof(char));
	int i = 0;
	do
	{
		scanf("%s",str[i]);
		++i;
		str[i] = (char*)malloc(WR * sizeof(char));
		//c = getch();
		//printf("%d, %c", c, c);
	} while (strncmp((str[i-1]),".",1)!=0);
	--i;
	qsort(str, i-1, sizeof(str[0]), cmp); // сортировка
	for (int j = 0; j < i; j++)
	{
		puts(str[j]);
	}
	//free(str);
	return 0;
}