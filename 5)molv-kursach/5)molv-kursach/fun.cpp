#include "fun.h"
#include "ElemL1.h"
#include <cstddef>

void Initialization(ElemL1* a)
{
    a = NULL;
}

void InitializationC(R_Channel** a)
{
    (*a)->Channel = NULL;
    (*a)->goa = NULL;
    (*a)->next = NULL;
}

void InitializationA(ads** a)
{
    (*a)->ad = NULL;
    (*a)->next = NULL;
}

void SetNext(ElemL1** a, ElemL1* p) {
    (*a)->next = p;
}

void SetInf(ElemL1** a, strlenght SL) {
    int i = 0;
    while (i < SL.L) {
        (*a)->Q.A[i] = SL.A[i];
        i++;
    }
    (*a)->Q.L = SL.L;
}

ElemL1* GetNext(ElemL1* a) {
    return a->next;
}

ElemL1* GetInfo(strlenght Q) {
    ElemL1* p = new ElemL1;
    SetNext(&p, NULL);
    SetInf(&p, Q);
    return p;
}

int IfEmpty(ElemL1* h) {
    if (h == NULL) return 1;
    else return 0;
}

void InBeg(ElemL1** h, ElemL1* p, strlenght SL) {
    p = GetInfo(SL);
    SetNext(&p, *h);
    *h = p;
}

ElemL1* GetLast(ElemL1* h) {
    ElemL1* cur;
    cur = h;
    if (!IfEmpty(h))
        while (GetNext(cur) != NULL)
            cur = GetNext(cur);
    return cur;
}

void Insert(ElemL1** h, ElemL1* p, strlenght SL) {
    if (IfEmpty(*h)) InBeg(h, p, SL);
    else {
        p = GetInfo(SL);
        ElemL1* c;
        c = GetLast(*h);
        SetNext(&c, p);
    }
}

void SetCurrent(ElemL1** c, ElemL1* p) {
    *c = p;
}

void InMid(ElemL1** prev, ElemL1* p, strlenght SL) {
    p = GetInfo(SL);
    SetNext(&p, GetNext(*prev));
    SetNext(prev, p);
}


int Compare(ElemL1* l, ElemL1* ll) {
    int i = 0;
    while (l->next != NULL || ll->next != NULL) {
        if (l->Q.L == ll->Q.L) {
            for (i = 0; i < l->Q.L; i++) {
                if (l->Q.A[i] != ll->Q.A[i]) return 0;
            }
        }
        GetNext(l);
        GetNext(ll);
    }
    return 1;
}

void SetNextC(R_Channel* a, R_Channel* p) {
    a->next = p;
}

void SetNextT(timing** a, timing* p) {
    (*a)->next = p;
}

int IfEmptyT(timing* h) {
    if (h == NULL) return 1;
    else return 0;
}

timing* GetNextT(timing* a) {
    return a->next;
}

timing* GetLastT(timing* h) {
    timing* cur;
    cur = h;
    if (!IfEmptyT(h))
        while (GetNextT(cur) != NULL)
            cur = GetNextT(cur);
    return cur;
}

void InsertT(timing** h, timing* p) {
    if (IfEmptyT(*h)) *h = p;
    else {
        timing* c;
        c = GetLastT(*h);
        SetNextT(&c, p);
    }
}

void SetNextA(ads** a, ads* p) {
    (*a)->next = p;
}

int IfEmptyA(ads* h) {
    if (h == NULL) return 1;
    else return 0;
}

ads* GetNextA(ads* a) {
    return a->next;
}

ads* GetLastA(ads* h) {
    ads* cur;
    cur = h;
    if (!IfEmptyA(h))
        while (GetNextA(cur) != NULL)
            cur = GetNextA(cur);
    return cur;
}

void InsertA(ads** h, ads* p) {
    if (IfEmptyA(*h)) *h = p;
    else {
        ads* c;
        c = GetLastA(*h);
        SetNextA(&c, p);
    }
}

void SetNextG(group_of_ads** a, group_of_ads* p) {
    (*a)->next = p;
}

int IfEmptyG(group_of_ads* h) {
    if (h == NULL) return 1;
    else return 0;
}

group_of_ads* GetNextG(group_of_ads* a) {
    return a->next;
}

group_of_ads* GetLastG(group_of_ads* h) {
    group_of_ads* cur;
    cur = h;
    if (!IfEmptyG(h))
        while (GetNextG(cur) != NULL)
            cur = GetNextG(cur);
    return cur;
}

void InsertG(group_of_ads** h, group_of_ads* p) {
    if (IfEmptyG(*h)) *h = p;
    else {
        group_of_ads* c;
        c = GetLastG(*h);
        SetNextG(&c, p);
    }
}

void SetNextC(R_Channel** a, R_Channel* p) {
    (*a)->next = p;
}

int IfEmptyC(R_Channel* h) {
    if (h == NULL) return 1;
    else return 0;
}

R_Channel* GetNextC(R_Channel* a) {
    return a->next;
}

R_Channel* GetLastC(R_Channel* h) {
    R_Channel* cur;
    cur = h;
    if (!IfEmptyC(h))
        while (GetNextC(cur) != NULL)
            cur = GetNextC(cur);
    return cur;
}

void InsertC(R_Channel** h, R_Channel* p) {
    if (IfEmptyC(*h)) *h = p;
    else {
        R_Channel* c;
        c = GetLastC(*h);
        SetNextC(&c, p);
    }
}

R_Channel* GetInfoC(R_Channel* h) {
    R_Channel* p = new R_Channel;
    SetNextC(p, NULL);
    p->Channel = h->Channel;
    p->goa = h->goa;
    p->t = h->t;
    return p;
}