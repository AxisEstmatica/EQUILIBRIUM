#pragma once
#include "element.h"
class LINE
{
public:
	LINE();
	~LINE();
	void add(int val); // ���������� ��������
	int del(); // ���������� ��������
	int size();
	void output(); // ����� �������\��
	void copy(LINE& TMP); // ����������� �������
	void merge(LINE& MAIN, LINE& COPY); // ������� ��������
protected:
	ELMT *get_end(); // ����������� ��������� �� ��������� �������
private:
	ELMT *end; // ��������� �� ����� �������
	int NUM; // ���������� ��������� �������
};