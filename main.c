#pragma warning(disable : 4996)
#include <stdio.h>
#include <locale.h>
int main(void)
{
	setlocale(LC_ALL, "Rus");
 	printf("������ ������ �� ����� ������� � ������?\n");
	int i = -599;
	while (i < 400000)
		printf("(���)");
}