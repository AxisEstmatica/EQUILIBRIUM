#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>
#define N 3
using namespace std;
class Abiturient
{
	string name1;
	string name2;
	string name3;
	string Adress;
	int marks[N];

public:
	int sum;
	void set()
	{
		cout << "Введите Фамилию" << endl;
		cin >> name1;
		cout << "Введите Имя" << endl;
		cin >> name2;
		cout << "Введите Отчество" << endl;
		cin >> name3;
		getchar();
		cout << "Введите адрес" << endl;
		getline(cin,Adress);
		sum = 0;
		for (int i = 0, *ptr = marks; i < N; ++i)
		{
			cout << "Введите оценку №" << i+1 << ": " << endl;
			cin >> *(ptr + i);
			sum += *(ptr + i);
		}
	}
	void get()
	{
		cout << "Фамилия: " << name1 << endl;
		cout << "Имя: " << name2 << endl;
		cout << "Отчество: " << name3 << endl;
		cout << "Адрес: " << Adress << endl;
		for (int i = 0, sum = 0; i < N; ++i)
			cout << "Оценка №" << i+1 << ": " << marks[i] << endl;
		cout << "Сумма баллов: " << sum << endl;
	}
	// for getting information
	int get_marks(int i)
	{
		int *ptr = marks;
		return *(ptr+i);
	}
	void ret_sum()
	{
		sum = 0;
		for (int i = 0, *ptr = marks; i < N; ++i)
		{
			sum += *(ptr + i);
		}
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
		cout << "Меню:\n  1:Ввести еще одного абитуриента \n  2:Перейти в меню поиска" << endl;
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
	int MX; // as max
	int pos;
	while (menu_2 != 5)
	{
		cout << "Меню:\n    1:Список абитуриентов, имеющих неудовлетворительные оценки \n    2:Список абитуриентов, сумма баллов у которых не меньше заданной\n    3:Выбрать N абитуриентов, имеющих самую высокую сумму баллов\n    4:Список абитуриентов, имеющих полупроходной балл\n    5:выход " << endl;
		cin >> menu_2;
		int cnt_1;
		system("cls");
		switch (menu_2)
		{
		case 1:
			cout << "Список абитуриентов, имеющих неудовлетворительные оценки \n" << endl;
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
			cout << "Список абитуриентов, сумма баллов у которых не меньше заданной\n    Введите сумму баллов: " << endl;
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
			cout << "Выбрать N абитуриентов, имеющих самую высокую сумму баллов\n    Введите количество абитуриентов: " << endl;
			cin >> Ne;
			Ne > cnt ? Ne = cnt : NULL;
			for (int i = 0, j; i < Ne; ++i)
			{
				for (j = 0, MX = 0, pos = 0; j < cnt; ++j)
				{
					if (UST[0][j].sum > MX)
					{
						MX = UST[0][j].sum;
						pos = j;
					}
				}
				UST[1][i] = UST[0][pos];
				UST[0][pos].sum = 0;
			}
			for (int i = 0; i < Ne; ++i)
			{
				UST[1][i].get();
			}
			for (int i = 0; i < cnt; ++i)
			{
				UST[0][i].ret_sum();
			}
			break;
		case 4:
			cout << "Список абитуриентов, имеющих полупроходной балл\n    Введите проходной балл: " << endl;
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
