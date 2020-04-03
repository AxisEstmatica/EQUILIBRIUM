#pragma once
#include "LINE.h"
class LINE_PRI : private LINE
{
public:
	void add(int val); // добавление элемента
	int del(); // извлечение элемента
	int size();
	void output(); // вывод очереди\ей
	void copy(LINE_PRI& TMP); // копирование очереди
	void merge(LINE_PRI& MAIN, LINE_PRI& COPY); // слияние очередей
	float harmonic_avg(); // нахождение среднего гармонического
};