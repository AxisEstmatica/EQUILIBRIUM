#pragma warning(disable : 4996) // ���������� ������ c4996
#include <stdio.h>
#include <conio.h> // ���������� ������������� '_getch()' ???
#define YES 1
#define NO 0
int main(void)
{
	// ��������� ������������
	int c;       // ������� ������ �� ������
	int counter; // ���������� 'a'
	int flag;    // ������, �� �������� �� 
	             //���������� ������� ����� � � �����
	// ��������� ������������
	counter = 0;
	flag = NO;   // ���������� �������� ������
	printf("Please, enter some words:\n");
	// ���� ������� �������� �� ������, ���������� � �����������
	while ( (c = getchar()) != EOF )
	{
		if (c == 'a' || c == 'A')  // �������� ������� ����� �
		{
			flag = YES;
		}
		if (c == ' ' || c == '.' || c == '\n' || c == ',')
		{
			if (flag == YES) // �������� �� ������� ����� � � �����
			{
				++counter;   // ���������� �������� �� 1
				flag = NO;   // ����� ������
			}
		}
	}
	printf("Number of words that contains letters 'a' = %d\n", counter);
	printf("\nPress any button to close the window\n");
	_getch(); // �������� ����� ���� ����
	return 0;
}