#pragma warning(disable : 4996) // ���������� ������ c4996
#include <stdio.h>
//#include <malloc.h>
//#include <string.h>
//#include <stdlib.h>
#include <windows.h>
#define YES 1
#define NO 0
#define STR 1024



//void read(char *ptr);
void processing(char num[STR / 8]);

void main(void)
{
	WORD foregroundColor0; // ���� ����
	WORD textAttribute;	   // ������� ������ - ���� ������� � ����
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	foregroundColor0 = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN /*| FOREGROUND_RED*/;
	textAttribute = foregroundColor0;// | backgroundColor;
	SetConsoleTextAttribute(hStdout, textAttribute);
	/*
	WORD foregroundColor0; // ���� ����  
	WORD foregroundColor1; // ���� ������������  
	//WORD foregroundColor;  // ���� �������  
	WORD backgroundColor;  // ���� ����  
	WORD textAttribute;	   // ������� ������ - ���� ������� � ���� 

 // �������� ����������� ����������   
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

 // ���������� ����� ��������, ������������ � ����  
	foregroundColor0 = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN /*| FOREGROUND_RED*/;
	//foregroundColor1 = FOREGROUND_INTENSITY | FOREGROUND_RED;
	//backgroundColor = BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
	

	int i; // �������
	int j; // �������
	char str[STR]; // ������ ������
	char num[STR / 8]; // ������ ������������� ���������
	char *str_ptr = str;
	FILE *frd;
	printf("Please enter address of file: ");
	gets(str); // �������� ���� � �����
	if (*str_ptr == '"')
	{ // �������� �������
		i = 0;
		while (*(str_ptr + i) != '\0')
		{
			(*(str_ptr + i + 1) == '"') ? (*(str_ptr + i) = '\0') : (*(str_ptr + i) = *(str_ptr + i + 1));
			++i;
		}
	}
	printf("Path of file: %s\n", str); // �������
	frd = fopen((str), "rt");
	if (frd == NULL)   
		return; // chk open file

	while (!feof(frd)) // for EOF
	{
		fgets(str, STR, frd); // get file string
		str_ptr = str;
		i = 0;
		while (*(str_ptr + i) != '\0')
		{
			if (*(str_ptr + i) == '/' && *(str_ptr + i + 1) == '/')
			{ // ������ �� //
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
				while (*(str_ptr + i) != '\0' && *(str_ptr + i) != ';' && *(str_ptr + i) != ' ' && *(str_ptr + i) != ',' && *(str_ptr + i) != '}' && *(str_ptr + i) != ']' && *(str_ptr + i) != '\n')
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
	WORD foregroundColor0; // ���� ����  
	WORD foregroundColor1; // ���� ������������  
	//WORD foregroundColor;  // ���� �������  
	WORD backgroundColor;  // ���� ����  
	WORD textAttribute;	   // ������� ������ - ���� ������� � ���� 

	// �������� ����������� ����������   
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	// ���������� ����� ��������, ������������ � ����  
	foregroundColor0 = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN /*| FOREGROUND_RED*/;
	foregroundColor1 = FOREGROUND_INTENSITY | FOREGROUND_RED;
	backgroundColor = BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;

	int j = 0;
	int value = strlen(num);
	while (num[j] == '-' || (num[j] >= '0'&& num[j] <= '9'))
	{
		++j;
	}
	if (value == j)
	{
		textAttribute = foregroundColor1; //| backgroundColor;
		SetConsoleTextAttribute(hStdout,textAttribute);
		printf("%s", num);
		textAttribute = foregroundColor0;// | backgroundColor;
		SetConsoleTextAttribute(hStdout, textAttribute);
	}
	else
	{
		printf("%s", num);
	}
	return;
}