#include "all.h"


void all::progress(ofstream &fout_rep,int &res) {
	
	int k = 0;
	while (1) {
		burg.cur = burg.head;
		l_y* t = burg.cur;
		while (burg.cur != nullptr) {

			if (!burg.cur->try_burgering()) {
				cout << "Fail to prepair: ";
				t->output(3);
				cout << endl;
				fout_rep << "Was prepaired " << k / 2 << " burgers\n";
				mater.output(0);
				cout << "Finish\n";
				fout_rep << "Finish\n";
				return;
			}
			if (k % 2 == 0) t = burg.cur;
			if (k % 2 == 1) {
				cout << "Burger: ";
				fout_rep << "Burger: ";
				t->output(3);
				t->output(fout_rep);
				cout << " was prepaired\n";
				fout_rep << " was prepaired\n";
				fout_rep << "Materials left:\n";
				mater.output(fout_rep);

			}
			k++;
			burg.cur = burg.cur->get_next();

		}
	}
}

void all::input(ifstream& f, int t) {
	int amount[100];
	l_y* b[100];
	int bb = 0;
	char a[100];
	int aa = 0;
	int k;
	if (t == 0) {
		int n;
		f >> n;
		f.get();

		for (int i = 0; i < n; i++){
			f >> k;
			aa = 0;
			char tmp;
			f.get();
			while (1) {
				f.get(tmp);
				//cout << tmp;
				if (tmp == '\n') break;
				a[aa++] = tmp;
			}
			mater.push_back(0, a, aa, k, b, 0, amount);
		}
	}
	else if (t == 1) {
		int n;
		f >> n;
		f.get();

		for (int i = 0; i < n; i++) {
			char tmp;
			aa = 0;
			while (1) {
				f.get(tmp);
				//cout << tmp;
				if (tmp == '\n') break;
				a[aa++] = tmp;
			}
			burg.push_back(0, a, aa, 0, b, 0, amount);
			f >> k;
			//cout << k << endl;
			for (int i2 = 0; i2 < k; i2++) {
				f >> amount[i2];
				aa = 0;
				f.get();
				while (1) {
					f.get(tmp);
					//cout << tmp;
					if (tmp == '\n') break;
					a[aa++] = tmp;
				}
				l_y* cur_mat = mater.find_link(a, aa);
				//cout << cur_mat << endl;
				b[i2] = cur_mat;
			}
			burg.push_back(1, a, 0, 0, b, k, amount);
		}
	}
	else {
		cout << "????? how\n";
	}

}