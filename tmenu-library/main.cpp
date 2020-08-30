#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <vector>
#include <windows.h>
#include <iomanip>
#include "Tmenu.h"

using namespace std;

void main_menu();

void f1()
{
    TMenu Menu("Funkcja 1");
    Menu.add("Funkcja 1.1", f1);
    Menu.add("Funkcja 1.2", f1);
    Menu.add("Funkcja 1.3", f1);
    Menu.add("Funkcja 1.4", f1);
    Menu.add("Funkcja 1.5", f1);
    Menu.add("Cofnij", main_menu);
    Menu.view();
}

void f2()
{
    TMenu Menu("Funkcja 2");
    Menu.add("Funkcja 2.1", f2);
    Menu.add("Funkcja 2.2", f2);
    Menu.add("Funkcja 2.3", f2);
    Menu.add("Funkcja 2.4", f2);
    Menu.add("Funkcja 2.5", f2);
    Menu.add("Cofnij", main_menu);
    Menu.view();
}

void f3()
{
    TMenu Menu("Funkcja 3");
    Menu.add("Funkcja 3.1", f1);
    Menu.add("Funkcja 3.2", f1);
    Menu.add("Funkcja 3.3", f1);
    Menu.add("Funkcja 3.4", f1);
    Menu.add("Funkcja 3.5", f1);
    Menu.add("Cofnij", main_menu);
    Menu.view();
}

void f4()
{
    TMenu Menu("Funkcja 4");
    Menu.add("Funkcja 4.1", f1);
    Menu.add("Funkcja 4.2", f1);
    Menu.add("Funkcja 4.3", f1);
    Menu.add("Funkcja 4.4", f1);
    Menu.add("Funkcja 4.5", f1);
    Menu.add("Cofnij", main_menu);
    Menu.view();
}

void f5()
{
    TMenu Menu("Funkcja 5");
    Menu.add("Funkcja 5.1", f1);
    Menu.add("Funkcja 5.2", f1);
    Menu.add("Funkcja 5.3", f1);
    Menu.add("Funkcja 5.4", f1);
    Menu.add("Funkcja 5.5", f1);
    Menu.add("Cofnij", main_menu);
    Menu.view();
}

void f_exit()
{
    cout<<"Program zostanie zamkniêty"<<endl;
    _sleep(1000);
    system("cls");
    system("color f");
    exit(0);
}

void main_menu()
{
    TMenu Menu("Program");
    Menu.add("Funkcja 1", f1);
    Menu.add("Funkcja 2", f2);
    Menu.add("Funkcja 3", f3);
    Menu.add("Funkcja 4", f4);
    Menu.add("Funkcja 5", f5);
    Menu.add("Zamknij program", f_exit);
    Menu.view();
}

int main()
{
    setlocale( LC_ALL, "" );
    main_menu();
    return 0;
}
