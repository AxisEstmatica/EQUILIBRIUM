#include <iostream>
#include "line_description.h"
using namespace std;
void LINE::get(int NUM, LINE &NEW_EL)
{
	cout << "Введите число, добавляемое в очередь: " << endl;
	cin >> box;
	if (NUM == 0)
		spot = NULL;
	else
		spot = &NEW_EL;
}
void LINE::output(LINE &TMP_EL, int NUM)
{
	int *line = new int[NUM];
	int *i = new int;
	LINE *address = new LINE;
	address = &TMP_EL;
	*i = 0;
	cout << "  " << i << "  " << *i << "  " << TMP_EL.box << "  " << TMP_EL.spot << "  " << NUM<< endl; // debug
	cout << " Текущие элементы очереди:" << endl;
	while ((*i)+1 != NUM)
	{
		line[*i] = address->box;
		(*i)++;
		address = address->spot;
		//TMP_EL.box = TMP_EL.spot->box;
		//TMP_EL.spot = TMP_EL.spot->spot;
		cout << "  " << i << "  " << *i << "  " << TMP_EL.box << "  " << "  " << TMP_EL.spot << NUM << endl; // debug
	}
	line[*i] = address->box;
	do
	{
		cout << " " << line[*i];
		(*i)--;
	} while ((*i)!=-1);
	cout << endl;
	delete[NUM] line;
	delete i;
	delete address;
}