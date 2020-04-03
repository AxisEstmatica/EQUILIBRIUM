#pragma once
#include "LINE.h"
class LINE_PRO : protected LINE
{
public:
	void add(int val); // ���������� ��������
	int del(); // ���������� ��������
	int size();
	void output(); // ����� �������\��
	void copy(LINE_PRO& TMP); // ����������� �������
	void merge(LINE_PRO& MAIN, LINE_PRO& COPY); // ������� ��������
	float harmonic_avg(); // ���������� �������� ��������������
};