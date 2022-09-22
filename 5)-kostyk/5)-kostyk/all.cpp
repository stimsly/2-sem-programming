#include "all.h"

int all::progress(ofstream &f) {
	a.cur = a.head;
	int allow = 1;
	f << "�������� ���������� �������...\n";
	int r = 1;
	int ans = 0;
	while (1) {
		if (a.cur == nullptr) break;
		
		int cur = a.cur->get_cost();
		int x = 1;
		f << r << ") ����: " << a.cur->get_cost() << "\n�������: ";
		a.cur->output(f);
		r++;
		while (cur) {
			int al = 0;
			for (int i = 0; i < n; i++) al += nom[i] * amount[i];
			if (al < cur) {
				f << "�� ������� ��������� ��� �����\n";
				break;
			}
			int nmax = -1;
			for (int i = 0; i < n; i++) {
				if (amount[i]) {
					if (nmax == -1 and nom[i] <= cur) nmax = i;
					else if (nom[i] > nom[nmax] and nom[i] <= cur) nmax = i;
				}
			}
			if (nmax == -1) {
				f << "  �� ������� ��������� ��� �����\n";
				allow = 0;
				break;
			}
			else {
				ans++;
				cur -= nom[nmax];
				amount[nmax]--;
				if (!x) f << "+ ";
				f << nom[nmax] << " ";
				x = 0;
			}
		}
		if (!cur) a.cur->set_c();
		f << endl << endl;
		a.cur = a.cur->get_next();
		output1(f);
	}
	f << "�������: ����� ���������� ���-�� ����� " << ans << endl << endl;

	return 0;
}