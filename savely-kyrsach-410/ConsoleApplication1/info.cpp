#include "info.h"
int info::get_size() { return this->size; };
char info::get(int i) { return this->a[i]; };
l_y* info::get_name() { return name; };
int info::get_amount() { return amount; };
int info::get_t() { return type; };

void info::set(char a, int i) {this->a[i] = a;};
void info::set_size(int a) {this->size = a;};
void info::set_amount(int a) { amount = a; };
void info::set_t(int a) { type = a; };
void info::set_name(l_y* a) { name = a; };
