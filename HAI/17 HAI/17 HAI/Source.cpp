#include <iostream>
#include <stack>
#include <Windows.h>
#include <stdbool.h>
using namespace std;
int processing(int size);
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	int size = 0;
	printf("Ввести последовательность скобок: ");
	size = processing(size);
	printf(size > 0 ? "Последовательность не верна\n" : "Последовательность верна\n");
	return 0;
}

int processing(int size)
{
	char c = ' ';
	bool error = 0;
	stack <char> stk;
	for (; scanf_s("%c", &c), c != '\n' && error == 0;)
	{
		switch (c)
		{
		case '(':
		case '[':
		case '{':
			stk.push(c);
			size++;
			break;
		case ')':
			(stk.empty() == 0) ? (stk.top() == '(') ? size-- : error = 1 : error = 1;   // проверка на наличие символов в стеке
			if (error == 0)
				stk.pop(); // удаление верхнего элемента
			break;
		case ']':
			(stk.empty() == 0) ? (stk.top() == '[') ? size-- : error = 1 : error = 1;
			if (error == 0)
				stk.pop();
			break;
		case '}':
			(stk.empty() == 0) ? (stk.top() == '{') ? size-- : error = 1 : error = 1;
			if (error == 0)
				stk.pop();
		}
	}
	return size = (error != 0) ? 1 : size;
}
