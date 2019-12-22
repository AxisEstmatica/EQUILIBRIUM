#pragma warning(disable : 4996) // отключение ошибки c4996
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define YES 1
#define NO 0
#define N 9
#define STR 200
#define OTS 9 // отступ

void include(char *filestr); // функция добавления записей
void write(char *filestr, struct student x); // функция записи структуры в
void rewrite(char *filestr, struct student *DATA); // функция перезаписи БД, в принципе только здесь её потерять и можно...
void read(char *filestr, struct student *DATA); // функция чтения информации в массив структур
int counter(char *filestr); // подсчитывает размер базы данных (структур)
void uninclude(char *filestr); // функция удаления записей
void abc(char *filestr); // функция вывода студентов в алфавитном порядке
void out_grant(char *filestr); // функция назначения стипендий студентам
void out_reex(char *filestr); // функция вывода студентов на пересдачу
void out_expel(char *filestr); // функция вывода студентов на отчисление
void list(char *filestr); // функция вывода списка студентов
void change(char *filestr); // функция редактирования записи
void menu(); // функция описания возможностей программы
void output(char *filestr, int EDGE, struct student *DATA); // вывод данных на экран
void out_avg(char *filestr); // функция вывода согласно среднему баллу

struct student
{
	int  group;		// номер группы
	char name1[40]; // Фамилия
	char name2[40]; // Имя
	char name3[40]; // Отчество
	char disp[150]; // Дисциплины
	int  mark[10];  // Оценка
	float avg; // средний балл
};

int cmp_by_name(const void * a, const void * b) // функция сортироки по фамилии имени отчеству
{
	int cmp;
	cmp = strcmp(((struct student*)a)->name1, ((struct student*)b)->name1);
	if (cmp) return cmp;
	cmp = strcmp(((struct student*)a)->name2, ((struct student*)b)->name2);
	if (cmp) return cmp;
	return strcmp(((struct student*)a)->name3, ((struct student*)b)->name3);
}

int cmp_by_avg(const void * a, const void * b) // функция сортировки вещественных чисел
{
	if (((struct student*)b)->avg < ((struct student*)a)->avg)
		return -1;
	else return 1;
}

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

int main(void) // b.f.
{
	int i; 
	int c; // действующий символ
	char m_comToChar[N][14] = { "add","edit","delete","output name","output mark","output grant","output repeat","output expel","end" };
	int command;
	char *filestr = (char*)malloc(151*sizeof(char));
	while (1)
	{
		system("cls"); // очищение консоли
		menu();
		printf(" | Input: ");
		{ // ввод строки в динамический массив
			i = 0;
			while ((c = getchar()) != '\n')
			{
				*(filestr + i) = c;
				//filestr = (char*)realloc(filestr, (2 + (i)) * sizeof(char));
				++i;
			}
			*(filestr + i) = '\0';
		}
		for (i = add, command = -1; i < close; ++i)
			if (strcmp(filestr, m_comToChar[i]) == 0)
			{
				command = i;
			}
		if (command >= 0 && command < 10)
			printf(" | Entered command: \"%s\"\n", m_comToChar[command]);
		else
			printf(" | Entered command: \"%s\" corrupted\n", filestr);
		switch (command)
		{
		case add:
			system("cls"); // очищение консоли
			printf(" | Add new student to database\n");
			include(filestr);
			break;
		case edit:
			system("cls"); // очищение консоли
			list(filestr);
			printf(" | Edit student's marks\n");
			change(filestr);
			break;
		case delete:
			system("cls"); // очищение консоли
			list(filestr);
			printf(" | Delete student from database\n");
			uninclude(filestr);
			break;
		case output_name:
			system("cls"); // очищение консоли
			abc(filestr);
			break;
		case output_mark:
			system("cls"); // очищение консоли
			out_avg(filestr);
			break;
		case output_grant: 
			system("cls"); // очищение консоли
			out_grant(filestr);
			break;
		case output_repeat: 
			system("cls"); // очищение консоли
			out_reex(filestr);
			break;
		case otput_expel:
			system("cls"); // очищение консоли
			out_expel(filestr);
			break;
		case end: 
			printf(" | \n | Shutdown program\n");
			free(filestr);
			return 0;
		default:
			printf(" | Not aviable command\n");
			break;
		}
		printf(" | \n | Press enter to continue\n");
		gets(filestr);
	}
}

void list(char *filestr)
{
	auto int i;
	printf(" | List of students:\n");
	printf(" | \n | NUM  Surname      Name         Middle name    Group\n | \n");
	i = counter(filestr); // HAS BEEN CHANGED IF ERROR COPY FROM PREVIOUS VERSION
	struct student* DATA = (struct student*)malloc(i * sizeof(struct student)); // несортированный массив структур
	read(filestr, DATA); // получаем динамический массив структур всех студентов
	qsort(DATA, i, sizeof(struct student), cmp_by_name); // сортировка
	for (int j = 0; j < i; ++j)
	{
		printf(" |  %3d. %-12s %-12s %-12s : group num = %d\n", j + 1, DATA[j].name1, DATA[j].name2, DATA[j].name3, DATA[j].group);
	}
	free(DATA);
	return;
}

void out_expel(char *filestr)
{
	auto int i;
	int k;
	int flag_expel;
	i = counter(filestr);
	struct student* DATA = (struct student*)malloc(i * sizeof(struct student)); // массив структур
	read(filestr, DATA); // получаем динамический массив структур всех студентов
	printf(" | List of students for expel:\n");
	printf(" | \n | NUM  Surname      Name         Middle name    Group\n | \n");
	qsort(DATA, i, sizeof(struct student), cmp_by_name); // сортировка
	for (int j = 0, num = 0, sum = 0; j < i; ++j, sum = 0)
	{
		for (k = 0, flag_expel = NO; DATA[j].mark[k] > 0 && k < 10; ++k)
		{
			if (DATA[j].mark[k] < 3)
			{
				++sum;
				if (sum == 3)
				{
					flag_expel = YES;
					break;
				}
			}
		}
		if (flag_expel == YES || sum == k)
		{
			printf(" | %3d. %-12s %-12s %-12s : group num = %d\n", num + 1, DATA[j].name1, DATA[j].name2, DATA[j].name3, DATA[j].group);
			++num;
		}
	}
	free(DATA);
	return;
}

void out_reex(char *filestr)
{
	auto int i;
	int k;
	int z;
	int flag_reex;
	i = counter(filestr);
	struct student* DATA = (struct student*)malloc(i * sizeof(struct student)); // массив структур
	read(filestr, DATA); // получаем динамический массив структур всех студентов
	printf(" | Students that directed to the re-examination:\n");
	printf(" | \n | NUM  Surname      Name         Middle name    Group\n | \n");
	qsort(DATA, i, sizeof(struct student), cmp_by_name); // сортировка
	for (int j = 0, num = 0; j < i; ++j)
	{
		z = 0;
		strcpy(filestr, DATA[j].disp);
		for (k = 0, flag_reex = NO; DATA[j].mark[k] > 0 && k < 10; ++k)
		{
			if (DATA[j].mark[k] == 2)
			{
				if (flag_reex == NO)
				{
					flag_reex = YES;
					printf(" | %3d. %-12s %-12s %-12s : group num = %d\n |      Failed exams: ", num + 1, DATA[j].name1, DATA[j].name2, DATA[j].name3, DATA[j].group);
					++num;
				}
				for (; *(filestr + z) != '\0'; )
				{
					if (*(filestr + z) == '|')
					{
						++z;
						break;
					}
					for (; *(filestr + z) != '\0' && *(filestr + z) != '|'; ++z) 
						printf("%c", *(filestr + z));
				}
				printf(" ");
				continue;
			}
			for ( ; *(filestr + z) != '\0'; )
			{
				if (*(filestr + z) == '|')
				{
					++z;
					break;
				}
				for (; *(filestr + z) != '\0' && *(filestr + z) != '|'; ++z) {}
			}
		}
		if (flag_reex == YES)
		{
			flag_reex = NO;
			printf("\n");
		}
	}
	free(DATA);
	return;
}

void out_grant(char *filestr)
{
	auto int i;
	int k;
	int flag_grant;
	i = counter(filestr);
	struct student* DATA = (struct student*)malloc(i * sizeof(struct student)); // массив структур
	read(filestr, DATA); // получаем динамический массив структур всех студентов
	printf(" | Granted students:\n");
	printf(" | \n | NUM  Surname      Name         Middle name    Group\n | \n");
	qsort(DATA, i, sizeof(struct student), cmp_by_name); // сортировка
	for (int j = 0, num = 0; j < i; ++j)
	{
		for (k = 0, flag_grant = YES; DATA[j].mark[k] > 0 && k < 10; ++k)
		{
			if (DATA[j].mark[k] < 4)
			{
				flag_grant = NO;
				break;
			}
		}
		if (flag_grant == YES)
		{
			printf(" | %3d. %-12s %-12s %-12s : group num = %d\n", num + 1, DATA[j].name1, DATA[j].name2, DATA[j].name3, DATA[j].group);
			++num;
		}
	}
	free(DATA);
	return;
}

void out_avg(char *filestr)
{
	auto int i;
	int k;
	i = counter(filestr);
	struct student* DATA = (struct student*)malloc(i * sizeof(struct student)); // несортированный массив структур
	read(filestr, DATA); // получаем динамический массив структур всех студентов
	printf(" | Educational rating:\n");
	printf(" | \n | NUM  Surname      Name         Middle name    Group\n | \n");
	for (int j = 0; j < i; ++j)
	{
		DATA[j].avg = 0;
		for (k = 0; DATA[j].mark[k] > 0 && k < 10; ++k)
		{
			if (DATA[j].mark[k] == 1)
				DATA[j].mark[k] = 0;
			DATA[j].avg += DATA[j].mark[k];
		}
		DATA[j].avg = (float)DATA[j].avg / k;
	}
	qsort(DATA, i, sizeof(struct student), cmp_by_avg); // сортировка
	for (k = 0; k < i; ++k)
		printf(" | %3d. %-12s %-12s %-12s : group num = %-6d : average mark = %.1f\n", k + 1, DATA[k].name1, DATA[k].name2, DATA[k].name3, DATA[k].group, DATA[k].avg);
	free(DATA);
	return;
}

void output(char *filestr, int EDGE, struct student *DATA) // вывод данных на экран
{
	char c; // debug
	int cnt;
	int j;
	printf(" | \n | NUM  Surname      Name         Middle name    Group\n | \n");
	for (int i = 0; i < EDGE; ++i)
	{
		printf(" | %3d. %-12s %-12s %-12s : group num = %d\n |      Desciplines:", i+1, DATA[i].name1, DATA[i].name2, DATA[i].name3, DATA[i].group);
		strcpy(filestr, DATA[i].disp);
		for (j = 0, cnt = 0; *(filestr + j) != '\0'; ++cnt)
		{
			printf("  ");
			*(filestr + j) == '|' ? ++j : NULL;
			for (; *(filestr + j) != '\0' && *(filestr + j) != '|'; ++j)
				printf("%c", *(filestr + j));
			if (DATA[i].mark[cnt]>1)
				printf(" = %d", DATA[i].mark[cnt]);
			else
				printf(" = N/A");
		}
		printf("\n | \n");
	}
	return;
}

void abc(char *filestr)
{
	auto int i;
	printf(" | Output database in alphabetical order:\n");
	i = counter(filestr); // HAS BEEN CHANGED IF ERROR COPY FROM PREVIOUS VERSION
	struct student* DATA = (struct student*)malloc(i * sizeof(struct student)); // несортированный массив структур
	read(filestr, DATA); // получаем динамический массив структур всех студентов
	qsort(DATA, i, sizeof(struct student), cmp_by_name); // сортировка
	output(filestr, i, DATA);
	free(DATA);
	return;
}

void include(char *filestr)
{
	int i = 0;
	int c;
	int ctr; // counter
	int end;
	struct student x;
	printf(" | Enter student's group: ");
	scanf("%d", &x.group);
	if (x.group < 0)
	{
		printf(" |  || Wrong group ||\n");
		gets(filestr);
		return;
	}
	gets(filestr); // особенность компилятора
	printf(" | Enter student's surname: ");
	gets(x.name1);
	printf(" | Enter student's name: ");
	gets(x.name2);
	printf(" | Enter student's middle name: ");
	gets(x.name3);
	printf(" | Enter number of disciplines: ");
	scanf("%d", &end);
	if (end < 0)
	{
		printf(" |  || Wrong number ||\n");
		gets(filestr);
		return;
	}
	gets(filestr); // особенность компилятора
	for (ctr = 0; ctr < end; )
	{
		printf(" | Enter discipline %d: ", ctr + 1);
		{ // ввод строки в динамический массив
			while ((c = getchar()) != '\n')
			{
				*(filestr + i) = c;
				++i;
			}
			*(filestr + i) = '|';
			++i;
		}
		x.mark[ctr] = 1;
		++ctr;
		if (ctr == end)
		{
			*(filestr + i - 1) = '\0';
		}
	}
	strcpy(x.disp, filestr);
	write(filestr, x);
	printf(" | Student had been added!\n");
	return;
}

void write(char *filestr, struct student x) // запись данных в конец файла
{
	int i;
	int cnt = 0; // counter
	FILE *fwr;
	fwr = fopen("base.txt", "at");
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
	fclose(fwr);
}

void rewrite(char *filestr, struct student *DATA) // перезапись базы данных
{
	FILE *fwr;
	fwr = fopen("base.txt", "wt");
	fclose(fwr);
	for (int X = 0;X < _msize(DATA) / sizeof(struct student); ++X)
		write(filestr, DATA[X]);
}

void change(char *filestr)
{
	int i;
	int c;
	int X; // x - dimension (axis)
	struct student x; // требуется для хранения введённых параметров и дальнейшего сравнения с БД
	int cnt; // counter of discioline
	i = counter(filestr); // HAS BEEN CHANGED IF ERROR COPY FROM PREVIOUS VERSION
	struct student* DATA = (struct student*)malloc(i * sizeof(struct student));
	read(filestr, DATA); // получаем динамический массив структур всех студентов
	printf(" | Enter student's surname: ");
	gets(x.name1);
	printf(" | Enter student's name: ");
	gets(x.name2);
	printf(" | Enter student's middle name: ");
	gets(x.name3);
	printf(" | Enter student's group: ");
	scanf("%d",&x.group);
	gets(filestr);
	for (X = 0; X < _msize(DATA) / sizeof(struct student); ++X) // search
	{
		if (strcmp(DATA[X].name1, x.name1) == 0)
			if (strcmp(DATA[X].name2, x.name2) == 0)
				if (strcmp(DATA[X].name3, x.name3) == 0)
					if (x.group == DATA[X].group)
					break;
	}
	if (X == _msize(DATA) / sizeof(struct student)) // ne nashli studenta
	{
		printf(" | Student was not found\n");
		free(DATA);
		return;
	}
	i = 0;
	cnt = 0;
	while (DATA[X].disp[i] != '\0')
	{
		printf(" | Enter ");
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
			printf(" | Mark corrupted\n");// po horoshemu nado bi zaprosit' reenter no ne znauy...
		}
		if (DATA[X].disp[i] != '\0')
			++i;
		++cnt;
	}
	c = getchar(); // особенность компилятора (steck\n)
	rewrite(filestr,DATA); // serost' : perezapis' v obshem
	printf(" | Marks were edited!\n");
	free(DATA);
	return;
}

int counter(char *filestr) // count struct massive /// HAS BEEN CHANGED IF ERROR COPY FROM PREVIOUS VERSION
{
	FILE *frd = fopen("base.txt", "rt");
	auto int i = 0;
	int c;
	while (!feof(frd))
	{
		fgets(filestr, 6, frd);
		if (strcmp(filestr, "\n") == 0)
			fgets(filestr, 6, frd);
		if (strcmp(filestr, "Group") == 0)
			++i;
		while ((c = fgetc(frd)) != '\n')
			if (c == EOF)
				break;
	}
	fclose(frd);
	return i;
}

void read(char *filestr, struct student *DATA)
{
	auto int i; // edited
	int c;
	int X = 0; // dimension
	int cnt;
	FILE *frd = fopen("base.txt", "rt");
	for ( ; (c = fgetc(frd)) == 'G'; i=0,++X)
	{
		{ // group
			i = 0;
			while ((c = fgetc(frd)) != '\n')
			{
				*(filestr + i) = c;
				++i;
			}
			--i;
			DATA[X].group = 0;
			for (cnt = 1; *(filestr + i) >= '0' && *(filestr + i) <= '9'; i--, cnt *= 10) // *(filestr + i) != ' '
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
		for (i = 0; i < OTS; c = fgetc(frd), ++i) {}
		i = 0;
		while ((c = fgetc(frd)) != '\n') // name2
		{
			*(filestr + i) = c;
			++i;
		}
		*(filestr + i) = '\0';
		strcpy(DATA[X].name2, filestr);
		for (i = 0; i < OTS; c = fgetc(frd), ++i) {}
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
		strcpy(DATA[X].disp, filestr); // vajno
	}
	fclose(frd);
}

void uninclude(char *filestr)
{
	int i;
	int X; // x - dimension (axis)
	struct student x; // требуется для хранения введённых параметров и дальнейшего сравнения с БД
	int cnt; // counter of delete element
	i = counter(filestr);
	struct student* DATA = (struct student*)malloc(i * sizeof(struct student));
	read(filestr, DATA); // получаем динамический массив структур всех студентов
	printf(" | Enter student's surname: ");
	gets(x.name1);
	printf(" | Enter student's name: ");
	gets(x.name2);
	printf(" | Enter student's middle name: ");
	gets(x.name3);
	printf(" | Enter student's group: ");
	scanf("%d", &x.group);
	gets(filestr);
	for (X = 0; X < _msize(DATA) / sizeof(struct student); ++X) // search
	{
		if (strcmp(DATA[X].name1, x.name1) == 0)
			if (strcmp(DATA[X].name2, x.name2) == 0)
				if (strcmp(DATA[X].name3, x.name3) == 0)
					if (x.group == DATA[X].group)
						break;
	}
	if (X == _msize(DATA) / sizeof(struct student)) // ne nashli studenta
	{
		printf(" | Student was not found\n");
		free(DATA);
		return;
	}
	cnt = X;
	FILE *fwr;
	fwr = fopen("base.txt", "wt");
	fclose(fwr);
	for (int X = 0; X < _msize(DATA) / sizeof(struct student); ++X)
		if (X != cnt)
			write(filestr, DATA[X]);

	printf(" | Student had been deleted!\n");
	free(DATA);
	return;
}

void menu()
{
	WORD foregroundColor0;
	WORD foregroundColor1;
	WORD textAttribute;	   // атрибут текста - цвет символа и фона
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	foregroundColor1 = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED;
	textAttribute = foregroundColor1;
	SetConsoleTextAttribute(hStdout, textAttribute);
	printf("  ________________________________________________________________\n");
	printf(" |                     Database Dean's Office                     |\n");
	printf(" |----------------------------------------------------------------|\n");
	printf(" | Choose desirable action:                                       |\n");
	printf(" | Aviable commands: |          Description of command:           |\n");
	printf(" | - add             | (Replenishment of the database)            |\n");
	printf(" | - edit            | (Editing marks)                            |\n");
	printf(" | - delete          | (Delete student from database)             |\n");
	printf(" | - output name     | (Output database in alphabetic order)      |\n");
	printf(" | - output mark     | (Output average marks in descending order) |\n");
	printf(" | - output grant    | (List of granted students)                 |\n");
	printf(" | - output repeat   | (List of students sent for re-examination) |\n");
	printf(" | - output expel    | (List of studdents for expel)              |\n");
	printf(" | - end             | (Close program)                            |\n");
	printf(" |________________________________________________________________|\n");
	return;
}
