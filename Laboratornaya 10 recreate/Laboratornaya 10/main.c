#pragma warning(disable : 4996) // отключение ошибки c4996
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define YES 1
#define NO 0
#define STR 1024
#define N 3

int i = 0; // счётчик
int value = 0; // объём массива
char c; // очередной символ
int type;

char buffer[50]; // static buf

int ITR;
int prev_X;
int X; // dimensions xyz
int Y;
int Z;
int J; // for name
int F = 0; //number of opened files

enum MyType
{
	tstruct,
	tchar,
	tint,
	tfloat,
	tdouble,
	tinclude,
	tdefine,
	tconst,
	tshort,
	tsigned,
	tunsigned,
	tlong,
	last
};

char test[3][20]; // тестовый массив, хранящий предположительные данные о типе, имени, значении

const char TYPE[last][9] = {"struct", "char","int","float","double","#include", "#define", "const", "short", "signed", "unsigned", "long" };
const int TYPE_len[last] = {6,4,3,5,6,7,7,5,5,6,7,4};

void str_shift(char *filestr);
void open_file(char *filestr);
void write(char *filestr, char ***title, char **name);
void output_res(char *filestr, char ***title, char **name);
void rewrite(char *filestr);
void one_space(char *filestr);
void mod(char ***title);
void fname(char *filestr, char **name);
//void incr(char ***title);

void output(char *filestr) // for debug
{
	auto int i;
	auto int value;
	value = _msize(filestr);
	printf("\nOutput filestr:\n");
	for (i = 0; i < value; ++i)
	{
		printf("%c", *(filestr + i));
		if (*(filestr + i) == '\0')
			printf("~");
	}
	printf("\nOutput end.\n");
}

void str_shift(char *filestr) // сдвиг влево на 1 символ строки
{
	auto int i;
	auto int value;
	value = _msize(filestr);
	for (i = 1; i < value; ++i)
		*(filestr + i - 1) = *(filestr + i);
	filestr = filestr = (char*)realloc(filestr, (value - 1) * sizeof(char));
	return;
}

void open_file(char *filestr)
{
	{ // ввод строки в динамический массив
		i = 0;
		while ((c = getchar()) != '\n')
		{
			*(filestr + i) = c;
			filestr = (char*)realloc(filestr, (2 + (i++)) * sizeof(char));
		}
		*(filestr + i) = '\0';
		printf("Path of file: %s\n", filestr);
	}
	if (*filestr == '"') // удаление ковычек
	{
		i = 0;
		while (*(filestr + i) != '\0')
		{
			(*(filestr + i + 1) == '"') ? (*(filestr + i) = '\0') : (*(filestr + i) = *(filestr + i + 1));
			++i;
		}
		//filestr = (char*)realloc(filestr, (1 + i) * sizeof(char));
	}
	printf("Path of file: %s\n", filestr);
	//output(filestr); //debug
	return;
}

int main(void)
{
	ITR = 0;
	int flag_bkt=0;
	int flag_qte = 0;
	int prev_J = 0;

	char prev_c; // for defence
	int flag_zap; // flag of запятой

	WORD foregroundColor0; // цвет 
	WORD textAttribute;	   // атрибут текста - цвет
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	foregroundColor0 = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN /*| FOREGROUND_RED*/;
	textAttribute = foregroundColor0;// | backgroundColor;
	SetConsoleTextAttribute(hStdout, textAttribute);
	// создаём скелет трёхмерного массива
	X = 0;
	prev_X = X;
	char ***title;
	title = (char***)malloc(sizeof(char**)); // page down
	title[0] = (char**)malloc(N * sizeof(char*)); // page right; 4 coloumns
	for (Y = 0; Y < N; ++Y)
		title[0][Y] = (char*)malloc(sizeof(char)); // page up
	title[X][1][0] = '\0'; // устанавливаем конец слова в начало
	//
	FILE *frd;
	printf("Please enter address of file: ");
	char *filestr = (char*)malloc(sizeof(char));
	open_file(filestr); // вносим путь файла в filestr
	//open_file(filestr); // вносим путь файла в filestr
	// start of 2 massive
	J = 0;
	char **name; // page of names
	name = (char**)malloc(2*sizeof(char*)); // page down
	name[0] = (char*)malloc(_msize(filestr) * sizeof(char)); // page right
	name[1] = (char*)malloc(_msize(filestr) * sizeof(char));
	strcpy(name[J], filestr); // запомнили путь файла 
	// сохраняем путь файла в массив имён файлов (не забыть про увеличение количества строк)
	// цикл поиска файлов
	do
	{


		//open_file(filestr); // вносим путь файла в filestr
		//printf("Path of deb file: %s\n", filestr); //debug
		//output(filestr); //debug
		//name = (char**)realloc(name, (J + 2) * sizeof(char*));
		//name[J+1] = (char*)malloc(sizeof(char)); // page right
		
		//output(filestr); //debug
		//
		frd = fopen((filestr), "rt");
		//frd = fopen((filestr),"rt");
		if (frd == NULL)
		{
			printf("FILE CORRUPT\n");
			break;
		}
		// обрабатывать до ';', EOF


		{ // поиск сходства со значениями
			//i = 0;
			while (!feof(frd))
			{
				flag_qte = 0;
				{ // ввод строки в динамический массив
					i = 0;
					while ((c = getc(frd)) != ';' && c != EOF)
					{
						*(filestr + i) = c;
						filestr = (char*)realloc(filestr, (2 + (i++)) * sizeof(char));
					}
					*(filestr + i) = '\0';
					//output(filestr);
					//puts(filestr);
				}
				rewrite(filestr);
				//output(filestr);
				prev_c = ' ';
				while (*filestr != '\0')//&& *filestr != '{')
				{
					//if (*(filestr) == '\0')
						//printf("~_%c_", *(filestr + i));
					if (prev_c == ' ') // defence
						for (type = 0; type < last; ++type)
						{
							if (strncmp(filestr, TYPE[type], TYPE_len[type]) == 0)
								break;
						}
					else
						type = last; // если символ перед типом существовал то это не тип
					// recreation
					if (prev_X != X)
					{ // если изменился X то расширяем трёхмеру
						//output_res(filestr, title, name); // debug
						prev_X = X;
						title = (char***)realloc(title, (1 + X) * sizeof(char**)); // page down
						title[X] = (char**)malloc(N * sizeof(char*)); // page right; 4 coloumns
						for (Y = 0; Y < N; Y++)
							title[X][Y] = (char*)malloc(sizeof(char)); // page up
						title[X][1][0] = '\0'; // устанавливаем конец слова в начало
					}
					//printf("/nKKKKK bkt = %d qte = %d /n",flag_bkt,flag_qte); // debug
					if (flag_bkt == 0)
					{
						switch (type)
						{
						case tchar:
						case tint:
						case tfloat:
						case tdouble:
							flag_zap = 0;
							for (i = 0; *(filestr + i) != '\0'; ++i)
								if (*(filestr + i) == ',')
									++flag_zap;
							for (i = 0; *(filestr + i) != '\0'; ++i)
								if (*(filestr + i) == '{' || *(filestr + i) == '(')
									flag_zap = 0;
							if (flag_zap != 0)
							{
								title = (char***)realloc(title, (1 + X + flag_zap) * sizeof(char**)); // page down
								for (i = X + 1; i <= X + flag_zap; ++i)
								{

									title[i] = (char**)malloc(N * sizeof(char*)); // page right; 4 coloumns
									for (Y = 0; Y < N; Y++)
										title[i][Y] = (char*)malloc(sizeof(char)); // page up
									title[i][1][0] = '\0'; // устанавливаем конец слова в начало
								}
							}
							write(filestr, title, name);
							//output(filestr);
							break;
						case tinclude:
							fname(filestr, name);
							if (prev_J != J)
							{
								name = (char**)realloc(name, (J + 2) * sizeof(char*));
								prev_J = J;
							}
							//output(name[J]);
							//printf("\nKKKKKK  \"%s\" J = %d\n", name[J], J); //debug
							break;
							//break;
						case tconst:
						case tshort:
						case tsigned:
						case tunsigned:
						case tlong:
							mod(title);
							break;

							//default:
								//break;
						}
					}
					if (*filestr == '\'')
						++flag_qte;
					if (flag_qte == 2)
						flag_qte = 0;
					if (*filestr == '{' && flag_qte == 0)
					{
						++flag_bkt;
						//printf("\nXXXXXXXXXXXXX%d\n", flag_bkt);
					}
					if (*filestr == '}' && flag_qte == 0)
					{
						--flag_bkt;
						//printf("\nXXXZZZZZXXXX%d\n", flag_bkt);
					}
					//printf("\nXNNNNNNNNNNN%d\n", flag_qte);
					//printf("i = %d", i);
					prev_c = *filestr;
					str_shift(filestr);
					//++i;
				}
			}
		}

		fclose(frd);
		++ITR;
		if (ITR == J + 1)
		{
			break;
		}
		
		i = _msize(name[ITR]);
		filestr = filestr = (char*)realloc(filestr,i);
		strcpy(filestr, name[ITR]);
		flag_bkt = 0;
		flag_qte = 0;
		//output(filestr);
		//printf("\n      URABOROSSS  \"%s\" J = %d\n", name[J], J); //debug
		//printf("J=%dINC=%d", J,ITR);
	} while (ITR!=J+1);
	output_res(filestr, title, name);
	//output(name[0]); //debug
	//output(name[1]);//debug
	//output(name[2]);//debug
	//output(name[3]);//debug
	free(name);
	free(title);
	free(filestr);
	return 0;
}


void fname(char *filestr, char **name)
{
	//output(name[0]);
	auto int value = _msize(name[0]);
	auto int i = 0;
	auto int j = 0;
	char way[100];
	int flag_sh = NO; // flag of \ owner
	while (*(filestr+i)!='\"')
	{
		if (*(filestr + i) == '<' || *(filestr + i) == '\0')
			return;
		++i;
	}
	++J;
	//name = (char**)realloc(name, (J + 1) * sizeof(char*));
	++i;
	for (j=0;*(filestr + i) != '\"';++i,++j)
	{
		way[j] = *(filestr + i);
	}
	way[j] = '\0';
	for (j = 0; way[j]!='\0' ; ++j)
	{
		if (way[j] == '\\')
		{
			flag_sh = YES;
			break;
		}
	}
	if (flag_sh == NO)
	{
		name[J] = (char*)malloc(value);
		strcpy(name[J],name[0]);
		//i = 0;
		//while (name[J][i] != '\0')
		//	++i;
		i = strlen(name[J]);
		while (name[J][i] != '\\')
		{
			--i;
		}
		++i;
		name[J] = (char*)realloc(name[J], (strlen(way)+1+i)*sizeof(char));
		for (j = 0; way[j] != '\0'; ++i, ++j)
		{
			name[J][i] = way[j];
		}
		name[J][i] = '\0';
	}
	else
	{
		name[J] = (char*)malloc((strlen(way) + 1) * sizeof(char));
		name[J] = way;
	}
	//printf("\nVVVVV  \"%s\" J = %d\n",name[J],J); //debug
	//title = (char***)realloc(title, (1 + X + flag_zap) * sizeof(char**)); // page down


	//++J;
	return;
}

void mod(char ***title)
{
	auto int i;
	auto int j;
	//output(title[X][1]); // debug
	title[X][1] = (char*)realloc(title[X][1], (strlen(title[X][1]) + strlen(TYPE[type]) + 2) * sizeof(char));
	for (i = 0; title[X][1][i] != '\0'; ++i) {}
	if (i != 0)
	{
		title[X][1][i] = ' ';
		++i;
	}
	for ( j=0; TYPE[type][j] != '\0'; ++i, ++j)
		title[X][1][i] = TYPE[type][j];
	title[X][1][i] = '\0';
	//output(title[X][1]); // debug
	return;
}

void write(char *filestr, char ***title, char **name)
{
	auto int flag_zap = 0;
	//auto int flag_kov = 0;
	//printf("X = %d", X);
	auto int i;
	auto int j;
	auto int value;
	for (i = 0; *(filestr + i) != '\0'; ++i)
		if (*(filestr + i) == ',')
			++flag_zap;
	for (i = 0; *(filestr + i) != '\0'; ++i)
		if (*(filestr + i) == '{')
			flag_zap = 0;

	i = strlen(name[ITR]);
	while (name[ITR][i] != '\\')
		--i;
	//++i;
	title[X][0] = (char*)realloc(title[X][0], (strlen(name[ITR]) - i) * sizeof(char));
	j = -1;
	do
	{
		++j;
		++i;
		title[X][0][j] = name[ITR][i];
	} while (title[X][0][j]!='\0');
	//output(title[X][0]);

	//output(filestr);
	i = 0;
	while (*(filestr + i++) != '\0')
		if (*(filestr + i) == '('|| *(filestr + i) == ')')
			return;
	//output(filestr);
	// type
	title[X][1] = (char*)realloc(title[X][1], (strlen(title[X][1]) + strlen(TYPE[type]) + 2) * sizeof(char));
	//printf("\nsjifi  %d   \"%s\"  jdsojfjodf\n", strlen(title[X][1]),title[X][1]); // debug
	for (i = 0; title[X][1][i] != '\0'; ++i) {}
	if (i != 0)
	{
		title[X][1][i] = ' ';
		++i;
	}
	for (j = 0; TYPE[type][j] != '\0'; ++i, ++j)
		title[X][1][i] = TYPE[type][j];
	title[X][1][i] = '\0';
	// type
	//title[X][1] = TYPE[type];
	value = strlen(TYPE[type]) + 1;
	for (i = 0; i < value; ++i)
	{
		str_shift(filestr);
	}
	//filestr = filestr + strlen(TYPE[type]) + 1;
	//output(filestr);
	/*
	for (i = 0; *(filestr + i) != '\0'; i++)
	{

	}
	*/
	i = 0;
	while (*(filestr + i) != ' ' && *(filestr + i) != '\0' && *(filestr + i) != ',' && *(filestr + i) != '=')
		++i;
	*(filestr + i) = '\0';
	//output(filestr);
	title[X][2] = (char*)realloc(title[X][2], (strlen(filestr) + 1) * sizeof(char));
	strcpy(title[X][2], filestr);
	//title[X][2] = filestr;
	while (flag_zap != 0)
	{
		++X;
		//printf("X = %d", X);
		//printf("132");
		//output(filestr);
		//title = (char***)realloc(title, (1 + X) * sizeof(char**)); // page down
		//title[X] = (char**)malloc(N * sizeof(char*)); // page right; 4 coloumns
		//for (Y = 0; Y < N; Y++)
		//	title[X][Y] = (char*)malloc(sizeof(char)); // page up
		title[X][0] = (char*)realloc(title[X][0], (strlen(title[X - 1][0]) + 1) * sizeof(char));
		//strcmp(title[X][0], title[X - 1][0]);
		title[X][0] = title[X - 1][0];
		title[X][1] = (char*)realloc(title[X][1], (strlen(title[X - 1][1]) + 1) * sizeof(char));
		//strcmp(title[X][1], title[X - 1][1]);
		title[X][1] = title[X - 1][1];
		value = strlen(filestr) + 1;
		for (i = 0; i < value; ++i)
		{
			str_shift(filestr);
		}
		for (value = 0; *(filestr + value) == ' ' || *(filestr + value) == ','; value++) {}
		for (i = 0; i < value; ++i)
		{
			str_shift(filestr);
		}
		//output(filestr);
		//printf("122");
		i = 0;
		while (*(filestr + i) != ' ' && *(filestr + i) != '\0' && *(filestr + i) != ',')
			++i;
		*(filestr + i) = '\0';
		//output(filestr);
		title[X][2] = (char*)realloc(title[X][2], (strlen(filestr) + 1) * sizeof(char));
		strcpy(title[X][2], filestr);
		//output(filestr);
		//printf("121");
		--flag_zap;
	}
	++X; // VAJNO
	

	return;
}

void output_res(char *filestr, char ***title, char **name)
{
	//X = 0;
	auto int Y = 0;
	auto int i;
	//auto int value;
	printf("      FILE       |            TYPE           |   NAME\n");
	for (i = 0; i < X; ++i)
	{
		printf(" %-15s | %-25s | %-20s\n", title[i][0], title[i][1], title[i][2]);
	}
	return;
}

void rewrite(char *filestr) // del '\n'
{
	auto int i = 0;
	auto int flag_qte = NO; // защита от ковычек
	while (*(filestr + i) != '\0') // del '//' (comments)
	{
		if ((*(filestr + i) == '/') && (*(filestr + i + 1) == '/'))
		{
			while (*(filestr + i) != '\n' && *(filestr + i) != '\0')
			{
				*(filestr + i) = ' ';
				++i;
			}
			//output(filestr);
			//printf("\n%c %c\n", *(filestr + i), *(filestr + i + 1));
			//printf("1452251"); //debug
			--i;
		}
		++i;
		//printf("1452251");
	}
	/*
	i = 0;
	while (*(filestr + i) != '\0') // del functions
	{
		if (*(filestr + i) == '(')
		{
			flag_qte = YES;
		}
		if (*(filestr + i) == ')' && flag_qte == YES)
		{
			i = 0;
			while (*(filestr + i) != '\n' && *(filestr + i) != '\0')
			{
				*(filestr + i) = ' ';
				++i;
			}
			if (*(filestr + i) != '\0')
				*(filestr + i) = '1';
			flag_qte = NO;
		}
		++i;
	}
	*/
	//flag_qte = NO;
	i = 0;
	while (*(filestr + i) != '\0') // del massives
	{
		if (*(filestr + i) == '\'')
		{
			flag_qte = YES;
		}
		if (*(filestr + i) == '[' && flag_qte == NO)
		{
			i = 0;
			while (*(filestr + i) != '\0')
			{
				*(filestr + i) = ' ';
				++i;
			}
		}
		++i;
	}
	i = 0;
	while (*(filestr+i) != '\0')
	{ // defence from functions
		if (*(filestr + i) == '(')
		{
			while (*(filestr + i) != '\n' && *(filestr + i) != '\0' && *(filestr + i) != ')')
			{
				*(filestr + i) = ' ';
				++i;
			}
			--i;
		}
		++i;
	}
	auto int value = _msize(filestr);
	for (i = 0; i < value; ++i)
	{
		if (*(filestr + i) == '\n')
			*(filestr + i) = ' ';
	}
	one_space(filestr);
	
	return;
}

void one_space(char *filestr)
{
	auto int i;
	auto int j;
	auto int value = _msize(filestr);
	auto int flag;
	for (i = 0; i < value; ++i)
	{
		if (*(filestr + i) == '\n')
			*(filestr + i) = ' ';
	}
	flag = NO;
	for (i = 0, j = 0; i < value; ++i, ++j)
	{ // избавление от лишних пробелов
		if (*(filestr + i) != ' ')
			flag = NO;
		if (flag == NO)
			*(filestr + j) = *(filestr + i);
		else
			--j;
		if (*(filestr + i) == ' ')
			flag = YES;
	}
	value = strlen(filestr) + 1;
	filestr = (char*)realloc(filestr, value * sizeof(char));
	return;
}
