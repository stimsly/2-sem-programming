#include "ALPHA_LIST.h"

int minimum(ALPHA* p)
{
	p->c6 = p->h6;
	int maximum = 0;
	while (p->c6 != nullptr) {
		if (maximum < p->c6->base.kolvo)
			maximum = p->c6->base.kolvo;
		p->c6 = p->c6->next;
	}
	return maximum;
}