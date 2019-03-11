#pragma warning(disable : 4996) // отключение ошибки c4996
#include <stdio.h>
//
#define YES 1
#define NO 0
#define MAXLINE 1000
//
void process_line(char buffer[]); // объ€вл€ем функцию

int main(void) //
{
	char line[MAXLINE]; //
	//
	printf("Please, enter some words,\nWARNING: words that start and end on similar letter will be deleted\n");
	gets(line);  // считываем строку до конца файла и запихиваем в массив line
	process_line(line); // выполн€ем функцию над массивом line
	printf("Result:\n");
	puts(line); // выводим массив line
	return 0;
}

void process_line(char buffer[]) // тело функции
{
	int c;  // текущий символ
	int prev_c; // предыдущий символ
	int flag; // признак разделени€ слов
	int E; // первый символ
	int i; // позици€ символа
	int post_i; // позици€ символа в финальном варианте
	int j; // позици€ начала слова
	int found; // признак отсутстви€ слова

	// ну понеслаааась
	found = NO;
	flag = NO;
	E = buffer[0]; // присваеваем первый символ, чтобы не потер€ть его
	j = 0;
	prev_c = buffer[0]; // та же причина
	i = 0; // потому что массивы начинаютс€ с нул€
	post_i = -1; // особенноесть for

	// читаем строчки

	do // цикл с постусловием
	{
		c = buffer[i];
		if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && (c != ' ' && c != '.' && c != ',' && c != '\n' && c != '\0' && c != '\t')) // проверка на не слово
		{
			found = YES;
		}
		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0' || c == '\t') // проверка конец слова
		{
			flag = YES; // нашли разделитель
			if ((prev_c - 'A' == E - 'A' || prev_c - 'a' == E - 'a' || prev_c - 'a' == E - 'A' || prev_c - 'A' == E - 'a') && found != YES) // проверка на условие
			{
				
			}
			else
			{
				if (buffer[i-1] == ' ' || buffer[i-1] == '.' || buffer[i-1] == ',' || buffer[i-1] == '\n' || buffer[i-1] == '\0' || buffer[i-1] == '\t') // если предыдущий символ разделитель, то...
				{
					++post_i;
					buffer[post_i] = c; // просто ставим разделитель
				}
				else
				{
					for (++post_i; j < i; ++j) // перезапись слова в тот-же массив
					{
						buffer[post_i] = buffer[j]; // присвоение
						++post_i;
					}
					buffer[post_i] = c; // устанавливаем разделитель между словами
				}
			}
			found = NO;

		}
		else
		{
			if (flag == YES) // проверка на прошедший разделитель
			{
				E = c; // первый символ не разделитель
				flag = NO; // обнул€ем флаг
				j = i; // запоминаем место первого символа
			}
			prev_c = c; // запоминаем последний не разделитель
		}
		++i;
	} 
	while (c != '\0'); // цикл работает до конца файла
	buffer[++post_i] = '\0';// устанавливаем конец файла
}