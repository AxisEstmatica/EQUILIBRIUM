#pragma warning(disable : 4996) // ���������� ������ c4996
#include <stdio.h>
#include <malloc.h>
#define YES 1
#define NO 0
#define STR 1024

int i = 0; // �������
int value = 0; // ����� �������
char c; // ��������� ������

#define MASSIVE 2

void shift(int *ptr, int sme); // shift(��������� �� �.�������, �����) || ����� ����� �� �������

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

	//char *filestr_ptr; // ��������� �� filestr
	FILE *frd;
	printf("\nPlease enter address of file: ");
	char *filestr = (char*)malloc(sizeof(char));
	{ // ���� ������ � ������������ ������
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
	if (*filestr == '"') // �������� ��������
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

	frd = fopen((filestr), "rt"); // ��������� �������� ����
	if (frd == NULL) // �������� �� �������� ������
	{
		printf("FILE HAS NOT BEEN OPENED");
		free(filestr);
		exit(1);
	}
	
	fclose(frd);
	free(filestr);
	return 0;
}

void shift(int *ptr, int sme) // ������� �������� �����, ��������
							  //������ ������� ����� �����\���� �� ��������
{
	i = 0;
	if (sme == 0)
		return;
	sme > 0 ? i = 1 :  NULL;
	value = _msize(ptr) / sizeof(*ptr);
	if (i == 1)
	{
		ptr = realloc(ptr, (value + sme) * sizeof(*ptr)); // ��������� ��� ������

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
		//for (i = 0; i < value; i++) // zada'yom massiv
		//	printf("%5d", *(ptr + i));
		printf("\n");
		i = *ptr;
		*ptr = (int*) realloc(ptr, (value - sme) * sizeof(*ptr)); // ����������������� ������
		*ptr = i;
	}
	return;
}

//int i;