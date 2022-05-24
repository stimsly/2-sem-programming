#include "list.h"

//void ChainList(form& fm, list* l) {
//
//    // �������� ����������-���������� ������������
//
//    for (int i = 0; i < 4; i++) {
//        if (fm.sizes[i] <= 0) {         // PTR == NULL
//            fm.sizes[i] = 1;
//            fm.multi[i]->to_base = l;
//            fm.multi[i]->next = NULL;
//        } else if (fm.sizes[i] > 0) {   // PTR != NULL
//            fm.sizes[i]++;
//            multi_list *ptr = fm.multi[i];
//
//            // �������� ����������
//
//            long long value;
//            long long comparable;
//
//            if (i == 0) {
//                value = l->inf.level;
//                comparable = ptr->to_base->inf.level;
//            } else if (i == 1) {
//                value = l->inf.rooms;
//                comparable = ptr->to_base->inf.rooms;
//            } else if (i == 2) {
//                value = l->inf.area;
//                comparable = ptr->to_base->inf.area;
//            } else {
//                value = l->inf.price;
//                comparable = ptr->to_base->inf.price;
//            }
//
//            while (ptr != NULL && value > comparable) {
//                ptr = ptr->next;    // ������� ����������!
//
//                if (i == 0) { comparable = ptr->to_base->inf.level; }
//                else if (i == 1) { comparable = ptr->to_base->inf.rooms; }
//                else if (i == 2) { comparable = ptr->to_base->inf.area; }
//                else { comparable = ptr->to_base->inf.price; }
//            }
//
//            if (ptr == fm.multi[i]) { // ������ �������� ����� ������ �������
//                multi_list *backup = ptr;
//                fm.multi[i]->to_base = l;
//                fm.multi[i]->next = backup;
//            } else {
//                multi_list *backup = ptr;
//                ptr->to_base = l;
//                ptr->next = backup;
//            }
//        }
//    }
//
//}

void ReadList(list* h, fstream& f, log_normal& _log) {
    int n = 0;
    f >> n;         // ������� ���-�� ������.

    ushort level, rooms, area;
    long long price;
    char c = '\0';

    list* cur = h;

    for (int i = 0; i < n && !f.eof(); i++) {
        list_wrapper address;
        list_wrapper district;  // ���������� ��������� ������������� ����� ��������

        if (i != 0) {
            cur->next = new list;
            cur = cur->next;
            cur->next = NULL;
        }

        f >> std::skipws >> level >> rooms >> area;
        f >> price;
        {
            _log.PutMessageLog(L"��������� ����: ", level);
            _log.PutMessageLog(L"��������� �������: ", rooms);
            _log.PutMessageLog(L"��������� �������: ", area);
            _log.PutMessageLog(L"��������� ����: ", price);
        }

        f >> std::noskipws >> c;
        do {
            f >> c;
            if (c != '\n' && !f.eof() && c != '\0')
                AddSymb(address, c);
        } while (!f.eof() && c != '\n' && c != '\0');         // ��������� �����

        _log.PutMessageLog(L"");
        _log.PutMessageLog(L"��������� �����: ");

        if (address.head == NULL) {
            _log.PutMessageOutConsoleLog(L"������ ��� ���������� ������ �� �����. ���������� ���������... ");
            exit(4);
        }

        _log.PutMessageLog(address);

        do {
            f >> c;
            if (c != '\n' && !f.eof() && c != '\0')
                AddSymb(district, c);
        } while (!f.eof() && c != '\n' && c != '\0');         // ��������� �����

        _log.PutMessageLog(L"");
        _log.PutMessageLog(L"��������� �����: ");
        if (district.head == NULL) {
            _log.PutMessageOutConsoleLog(L"������ ��� ���������� ������ �� �����. ���������� ���������... ");
            exit(5);
        }
        _log.PutMessageLog(district);
        _log.PutMessageLog(L""); // ������� \n


        // ����������, �������� ������.

        if (!SetInfo(cur->inf, level, rooms, area, price, address, district, _log)) {
            _log.PutMessageLog(L"���������� ��������� ���������� ��-�� ��� �������: ", i);
            _log.PutMessageLog(L"������ �� ������ � ����.");
        }
        else {
            _log.PutMessageLog(L"������� ��������� ���������� ��-�� ��� �������: ", i);
        }

        // ������� �������� ������ � ����� ������!

        FreeString(address);
        FreeString(district);
    }

    _log.PutMessageLog(L"���������� �� in.txt ���������");
}


void LogList(list* h, log_normal& _log) {
    list* ptr = h;
    _log.PutMessageOutConsoleLog(L"");
    _log.PutMessageOutConsoleLog(L"����� ���� ������:");

    int i = 0;
    while (ptr != NULL) {
        _log.PutMessageOutConsoleLog(L"");
        _log.PutMessageOutConsoleLog(L"����� ������������ ", ++i);

        OutputInfo(ptr->inf, _log);

        ptr = ptr->next;
    }

    _log.PutMessageOutConsoleLog(L"\n����� ���� ������ ��������.\n");
}

void OutputEquals(list* l, list* r, log_normal& _log) {
    list* ptr_l = l;
    list* ptr_r;
    while (ptr_l != NULL) {
        ptr_r = r;
        while (ptr_r != NULL) {
            if (CmpInfo(ptr_l->inf, ptr_r->inf)) {
                _log.PutMessageOutConsoleLog(L"��������� ����������� ��:");
                LogList(ptr_l, _log);
                _log.PutMessageOutConsoleLog(L"");
                break;
            }
            ptr_r = ptr_r->next;
        }

        ptr_l = ptr_l->next;
    }
}

void SortListBy(multi_list* sorted, list* origin, long value1, long value2, int param) {
    // �� ��������� ��������� ������ ������
    // sorted ������ ���� ������

    multi_list* ptr_sort = sorted;
    list* ptr = origin;
    bool first = true;

    while (ptr != NULL) {
        if (ptr->inf[param] >= value1 && ptr->inf[param] <= value2) {
            if (first) first = false;
            else {
                ptr_sort->next = new multi_list;
                ptr_sort = ptr_sort->next;
            }
            ptr_sort->to_base = ptr;
        }
        ptr = ptr->next;
    }

}

void SortListRepeat(multi_list** sorted, int value1, int value2, int param) {
    multi_list* ptr = *sorted;
    multi_list* prev = *sorted;
    bool first = true;
    while (ptr != NULL && ptr->to_base != NULL) {
        if (ptr->to_base->inf[param] <= value1 && ptr->to_base->inf[param] >= value2) {
            // �� ������ ��������� �� ������ ���� �������

            multi_list* to_delete = ptr;

            prev = *sorted;
            while (!first && prev->next != ptr && prev != NULL)
                prev = prev->next;

            ptr = ptr->next;
            delete to_delete;
            if (first) {
                *sorted = ptr;
            }
            else {
                prev->next = ptr;
            }
        }
        else {
            if (first) first = false;
            if (ptr != NULL) {
                prev = ptr;
                ptr = ptr->next;
            }
        }
    }
}

void SortListByDistrict(multi_list** sorted, list_wrapper& value) {
    multi_list* ptr = *sorted;
    multi_list* prev = *sorted;
    bool first = true;
    while (ptr != NULL && ptr->to_base != NULL) {
        if (!CmpString(ptr->to_base->inf.district, value)) {
            // �� ������ ��������� �� ������ ���� �������

            multi_list* to_delete = ptr;

            prev = *sorted;
            while (!first && prev->next != ptr && prev != NULL)
                prev = prev->next;

            ptr = ptr->next;
            delete to_delete;
            if (first) {
                *sorted = ptr;
            }
            else {
                prev->next = ptr;
            }
        }
        else {
            if (first) first = false;
            if (ptr != NULL) {
                prev = ptr;
                ptr = ptr->next;
            }
        }
    }
}

void ListSortedDistricts(multi_list* sorted, log_normal& _log) {
    multi_list* ptr = sorted;
    int i = 1;
    while (ptr != NULL && ptr->to_base != NULL) {
        wcout << endl << i << L": ";
        _log.PutMessageOutConsoleLog(ptr->to_base->inf.district);
        wcout << endl;
        ptr = ptr->next;
        i++;
    }
}

list_wrapper GetDistrictByIndex(multi_list* sorted, int index) {
    multi_list* ptr = sorted;
    int i = 1;
    while (ptr->next != NULL && i < index) {
        ptr = ptr->next;
        i++;
    }

    return ptr->to_base->inf.district;
}

void OutputSorted(multi_list* sorted, log_normal& _log) {
    multi_list* ptr = sorted;
    _log.PutMessageOutConsoleLog(L"����� �������� ������������:");
    int index = 1;
    while (ptr != NULL && ptr->to_base != NULL) {
        _log.PutMessageOutConsoleLog(L"", index++);

        OutputInfo(ptr->to_base->inf, _log);
        ptr = ptr->next;
    }
}

void FreeSorted(multi_list** sorted) {
    multi_list* ptr = NULL;
    if (sorted != NULL)
        ptr = *sorted;
    while (ptr != NULL) {
        multi_list* to_delete = ptr;
        ptr = ptr->next;
        delete to_delete;
    }
}

bool SetInfo(info& inf, const ushort& _level, const ushort& _rooms,
    const ushort& _area, const long long& _price, list_wrapper& _addr, list_wrapper& _dist, log_normal& _log);


bool CmpInfo(info& inf1, info& inf2);
bool InputInfo(info& inf, std::fstream& f);

void OutputInfo(info& inf, log_normal& _log);