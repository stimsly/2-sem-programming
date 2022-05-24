#include "all.h"

bool check(char a[100], char b[100], int aa, int bb) {
	for (int i = 0; i < min(aa,bb); i++) {
		if (a[i] < b[i]) return 0;
		if (a[i] > b[i]) return 1;
	}
	return aa > bb;
}

void all::progress() {
	a.cur = a.head;
	b.cur = b.head;
	
	char aa[100], bb[100];
	int sza = 0, szb = 0;

	while (a.cur != nullptr or b.cur != nullptr) {
		cout << a.cur << " " << b.cur << endl;
		if (a.cur == nullptr) {
			b.cur->get_all_line(bb, szb);
			if (szb)c.push_back(bb, szb);
			szb = 0;
			b.set_cur(b.cur->get_next());
			continue;
		}
		if (b.cur == nullptr) {
			a.cur->get_all_line(aa, sza);
			if (sza)c.push_back(aa, sza);
			sza = 0;
			a.set_cur(a.cur->get_next());
			continue;
		}
		b.cur->get_all_line(bb, szb);
		a.cur->get_all_line(aa, sza);
		if (!check(aa, bb, szb, sza)) {
			if (sza)c.push_back(aa, sza);
			sza = 0;
			szb = 0;
			a.set_cur(a.cur->get_next());
		}
		else {
			if(szb)c.push_back(bb, szb);
			szb = 0;
			sza = 0;
			b.set_cur(b.cur->get_next());
		}
		
	}
}