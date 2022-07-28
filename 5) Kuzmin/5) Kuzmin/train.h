#pragma once
#include "carriage.h"
#include "form_y.h"

#ifndef TRAIN_H
#define TRAIN_H

class train {
private:
	carriage* head_carriage;
	carriage* cur;
	carriage* last;
	int carriage_count;
	form_y about;
public:
	train();
	~train();
	void get_info();
	void create(ifstream& f);
	void push(int type);
	void add_about(ifstream& f);
	void delete_train();

	void order();
			
};

#endif