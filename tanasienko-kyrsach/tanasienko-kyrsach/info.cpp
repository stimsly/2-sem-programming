#include "info.h"

bool SetInfo(info& inf, const ushort& _level, const ushort& _rooms, const ushort& _area, const long long& _price, list_wrapper& _addr, list_wrapper& _dist, log_normal& _log) {

    // Проверки
    if (_level < 1 || _level > 100) {
        _log.PutMessageLog(L"Этаж может быть только от 1 до 100, неверный ввод: ", _level);
        return false;
    }

    if (_rooms < 1 || _rooms > 5000) {
        _log.PutMessageLog(L"Комнат может быть только от 1 до 5'000, неверный ввод: ", _rooms);
        return false;
    }

    if (_area < 10 || _area > 50000) {
        _log.PutMessageLog(L"Площадь может быть только от 10 до 50'000, неверный ввод: ", _area);
        return false;
    }

    if (_price < 500000 || _price > 100000000) {
        _log.PutMessageLog(L"Цена может быть только от 500'000 до 100'000'000, неверный ввод: ", _price);
        return false;
    }

    if (_addr.size > 50 || _addr.size < 1) {
        _log.PutMessageLog(L"Адрес может содержать только a-z и быть длиной < 51, неверный размер: ", _addr.size);
        _log.PutMessageLog(L"Считанный адрес: ");
        _log.PutMessageLog(_addr);
        return false;
    }

    if (_dist.size > 50 || _dist.size < 1) {
        _log.PutMessageLog(L"Район может содержать только a-z и быть длиной < 51, неверный размер: ", _dist.size);
        _log.PutMessageLog(L"Считанный район: ");
        _log.PutMessageLog(_dist);
        return false;
    }

    inf.level = _level;
    inf.rooms = _rooms;
    inf.area = _area;
    inf.price = _price;

    CopyString(inf.address, _addr);
    CopyString(inf.district, _dist);

    return true;    // успешно
}

void OutputInfo(info& inf, log_normal& _log) {

    _log.PutMessageOutConsoleLog(L"Этаж:", inf.level);
    _log.PutMessageOutConsoleLog(L"Комнат:", inf.rooms);
    _log.PutMessageOutConsoleLog(L"Площадь:", inf.area);
    _log.PutMessageOutConsoleLog(L"Цена:", inf.price);


    _log.PutMessageOutConsoleLog(L"");
    _log.PutMessageOutConsoleLog(L"Адрес:");
    _log.PutMessageOutConsole(inf.address);

    _log.PutMessageOutConsoleLog(L"");
    _log.PutMessageOutConsoleLog(L"Район:");
    _log.PutMessageOutConsole(inf.district);
}


bool CmpInfo(info& inf1, info& inf2) {
    for (int i = 1; i < 5; i++) {
        if (inf1[i] != inf2[i]) return false;
    }

    if (!CmpString(inf1.address, inf2.address)) return false;

    return CmpString(inf1.district, inf2.district);
}

/*
void info::SetInfo(const ushort& _level, const ushort& _rooms, const ushort& _area, const long long& _price, sl& _addr, sl& _dist) {
    level = _level;
    rooms = _rooms;
    area = _area;
    price = _price;

    CopySL(address, _addr);  // Здесь инициализируется sl
    CopySL(district, _dist);
}

bool CmpInfo(info& inf1, info& inf2, int param) {
    // Постепенно проверяем по каждому пункту
    if (inf1.level == inf2.level && param == 0) return true;
    else if (inf1.rooms == inf2.rooms && param == 1) return true;
    else if (inf1.area == inf2.area && param == 2) return true;
    else if (inf1.price == inf2.price && param == 3) return true;
    else if (inf1.address.str[0] == inf2.address.str[0] && param == 4) return true;
    else return inf1.district.str[0] == inf2.district.str[0] && param == 5;
}

bool InputInfo(info& inf, fstream& f) {
    f >> inf.level;
    f >> inf.rooms;
    f >> inf.area;
    f >> inf.price;

    sl address; InitSL(address, 256);
    InputSL(address, f);
    if (address.l == 0) { FreeSL(address); return false;}
    CopySL(inf.address, address);

    sl district; InitSL(district, 256);
    InputSL(district, f);
    if (district.l == 0) { FreeSL(district); return false;}
    CopySL(inf.district, district);

    FreeSL(address);
    FreeSL(district);
    return true;
}

void OutputInfo(info& inf, fstream& f) {
    f << inf.level << " этаж." << endl;
    f << inf.rooms << " комнат." << endl;
    f << inf.area << " кв. м." << endl;
    f << inf.price << " руб." << endl;
    f << "Район: "; OutputSL(inf.district, f);
    f << "Адрес: "; OutputSL(inf.address, f);
}
 */