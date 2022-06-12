#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.txt");

void f(int v, int i) {
    int d = 0;
    while (i) {
        i /= 10;
        d++;
    }
    d += 2;
    cout << v;
    while (d--) cout << " ";
}

void ff(long long res) {
    for (int k = 15; k >= 0; k--) cout << "x^" << k << " ";
    cout << endl;
    for (int k = 15; k >= 0; k--) {
        if ((1 << k) & res) {
            f(1, k);
        }
        else f(0, k);
    }
    cout << endl;
}

int main()
{
    long long a = 0;
    long long n;
    fin >> n;
    for (int i = n; i >= 0; i--) {
        long long x;
        fin >> x;
        a += (x << i);
    }
    for (int i = 0; i < (1LL << (n + 1)); i++) {
        for (int j = 0; j < (1LL << (n + 1)); j++) {
            long long res = 0;
            for (int k = 0; k < 15; k++) {
                if ((1 << k) & j) {
                    res = ((i << k)) ^ res;
                    //ff(res);
                }
            }
            if (res == a) {

                cout << "new\n";
                for (int k = 15; k >= 0; k--) cout << "x^" << k << " ";
                cout << endl;
                for (int k = 15; k >= 0; k--) {
                    if ((1 << k) & i) {
                        f(1, k);
                    }
                    else f(0, k);
                }
                cout << endl;

                for (int k = 15; k >= 0; k--) cout << "x^" << k << " ";
                cout << endl;
                for (int k = 15; k >= 0; k--) {
                    if ((1 << k) & j) {
                        f(1, k);
                    }
                    else f(0, k);
                }
                cout << endl;
                cout << endl;
            }
        }
    }

    //std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
