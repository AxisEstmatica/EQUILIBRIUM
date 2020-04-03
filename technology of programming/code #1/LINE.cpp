#include <iostream>
#include "LINE.h"
using namespace std;
LINE::LINE()
{
	end = nullptr;
	NUM = 0;
}

LINE::~LINE()
{
	while (NUM != 0)
	{
		ELMT *tmp = end;
		end = tmp->prev;
		delete tmp;
		--NUM;
	}
}

void LINE::add(int val)
{
	ELMT* dimension = new ELMT; // отправляем данные в свободное плавание
	dimension->prev = end;
	end = dimension;
	dimension->value = val;
	++NUM;
}

int LINE::del()
{
	int tmp_val;
	ELMT* tmp = end;
	if (tmp->prev == nullptr)
	{
		tmp_val = tmp->value;
		delete tmp;
		end = nullptr;
		--NUM;
	}
	else
	{
		while (tmp->prev->prev != nullptr)
		{
			tmp = (tmp->prev);
		}
		tmp_val = (tmp->prev->value);
		delete tmp->prev;
		tmp->prev = nullptr;
		--NUM;
	}
	cout << "| Извлечён первый элемент со значением: [" << tmp_val << "]" << endl;
	return tmp_val;
}

void LINE::output()
{
	ELMT* tmp = end;
	int *MAS = new int[NUM];
	int i = NUM-1;
	while (tmp->prev != nullptr)
	{
		MAS[i--] = tmp->value;
		tmp = tmp->prev;
	}
	MAS[i] = tmp->value;
	while (i < NUM-1)
	{
		cout << " [" << MAS[i++] << "]";
	}
	cout << " [" << MAS[i] << "]" << endl;
	delete[] MAS;
}

void LINE::copy(LINE& TMP)
{
	while (this->size()) // очищение очереди
	{
		this->del();
	}
	int cnt = TMP.size();
	int* MAS = new int[cnt];
	ELMT* line_ptr = TMP.get_end();
	for (int i = cnt; i-- > 0;)
	{
		MAS[i] = line_ptr->value;
		line_ptr = line_ptr->prev;
	}
	for (int i = 0; i < cnt; ++i)
	{
		this->add(MAS[i]);
	}
	delete[] MAS;
}

void LINE::merge(LINE& MAIN, LINE& COPY)
{
	while (this->size()) // очищение очереди
	{
		this->del();
	}
	int cnt1 = MAIN.size();
	int cnt2 = COPY.size();
	int* MAS = new int[cnt1+cnt2];
	ELMT* line_ptr = COPY.get_end();
	for (int i = cnt1 + cnt2; i-- > cnt1;)
	{
		MAS[i] = line_ptr->value;
		line_ptr = line_ptr->prev;
	}
	line_ptr = MAIN.get_end();
	for (int i = cnt1; i-- > 0;)
	{
		MAS[i] = line_ptr->value;
		line_ptr = line_ptr->prev;
	}
	for (int i = 0; i < cnt1 + cnt2; ++i)
	{
		this->add(MAS[i]);
	}
	delete[] MAS;
}

int LINE::size()
{
	return NUM;
}

ELMT* LINE::get_end()
{
	return end;
}