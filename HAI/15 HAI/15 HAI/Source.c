#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define begin 9//������ ������
#define end 21//����� ������

typedef struct {
	char name[40];//�������� 
	int time;//�����
}hairstyle;//�������� ��������

typedef struct {
	int min; // ����� � �������
	int pr; // ������ ��� ���
}time;//��������� �������� �������

typedef struct {
	char name[50];
	hairstyle rec; // ��������
	int time[2]; // ����� ������
}client;

int time_work = (end - begin) * 60;//����� ������ � �������
client man[30];//������ �������� �� ����
int counter = 0;//������� ������� �� ����
hairstyle list[10] = { "�������� �",30,"�������� �",40,"�������� �",50,"�������� �",60,"�������� �",65,"�������� �",45,"�������� �",82,"�������� �",23,"�������� �",54,"�������� �",23};
//������ �������� "��������, ����� ����������"

void record(time[]);//������ � ��������������
void delet(time[]);//�������� ������ �� ������
void out_record();//����� �� ����� ������ �������

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");//��� ���������� ������ ���������
	int a = 0;//���������� ��� switch
	time Time[(end - begin) * 60];//������ ������� ������ � �������
	int i = 0;//��� ������
	for (i = 0; i < time_work; i++)//������������� ������� ������ ��������������
	{
		Time[i].min = i;//����� ������
		Time[i].pr = 0;//���������� "��������/������"
	}
	while (a != 4)
	{
		system("cls");
		printf("�������� ��������\n\n");
		printf("1.���������� �� �������\n2.������� ������\n3.�������� �� ������\n4.�����\n");
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
			if (counter)//���� ������� ���, �� ������� ������
				delet(Time);//� ������� �������� �� ����������
			else
			{
				printf("\n������� ���!");
				system("pause");
			}

			break;
		case 4:
			break;
		default: printf("������� 1-4");
		}
	}
	system("pause");
	return 0;
}

void hr_out()//����� ������ �������� ��� ������
{
	int i;
	printf("��������\t\t����� ����������");
	for (i = 0; i < 10; i++)
	{
		printf("\n%2d.%s\t\t%i:%i", i + 1, list[i].name, list[i].time / 60, list[i].time % 60); // ���� : ������
	}
}

void delet(time T[])
{
	client x;//�������������� ����������
	int n, i;
	system("cls");
	out_record();//����� ������ �������
	do {
		printf("\n������� ���������� ����� ������ ��� ��������: ");
		scanf("%i", &n);//���� ������ ��������� ������
		if (n < 1 || counter < n)
			printf("������� ����� �� ������!\n");
	} while (n < 1 || counter < n);
	n--;
	i = 60 * (man[n].time[0] - begin) + man[n].time[1];
	for (; i < 60 * (man[n].time[0] - begin) + man[n].time[1] + man[n].rec.time; i++)
	{
		/*����������� ������ � "������� ������ �� �������" �� "����� ������ �� ������� + ����� ����� �������"*/
		T[i].pr = 0;//��� �������� ������ "�����������" �����, ������� ���� "������" � ������� ������ ��������������
		//printf("\n%i %i", T[i].min, T[i].pr);
	}

	if (n != counter - 1)//���� ��������� ������ �� ���������
	{
		x = man[n];//�� ������ �� � ��������� ������� 
		man[n] = man[counter - 1];
		man[counter - 1] = x;
	}
	system("pause");
	counter--;//��������� �������
}

void sort()
{//���������� ��������� �� ������� ������
	client x; // ���������� ��� ���������� ��������
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
{//����� ������� �� �����
	int i;
	printf("\n������:");
	sort();
	for (i = 0; i < counter; i++)
	{
		printf("\n%2d.%s ", i + 1, man[i].name);//����� �����
		printf("%i:", man[i].time[0]);//����� ����
		if (man[i].time[1] < 10)//���� ������ ����� 0-9
			printf("0");//�� ����������� 0 ������� ���� ���������� "9 00", � �� "9 0"
		printf("%i - ", man[i].time[1]);//����� �����
		printf("%i:", ((60 * man[i].time[0]) + man[i].time[1] + man[i].rec.time) / 60);
		if ((man[i].time[1] + man[i].rec.time) % 60 < 10)//����� ������� �� �������� ������ �������
			printf("0");
		printf("%i", (man[i].time[1] + man[i].rec.time) % 60);
	}
	printf("\n");
}

void record(time T[])
{
	system("cls");
	int i, j;
	int time_rec[2];// ������ �������� �����
	int n;
	//fflush(stdin);
	printf("������� ��� � �������: ");
	getchar(); // ���� \n � ������
	gets(man[counter].name);//, 50, stdin);
	if (counter)
	{
		out_record();//����� �������, ���� ��� ����
	}
	do {
		printf("\n������� �����, �� ������� ������ ����������(�������� 10 00): ");
		scanf("%i%i", &time_rec[0], &time_rec[1]);//���� ������� �� ������� ����� ���������� ������������
		if (time_rec[0] < begin || end <= time_rec[0])//���� ����� ������� �� ����� ������ ������, �� ������ ������ ����� ������
			printf("\n������� ����� � �������� %i - %i\n\n", begin, end);
	} while (time_rec[0] < begin || end <= time_rec[0]);//���� ����� ������� �� ����� ������ ������, �� ��������� ���� ������
	man[counter].time[0] = time_rec[0];//������ ������� � ������ �������(�����)
	man[counter].time[1] = time_rec[1];//������ ������� � ������ �������(�����)
	hr_out();//����� ������ �������, ��� ������
	printf("\n�������� ��������: ");
	scanf("%i", &n);//���������� ������ �������
	n--;
	man[counter].rec = list[n];//����������� ������ � �������
	i = (time_rec[0]-begin) * 60 + time_rec[1]; // ������������ ����� ������ � ������
	if (T[i].min + list[n].time <= T[time_work - 1].min)//���� ������� �� ������������ � ����� ������, �� �� ����������
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
			printf("�� �� ������ ���������� �� ������ �����!\n");
		}
		system("pause");
	}
	
}