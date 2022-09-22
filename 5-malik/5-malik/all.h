#pragma once
#include "form_y.h"

#ifndef ALL_H
#define ALL_H

class all {
public:
	form_y a, g;
	
	void input(ifstream &f, ifstream &f2) {
		a.input(f);
		g.input(f2);
	}
	void output(ofstream& fout) {
		fout << "Финальный список:\n";
		a.output(fout);
	}
	void plus(ofstream& f);// добавить
	void remove(ofstream& f);// удалить
	void in(ofstream& f); // проверка на принадлежность
	void is_f_in_g(ofstream& f); // являеться ли f подмножеством g
	void f_plus_g(ofstream& f); // обьеденить f и g
	void intersect(ofstream& f); // пересечение
	void minus(ofstream& f); // разность множеств f - g
	void un(ofstream& f); // обьеденение
	void symmetric_difference(ofstream& f); // симметрическая разность
	void split(ofstream &f); // расщепить
	void nmax(ofstream& f);// найти макс
	void nmin(ofstream& f);// найти мин
};

#endif