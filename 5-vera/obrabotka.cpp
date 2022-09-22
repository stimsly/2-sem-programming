#include "ALPHA_LIST.h"

void obrabotka(ALPHA* p, ofstream& r, ofstream& r1) {
	p->c3 = p->h3;
	int k = 0;
	rezult* q = new rezult;
	int raz = 0, kolvo = 0, kolvo_marok = 0;
	raz = raznica(p, kolvo);
	kolvo_marok = kolvo_marok1(p);
	p->c3 = p->h3;
	while (p->c3 != nullptr)
	{
		p->c2 = p->h2;
		q->Country = p->c3->base.Country_P;
		q->number_of_letter = p->c3->base.number_of_letter1;
		while (p->c2 != nullptr)
		{
			int i = 0;
			q->kolvo = 0;
			if (p->c2->base.kolvo_int != 0)
			{
				k = p->c3->base.raznica - p->c2->base.stoimost_int;
				if (k == 0)
				{
					p->c2->base.kolvo_int--;
					q->kolvo++;
					q->stoimost[i] = p->c2->base.stoimost_int;
					p->c3->base.raznica = p->c3->base.raznica - p->c2->base.stoimost_int;
					raz = raz - p->c2->base.stoimost_int;
					kolvo_marok--;
					break;
				}
			}
			p->c2 = p->c2->next;
		}
		push_back5(p, q);
		p->c3 = p->c3->next;
	}
	int ptr = 1;
	outputV5(p, r, ptr);
	obrabotka2(p, r, raz, kolvo, kolvo_marok);
	if (kolvo_marok != 0 && raz == 0)
	{
		r << "\n\nÂÑÅ ÊÎÍÂÅÐÒÛ ÎÁÍÎÂËÅÍÛ, ÌÀÐÊÈ ÂÑ¨ ÅÙ¨ ÎÑÒÀËÈÑÜ\n\n";
		r1 << "\n\nÂÑÅ ÊÎÍÂÅÐÒÛ ÎÁÍÎÂËÅÍÛ, ÌÀÐÊÈ ÂÑ¨ ÅÙ¨ ÎÑÒÀËÈÑÜ\n\n";
		int ptr = 1;
		outputV3(p, r, ptr, r1);
		ptr = 0;
	}
	if (kolvo_marok == 0 && raz == 0)
	{
		r << "\n\nÂÑÅ ÊÎÍÂÅÐÒÛ ÎÁÍÎÂËÅÍÛ, ÌÀÐÎÊ ÁÎËÜØÅ ÍÅ ÎÑÒÀËÎÑÜ\n\n";
		r1 << "\n\nÂÑÅ ÊÎÍÂÅÐÒÛ ÎÁÍÎÂËÅÍÛ, ÌÀÐÎÊ ÁÎËÜØÅ ÍÅ ÎÑÒÀËÎÑÜ\n\n";
	}
	if (kolvo_marok == 0 && raz != 0)
	{
		r << "\n\nÌÀÐÎÊ ÍÅ ÕÂÀÒÈËÎ\n\n";
		r << "\n\nÑÒÎÈÌÎÑÒÜ, ÊÎÒÎÐÓÞ ÂÑ¨ ÅÙ¨ ÍÓÆÍÎ ÏÎÊÐÛÒÜ\n\n";
		r1 << "\n\nÌÀÐÎÊ ÍÅ ÕÂÀÒÈËÎ\n\n";
		r1 << "\n\nÑÒÎÈÌÎÑÒÜ, ÊÎÒÎÐÓÞ ÂÑ¨ ÅÙ¨ ÍÓÆÍÎ ÏÎÊÐÛÒÜ\n\n";
		int ptr=1;
		outputV4(p, r, ptr);
		outputV4(p, r1, ptr);
	}
}

void obrabotka2(ALPHA* p, ofstream& r, int& raz, int& kolvo, int& kolvo_marok)
{
	int k = 0, k1 = 0, k2 = 0, k3 = 0, k5 = 0;
	int i = 0;
	int arr[100];
	while (raz != 0)
	{
		p->c3 = p->h3;
		p->c6 = p->h6;
		k1 = 0;
		while (p->c3 != nullptr)
		{
			p->c2 = p->h2;
			k2 = 0;
			k3 = 0;
			while (p->c2 != nullptr)
			{
				if (p->c2->base.kolvo_int != 0)
				{
					k3 = 1;
					k = p->c3->base.raznica - p->c2->base.stoimost_int;
					if (k == 0)
					{
						k2 = 1;
						p->c2->base.kolvo_int--;
						i = p->c6->base.kolvo;
						p->c6->base.stoimost[i] = p->c2->base.stoimost_int;
						p->c6->base.kolvo++;
						p->c3->base.raznica = p->c3->base.raznica - p->c2->base.stoimost_int;
						raz = raz - p->c2->base.stoimost_int;
						kolvo_marok--;
						break;
					}
				}
				p->c2 = p->c2->next;
			}
			if (kolvo_marok == 0 && raz != 0)
			{
				break;
			}
			if (k2 != 1)
			{
				k1++;
			}
			p->c3 = p->c3->next;
			p->c6 = p->c6->next;
		}
		obrabotka3(p, r, raz, kolvo, kolvo_marok);
		if (kolvo_marok == 0 && raz != 0)
		{
			break;
		}
	}
}

int raznica(ALPHA* p, int& kolvo) 
{
	kolvo = 0;
	p->c3 = p->h3;
	int raz = 0;
	while (p->c3 != nullptr) {
		raz = raz + p->c3->base.raznica;
		kolvo++;
		p->c3 = p->c3->next;
	}
	return raz;
}

int kolvo_marok1(ALPHA* p)
{
	p->c2 = p->h2;
	int kolvo_marok = 0;
	while (p->c2 != nullptr) {
		kolvo_marok = kolvo_marok + p->c2->base.kolvo_int;
		p->c2 = p->c2->next;
	}
	return kolvo_marok;
}

void obrabotka3(ALPHA* p, ofstream& r, int& raz, int& kolvo, int& kolvo_marok)
{
	bubble_marki(p, r);
	int k = 0, i = 0, k3 = 0, k2 = 0, k1 = 0, k5 = 0;
	while (raz != 0)
	{
		p->c3 = p->h3;
		p->c6 = p->h6;
		while (p->c3 != nullptr)
		{
			p->c2 = p->h2;
			k2 = 0;
			k3 = 0;
			while (p->c2 != nullptr)
			{
				if (p->c2->base.kolvo_int != 0 && p->c3->base.raznica != 0)
				{
					k3 = 1;
					k = p->c3->base.raznica - p->c2->base.stoimost_int;
					if (k < 0)
					{
						k2 = 1;
						raz = raz - p->c3->base.raznica;
						p->c2->base.kolvo_int--;
						p->c3->base.raznica = 0;
						i = p->c6->base.kolvo;
						p->c6->base.stoimost[i] = p->c2->base.stoimost_int;
						p->c6->base.kolvo++;
						kolvo_marok--;
						break;
					} 
				}
				p->c2 = p->c2->next;
			}
			if (kolvo_marok == 0 && raz != 0)
			{
				break;
			}
			if (k2 != 1)
			{
				k1++;
			}
			p->c3 = p->c3->next;
			p->c6 = p->c6->next;
		}
		obrabotka4(p,r,raz,kolvo, kolvo_marok);
		if (kolvo_marok == 0 && raz != 0)
		{
			break;
		}
	}
}

void obrabotka4(ALPHA* p, ofstream& r, int& raz, int& kolvo, int& kolvo_marok)
{
	int k = 0, i = 0;
	while (raz != 0)
	{
		p->c3 = p->h3;
		p->c6 = p->h6;
		while (p->c3 != nullptr)
		{
			p->c2 = p->h2;
			while (p->c2 != nullptr)
			{
				if (p->c2->base.kolvo_int != 0 && p->c3->base.raznica != 0)
				{
					k = p->c3->base.raznica - p->c2->base.stoimost_int;
					if (k > 0 || k==0)
					{
						raz = raz - p->c2->base.stoimost_int;
						p->c2->base.kolvo_int--;
						p->c3->base.raznica = p->c3->base.raznica - p->c2->base.stoimost_int;
						i = p->c6->base.kolvo;
						p->c6->base.stoimost[i] = p->c2->base.stoimost_int;
						p->c6->base.kolvo++;
						kolvo_marok--;
						break;
					}
				}
				p->c2 = p->c2->next;
			}
			p->c3 = p->c3->next;
			p->c6 = p->c6->next;
		}
		if (kolvo_marok == 0 && raz != 0)
		{
			break;
		}
	}
}