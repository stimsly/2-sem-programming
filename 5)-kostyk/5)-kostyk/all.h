#pragma once
#include "form_y.h"

#ifndef ALL_H
#define ALL_H
class all {
public:
	form_y a;
	int nom[100]{};
	int amount[100]{};
	int n{};
	int progress(ofstream &f);
	void input1(ifstream &f) {
		int n;
		f >> n;
		this->n = n;
		for (int i = 0; i < n; i++) {
			f >> nom[i] >> amount[i];
		}
	}
	void input(ifstream &f, ifstream& money) {
		a.input(f);
		input1(money);
	}
	void output1(ofstream& fout) {
		fout << "��������:\n\n";
		for (int i = 0; i < n; i++) {
			fout << "���� 1 ������: " << nom[i] << "\n���������� �����: " << amount[i] << endl << endl;;
		}
	}
	void output(ofstream& fout, int t) {
		fout << "������ �������:\n";
		a.output(fout, t);
		output1(fout);
	}
	
};

#endif