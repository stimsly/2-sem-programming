#include"ALPHA_LIST.h"

void sortirovka(ALPHA* l, dopList p, List p1, ofstream& r)
{
	r << "ÏÐÎÕÎÄÈÌ ÏÎ ÍÀÇÂÀÍÈßÌ ÑÒÐÀÍ, ×ÒÎÁÛ ÏÎÍßÒÜ, ÍÀÑÊÎËÜÊÎ ÈÇÌÅÍÈËÑß ÒÀÐÈÔ\n\n";
	int k = 0, k1=0;
		p.c = p.Country_N;
		if (p.c != nullptr) {
			p1.c = p1.Country;
			while (p.c != nullptr) {
				k1++;
				if (p1.c != nullptr) {
					int i, j, h = 0;
					char a[N], b[N];
					for (i = 0; i < p.c->el.l; i++)
					{
						a[i] = p.c->el.str[i];
						r << p.c->el.str[i];
					}
					r << endl << endl;
					for (j = 0; j < p1.c->el.l; j++)
					{
						b[j] = p1.c->el.str[j];
						r << p1.c->el.str[j];
					}
					r << endl << endl;
					if (j == i)
					{
						for (j = 0; j < i; j++)
							if (b[j] == a[j])
								h++;
						if (h == i)
						{
							k++;
							r << "ÝËÅÌÅÍÒÛ ÑÏÈÑÊÎÂ ÐÀÂÍÛ\n\n";
						}
						else
						{
							k = 0;
							r << "ÝËÅÌÅÍÒÛ ÑÏÈÑÊÎÂ ÍÅ ÐÀÂÍÛ\n\n";
							break;
						}
					}
					else
					{
						k = 0;
						r << "ÝËÅÌÅÍÒÛ ÑÏÈÑÊÎÂ ÍÅ ÐÀÂÍÛ\n\n";
						break;
					}
					p1.c = p1.c->next;
				}
				else
				{
					k = 0;
					r << "NULL\n\n";
					break;
				}
				p.c = p.c->next;
			}
			if (k == k1)
			{
				sortirovka2(l, p, p1, r);
			}
		}
		else
			r << "NULL\n\n";
}

void sortirovka1(ALPHA* p, ofstream& r) {
	p->c1 = p->h1;
	while (p->c1 != nullptr) {
		p->c = p->h;
		while (p->c != nullptr) {
			sortirovka(p, p->c1->base, p->c->base, r);
			p->c = p->c->next;
		}
		p->c1 = p->c1->next;
	}
	r << "ÍÎÂÛÉ ÑÏÈÑÎÊ ÏÈÑÅÌ\n\n";
	int ptr = 1;
	outputV4(p, r, ptr);
}

void sortirovka2(ALPHA* a, dopList p, List p1, ofstream& r) {
	r << "ÍÀÕÎÄÈÌ ÐÀÇÍÈÖÓ ÌÅÆÄÓ ÑÒÀÐÎÉ È ÍÎÂÎÉ ÖÅÍÎÉ\n\n";
	int k = 0;
	if (p1.StarTar < p.NovTar)
		k = p.NovTar - p1.StarTar;
	r << "ÄÎÁÀÂÈÌ ÍÎÂÛÅ ÄÀÍÍÛÅ Â ÑÏÈÑÎÊ, ÕÐÀÍßÙÈÉ ÄÀÍÍÛÅ Î ÐÀÇÍÈÖÅ, ÊÎÒÎÐÓÞ ÍÓÆÍÎ ÏÎÊÐÛÒÜ ÌÀÐÊÀÌÈ\n\n";
	pomoch* q = new pomoch;
	q->raznica = k;
	q->Country_P = p1.Country;
	q->Letter = p1.Letter;
	q->number_of_letter1 = p1.number_of_letter;
	push_back4(a, q);
}