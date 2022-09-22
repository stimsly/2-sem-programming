#pragma once
#ifndef TextType5
#define TextType5
#include "ListV.h"
#include<cmath>

using namespace std;

struct FormV
{
	ListV* h = nullptr, * l = nullptr, * c = nullptr;
	ListV* h1 = nullptr, * l1 = nullptr, * c1 = nullptr;
};

void inpG(ifstream& f, FormG* p);
void inpV(ifstream& f, FormV* p1);
void output(FormG p, ofstream& r);
void outputV(FormV* p, ofstream& r);
void push_back2(char a[], int size, FormG* p);
void push_back1(FormV* p, FormG* q);
void inpG2(ifstream& f1, FormG* p);
void inpV2(ifstream& f1, FormV* p1);
void output2(FormG p, ofstream& r);
void outputV2(FormV* p, ofstream& r);
void push_back22(char a[], int size, FormG* p);
void push_back12(FormV* p, FormG* q);
int obrabotka1(FormV* p, int& k);
int obrabotka4(FormV* p, int& k);
int obrabotka3(FormV* p);
void deletelist(FormG p, ofstream& r);
void deleteHead(FormV* p, ofstream& r);

#endif