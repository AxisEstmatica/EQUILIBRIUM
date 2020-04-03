#include <iostream>
#include "functions.h"
using namespace std;
#define ARR 3 // количество очередей
template <class QI>

void qi_processing(QI *LINE)
{
	int NUM = 0; // number of elements
	int value = 0;
	int menu = 0; // переменная меню
	while (menu != 7)
	{
		system("cls");
		cout << "| Введите номер одного из нижеперечисленных пунктов меню.\n";
		cout << "| Меню:\n";
		cout << "| [1]: Добавление элемента к основной очереди.\n";
		cout << "| [2]: Извлечение элемента из основной очереди.\n";
		cout << "| [3]: Вывод очередей на экран.\n";
		cout << "| [4]: Вычисление среднего гармонического.\n";
		cout << "| [5]: Создание копии основной очереди.\n";
		cout << "| [6]: Слияние основной очереди с копией и вывод результата на экран.\n";
		cout << "| [7]: Выход из программы." << endl;
		cout << "| ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "| Активирован пункт 1" << endl;
			cout << "| Введите значение, добавляемое к ОСНОВНОЙ очереди: ";
			cin >> value;
			LINE[0].add(value);
			to_main_menu(); // exit to main menu
			break;
		case 2:
			cout << "| Активирован пункт 2" << endl;
			NUM = LINE[0].size();
			if (NUM == 0)
			{
				cout << "| Основная очередь пуста, действие невозможно." << endl;
			}
			else
			{
				LINE[0].del();
			}
				to_main_menu();
			break;
		case 3:
			cout << "| Активирован пункт 3" << endl;
			NUM = LINE[0].size();
			if (NUM == 0)
				cout << "| Основная: [empty]" << endl;
				else
			{
				cout << "| Основная:";
				LINE[0].output();
			}
			NUM = LINE[1].size();
			if (NUM == 0)
				cout << "| Копия:    [empty]" << endl;
			else
			{
				cout << "| Копия:   ";
				LINE[1].output();
			}
			NUM = LINE[2].size();
			if (NUM == 0)
				cout << "| Слияние:  [empty]" << endl;
			else
			{
				cout << "| Слияние: ";
				LINE[2].output();
			}
			to_main_menu();
			break;
		case 4:
			cout << "| Активирован пункт 4" << endl;
			NUM = LINE[0].size();
			if (NUM == 0)
				cout << "| Основная: [empty]" << endl;
			else
			{
				cout << "| Основная: " << LINE[0].harmonic_avg() << endl;
			}
			NUM = LINE[1].size();
			if (NUM == 0)
				cout << "| Копия:    [empty]" << endl;
			else
			{
				cout << "| Копия:    " << LINE[1].harmonic_avg() << endl;
			}
			NUM = LINE[2].size();
			if (NUM == 0)
				cout << "| Слияние:  [empty]" << endl;
			else
			{
				cout << "| Слияние:  " << LINE[2].harmonic_avg() << endl;
			}
			to_main_menu();
			break;
		case 5:
			cout << "| Активирован пункт 5" << endl;
			NUM = LINE[0].size();
			if (NUM == 0)
			{
				cout << "| Очередь пуста, действие невозможно." << endl;
			}
			else
			{
				LINE[1].copy(LINE[0]);
				cout << "| Копия обновлена." << endl;
			}
			to_main_menu();
			break;
		case 6:
			cout << "| Активирован пункт 6" << endl;
			if (!LINE[0].size() || !LINE[1].size())
			{
				cout << "| До создания основной и скопированной очередей действие не возможно." << endl;
			}
			else
			{
				LINE[2].merge(LINE[0], LINE[1]);
				cout << "| Слияние произведено." << endl;
			}
			to_main_menu();
			break;
		}
	}
	cout << "| Работа программы завершена" << endl;
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
	cout << "| Введите номер типа наследования производного класса:\n| [1]: Public\n| [2]: Protected \n| [3]: Private" << endl;
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
		cout << "| Введено неверное значение, завершение программы." << endl;
		break;
	}
	return 0;
}