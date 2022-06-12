#pragma once
#ifndef ElemL
#define ElemL
#include "SL.h"

const int N = 5;

struct strlenght {
    char A[N];
    int L;
};

struct ElemL1 {
    strlenght Q;
    ElemL1* next;
};

struct ads {
    ElemL1* ad;
    char d[2];
    ads* next;
};

struct timing {
    char t[2];
    timing* next;
};

struct group_of_ads {
    ads* ad;
    group_of_ads* next;
};

struct R_Channel {
    ElemL1* Channel;
    group_of_ads* goa;
    timing* t;
    R_Channel* next;
};

#endif 