#include <iostream>

using namespace std;

#define ll long long

ll a;
ll b;

void gcd(ll a, ll b) {
	if (b > a) {
		cout << endl;
		int x = 0;
		for (int i = 50; i >= 0; i--) {
			if ((1LL << i) & a) {
				cout << "Остаток\n";
				for (int j = i; j >= 0; j--) {
					cout << "x" << j << " ";
				}
				cout << endl;
				for (int j = i; j >= 0; j--) {
					if (((1LL << j) & a)) cout << "1 ";
					else cout << "0 ";
				}
				cout << endl;
				return;
			}
		}
		return;
	}
	int f = 0;
	while ((b << f) * 2 < a) f++;
	//cout << a << " " << b << " " << f << " " << (b << f) << endl;
	cout << "x" << f << " ";
	a = a ^ (b << f);
	gcd(a, b);
}

int main(){
	int n, m;
	setlocale(LC_ALL, "Russian");
	cout << "Введи старшую степень первого многочлена: ";
	cin >> n;
	cout << "Введи старшую степень второго многочлена: ";
	cin >> m;
	cout << endl;
	for (int i = n; i >= 0; i--) {
		cout << i << " ";
	}
	cout << endl;
	for (ll i = n; i >= 0; i--) {
		ll x;
		cin >> x;
		a |= (x << i);
	}
	cout << endl;
	for (int i = m; i >= 0; i--) {
		cout << i << " ";
	}
	cout << endl;
	for (ll i = m; i >= 0; i--) {
		ll x;
		cin >> x;
		b |= (x << i);
	}
	cout << endl;
	gcd(a, b);

}