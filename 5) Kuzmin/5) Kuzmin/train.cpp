#include "train.h"

ofstream report("report.txt");

train::train() {
	report << "CREATE_NEW_TRAIN: " << this << "\n";
	cur = nullptr;
	last = nullptr;
	head_carriage = nullptr;
	carriage_count = 0;
}
train::~train() {
	report << "DESTROY_TRAIN: " << this << "\n";
}

void train::order() {
	report << "SOMBODY_WONTS_TO_BUY_A_TICKET\n";
	system("cls");
	get_info();
	cout << "Введите номер вагона в котором хотите купить билет: ";
	int n;
	cin >> n;
	if (n < 1 or n > carriage_count) {
		report << "WRONG_CARRIAGE_NUMBER\n";
		return;
	}
	cur = head_carriage;
	for (int i = 1; i < n; i++) {
		cur = cur->get_next();
	}
	if (cur->get_lower() + cur->get_upper() == 0) {
		report << "NO_FREE_SEATS_IN_CARRIAGE_NUMBER_" << n << "\n";
		return;
	}
	if (cur->get_lower()) {
		cout << "Хотите взять нижнее место?(1 или 0)\n";
		int wish;
		cin >> wish;
		if (wish) {
			cur->set_lower(cur->get_lower() - 1);
			report << "LOWER_SEAT_IN_CARRIAGE_NOMBER_" << n << "_WAS_BOUGHT\n";
			return;
		}
	}
	if (cur->get_lower()) {
		cout << "Хотите взять верхнее место?(1 или 0)\n";
		int wish;
		cin >> wish;
		if (wish) {
			cur->set_lower(cur->get_lower() - 1);
			report << "UPPER_SEAT_IN_CARRIAGE_NOMBER_" << n << "_WAS_BOUGHT\n";
		}
	}
	cout << "OPERATION_CLOSED_SUCCESSFULY\n";
}

void train::delete_train() {
	report << "STARTING_REMOVE_CARRIEGES_OF_TRAIN: " << this << "\n";
	cur = head_carriage;
	while (cur != nullptr) {
		carriage* t = cur;
		cur = cur->get_next();
		report << "Destroy carriage: " << t << endl;
		delete t;
	}
	report << "TRAIN_ARE_EMPTY\n";
}

void train::add_about(ifstream& f) {
	report << "READ_ABOUT_TRAIN " << this << "\n";
	about.read(f);
	report << "END_OF_READ_ABOUT_TRAIN\n";

}

void train::push(int type) {

	if (type < 1 or type > 2) {
		report << "FAILED_TO_ADD_NEW_CARRIEGE (INVALIDE_TYPE=" << type << " MUST_BE_IN_RANGE[1;2])\n";
		return;
	}

	report << "ADD_NEW_CARRIEGE (TYPE=" << type << ")\n";

	carriage_count++;

	if (head_carriage == nullptr) {
		head_carriage = new carriage(type);
		last = head_carriage;
	}
	else {
		last->set_next(new carriage(type));
		last = last->get_next();
	}
	report << "Create new carriage: " << last << endl;

}

void train::create(ifstream& f) {
	report << "ADD_CARRIAGES_FOR_TRAIN: " << this << "\n";
	int type;
	while (!f.eof()) {
		f >> type;
		push(type);
	}
	report << "NEW_CARRIAGER_WAS_ADDED\n";
}

void train::get_info() {
	report << "GET_TRAIN_INfO: " << this << "\n";

	about.write();

	cur = head_carriage;
	int number = 0;
	while (cur != nullptr) {
		number++;
		cout << "Вагон номер: " << number << "\nТип: ";
		cur->get_info();
		cur = cur->get_next();
	}
	report << "END_OF_TRAIN_INFO\n";
}