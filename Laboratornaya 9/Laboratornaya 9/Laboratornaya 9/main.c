#pragma warning(disable : 4996) // отключение ошибки c4996
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
	printf("Текущее содержимое файла text.txt:\n");
	mirrortext;
	// типа развилочку надо бы добавить про то мол изменить файл или оставить, подумаю...
	erasespace;
	printf("\nРезультат обработки (res.txt):\n");
	mirrorres;
	return 0;
}