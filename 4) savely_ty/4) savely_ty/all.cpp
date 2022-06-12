#include "all.h"

bool check(char a[100], char b[100], int aa, int bb) {
	if (aa != bb) return 0;
	for (int i = 0; i < min(aa,bb); i++) {
		if (a[i] != b[i]) return 0;
	}
	return 1;
}

void all::progress() {
	a.cur = a.head;
	char aa[100], bb[100], cc[100];
	int sza = 0, szb = 0, szc = 0;
	szb = 0;
	b.cur = b.head;

	while (a.cur != nullptr) {
		int x = 1;
		a.cur->get_all_line(aa, sza);
		b.cur = b.head;

		while (b.cur != nullptr) {
			b.cur->get_all_line(bb, szb);
			if (check(aa, bb, sza, szb)) {
				x = 0;
				break;
			}
			b.set_cur(b.cur->get_next());
			szb = 0;
		}
		c.cur = c.head;
		while (c.cur != nullptr) {
			c.cur->get_all_line(cc, szc);
			if (check(aa, cc, sza, szc)) {
				x = 0;
				break;
			}
			c.set_cur(c.cur->get_next());
			szc = 0;
		}
		a.set_cur(a.cur->get_next());

		if (x) c.push_back(aa, sza);
		sza = 0;

	}

}