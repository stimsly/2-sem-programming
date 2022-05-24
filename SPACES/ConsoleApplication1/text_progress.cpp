#include "text.h"
#include<iostream>
void text::progress() {
	for (int i = 0; i < this->l; i++) {
		int was = 0;
		int cur = 0;
		for (int j = 0; j < this->textM[i].get_len(); j++) {
			if (!was and textM[i].get_char(j) == ' ') {
				cur++;
			}
			if (!was and textM[i].get_char(j) != ' ' and cur) {
				skip(i, j, cur);
				cur = 0;
				j = 0;
			}
			if (was and textM[i].get_char(j) == ' ') {
				cur++;
			}
			if (was and textM[i].get_char(j) != ' ' and cur > 1) {
				skip(i, j, cur - 1);
				cur = 0;
				j = 0;
			}
			if (textM[i].get_char(j) != ' ') {
				cur = 0;
				was = 1;
			}

		}
		if (cur > 1) {
			
			skip(i, textM[i].get_len(), cur);
		}
	}
}