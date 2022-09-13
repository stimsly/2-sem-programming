#include <iostream>
#include "text.h"

ofstream f2("output.txt");

void text::progress() {
	int ans = 0;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < textM[i].getlen(); j++) {
			if (textM[i].getchar(j) == '.') ans++;
		}
	}
	f2 << "\nTotal amount of sentensies is: " << ans << endl;
}

void text::output() {
	if (l == 0) {
		f2 << "EMPTY\n";
		return;
	}
	f2 << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Primary text: \n";
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < textM[i].getlen(); j++) {
			f2 << textM[i].getchar(j);
		}
		f2 << endl;
	}
	f2 << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>END.\n\n";

	return;
}