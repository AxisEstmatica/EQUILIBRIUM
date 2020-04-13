#pragma once
#include "element.h"
#include <iostream>
using namespace std;
class TLINE // класс двусвязного линейного списка (ДЛС)
{
public:
	TLINE();
	~TLINE();
	void add_to_end(int val); // добавление элемента в конец ДЛС
	void erase(); // удаление списка
	void ptr_on_start();
	void ptr_right();
	int size();
	void output();
	int get_value();
	friend bool operator < (int X, const TLINE& right);
	bool operator < (int X);
	friend bool operator > (int X, const TLINE& right);
	bool operator > (int X);
	friend bool operator == (int X, const TLINE& right);
	bool operator == (int X);
	friend bool operator <= (int X, const TLINE& right);
	bool operator <= (int X);
	friend bool operator >= (int X, const TLINE& right);
	bool operator >= (int X);
	friend bool operator != (int X, const TLINE& right);
	bool operator != (int X);
	TLINE& operator ()(int X); // перегрузка чтоб принималась ф-я
	TLINE& operator ()(int X, int Z); // перегрузка чтоб принималась ф-я
private:
	int NUM; // кол-во элементов ДЛС
	ELMT *START;
	ELMT *END;
	ELMT *ptr; // указатель на рабочий элемент ДЛС
};
