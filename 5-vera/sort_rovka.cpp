#include"ALPHA_LIST.h"

void sort_rovka(ALPHA* p, ofstream& r)
{
	p->c3 = p->h3;
	while (p->c3 != nullptr) {
		p->c4 = p->c3;
		p->c4 = p->c4->next;
		while (p->c4 != nullptr)
		{
			if (p->c3->base.raznica < p->c4->base.raznica)
			{
				p->c3->base.temp = p->c3->base.raznica;
				p->c3->base.raznica = p->c4->base.raznica;
				p->c4->base.raznica = p->c3->base.temp;
				p->c3->base.temp = p->c3->base.number_of_letter1;
				p->c3->base.number_of_letter1 = p->c4->base.number_of_letter1;
				p->c4->base.number_of_letter1 = p->c3->base.temp;
				p->c3->base.c = p->c3->base.Country_P;
				p->c3->base.Country_P = p->c4->base.Country_P;
				p->c4->base.Country_P = p->c3->base.c;
				p->c3->base.c1 = p->c3->base.Letter;
				p->c3->base.Letter = p->c4->base.Letter;
				p->c4->base.Letter = p->c3->base.c1;
			}
			p->c4 = p->c4->next;
		}
		p->c3 = p->c3->next;
	}
	int ptr = 1;
	r << "\n\nÓÏÎÐßÄÎ×ÈÌ ÑÏÈÑÎÊ ÏÎ ÓÁÛÂÀÍÈÞ ÏÎ ÑÒÎÈÌÎÑÒÈ, ÊÎÒÎÐÓÞ ÍÓÆÍÎ ÏÎÊÐÛÒÜ\n\n";
	outputV4(p, r, ptr);
}

void sort_rovka_marok(ALPHA* p, ofstream& r, int& ptr, ofstream& r1)
{
	p->c2 = p->h2;
	while (p->c2 != nullptr) {
		p->c5 = p->c2;
		p->c5 = p->c5->next;
		while (p->c5 != nullptr)
		{
			if (p->c2->base.stoimost_int < p->c5->base.stoimost_int)
			{
				p->c2->base.temp = p->c2->base.stoimost_int;
				p->c2->base.stoimost_int = p->c5->base.stoimost_int;
				p->c5->base.stoimost_int = p->c2->base.temp;
				p->c2->base.temp = p->c2->base.kolvo_int;
				p->c2->base.kolvo_int = p->c5->base.kolvo_int;
				p->c5->base.kolvo_int = p->c2->base.temp;
			}
			p->c5 = p->c5->next;
		}
		p->c2 = p->c2->next;
	}
	r << "\n\nÓÏÎÐßÄÎ×ÈÌ ÑÏÈÑÎÊ ÏÎ ÓÁÛÂÀÍÈÞ ÏÎ ÑÒÎÈÌÎÑÒÈ ÌÀÐÊÈ\n\n";
	ptr = 2;
	outputV3(p, r, ptr, r1);
	ptr = 1;
}

void bubble_marki(ALPHA* p, ofstream& r)
{
	p->c2 = p->h2;
	while (p->c2 != nullptr) {
		p->c5 = p->c2;
		p->c5 = p->c5->next;
		while (p->c5 != nullptr)
		{
			if (p->c2->base.stoimost_int > p->c5->base.stoimost_int)
			{
				p->c2->base.temp = p->c2->base.stoimost_int;
				p->c2->base.stoimost_int = p->c5->base.stoimost_int;
				p->c5->base.stoimost_int = p->c2->base.temp;
				p->c2->base.temp = p->c2->base.kolvo_int;
				p->c2->base.kolvo_int = p->c5->base.kolvo_int;
				p->c5->base.kolvo_int = p->c2->base.temp;
			}
			p->c5 = p->c5->next;
		}
		p->c2 = p->c2->next;
	}
	r << "\n\nÓÏÎÐßÄÎ×ÈÌ ÑÏÈÑÎÊ ÏÎ ÂÎÇÐÀÑÒÀÍÈÞ ÏÎ ÑÒÎÈÌÎÑÒÈ ÌÀÐÊÈ\n\n";
	int ptr = 2;
	ofstream r1;
	outputV3(p, r, ptr, r1);
	ptr = 1;
}

void bubble_pisma(ALPHA* p, ofstream& r)
{
	p->c6 = p->h6;
	while (p->c6 != nullptr) {
		p->c7 = p->c6;
		p->c7 = p->c7->next;
		while (p->c7 != nullptr)
		{
			if (p->c6->base.number_of_letter > p->c7->base.number_of_letter)
			{
				for (int i = 0; i < p->c6->base.kolvo; i++)
				{
					p->c6->base.tmp[i] = p->c6->base.stoimost[i];
				}
				for (int i = 0; i < p->c7->base.kolvo; i++)
				{
					p->c6->base.stoimost[i] = p->c7->base.stoimost[i];
				}
				for (int i = 0; i < p->c6->base.kolvo; i++)
				{
					p->c7->base.stoimost[i] = p->c6->base.tmp[i];
				}
				p->c6->base.temp = p->c6->base.number_of_letter;
				p->c6->base.number_of_letter = p->c7->base.number_of_letter;
				p->c7->base.number_of_letter = p->c6->base.temp;
				p->c6->base.temp = p->c6->base.kolvo;
				p->c6->base.kolvo = p->c7->base.kolvo;
				p->c7->base.kolvo = p->c6->base.temp;
				p->c6->base.c = p->c6->base.Country;
				p->c6->base.Country = p->c7->base.Country;
				p->c7->base.Country = p->c6->base.c;
			}
			p->c7 = p->c7->next;
		}
		p->c6 = p->c6->next;
	}
}