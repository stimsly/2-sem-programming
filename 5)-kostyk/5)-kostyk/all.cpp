#include "all.h"

int all::progress(ofstream &f) {
	a.cur = a.head;
	int allow = 1;
	f << "Началось выполнение заданий...\n";
	int r = 1;
	int ans = 0;
	while (1) {
		if (a.cur == nullptr) break;
		
		int cur = a.cur->get_cost();
		int x = 1;
		f << r << ") Цена: " << a.cur->get_cost() << "\nЗадание: ";
		a.cur->output(f);
		r++;
		while (cur) {
			int al = 0;
			for (int i = 0; i < n; i++) al += nom[i] * amount[i];
			if (al < cur) {
				f << "Не удалось разменять эту сумму\n";
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
				f << "  не удалось разменять эту сумму\n";
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
	f << "Подытог: всего потраченое кол-во купюр " << ans << endl << endl;

	return 0;
}