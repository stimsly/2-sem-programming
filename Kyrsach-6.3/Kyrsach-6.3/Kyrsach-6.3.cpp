#include <iostream>
#include <fstream>
#include <Windows.h>
#include "all.h"

using namespace std;

ifstream fin_comp("components.txt");
ifstream fin_prod("products.txt");
//ifstream fin_comp("components.txt");
ofstream fout_rep("report.txt");
all prog;
int res = 0;
void menu() {
	int t = 0;
	report a;
	cout << "Choose an action:\n" <<
		"1.Output list of products\n" <<
		"2.Output list of materials\n" <<
		"3.Start baking\n" <<
		"4.Add resourses\n" <<
		"0.Exit\n" << 
		"Your chose: ";
	cin >> t;
	if (t < 0 or t > 4) {
		system("cls");
		cout << "Wrong number try again!\n\n";
		a.output_mes("This man try to enter the wrong number))))#", fout_rep);
		menu();
	}
	if (!t) {
		a.output_mes("End of programm#", fout_rep);
		return;
	}
	system("cls");
	if (t == 1) {
		a.output_mes("This man ask about list of products(he enter 1)#", fout_rep);
		prog.output_prod();
		system("pause");
		system("cls");
		menu();
	}
	else if (t == 2) {
		a.output_mes("This man ask about list of materials(he enter 2)#", fout_rep);
		prog.output_mater();
		system("pause");
		system("cls");
		menu();
	}
	else if(t == 3) {
		a.output_mes("This man start baking))#", fout_rep);
		prog.progress(fout_rep, res);
		system("pause");
		system("cls");
		menu();
		
	}
	else if (t == 4) {
		a.output_mes("This man add some materials))#", fout_rep);
		prog.add();
		system("pause");
		system("cls");
		menu();
	}
	
}

int main()
{
	setlocale(LC_ALL, "Russian");
	prog.input(fin_prod, fin_comp, fout_rep);
	menu();
	return 0;
}
