#pragma warning(disable : 4996) // отключение ошибки c4996
#include <stdio.h>
#include <conio.h>
#define YES 1
#define NO 0
int main(void)
{
	// начальное присваивание
	int c;       // текущий символ из потока
	int counter; // количество 'a'
	int flag; //
	// начальные присваивания
	counter = 0;
	flag = NO;
	printf("Please, enter some words:\n");
	// цикл чтоения символов из потока, связанного с клавиатурой
	while ( (c = getchar()) != EOF )
	{
		if (c == 'a' || c == 'A')
		{
			flag = YES;
		}
		if (c == ' ' || c == '.' || c == '\n' || c == ',') //
		{
			if (flag == YES)
			{
				++counter;
				flag = NO;
			}
		}
	}
	printf("Number of words that contains letters 'a' = %d\n", counter);
	_getch();
	return 0;
}