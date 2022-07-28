#pragma once
#include "laibraries.h"

#ifndef CARRIAGE_H
#define CARRIAGE_H

const int USUAL_SEATS = 36;
const int UNKNOUWN_TYPE = -1;

class carriage {
private:
	carriage* next_carriage;
	int type;
	int seats_count;
	int upper_seats_left;
	int lower_seats_left;
public:

	carriage();

	carriage(int type);

	void get_info();

	carriage* get_next();
	void set_next(carriage* a);
	int get_lower();
	int get_upper();
	void set_lower(int a);
	void set_upper(int a);
};

#endif