#pragma once
#ifndef TextType6
#define TextType6
#include "dopList.h"
#include<cmath>

using namespace std;

struct dopHList
{
	dopList base;
	dopHList* next = nullptr;
};

struct markiList
{
	marki base;
	markiList* next = nullptr;
};

struct hpomoch
{
	pomoch base;
	hpomoch* next = nullptr;
};

void output(List p, ofstream& r, int& ptr, ofstream& r1);
void inpG2(ifstream& f1, List* p);
void inpG3(ifstream& f1, marki* p);
void output2(dopList p, ofstream& r, int& ptr, ofstream& r1);
void output3(marki p, ofstream& r, int& ptr, ofstream& r1);
void output4(pomoch p, ofstream& r);

#endif