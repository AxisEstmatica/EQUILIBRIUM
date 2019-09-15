#pragma warning(disable : 4996) // ���������� ������ c4996
#include <stdio.h>
//
#define YES 1
#define NO 0
#define MAXLINE 1000
//
void process_line(int *line_ptr); // ��������� �������

int main(void) //
{
	char line[MAXLINE]; //
	//
	printf("Please, enter some words,\nWARNING: words that start and end on similar letter will be deleted\n");
	gets(line);  // ��������� ������ �� ����� ����� � ���������� � ������ line
	int *ptr1 = line;
	int *ptr2 = line[0];
	int *ptr3 = &line[0];
	printf("1 = %d, 2 = %d, 3 = %d\n", ptr1, ptr2, ptr3);
	int *line_ptr = line;
	process_line(*line_ptr); // ��������� ������� ��� �������� line
	printf("Result:\n");
	puts(line); // ������� ������ line
	return 0;
}

void process_line(int *line_ptr) // ���� �������
{
	//int *buf_ptr = buffer;
	int c;  // ������� ������
	int prev_c; // ���������� ������
	int flag; // ������� ���������� ����
	int E; // ������ ������
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
		c = line_ptr;
		if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && (c != ' ' && c != '.' && c != ',' && c != '\n' && c != '\0' && c != '\t')) // �������� �� �� �����
		{
			found = YES;
		}
		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0' || c == '\t') // �������� ����� �����
		{
			flag = YES; // ����� �����������
			if ((prev_c - 'A' == E - 'A' || prev_c - 'a' == E - 'a' || prev_c - 'a' == E - 'A' || prev_c - 'A' == E - 'a') && found != YES) // �������� �� �������
			{
				
			}
			else
			{
				if (buffer[i-1] == ' ' || buffer[i-1] == '.' || buffer[i-1] == ',' || buffer[i-1] == '\n' || buffer[i-1] == '\0' || buffer[i-1] == '\t') // ���� ���������� ������ �����������, ��...
				{
					++post_i;
					buffer[post_i] = c; // ������ ������ �����������
				}
				else
				{
					for (++post_i; j < i; ++j) // ���������� ����� � ���-�� ������
					{
						buffer[post_i] = buffer[j]; // ����������
						++post_i;
					}
					buffer[post_i] = c; // ������������� ����������� ����� �������
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
	buffer[++post_i] = '\0';// ������������� ����� �����
}