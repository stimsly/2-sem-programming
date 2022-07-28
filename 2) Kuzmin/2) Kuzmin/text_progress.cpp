#include <iostream>
#include "text.h"

ofstream f2("output.txt");

void text::progress() {
	int x = -1;
	int y = -1;
	int count = 0;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < textM[i].getlen() - 1; j++) {
			if (textM[i].getchar(j) == '/' and textM[i].getchar(j + 1) == '/' and x == -1) {
				count++;
				for (int j2 = j + 2; j2 < textM[i].getlen(); j2++) {
					if (textM[i].getchar(j2) == '{' or textM[i].getchar(j2) == '}') {
						for (int k = j2; k < textM[i].getlen() - 1; k++) textM[i].setchar(k, textM[i].getchar(k + 1));
						textM[i].setlen(textM[i].getlen() - 1);
						i--;
					}
				}
				i++;
				j = 0;
			}
			if ( (textM[i].getchar(j) == '{' or textM[i].getchar(j) == '}') and x != -1) {
				//cout << x << " " << y << " " << i << " " << j << endl;
				for (int k = j; k < textM[i].getlen() - 1; k++) textM[i].setchar(k, textM[i].getchar(k + 1));
				textM[i].setlen(textM[i].getlen() - 1);
				j = y + 1;
				i = x;
				continue;
			}
			if (textM[i].getchar(j) == '/' and textM[i].getchar(j + 1) == '*' and x == -1) {
				count++;
				x = i;
				y = j;
			}
			if (textM[i].getchar(j) == '*' and textM[i].getchar(j + 1) == '/' and x != -1) {
				x = -1;
				y = -1;
			}
		}
	}
	x = -1;
	y = -1;
	count = 0;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < textM[i].getlen() - 1; j++) {
			if (textM[i].getchar(j) == '/' and textM[i].getchar(j + 1) == '/' and x == -1) {
				count++;
				i++;
				j = 0;
			}
			if (textM[i].getchar(j) == '/' and textM[i].getchar(j + 1) == '*' and x == -1) {
				count++;
				x = i;
				y = j;
			}
			if (textM[i].getchar(j) == '*' and textM[i].getchar(j + 1) == '/' and x != -1) {
				x = -1;
				y = -1;
			}
		}
	}
	f2 << "Количество комментариев: " << count << endl;
	count = 0;
	x = 0;
	y = 0;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < textM[i].getlen(); j++) {
			if (textM[i].getchar(j) == '{') {
				f2 << "Началось новое утверждение\n";
				f2 << endl;
				y = 0;
				for (int i2 = i; i2 < l; i2++) {
					for (int j2 = 0; j2 < textM[i2].getlen(); j2++) {
						f2 << textM[i2].getchar(j2);
						if (textM[i2].getchar(j2) == '{') x++;
						if (textM[i2].getchar(j2) == '}') x--;
					}
					y++;
					f2 << endl;
					if (!x) break;
				}
				count++;
				f2 << "Это утверждение занимает: " << y << " строк.\n\n\n";
			}
		}
	}
	f2 << "Общее количество утверждений: " << count << endl;
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