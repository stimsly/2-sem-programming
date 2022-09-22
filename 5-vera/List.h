#pragma once
#ifndef TextType3
#define TextType3
#include "Elem.h"

using namespace std;

struct List
{
	Elem* Letter = nullptr, * c = nullptr;
	Elem* Country = nullptr, * c1 = nullptr;
	int StarTar;
	int number_of_letter;
};

struct rezult
{
	Elem* Country = nullptr, * c = nullptr;
	int number_of_letter;
	int kolvo=0, temp=0;
	int stoimost[100], tmp[100];
};

#endif