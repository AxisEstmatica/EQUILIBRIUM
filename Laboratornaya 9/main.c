#pragma warning(disable : 4996) // отключение ошибки c4996
#include <stdio.h>
#define YES 1
#define NO 0
#define STR 1024
char filestr[STR];
char c; // текущий символ

void erasespace(void); // удаляем лишние пробелы
void mirrortext(void); // содержимое файла текст на консоль
void mirrorres(void); // содержимое файла рес на консоль

int main(void)
{
	printf("Current contents of the file text.txt:\n");
	mirrortext();
	erasespace();
	printf("\nResult of processing (res.txt):\n");
	mirrorres();
	return 0;
}

void erasespace(void)
{
	int CONTROL = NO;
	char *filestr_ptr;
	FILE *frd, *fwr; 
	frd = fopen("text.txt", "rt"); // открываем исходный файл
	fwr = fopen("res.txt", "w"); // открываем файл результата
	if (frd == NULL || fwr == NULL)
	{
		printf("FILE HAS NOT BEEN OPENED");
		exit(1);
	}
	while (!feof(frd)) // to end of file
	{
		filestr_ptr = fgets(filestr, STR, frd); // читаем строку
		if (filestr_ptr == NULL)
			break; // file end
		while (*filestr_ptr != '\0') // to string end
		{
			c = *filestr_ptr;
			if (c == ' ' || c == ',' || c == '.' || c == '?' || c == '!' || c ==';' || c == ':') // если значение разделителя, то
			{
				c == ' ' ? CONTROL = YES : fprintf(fwr, "%c", c);
			}
			else
			{
				*filestr == ' ' ? CONTROL = NO, *filestr = '.', fprintf(fwr, "%c", c) : CONTROL == YES ? CONTROL = NO, fprintf(fwr, " %c", c) : fprintf(fwr, "%c", c); // выбираем поставить разделитель с пробелом или без
			}
			++filestr_ptr;
		}
		fprintf(fwr, "\0");
	}

	fclose(frd);
	fclose(fwr);
}

void mirrortext(void)
{
	FILE *fp;
	fp = fopen("text.txt", "rt");
	if (fp == NULL) // а это нужно?
	{
		printf("FILE HAS NOT BEEN OPENED");
		exit(1);
	}
	while (!feof(fp))
	{
		c = fgetc(fp);
		printf("%c", c);
	}
	fclose(fp);
}

void mirrorres(void)
{
	FILE *fp;
	fp = fopen("res.txt", "rt");
	if (fp == NULL) // а это нужно?
	{
		printf("FILE HAS NOT BEEN OPENED");
		exit(1);
	}
	while (!feof(fp))
	{
		c = fgetc(fp);
		printf("%c", c);
	}
	fclose(fp);
}