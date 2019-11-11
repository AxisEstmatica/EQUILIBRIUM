#pragma warning(disable : 4996) // отключение ошибки c4996
#include <stdio.h>

int main(void)
{
	char name[] = "IVANOVII5437704MAKAROVDV9054310ZENCHINKOLA6159086MENSHIKOVKH7345268VARFLAMOVNG8390249LEBEDEVVA4579382MIRONOVZI6660055VASILEVNN7835461VERSHILOVKI8946734";
	int bill[] = {8328,20831,2837,123,2334,99,38274,400,750};
	char ent[8]; // number
	int i = 0; //counter for programm
	int cnt = 0; // counter of number place in base
	char *name_ptr = name;
	int *bill_ptr = bill;
	char *ent_ptr = ent;
	//
	printf("Real numbers:\n");
	while (i < sizeof(bill)/sizeof(int)) // output numbers
	{
		while (*name_ptr < '0' || *name_ptr > '9')
			name_ptr++;
		printf("  ");
		while ((*name_ptr >= '0') && (*name_ptr <= '9'))
		{
			printf("%c", *name_ptr);
			name_ptr++;
		}
		printf("\n");
		i++;
	}
	i = 0;
	name_ptr = name;
	//
	printf("Enter phone number: "); // input need number
	gets(ent);
	int z = 0;
	while (i < 7 && *name_ptr != '\0') // check number
	{
		while (*name_ptr < '0' || *name_ptr > '9')
			name_ptr++;

		if (*name_ptr == *ent_ptr)
		{
			i++;
		}
		name_ptr++;
		ent_ptr++;
		
		(((*(name_ptr) < '0') || (*(name_ptr) > '9')) && (i < 7)) ? i = 0, cnt++, ent_ptr = ent : z++; // if next no number so zero
	}
	if (cnt == sizeof(bill) / sizeof(int)) // check existence of number
	{
		printf("NUMBER NOT IN BASE");
		return 0;
	}
	ent_ptr = (name_ptr - 7); // end of searched name
	name_ptr = ent_ptr;
	while ((*(name_ptr-1) < '0' || *(name_ptr-1) > '9') && (name_ptr != name)) // search name, if beginning so
		name_ptr--; // it would not be number before the name begins
	printf("CARDHOLDER: "); // output name
	while (name_ptr != (ent_ptr-2))
	{
		printf("%c", *name_ptr);
		name_ptr++;
	}
	printf(" %c.%c. ", *name_ptr, *(name_ptr + 1));
	printf("NUMBER: "); // output name
	printf("%s", ent);
	printf(" BILL: %d", *(bill_ptr+cnt)); // output payment
	return 0;
}