#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <conio.h>
#include"DBase.h"
#include"Menu.h"

using namespace std;

int getOption();

int main()
{

    int option = getOption();
    char is_continue;
    enum enumoption{SHOWCAR = 1, ADDCAR = 2, SHOWUSER = 3, ADDUSER = 4, CHANGE = 5, DELETE = 6, CLOSE = 7};
    Dbase databaseMobil = Dbase("DataMobil.txt");
    Dbase databaseUser = Dbase("DataUser.txt");

    while (option != CLOSE){
        switch (option){
        case SHOWCAR:
            databaseMobil.showAllMobil();
            break;
        case ADDCAR:
            databaseMobil.addMobil();
            break;
        case SHOWUSER:
            databaseUser.showAllUser();
            break;
        case ADDUSER:
            databaseUser.addUser();
            databaseMobil.showAvMobil();
            databaseMobil.changeStatusMobil();
            databaseMobil.showAvMobil();
            break;
        case CHANGE:
            databaseMobil.showAllMobil();
            databaseMobil.changeStatusMobil();
            databaseMobil.showAllMobil();
            break;
        case DELETE:
            databaseMobil.showAllMobil();
            databaseMobil.deleteMobil();
            databaseMobil.showAllMobil();
            break;
        default:
            break;
        }

        cout <<"-enter any key to continue-";
        is_continue = getch();
        option = getOption();
    }

    return 0;
}
