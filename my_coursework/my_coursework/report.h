#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

#ifndef REPORT_H
#define REPORT_H
class report {
private:
	char mark = '#';
public:
	void output_mes(const char a[100], ofstream& f) {
		for (int i = 0;; i++) {
			if (a[i] == mark) break;
			f << a[i];
		}
		f << endl;
	};
};

#endif