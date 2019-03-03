//#pragma warning(disable : 4996) // отключение ошибки c4996
#include <stdio.h>
//
#define YES 1
#define NO 0
#define MAXLINE 1000
//
void process_line(char buffer[]); //

int main(void) //
{
	char line[MAXLINE]; //
	//
	printf("Please, enter some words,\nWARNING: words that start and end on similar letter will be deleted\n");
	gets(line);  //
	process_line(line); //
	printf("Result:\n");
	puts(line); //
	return 0;
}

void process_line(char buffer[]) //
{
	int c;  // текущий символ
	int prev_c; // предыдущий символ
	int flag; // признак разделения слов
	int C; // первый символ
	int i; // позиция символа
	int post_i; // позиция символа в финальном варианте
	int j; // позиция начала слова
	int found; // признак отсутствия слова

	// ну понеслаааась
	found = NO;
	flag = NO;
	C = buffer[0]; // присваеваем первый символ, чтобы не потерять его
	j = 0;
	prev_c = buffer[0]; // та же причина
	i = 0; // потому что массивы начинаются с нуля
	post_i = 0; // та же причина

	// читаем строчки

	do // цикл с постусловием
	{
		c = buffer[i];
		if ((c < 'a' && c < 'z' || c < 'A' && c < 'Z') && (c != ' ' && c != '.' && c != ',' && c != '\n' && c != '\0')) // проверка на не слово
		{
			found = YES;
		}
		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0') //
		{
			flag = YES;
			if (prev_c == C && found != YES) //
			{
				
			}
			else
			{
				for (; j < i; ++j) //
				{
					buffer[post_i] = buffer[j]; //
					++post_i;
				}
				buffer[post_i] = c; //
				++post_i;
			}
			found = NO;

		}
		else
		{
			if (flag == YES) //
			{
				C = c; //
				flag = NO; //
				j = i; //
			}
			prev_c = c; //
		}
		++i;

	} while (c != '\0'); //
	buffer[post_i] = '\0';// очищение строки от остаточных символов
}
