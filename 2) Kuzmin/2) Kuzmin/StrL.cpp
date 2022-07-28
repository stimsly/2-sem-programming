#include "StrL.h"


char StrL::getchar(int i) {
	return s[i];
}

int StrL::getlen() {
	return len;
}

void StrL::setchar(int i, int a) {
	s[i] = a;
}

void StrL::setlen(int a) {
	len = a;
}