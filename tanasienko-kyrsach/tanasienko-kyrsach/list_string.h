#pragma once

#include "iostream"

struct list_string {
    char c = '\0';
    list_string* next = NULL;
};


struct list_wrapper {
    list_string* head = NULL;
    list_string* tail = NULL;
    int size = -1;              // Память не инициализирована = -1, Считана пустая строка = 0.

    char operator[] (int index);    // нахождение i-го элемента

    void InitializeWrapper(list_string* h);
};

void InitializeWrapper(list_string* h);
void MoveByChar(list_string** list_str);
void AddSymb(list_wrapper& list_wrap, char c); // Добавление символа в конец списка
void FreeString(list_wrapper& list_wrap); // Удаление с головы списка
void CopySymb(list_string* dest, list_string* origin);  // копирование одиночного символа
void CopyString(list_wrapper& dest, list_wrapper& origin); // копирование символов

bool CmpString(list_wrapper& str1, list_wrapper& str2);
void ConvertToString(list_wrapper& list_wrap, char* c_str, int size);