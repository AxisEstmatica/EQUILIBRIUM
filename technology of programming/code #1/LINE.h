#pragma once
#include "element.h"
class LINE
{
public:
	LINE();
	~LINE();
	void add(int val); // добавление элемента
	int del(); // извлечение элемента
	int size();
	void output(); // вывод очереди\ей
	void copy(LINE& TMP); // копирование очереди
	void merge(LINE& MAIN, LINE& COPY); // слияние очередей
protected:
	ELMT *get_end(); // возвращение указателя на последний элемент
private:
	ELMT *end; // указатель на конец очереди
	int NUM; // количество элементов очереди
};