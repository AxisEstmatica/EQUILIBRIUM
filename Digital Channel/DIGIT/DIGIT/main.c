#pragma warning(disable : 4996) // îòêëþ÷åíèå îøèáêè c4996
#include <stdio.h>
#define YES 1
#define NO 0

#define K 12 // число битов одного символа, ну или как оно там называется

#define STR 10 // длина символв файловой строки
#define LSTR 120 // длина символов бинарной строки

char filestr[STR]; // int or char?
int binstr[LSTR]; // int or char?

void KODER(void); // перегоням в кодовые слова
//void CHANNEL(void); // добавляем ошибки
//void DECODER(void); // перегоняем в кодовые слова
int CONTROL(int i, int j); // вычисление контрольного бита

int main(void)
{
	//int filestr[STR]; // int or char? не понадобится - убрать

	FILE *fp; // потом объединю в функцию "файл"
	fp = fopen("text.txt", "r");
	
	if (fp == NULL) // а это нужно?
	{
		printf("FILE HAS NOT BEEN OPENED");
		return 0;
	}

	fgets(filestr, STR, fp);
	puts(filestr); // uberu
	fclose(fp);

	KODER();

	printf("\n"); // потом уберу
	for (int i = 0, j = 1; i < LSTR; ++i, ++j) // это тоже
	{
		printf("%d", binstr[i]);
		if (j == 12) // uberu
		{
			printf(" %d ", i);
			j = 0;
		}
	}

	//CHANNEL();

	//DECODER();

	return 0;
}

void KODER(void)
{
	//int MTR[K+1][4]; // MATRIX
	int n; // переменная
	int pos; // позиция символа
	char c; // текущий символ
	int j = 0; // позиция бита каждой структуры из 12 символов
	int i; // счётчик

	printf("%c", filestr[0]); // uberu
	printf("%d", filestr[0]); // uberu
	printf("%c\n", filestr[0]); // uberu

	// перегон значений чар в метод Хэмминга

	for (i = 0; (c = filestr[i]) != '\0'; ++i, j = 0)
	{
		printf(" %c ", c); // uberu
		for (n = 0, pos = n + i * K; n < 8; ++n, ++pos, ++j) // в чаре 8 бит, потом уберу n в вычислении pos
		{
			if (j != 0 && j != 1 && j != 3 && j != 7)
			{
				binstr[pos] = (c >> 7 - n) & 1;
			}
			else
			{
				--n;
				binstr[pos] = 0;
			}
		}
		for (j = 0, pos = i * K; j < K; ++j, ++pos)
		{
			if (j == 0 || j == 1 || j == 3 || j == 7)
			{
				binstr[pos] = CONTROL(i, j); // загоняем контрольные биты
			}
		}
	}

	// создание матрицы преобразования uberu
	//
	for (i = 0; i < 4; ++i) // uberu
	{
		//MTR[K][i] = i + 1;
	}

	for (i = 0; i < 4; ++i) // uberu
	{
		for (j = 0; j < K; ++j)
		{
			
		}
	}
	//
	// вычисление контрольных битов
}

int CONTROL(int i, int j)
{
	int LINE[K]; // строка матрицы преобразования
	int z = j; // под вопросом
	int x;
	int t = 0;
	int sum = 0;
	int pos = i * K; // ищем первый элемент символа

	for (x = 0; x < j; ++x)
	{
		LINE[x] = 0;
	}
	x = 1;
	while (z < K)
	{
		if (t == j + 1)
		{
			x = x ^ 1;
			t = 0;
		}
		LINE[z] = x;

		if (x == 1)
		{
			sum = sum + binstr[pos + z];
		}

		++t;
		++z;
	}
	x = sum & 1; // остаток по мод2
	return x;
}