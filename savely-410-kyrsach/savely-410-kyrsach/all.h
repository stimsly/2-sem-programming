#pragma once

#include "form_y.h"

using namespace std;

class all {
private:
	form_y vowels;
	form_y consonants;
	static const int ABC = 26;
	bool is[ABC];
public:
	all() {
		for (int i = 0; i < ABC; i++) is[i] = 0;
		is['a' - 'a'] = 1;
		is['e' - 'a'] = 1;
		is['i' - 'a'] = 1;
		is['o' - 'a'] = 1;
		is['u' - 'a'] = 1;
	}


	void input(ifstream& f1, ofstream& fout_rep);
	int count(char a[100], int len);
	void clear() {
		vowels.clear();
		consonants.clear();
	}
	void output(ofstream &f) {
		f << "Список оканчивающийся на гласные:\n";
		vowels.output(f);
		f << endl;
		f << "Список оканчивающийся на согласные:\n";
		consonants.output(f);

	}
};


