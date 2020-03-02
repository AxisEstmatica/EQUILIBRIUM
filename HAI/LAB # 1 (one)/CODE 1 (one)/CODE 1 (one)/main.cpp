#include <iostream>
//#include <fstream>
//#include <ctime>
#include <string>
#include <windows.h>
#include "line_description.h"
#include "functions.h"
using namespace std;
//#define N 10
//#define YES 1
//#define NO 0


int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	int NUM = 0; // number of elements
	class LINE *NEW_EL = new LINE; // new element
	class LINE *TMP_EL; // temporary element
	//LINE **prev_ptr; // address of previous element
	int menu = 0;
	while (menu != 7)
	{
		system("cls");
		cout << " ������� ����� ������ �� ����������������� ������� ����.\n ����:\n  1: ���������� �������� �������.\n  2: ���������� �������� �������.\n  3: ����� ������� �� �����.\n  4: ���������� ���������� �������� (���� ����� �������� ������).\n  5: �������� ����� �������.\n  6: ������� ������������ ������� � ������ � ����� ���������� �� �����.\n  7: ����� �� ���������." << endl;
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << " ����������� ����� 1" << endl;
			//prev_ptr = &NEW_EL;
			TMP_EL = NEW_EL; // data of previous element copy to temporary element
			cout << "  " << &NEW_EL << "  " << &TMP_EL << endl; // debug
			if (NUM != 0)
				LINE *NEW_EL = new LINE;
			cout << "  " << &NEW_EL << "  " << &TMP_EL << endl; // debug
			//TMP_EL = NEW_EL; // data of previous element copy to temporary element
			add(*NEW_EL, NUM); // get new element of the line
			++NUM; // increase our line length
			to_main_menu(); // exit to main menu
			break;
		case 2:
			cout << " ����������� ����� 2" << endl;
			if (NUM == 0)
				cout << " ������� �����, �������� ����������" << endl;
			to_main_menu();
			break;
		case 3:
			cout << " ����������� ����� 3" << endl;
			if (NUM == 0)
				cout << " ������� �����, �������� ����������" << endl;
			else
			{
				TMP_EL = NEW_EL;
				TMP_EL->output(*TMP_EL, NUM);
			}
			to_main_menu();
			break;
		case 4:
			cout << " ����������� ����� 4" << endl;
			if (NUM == 0)
				cout << " ������� �����, �������� ����������" << endl;
			to_main_menu();
			break;
		case 5:
			cout << " ����������� ����� 5" << endl;
			if (NUM == 0)
				cout << " ������� �����, �������� ����������" << endl;
			to_main_menu();
			break;
		case 6:
			cout << " ����������� ����� 6" << endl;
			if (NUM == 0)
				cout << " ������� �����, �������� ����������" << endl;
			to_main_menu();
			break;
		}
	}
	cout << " ������ ��������� ���������" << endl;
	return 0;
}