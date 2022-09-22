#pragma once
#ifndef TextType2
#define TextType2
#include "Info.h"

using namespace std;

struct ListG
{
	Info el;
	ListG* next = nullptr;
	ListG(char a[], int len) {
		for (int i = 0; i < len; i++) {
			el.stroka[i] = a[i];
		}
		el.l = len;
	}
	ListG() {

	}
};


#endif