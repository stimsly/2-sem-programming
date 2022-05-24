#pragma once
#include "form_y.h"

#ifndef ALL_H
#define ALL_H

class all {
private:
	form_y prod;
	form_x mater;
public:
	
	void progress(ofstream &fout_rep);
	void input(ifstream &f1, ifstream &f2, ofstream &fout_rep) {
		prod.input(f1);
		mater.input_mater(f2);
		report a;
		a.output_mes("This man input products and materials#", fout_rep);
	}
	void output_prod() {
		prod.output();
	}
	void output_mater() {
		mater.output();
	}
};

#endif