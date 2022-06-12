#include "text.h"

void text::output(ofstream& f) {
	if (l == 0) f << "EMPTY\n";
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < textM[i].getlen(); j++) {
			f << textM[i].getchar(j);
		}
		f << endl;
	}
	return;
}