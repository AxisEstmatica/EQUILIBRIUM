#pragma once
#include "element.h"
#include <iostream>
using namespace std;
class TLINE // ����� ����������� ��������� ������ (���)
{
public:
	TLINE();
	~TLINE();
	void add_to_end(int val); // ���������� �������� � ����� ���
	void erase(); // �������� ������
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
	TLINE& operator ()(int X); // ���������� ���� ����������� �-�
	TLINE& operator ()(int X, int Z); // ���������� ���� ����������� �-�
private:
	int NUM; // ���-�� ��������� ���
	ELMT *START;
	ELMT *END;
	ELMT *ptr; // ��������� �� ������� ������� ���
};