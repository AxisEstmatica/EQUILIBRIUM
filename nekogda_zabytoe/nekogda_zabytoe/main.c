#pragma warning(disable : 4996) // ���������� ������ c4996
//#pragma warning(disable : 4013) // ���������� ������ c4996
//#pragma optimize( "[optimization-list]", {on | off})
//#pragma optimize("agi", off)
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
//#include <dir.h>
//#include <stdbool.h>
//#include <>
#define YES 1
#define NO 0
#define STR 1024

int i; // counter
//int command; // number of enetred command
char c; // ����������� ������

void include(char *filestr); // ������� ���������� �������
void write(char *filestr, struct student x); // ������� ������ ��������� � 
//void delete(); // ������� �������� �������
//void output_abc(); // ������� ������ �������
//void search(); // ������� ������ ������
//void edit(); // ������� �������������� ������

struct student
{
	int  group;		// ����� ������
	char name1[15]; // �������
	char name2[15]; // ���
	char name3[15]; // ��������
	char disp[150]; // ����������
	int  mark[10];  // ������
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

char m_comToChar[9][14] = { "add","edit","delete","output name","output mark","output grant","output repeat","output expel","end"};

int main(void) // b.f.
{
	//FILE *frd;
	int command;
	printf("Data base");
	char *filestr = (char*)malloc(sizeof(char));
loop:
	//frd = fopen("base.txt", "rt"); // ��������� �������� ����
	printf("\nChoose desirable action:\nAviable commands:\n");
	for (i = 0; i < 9; ++i)
		printf(" - %s\n", m_comToChar[i]);
	printf("Input: ");
	{ // ���� ������ � ������������ ������
		i = 0;
		while ((c = getchar()) != '\n')
		{
			*(filestr + i) = c;
			filestr = (char*)realloc(filestr, (2 + (i++)) * sizeof(char));
		}
		*(filestr + i) = '\0';
		printf("filestr: %s\n", filestr);
	}
	for (i = add, command = -1; i < close; ++i)
		if (strcmp(filestr, m_comToChar[i]) == 0)
		{
			command = i;
			printf("Entered string: \"%s\" i = %d\n", m_comToChar[command], i);
		}
	if (command >= 0 && command < 10)
		printf("Entered string: \"%s\"\n", m_comToChar[command]);
	else
		printf("Entered string: \"%s\" corrupted\n", filestr);
	switch (command)
	{
	case add: printf("Work in progress\n");
		include(filestr);
		break;
	case edit: printf("Work in progress\n");
		break;
	case delete: printf("Work in progress\n");
		break;
	case output_name: printf("Work in progress\n");
		break;
	case output_mark: printf("Work in progress\n");
		break;
	case output_grant: printf("Work in progress\n");
		break;
	case output_repeat: printf("Work in progress\n");
		break;
	case otput_expel: printf("Work in progress\n");
		break;
	case end: printf("Shutdown program\n");
		free(filestr);
		return 0;
	default:
		printf("Not aviable command\n");
		break;
	}
	goto loop;
}

void include(char *filestr)
{
	i = 0;
	int ctr; // counter
	int end;
	struct student x;
	printf("Enter student's group : ");
	scanf("%d", &x.group);
	gets(filestr); // ����������� �����������
	printf("Enter student's surname : ");
	//scanf("%s", x.name1);
	//gets_s(x.name1);
	//gets(x.name1);
	gets(x.name1);
	printf("Enter student's name : ");
	gets(x.name2);
	printf("Enter student's middle name : ");
	gets(x.name3);
	//
	printf("Enter number of disciplines: ");
	scanf("%d", &end);
	gets(filestr); // ����������� �����������
	for (ctr = 0; ctr < end; )
	{
		printf("Enter discipline %d : ", ctr + 1);
		{ // ���� ������ � ������������ ������
			//c = getchar(); // ����������� �����������
			while ((c = getchar()) != '\n')
			{
				*(filestr + i) = c;
				filestr = (char*)realloc(filestr, (2 + (i++)) * sizeof(char));
			}
			*(filestr + i) = '|';
			filestr = (char*)realloc(filestr, (2 + (i++)) * sizeof(char));
			//printf("filestr: %s\n", filestr);
		}
		//gets(x.disp);
		//printf("Enter mark %d : ", ctr + 1);
		//scanf("%d", &x.mark[ctr]);
		x.mark[ctr] = 1;
		++ctr;
		if (ctr == end)
		{
			filestr = (char*)realloc(filestr, (i) * sizeof(char));
			*(filestr + i - 1) = '\0';
		}
	}
	printf("filestr: %s\n", filestr);
	//x.disp[150] = strdup(filestr);
	strcpy(x.disp, filestr);
	printf("disp: %s\n", x.disp);
	write(filestr, x);
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
	//c = getchar(); // ����������� �����������
	fclose(fwr);
	//return;
}