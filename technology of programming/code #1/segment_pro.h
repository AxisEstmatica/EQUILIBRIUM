#pragma once
#include "LINE.h"
class LINE_PRO : protected LINE
{
public:
	void add(int val); // добавление элемента
	int del(); // извлечение элемента
	int size();
	void output(); // вывод очереди\ей
	void copy(LINE_PRO& TMP); // копирование очереди
	void merge(LINE_PRO& MAIN, LINE_PRO& COPY); // слияние очередей
	float harmonic_avg(); // нахождение среднего гармонического
};