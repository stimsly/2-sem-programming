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
		fout << "��������� ������:\n";
		a.output(fout);
	}
	void plus(ofstream& f);// ��������
	void remove(ofstream& f);// �������
	void in(ofstream& f); // �������� �� ��������������
	void is_f_in_g(ofstream& f); // ��������� �� f ������������� g
	void f_plus_g(ofstream& f); // ���������� f � g
	void intersect(ofstream& f); // �����������
	void minus(ofstream& f); // �������� �������� f - g
	void un(ofstream& f); // �����������
	void symmetric_difference(ofstream& f); // �������������� ��������
	void split(ofstream &f); // ���������
	void nmax(ofstream& f);// ����� ����
	void nmin(ofstream& f);// ����� ���
};

#endif