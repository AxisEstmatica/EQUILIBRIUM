#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>
#define N 5
using namespace std;
class Abiturient
{
	string name1;
	string name2;
	string name3;
	string Adress;
	int marks[N];
	//float average_mark;
	//int sum;

public:
	int sum;
	void set()
	{
		cout << "������� �������" << endl;
		cin >> name1;
		cout << "������� ���" << endl;
		cin >> name2;
		cout << "������� ��������" << endl;
		cin >> name3;
		getchar();
		cout << "������� �����" << endl;
		getline(cin,Adress);
		sum = 0;
		for (int i = 0, *ptr = marks; i < N; ++i)
		{
			cout << "������� ������ �" << i+1 << ": " << endl;
			cin >> *(ptr + i);
			sum += *(ptr + i);
		}
		//cout << sum;///
		//average_mark = (float)sum / N;
		//cout << average_mark;///
	}
	void get()
	{
		cout << "�������: " << name1 << endl;
		cout << "���: " << name2 << endl;
		cout << "��������: " << name3 << endl;
		cout << "�����: " << Adress << endl;
		for (int i = 0, sum = 0; i < N; ++i)
			cout << "������ �" << i+1 << ": " << marks[i] << endl;
		cout << "����� ������: " << sum << endl;
	}
	// for getting information
	int get_marks(int i)
	{
		int *ptr = marks;
		return *(ptr+i);
	}
	int get_sum()
	{
		return sum;
	}
};

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	int menu_1 = 0;
	int cnt = 0;

	class Abiturient **UST; // objest
	UST = new Abiturient*[1];
	while (menu_1 != 2)
	{
		system("cls");
		cout << "����:\n  1:������ ��� ������ ����������� \n  2:������� � ���� ������" << endl;
		cin >> menu_1;

		switch (menu_1) {
		case 1:

			UST[0] = new Abiturient[cnt + 1];
			for (int i = 0; i < cnt; i++)
			{
				UST[0][i] = UST[1][i];

			}
			UST[1] = new Abiturient[cnt + 1];

			UST[0][cnt].set();
			for (int i = 0; i < cnt + 1; i++)
			{
				UST[1][i] = UST[0][i];
			}
			cnt++;
			break;
		}
	}
	int menu_2 = 0;
	int Ne;
	int max = -1; // for [1]
	int MX; // as max
	int pos;
	while (menu_2 != 5)
	{
		cout << "����:\n    1:������ ������������, ������� �������������������� ������ \n    2:������ ������������, ����� ������ � ������� �� ������ ��������\n    3:������� N ������������, ������� ����� ������� ����� ������\n    4:������ ������������, ������� ������������� ����\n    5:����� " << endl;
		cin >> menu_2;
		int cnt_1;
		system("cls");
		switch (menu_2)
		{
		case 1:
			cout << "������ ������������, ������� �������������������� ������ \n" << endl;
			for (int i = 0; i < cnt; i++)
			{
				Ne = 0;
				for (int j = 0; j < N; ++j)
					if (UST[0][i].get_marks(j) < 40)
						++Ne;
				if (Ne != 0)
				{
					UST[0][i].get();
					cout << endl;
				}
			}
			break;
		case 2:
			cout << "������ ������������, ����� ������ � ������� �� ������ ��������\n    ������� ����� ������: " << endl;
			cin >> Ne;
			for (int i = 0; i < cnt; i++)
			{
				if (UST[0][i].get_sum() >= Ne)
				{
					UST[0][i].get();
					cout << endl;
				}
			}
			break;
		case 3:
			cout << "������� N ������������, ������� ����� ������� ����� ������\n    ������� ���������� ������������: " << endl;
			cin >> Ne;
			Ne > cnt ? Ne = cnt : NULL;
			for (int i = 0, j; i < Ne; ++i)
			{
				for (j = 0, MX = 0, pos = 0; j < cnt; ++j)
				{
					if (UST[0][j].sum > MX && UST[0][j].sum != max)
					{
						MX = UST[0][j].sum;
						pos = j;
					}
				}
				UST[1][i] = UST[0][pos];
				max = UST[1][i].sum;
			}
			for (int i = 0; i < Ne; ++i)
			{
				UST[1][i].get();
			}

			break;
		case 4:
			cout << "������ ������������, ������� ������������� ����\n    ������� ��������� ����: " << endl;
			cin >> Ne;
			for (int i = 0; i < cnt; i++)
			{
				if (UST[0][i].get_sum() == Ne-1)
				{
					UST[0][i].get();
					cout << endl;
				}
			}
			break;
		}
	}
}