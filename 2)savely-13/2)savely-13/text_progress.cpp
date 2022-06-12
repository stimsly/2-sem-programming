#include <iostream>
#include "text.h"

void text::progress() {
	int x = -1;
	int y = -1;
	for (int i = 0; i < l; i++) {

		for (int j = 0; j < textM[i].getlen() - 1; j++) {
			if (textM[i].getchar(j) == '/' and textM[i].getchar(j + 1) == '/' and x == -1) {
				textM[i].setlen(j);
				if (j == 0) {
					for (int j2 = i; j2 < l - 1; j2++) {
						textM[j2] = textM[j2 + 1];
					}
					l--;
					i--;
				}
			}
			if (textM[i].getchar(j) == '/' and textM[i].getchar(j + 1) == '*') {
				x = i;
				y = j;
			}
			if (textM[i].getchar(j) == '*' and textM[i].getchar(j + 1) == '/' and x != -1) {
				if (i == x) {
					for (int j2 = 0; j + 2 + j2 < textM[i].getlen(); j2++) {
						textM[i].setchar(y + j2, textM[i].getchar(j + 2 + j2));
					}
					textM[i].setlen(textM[i].getlen() - (j - y + 2));
					if (textM[i].getlen() == 0) {
						for (int j2 = x; j2 < l - 1; j2++) {
							textM[j2] = textM[j2 + 1];
						}
						l--;
					}
				}
				else {
					while (x + 1 != i) {
						for (int j2 = x + 1; j2 < l - 1; j2++) {
							textM[j2] = textM[j2 + 1];
						}
						l--;
						i--;
					}
					textM[x].setlen(y);
					if (textM[x].getlen() == 0) {
						for (int j2 = x; j2 < l - 1; j2++) {
							textM[j2] = textM[j2 + 1];
						}
						l--;
						i--;
					}
					for (int j2 = 0; j + 2 + j2 < textM[i].getlen(); j2++) {
						textM[i].setchar(j2, textM[i].getchar(j + 2 + j2));
					}
					textM[i].setlen(textM[i].getlen() - (j + 2));
					if (textM[i].getlen() == 0) {
						for (int j2 = i; j2 < l - 1; j2++) {
							textM[j2] = textM[j2 + 1];
						}
						l--;
					}
				}
				x = -1;
				y = -1;
				i--;
				break;
			}
		}
	}
}