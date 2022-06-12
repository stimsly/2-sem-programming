#pragma once
#include "ElemL1.h"
#include "form.h"
void Initialization(ElemL1* a);
void InitializationC(R_Channel** a);
void InitializationA(ads** a);
void SetNext(ElemL1** a, ElemL1* p);
void SetNextC(R_Channel* a, R_Channel* p);
void SetInf(ElemL1** a, strlenght SL);
ElemL1* GetNext(ElemL1* a);
ElemL1* GetInfo(strlenght A);
int IfEmpty(ElemL1* h);
void InBeg(ElemL1** h, ElemL1* p, strlenght SL);
ElemL1* GetLast(ElemL1* h);
void Insert(ElemL1** h, ElemL1* p, strlenght SL);
void SetCurrent(ElemL1** c, ElemL1* p);
void InMid(ElemL1** prev, ElemL1* p, strlenght SL);
int Compare(ElemL1* l, ElemL1* ll);
void SetNextT(timing** a, timing* p);
int IfEmptyT(timing* h);
timing* GetNextT(timing* a);
timing* GetLastT(timing* h);
void InsertT(timing** h, timing* p);
void SetNextA(ads** a, ads* p);
int IfEmptyA(ads* h);
ads* GetNextA(ads* a);
ads* GetLastA(ads* h);
void InsertA(ads** h, ads* p);
void SetNextG(group_of_ads** a, group_of_ads* p);
int IfEmptyG(group_of_ads* h);
group_of_ads* GetNextG(group_of_ads* a);
group_of_ads* GetLastG(group_of_ads* h);
void InsertG(group_of_ads** h, group_of_ads* p);
void SetNextC(R_Channel** a, R_Channel* p);
int IfEmptyC(R_Channel* h);
R_Channel* GetNextC(R_Channel* a);
R_Channel* GetLastC(R_Channel* h);
void InsertC(R_Channel** h, R_Channel* p);
R_Channel* GetInfoC(R_Channel* h);