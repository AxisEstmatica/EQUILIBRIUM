#include "functions.h"
#include <iostream>
//#include "line_description.h"
using namespace std;
void to_main_menu()
{
	int menu;
	menu = 0;
	cout << " Нажмите 4 чтобы вернуться в главное меню." << endl;
	while (menu != 4)
		cin >> menu;
	return;
}
void add(LINE &NEW_EL, int NUM) // add NEW element
{
	NEW_EL.get(NUM, NEW_EL);
}