#pragma warning(disable : 4996) // отключение ошибки c4996
//#pragma warning(disable : 4013) // отключение ошибки c4996
//#pragma optimize( "[optimization-list]", {on | off})
//#pragma optimize("agi", off)
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
//#include <unistd.h>  //Для sleep ne rabotayet
//#include <conio.h>
//#include <dir.h>
//#include <stdbool.h>
//#include <>
#define YES 1
#define N 9
#define STR 200

#include <time.h>
void delay(int ms) // аргумент- требуемое время задержки в миллисекундах
{
	int c = clock() + ms;
	while (clock() < c);
}

int i; // counter
//int command; // number of enetred command
char c; // действующий символ

void include(char *filestr); // функция добавления записей
void write(char *filestr, struct student x); // функция записи структуры в
void rewrite(char *filestr, struct student *DATA); // функция перезаписи БД, в принципе только здесь её потерять и можно...
void read(char *filestr, struct student *DATA); // функция чтения информации в массив структур
void counter(char *filestr); // подсчитывает размер базы данных (структур)
void uninclude(char *filestr); // функция удаления записей
//void forget(char *filestr, struct student *DATA)
//void output_abc(); // функция вывода записей
//void search(); // функция поиска записи
void change(char *filestr); // функция редактирования записи

struct student
{
	int  group;		// номер группы
	char name1[20]; // Фамилия
	char name2[20]; // Имя
	char name3[20]; // Отчество
	char disp[150]; // Дисциплины
	int  mark[10];  // Оценка
};

enum my_command
{
	add, // add information
	edit, // edit information
	delete,
	output_name,
	output_mark,
	output_grant,
	output_repeat,
	otput_expel,
	end,
	close // end of enum
};

char m_comToChar[N][14] = { "add","edit","delete","output name","output mark","output grant","output repeat","output expel","end"};

int main(void) // b.f.
{
	//FILE *frd;
	int command;
	//printf("Data base");
	//char str[STR];
	char *filestr = (char*)malloc(151*sizeof(char));
loop:
	//filestr = (char*)malloc(sizeof(char));
	//delay(2500); // остановка на какое-то время
	//sleep(5); // ne rabotayet
	system("cls"); // ochisheniye consoli
	printf("Data base");
	//frd = fopen("base.txt", "rt"); // открываем исходный файл
	printf("\nChoose desirable action:\nAviable commands:\n");
	for (i = 0; i < N; ++i)
		printf(" - %s\n", m_comToChar[i]);
	printf("Input: ");
	{ // ввод строки в динамический массив
		i = 0;
		while ((c = getchar()) != '\n')
		{
			*(filestr + i) = c;
			//filestr = (char*)realloc(filestr, (2 + (i)) * sizeof(char));
			++i;
		}
		*(filestr + i) = '\0';
		//printf("filestr: %s\n", filestr);
	}
	for (i = add, command = -1; i < close; ++i)
		if (strcmp(filestr, m_comToChar[i]) == 0)
		{
			command = i;
			//printf("Entered string: \"%s\" i = %d\n", m_comToChar[command], i);
		}
	if (command >= 0 && command < 10)
		printf("Entered command: \"%s\"\n", m_comToChar[command]);
	else
		printf("Entered command: \"%s\" corrupted\n", filestr);
	switch (command)
	{
	case add: printf("Completed\n");
		include(filestr);
		printf("Completed!\n");
		delay(2500); // остановка на какое-то время
		break;
	case edit: printf("Completed\n");
		change(filestr);
		printf("Completed!\n");
		delay(2500); // остановка на какое-то время
		break;
	case delete: printf("Completed\n");
		uninclude(filestr);
		printf("Completed!\n");
		delay(2500); // остановка на какое-то время
		break;
	case output_name: printf("Work in progress\n");
		//delay(2500); // остановка на какое-то время
		break;
	case output_mark: printf("Work in progress\n");
		//delay(2500); // остановка на какое-то время
		break;
	case output_grant: printf("Work in progress\n");
		//delay(2500); // остановка на какое-то время
		break;
	case output_repeat: printf("Work in progress\n");
		//delay(2500); // остановка на какое-то время
		break;
	case otput_expel: printf("Work in progress\n");
		//delay(2500); // остановка на какое-то время
		break;
	case end: printf("\nShutdown program\n");
		free(filestr);
		return 0;
	default:
		printf("Not aviable command\n");
		delay(2500); // остановка на какое-то время
		break;
	}
	//free(filestr);
	goto loop;
}

void include(char *filestr)
{
	i = 0;
	int ctr; // counter
	int end;
	struct student x;
	printf("Enter student's group: ");
	scanf("%d", &x.group);
	gets(filestr); // особенность компилятора
	printf("Enter student's surname: ");
	//scanf("%s", x.name1);
	//gets_s(x.name1);
	//gets(x.name1);
	gets(x.name1);
	printf("Enter student's name: ");
	gets(x.name2);
	printf("Enter student's middle name: ");
	gets(x.name3);
	//
	printf("Enter number of disciplines: ");
	scanf("%d", &end);
	gets(filestr); // особенность компилятора
	for (ctr = 0; ctr < end; )
	{
		printf("Enter discipline %d: ", ctr + 1);
		{ // ввод строки в динамический массив
			//c = getchar(); // особенность компилятора
			while ((c = getchar()) != '\n')
			{
				*(filestr + i) = c;
				//filestr = (char*)realloc(filestr, (2 + (i)) * sizeof(char));
				++i;
			}
			*(filestr + i) = '|';
			//filestr = (char*)realloc(filestr, (2 + (i)) * sizeof(char));
			++i;
			//printf("filestr: %s\n", filestr);
		}
		//gets(x.disp);
		//printf("Enter mark %d : ", ctr + 1);
		//scanf("%d", &x.mark[ctr]);
		x.mark[ctr] = 1;
		++ctr;
		if (ctr == end)
		{
			//filestr = (char*)realloc(filestr, (i) * sizeof(char));
			*(filestr + i - 1) = '\0';
		}
	}
	printf("filestr: %s\n", filestr);
	//x.disp[150] = strdup(filestr);
	strcpy(x.disp, filestr);
	printf("disp: %s\n", x.disp);
	write(filestr, x);
	printf("Student had been added!\n");
	//return;
}

void write(char *filestr, struct student x)
{
	int cnt = 0; // counter
	FILE *fwr;
	fwr = fopen("base.txt", "at");
	//
	strcpy(filestr, x.disp);
	fprintf(fwr, "Group num %d\nStudent: %s\n         %s\n         %s\n", x.group, x.name1, x.name2, x.name3);
	fprintf(fwr, "Mark | Discipline\n");
	for (i = 0; *(filestr + i) != '\0'; ++cnt)
	{
		fprintf(fwr, " %d ", x.mark[cnt]);
		*(filestr + i) == '|' ? ++i : NULL;
		for ( ; *(filestr + i) != '\0' && *(filestr + i) != '|'; ++i)
			fprintf(fwr, "%c", *(filestr + i));
		fprintf(fwr, "\n");
	}
	fprintf(fwr, "\n");
	//c = getchar(); // особенность компилятора
	fclose(fwr);
	//return;
}

void rewrite(char *filestr, struct student *DATA)
{
	FILE *fwr;
	//struct student x; // требуется для...
	fwr = fopen("base.txt", "wt");
	fclose(fwr);
	for (int X = 0;X < _msize(DATA) / sizeof(struct student); ++X)
		write(filestr, DATA[X]);
}

void change(char *filestr)
{
	int X; // x - dimension (axis)
	struct student x; // требуется для хранения введённых параметров и дальнейшего сравнения с БД
	int cnt; // counter of discioline
	//filestr = (char*)realloc(filestr, 151 * sizeof(char));
	counter(filestr);
	struct student* DATA = (struct student*)malloc(i * sizeof(struct student));
	read(filestr, DATA); // получаем динамический массив структур всех студентов
	printf("Enter student's surname: ");
	gets(x.name1);
	printf("Enter student's name: ");
	gets(x.name2);
	printf("Enter student's middle name: ");
	gets(x.name3);
	for (X = 0; X < _msize(DATA) / sizeof(struct student); ++X) // search
	{
		if (strcmp(DATA[X].name1, x.name1) == 0)
			if (strcmp(DATA[X].name2, x.name2) == 0)
				if (strcmp(DATA[X].name3, x.name3) == 0)
					break;
	}
	if (X == _msize(DATA) / sizeof(struct student)) // ne nashli studenta
	{
		// nado bi vijti
		printf("Student was not found\n");
		goto away; // extra exit
	}
	printf("X = %d\n", X);
	i = 0;
	cnt = 0;
	//while (DATA[X].disp[i]!='|' && DATA[X].disp[i] != '\0')
	while (DATA[X].disp[i] != '\0')
	{
		//if (DATA[X].disp[i] == '\0')
			//break;
		printf("Enter ");
		while (DATA[X].disp[i] != '|' && DATA[X].disp[i] != '\0')
		{
			printf("%c", DATA[X].disp[i]);
			++i;
		}
		printf(" mark: ");
		scanf("%d",&DATA[X].mark[cnt]);
		if (DATA[X].mark[cnt]<2 || DATA[X].mark[cnt] >5)
		{
			DATA[X].mark[cnt] = 1; // bez ponyatia chto delat'
			printf("Mark corrupted\n");// po horoshemu nado bi zaprosit' reenter no ne znauy...
		}
		if (DATA[X].disp[i] != '\0')
			++i;
		++cnt;
	}
	c = getchar(); // особенность компилятора (steck\n)
	/*
	for (cnt = 0; cnt < 5; cnt++)
		printf("%d\n", DATA[X].mark[cnt]);
	puts(DATA[X].disp);
	*/

	rewrite(filestr,DATA); // serost' : perezapis' v obshem
	/*
	for (X = 0; X < _msize(DATA) / sizeof(struct student); ++X) // rewrite
	{
		write(char *filestr, struct student x);
	}
	/*int X = 2;
	printf("%d\n", DATA[X].group);
	puts(DATA[X].name1);
	puts(DATA[X].name2);
	puts(DATA[X].name3);
	for (cnt = 0; cnt < 3; cnt++)
		printf("%d\n", DATA[X].mark[cnt]);
	puts(DATA[X].disp);
	X = 3;
	printf("%d\n", DATA[X].group);
	puts(DATA[X].name1);
	puts(DATA[X].name2);
	puts(DATA[X].name3);
	for (cnt = 0; cnt < 3; cnt++)
		printf("%d\n", DATA[X].mark[cnt]);
	puts(DATA[X].disp);
	*/
	//printf("%d", _msize(filestr) / sizeof(filestr[0]));
	//printf("%d ", sizeof(struct student));
	//printf("%d", _msize(DATA) / sizeof(struct student));

	// nujna zapis' obratno
	printf("Marks were edited!\n");
away: // extrenniy exit
	free(DATA);

	return;
}

void counter(char *filestr) // count struct massive
{
	FILE *frd = fopen("base.txt", "rt");
	i = 0;
	//c = 5;
	//filestr = "Group";
	//puts(filestr);
	while (!feof(frd))
	{
		fgets(filestr, 6, frd);
		//puts(filestr);
		if (strcmp(filestr, "\n") == 0)
			fgets(filestr, 6, frd);
		//puts(filestr);
		if (strcmp(filestr, "Group") == 0)
			++i;
		while ((c = fgetc(frd)) != '\n')
			if (c == EOF)
				break;
		//printf("i = %d\n", i);
	}
	//printf("\ni = %d\n\n", i);
	fclose(frd);
}

void read(char *filestr, struct student *DATA)
{
	int X = 0; // dimension
	int cnt;
	FILE *frd = fopen("base.txt", "rt");
		{ // group
			i = 0;
			while ((c = fgetc(frd)) != '\n')
			{
				laplas: // laplas's demon
				*(filestr + i) = c;
				++i;
			}
			--i;
			DATA[X].group = 0;
			for (cnt = 1; *(filestr + i) != ' '; i--, cnt *= 10)
				DATA[X].group += cnt * (*(filestr + i) - '0');
		}
		for (; (c = fgetc(frd)) != ':'; ) {}
		c = fgetc(frd);
		i = 0;
		while ((c = fgetc(frd)) != '\n') // name1
		{
			*(filestr + i) = c;
			++i;
		}
		*(filestr + i) = '\0';
		strcpy(DATA[X].name1, filestr);
		for (i=0; i<9; c = fgetc(frd), ++i) {}
		i = 0;
		while ((c = fgetc(frd)) != '\n') // name2
		{
			*(filestr + i) = c;
			++i;
		}
		*(filestr + i) = '\0';
		strcpy(DATA[X].name2, filestr);
		for (i = 0; i < 9; c = fgetc(frd), ++i) {}
		i = 0;
		while ((c = fgetc(frd)) != '\n') // name3
		{
			*(filestr + i) = c;
			++i;
		}
		*(filestr + i) = '\0';
		strcpy(DATA[X].name3, filestr);
		i = 0; // mark and discipline
		cnt = i;
		c = fgetc(frd);
		for (; (c = fgetc(frd)) != '\n'; ) {}
		c = fgetc(frd);
		while (c != '\n' && (c != EOF))
		{
			c = fgetc(frd);
			DATA[X].mark[cnt] = c - '0';
			c = fgetc(frd);
			//printf("X = %d\n", X);
			while ((c = fgetc(frd)) != '\n' && (c != EOF)) // 
			{
				*(filestr + i) = c;
				++i;
			}
			if ((c = fgetc(frd)) == '\n')
			{
				*(filestr + i) = '\0'; // отправная точка
				break;
			}
			*(filestr + i++) = '|';
			++cnt;
		}
		//printf("X = %d\n", X);
		
		strcpy(DATA[X].disp, filestr); // vajno
		/*
		printf("%d\n", DATA[X].group);
		puts(DATA[X].name1);
		puts(DATA[X].name2);
		puts(DATA[X].name3);
		for (cnt = 0; cnt < 3; cnt++)
		printf("%d\n", DATA[X].mark[cnt]);
		puts(DATA[X].disp);
		*/
		if ((c = fgetc(frd)) == 'G')
		{
			++X;
			//DATA = (struct student*)realloc(DATA, (X + 1) * sizeof(struct student));
			i = 0;
			goto laplas;
		}
		//printf("%d", _msize(DATA) / sizeof(struct student));
		//printf("jkahsfh;ask");
		//printf("\n%d\n\n", _msize(DATA) / sizeof(struct student)); // zakrito poslednim
		/*
		for (X = 0; X < _msize(DATA) / sizeof(struct student); X++)
		{
			printf("%d\n", DATA[X].group);
			puts(DATA[X].name1);
			puts(DATA[X].name2);
			puts(DATA[X].name3);
			for (cnt = 0; cnt < 3; cnt++)
				printf("%d\n", DATA[X].mark[cnt]);
			puts(DATA[X].disp);
		}*/
	fclose(frd);
}

void uninclude(char *filestr)
{
	int X; // x - dimension (axis)
	struct student x; // требуется для хранения введённых параметров и дальнейшего сравнения с БД
	int cnt; // counter of delete element
	//filestr = (char*)realloc(filestr, 151 * sizeof(char));
	counter(filestr);
	struct student* DATA = (struct student*)malloc(i * sizeof(struct student));
	read(filestr, DATA); // получаем динамический массив структур всех студентов
	printf("Enter student's surname: ");
	gets(x.name1);
	printf("Enter student's name: ");
	gets(x.name2);
	printf("Enter student's middle name: ");
	gets(x.name3);
	for (X = 0; X < _msize(DATA) / sizeof(struct student); ++X) // search
	{
		if (strcmp(DATA[X].name1, x.name1) == 0)
			if (strcmp(DATA[X].name2, x.name2) == 0)
				if (strcmp(DATA[X].name3, x.name3) == 0)
					break;
	}
	if (X == _msize(DATA) / sizeof(struct student)) // ne nashli studenta
	{
		// nado bi vijti
		printf("Student was not found\n");
		goto away_del; // extra exit
	}
	printf("X = %d\n", X);

	cnt = X;
	FILE *fwr;
	//struct student x; // требуется для...
	fwr = fopen("base.txt", "wt");
	fclose(fwr);
	for (int X = 0; X < _msize(DATA) / sizeof(struct student); ++X)
		if (X != cnt)
			write(filestr, DATA[X]);

	printf("Student had been deleted!\n");
away_del: // extrenniy exit
	free(DATA);
	return;
}