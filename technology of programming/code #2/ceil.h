#pragma once
class CEIL
{
public:
	CEIL();
	explicit CEIL(int x = 0); // �������� �� ���������, ��� ������������� �������� ������ �������� value = 0
	CEIL& operator --(); // prefix
	CEIL& operator ++();
	friend CEIL operator ++(CEIL &x, int); // int is postfix
	friend CEIL operator --(CEIL &x, int); // ptr as friend
	CEIL& operator ()(int x); // ���������� ���� ����������� �-�
	void show();
private:
	int value;;
};