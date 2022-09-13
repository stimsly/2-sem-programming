#pragma once
#include "form_y.h"

#ifndef ALL_H
#define ALL_H

class all {
public:
	form_y a, b;
	int progress();
	void input(ifstream &f1, ifstream &f2) {
		a.input(f1);
		b.input(f2);
	}
	void output(ofstream& fout, int ans) {
		fout << "������ ������:\n";
		a.output(fout);
		fout << "������ ������:\n";
		b.output(fout);
		if (ans == 0) fout << "\n������ ������ �� ������ �� ������.\n";
		if (ans == 1) fout << "\n������ ������ ������ �� ������.\n";
	}
};

#endif