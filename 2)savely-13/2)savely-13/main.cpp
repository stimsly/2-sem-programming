#include <bits/stdc++.h>
#include <fstream>
#include "text.h";

using namespace std;


int main() {
	ifstream f("input.txt");
	ofstream f2("output.txt");

	text a;
	
	a.input(f);
	f2 << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Primary text: \n";
	a.output(f2);
	f2 << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>END.\n\n";
	f2 << "Total number of lines is: " << a.get_l() << endl;
	a.progress();
	f2 << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Result Text: \n";
	a.output(f2);
	f2 << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>END";
	f2 << "Total number of lines is: " << a.get_l() << endl;
	return 0;
}