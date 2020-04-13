#include "functions.h"
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	int menu = 0; // ���������� ����
	int X = 0; // ���������� ��� ���������
	int Z = 5; // ���������� ��� ������
	CEIL A(0);
	CEIL B(0);
	while (menu != 5)
	{
		system("cls");
		cout << "| ������� 1. ������� ��������. ������ � ������� ����� �����.\n";
		cout << "| ������� ����� ������ �� ����������������� ������� ����.\n";
		cout << "| ����:\n";
		cout << "| [0]: ��������� �������� B; B="; B.show(); cout << endl;
		cout << "| [1]: �������� --(�������, �����), ���������� �� 1. A=--B\n";
		cout << "| [2]: �������� ++(�������, �����), ���������� �� 1. A=++B\n";
		cout << "| [3]: �������� --(����, ������������� �-�), ���������� �� 2. A=B--\n";
		cout << "| [4]: �������� ++(����, ������������� �-�), ���������� �� 2. A=B++\n";
		cout << "| [5]: � ������� 2 -->" << endl;
		cout << "| ";
		cin >> menu;
		switch (menu)
		{
		case 0: cout << "| ����������� ����� 0" << endl;
			B(title_one());
			cout << "| �������� ��������" << endl;
			to_main_menu(); break;
		case 1: cout << "| ����������� ����� 1" << endl;
			cout << "| A="; A.show(); cout << " B="; B.show(); cout << endl;
			cout << "| A=--B"; A = --B;
			cout << "| A="; A.show(); cout << " B="; B.show(); cout << endl;
			to_main_menu(); break;
		case 2: cout << "| ����������� ����� 2" << endl;
			cout << "| A="; A.show(); cout << " B="; B.show(); cout << endl;
			cout << "| A=++B"; A = ++B;
			cout << "| A="; A.show(); cout << " B="; B.show(); cout << endl;
			to_main_menu(); break;
		case 3: cout << "| ����������� ����� 3" << endl;
			cout << "| A="; A.show(); cout << " B="; B.show(); cout << endl;
			cout << "| A=B--"; A = B--;
			cout << "| A="; A.show(); cout << " B="; B.show(); cout << endl;
			to_main_menu(); break;
		case 4: cout << "| ����������� ����� 4" << endl;
			cout << "| A="; A.show(); cout << " B="; B.show(); cout << endl;
			cout << "| A=B++"; A = B++;
			cout << "| A="; A.show(); cout << " B="; B.show(); cout << endl;
			to_main_menu(); break;
		case 5: cout << "| ����������� ����� 5" << endl; break;
		default:
			cout << "| ������� �������� ��������." << endl;
			break;
		}
	}
	TLINE LIST_NAME;// = new TLINE;
	list_size(LIST_NAME, 10); // ������������� �������������� ������
	int num; // ��� ������� ������
	while (menu != 17)
	{
		system("cls");
		cout << "| ������� 2. �������� ��������. ������ � ���������� �������� ������� (���).\n";
		cout << "| ������� ����� ������ �� ����������������� ������� ����.\n";
		cout << "| ����:\n";
		cout << "| [00]: ��������� �������� X; X=" << X << endl;
		cout << "| [01]: ��������� �������� Z; Z=" << Z << endl;
		cout << "| [02]: ��������� ���������� ��������� ������. ����������� ���������� ������� �� -50 �� 50.\n";
		cout << "| ������� ���������� ��������� ������: "; cout << LIST_NAME.size() << endl;
		cout << "| [03]: ���������� () ==> ����� ������: { X=0 == [���� ������]} { X>0 == [������ X ���������]} { X<0 == [��������� X ���������]}\n";
		cout << "| [04]: ���������� () ==> ����� ��������� ������: �� X �� Z\n";
		cout << "| ���������: 1 - ����� | 0 - �������.\n";
		cout << "| [05]: ��� < X\n";
		cout << "| [06]: X < ���\n";
		cout << "| [07]: ��� > X\n";
		cout << "| [08]: X > ���\n";
		cout << "| [09]: ��� == X\n";
		cout << "| [10]: X == ���\n";
		cout << "| [11]: ��� != X\n";
		cout << "| [12]: X != ���\n";
		cout << "| [13]: ��� <= X\n";
		cout << "| [14]: X <= ���\n";
		cout << "| [15]: ��� >= X\n";
		cout << "| [16]: X >= ���\n";
		cout << "| [17]: ���������� ������ ��������� -->||<" << endl;
		cout << "| ";
		cin >> menu;
		LIST_NAME.ptr_on_start(); // ������������� ��������� ������ �� ������ �������
		switch (menu)
		{
		case 0: cout << "| ����������� ����� 0." << endl;
			cout << "| ������� ����� �������� X="; cin >> X;
			to_main_menu();
			break;
		case 1: cout << "| ����������� ����� 1." << endl;
			cout << "| ������� ����� �������� Z="; cin >> Z;
			to_main_menu();
			break;
		case 2: cout << "| ����������� ����� 2." << endl;
			cout << "| ������� ����� ���������� ��������� ������: "; cin >> num;
			if (num > 0)
			{
				list_size(LIST_NAME, num);
			}
			else
			{
				cout << "| ����������� ���������� ��������� ������: 1, ��������� �� ���� �����������." << endl;
			}
			to_main_menu();
			break;
		case 3: cout << "| ����������� ����� 3." << endl;
			if (abs(X) <= LIST_NAME.size())
			{
				cout << "| ����� ��������� ���������:\n";
			}
			else
			{
				cout << "| ����������� �������� ��������� ����� ���������.\n| ����� ���������� ���������:\n";
			}
			LIST_NAME(X);
			to_main_menu();
			break;
		case 4: cout << "| ����������� ����� 4." << endl;
			if (X > 0 && Z >= X && Z <= LIST_NAME.size())
			{
				cout << "| ����� ��������� ���������:\n"; LIST_NAME(X, Z);
			}
			else
			{
				cout << "| ����������� �������� ���� ������� ������.\n";
				cout << "| �� ������ ���������� � ��� �������, �.�. �� 1 �� " << LIST_NAME.size() << endl;
			}
			to_main_menu();
			break;
		case 5: cout << "| ����������� ����� 5." << endl;
			cout << "| ��� < X\n";
			for (int i = 0; i < LIST_NAME.size(); ++i)
			{
				cout << "| " << LIST_NAME.get_value() << " < " << X << " = "; num = LIST_NAME < X; cout << num << endl;
				LIST_NAME.ptr_right();
			}
			to_main_menu();
			break;
		case 6: cout << "| ����������� ����� 6." << endl;
			cout << "| X < ���\n";
			for (int i = 0; i < LIST_NAME.size(); ++i)
			{
				cout << "| " << X << " < " << LIST_NAME.get_value() << " = "; num = X < LIST_NAME; cout << num << endl;
				LIST_NAME.ptr_right();
			}
			to_main_menu();
			break;
		case 7: cout << "| ����������� ����� 7." << endl;
			cout << "| ��� > X\n";
			for (int i = 0; i < LIST_NAME.size(); ++i)
			{
				cout << "| " << LIST_NAME.get_value() << " > " << X << " = "; num = LIST_NAME > X; cout << num << endl;
				LIST_NAME.ptr_right();
			}
			to_main_menu();
			break;
		case 8: cout << "| ����������� ����� 8." << endl;
			cout << "| X > ���\n";
			for (int i = 0; i < LIST_NAME.size(); ++i)
			{
				cout << "| " << X << " > " << LIST_NAME.get_value() << " = "; num = X > LIST_NAME; cout << num << endl;
				LIST_NAME.ptr_right();
			}
			to_main_menu();
			break;
		case 9: cout << "| ����������� ����� 9." << endl;
			cout << "| ��� == X\n";
			for (int i = 0; i < LIST_NAME.size(); ++i)
			{
				cout << "| " << LIST_NAME.get_value() << " == " << X << " = "; num = LIST_NAME == X; cout << num << endl;
				LIST_NAME.ptr_right();
			}
			to_main_menu();
			break;
		case 10: cout << "| ����������� ����� 10." << endl;
			cout << "| X == ���\n";
			for (int i = 0; i < LIST_NAME.size(); ++i)
			{
				cout << "| " << X << " == " << LIST_NAME.get_value() << " = "; num = X == LIST_NAME; cout << num << endl;
				LIST_NAME.ptr_right();
			}
			to_main_menu();
			break;
		case 11: cout << "| ����������� ����� 11." << endl;
			cout << "| ��� != X\n";
			for (int i = 0; i < LIST_NAME.size(); ++i)
			{
				cout << "| " << LIST_NAME.get_value() << " != " << X << " = "; num = LIST_NAME != X; cout << num << endl;
				LIST_NAME.ptr_right();
			}
			to_main_menu();
			break;
		case 12: cout << "| ����������� ����� 12." << endl;
			cout << "| X != ���\n";
			for (int i = 0; i < LIST_NAME.size(); ++i)
			{
				cout << "| " << X << " != " << LIST_NAME.get_value() << " = "; num = X != LIST_NAME; cout << num << endl;
				LIST_NAME.ptr_right();
			}
			to_main_menu();
			break;
		case 13: cout << "| ����������� ����� 13." << endl;
			cout << "| ��� <= X\n";
			for (int i = 0; i < LIST_NAME.size(); ++i)
			{
				cout << "| " << LIST_NAME.get_value() << " <= " << X << " = "; num = LIST_NAME <= X; cout << num << endl;
				LIST_NAME.ptr_right();
			}
			to_main_menu();
			break;
		case 14: cout << "| ����������� ����� 14." << endl;
			cout << "| X <= ���\n";
			for (int i = 0; i < LIST_NAME.size(); ++i)
			{
				cout << "| " << X << " <= " << LIST_NAME.get_value() << " = "; num = X <= LIST_NAME; cout << num << endl;
				LIST_NAME.ptr_right();
			}
			to_main_menu();
			break;
		case 15: cout << "| ����������� ����� 15." << endl;
			cout << "| ��� >= X\n";
			for (int i = 0; i < LIST_NAME.size(); ++i)
			{
				cout << "| " << LIST_NAME.get_value() << " >= " << X << " = "; num = LIST_NAME >= X; cout << num << endl;
				LIST_NAME.ptr_right();
			}
			to_main_menu();
			break;
		case 16: cout << "| ����������� ����� 16." << endl;
			cout << "| X >= ���\n";
			for (int i = 0; i < LIST_NAME.size(); ++i)
			{
				cout << "| " << X << " >= " << LIST_NAME.get_value() << " = "; num = X >= LIST_NAME; cout << num << endl;
				LIST_NAME.ptr_right();
			}
			to_main_menu();
			break;
		case 17: cout << "| ���������� ������ ���������." << endl; break;
		default:
			cout << "| ������� �������� ��������." << endl;
			break;
		}
	}
	return 0;
}