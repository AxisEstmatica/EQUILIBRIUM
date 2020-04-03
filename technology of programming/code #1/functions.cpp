#include <iostream>
#include <string>
#include "functions.h"
using namespace std;
void to_main_menu()
{
	int menu;
	menu = 0;
	cout << "| Введите 4 чтобы вернуться в главное меню." << endl;
	while (menu != 4)
	{
		cout << "| ";
		cin >> menu;
	}
	return;
}
