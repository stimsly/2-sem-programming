#include"FormV.h"

int obrabotka4(FormG p, FormG p1, int& k) {
	int elm = 0;
	p.c = p.h;
	cout << "TEST5" << endl;
if (p.c != nullptr) {
	while (p.c != nullptr) {
		cout << "TEST4" << endl;
		k = 0;
		p1.c = p1.h;
		while (p1.c != nullptr) {
			int i, j, h = 0;
			char a[N], b[N];
			k = 0;
			cout << "1 elem: " << endl;
			for (i = 0; i < p.c->el.l; i++)
			{
				a[i] = p.c->el.stroka[i];
				cout << p.c->el.stroka[i];
			}
			cout << endl << endl << "2 elem: " << endl;
			for (j = 0; j < p1.c->el.l; j++)
			{
				b[j] = p1.c->el.stroka[j];
				cout << p1.c->el.stroka[j];
			}
			cout << endl << endl;
			if (j == i)
			{
				for (j = 0; j < i; j++)
					if (b[j] == a[j])
					{
						h++;
						cout << b[j] << "  " << a[j] << endl;
					}
				if (h == i)
				{
					k++;
				}
			}
			if (k > 0)
			{
				k = -1;
				cout << "TEST1" << endl;
				break;
			}
			p1.c = p1.c->next;
		}
		if (k != -1)
			break;
		p.c = p.c->next;
	}
	if (k == -1)
	{
		cout << "TEST6" << endl;
		p1.c = p1.h;
		while (p1.c != nullptr) {
			cout << "TEST7" << endl;
			k = 0;
			p.c = p.h;
			while (p.c != nullptr) {
				int i, j, h = 0;
				char a[N], b[N];
				k = 0;
				cout << "1 elem: " << endl;
				for (i = 0; i < p.c->el.l; i++)
				{
					a[i] = p.c->el.stroka[i];
					cout << p.c->el.stroka[i];
				}
				cout << endl << "2 elem: " << endl;
				for (j = 0; j < p1.c->el.l; j++)
				{
					b[j] = p1.c->el.stroka[j];
					cout << p1.c->el.stroka[j];
				}
				cout << endl;
				if (j == i)
				{
					for (j = 0; j < i; j++)
						if (b[j] == a[j])
						{
							h++;
							cout << b[j] << "  " << a[j] << endl;
						}
					if (h == i)
					{
						k++;
					}
				}
				if (k > 0)
				{
					elm++;
					k = -1;
					break;
				}
				p.c = p.c->next;
			}
			if (k != -1)
				break;
			p1.c = p1.c->next;
		}
	}
}
else
k = -1;
	return k;
}

int obrabotka3(FormV* p) {
	int i = 0;
	int k = -1;
	p->c = p->h;
		while (p->c != nullptr) {
			cout << "TEST2" << endl;
			p->c1 = p->h1;
			k = 0;
			while (p->c1 != nullptr) {
				obrabotka4(p->c->G, p->c1->G, k);
				if (k == -1)
					break;
				p->c1 = p->c1->next;
			}
			if (k != -1)
				break;
			p->c = p->c->next;
		}
		if (k == -1)
		{
			p->c1 = p->h1;
			while (p->c1 != nullptr) {
				cout << "TEST3" << endl;
				p->c = p->h;
				k = 0;
				while (p->c != nullptr) {
					obrabotka4(p->c1->G, p->c->G, k);
					if (k == -1)
						break;
					p->c = p->c->next;
				}
				if (k != -1)
					break;
				p->c1 = p->c1->next;
			}
		}
	if (k == -1)
		cout << "SOVPALI" << " ";
	else
		cout << "NE SOVPALI" << " ";
	return k;
}