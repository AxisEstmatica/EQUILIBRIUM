#include <iostream>
#include "functions.h"
using namespace std;
#define ARR 3 // ���������� ��������
template <class QI>

void qi_processing(QI *LINE)
{
	int NUM = 0; // number of elements
	int value = 0;
	int menu = 0; // ���������� ����
	while (menu != 7)
	{
		system("cls");
		cout << "| ������� ����� ������ �� ����������������� ������� ����.\n";
		cout << "| ����:\n";
		cout << "| [1]: ���������� �������� � �������� �������.\n";
		cout << "| [2]: ���������� �������� �� �������� �������.\n";
		cout << "| [3]: ����� �������� �� �����.\n";
		cout << "| [4]: ���������� �������� ��������������.\n";
		cout << "| [5]: �������� ����� �������� �������.\n";
		cout << "| [6]: ������� �������� ������� � ������ � ����� ���������� �� �����.\n";
		cout << "| [7]: ����� �� ���������." << endl;
		cout << "| ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "| ����������� ����� 1" << endl;
			cout << "| ������� ��������, ����������� � �������� �������: ";
			cin >> value;
			LINE[0].add(value);
			to_main_menu(); // exit to main menu
			break;
		case 2:
			cout << "| ����������� ����� 2" << endl;
			NUM = LINE[0].size();
			if (NUM == 0)
			{
				cout << "| �������� ������� �����, �������� ����������." << endl;
			}
			else
			{
				LINE[0].del();
			}
				to_main_menu();
			break;
		case 3:
			cout << "| ����������� ����� 3" << endl;
			NUM = LINE[0].size();
			if (NUM == 0)
				cout << "| ��������: [empty]" << endl;
				else
			{
				cout << "| ��������:";
				LINE[0].output();
			}
			NUM = LINE[1].size();
			if (NUM == 0)
				cout << "| �����:    [empty]" << endl;
			else
			{
				cout << "| �����:   ";
				LINE[1].output();
			}
			NUM = LINE[2].size();
			if (NUM == 0)
				cout << "| �������:  [empty]" << endl;
			else
			{
				cout << "| �������: ";
				LINE[2].output();
			}
			to_main_menu();
			break;
		case 4:
			cout << "| ����������� ����� 4" << endl;
			NUM = LINE[0].size();
			if (NUM == 0)
				cout << "| ��������: [empty]" << endl;
			else
			{
				cout << "| ��������: " << LINE[0].harmonic_avg() << endl;
			}
			NUM = LINE[1].size();
			if (NUM == 0)
				cout << "| �����:    [empty]" << endl;
			else
			{
				cout << "| �����:    " << LINE[1].harmonic_avg() << endl;
			}
			NUM = LINE[2].size();
			if (NUM == 0)
				cout << "| �������:  [empty]" << endl;
			else
			{
				cout << "| �������:  " << LINE[2].harmonic_avg() << endl;
			}
			to_main_menu();
			break;
		case 5:
			cout << "| ����������� ����� 5" << endl;
			NUM = LINE[0].size();
			if (NUM == 0)
			{
				cout << "| ������� �����, �������� ����������." << endl;
			}
			else
			{
				LINE[1].copy(LINE[0]);
				cout << "| ����� ���������." << endl;
			}
			to_main_menu();
			break;
		case 6:
			cout << "| ����������� ����� 6" << endl;
			if (!LINE[0].size() || !LINE[1].size())
			{
				cout << "| �� �������� �������� � ������������� �������� �������� �� ��������." << endl;
			}
			else
			{
				LINE[2].merge(LINE[0], LINE[1]);
				cout << "| ������� �����������." << endl;
			}
			to_main_menu();
			break;
		}
	}
	cout << "| ������ ��������� ���������" << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	LINE_PUB *QI1 = NULL;
	LINE_PRO *QI2 = NULL;
	LINE_PRI *QI3 = NULL;
	int menu = 0;
	system("cls");
	cout << "| ������� ����� ���� ������������ ������������ ������:\n| [1]: Public\n| [2]: Protected \n| [3]: Private" << endl;
	cout << "| ";
	cin >> menu;
	switch (menu)
	{
	case 1: QI1 = new LINE_PUB[ARR];
		qi_processing(QI1);
		delete[] QI1;
		break;
	case 2: QI2 = new LINE_PRO[ARR];
		qi_processing(QI2);
		delete[] QI2;
		break;
	case 3: QI3 = new LINE_PRI[ARR];
		qi_processing(QI3);
		delete[] QI3;
		break;
	default:
		cout << "| ������� �������� ��������, ���������� ���������." << endl;
		break;
	}
	return 0;
}