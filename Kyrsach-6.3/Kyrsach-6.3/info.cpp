#include "info.h"

int info::get_size() { return this->size; };

char info::get(int i) { return this->a[i]; };

void info::set(char a, int i) {
	this->a[i] = a;
};
void info::set_size(int a) {
	this->size = a;
};
