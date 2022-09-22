#include <bits/stdc++.h>
#include <fstream>

using namespace std;

const int N = 60;

class str {
public:
	char a[N]{};
	char letter;
	int len = 0;
} s;

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
	int len = 0;
	n = max(0, min(n, N));
	while (f_s.get(s.a[len]) && len < n && (s.a[len] != o || o == ' ')) {
		len++;
	}
	s.len = len;
}
void out(ofstream& f) {
	for (int i = 0; i < s.len; i++) f << s.a[i];
	if (s.len == 0) f << "empty";
	f << endl;
}
void process() {
	for (int i = 0; i < s.len - 1;) {
		if (s.a[i] == ' ' and s.a[i + 1] == ' ') { // если два пробела рядом убираем один из
			for (int j = i + 1; j < s.len - 1; j++) s.a[j] = s.a[j + 1];
			s.len--;
		}
		else {
			i++;
		}
	}
}


int main() {
	int t;
	cin >> t;

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	inp(fin, t);
	fout << "Primary string: ";
	out(fout);
	process();
	fout << "Result string: ";
	out(fout);
	return 0;
}