#pragma warning(disable : 4996)
#include <stdio.h>
#include <time.h> 
#include <conio.h> 
#include <stdlib.h> 
#include <math.h>

#define K 13 // число битов одного кодового слова

#define STR 20 // длина символв файловой строки
#define LSTR 260 // длина символов бинарной строк
char filestr[STR]; // int or char?
char binstr[LSTR]; // int or char?

void KODER(void); // перегоням в кодовые слова
void CHANNEL(void); // создаем ошибки в символах
void DECODER(void); // исправляем ошибки в символах

int CONTROL(int i, int j); // вычисление контрольного бита
int DECODLOG(int i); // вычисление позиции неправильного бита

int main(void)
{
	//int filestr[STR]; // int or char? не понадобится - убрать

	FILE *fp; // потом объединю в функцию "файл", не-а не буду
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
		if (j == K) // uberu
		{
			printf(" %d ", i);
			j = 0;
		}
	}

	printf("\n");

	CHANNEL();
	printf("\n");
	for (int i = 0, j = 1; i < LSTR; ++i, ++j) // это тоже
	{
		printf("%d", binstr[i]);
		if (j == K) // uberu
		{
			printf(" %d ", i);
			j = 0;
		}
	}

	printf("\n");

	DECODER();
	printf("\n");
	for (int i = 0, j = 1; i < LSTR; ++i, ++j) // это тоже
	{
		printf("%d", binstr[i]);
		if (j == K) // uberu
		{
			printf(" %d ", i);
			j = 0;
		}
	}

	FILE *fn; // выводим результат
	fn = fopen("restext.txt", "w");

	fputs(filestr, fn);
	fclose(fn);

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
		for (j = 0, pos = i * K; j < K - 1; ++j, ++pos) // -1
		{
			if (j == 0 || j == 1 || j == 3 || j == 7)
			{
				binstr[pos] = CONTROL(i, j); // загоняем контрольные биты
			}
		}
		for (j = 0, pos = i * K; j < K - 1; ++j)
		{
			binstr[pos + K - 1] = binstr[pos + K - 1] + binstr[pos + j];
		}
		binstr[pos + K - 1] = binstr[pos + K - 1] & 1; // нечётные 1
	}

}

int CONTROL(int i, int j)
{
	int LINE[K - 1]; // строка матрицы преобразования // -1
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
	while (z < K - 1) // -1
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

void CHANNEL(void)
{
	int i; // изменённые биты
	int y = 0; // переменная
	int z = 1; // номер кодового слова
	int j = 0; // кратность ошибки

	FILE *fl; // для лог файла канала
	fl = fopen("channellog.txt", "w");
	fprintf(fl, "1, 2, 4, 8 биты - контрольные биты каждого кодового слова.\n");
	fputs(filestr, fl);
	fprintf(fl, " - символы, считанные из файла text.txt. Далее строка кодовых слов, созданная функцией KODER (пробелы для различия, в самом массиве их нет):\n");

	for (i = 0; i < LSTR; ++i)
	{
		if (i%K == 0 && i != 0)
		{
			fprintf(fl, "  ");
		}
		fprintf(fl, "%d", binstr[i]);
	}

	srand(time(NULL));

	fprintf(fl, "\nРезультат работы функции CHANNEL - изменённые биты (отсчёт от 1):\nРезультат:\n"); //  
	for (i = -1, i = i + 1 + rand() % 30; i < LSTR; i = i + 1 + rand() % 30) // добавление помех
	{
		for (; y <= i; ++y)
		{
			if (y%K == 0 && y != 0)
			{
				if (j == 0)
				{
					fprintf(fl, "нет ");
				}
				fprintf(fl, "- помехи кодового слова №%d (кратность ошибки: %d)\n", z, j);
				++z;
				j = 0;
			}
		}
		fprintf(fl, "%d ", i + 1); //
		++j;
		binstr[i] = binstr[i] ^ 1;
	}
	fprintf(fl, "- помехи кодового слова №%d (кратность ошибки: %d)\nЕсли оставшиеся кодовые слова не перечислены, то ошибок в них нет.", z, j);

	fprintf(fl, "\nРезультирующая строка кодовых слов, после работы функции CHANNEL (пробелы добавлены для визуальной распознаваемости кодовых слов):\n");
	for (i = 0; i < LSTR; ++i)
	{
		if (i % K == 0 && i != 0)
		{
			fprintf(fl, "  ");
		}
		fprintf(fl, "%d", binstr[i]);
	}
	fclose(fl);
}


void DECODER(void)
{
	int n; // переменная, я вот буду использовать её в своих целях AXIS
	int pos = 0; // позиция символа
	char c; // текущий символ
	int j = 0; // позиция бита каждой структуры из 12 символов
	int i; // счётчик
	int num; //позиция неправильного бита в символе
	int schet = 0; //счетчик не контрольных битов
	int rem_bin = 0; //запоминаем 13 бит символа
	int error[STR] = { 0 }; //наличие 2ой ошибки

	FILE *fz; // для лог файла декодера
	fz = fopen("decoderlog.txt", "w");
	fprintf(fz, "1, 2, 4, 8 биты - контрольные биты каждого кодового слова.\nОшибки кратности более двух будут распознаны неверно.\nСимвол с двойной ошибкой будет заменён на '@'.");
	fprintf(fz, "\nРезультирующая строка кодовых слов, после работы функции CHANNEL (пробелы добавлены для визуальной распознаваемости кодовых слов):\n");
	for (i = 0; i < LSTR; ++i)
	{
		if (i % K == 0 && i != 0)
		{
			fprintf(fz, "  ");
		}
		fprintf(fz, "%d", binstr[i]);
	}

	fprintf(fz, "\nРезультат работы функции DECODER - восстановление, где возможно, испорченных битов (отсчёт от 1):\nРезультат:");
	//fputs(filestr, fz);

	printf(" \n ");
	for (i = 0, n = 1; (c = filestr[i]) != '\0'; ++i)
	{
		rem_bin = 0; // обнуляем с каждым новым элементом

		for (j = 0, pos = i * K; j < K - 1; ++j)
		{
			rem_bin = rem_bin + binstr[pos + j]; //считаем новый бит четности
		}

		rem_bin = rem_bin & 1; // нечётные 1, четные 0

		num = DECODLOG(i);
		printf("( %d ", rem_bin);
		printf(" %d )", num);

		if (rem_bin == binstr[pos + K - 1] && num >= 0) //2 ошибки (то есть четное колличество ошибок, но они есть)
		{
			error[i] = 1; //чтобы потом исправить ошибку в символе с номером i
			fprintf(fz, "\nВ кодовом слове № %d обнаружена двойная ошибка.", n);
			++n;
		}

		else if (num >= 0 && num < 12) // 1 ошибка 
		{
			binstr[i * K + num] ^= 1; //неправильный бит меняем на правильный
			fprintf(fz, "\nВ кодовом слове № %d обнаружена однократная ошибка. Исправленный символ - %d.", n, i*K + num + 1);
			++n;
		}
		if (n == i + 1)
		{
			fprintf(fz, "\nВ кодовом слове № %d ошибка не обнаружена.", n);
			++n;
		}
	}

	printf(" \n ");

	for (i = 0; (c = filestr[i]) != '\0'; ++i, j = 0)
	{
		if (error[i] == 1) // указатель на то, что в слове 2 ошибки
		{
			filestr[i] = '@'; //запоминаем символ в исходник
			printf(" %c ", filestr[i]);
			continue;
		}

		schet = 0; // при новом символе обнуляем счетчик НЕ контрольных битов
		c = 0; // обнуляем код текущего символа, чтобы записать код нового

		for (j = 0, pos = i * K; j < K - 1; ++j, ++pos) // -1
		{
			if (j != 0 && j != 1 && j != 3 && j != 7)
			{
				c = c + pow(2, (7 - schet))*binstr[pos]; //переводим код символа из 2СС в 10СС
				schet++; //встретился НЕ контрольный бит
			}
		}

		filestr[i] = c; //запоминаем символ в исходник
		printf(" %c ", filestr[i]);
	}

	fprintf(fz, "\nСледующие символы не отображаются, т.к. это конец строки, иными словами любые данные за символом № %d не несут какую-либо информацию.\nРезультирующая строка кодовых слов, после работы функции DECODER (пробелы добавлены для визуальной распознаваемости кодовых слов):\n", n - 1);
	for (i = 0; i < LSTR; ++i)
	{
		if (i % K == 0 && i != 0)
		{
			fprintf(fz, "  ");
		}
		fprintf(fz, "%d", binstr[i]);
	}
	fprintf(fz, "\nРезультат:");
	fputs(filestr, fz);
	fclose(fz);
}

int DECODLOG(int i)

{
	int schet = 0; // счетчик разрядов
	int pos = 0; //позиция символа
	int j = 0; //номер бита в символе
	int  num = 0; //номер плохого бита ---> то что нужно <---
	int cret = 3; //счетчик битов равный колличеству контрольных битов (4 контрольных, т.к. в одном символе только 8 бит)	

	for (j = 0, pos = i * K; j < 8; ++j, ++pos)
	{

		if (j == 0 || j == 1 || j == 3 || j == 7) //определение матрицы синдромов
		{
			schet *= 10; //ведем подсчет разрядов
			schet += CONTROL(i, j); //разряды сложенные (справа налево) в двузначное число дадут номер неправильного элемента!!!
		}

		if (j == 7)//поиск неправильного разряда после просмотра последнего контрольного бита
		{
			while (schet) //вычисление позиции неправильного бита в символе
						  // считаем задом наперед, т.к. складывали разряды слева направо
			{
				num += pow(2, cret)*(schet % 10);
				schet = schet / 10;
				cret--;
			}

			return (num - 1); //т.к. счет в строке от 0, а не от 1

		}
	}
}