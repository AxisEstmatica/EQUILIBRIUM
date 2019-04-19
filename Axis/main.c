#include <stdio.h>

#define MAXLINE 1000

int main(void) //
{
	char line[MAXLINE];
	char WORD[MAXLINE];
	int c;
	int i;
	int j; // nachalo
	int k;
	int counter;
	int max;
	int prev_c;
	int max2;
	int cnt;

	i = 0;
	prev_c = ' ';
	max = 0;
	counter = 0;
	j = 0;
	cnt = 0;
	max2 = 0;
	
	printf("Please, enter some words,\nWARNING: words that start and end on similar letter will be deleted\n");
	gets(line);  // считываем строку до конца файла и запихиваем в массив line
	
	do
	{
		c = line[i];
		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0' || c == '\t')
		{
			cnt = i + 1 - j;
			if (cnt > max2)
			if (counter > max)
			{
				max = counter;
				max2 = cnt;
				for (k = 0;j != i; ++j, ++k)
				{
					WORD[k] = line[j];
				}
				WORD[k] = '\0';
				cnt = 0;
			}
			counter = 0;
		}
		if (c >= 'A' && c <= 'Z')
		{
			++counter;
		}
		if (prev_c == ' ' || prev_c == '.' || prev_c == ',' || prev_c == '\n' || prev_c == '\t')
		{
			j = i;
		}
		prev_c = c;
		++i;
	}
	while (c != '\0');

	printf("Result:\n");
	puts(WORD); // выводим массив line
	getch();
	getch();
	return 0;
}