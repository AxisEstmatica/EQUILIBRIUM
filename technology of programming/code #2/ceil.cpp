#include <iostream>
#include "ceil.h"
using namespace std;
CEIL::CEIL()
{
	value = 0;
}
CEIL::CEIL(int x)
{
	value = x;
}
CEIL& CEIL::operator --()
{
	--value;
	return *this;
}
CEIL& CEIL::operator ++()
{
	++value;
	return *this;
}
CEIL operator -- (CEIL &x, int)
{
	CEIL tmp(x.value);
	--x.value;
	--x.value;
	return tmp;
}
CEIL operator ++ (CEIL &x, int)
{
	CEIL tmp(x.value);
	++x.value;
	++x.value;
	return tmp;
}
CEIL& CEIL::operator()(int x)
{
	value = x;
	return *this;
}
void CEIL::show()
{
	cout << value;
}