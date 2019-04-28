#pragma warning(disable : 4996) // îòêëþ÷åíèå îøèáêè c4996
#include <stdio.h>
#define YES 1
#define NO 0

int main(void)
{
	long long int N; // dlinnoye zeloye chislo
	int K; // kolichestvo raz, na kotoroye nado sdvinut' N
	int i;
	int j;
	int flag;

	printf("Enter long N:");
	scanf("%lld", &N);
	printf("Enter K, that will shift N K times to left: ");
	scanf("%d", &K);
	printf("Initial Number: ");

	if(N >= 0)
		for (j = 8; j > 0; --j)
		{
			for (i = 1; i < 5; ++i)
			{
				printf("%d", (N >> j * 4 - i & 1));
			}
			printf(" ");
		}
	else
		for (j = 8, flag = YES; j > 0; --j)
		{
			for (i = 1; i < 5; ++i)
			{
				if (flag == YES)
				{
					flag = NO;
					printf("1");
				}
				else
				{
					printf("%d", ((~N + 1) >> j * 4 - i & 1));
				}
			}
			printf(" ");
		}

	printf("\n");

	if (K < 0)
	{
		printf("Wrong K\n");
	}

	printf("Shifted Number: ");

	if (K > 0)
	{
		for (i = 0; i < K; ++i)
		N = N << 1; // sdvig vlevo na 1 razryad
	}

	if (((~N + 1) >> 31 & 1) == 1 && K > 0)
	{
		N = -N;
	}

	if (((~N + 1) >> 31 & 1) == 0 && N < 0 && K > 0)
	{
		N = -N;
	}

	if (N >= 0)
		for (j = 8; j > 0; --j)
		{
			for (i = 1; i < 5; ++i)
			{
				printf("%d", (N >> j * 4 - i & 1));
			}
			printf(" ");
		}
	else
		for (j = 8, flag = NO; j > 0; --j)
		{
			for (i = 1; i < 5; ++i)
			{
				if (flag == YES)
				{
					flag = NO;
					printf("1");
				}
				else
				{
					printf("%d", ((~N + 1) >> j * 4 - i & 1));
				}
			}
			printf(" ");
		}

	printf("\n");
	printf("Result: %ld", N);

	return 0;
}
