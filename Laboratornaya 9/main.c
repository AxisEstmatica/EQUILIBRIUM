#pragma warning(disable : 4996) // ���������� ������ c4996
#include <stdio.h>
//
#define YES 1
#define NO 0
#define MAXLINE 1000
//

void erasespace(void);
void mirrortext(void);
void mirrorres(void);

int main(void)
{
	printf("������� ���������� ����� text.txt:\n");
	mirrortext;
	// ���� ���������� ���� �� �������� ��� �� ��� �������� ���� ��� ��������, �������...
	erasespace;
	printf("\n��������� ��������� (res.txt):\n");
	mirrorres;
	return 0;
}