#include "l_x.h"


void l_x::set_next(l_x* next) { this->next = next; };
l_x* l_x::get_next() { return this->next; };
int l_x::get_size() { return cur.get_size(); };
char l_x::get_i(int i) { return cur.get(i); };
int l_x::get_amount() { return cur.get_amount(); };