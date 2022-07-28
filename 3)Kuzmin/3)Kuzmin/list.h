#pragma once
#include <fstream>
#include <iostream>
#include "Node.h"
using namespace std;



#ifndef LIST_H
#define LIST_H



class List {
private:
	int Size;
	Node* head;
public:
	List() {
		Size = 0;
		this->head = nullptr;
	}

	void input();
	void push_back(char line[n + 1], char mark);
	void progress(Line a, Line b, ofstream &fout);
	void print(ofstream& f);
	void clear();
	

	bool is_empty();
};

#endif // !STR_H