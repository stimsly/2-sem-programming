#include"ALPHA_LIST.h"

void outputV(ALPHA* p, ofstream& r, int& ptr, ofstream& r1) {
	p->c = p->h;
	while (p->c != nullptr) {
		output(p->c->base, r, ptr, r1);
		r << endl;
		p->c = p->c->next;
		if (ptr == 0)
			r << endl << "||" << endl << "\\/" << endl;
	}
	if (ptr == 0)
		r << "NULL" << "\n\n";
}

void output(List p, ofstream& r, int& ptr, ofstream& r1) {
	p.c = p.Letter;
	if (p.c != nullptr) {
		while (p.c != nullptr) {
			for (int i = 0; i < p.c->el.l; i++)
			{
				if (ptr == 0)
				{
					r << p.c->el.str[i];
				}
				if (ptr == 1)
				{
					r << p.c->el.str[i];
					r1 << p.c->el.str[i];
				}
			}
			if(ptr==0)
			r << " -> ";
			p.c = p.c->next;
		}
		if (ptr == 0)
		{
			r << "NULL";
			r << "\n" << "�" << " " << p.number_of_letter << "\n";
		}
		if (ptr == 1)
		{
			r << " " << "�" << p.number_of_letter << "\n";
			r1 << " " << "�" << p.number_of_letter << "\n";
		}
	}
	else
		r << "������ �������";
	p.c1 = p.Country;
	if (ptr == 1)
	{
		r1 << "������: ";
		r << "������: ";
	}
	if (p.c1 != nullptr) {
		while (p.c1 != nullptr) {
			for (int i = 0; i < p.c1->el.l; i++)
			{
				if (ptr == 0)
				{
					r << p.c1->el.str[i];
				}
				if (ptr == 1)
				{
					r << p.c1->el.str[i];
					r1 << p.c1->el.str[i];
				}
			}
			if(ptr==0)
			r << " -> ";
			p.c1 = p.c1->next;
		}
		if (ptr == 0)
		{
			r << "NULL";
			r << "\n" << "��������� �������� � ������� �� ��������� ������: " << "\n" << p.StarTar << "\n\n";
		}
		if (ptr == 1)
		{
			r << "\n" << "��������� �������� � ������� �� ��������� ������: " << "\n" << p.StarTar << "\n\n";
			r1 << "\n" << "��������� �������� � ������� �� ��������� ������: " << "\n" << p.StarTar << "\n\n";
		}
	}
	else
		r << "������ �������";

}

void outputV2(ALPHA* p, ofstream& r, int& ptr, ofstream& r1) {
	p->c1 = p->h1;
	while (p->c1 != nullptr) {
		output2(p->c1->base, r, ptr, r1);
		r << endl;
		p->c1 = p->c1->next;
		if (ptr == 0)
		r << endl << "||" << endl << "\\/" << endl;
	}
	if (ptr == 0)
	r << "NULL";
}

void output2(dopList p, ofstream& r, int& ptr, ofstream& r1) {
	if (ptr == 1)
	{
		r << "������: ";
		r1 << "������: ";
	}
	p.c = p.Country_N;
	if (p.c != nullptr) {
		while (p.c != nullptr) {
			for (int i = 0; i < p.c->el.l; i++)
			{
				if (ptr == 0)
				{
					r << p.c->el.str[i];
				}
				if (ptr == 1)
				{
					r << p.c->el.str[i];
					r1 << p.c->el.str[i];
				}
			}
			if (ptr == 0)
			r << " -> ";
			p.c = p.c->next;
		}
		if (ptr == 0) {
			r << "NULL";
			r << "\n" << "����� �����: " << p.NovTar << "\n";
		}
		if (ptr == 1)
		{
			r << "\n" << "����� �����: " << p.NovTar << "\n\n";
			r1 << "\n" << "����� �����: " << p.NovTar << "\n\n";
		}
	}
	else
		r << "������ �������";
}

void outputV3(ALPHA* p, ofstream& r, int& ptr, ofstream& r1) {
	p->c2 = p->h2;
	while (p->c2 != nullptr) {
		output3(p->c2->base, r, ptr, r1);
		r << endl;
		p->c2 = p->c2->next;
		if (ptr == 0)
		r << endl << "||" << endl << "\\/" << endl;
	}
	if (ptr == 0)
	r << "NULL";
}

void output3(marki p, ofstream& r, int& ptr, ofstream& r1) {
	p.c = p.stoimost;
	if (p.c != nullptr) {
		while (p.c != nullptr) {
			for (int i = 0; i < p.c->el.l; i++)
			{
				if (ptr == 0)
				{
					r << p.c->el.str[i];
				}
				if (ptr == 1)
				{
					r << p.c->el.str[i];
					r1 << p.c->el.str[i];
				}
				if (ptr == 2)
				{
					r << p.c->el.str[i];
				}
			}
			if (ptr == 0)
			r << " -> ";
			p.c = p.c->next;
		}
		if (ptr == 0) {
			r << "NULL";
			r << "\n" << p.stoimost_int << "\n";
		}
		if (ptr == 1)
		{
			r << " " << p.stoimost_int << " ���." << "\n";
			r1  << " " << p.stoimost_int << " ���." << "\n";
		}
		if (ptr == 2)
		{
			r << " " << p.stoimost_int << " ���." << "\n";
		}
	}
	else
		r << "������ �������";
	p.c1 = p.kolvo;
	if (p.c1 != nullptr) {
		while (p.c1 != nullptr) {
			for (int i = 0; i < p.c1->el.l; i++)
			{
				if (ptr == 0)
				{
					r << p.c1->el.str[i];
				}
				if (ptr == 1)
				{
					r << p.c1->el.str[i];
					r1 << p.c1->el.str[i];
				}
				if (ptr == 2)
				{
					r << p.c1->el.str[i];
				}
			}
			if (ptr == 0)
			r << " -> ";
			p.c1 = p.c1->next;
		}
		if (ptr == 0) {
			r << "NULL";
			r << "\n" << p.kolvo_int << "\n";
		}
		if (ptr == 1)
		{
			r << ": " << p.kolvo_int << "\n\n";
			r1 << ": " << p.kolvo_int << "\n\n";
		}
		if (ptr == 2)
		{
			r << ": " << p.kolvo_int << "\n\n";
		}
	}
	else
		r << "������ �������";
}

void outputV4(ALPHA* p, ofstream& r, int& ptr) {
	p->c3 = p->h3;
	while (p->c3 != nullptr) {
		output4(p->c3->base, r);
		r << endl;
		p->c3 = p->c3->next;
	}
	if (ptr == 0)
		r << "NULL";
}

void output4(pomoch p, ofstream& r) {
	p.c1 = p.Letter;
	if (p.c1 != nullptr) {
		while (p.c1 != nullptr) {
			for (int i = 0; i < p.c1->el.l; i++)
			{
				r << p.c1->el.str[i];
			}
			p.c1 = p.c1->next;
		}
		r <<  " �" << p.number_of_letter1 << "\n";
	}
	r << "������: ";
	p.c = p.Country_P;
	if (p.c != nullptr) {
		while (p.c != nullptr) {
			for (int i = 0; i < p.c->el.l; i++)
			{
					r << p.c->el.str[i];
			}
			p.c = p.c->next;
		}
		r << "\n���������, ������� ����� ������� �������:\n";
		r << p.raznica << "\n\n";
	}
	else
		r << "������ �������";
}

void outputV5(ALPHA* p, ofstream& r, int& ptr)
{
	p->c6 = p->h6;
		while (p->c6 != nullptr) {
			r << "������ �" << p->c6->base.number_of_letter << "\n";
			r << "������: ";
			p->c6->base.c = p->c6->base.Country;
			if (p->c6->base.c != nullptr) {
				while (p->c6->base.c != nullptr) {
					for (int i = 0; i < p->c6->base.c->el.l; i++)
					{
						r << p->c6->base.c->el.str[i];
					}
					p->c6->base.c = p->c6->base.c->next;
				}
				r << "\n���������� �����, ������� ����������:\n";
				r << p->c6->base.kolvo << "\n";
				r << "��������� �����, ������� ����������:\n";
				for (int i = 0; i < p->c6->base.kolvo; i++)
				{
					r << p->c6->base.stoimost[i] << " ";
				}
				r << endl << endl;
			}
			p->c6 = p->c6->next;
		}
		if (ptr == 0)
			r << "NULL";
}