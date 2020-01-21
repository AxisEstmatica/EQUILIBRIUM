#pragma warning(disable : 4996) // отключение ошибки c4996
#include <stdio.h>
#include <windows.h>
#include <locale.h>
#define STR 1024

void processing(char num[STR / 8]);

void main(void)
{
	char *locale = setlocale(LC_ALL, "");
	WORD foregroundColor0; // цвет слов
	WORD textAttribute;	   // атрибут текста - цвет символа и фона
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	foregroundColor0 = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN;
	textAttribute = foregroundColor0;
	SetConsoleTextAttribute(hStdout, textAttribute);
	int i; // счётчик
	int j; // счётчик
	char str[STR]; // массив строки
	char num[STR / 8]; // массив целочисленной константы
	char *str_ptr = str;
	FILE *frd;
	printf("Please enter address of file: ");
	gets(str); // получаем путь к файлу
	if (*str_ptr == '"')
	{ // удаление ковычек
		i = 0;
		while (*(str_ptr + i) != '\0')
		{
			(*(str_ptr + i + 1) == '"') ? (*(str_ptr + i) = '\0') : (*(str_ptr + i) = *(str_ptr + i + 1));
			++i;
		}
	}
	printf("Path of file: %s\n", str); // отладка
	frd = fopen((str), "rt");
	if (frd == NULL)   
		return -2; // chk open file

	while (!feof(frd)) // for EOF
	{
		fgets(str, STR, frd); // get file string
		str_ptr = str;
		i = 0;
		while (*(str_ptr + i) != '\0')
		{
			if (*(str_ptr + i) == '/' && *(str_ptr + i + 1) == '/')
			{ // защита от //
				while (*(str_ptr + i) != '\0')
				{
					printf("%c", *(str_ptr + i));
					++i;
				}
				break;
			}
			if (*(str_ptr + i) == '-' || (*(str_ptr + i) >= '0' && *(str_ptr + i) <= '9'))
			{
				j = 0;
				while (*(str_ptr + i) != '\0' && *(str_ptr + i) != ';' && *(str_ptr + i) != ' ' && *(str_ptr + i) != ',' && *(str_ptr + i) != '}' && *(str_ptr + i) != ']' && *(str_ptr + i) != '\n' && *(str_ptr + i) != ')')
				{
					num[j] = *(str_ptr + i);
					++i;
					++j;
				}
				--i;
				num[j] = '\0';
				processing(num);
			}
			else
				printf("%c", *(str_ptr + i));
			++i;
		}
	}
	fclose(frd);
	return 0;
}

void processing(char num[STR / 8])
{
	WORD foregroundColor0; // цвет обычный
	WORD foregroundColor1; // цвет необычный 
	WORD textAttribute;	   // атрибут текста - цвет символа и фона  
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
	foregroundColor0 = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN;
	foregroundColor1 = FOREGROUND_INTENSITY | FOREGROUND_RED;
	int j = 0;
	int value = strlen(num);
	while (num[j] == '-' || (num[j] >= '0'&& num[j] <= '9'))
		++j;
	if (value == j)
	{
		textAttribute = foregroundColor1;
		SetConsoleTextAttribute(hStdout,textAttribute);
		printf("%s", num);
		textAttribute = foregroundColor0;
		SetConsoleTextAttribute(hStdout, textAttribute);
	}
	else
		printf("%s", num);
	return;
}
