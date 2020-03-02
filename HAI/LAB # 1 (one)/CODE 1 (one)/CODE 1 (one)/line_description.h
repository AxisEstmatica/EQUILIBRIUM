#pragma once

class LINE
{
	int box; // value
	LINE *spot; // address of previous element
public:
	void get(int NUM, LINE &NEW_EL); // function of getting of NEW element
	void extraction(); // function of extracting element from the line
	void output(LINE &TMP_EL, int MUM); // function of output line
};
