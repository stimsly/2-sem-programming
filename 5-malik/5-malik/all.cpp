#include "all.h"

bool check(char a[100], char b[100], int aa, int bb) {
	if (aa != bb) {
		return aa > bb;
	}
	for (int i = 0; i < min(aa,bb); i++) {
		if (a[i] < b[i]) return 0;
		if (a[i] > b[i]) return 1;
	}
	return 1;
}

void read_element(char(&a)[100], int &i, ofstream &f) {
	i = 0;
	cout << "Введите элемент(после последней позиции вставьте !): ";
	while (1) {
		char aa;
		cin >> aa;
		if (aa == '!') break;
		a[i++] = aa;
	}
	cout << "Вы ввели: ";
	for (int j = 0; j < i; j++) cout << a[j];
	cout << endl;
	f << "Вы ввели: ";
	for (int j = 0; j < i; j++) f << a[j];
	f << endl;
}

bool eq(char a[100], char b[100], int aa, int bb) {
	if (aa != bb) return 0;
	for (int i = 0; i < aa; i++) {
		if (a[i] != b[i]) return 0;
	}
	return 1;
}

void all::symmetric_difference(ofstream& f) {
	cout << "Симметрическая разность f и g\n";
	f << "Симметрическая разность f и g\n";
	a.cur = a.head;
	g.cur = g.head;
	char aa[100], bb[100];
	form_y ans;
	int sa = 0, sb = 0;
	while (1) {
		sb = 0;
		sa = 0;
		if (a.cur == nullptr and g.cur == nullptr) break;
		if (a.cur == nullptr) {
			g.cur->get_all_line(bb, sb);
			ans.push_back(bb, sb);
			g.cur = g.cur->get_next();
			continue;
		}
		if (g.cur == nullptr) {
			a.cur->get_all_line(aa, sa);
			ans.push_back(aa, sa);
			a.cur = a.cur->get_next();
			continue;
		}
		a.cur->get_all_line(aa, sa);
		g.cur->get_all_line(bb, sb);
		if (eq(aa, bb, sa, sb)) {
			g.cur = g.cur->get_next();
			a.cur = a.cur->get_next();
		}
		else if (check(aa, bb, sa, sb)) {
			ans.push_back(bb, sb);
			g.cur = g.cur->get_next();
		}
		else {
			ans.push_back(aa, sa);
			a.cur = a.cur->get_next();
		}
	}
	cout << "Полученное множество\n";
	f << "Полученное множество\n";
	ans.output(f);
}

void all::f_plus_g(ofstream &f) {
	cout << "Попытка обьеденить f и g\n";
	f << "Попытка обьеденить f и g\n";
	a.cur = a.head;
	g.cur = g.head;
	char aa[100], bb[100];
	form_y ans;
	int sa = 0, sb = 0;
	while (1) {
		sb = 0;
		sa = 0;
		if (a.cur == nullptr and g.cur == nullptr) break;
		if (a.cur == nullptr) {
			g.cur->get_all_line(bb, sb);
			ans.push_back(bb, sb);
			g.cur = g.cur->get_next();
			continue;
		}
		if (g.cur == nullptr) {
			a.cur->get_all_line(aa, sa);
			ans.push_back(aa, sa);
			a.cur = a.cur->get_next();
			continue;
		}
		a.cur->get_all_line(aa, sa);
		g.cur->get_all_line(bb, sb);
		if (eq(aa, bb, sa, sb)) {
			ans.push_back(bb, sb);
			g.cur = g.cur->get_next();
			a.cur = a.cur->get_next();
		}
		else if (check(aa, bb, sa, sb)) {
			ans.push_back(bb, sb);
			g.cur = g.cur->get_next();
		}
		else {
			ans.push_back(aa, sa);
			a.cur = a.cur->get_next();
		}
	}
	cout << "Полученное множество\n";
	f << "Полученное множество\n";
	ans.output(f);
}

void all::minus(ofstream& f) {
	cout << "Попытка вычесть из F - G\n";
	f << "Попытка вычесть из F - G\n";
	form_y ans;
	int x = 1;
	a.cur = a.head;
	while (a.cur != nullptr) {
		int y = 0;
		char aa[100];
		int sa = 0;
		a.cur->get_all_line(aa, sa);
		g.cur = g.head;
		while (g.cur != nullptr) {
			char bb[100];
			int sb = 0;
			g.cur->get_all_line(bb, sb);
			if (eq(aa, bb, sa, sb)) {
				y = 1;
				break;
			}
			g.cur = g.cur->get_next();
		}
		if (!y) ans.push_back(aa, sa);
		a.cur = a.cur->get_next();
	}
	cout << "Полученное множество\n";
	f << "Полученное множество\n";
	ans.output(f);
}

void all::intersect(ofstream& f) {
	cout << "Попытка обьеденить F и G\n";
	f << "Попытка обьеденить F и G\n";
	form_y ans;
	int x = 1;
	a.cur = a.head;
	while (a.cur != nullptr) {
		int y = 0;
		char aa[100];
		int sa = 0;
		a.cur->get_all_line(aa, sa);
		g.cur = g.head;
		while (g.cur != nullptr) {
			char bb[100];
			int sb = 0;
			g.cur->get_all_line(bb, sb);
			if (eq(aa, bb, sa, sb)) {
				ans.push_back(aa, sa);
				break;
			}
			g.cur = g.cur->get_next();
		}
		a.cur = a.cur->get_next();
	}
	cout << "Полученное множество\n";
	f << "Полученное множество\n";
	ans.output(f);
}

void all::is_f_in_g(ofstream& f) {
	cout << "Проверка на то что F подмножество G\n";
	f << "Проверка на то что F подмножество G\n";
	int x = 1;
	a.cur = a.head;
	while (a.cur != nullptr) {
		int y = 0;
		char aa[100];
		int sa = 0;
		a.cur->get_all_line(aa, sa);
		g.cur = g.head;
		while (g.cur != nullptr) {
			char bb[100];
			int sb = 0;
			g.cur->get_all_line(bb, sb);
			if (eq(aa, bb, sa, sb)) {
				y = 1;
				break;
			}
			g.cur = g.cur->get_next();
		}
		if (!y) {
			x = 0;
			break;
		}
		a.cur = a.cur->get_next();
	}
	if (x) {
		cout << "F подмножество G\n";
		f << "F подмножество G\n";
	}
	else {
		cout << "F не подмножество G\n";
		f << "F не подмножество G\n";
	}
}

void all::un(ofstream& f) {
	cout << "Попытка сконкатенировать f и g\n";
	f << "Попытка сконкатенировать f и g\n";
	form_y ans;
	a.cur = a.head;
	while (a.cur != nullptr) {
		char aa[100];
		int sa = 0;
		a.cur->get_all_line(aa, sa);
		ans.push_back(aa, sa);
		a.cur = a.cur->get_next();
	}
	g.cur = g.head;
	while (g.cur != nullptr) {
		char aa[100];
		int sa = 0;
		g.cur->get_all_line(aa, sa);
		ans.push_back(aa, sa);
		g.cur = g.cur->get_next();
	}
	cout << "Полученное множество:\n";
	f << "Полученное множество:\n";
	ans.output(f);
}

void all::remove(ofstream& f) {
	cout << "Попытка удалить\n";
	f << "Попытка удалить\n";
	char b[100];
	int i = 0;
	read_element(b, i, f);
	a.cur = a.head;
	a.prv = a.head;
	if (a.head == nullptr) {
		cout << "Такого элемента нет\n";
		f << "Такого элемента нет\n";
		return;
	}
	while (a.cur != nullptr) {
		char aa[100];
		int sa = 0;
		a.cur->get_all_line(aa, sa);
		if (eq(b, aa, sa, i)) {
			if (a.cur == a.head) {
				a.head = a.cur->get_next();
				
			}
			else {
				a.prv->set_next(a.cur->get_next());
			
			}
			cout << "Элемент удален\n";
			f << "Элемент удален\n";
			return;
		}
		a.prv = a.cur;
		a.cur = a.cur->get_next();
	}
	cout << "Такого элемента нет\n";
	f << "Такого элемента нет\n";
	return;
}

void all::split(ofstream& f) {
	cout << "Попытка расщепить множество\n";
	f << "Попытка расщепить множество\n";
	form_y f1, f2;
	a.cur = a.head;
	char b[100];
	int i = 0;
	read_element(b, i, f);
	int x = 0, y = 0;;
	while (a.cur != nullptr) {
		char aa[100];
		int sa = 0;
		a.cur->get_all_line(aa, sa);
		if (eq(aa, b, sa, i)) y = 1;
		a.cur = a.cur->get_next();
	}
	if (!y) {
		cout << "Нет такого элемента!\n";
		f << "Нет такого элемента!\n";
		return;
	}
	a.cur = a.head;
	while (a.cur != nullptr) {
		char aa[100];
		int sa = 0;
		a.cur->get_all_line(aa, sa);
		if (eq(aa, b, sa, i)) x = 1;
		if (!x) f1.push_back(aa, sa);
		if (x) f2.push_back(aa, sa);
		a.cur = a.cur->get_next();
	}
	cout << "Список f1:\n";
	f << "Список f1:\n";
	f1.output(f);
	cout << "Список f2:\n";
	f << "Список f2:\n";
	f2.output(f);
}

void all::plus(ofstream &f) {
	cout << "Попытка добавить элемент!\n";
	f << "Попытка добавить элемент!\n";
	system("cls");
	char b[100];
	int i = 0;
	read_element(b, i, f);
	if (a.head == nullptr) {
		a.push_back(b, i);
		return;
	}
	a.cur = a.head;
	a.prv = a.head;
	while (1) {
		char aa[100];
		int sa = 0;
		if (a.cur == nullptr) break;
		a.cur->get_all_line(aa, sa);
		if (eq(b, aa, sa, i)) {
			cout << "Такой элемент уже есть!\n";
			f << "Такой элемент уже есть!\n";
			return;
		}
		if (check(b, aa, i, sa)) {
			a.prv = a.cur;
			a.cur = a.cur->get_next();
		}
		else break;
	}
	if (a.cur == a.head) {
		a.head = (new l_y(b, i));
		a.head->set_next(a.cur);
	}
	else {
		a.prv->set_next(new l_y(b, i));
		a.prv = a.prv->get_next();
		a.prv->set_next(a.cur);
	}
	cout << "Элемент добавлен\n";
	f << "Элемент добавлен\n";
	return;
}


void all::in(ofstream& f) {
	cout << "Проверка на приналдежность\n";
	f << "Проверка на приналдежность\n";
	char b[100];
	int i = 0;
	read_element(b, i, f);
	if (a.head == nullptr) {
		cout << "Такого элемента нет\n";
		f << "Такого элемента нет\n";
		return;
	}
	a.cur = a.head;
	while (a.cur != nullptr) {
		char aa[100];
		int sa = 0;
		a.cur->get_all_line(aa, sa);
		if (eq(b, aa, sa, i)) {
			cout << "Такой элемент есть\n";
			f << "Такой элемент есть\n";
			return;
		}
		a.cur = a.cur->get_next();
	}
	cout << "Такого элемента нет\n";
	f << "Такого элемента нет\n";
	return;
}

void all::nmax(ofstream& f) {
	a.cur = a.head;
	while (a.cur->get_next() != nullptr) {
		a.cur = a.cur->get_next();
	}
	if (a.head == nullptr) {
		cout << "Список пуст - максимального элемента нет\n";
		f << "Список пуст - максимального элемента нет\n";
	}
	else {

		cout << "Максимальный элемент: ";
		f << "Максимальный элемент: ";
		a.cur->output(f);
		cout << endl;
		f << endl;
	}
}
void all::nmin(ofstream& f) {
	if (a.head == nullptr) {
		cout << "Список пуст - минимального элемента нет\n";
		f << "Список пуст - минимального элемента нет\n";

	}
	else {
		cout << "Минимальный элемент: ";
		f << "Минимальный элемент: ";
		a.head->output(f);
		cout << endl;
		f << endl;
	}
}
