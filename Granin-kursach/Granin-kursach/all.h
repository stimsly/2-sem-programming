#pragma once

#include "form_y.h"

using namespace std;

class all {
private:
	form_y burg;
	form_y mater;
public:
	
	void progress(ofstream &fout_rep, int &res);
	//void add() { mater.add(); };
	void input(ifstream &f1, ifstream &f2, ofstream &fout_rep) {
		input(f2, 0);
		input(f1, 1);
		fout_rep << "This man input products and materials\n";
	}
	void input(ifstream& f, int t);
	void output_prod() {
		burg.output(1);
	}
	void output_mater() {
		mater.output(0);
	}
	void clear() {
		burg.clear();
		mater.clear();
	}
	void add(ofstream &f) {
		mater.add(f);
	}
};

