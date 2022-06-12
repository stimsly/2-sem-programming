#include "f_SL.h"
#include "fun.h"
#include "ElemL1.h"
#include <iostream>

void inputSLC(fstream& f, R_Channel** p) {
    R_Channel* ch = new R_Channel;
    ch = NULL;
    char s = ' ';
    int i = 0;
    bool flag = true;
    while (!f.eof()) {
        R_Channel* a = new R_Channel;
        a->next = NULL;
        ElemL1* l = new ElemL1;
        ElemL1* ll = new ElemL1;
        ll = NULL;
        flag = true;
        while (flag) {
            l = GetInfo(l->Q);
            flag = inputSL(f, l->Q);
            Insert(&ll, l, l->Q);
        }
        a->Channel = ll;
        f >> s;
        timing* t = new timing;
        t = NULL;
        while (!f.eof()) {
            timing* b = new timing;
            b->next = NULL;
            while (i < 2) {
                b->t[i] = s;
                f >> s;
                i++;
            }
            i = 0;
            InsertT(&t, b);
            if (s == '\n') break;
            f >> s;
        }
        a->t = t;
        InsertC(&ch, a);
    }
    (*p) = ch;
}

void inputSLA(fstream& f, ads** p) {
    ads* ad = new ads;
    ad = NULL;
    char s = ' ';
    int i = 0;
    bool flag = true;
    while (!f.eof()) {
        ads* a = new ads;
        a->next = NULL;
        ElemL1* l = new ElemL1;
        ElemL1* ll = new ElemL1;
        ll = NULL;
        flag = true;
        while (flag) {
            l = GetInfo(l->Q);
            flag = inputSL(f, l->Q);
            Insert(&ll, l, l->Q);
        }
        a->ad = ll;
        f >> s;
        while (i < 2) {
            a->d[i] = s;
            i++;
            f >> s;
        }
        i = 0;
        InsertA(&ad, a);
    }
    (*p) = ad;
}

bool inputSL(fstream& f, strlenght& SL)
{
    int i = 0;
    char s;
    bool flag = true;
    while (!f.eof()) {
        s = '\0';
        f >> s;
        if (s == '\0') break;
        if (s != ':') {
            SL.A[i] = s;
            i++;
        }
        if (i >= N) break;
        if (s == ':') {
            f >> s;
            flag = false;
            break;
        }
    }
    SL.L = i;
    return flag;
}



void outputSL(fstream& of, strlenght SL) {
    int i = 0;
    while (i < SL.L) {
        of << SL.A[i];
        i++;
    }
}

void outputSLcosole(fstream& of, strlenght SL) {
    int i = 0;
    while (i < SL.L) {
        of << SL.A[i];
        cout << SL.A[i];
        i++;
    }
}