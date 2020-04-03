#include "segment_pri.h"
#include <iostream>

float LINE_PRI::harmonic_avg()
{
	float variable = 0;
	ELMT* tmp = get_end();
	int number = size();
	while (number != 0)
	{
		variable += 1.0 / (tmp->value);
		tmp = (tmp->prev);
		--number;
	}
	return float(size() / variable);
}
void LINE_PRI::add(int val)
{
	return LINE::add(val);
}
int LINE_PRI::del()
{
	return LINE::del();
}
int LINE_PRI::size()
{
	return LINE::size();
}
void LINE_PRI::output()
{
	return LINE::output();
}
void LINE_PRI::copy(LINE_PRI& TMP)
{
	return LINE::copy(TMP);
}
void LINE_PRI::merge(LINE_PRI& MAIN, LINE_PRI& COPY)
{
	return LINE::merge(MAIN, COPY);
}