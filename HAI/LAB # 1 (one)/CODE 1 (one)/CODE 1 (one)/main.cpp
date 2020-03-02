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
		cout << " Введите номер одного из нижеперечисленных пунктов меню.\n Меню:\n  1: Добавление элемента очереди.\n  2: Извлечение элемента очереди.\n  3: Вывод очереди на экран.\n  4: Вычисление требуемого значения (надо будет написать какого).\n  5: Создание копии очереди.\n  6: Слияние оригинальной очереди с копией и вывод результата на экран.\n  7: Выход из программы." << endl;
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << " Активирован пункт 1" << endl;
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
			cout << " Активирован пункт 2" << endl;
			if (NUM == 0)
				cout << " Очередь пуста, действие невозможно" << endl;
			to_main_menu();
			break;
		case 3:
			cout << " Активирован пункт 3" << endl;
			if (NUM == 0)
				cout << " Очередь пуста, действие невозможно" << endl;
			else
			{
				TMP_EL = NEW_EL;
				TMP_EL->output(*TMP_EL, NUM);
			}
			to_main_menu();
			break;
		case 4:
			cout << " Активирован пункт 4" << endl;
			if (NUM == 0)
				cout << " Очередь пуста, действие невозможно" << endl;
			to_main_menu();
			break;
		case 5:
			cout << " Активирован пункт 5" << endl;
			if (NUM == 0)
				cout << " Очередь пуста, действие невозможно" << endl;
			to_main_menu();
			break;
		case 6:
			cout << " Активирован пункт 6" << endl;
			if (NUM == 0)
				cout << " Очередь пуста, действие невозможно" << endl;
			to_main_menu();
			break;
		}
	}
	cout << " Работа программы завершена" << endl;
	return 0;
}