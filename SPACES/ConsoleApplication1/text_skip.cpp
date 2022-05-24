#include<fstream>
#include<iostream>
#include "text.h"
using namespace std;

void text::skip(int j, int pos, int cur) {
	for (int i = pos; i < textM[j].get_len(); i++) {
		textM[j].set_char(i - cur, textM[j].get_char(i));
	}
	textM[j].set_len(textM[j].get_len() - cur);
}