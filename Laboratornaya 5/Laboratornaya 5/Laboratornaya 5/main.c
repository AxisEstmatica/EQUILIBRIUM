#pragma warning(disable : 4996) // отключение ошибки c4996
#include <stdio.h>

#define YES 1
#define NO 0
#define N 10 // da potomushto zifr budet desyat'

void process_MAS(int buffer[]); // ob'yavlyaem nashu funktsi'yu
int MAX(int buffer[]); // ishem max
int MIN(int buffer[]); // ishem min

int main(void)
{
	int MAS[N]; // ob'yavla'em massiv MAS dlya zelih chisel
	int i;
	printf("Enter 10 integer numbers\n");

	for (i = 0; i < N; ++i) // mi zadayem znachenia dlya massiva, oni zeliie
	{
		printf("Number %d:", i+1); // prekrasno rabotayet
			scanf("%d", &MAS[i]);
	}

	process_MAS (MAS); // telo; vishnevaya semerka, neonovie fari...
	
	printf("Result:");
	for (i = 0; i < N; ++i) // vivodim massiv
	{
		printf(" %d", MAS[i]);
	}

	return 0; // radyemsya
}

void process_MAS(int buffer[]) // mi opisyvayem nashu funktsiuu
{
	int i;
	int max; // maximalnii element
	int min; // minimalnii element
	int n_max; // (nuzhno li?) nomer maximal'nogo elementa
	int n_min; // (nuzhno li?) nomer naimenshigo elementa
	int flag_max; // flazhok max
	int flag_min; // flazhok min
	flag_max = NO;
	flag_min = NO;
	
	max = MAX(buffer);
	min = MIN(buffer);

	if (max == min) // zashita ot bespoleznih deystvii
	{
		i = 10;
	}
	else
	{
		i = 0;
	}

	while (i < N)
	{
		if (buffer[i] == max) // nahodim positsiuu max
		{
			flag_max = YES;
			n_max = i;
		}
		if (buffer[i] == min) // nahodim pozitsiuu min
		{
			flag_min = YES;
			n_min = i;
		}
		if (flag_max == YES && flag_min == YES)
		{
			if (n_max < n_min)
			{
				// esli dobavit' to chto v else no ot max do min to budet luche
			}
			else
			{
				for (++n_min; n_min < n_max; ++n_min) // obnulyaem ot min do max
				{
					buffer[n_min] = 0;
				}
			}
			flag_max = NO;
			flag_min = NO;
			--i; // shtob ne upustil min ili max
		}

		++i;
	}
}

int MAX(int buffer[]) // tut mi ishem min
{
	int i;
	int max;
	max = buffer[0];
	for (i = 1; i < N; ++i)
	{
		if (buffer[i] > max) // esli bolshe to bolshe
		{
			max = buffer[i];
		}
	}
	return max;
}

int MIN(int buffer[]) // tut mi ishem max
{
	int i;
	int min;
	min = buffer[0];
	for (i = 1; i < N; ++i)
	{
		if (buffer[i] < min) // esli men'she to menshe
		{
			min = buffer[i];
		}
	}
	return min;
}