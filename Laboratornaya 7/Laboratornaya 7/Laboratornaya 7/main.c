#pragma warning(disable : 4996) // отключение ошибки c4996
#include <stdio.h>

int main(void)
{
	long int N; // dlinnoye zeloye chislo
	int K; // kolichestvo raz, na kotoroye nado sdvinut' N

	printf("Enter long N:");
	scanf("%ld", &N);
	printf("Enter K, that will shift N K times to left: ");
	scanf("%d", &K);

	if (K < 0)
	{
		printf("Wrong K\n");
	}

	while (K > 0)
	{
		N = N << 1; // sdvig vlevo na 1 razryad
		--K;
	}

	printf("Result: %ld", N);

	return 0;
}