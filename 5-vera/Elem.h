#pragma once
#ifndef TextType2
#define TextType2
#include "Info.h"

using namespace std;

struct Elem
{
	Info el;
	Elem* next = nullptr;
	Elem(char a[], int len) {
		for (int i = 0; i < len; i++) {
			el.str[i] = a[i];
		}
		el.l = len;
	}
	Elem() {

	}
};


#endif