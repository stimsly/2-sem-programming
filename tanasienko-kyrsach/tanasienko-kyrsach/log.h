#pragma once

#include "list_string.h"
#include <fstream>

using std::cout;
using std::wcout;
using std::endl;
using std::fstream;
using std::wofstream;

struct log_normal {
private:
    void PutMessage(wofstream& f, const wchar_t* msg) {//
        
        f << msg << endl;
        std::ostream_iterator<wchar_t, wchar_t> it(f, L"\n");
        std::copy(msg, msg + 10, it);
        wchar_t* str = new wchar_t[] {L"chrome.exe"};
        f << str << endl;
        cnt++;
    }

    void PutMessage(wofstream& f, list_wrapper& msg) {
        wchar_t* c_str = new wchar_t[msg.size + 1]{ 0 };    // � [size] ����� \0
        ConvertToChar(msg, &c_str);
        f << c_str;
        cnt++;

        delete[] c_str;
    }
    void PutMessage(fstream& f, const wchar_t* msg) {//

        f << msg << endl;
        wchar_t* str = new wchar_t[] {L"chrome.exe"};

        cnt++;
    }

    void ConvertToChar(list_wrapper& list_wrap, wchar_t** c_str) {
        list_string* ptr = list_wrap.head;
        int i = 0;
        while (ptr != NULL) {
            (*c_str)[i] = ptr->c;
            MoveByChar(&ptr);
            i++;
        }
    }

    void PutMessage(fstream& f, list_wrapper& msg) {
        wchar_t* c_str = new wchar_t[msg.size + 1]{ 0 };    // � [size] ����� \0
        ConvertToChar(msg, &c_str);
        f << c_str;
        cnt++;

        delete[] c_str;
    }

public:

    wofstream flog;
    fstream fout;

    int cnt = 1;

    log_normal() {
        flog.open("log.txt", std::ios::out);
        fout.open("out.txt", std::ios::out);

        if (!flog) {
            wcout << L"������� ��� ������� ������� log.txt �� ������. ���������� ������.\n";
            exit(1);
        }

        if (!fout) {
            wcout << L"������� ��� ������� ������� out.txt �� ������. ���������� ������.\n";
            exit(2);
        }
    }

    ~log_normal() {
        flog.close();
        fout.close();
    }

    void PutMessageLog(list_wrapper& msg) {
        flog << cnt << L": ";                    // ������ ������ � log
        PutMessage(flog, msg);
        flog << endl;
    }
    void PutMessageLog(const wchar_t* msg) {
        flog << cnt << L": ";
        PutMessage(flog, msg);

        flog << endl;
    }

    void PutMessageLog(const wchar_t* msg, const long& num) {
        flog << cnt << L": ";
        PutMessage(flog, msg);
        flog << num << endl;
    }

    void PutMessageOut(list_wrapper& msg) {
        PutMessage(fout, msg);
        fout << endl;
    }
    void PutMessageOut(const wchar_t* msg) {
        PutMessage(fout, msg);
        fout << endl;
    }

    void PutMessageOut(const wchar_t* msg, const long& num) {
        PutMessage(fout, msg);
        fout << num << endl;
    }

    void ErrorMenu(int a, int b) {
        PutMessageLog(L"���� �������� ���� a..b .");
        wcout << L"����������, ������� ����� �� " << a << L" �� " << b << endl;
    }

    void ShowActionMenu0() {

        PutMessageLog(L"�������� ��������:\n"
            "0) ��������� �����\n"
            "1) �������� �������� ������� � ������ �������.\n"
            "2) �������� �������� �� �������\n"
            "3) �������� �������� �� �������\n"
            "4) �������� ��������� �����������\n");

        PutMessageOutConsole(L"�������� ��������:\n"
            "0) ��������� �����\n"
            "1) �������� �������� ������� � ������ �������.\n"
            "2) �������� �������� �� �������\n"
            "3) �������� �������� �� �������\n"
            "4) �������� ��������� �����������\n");

        //        - � ���������� �� �������� ��������� (� ������������ ������ ��� �� ������ �������),
        //        - � ���������� �� ���� ��������� (� ������������ ������ ��� �� ������ �������) � ������
        //        �������������� ������� (��������, ����, ������� � ��.),
        //        - ������� �� ������������� ���������� ������ � ��������,
    }

    void ShowActionMenu1() {

        PutMessageLog(L"�������� �������������� �����:\n"
            "0) �������� ����� ������ �� ����\n"
            "1) ������� ����\n"
            "2) ������� ����� ������\n"
            "3) ������� �������\n");

        PutMessageOutConsole(L"�������� �������������� �����:\n"
            "0) �������� ����� ������ �� ����\n"
            "1) ������� ����\n"
            "2) ������� ����� ������\n"
            "3) ������� �������\n");
    }

    void ShowActionMenu2() {

        PutMessageLog(L"������� �������:\n"
            "0) ��������� � ���������� ����\n"
            "1) �������� ��� ��������\n"
            "2) �������� ���������� �� �������� �������� (� ������������ ������ ��� �� ������ �������)\n"
            "3) �������� ���������� �� ���� �������� (� ������������ ������ ��� �� ������ �������)\n"
            "4) �������� ���������� �� ���-�� ������\n");

        PutMessageOutConsole(L"������� �������:\n"
            "0) ��������� � ���������� ����\n"
            "1) �������� ��� ��������\n"
            "2) �������� ���������� �� �������� �������� (� ������������ ������ ��� �� ������ �������)\n"
            "3) �������� ���������� �� ���� �������� (� ������������ ������ ��� �� ������ �������)\n"
            "4) �������� ���������� �� ���-�� ������\n");
    }

    void ShowActionMenu3() {

        PutMessageLog(L"�������� ��������:\n"
            "0) ��������� � ���������� ����\n"
            "1) ������� �����\n"
            "2) ������ ����� �������\n"
            "3) ��� ������\n");

        PutMessageOutConsole(L"�������� ��������:\n"
            "0) ��������� � ���������� ����\n"
            "1) ������� �����\n"
            "2) ������ ����� �������\n"
            "3) ��� ������\n");
    }


    void PutMessageConsole(const wchar_t* msg) {
        wcout << msg << endl;
    }

    void PutMessageConsole(const wchar_t* msg, long num) {
        wcout << msg << num << endl;
    }

    void PutMessageConsole(list_wrapper& msg) {
        wchar_t* c_str = new wchar_t[msg.size + 1]{ 0 };    // � [size] ����� \0
        ConvertToChar(msg, &c_str);
        wcout << c_str;

        delete[] c_str;
    }

    void PutMessageOutConsole(const wchar_t* msg) {
        PutMessageOut(msg);
        PutMessageConsole(msg);
    }

    void PutMessageOutConsole(const wchar_t* msg, long num) {
        PutMessageOut(msg, num);
        PutMessageConsole(msg, num);
    }

    void PutMessageOutConsole(list_wrapper& msg) {
        PutMessageOut(msg);
        PutMessageConsole(msg);
    }

    void PutMessageOutConsoleLog(const wchar_t* msg) {
        PutMessageLog(msg);
        PutMessageOutConsole(msg);
    }

    void PutMessageOutConsoleLog(list_wrapper& msg) {
        PutMessageLog(msg);
        PutMessageOutConsole(msg);
    }

    void PutMessageOutConsoleLog(const wchar_t* msg, long num) {
        PutMessageLog(msg, num);
        PutMessageOutConsole(msg, num);
    }
};



