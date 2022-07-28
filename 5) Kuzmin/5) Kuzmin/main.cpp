#include "train.h"

ifstream train_carriages("train.txt");
ifstream train_info("train_info.txt");


void menu(train &a) {
    
    int t;
    cout << "1. About train\n" <<
        "2. Buy ticket\n" <<
        "0. Exit\n";
    cin >> t;
    system("cls");
    if (!t) return;
    if (t < 0 or t > 2) {        
        menu(a);
        return;
    }
    if (t == 1) {
        a.get_info();

    }
    if (t == 2) {
        a.order();
    }
    system("pause");
    system("cls");
    menu(a);
}

int main()
{
    train a;
    setlocale(LC_ALL, "Russian");
    a.create(train_carriages);
    a.add_about(train_info);
    system("pause");
    system("cls");
    menu(a);
    a.delete_train();

}       
