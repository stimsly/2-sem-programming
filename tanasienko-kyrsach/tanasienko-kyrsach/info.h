#pragma once
#pragma once

#include "log.h"


typedef unsigned short ushort;

struct info {
    ushort level = 0u;  // этаж (1-100)
    ushort rooms = 0u;  // число комнат (1 - 5'000)
    ushort area = 0u;   // площадь (10 - 50'000)
    long price = 0;    // цена (5'000'000 - 100'000'000)

    list_wrapper address;      // адресс (а - z) (<= 50 символов)
    list_wrapper district;    // район на английском! (a - z) (<= 50 символов)

    long long operator[] (int index) {
        if (index == 1) return level;
        else if (index == 2) return rooms;
        else if (index == 3) return area;
        else if (index == 4) return price;
        else return -1;
    }

    list_wrapper& operator[] (bool index) {
        if (!index) return address;         // index = false
        else return district;               // index = true
    }

    ~info() {
        FreeString(address);
        FreeString(district);
    }
};

bool SetInfo(info& inf, const ushort& _level, const ushort& _rooms,
    const ushort& _area, const long long& _price, list_wrapper& _addr, list_wrapper& _dist, log_normal& _log);


bool CmpInfo(info& inf1, info& inf2);
bool InputInfo(info& inf, std::fstream& f);

void OutputInfo(info& inf, log_normal& _log);