#pragma warning(disable : 4996) // отключение ошибки c4996
#include <stdio.h>

#define YES 1
#define NO 0
#define N 10 // потому что цифр будет 10

void process_MAS(int buffer[]); // рабочая функция
int MAX(int buffer[]); // ищем наибольшее значение
int MIN(int buffer[]); // ищем наименьшее значение

int main(void)
{
	int MAS[N]; // объявляем массив для целых чисел
	int i;
	printf("Enter 10 integer numbers\n");

	for (i = 0; i < N; ++i) // задаём значения массива
	{
		printf("Number %d:", i+1); // работает...
			scanf("%d", &MAS[i]);
	}

	process_MAS (MAS); // обнуляем значения между мин и макс
	
	printf("Result:");
	for (i = 0; i < N; ++i) // выводим массив
	{
		printf(" %d", MAS[i]);
	}

	return 0; // radyemsya
}

void process_MAS(int buffer[]) // описываем нашу функцию
{
	int i;
	int max; // максимальный элемент
	int min; // минимальный элемент
	int n_max; // номер наибольшего элемента
	int n_min; // номер наименьшего элемента
	int flag_max; // флажок НБ значения
	int flag_min; // флажок НМ значения
	flag_max = NO;
	flag_min = NO;
	
	max = MAX(buffer);
	min = MIN(buffer);

	if (max == min) // защита от бесполезных действий
	{
		i = 10;
	}
	else
	{
		i = 0;
	}

	while (i < N)
	{
		if (buffer[i] == max) // находим позицию НБ значения
		{
			flag_max = YES;
			n_max = i;
		}
		if (buffer[i] == min) // находим позицию НМ значения
		{
			flag_min = YES;
			n_min = i;
		}
		if (flag_max == YES && flag_min == YES)
		{
			if (n_max < n_min)
			{
				// можно добавить обратное else и будет обнулять от НБ до НМ
			}
			else
			{
				for (++n_min; n_min < n_max; ++n_min) // обнуляем от НМ до НБ
				{
					buffer[n_min] = 0;
				}
			}
			flag_max = NO;
			flag_min = NO;
			--i; // чтобы не упустили НБ или НМ значение
		}

		++i;
	}
}

int MAX(int buffer[]) // ищем НБ значение
{
	int i;
	int max;
	max = buffer[0];
	for (i = 1; i < N; ++i)
	{
		if (buffer[i] > max) // если больше, то больше
		{
			max = buffer[i];
		}
	}
	return max; // возвращаем НБ значение
}

int MIN(int buffer[]) // ищем НМ значение
{
	int i;
	int min;
	min = buffer[0];
	for (i = 1; i < N; ++i)
	{
		if (buffer[i] < min) // если мньше, то меньше
		{
			min = buffer[i];
		}
	}
	return min; // возвращаем НМ значение
}