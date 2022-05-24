#include<fstream>
#include<iostream>
#include "text.h"
using namespace std;

void text::output(ofstream& f) {
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < textM[i].get_len(); j++) f << textM[i].get_char(j);
		f << endl;
	}
}