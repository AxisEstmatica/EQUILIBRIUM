#include "functions.h"
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	int menu = 0; // переменная меню
	int X = 0; // переменная для сравнения
	int Z = 5; // переменная для списка
	CEIL A(0);
	CEIL B(0);
	while (menu != 5)
	{
		system("cls");
		cout << "| Задание 1. Унарная операция. Работа с классом целых чисел.\n";
		cout << "| Введите номер одного из нижеперечисленных пунктов меню.\n";
		cout << "| Меню:\n";
		cout << "| [0]: Изменение значения B; B="; B.show(); cout << endl;
		cout << "| [1]: Оператор --(префикс, метод), уменьшение на 1. A=--B\n";
		cout << "| [2]: Оператор ++(префикс, метод), увеличение на 1. A=++B\n";
		cout << "| [3]: Оператор --(пост, дружественная ф-я), уменьшение на 2. A=B--\n";
		cout << "| [4]: Оператор ++(пост, дружественная ф-я), увеличение на 2. A=B++\n";
		cout << "| [5]: К заданию 2 -->" << endl;
		cout << "| ";
		cin >> menu;
		switch (menu)
		{
		case 0: cout << "| Активирован пункт 0" << endl;
			B(title_one());
			cout << "| Значение изменено" << endl;
			to_main_menu(); break;
		case 1: cout << "| Активирован пункт 1" << endl;
			cout << "| A="; A.show(); cout << " B="; B.show(); cout << endl;
			cout << "| A=--B"; A = --B;
			cout << "| A="; A.show(); cout << " B="; B.show(); cout << endl;
			to_main_menu(); break;
		case 2: cout << "| Активирован пункт 2" << endl;
			cout << "| A="; A.show(); cout << " B="; B.show(); cout << endl;
			cout << "| A=++B"; A = ++B;
			cout << "| A="; A.show(); cout << " B="; B.show(); cout << endl;
			to_main_menu(); break;
		case 3: cout << "| Активирован пункт 3" << endl;
			cout << "| A="; A.show(); cout << " B="; B.show(); cout << endl;
			cout << "| A=B--"; A = B--;
			cout << "| A="; A.show(); cout << " B="; B.show(); cout << endl;
			to_main_menu(); break;
		case 4: cout << "| Активирован пункт 4" << endl;
			cout << "| A="; A.show(); cout << " B="; B.show(); cout << endl;
			cout << "| A=B++"; A = B++;
			cout << "| A="; A.show(); cout << " B="; B.show(); cout << endl;
			to_main_menu(); break;
		case 5: cout << "| Активирован пункт 5" << endl; break;
		default:
			cout << "| Введено неверное значение." << endl;
			break;
		}
	}
	TLINE LIST_NAME;// = new TLINE;
	list_size(LIST_NAME, 10); // устанавливаем первоначальный размер
	int num; // для размера списка
	while (menu != 17)
	{
		system("cls");
		cout << "| Задание 2. Бинарная операция. Работа с двусвязным линейным списком (ДЛС).\n";
		cout << "| Введите номер одного из нижеперечисленных пунктов меню.\n";
		cout << "| Меню:\n";
		cout << "| [00]: Изменение значения X; X=" << X << endl;
		cout << "| [01]: Изменение значения Z; Z=" << Z << endl;
		cout << "| [02]: Изменение количества элементов списка. Заполняется случайными числами от -50 до 50.\n";
		cout << "| Текущее количество элементов списка: "; cout << LIST_NAME.size() << endl;
		cout << "| [03]: Перегрузка () ==> Вывод списка: { X=0 == [Весь список]} { X>0 == [Первые X элементов]} { X<0 == [Последние X элементов]}\n";
		cout << "| [04]: Перегрузка () ==> Вывод диапазона списка: от X до Z\n";
		cout << "| Сравнения: 1 - верно | 0 - неверно.\n";
		cout << "| [05]: ДЛС < X\n";
		cout << "| [06]: X < ДЛС\n";
		cout << "| [07]: ДЛС > X\n";
		cout << "| [08]: X > ДЛС\n";
		cout << "| [09]: ДЛС == X\n";
		cout << "| [10]: X == ДЛС\n";
		cout << "| [11]: ДЛС != X\n";
		cout << "| [12]: X != ДЛС\n";
		cout << "| [13]: ДЛС <= X\n";
		cout << "| [14]: X <= ДЛС\n";
		cout << "| [15]: ДЛС >= X\n";
		cout << "| [16]: X >= ДЛС\n";
		cout << "| [17]: Завершение работы программы -->||<" << endl;
		cout << "| ";
		cin >> menu;
		LIST_NAME.ptr_on_start(); // устанавливаем указатель списка на первый элемент
		switch (menu)
		{
		case 0: cout << "| Активирован пункт 0." << endl;
			cout << "| Введите новое значение X="; cin >> X;
			to_main_menu();
			break;
		case 1: cout << "| Активирован пункт 1." << endl;
			cout << "| Введите новое значение Z="; cin >> Z;
			to_main_menu();
			break;
		case 2: cout << "| Активирован пункт 2." << endl;
			cout << "| Введите новое количество элементов списка: "; cin >> num;
			if (num > 0)
			{
				list_size(LIST_NAME, num);
			}
			else
			{
				cout << "| Минимальное количество элементов списка: 1, изменения не были произведены." << endl;
			}
			to_main_menu();
			break;
		case 3: cout << "| Активирован пункт 3." << endl;
			if (abs(X) <= LIST_NAME.size())
			{
				cout << "| Вывод заданного диапазона:\n";
			}
			else
			{
				cout << "| Запрошенное значение превышает число элементов.\n| Вывод урезанного диапазона:\n";
			}
			LIST_NAME(X);
			to_main_menu();
			break;
		case 4: cout << "| Активирован пункт 4." << endl;
			if (X > 0 && Z >= X && Z <= LIST_NAME.size())
			{
				cout << "| Вывод заданного диапазона:\n"; LIST_NAME(X, Z);
			}
			else
			{
				cout << "| Запрошенный диапазон шире размера списка.\n";
				cout << "| Он должен находиться в его пределе, т.е. от 1 до " << LIST_NAME.size() << endl;
			}
			to_main_menu();
			break;
		case 5: cout << "| Активирован пункт 5." << endl;
			cout << "| ДЛС < X\n";
			for (int i = 0; i < LIST_NAME.size(); ++i)
			{
				cout << "| " << LIST_NAME.get_value() << " < " << X << " = "; num = LIST_NAME < X; cout << num << endl;
				LIST_NAME.ptr_right();
			}
			to_main_menu();
			break;
		case 6: cout << "| Активирован пункт 6." << endl;
			cout << "| X < ДЛС\n";
			for (int i = 0; i < LIST_NAME.size(); ++i)
			{
				cout << "| " << X << " < " << LIST_NAME.get_value() << " = "; num = X < LIST_NAME; cout << num << endl;
				LIST_NAME.ptr_right();
			}
			to_main_menu();
			break;
		case 7: cout << "| Активирован пункт 7." << endl;
			cout << "| ДЛС > X\n";
			for (int i = 0; i < LIST_NAME.size(); ++i)
			{
				cout << "| " << LIST_NAME.get_value() << " > " << X << " = "; num = LIST_NAME > X; cout << num << endl;
				LIST_NAME.ptr_right();
			}
			to_main_menu();
			break;
		case 8: cout << "| Активирован пункт 8." << endl;
			cout << "| X > ДЛС\n";
			for (int i = 0; i < LIST_NAME.size(); ++i)
			{
				cout << "| " << X << " > " << LIST_NAME.get_value() << " = "; num = X > LIST_NAME; cout << num << endl;
				LIST_NAME.ptr_right();
			}
			to_main_menu();
			break;
		case 9: cout << "| Активирован пункт 9." << endl;
			cout << "| ДЛС == X\n";
			for (int i = 0; i < LIST_NAME.size(); ++i)
			{
				cout << "| " << LIST_NAME.get_value() << " == " << X << " = "; num = LIST_NAME == X; cout << num << endl;
				LIST_NAME.ptr_right();
			}
			to_main_menu();
			break;
		case 10: cout << "| Активирован пункт 10." << endl;
			cout << "| X == ДЛС\n";
			for (int i = 0; i < LIST_NAME.size(); ++i)
			{
				cout << "| " << X << " == " << LIST_NAME.get_value() << " = "; num = X == LIST_NAME; cout << num << endl;
				LIST_NAME.ptr_right();
			}
			to_main_menu();
			break;
		case 11: cout << "| Активирован пункт 11." << endl;
			cout << "| ДЛС != X\n";
			for (int i = 0; i < LIST_NAME.size(); ++i)
			{
				cout << "| " << LIST_NAME.get_value() << " != " << X << " = "; num = LIST_NAME != X; cout << num << endl;
				LIST_NAME.ptr_right();
			}
			to_main_menu();
			break;
		case 12: cout << "| Активирован пункт 12." << endl;
			cout << "| X != ДЛС\n";
			for (int i = 0; i < LIST_NAME.size(); ++i)
			{
				cout << "| " << X << " != " << LIST_NAME.get_value() << " = "; num = X != LIST_NAME; cout << num << endl;
				LIST_NAME.ptr_right();
			}
			to_main_menu();
			break;
		case 13: cout << "| Активирован пункт 13." << endl;
			cout << "| ДЛС <= X\n";
			for (int i = 0; i < LIST_NAME.size(); ++i)
			{
				cout << "| " << LIST_NAME.get_value() << " <= " << X << " = "; num = LIST_NAME <= X; cout << num << endl;
				LIST_NAME.ptr_right();
			}
			to_main_menu();
			break;
		case 14: cout << "| Активирован пункт 14." << endl;
			cout << "| X <= ДЛС\n";
			for (int i = 0; i < LIST_NAME.size(); ++i)
			{
				cout << "| " << X << " <= " << LIST_NAME.get_value() << " = "; num = X <= LIST_NAME; cout << num << endl;
				LIST_NAME.ptr_right();
			}
			to_main_menu();
			break;
		case 15: cout << "| Активирован пункт 15." << endl;
			cout << "| ДЛС >= X\n";
			for (int i = 0; i < LIST_NAME.size(); ++i)
			{
				cout << "| " << LIST_NAME.get_value() << " >= " << X << " = "; num = LIST_NAME >= X; cout << num << endl;
				LIST_NAME.ptr_right();
			}
			to_main_menu();
			break;
		case 16: cout << "| Активирован пункт 16." << endl;
			cout << "| X >= ДЛС\n";
			for (int i = 0; i < LIST_NAME.size(); ++i)
			{
				cout << "| " << X << " >= " << LIST_NAME.get_value() << " = "; num = X >= LIST_NAME; cout << num << endl;
				LIST_NAME.ptr_right();
			}
			to_main_menu();
			break;
		case 17: cout << "| Завершение работы программы." << endl; break;
		default:
			cout << "| Введено неверное значение." << endl;
			break;
		}
	}
	return 0;
}