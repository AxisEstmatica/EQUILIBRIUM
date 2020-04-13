#pragma once
class CEIL
{
public:
	CEIL();
	explicit CEIL(int x = 0); // параметр по умолчанию, без инициализации присвоит классу значение value = 0
	CEIL& operator --(); // prefix
	CEIL& operator ++();
	friend CEIL operator ++(CEIL &x, int); // int is postfix
	friend CEIL operator --(CEIL &x, int); // ptr as friend
	CEIL& operator ()(int x); // перегрузка чтоб принималась ф-я
	void show();
private:
	int value;;
};
