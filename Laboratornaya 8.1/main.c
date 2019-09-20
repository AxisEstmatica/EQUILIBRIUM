#pragma warning(disable : 4996) // ���������� ������ c4996
#include <stdio.h>
//
#define YES 1
#define NO 0
#define MAXLINE 1000
//
void process_line(char *line_ptr); // ��������� �������

int main(void) //
{
	char line[MAXLINE]; //
	char *line_ptr = line; // ��������� �� ������ �������
	//
	printf("Please, enter some words,\nWords that start and end on similar letter will be deleted:\n");
	gets(line);  // ��������� ������ �� ����� ����� � ���������� � ������ line
	//line_ptr = line; // ����������� ������ ������� ���������
	process_line(line_ptr); // ��������� ������� ��� �������� line
	printf("Result:\n");
	puts(line); // ������� ������ line
	return 0;
}

void process_line(char *line_ptr) // ���� �������
{
	//int *line_ptr = &line[0];
	char c;  // ������� ������
	char prev_c; // ���������� ������
	int flag; // ������� ���������� ����
	char E; // ������ ������
	int i; // ������� �������
	int post_i; // ������� ������� � ��������� ��������
	int j; // ������� ������ �����
	int found; // ������� ���������� �����

	// �� ������������
	found = NO;
	flag = NO;
	E = *line_ptr; // ����������� ������ ������, ����� �� �������� ���
	j = 0;
	prev_c = *line_ptr; // �� �� �������
	i = 0; // ������ ��� ������� ���������� � ����
	post_i = -1; // ������������ for

	// ������ �������

	do // ���� � ������������
	{
		c = *(line_ptr+i);
		if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && (c != ' ' && c != '.' && c != ',' && c != '\n' && c != '\0' && c != '\t')) // �������� �� �� �����
		{
			found = YES; // ��� �� �����
		}
		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0' || c == '\t') // �������� ����� �����
		{
			flag = YES; // ����� �����������
			if ((prev_c - 'A' == E - 'A' || prev_c - 'a' == E - 'a' || prev_c - 'a' == E - 'A' || prev_c - 'A' == E - 'a') && found != YES) // �������� �� �������
			{
				if ((E < 'a' || E > 'z') && (E < 'A' || E > 'Z')) // ���� ���� ����� ����� ���������� ����� �� ����� ��������� �����������
				{
					++post_i;
					*(line_ptr + post_i) = c; // ������ ������ �����������
				}
			}
			else
			{
				if (*(line_ptr + i-1) == ' ' || *(line_ptr + i - 1) == '.' || *(line_ptr + i - 1) == ',' || *(line_ptr + i - 1) == '\n' || *(line_ptr + i - 1) == '\t') // ���� ���������� ������ �����������, ��...
				{
					++post_i;
					*(line_ptr+post_i) = c; // ������ ������ �����������
				}
				else
				{
					for (++post_i; j < i; ++j) // ���������� ����� � ���-�� ������
					{
						*(line_ptr + post_i) = *(line_ptr + j); // ����������
						++post_i;
					}
					*(line_ptr + post_i) = c; // ������������� ����������� ����� �������
				}
			}
			found = NO;

		}
		else
		{
			if (flag == YES) // �������� �� ��������� �����������
			{
				E = c; // ������ ������ �� �����������
				flag = NO; // �������� ����
				j = i; // ���������� ����� ������� �������
			}
			prev_c = c; // ���������� ��������� �� �����������
		}
		++i;
	} 
	while (c != '\0'); // ���� �������� �� ����� �����
	++post_i;
	*(line_ptr + post_i) = '\0';// ������������� ����� �����
}