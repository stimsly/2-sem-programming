#include <iostream>
#include "all.h";

ifstream fin("text.txt");
ofstream fout("report.txt");
all a;

int main()
{
    a.input(fin, fout);
    a.output(fout);
    a.clear();
}
