#pragma warning(disable : 4996) // отключение ошибки c4996
#include <stdio.h>
//
#define YES 1
#define NO 0
#define MAXLINE 1000
//
void process_line(char *line_ptr); // объ€вл€ем функцию

int main(void) //
{
	char line[MAXLINE]; //
	char *line_ptr = line; // указатель на начало массива
	//
	printf("Please, enter some words,\nWords that start and end on similar letter will be deleted:\n");
	gets(line);  // считываем строку до конца файла и запихиваем в массив line
	//line_ptr = line; // присваиваем начало массива указателю
	process_line(line_ptr); // выполн€ем функцию над массивом line
	printf("Result:\n");
	puts(line); // выводим массив line
	return 0;
}

void process_line(char *line_ptr) // тело функции
{
	//int *line_ptr = &line[0];
	char c;  // текущий символ
	char prev_c; // предыдущий символ
	int flag; // признак разделени€ слов
	char E; // первый символ
	int i; // позици€ символа
	int post_i; // позици€ символа в финальном варианте
	int j; // позици€ начала слова
	int found; // признак отсутстви€ слова

	// ну понеслаааась
	found = NO;
	flag = NO;
	E = *line_ptr; // присваеваем первый символ, чтобы не потер€ть его
	j = 0;
	prev_c = *line_ptr; // та же причина
	i = 0; // потому что массивы начинаютс€ с нул€
	post_i = -1; // особенноесть for

	// читаем строчки

	do // цикл с постусловием
	{
		c = *(line_ptr+i);
		if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && (c != ' ' && c != '.' && c != ',' && c != '\n' && c != '\0' && c != '\t')) // проверка на не слово
		{
			found = YES; // это не слово
		}
		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0' || c == '\t') // проверка конец слова
		{
			flag = YES; // нашли разделитель
			if ((prev_c - 'A' == E - 'A' || prev_c - 'a' == E - 'a' || prev_c - 'a' == E - 'A' || prev_c - 'A' == E - 'a') && found != YES) // проверка на условие
			{
				if ((E < 'a' || E > 'z') && (E < 'A' || E > 'Z')) // фикс того когда после рандомного знака не буквы сжираютс€ разделители
				{
					++post_i;
					*(line_ptr + post_i) = c; // просто ставим разделитель
				}
			}
			else
			{
				if (*(line_ptr + i-1) == ' ' || *(line_ptr + i - 1) == '.' || *(line_ptr + i - 1) == ',' || *(line_ptr + i - 1) == '\n' || *(line_ptr + i - 1) == '\t') // если предыдущий символ разделитель, то...
				{
					++post_i;
					*(line_ptr+post_i) = c; // просто ставим разделитель
				}
				else
				{
					for (++post_i; j < i; ++j) // перезапись слова в тот-же массив
					{
						*(line_ptr + post_i) = *(line_ptr + j); // присвоение
						++post_i;
					}
					*(line_ptr + post_i) = c; // устанавливаем разделитель между словами
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
	++post_i;
	*(line_ptr + post_i) = '\0';// устанавливаем конец файла
}