#include "all.h"

bool all::progress() {
	int l1a[N * N];
	int l2a[N * N];
	int sl1 = 0;
	int sl2 = 0;
	int pl1 = 0;
	int pl2 = 0;
	int kl1 = -1;
	int kl2 = -1;
	while (1) {
		if (pl1 == sl1) {
			kl1++;
			l1.find(l1a, sl1, kl1);
			//cout << sl1 << " " << kl1 << endl;
			if (sl1 == N * N * 2) return true;
			//cout << sl1 << " " << kl1 << endl;
			//for (int i = 0; i < sl1; i++) cout << l1a[i] << " ";
			//cout << endl;
			pl1 = 0;
			continue;
		}
		if (pl2 == sl2) {
			kl2++;
			l2.find(l2a, sl2, kl2);
			//cout << "second " << sl2 << " " << kl2 << endl;
			if (sl2 == N * N * 2) return false;
			//for (int i = 0; i < sl2; i++) cout << l2a[i] << " ";
			//cout << endl;
			pl2 = 0;
			continue;
		}
		//cout << pl1 << " " << l1a[pl1] << " " << pl2 << " " << l2a[pl2] << endl;
		if (sl1 == N * N * 2) return true;
		if (sl2 == N * N * 2) return false;
		if (l1a[pl1] == l2a[pl2]) {
			pl1++;
			pl2++;
			continue;
		}
		if (l1a[pl1] < l2a[pl2]) return false;
		if (l1a[pl1] > l2a[pl2]) {
			pl2++;
			continue;
		}
	}

	return true;
}