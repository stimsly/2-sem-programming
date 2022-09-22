#pragma once
#ifndef TextType4
#define TextType4
#include "List.h"

using namespace std;

struct hList
{
	List base;
	hList* next = nullptr;
};

struct hrezult
{
	rezult base;
	hrezult* next = nullptr;
};

#endif