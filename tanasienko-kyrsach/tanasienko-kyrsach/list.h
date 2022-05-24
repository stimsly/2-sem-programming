#pragma once

#include "info.h"

#define INFO_DATA_COUNT 4   // обрабатываем только численные значения

struct list {
    info inf;
    list* next = NULL; // next base
};

struct multi_list {
    list* to_base = NULL;
    multi_list* next = NULL;
};

void InitBaseData();
void LogList(list* h, log_normal& _log);
//void ChainList(form& fm, list* l);
void ReadList(list* h, fstream& f, log_normal& _log);
void OutputEquals(list* l, list* r, log_normal& _log);
void OutputList(list* h, std::fstream& f);
void DeleteList(list* h);


void SortListBy(multi_list* sorted, list* origin, long value1, long value2, int param);
void SortListRepeat(multi_list** sorted, int value1, int value2, int param);
void SortListByDistrict(multi_list** sorted, list_wrapper& value);
void ListSortedDistricts(multi_list* sorted, log_normal& _log);
list_wrapper GetDistrictByIndex(multi_list* sorted, int index);
void OutputSorted(multi_list* sorted, log_normal& _log);
void FreeSorted(multi_list** sorted);