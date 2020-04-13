#include "twolinelist.h"
TLINE::TLINE()
{
	NUM = 0;
	START = nullptr;
	END = nullptr;
	ptr = nullptr;
}
TLINE::~TLINE()
{
	while (NUM != 0)
	{
		ELMT *tmp = END;
		END = tmp->prev;
		delete tmp;
		--NUM;
	}
}
void TLINE::add_to_end(int val)
{
	ELMT* newelmt = new ELMT; // новый элемент
	if (START == nullptr)
	{
		START = newelmt;
	}
	if (END != nullptr)
	{
		END->next = newelmt;
	}
	newelmt->prev = END;
	END = newelmt;
	newelmt->value = val;
	newelmt->next = nullptr;
	++NUM;
}
void TLINE::erase()
{
	while (NUM != 0)
	{
		ELMT* tmp = END;
		if (tmp->prev == nullptr)
		{
			delete tmp;
			END = nullptr;
			START = nullptr;
			--NUM;
		}
		else
		{
			tmp = tmp->prev;
			delete tmp->next;
			END = tmp;
			--NUM;
		}
	}
	cout << "| Очищение списка завершено.\n";
}
void TLINE::ptr_on_start()
{
	if (START == nullptr)
	{
		cout << "| Список пуст.\n";
		return;
	}
	ptr = START;
}
void TLINE::ptr_right()
{
	if (START == nullptr)
	{
		cout << "| Список пуст.\n";
		return;
	}
	if (ptr == nullptr)
	{
		ptr = START;
	}
	if (ptr->next == nullptr)
	{
		cout << "| Достигнут конец списка.\n";
	}
	else
	{
		ptr = ptr->next;
	}
}
int TLINE::get_value()
{
	return ptr->value;
}
int TLINE::size()
{
	return NUM;
}
void TLINE::output()
{
	cout << "|";
	ELMT* tmp = END;
	int *MAS = new int[NUM];
	int i = NUM - 1;
	while (tmp->prev != nullptr)
	{
		MAS[i--] = tmp->value;
		tmp = tmp->prev;
	}
	MAS[i] = tmp->value;
	while (i < NUM - 1)
	{
		cout << " [" << MAS[i++] << "]";
	}
	cout << " [" << MAS[i] << "]" << endl;
	delete[] MAS;
}
bool operator < (int X, const TLINE& right)
{
	return X < right.ptr->value;
}
bool TLINE::operator < (int X)
{
	return ptr->value < X;
}
bool operator > (int X, const TLINE& right)
{
	return X > right.ptr->value;
}
bool TLINE::operator > (int X)
{
	return ptr->value > X;
}
bool operator == (int X, const TLINE& right)
{
	return X == right.ptr->value;
}
bool TLINE::operator == (int X)
{
	return ptr->value == X;
}
bool operator != (int X, const TLINE& right)
{
	return X != right.ptr->value;
}
bool TLINE::operator != (int X)
{
	return ptr->value != X;
}
bool operator <= (int X, const TLINE& right)
{
	return X <= right.ptr->value;
}
bool TLINE::operator <= (int X)
{
	return ptr->value <= X;
}
bool operator >= (int X, const TLINE& right)
{
	return X >= right.ptr->value;
}
bool TLINE::operator >= (int X)
{
	return ptr->value >= X;
}
TLINE& TLINE::operator ()(int X)
{
	if (X == 0)
	{
		output();
		return *this;
	}
	if (X > 0)
	{
		if (X > NUM)
		{
			output();
			return *this;
		}
		cout << "|";
		ELMT* tmp = START;
		int *MAS = new int[X];
		int i = 0;
		while (i < X - 1)
		{
			MAS[i++] = tmp->value;
			tmp = tmp->next;
		}
		MAS[i] = tmp->value;
		i = 0;
		while (i < X - 1)
		{
			cout << " [" << MAS[i++] << "]";
		}
		cout << " [" << MAS[i] << "]" << endl;
		delete[] MAS;
	}
	else
	{
		if (abs(X) > NUM)
		{
			output();
			return *this;
		}
		cout << "|";
		ELMT* tmp = END;
		int *MAS = new int[-X];
		int i = -X - 1;
		while (i > 0)
		{
			MAS[i--] = tmp->value;
			tmp = tmp->prev;
		}
		MAS[i] = tmp->value;
		while (i < -X - 1)
		{
			cout << " [" << MAS[i++] << "]";
		}
		cout << " [" << MAS[i] << "]" << endl;
		delete[] MAS;
	}
	return *this;
}
TLINE& TLINE::operator ()(int X, int Z)
{
	cout << "|";
	ELMT* tmp = START;
	int *MAS = new int[Z - X + 1];
	int i = 0;
	while (i < X - 1)
	{
		ptr_right(); ++i;
	}
	i = 0;
	while (i < Z - 1)
	{
		MAS[i++] = tmp->value;
		tmp = tmp->next;
	}
	MAS[i] = tmp->value;
	i = 0;
	while (i < Z - X)
	{
		cout << " [" << MAS[i++] << "]";
	}
	cout << " [" << MAS[i] << "]" << endl;
	delete[] MAS;
	return *this;
}
