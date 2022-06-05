#include "all.h"
#include <fstream>


bool check(char a[100], char b[100], int aa, int bb) {
	
	if (aa != bb) return 0;
	for (int i = 0; i < aa; i++) if (a[i] != b[i]) return 0;
	return 1;
}


void all::input(ifstream& f) {
	int n;
	f >> n;
	f.get();
	for (int i = 0; i < n; i++) {
		char book[30][30]{};
		char a;
		int j[30]{};
		while (1) {
			f.get(a);
			//cout << a;
			if (a == '\n') break;
			book[0][j[0]++] = a;
		}
		b[book[0][0] - 'a'] = 1;
		int k;
		f >> k;
		//cout << k << endl;
		f.get();
		for (int i2 = 0; i2 < k; i2++) {
			while (1) {
				f.get(a);
				//cout << a;
				if (a == '\n') break;
				
				book[i2+1][j[i2+1]++] = a;
			}
			push_back_w(book[i2+1], j[i2+1], book[0], j[0]);
			w[book[i2 + 1][0] - 'a']++;

		}
		books[book[0][0] - 'a'].push_back(k + 1, book, j);
	}
}

void all::push_back_w(char name[30], int a, char book[30], int b) {
	writers[name[0] - 'a'].push_back_w(name, a, book, b);
}

void all::output_books() {
	for (int i = 0; i < 26; i++) {
		books[i].output(1);
	}
}

void all::output_writers() {
	for (int i = 0; i < 26; i++) {
		writers[i].output(1);
	}
}

void all::output_books(char a, ofstream &f) {
	books[a - 'a'].output(0);
	cout << "Выберите книгу: ";

	int t;
	cin >> t;
	f << "Пользователь выбрал " << t << " книгу\n";
	cout << "Хотите взять эту книгу?(0 или 1): ";
	cin >> t;
	cout << endl;
	if (t) {
		books[a - 'a'].cur = books[a - 'a'].head;
		
		for (int i = 1; i < t; i++) {
			books[a - 'a'].cur = books[a - 'a'].cur->get_next();
			
		}
		
		
		f << "Пользователь забрал книжку: ";
		char b[100];
		int len;
		books[a - 'a'].cur->get_first(b, len);
		for (int i = 0; i < len; i++) f << b[i];
		f << endl;
		books[a - 'a'].remove_book(b, len, 0);
		for (int i = 0; i < 26; i++) writers[i].remove_book(b, len, 0);
	}
	else {
		char b[100];
		int len;
		f << "Пользователь не забрал книжку: ";
		books[a - 'a'].cur = books[a - 'a'].head;

		books[a - 'a'].cur->get_first(b, len);
		for (int i = 0; i < len; i++) f << b[i];
		f << endl;
		cout << "Авторы написавшие эту книгу:\n";
		for (int i = 1; i < t; i++) {
			books[a - 'a'].cur = books[a - 'a'].cur->get_next();
			
		}
		books[a - 'a'].cur->output(0, 1);
	}

}

void all::output_writers(char a, ofstream &f) {
	writers[a - 'a'].output(0);
	cout << "Выберите автора: ";
	int t;
	cin >> t;
	system("cls");
	f << "Пользователь выбрал " << t << " писателя\n";

	writers[a - 'a'].cur = writers[a - 'a'].head;
	if (writers[a - 'a'].cur == nullptr) {
		f << "Невозможно выбрать автора\n";
		return;
	}
	for (int i = 1; i < t; i++) {
		writers[a - 'a'].cur = writers[a - 'a'].cur->get_next();
		if (writers[a - 'a'].cur == nullptr) {
			f << "Невозможно выбрать автора\n";
			return;
		}
	}
	system("cls");
	cout << "Книги которые написал выбранный автор\n";
	writers[a - 'a'].cur->output(0, 1);
}
