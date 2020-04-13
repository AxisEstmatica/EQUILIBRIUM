#include "functions.h"
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
int title_one()
{
	int value = 0;
	cout << "| Введите начальное значение B." << endl;
	cout << "| ";
	cin >> value;
	return value;
}
void list_size(TLINE &LIST_NAME, int size)
{
	srand(time(0));
	if (LIST_NAME.size())
	{
		LIST_NAME.erase();
	}
	for (int i = 0; i < size; ++i)
	{
		LIST_NAME.add_to_end(rand() % 101 - 50);
	}
	return;
}
