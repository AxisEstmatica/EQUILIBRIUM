#pragma warning(disable : 4996) // отключение ошибки c4996
#include <stdio.h>
#include <conio.h> // библиотека обслуживающая '_getch()' ???
#define YES 1
#define NO 0
int main(void)
{
	// начальное присваивание
	int c;       // текущий символ из потока
	int counter; // количество 'a'
	int flag;    // флажок, по которому мы 
	             //определяем наличие буквы а в слове
	// начальные присваивания
	counter = 0;
	flag = NO;   // изначально обнуляем флажок
	printf("Please, enter some words:\n");
	// цикл чтоения символов из потока, связанного с клавиатурой
	while ( (c = getchar()) != EOF )
	{
		if (c == 'a' || c == 'A')  // выявляем наличие буквы а
		{
			flag = YES;
		}
		if (c == ' ' || c == '.' || c == '\n' || c == ',')
		{
			if (flag == YES) // проверка на наличие буквы а в слове
			{
				++counter;   // увеличение счётчика на 1
				flag = NO;   // сброс флажка
			}
		}
	}
	printf("Number of words that contains letters 'a' = %d\n", counter);
	printf("\nPress any button to close the window\n");
	_getch(); // ожидание ввода чего либо
	return 0;
}
