#pragma once
#include <fstream>
#include <iostream>
#include "Node.h"
using namespace std;



#ifndef LIST_H
#define LIST_H



class List {
public:
	List() {
		Size = 0;
		this->head = nullptr;
	}

	void input(ifstream &f2);
	void push_back(char line[n + 1], char mark);
	void progress(int delete_number);
	void print(ofstream& f);
	void clear();

	bool is_empty();

private:
	int Size;
	Node* head;
};

#endif // !STR_H