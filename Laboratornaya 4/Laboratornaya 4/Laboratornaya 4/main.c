//#pragma warning(disable : 4996) // ���������� ������ c4996
#include <stdio.h>
//
#define YES 1
#define NO 0
#define MAXLINE 1000
//
void process_line(char buffer[]); //

int main(void) //
{
	char line[MAXLINE]; //
	//
	printf("Please, enter some words,\nWARNING: words that start and end on similar letter will be deleted\n");
	gets(line);  //
	process_line(line); //
	printf("Result:\n");
	puts(line); //
	return 0;
}

void process_line(char buffer[]) //
{
	char c;  // ������� ������
	int prev_c; // ���������� ������
	int flag; // ������� ���������� ����
	int C; // ������ ������
	int i; // ������� �������
	int post_i; // ������� ������� � ��������� ��������
	int j; // ������� ������ �����

	// �� ������������
	flag = NO;
	C = ' ';
	j = 0;
	prev_c = ' '; //
	i = 0; // ������ ��� ������� ���������� � ����
	post_i = 0; // �� �� �������

	// ������ �������

	do // ���� � ������������
	{
		c = buffer[i];
		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0') //
		{
			flag = YES;
			if (prev_c == C) //
			{

			}
			else
			{
				for (; j < i; ++j) //
				{
					buffer[post_i] = buffer[j]; //
					++post_i;
				}
				buffer[post_i] = c; //
				++post_i;
			}

		}
		else
		{
			if (flag == YES) //
			{
				C = c; //
				flag = NO; //
				j = i; //
			}
			prev_c = c; //
		}
		++i;

	} while (c != '\0'); //
	for (; post_i < MAXLINE; ++post_i) // �������� ������ �� ���������� ��������
	{
		buffer[post_i] = 0;
	}
}