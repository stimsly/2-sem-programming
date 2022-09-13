#include "all.h"

bool check(char a[100], char b[100], int aa, int bb) {
	if (aa != bb) return 0;
	for (int i = 0; i < aa; i++) {
		if (a[i] != b[i]) return 0;
	}
	return 1;
}

int all::progress() {
	a.cur = a.head;
	
	
	char aa[100], bb[100];
	int sza = 0, szb = 0;
	int y = 1;
	while (a.cur != nullptr) {
		a.cur->get_all_line(aa, sza);
		b.cur = b.head;
		int x = 0;
		while (b.cur != nullptr) {
			b.cur->get_all_line(bb, szb);
			if (check(aa, bb, sza, szb) and b.cur->get_was() == 0) {
				b.cur->set_was();
				x = 1;
				break;
			}
			b.cur = b.cur->get_next();
		}
		if (x == 0) {
			y = 0;
			break;
		}
		a.cur = a.cur->get_next();
	}
	return y;
}