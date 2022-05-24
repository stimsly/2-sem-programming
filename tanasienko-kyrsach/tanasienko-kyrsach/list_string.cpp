#include "list_string.h"

char list_wrapper::operator[] (int index) {
    if (index == -1)       return '\0';     // память не инициализирована
    if (index == size - 1) return tail->c;

    int i = 0;
    list_string* ptr = head;
    while (i != index && ptr != NULL)
        MoveByChar(&ptr);

    return ptr->c;
}

void list_wrapper::InitializeWrapper(list_string* h) {
    if (size != -1) FreeString(*this);

    head = h;
    tail = head;

    if (h->c != '\0') size = 1;
    else size = 0;

    // Пояснение: '\0' используется в списке исключительно, как обозначение считанной пустоты.
}

void MoveByChar(list_string** list_str) {
    if (list_str != NULL)
        if (*list_str != NULL)
            *list_str = (*list_str)->next;
}

void AddSymb(list_wrapper& list_wrap, char c) {
    list_string* ptr = list_wrap.tail;
    // ptr - указатель на хвост
    if (ptr != NULL) {                  // Если это не первый элемент, то хвост существует
        ptr->next = new list_string;
        ptr = ptr->next;
        ptr->c = c;
        ptr->next = NULL;
        list_wrap.tail = ptr;

        list_wrap.size++;  //  Увеличили размер.
    }
    else {                            // Нет хвоста - нет и головы, создадим их.
        list_wrap.head = new list_string;
        list_wrap.head->c = c;
        list_wrap.head->next = NULL;
        list_wrap.tail = list_wrap.head;
        list_wrap.size = 1;
    }
}

void FreeString(list_wrapper& list_wrap) {
    list_string* ptr = list_wrap.head;

    while (ptr != NULL) {
        list_string* to_delete = ptr;
        MoveByChar(&ptr);
        delete to_delete;
    }

    list_wrap.head = NULL;
    list_wrap.tail = NULL;
    list_wrap.size = -1;
}

void CopySymb(list_string* dest, list_string* origin) {
    dest->c = origin->c;
}

void CopyString(list_wrapper& dest, list_wrapper& origin) {
    if (dest.size != -1)
        FreeString(dest);

    list_string* ptr = origin.head;
    while (ptr != NULL) {
        AddSymb(dest, ptr->c);
        MoveByChar(&ptr);
    }

    {
        // Старый вариант решения

//    // Дабы не возникло проблем с памятью:
//    list_string* new_head = new list_string;    // Создаём новую копию с выделенной памятью под каждую
//    list_string* ptr = origin.head;
//
//    while (ptr != NULL) {
//        CopySymb(new_head, ptr);
//        new_head->next = NULL;
//        MoveByChar(ptr);
//    }
//
//    dest.size = origin.size;
    }
}

bool CmpString(list_wrapper& str1, list_wrapper& str2) {
    if (str1.size != str2.size) {
        return false;                            // str1 != str2
    }
    else {
        list_string* ptr1 = str1.head;
        list_string* ptr2 = str2.head;

        while (ptr1 != NULL) {
            if (ptr1->c != ptr2->c) return false;   // str1 != str2
            MoveByChar(&ptr1);
            MoveByChar(&ptr2);
        }
    }

    return true;       // str1 == str2
}

void ConvertToString(list_wrapper& list_wrap, char* c_str, int size) {
    int i = 0;
    if (list_wrap.size > 0) FreeString(list_wrap);
    while (c_str[i] != '\0' && c_str[i] != '\n' && i < size) {
        AddSymb(list_wrap, c_str[i]);
        i++;
    }
}