#pragma once
#include"all.h"
using namespace std;

#ifndef FLETTER_H
#define FLETTER_H

class f_letter {
private:
	char *a[26];
public:
	f_letter() {
		
		for (int i = 0; i < 26; i++) a[i] = nullptr;
	};


};

#endif