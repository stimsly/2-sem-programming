
#include <iostream>
const int n = 79;
using namespace std;
class Strin {
private:
    char s[n];
    int L = 0;
public:

    void set_1();
    void print_1();
    void run();
};

void Strin::set_1() {
    char a;
    cin >> noskipws;
    for (int i = 0; i < n; i++, L++) {
        cin >> s[i];
        cout << i << " " << s[i] << endl;
        if (s[i] == ' ') break;
    }
    //cout << L;
}
void Strin::print_1() {
    cout << L << endl;
    for (int i = 0; i < L; i++) {
        cout << s[i];
    }
}

int main()
{
    Strin s1;
    s1.set_1();
    s1.print_1();
    return 0;
}
