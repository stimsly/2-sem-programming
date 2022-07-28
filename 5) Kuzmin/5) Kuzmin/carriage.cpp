#include "carriage.h"

carriage::carriage() {
	next_carriage = nullptr;
	type = UNKNOUWN_TYPE;
	seats_count = 0;
	upper_seats_left = 0;
	lower_seats_left = 0;
}

carriage::carriage(int type) {
	this->type = type;
	seats_count = USUAL_SEATS;
	upper_seats_left = USUAL_SEATS / 2;
	lower_seats_left = USUAL_SEATS / 2;
	if (type == 1) {
		seats_count += USUAL_SEATS / 2;
		upper_seats_left += USUAL_SEATS / 4;
		lower_seats_left += USUAL_SEATS / 4;
	}
}

void carriage::get_info() {
	if (type == 1) cout << "Плацкарт\n";
	else if (type == 2) cout << "Куппе\n";
	cout << "Общее количество мест: " << seats_count << endl;
	cout << "Свободных мест сверху: " << upper_seats_left << endl;
	cout << "Свободных мест снизу: " << lower_seats_left << endl << endl;
}

carriage* carriage::get_next() {
	return next_carriage;
}
void carriage::set_next(carriage* a) {
	next_carriage = a;
}

int carriage::get_lower() { return lower_seats_left; }
int carriage::get_upper() { return upper_seats_left; }
void carriage::set_lower(int a) { lower_seats_left = a; }
void carriage::set_upper(int a) { upper_seats_left = a; }