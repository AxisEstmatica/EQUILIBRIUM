#pragma warning(disable : 4996) // отключение ошибки c4996
#include <stdio.h>
#include <malloc.h>
#define YES 1
#define NO 0
#define STR 1024

int i = 0; // счЄтчик
int value = 0; // объЄм массива
char c; // очередной символ

#define MASSIVE 2

void shift(int *ptr, int sme); // shift(указатель на н.массива, сдвиг) || сдвиг влево до размера

int main(void)
{
#if MASSIVE == 0 // не работает
	printf("Trying reverse\n");
	srand(time(NULL));
	int MAS[50];

	for (i = 0; i < 50; i++) // zada'yom massiv
	{
		MAS[i] = -200 + rand() % 400;
		printf("%5d", MAS[i]);
	}
	printf("\n\n");
	reverse(50, 5);
	for (i = 0; i < 50; i++) // zada'yom massiv
	{
		printf("%5d", MAS[i]);
	}
	printf("\n");
	printf("END REVERSE\n");
#elif MASSIVE == 1 // сдвиг влево работает так себе, не больше исходного массива
	// да и не нужно мне это сейчас
	int sme;
	printf("Trying shift\n");
	srand(time(NULL));
	int *MAS;
	MAS = (int*)malloc(50 * sizeof(int));
	if (MAS == NULL)
	{
		printf("\nMAS is NULL\n");
		return 0;
	}
	else
		printf("\nMAS IS OK\n");

	for (i = 0; i < 50; i++) // zada'yom massiv
	{
		MAS[i] = -200 + rand() % 400;
		printf("%5d", MAS[i]);
	}
	printf("\n");
	printf("Please enter needed shift: ");
	scanf("%d", &sme); // int* pintarr = new int [10];
	printf("THX"); // int cnt = _msize(pintarr)/sizeof(pintarr[0]);
	value = _msize(MAS)/sizeof(MAS[0]);
	shift(&MAS[0], sme);

	if (MAS == NULL)
	{
		printf("\nMAS is NULL\n");
		return 0;
	}
	else
		printf("\nMAS IS OK\n");

	value = _msize(MAS) / sizeof(MAS[0]);
	//printf("value = %d\n", value);
	//printf("m = %d\n", MAS[0]);
	for (i = 0; i < value; i++) // zada'yom massiv
	{
		printf("%5d", MAS[i]);
	}
	printf("\n");
	printf("END SHIFT\n");
	free(MAS);
#endif

	// program start

	//char *filestr_ptr; // указатель на filestr
	FILE *frd;
	printf("\nPlease enter address of file: ");
	char *filestr = (char*)malloc(sizeof(char));
	{ // ввод строки в динамический массив
		i = 0;
		while ((c = getchar()) != '\n')
		{
			*(filestr + i) = c;
			filestr = (char*)realloc(filestr, (2 + (i++)) * sizeof(char));
		}
		*(filestr + i) = '\0';
		puts(filestr);
		printf("%s\n", filestr);
	}
	if (*filestr == '"') // удаление коввычек
	{
		i = 0;
		while (*(filestr + i) != '\0')
		{
			(*(filestr + i + 1) == '"') ? (*(filestr + i) = '\0') : (*(filestr + i) = *(filestr + i + 1));
			++i;
		}
		//filestr = (char*)realloc(filestr, i * sizeof(char));
	}
	puts(filestr);

	frd = fopen((filestr), "rt"); // открываем исходный файл
	if (frd == NULL) // проверка на открытие файлов
	{
		printf("FILE HAS NOT BEEN OPENED");
		free(filestr);
		exit(1);
	}
	
	fclose(frd);
	free(filestr);
	return 0;
}

void shift(int *ptr, int sme) // функци€ смещени€ стека, создание
							  //пустых нулевых €чеек слева\либо их удаление
{
	i = 0;
	if (sme == 0)
		return;
	sme > 0 ? i = 1 :  NULL;
	value = _msize(ptr) / sizeof(*ptr);
	if (i == 1)
	{
		ptr = realloc(ptr, (value + sme) * sizeof(*ptr)); // выделение доп пам€ти

		for (i = value; i > 0; i--, value--) // сдвиг старых элементов
			*(ptr + value + sme - 1) = *(ptr + value-1); 
		for (i = 0; i < sme; i++) // обнуление новых
			*(ptr + i) = 0;
	}
	else
	{
		sme = -sme;
		if (sme >= value)
		{
			sme = value;
			free(ptr);
			return;
		}
		for (i = 0; i < value - sme; i++) // сдвиг старых элементов
			*(ptr + i) = *(ptr + i + sme);
		//for (i = 0; i < value; i++) // zada'yom massiv
		//	printf("%5d", *(ptr + i));
		printf("\n");
		i = *ptr;
		*ptr = (int*) realloc(ptr, (value - sme) * sizeof(*ptr)); // перераспределение пам€ти
		*ptr = i;
	}
	return;
}

//int i;