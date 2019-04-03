#pragma warning(disable : 4996) // отключение ошибки c4996
#include <stdio.h>

#define YES 1
#define NO 0
#define MAX 100 // kak po mne tak i 10 dostatochno, nu da ladno

int main(void)
{
	int MAS[MAX][MAX]; // ob'yavlyaem dvumernii massiv
	int N; // stroka
	int K; // stolbets
	int i; // po strokam
	int j; // po stolbzam
	int flag; // flazhok
	int diff; // raznost'

	printf("N = "); // zada'yom N i K
	scanf("%d", &N);
	printf("K = ");
	scanf("%d", &K);

	for (i = 0; i < N; i++) // zada'yom massiv
	{
		for (j = 0; j < K; j++)
		{
			printf("Element number %d %d: ", i + 1, j + 1);
			scanf("%d", &MAS[i][j]);
		}
	}

	for (i = 0; i < N; i++)
	{
		flag = YES;
		diff = MAS[i][0] - MAS[i][1];
		for (j = 1; j < K - 1; j++)
		{
			if (diff != MAS[i][j] - MAS[i][j + 1])
			{
				flag = NO;
			}
		}
		if (flag == YES)
		{
			MAS[i][K] = YES;
		}
		else
		{
			MAS[i][K] = NO;
		}
	}

	flag = NO; // yest' li arifmeticheskaya progressia
	printf("Strings");
	for (i = 0; i < N; i++)
	{
		if (MAS[i][K] == YES)
		{
			printf(" %d", i + 1);
			flag = YES;
		}
	}
	if (flag == YES)
	{
		printf(" have an arithmetic progrssion");
	}
	else
	{
		printf(" have no arithmetic progrssion");
	}

	return 0;
}