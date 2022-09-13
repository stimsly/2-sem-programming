#include <bits/stdc++.h>
#include <fstream>

using namespace std;

const int N = 60;

class str {
private:
	char a[N];
	char letter;
	int len = 0;
public:
	int getlen() {
		return len;
	}
	void setlen(int t) {
		len = t;
	}
	char get_char(int i) {
		return a[i];
	}
	void inp(ifstream& f_s, int t) { // считываем строку 
		if (!f_s.is_open()) {
			cout << "File(s) can not be open!";
			return;
		}
		char o = ' ';
		int n = N;
		if (t == 1) {
			f_s.get(o); // если считываем до маркера
		}
		else {
			f_s >> n;// если определенное кол во символов
			f_s.get();
		}
		n = max(0, min(n, N));
		while (f_s.get(a[len]) && len < n && (a[len] != o || o == ' ')) {
			len++;
		}
	}
	void out(ofstream& f) {
		for (int i = 0; i < len; i++) f << a[i];
		if (len == 0) f << "empty";
		f << endl;
	}
	void process() {
		for (int i = 0; i < len - 1;) {
			if (a[i] == ' ' and a[i + 1] == ' ') { // если два пробела рядом убираем один из
				for (int j = i + 1; j < len - 1; j++) a[j] = a[j + 1];
				len--;
			}
			else {
				i++;
			}
		}
		setlen(len);
	}
};


int main() {
	int t;
	cin >> t;

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	str s;

	s.inp(fin, t);
	fout << "Primary string: ";
	s.out(fout);
	s.process();
	fout << "Result string: ";
	s.out(fout);
	return 0;
}