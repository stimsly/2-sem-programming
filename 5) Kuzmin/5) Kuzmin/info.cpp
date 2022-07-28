#include "info.h"

info::info() {
	i = 0;
	for (int i = 0; i < N; i++) a[i] = '^';
}
info::info(int n, char b[]) {
	for (int i = 0; i < n; i++) {
		a[i] = b[i];
	}
	i = n;
}

void info::set(int i, char a) { this->a[i] = a; }
void info::set_n(int a) { i = a; }
int info::get_n() { return i; }
char info::get(int i) { return a[i]; }