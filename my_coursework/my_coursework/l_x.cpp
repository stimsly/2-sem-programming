#include "l_x.h"

l_x* l_x::get_next() { return this->next; };
void l_x::set_next(l_x* next) { this->next = next; };

int l_x::get_size() { return cur.get_size(); };
char l_x::get_i(int i) { return cur.get(i); };