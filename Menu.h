#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
#include <limits>
#include <string>

using namespace std;

int getOption(){
    int input;
    system("cls");

    cout << "-----Rental Mobil-----" << endl;
    cout << "1. Show All Car" << endl;
    cout << "2. Add Car" << endl;
    cout << "3. Show All User" << endl;
    cout << "4. Add User" << endl;
    cout << "5. Change Car Status" << endl;
    cout << "6. Delete Car" << endl;
    cout << "7. Keluar" << endl;

    cout << "Masukkan pilihan menu: "; cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    return input;
}


#endif // MENU_H_INCLUDED
