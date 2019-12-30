#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, const char * argv[])
{
	for (int i = 0; i < argc; i++)
		printf("%d. %s\n", i, argv[i]);
	printf("\n");
	if (argc < 2)
	{
		printf("ERR1\n");
		return 0;
	}
	printf("PARAMETRS: ");
	for (int i = 0; i < (argc - 2); i++)
	{
		printf("%s", argv[i + 2]);
	}
	printf("\n");
	FILE *txt;
	txt = fopen(argv[1], "rt");
	if (txt == NULL)
	{
		printf("Err2\n");
		return 6;
	}
	char sim;
	int cnt = 0;;
	int separ = 0;
	do
	{
		if (separ == 0)
		{
			printf("WORD %i: ", cnt+1);
			separ = 100;
		}

		sim = getc(txt);
		for (int i = 0; i < (argc - 2); i++)
		{

			(sim == argv[i + 2][0]) ? (separ = 0) : (separ = 1);
			if (separ == 0)
			{
				break;
			}
		}
		if (separ != 0 && sim != '\n'&&sim != ' '&&sim != EOF)
			printf("%c", sim);

		if (separ == 0)
		{
			printf("\n");
			cnt++;
		}
	} while ((sim) != EOF);
	printf("\n");
	return 0;
}
