#include <iostream>
#include <string>
#include "functions.h"
using namespace std;
void to_main_menu()
{
	int menu;
	menu = 0;
	cout << "| ������� 4 ����� ��������� � ������� ����." << endl;
	while (menu != 4)
	{
		cout << "| ";
		cin >> menu;
	}
	return;
}