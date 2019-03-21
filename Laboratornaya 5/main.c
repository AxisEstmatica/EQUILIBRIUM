#pragma warning(disable : 4996) // ���������� ������ c4996
#include <stdio.h>

#define YES 1
#define NO 0
#define N 10 // ������ ��� ���� ����� 10

void process_MAS(int buffer[]); // ������� �������
int MAX(int buffer[]); // ���� ���������� ��������
int MIN(int buffer[]); // ���� ���������� ��������

int main(void)
{
	int MAS[N]; // ��������� ������ ��� ����� �����
	int i;
	printf("Enter 10 integer numbers\n");

	for (i = 0; i < N; ++i) // ����� �������� �������
	{
		printf("Number %d:", i+1); // ��������...
			scanf("%d", &MAS[i]);
	}

	process_MAS (MAS); // �������� �������� ����� ��� � ����
	
	printf("Result:");
	for (i = 0; i < N; ++i) // ������� ������
	{
		printf(" %d", MAS[i]);
	}

	return 0; // radyemsya
}

void process_MAS(int buffer[]) // ��������� ���� �������
{
	int i;
	int max; // ������������ �������
	int min; // ����������� �������
	int n_max; // ����� ����������� ��������
	int n_min; // ����� ����������� ��������
	int flag_max; // ������ �� ��������
	int flag_min; // ������ �� ��������
	flag_max = NO;
	flag_min = NO;
	
	max = MAX(buffer);
	min = MIN(buffer);

	if (max == min) // ������ �� ����������� ��������
	{
		i = 10;
	}
	else
	{
		i = 0;
	}

	while (i < N)
	{
		if (buffer[i] == max) // ������� ������� �� ��������
		{
			flag_max = YES;
			n_max = i;
		}
		if (buffer[i] == min) // ������� ������� �� ��������
		{
			flag_min = YES;
			n_min = i;
		}
		if (flag_max == YES && flag_min == YES)
		{
			if (n_max < n_min)
			{
				// ����� �������� �������� else � ����� �������� �� �� �� ��
			}
			else
			{
				for (++n_min; n_min < n_max; ++n_min) // �������� �� �� �� ��
				{
					buffer[n_min] = 0;
				}
			}
			flag_max = NO;
			flag_min = NO;
			--i; // ����� �� �������� �� ��� �� ��������
		}

		++i;
	}
}

int MAX(int buffer[]) // ���� �� ��������
{
	int i;
	int max;
	max = buffer[0];
	for (i = 1; i < N; ++i)
	{
		if (buffer[i] > max) // ���� ������, �� ������
		{
			max = buffer[i];
		}
	}
	return max; // ���������� �� ��������
}

int MIN(int buffer[]) // ���� �� ��������
{
	int i;
	int min;
	min = buffer[0];
	for (i = 1; i < N; ++i)
	{
		if (buffer[i] < min) // ���� �����, �� ������
		{
			min = buffer[i];
		}
	}
	return min; // ���������� �� ��������
}