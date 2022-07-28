#include "all.h"

bool check(char a[100], char b[100], int aa, int bb) {
	if (aa > bb) return 1;
	if (aa < bb) return 0;
	for (int i = 0; i < aa; i++) {
		if (a[i] < b[i]) return 0;
		if (a[i] > b[i]) return 1;
	}
	return 0;
}

bool equal(char a[100], char b[100], int aa, int bb) {
	if (aa != bb) return 0;
	for (int i = 0; i < aa; i++) {
		if (a[i] != b[i]) return 0;
	}
	return 1;
}

void all::progress() {
	a.cur = a.head;
	b.cur = b.head;
	
	char aa[100], bb[100];
	int sza = 0, szb = 0;

	while (a.cur != nullptr and b.cur != nullptr) {
		cout << a.cur << " " << b.cur << endl;
		b.cur->get_all_line(bb, szb);
		a.cur->get_all_line(aa, sza);
		if (equal(bb, aa, szb, sza)) {
			if (sza)c.push_back(aa, sza);
			sza = 0;
			szb = 0;
			a.set_cur(a.cur->get_next());
			b.set_cur(b.cur->get_next());
			continue;
		}
		if (check(aa, bb, sza, szb)) {
			sza = 0;
			szb = 0;
			b.set_cur(b.cur->get_next());
		}
		else {
			szb = 0;
			sza = 0;
			a.set_cur(a.cur->get_next());
		}
		
	}
}