#include "segment_pro.h"
#include <iostream>

float LINE_PRO::harmonic_avg()
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
void LINE_PRO::add(int val)
{
	return LINE::add(val);
}
int LINE_PRO::del()
{
	return LINE::del();
}
int LINE_PRO::size()
{
	return LINE::size();
}
void LINE_PRO::output()
{
	return LINE::output();
}
void LINE_PRO::copy(LINE_PRO& TMP)
{
	return LINE::copy(TMP);
}
void LINE_PRO::merge(LINE_PRO& MAIN, LINE_PRO& COPY)
{
	return LINE::merge(MAIN, COPY);
}