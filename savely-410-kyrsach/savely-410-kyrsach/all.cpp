#include "all.h"

char low(char a) {
	if (a >= 'A' and a <= 'Z') a = a - 'A' + 'a';
	return a;
}

int all::count(char a[100], int len) {
	int ans = 0;
	for (int i = 0; i < len; i++) ans += is[a[i] - 'a'];
	return ans;
}

void all::input(ifstream& f, ofstream &fout) {
	char a[100];
	int len = 0;
	while (!f.eof()) {
		char b;
		f.get(b);
		if (f.eof()) break;
		b = low(b);
		if (b >= 'a' and b <= 'z') {
			a[len++] = b;
			//cout << b;
		}
		else {
			if (len) {
				int v = count(a, len);
				
				if (is[a[len - 1] - 'a']) {
					//fout << a[len - 1] << endl;
					fout << "ѕроихводитс€ вставка слова в список где на конце гласна€\n";
					fout << " оличество гласных: " << v << endl;
					if (!vowels.was(a, len)) {
						vowels.push_back(a, len, v, fout);
						vowels.output(fout);
						fout << "\n\n\n";
					}
					//cout << endl;
				}
				else {
					//fout << a[len - 1] << endl;
					fout << "ѕроихводитс€ вставка слова в список где на конце согласна€\n";
					fout << " оличество согласных: " << len - v << endl;
					if (!consonants.was(a, len)) {
						consonants.push_back(a, len, len - v, fout);
						consonants.output(fout);
						fout << "\n\n\n";
					}
					//cout << endl;
				}
				//cout << endl;
				len = 0;
				
			}
		}
	}
}