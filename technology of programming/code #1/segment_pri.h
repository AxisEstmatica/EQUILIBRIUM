#pragma once
#include "LINE.h"
class LINE_PRI : private LINE
{
public:
	void add(int val); // ���������� ��������
	int del(); // ���������� ��������
	int size();
	void output(); // ����� �������\��
	void copy(LINE_PRI& TMP); // ����������� �������
	void merge(LINE_PRI& MAIN, LINE_PRI& COPY); // ������� ��������
	float harmonic_avg(); // ���������� �������� ��������������
};