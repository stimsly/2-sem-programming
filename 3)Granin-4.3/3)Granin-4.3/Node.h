#pragma once
#include<fstream>
#include<iostream>
#include"Line.h"
using namespace std;
#ifndef NODE_H
#define NODE_H

class Node {
private:
	Line line;
	Node* next;
	
public:
	Node(char line[n + 1], char mark, Node* next = nullptr) {
		this->next = next;
		this->line.set_mark(mark);
		int i = 0;
		while (line[i] != mark) {
			this->line.set_char(i, line[i]);
			i++;
		}
		this->line.set_char(i, this->line.get_mark());
	}
	
	char get_char(int i);
	char get_mark();
	Node* get_next();

	void set_mark(char mark);
	void set_char(int i, char a);
	void set_next(Node* next);
	void clear(Node *head);
};

#endif