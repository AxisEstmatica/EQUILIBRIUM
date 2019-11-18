#pragma warning(disable : 4996) // ���������� ������ c4996
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define YES 1
#define NO 0
#define STR 1024

int i = 0; // �������
int value = 0; // ����� �������
char c; // ��������� ������

int X; // dimensions
int Y;
int Z;
int J; // for name
int F = 0; //number of opened files

int inc_tr = 0; // trigger #include
int sco_tr = 0; // trigger ������ {
int sc1_tr = 0; // trigger ������ (
int poi_tr = 0; // trigger point with comma
int true_tr = 0; // trigger on '='
int FIRST = NO; // trigger �� ������� ������

#include "head.h"
#include "Umbrella.h"
#include "Uraboros.h"

#define MASSIVE 2
#define MASSintIVE 1

int f_int(char * filestr); // ��� ����
int f_char(char * filestr); // ��� char
int f_const(char * filestr); // for constant
int f_incl(char * filestr); // for include
int f_doub(char * filestr); // for include

void shift(char *ptr, int sme); // shift(��������� �� �.�������, �����) || ����� ����� �� �������
void writer(char *filestr, char ***title, char **name); // ���������� ����� ����� ��������

int main(void)
{
#if MASSIVE == 0 // �� ��������
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
#elif MASSIVE == 1 // ����� ����� �������� ��� ����, �� ������ ��������� �������
	// �� � �� ����� ��� ��� ������
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
	FILE *frd;
	printf("Please enter address of file: ");
	char *filestr = (char*)malloc(sizeof(char));
	{ // ���� ������ � ������������ ������
		i = 0;
		while ((c = getchar()) != '\n')
		{
			*(filestr + i) = c;
			filestr = (char*)realloc(filestr, (2 + (i++)) * sizeof(char));
		}
		*(filestr + i) = '\0';
		printf("Path of file: %s\n", filestr);
	}
	if (*filestr == '"') // �������� �������
	{
		i = 0;
		while (*(filestr + i) != '\0')
		{
			(*(filestr + i + 1) == '"') ? (*(filestr + i) = '\0') : (*(filestr + i) = *(filestr + i + 1));
			++i;
		}
	}
	printf("Path of file: %s\n", filestr);
	// start of 2 massive
	J = 0;
	char **name; // page of names
	name = (char**)malloc(sizeof(char*)); // page down
	name[0] = (char*)malloc(sizeof(char)); // page right
	while (*(filestr + i) != '\\')
	{
		--i;
	}
	++i;
	X = 0;
	Y = 0;
	while (*(filestr + i) != '\0')
	{
		name[0][Y] = *(filestr + i);
		++i;
		++Y;
		name[0] = (char*)realloc(name[0], (1 + Y) * sizeof(char));
	}
	name[J][Y] = '\0';
	//puts(name[0]);
		// �Ш� ����
	char ***title;
	title = (char***)malloc(sizeof(char**)); // page down
	title[0] = (char**)malloc(4 * sizeof(char*)); // page right; 4 coloumns
	for (Y = 0; Y < 4; Y++)
		title[0][Y] = (char*)malloc(sizeof(char)); // page up
loop:
	if (inc_tr != 0)
	{
		frd = fopen((name[F]), "rt");
		J = 0;
	}
	else
		frd = fopen((filestr), "rt"); // ��������� �������� ����
	if (frd == NULL) // �������� �� �������� ������
	{
		printf("FILE HAS NOT BEEN OPENED");
		free(filestr);
		exit(1);
	}
	while (!feof(frd)) // to end of file
	{
		i = 0;
		sc1_tr = 0;
		while ((c = fgetc(frd)) != '\n')
		{
			if (c == EOF) // end if EOF
				break;
			c == '{' ? ++sco_tr : c == '}' ? --sco_tr : NULL;
			c == '(' ? ++sc1_tr : NULL;
			if (c == '/' && *(filestr + i - 1) == c) // end if //
			{
				filestr = (char*)realloc(filestr, (1 + i) * sizeof(char)); // ���������� ��� �������
				--i;
				while ((c = fgetc(frd)) != '\n') // ��������� �� ����� ������
					if (c == EOF) // end if EOF
						break;
				break;
			}
			*(filestr + i) = c;
			filestr = (char*)realloc(filestr, (2 + (i++)) * sizeof(char));
		}
		*(filestr + i) = '\0';
		//puts(filestr);
		// ����� ���� �� ������
		i = 0;
		while (*(filestr+i) != '\0') // �� ����� ������
		{
			while (*(filestr + i) == ' ') // ������������ �� ������� �� �������
				++i;
			while (*(filestr + i) != ';') // �� ;
			{
				if (*(filestr + i) == '\0') // �� ����� ������
					break;
				if((sco_tr == 0) && (sc1_tr == 0))
				switch (*(filestr + i))
				{
				case 'i': if (f_int((filestr + i)) == 0)
				{
					title[X][1] = (char*)realloc(title[X][1],4*sizeof(char)); // page up (i-1 n-2 t-3 '\0'-4)
					title[X][1] = "int";
					writer(filestr, title, name);
				}
					break;
				case 'c': if (f_char((filestr + i)) == 0)
				{
					title[X][1] = (char*)realloc(title[X][1], 5 * sizeof(char)); // page up (char'\0'-5)
					title[X][1] = "char";
					writer(filestr, title, name);
				}
					break;
				case 'd':if (f_doub((filestr + i)) == 0)
				{
					title[X][1] = (char*)realloc(title[X][1], 7 * sizeof(char)); // page up (char'\0'-5)
					title[X][1] = "double";
					writer(filestr, title, name);
				}
					break;
				case '#':if (f_const((filestr + i)) == 0)
				{
					title[X][1] = (char*)realloc(title[X][1], 8 * sizeof(char)); // page up (#define '\0'-4)
					title[X][1] = "CONSTANT";
					writer(filestr, title, name);
				}
						 if (f_incl((filestr + i)) == 0)
						 {

							 while ((*(filestr + i) != '\"') &&(*(filestr + i) != '<'))
								 ++i;
							 if (*(filestr + i) == '<')
								 break;
							 ++J;
							 name = (char**)realloc(name,(1+J)*sizeof(char*)); // page down
							 name[J] = (char*)malloc(sizeof(char)); // page right
							 ++i;
							 name = (char**)realloc(name, (1 + J) * sizeof(char*));
							 for (Y = 0; *(filestr + i) != '\"'; Y++, ++i)
							 {
									 name[J][Y] = *(filestr + i);
									 name[J] = (char*)realloc(name[J], (2 + Y) * sizeof(char));
							 }
							 name[J][Y] = '\0';
						 }
					break;
				default:
					break;
				}
				// recreation
				title = (char***)realloc(title, (1 + X) * sizeof(char**)); // page down
				title[X] = (char**)malloc(4 * sizeof(char*)); // page right; 4 coloumns
				for (Y = 0; Y < 4; Y++)
					title[X][Y] = (char*)malloc(sizeof(char)); // page up
				while ((*(filestr + i) != ';') && (*(filestr + i) != '\0'))
					++i;
				++i;
			}
			if (*(filestr + i) == ';')
			++i;
		}
	}
	//printf("\nEND OF FILE\n");
	++F;
	inc_tr += J;
	if (F != inc_tr+1)
		goto loop;
	fclose(frd);
	printf("Extern variables = %d\n",X);
	value = X; // ������ ������ ���!!!!!!!!!!
	for (X = 0; X < value; X++)
	{
		printf("Name of file: %-10s | Type: %-8s | Name: %-13s | Value: %s\n",title[X][0], title[X][1], title[X][2], title[X][3]);
	}
	value = inc_tr;
	for (J = 0; J < value+1; J++)
	{
		printf("Name of file: %s\n", name[J]);
	}
	for (value = X, X = 0; X < value; X++)
		free(title[X]);
	free(title);
	free(filestr);
	for (J = 0; J < inc_tr; J++)
		free(name[J]);
	free(name);
	return 0;
}

void shift(char *ptr, int sme) // ������� �������� �����, ��������
							  // ������ ������� ����� �����\���� �� ��������
{
	i = 0;
	if (sme == 0)
		return;
	sme > 0 ? i = 1 :  NULL;
	value = _msize(ptr) / sizeof(*ptr);
	if (i == 1)
	{
		ptr = realloc(ptr, (value + sme) * sizeof(*ptr)); // allocation of add-al memory

		for (i = value; i > 0; i--, value--) // ����� ������ ���������
			*(ptr + value + sme - 1) = *(ptr + value-1); 
		for (i = 0; i < sme; i++) // ��������� �����
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
		for (i = 0; i < value - sme; i++) // ����� ������ ���������
			*(ptr + i) = *(ptr + i + sme);
		printf("\n");
		i = *ptr;
		*ptr = (char*) realloc(ptr, (value - sme) * sizeof(*ptr)); // memory relocation
		*ptr = i;
	}
	return;
}

void writer(char *filestr, char ***title, char **name)
{
	value = sizeof(name[0]) / sizeof(char);
	title[X][0] = (char*)realloc(title[X][0], value * sizeof(char)); // page up (i-1 n-2 t-3 '\0'-4)
	title[X][0] = name[F];
	while (*(filestr + i) != ' ')
		++i;
	while (*(filestr + i) == ' ')
		++i;
	for (Z = 0; (*(filestr + i) != ' ') && (*(filestr + i) != ';'); Z++, i++)
	{
		title[X][2][Z] = *(filestr + i);
		title[X][2] = (char*)realloc(title[X][2], (2 + Z) * sizeof(char));
	}
	title[X][2][Z] = '\0';
	//
	if (*(filestr + i) == ';')
	{
		title[X][3] = (char*)realloc(title[X][3], 4 * sizeof(char));
		title[X][3] = "N/A";
	}
	while ((*(filestr + i) != ';') && (*(filestr + i) != '\0'))
	{
		while (*(filestr + i) == ' ')
		{
			++i;
			if (*(filestr + i) == '=')
				++i;
		}
		for (Z = 0; (*(filestr + i) != ' ') && (*(filestr + i) != ';') && (*(filestr + i) != '\0'); Z++, i++)
		{
			title[X][3][Z] = *(filestr + i);
			title[X][3] = (char*)realloc(title[X][3], (2 + Z) * sizeof(char));
		}
		title[X][3][Z] = '\0';
		break;
		++i;
		if (*(filestr + i) == ';')
		{
			title[X][3] = (char*)realloc(title[X][3], 4 * sizeof(char));
			title[X][3] = "N/A";
		}
	}
	++X; // ���������� 
}

int f_int(char * filestr) // ��� ����
{
	auto i = 0;
	char *word = (char*)malloc(sizeof(char)); // word massive
	while (i < 3)
	{
		*(word + i) = *(filestr + i);
		word = (char*)realloc(word, (2 + (i++)) * sizeof(char));
	}
	*(word + i) = '\0';
	if (*(filestr + i) != ' ')
	{
		free(word);
		return -1;
	}
	i = strcmp(word, "int");
	free(word);
	return i;
}

int f_char(char * filestr)
{
	auto i = 0;
	char *word = (char*)malloc(sizeof(char)); // word massive
	while (i < 4)
	{
		*(word + i) = *(filestr + i);
		word = (char*)realloc(word, (2 + (i++)) * sizeof(char));
	}
	*(word + i) = '\0';
	if (*(filestr + i) != ' ')
	{
		free(word);
		return -1;
	}
	i = strcmp(word, "char");
	free(word);
	return i;
}

int f_const(char * filestr)
{
	auto i = 0;
	char *word = (char*)malloc(sizeof(char)); // word massive
	while (i < 7)
	{
		*(word + i) = *(filestr + i);
		word = (char*)realloc(word, (2 + (i++)) * sizeof(char));
	}
	*(word + i) = '\0';
	if (*(filestr + i) != ' ')
	{
		free(word);
		return -1;
	}
	i = strcmp(word, "#define");
	free(word);
	return i;
}

int f_incl(char * filestr)
{
	auto i = 0;
	char *word = (char*)malloc(sizeof(char)); // word massive
	while (i < 8)
	{
		*(word + i) = *(filestr + i);
		word = (char*)realloc(word, (2 + (i++)) * sizeof(char));
	}
	*(word + i) = '\0';
	if (*(filestr + i) != ' ')
	{
		free(word);
		return -1;
	}
	i = strcmp(word, "#include");
	free(word);
	return i;
}

int f_doub(char * filestr)
{
	auto i = 0;
	char *word = (char*)malloc(sizeof(char)); // word massive
	while (i < 6)
	{
		*(word + i) = *(filestr + i);
		word = (char*)realloc(word, (2 + (i++)) * sizeof(char));
	}
	*(word + i) = '\0';
	if (*(filestr + i) != ' ')
	{
		free(word);
		return -1;
	}
	i = strcmp(word, "double");
	free(word);
	return i;
}