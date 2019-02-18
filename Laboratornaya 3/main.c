#pragma warning(disable : 4996) // отключение ошибки c4996
#include <stdio.h>
#include <conio.h> // библиотека обслуживающа€ '_getch()' ???
#define YES 1
#define NO 0
int main(void)
{
	// начальное присваивание
	int c;       // текущий символ из потока
	int counter; // количество 'a'
	int flag;    // флажок, по которому мы 
	             //определ€ем наличие буквы а в слове
	// начальные присваивани€
	counter = 0;
	flag = NO;   // изначально обнул€ем флажок
	printf("Please, enter some words:\n");
	// цикл чтоени€ символов из потока, св€занного с клавиатурой
	while ( (c = getchar()) != EOF )
	{
		if (c == 'a' || c == 'A')  // вы€вл€ем наличие буквы а
		{
			flag = YES;
		}
		if (c == ' ' || c == '.' || c == '\n' || c == ',')
		{
			if (flag == YES) // проверка на наличие буквы а в слове
			{
				++counter;   // увеличение счЄтчика на 1
				flag = NO;   // сброс флажка
			}
		}
	}
	printf("Number of words that contains letters 'a' = %d\n", counter);
	printf("\nPress any button to close the window\n");
	_getch(); // ожидание ввода чего либо
	return 0;
}