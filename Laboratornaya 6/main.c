#pragma warning(disable : 4996) // îòêëþ÷åíèå îøèáêè c4996
#include <stdio.h>

#define YES 1
#define NO 0
#define N 10 
#define K 10

int main(void)
{
	int MAS[MAX][MAX]; // ob'yavlyaem dvumernii massiv
	int i; // po strokam
	int j; // po stolbzam
	int flag; // flazhok
	int diff; // raznost'

	for (i = 0; i < N; i++) // zada'yom massiv
	{
		for (j = 0; j < K; j++)
		{
			MAS[i][j] = rand();
		}
	}

	for (i = 0; i < N; i++) // ishem ariphmeticheskuu progressiu
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
