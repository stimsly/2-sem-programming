#include "all.h"

bool cheak(char a[100], char b[100], int aa, int bb) {
	if (aa != bb) return 0;
	for (int i = 0; i < aa; i++) {
		if (a[i] != b[i]) return 0;
	}
	return 1;
}

void all::progress() {
	a.cur = a.head;
	// у b есть только head
	char aa[100], bb[100];
	int sza = 0, szb = 0;
	b.head->get_all_line(bb, szb);
	a.prv = nullptr;
	bool d_next = 0;
	while (a.cur != nullptr) {
		
		cout << a.prv << endl << a.cur << endl;
		a.cur->get_all_line(aa, sza);
		if (!d_next) {
			if (cheak(aa, bb, sza, szb)) {
				d_next = 1;
			}
			a.prv = a.cur;
			a.set_cur(a.cur->get_next());
		}
		else {
			if (!cheak(aa, bb, sza, szb)) {
				d_next = 0;
				l_y* cur2 = a.cur;
				a.set_cur(a.cur->get_next());
				a.prv->set_next(a.cur);
				delete cur2;
			}
			else {
				a.prv = a.cur;
				a.set_cur(a.cur->get_next());
			}
		}
		cout << d_next << endl;
		sza = 0;
		
	}
}