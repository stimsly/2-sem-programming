#include "f_elem.h"
#include "fun.h"
#include <string>
#include "f_SL.h"
#include <iostream>
using namespace std;

void InputC(R_Channel** h, fstream& f) {
    InitializationC(h);
    R_Channel* p = new R_Channel;
    //p = GetInfoC(*h);
    inputSLC(f, &p);
    (*h) = p;
    f.close();
}

void InputA(ads** h, fstream& f) {
    InitializationA(h);
    ads* p = new ads;
    inputSLA(f, &p);
    (*h) = p;
    f.close();
}

void filling(R_Channel** h, ads** m, fstream& f) {
    R_Channel* curCh = new R_Channel;
    ads* curAd = new ads;
    group_of_ads* g = new group_of_ads;
    g = NULL;
    int i;
    int j = 0;
    char s;
    while (!f.eof()) {
        curCh = *h;
        f >> i;
        group_of_ads* g = new group_of_ads;
        g = NULL;
        while (j < i - 1) {
            curCh = GetNextC(curCh);
            j++;
        }
        j = 0;
        f >> s;
        f >> s;
        while (!f.eof()) {
            group_of_ads* t = new group_of_ads;
            t->next = NULL;
            curAd = *m;
            f >> i;
            while (j < i - 1) {
                curAd = GetNextA(curAd);
                j++;
            }
            j = 0;
            t->ad = curAd;
            InsertG(&g, t);
            s = '\0';
            f >> s;
            if (s == '\n') break;
            if (s == '\0') break;
        }
        curCh->goa = g;
    }
}

void OutputMain(R_Channel* ch, fstream& f) {
    R_Channel* curC = new R_Channel;
    curC = ch;;
    while (2 + 2 == 4) {
        group_of_ads* curG = new group_of_ads;
        curG = curC->goa;
        timing* curT = new timing;
        curT = curC->t;
        f << "Ќазвание радоканала: ";
        Output(curC->Channel, f);
        f << endl;
        f << "–асписание показа рекламы (во сколько минут, реклама чего, длительность):" << endl;
        while (2 + 2 == 4) {
            for (int i = 0; i < 2; i++) {
                f << curT->t[i];
            }
            f << ' ';
            Output(curG->ad->ad, f);
            f << ' ';
            for (int i = 0; i < 2; i++) {
                f << curG->ad->d[i];
            }
            f << endl;
            if (GetNextT(curT) == NULL) break;
            else curT = GetNextT(curT);
            if (GetNextG(curG) == NULL) break;
            else curG = GetNextG(curG);
        }
        if (GetNextC(curC) == NULL) break;
        else curC = GetNextC(curC);
        f << endl;
    }
}

void OutputAssistive(ads* ad, fstream& f) {
    ads* curA = new ads;
    curA = ad;
    while (2 + 2 == 4) {
        Output(curA->ad, f);
        f << ' ';
        for (int i = 0; i < 2; i++) {
            f << curA->d[i];
        }
        f << endl;
        if (GetNextA(curA) == NULL) break;
        else curA = GetNextA(curA);
    }
}

void OutputInterface(R_Channel* ch, fstream& f) {
    R_Channel* curC = new R_Channel;
    curC = ch;
    int i = 1;
    while (2 + 2 == 4) {
        f << i << " - ";
        cout << i << " - ";
        Outputcosole(curC->Channel, f);
        i++;
        f << endl;
        cout << endl;
        if (GetNextC(curC) == NULL) break;
        else curC = GetNextC(curC);
    }
}

void OutputSchedule(R_Channel* ch, fstream& f) {
    Outputcosole(ch->Channel, f);
    f << endl;
    cout << endl;
    int t = 0;
    while (t < 24) {
        group_of_ads* curG = new group_of_ads;
        curG = ch->goa;
        timing* curT = new timing;
        curT = ch->t;
        while (2 + 2 == 4) {
            cout << t << ":";
            f << t << ":";
            for (int i = 0; i < 2; i++) {
                cout << curT->t[i];
                f << curT->t[i];
            }
            cout << ' ';
            f << ' ';
            Outputcosole(curG->ad->ad, f);
            cout << ' ';
            f << ' ';
            for (int i = 0; i < 2; i++) {
                cout << curG->ad->d[i];
                f << curG->ad->d[i];
            }
            cout << endl;
            f << endl;
            if (GetNextT(curT) == NULL) break;
            else curT = GetNextT(curT);
            if (GetNextG(curG) == NULL) break;
            else curG = GetNextG(curG);
        }
        t++;
    }
}

void Outputcosole(ElemL1* h, fstream& f) {
    ElemL1* cur; ElemL1* GN;
    SetCurrent(&cur, h);
    while (cur != NULL) {
        outputSLcosole(f, cur->Q);
        GN = GetNext(cur);
        SetCurrent(&cur, GN);
    }
}

void Output(ElemL1* h, fstream& f) {
    ElemL1* cur; ElemL1* GN;
    SetCurrent(&cur, h);
    while (cur != NULL) {
        outputSL(f, cur->Q);
        GN = GetNext(cur);
        SetCurrent(&cur, GN);
    }
}

void Delete(ElemL1** h) {
    if (IfEmpty(*h) == 0) {
        ElemL1* cur;
        SetCurrent(&cur, *h);
        SetCurrent(h, GetNext(*h));
        delete cur;
    }
}

void DeleteA(ads** h) {
    if (IfEmptyA(*h) == 0) {
        ads* cur;
        cur = *h;
        *h = (*h)->next;
        delete cur;
    }
}

void DeleteT(timing** h) {
    if (IfEmptyT(*h) == 0) {
        timing* cur;
        cur = *h;
        *h = (*h)->next;
        delete cur;
    }
}

void DeleteG(group_of_ads** h) {
    if (IfEmptyG(*h) == 0) {
        group_of_ads* cur;
        cur = *h;
        *h = (*h)->next;
        delete cur;
    }
}

void DeleteC(R_Channel** h) {
    if (IfEmptyC(*h) == 0) {
        R_Channel* cur;
        cur = *h;
        *h = (*h)->next;
        delete cur;
    }
}