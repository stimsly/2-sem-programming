#pragma once
#ifndef TextType5
#define TextType5
#include "hList.h"

using namespace std;

struct dopList
{
	Elem* Country_N = nullptr, * c= nullptr;
	int NovTar;
};

struct marki {
	Elem* stoimost = nullptr, * c = nullptr;
	Elem* kolvo = nullptr, * c1 = nullptr;
	int stoimost_int, kolvo_int;
	int temp;
};

struct pomoch
{
	Elem* Country_P = nullptr, * c = nullptr;
	Elem* Letter = nullptr, * c1 = nullptr;
	int raznica;
	int number_of_letter1;
	int temp;
};

#endif