#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define begin 9//начало работы
#define end 21//конец работы

typedef struct {
	char name[40];//название 
	int time;//время
}hairstyle;//описание прически

typedef struct {
	int min; // время в минутах
	int pr; // занято или нет
}time;//структура описания времени

typedef struct {
	char name[50];
	hairstyle rec; // причёска
	int time[2]; // время записи
}client;

int time_work = (end - begin) * 60;//время работы в минутах
client man[30];//массив клиентов за день
int counter = 0;//счетчик записей за день
hairstyle list[10] = { "Причёска А",30,"Причёска Б",40,"Причёска В",50,"Причёска Г",60,"Причёска Д",65,"Причёска Е",45,"Причёска Ё",82,"Причёска Ж",23,"Причёска З",54,"Причёска И",23};
//массив причесок "название, время исполнения"

void record(time[]);//запись в парикмахерскую
void delet(time[]);//удаление записи из списка
void out_record();//вывод на экран списка записей

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");//для корректной работы кириллицы
	int a = 0;//переменная для switch
	time Time[(end - begin) * 60];//массив времени работы в минутах
	int i = 0;//для циклов
	for (i = 0; i < time_work; i++)//инициализация времени работы парикмахерской
	{
		Time[i].min = i;//номер минуты
		Time[i].pr = 0;//показатель "свободно/занято"
	}
	while (a != 4)
	{
		system("cls");
		printf("Выберите действие\n\n");
		printf("1.Записаться на стрижку\n2.Вывести записи\n3.Удаление из списка\n4.Выход\n");
		scanf("%i", &a);
		switch (a)
		{
		case 1:
			record(Time);
			break;
		case 2:
			out_record();
			system("pause");
			break;
		case 3:
			if (counter)//если записец нет, то удалять нечего
				delet(Time);//и функция удаления не вызывается
			else
			{
				printf("\nЗаписей нет!");
				system("pause");
			}

			break;
		case 4:
			break;
		default: printf("Введите 1-4");
		}
	}
	system("pause");
	return 0;
}

void hr_out()//вывод списка причесок для выбора
{
	int i;
	printf("Прическа\t\tвремя выполнения");
	for (i = 0; i < 10; i++)
	{
		printf("\n%2d.%s\t\t%i:%i", i + 1, list[i].name, list[i].time / 60, list[i].time % 60); // часы : минуты
	}
}

void delet(time T[])
{
	client x;//впомогательная переменная
	int n, i;
	system("cls");
	out_record();//вывод списка записей
	do {
		printf("\nВведите порядковый номер записи для удаления: ");
		scanf("%i", &n);//ввод номера удаляемой записи
		if (n < 1 || counter < n)
			printf("Введите номер из списка!\n");
	} while (n < 1 || counter < n);
	n--;
	i = 60 * (man[n].time[0] - begin) + man[n].time[1];
	for (; i < 60 * (man[n].time[0] - begin) + man[n].time[1] + man[n].rec.time; i++)
	{
		/*освобождаем минуты с "времени записи на стрижку" до "время записи на стрижку + время самой стрижки"*/
		T[i].pr = 0;//при удалении записи "освобождаем" время, которое было "занято" в массиве работы парикмахерской
		//printf("\n%i %i", T[i].min, T[i].pr);
	}

	if (n != counter - 1)//если удаляемая запись не последняя
	{
		x = man[n];//то меняем ее с последней записью 
		man[n] = man[counter - 1];
		man[counter - 1] = x;
	}
	system("pause");
	counter--;//уменьшаем счетчик
}

void sort()
{//сортировка пузырьком по времени записи
	client x; // переменная для временного хранения
	int i, j;
	if (counter < 2)
		return;
	for (i = 0; i < counter - 1; i++)
		for (j = i + 1; j < counter; j++)
			if (man[i].time[0] > man[j].time[0])
			{
				x = man[i];
				man[i] = man[j];
				man[j] = x;
			}
}

void out_record()
{//вывод записей на экран
	int i;
	printf("\nЗаписи:");
	sort();
	for (i = 0; i < counter; i++)
	{
		printf("\n%2d.%s ", i + 1, man[i].name);//вывод имени
		printf("%i:", man[i].time[0]);//вывод часа
		if (man[i].time[1] < 10)//если минуты равны 0-9
			printf("0");//то приписываем 0 впереди чтоб получилось "9 00", а не "9 0"
		printf("%i - ", man[i].time[1]);//вывод минут
		printf("%i:", ((60 * man[i].time[0]) + man[i].time[1] + man[i].rec.time) / 60);
		if ((man[i].time[1] + man[i].rec.time) % 60 < 10)//вывод времени до которого длится стрижка
			printf("0");
		printf("%i", (man[i].time[1] + man[i].rec.time) % 60);
	}
	printf("\n");
}

void record(time T[])
{
	system("cls");
	int i, j;
	int time_rec[2];// хранит введённое время
	int n;
	//fflush(stdin);
	printf("Введите имя и фамилию: ");
	getchar(); // есть \n в потоке
	gets(man[counter].name);//, 50, stdin);
	if (counter)
	{
		out_record();//вывод записей, если они есть
	}
	do {
		printf("\nВведите время, на которое хотите записаться(например 10 00): ");
		scanf("%i%i", &time_rec[0], &time_rec[1]);//ввод времени на которое хочет записаться пользователь
		if (time_rec[0] < begin || end <= time_rec[0])//если время выходит за рамки режима работы, то просим ввести время заново
			printf("\nВведите время в пределах %i - %i\n\n", begin, end);
	} while (time_rec[0] < begin || end <= time_rec[0]);//если время выходит за рамки режима работы, то запускаем ввод заново
	man[counter].time[0] = time_rec[0];//запись времени в массив записей(часов)
	man[counter].time[1] = time_rec[1];//запись времени в массив записей(минут)
	hr_out();//вывод списка стрижек, для выбора
	printf("\nВыберите прическу: ");
	scanf("%i", &n);//считывание номера стрижки
	n--;
	man[counter].rec = list[n];//копирование данных о стрижке
	i = (time_rec[0]-begin) * 60 + time_rec[1]; // сопоставляем время работы и записи
	if (T[i].min + list[n].time <= T[time_work - 1].min)//если стрижка не укладывается в режим работы, то не записываем
	{
		int flag = 0;
		for (j = i; j < T[i].min + list[n].time; j++)
		{
			if (T[j].pr == 1) flag = 1;
		}
		if (flag == 0)
		{
			for (j = i; j < T[i].min + list[n].time; j++)
			{
				T[j].pr = 1;
			}
			counter++;
		}
		else
		{
			printf("Вы не можете записаться на данное время!\n");
		}
		system("pause");
	}
	
}
