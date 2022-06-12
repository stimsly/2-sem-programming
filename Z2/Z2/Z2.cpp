#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("input.txt");

#define ll long long

ll a;
ll b;

void f(int v, int d) {
	int i = 0;
	while (d) {
		d /= 10;
		i++;
	}
	i = max(i, 1);
	cout << v << " ";
	while (i--) {
		cout << " ";
	}
	cout << " ";
}

void gcd(ll a, ll b) {
	if (b > a) {
		
	}
	int aa = 0;
	int bb = 0;
	for (int i = 0; i < 60; i++) {
		if ((1LL << i) & a) aa = i;
	}
	for (int i = 0; i < 60; i++) {
		if ((1LL << i) & b) bb = i;
	}
	//cout << a << " " << b << " " << f << " " << (b << f) << endl;
	if (bb > aa) {
		cout << endl;
		int x = 0;
		for (int i = 50; i >= 0; i--) {
			if ((1LL << i) & a) {
				cout << "Остаток\n";
				for (int j = i; j >= 0; j--) {
					cout << "x^" << j << " ";
				}
				cout << endl;
				for (int j = i; j >= 0; j--) {
					if (((1LL << j) & a)) f(1, j);
					else f(0, j);
				}
				cout << endl;
				return;
			}
		}
		return;
	}
	cout << "x^" << aa - bb << " ";
	a = a ^ (b << (aa - bb));
	if (bb >= aa) {
		cout << endl;
		int x = 0;
		for (int i = 50; i >= 0; i--) {
			if ((1LL << i) & a) {
				cout << "Остаток\n";
				for (int j = i; j >= 0; j--) {
					cout << "x^" << j << " ";
				}
				cout << endl;
				for (int j = i; j >= 0; j--) {
					if (((1LL << j) & a)) f(1, j);
					else f(0, j);
				}
				cout << endl;
				return;
			}
		}
		return;
	}
	gcd(a, b);
}

int main(){
	int n, m;
	setlocale(LC_ALL, "Russian");
	cout << "Введи старшую степень первого многочлена: ";
	fin >> n;
	cout << "Введи старшую степень второго многочлена: ";
	fin >> m;
	cout << n << " " << m << endl;
	cout << endl;
	for (int i = n; i >= 0; i--) {
		cout << i << " ";
	}
	cout << endl;
	for (ll i = n; i >= 0; i--) {
		ll x;
		fin >> x;
		a |= (x << i);
	}
	cout << endl;
	for (int i = m; i >= 0; i--) {
		cout << i << " ";
	}
	cout << endl;
	for (ll i = m; i >= 0; i--) {
		ll x;
		fin >> x;
		b |= (x << i);
	}
	cout << endl;
	gcd(a, b);

}