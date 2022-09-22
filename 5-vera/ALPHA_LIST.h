#pragma once
#ifndef TextType7
#define TextType7
#include "dopHList.h"
#include<cmath>

using namespace std;

struct ALPHA
{
	dopHList* h1 = nullptr, * c1 = nullptr;
	markiList* h2 = nullptr, * c2 = nullptr, * h5 = nullptr, * c5 = nullptr;
	hList* h = nullptr, * c = nullptr;
	hpomoch* h3 = nullptr, * c3 = nullptr, * h4 = nullptr, * c4 = nullptr;
	hrezult* h6 = nullptr, * c6 = nullptr, * h7 = nullptr, * c7 = nullptr;
};

void deleteHead3(ALPHA* p);
void deleteHead2(ALPHA* p);
void bubble_pisma(ALPHA* p, ofstream& r);
void bubble_marki(ALPHA* p, ofstream& r);
void push_back4(ALPHA* p, pomoch* q);
void push_back1(ALPHA* p, dopList* q);
void push_back2(char a[], int size, dopList* p);
void push_back12(ALPHA* p, List* q);
void push_back22(char a[], int size, List* p);
void push_back32(char a[], int size, List* p);
void push_back13(ALPHA* p, marki* q);
void push_back23(char a[], int size, marki* p);
void push_back33(char a[], int size, marki* p);
void push_back5(ALPHA* p, rezult* q);
void inpV(ALPHA* p1);
void inpG1(ifstream& f, dopList* p);
void outputV(ALPHA* p, ofstream& r, int& ptr, ofstream& r1);
void outputV2(ALPHA* p, ofstream& r, int& ptr, ofstream& r1);
void outputV3(ALPHA* p, ofstream& r, int& ptr, ofstream& r1);
void outputV4(ALPHA* p, ofstream& r, int& ptr);
void sortirovka1(ALPHA* p, ofstream& r);
void sortirovka2(ALPHA* a, dopList p, List p1, ofstream& r);
void sortirovka(ALPHA* l, dopList p, List p1, ofstream& r);
void deleteHead(ALPHA* p, ofstream& r);
void sort_rovka(ALPHA* p, ofstream& r);
void sort_rovka_marok(ALPHA* p, ofstream& r, int& ptr, ofstream& r1);
void obrabotka(ALPHA* p, ofstream& r, ofstream& r1);
void obrabotka2(ALPHA* p, ofstream& r, int& raz, int& kolvo, int& kolvo_marok);
int raznica(ALPHA* p, int& kolvo);
int kolvo_marok1(ALPHA* p);
void obrabotka3(ALPHA* p, ofstream& r, int& raz, int& kolvo, int& kolvo_marok);
void obrabotka4(ALPHA* p, ofstream& r, int& raz, int& kolvo, int& kolvo_marok);
void outputV5(ALPHA* p, ofstream& r, int& ptr);
int minimum(ALPHA* p);

#endif