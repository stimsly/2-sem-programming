#include <iostream>
#include <fstream>
#include "form_y.h"
using namespace std;

int main()
{
    ifstream f("l.txt");
    ofstream fout("output.txt");
    form_y a;
    a.input(f);
    fout << "Primary list:\n";
    a.output(fout);
    a.progress();
    fout << "Result list:\n";
    a.output(fout);
}