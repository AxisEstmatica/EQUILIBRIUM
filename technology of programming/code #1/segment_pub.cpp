#include "segment_pub.h"
#include <iostream>

float LINE_PUB::harmonic_avg()
{
	float variable = 0;
	ELMT* tmp = get_end();
	int number = size();
	while (number != 0)
	{
		variable += 1.0/(tmp->value);
		tmp = (tmp->prev);
		--number;
	}
	return float(size() / variable);
}