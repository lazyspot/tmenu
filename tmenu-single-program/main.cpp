#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <vector>
#include <windows.h>
#include <iomanip>

using namespace std;

void main_menu();

class TMenu
{
    public:
        TMenu(string _Title);
        TMenu(void);

        void add(string _Name, void (*procedure) () );
        void view();
        void SetTitle(string _Title);


    private:
        struct TItem
        {
            string Name;
            void (*procedure)();
        };
        string Title;
        string Max;
        string spac;

        int max;
        int index;

        vector <TItem> List;
};

TMenu::TMenu(string _Title)
{
    //system("windows1250");
    Title = _Title;
    max = Title.size() + 4;

    index = 0;
}

void TMenu::add(string Name, void (*procedure) ())
{
    if (Name != "")
    {
        TItem item;
        item.Name = Name;
        item.procedure = procedure;

        List.push_back(item);

        max = (Name.size() + 4 > max)? Name.size() + 4 : max;

        Max  = "";
        spac = "";
        for (int i = 0; i < max; i ++)
        {
            Max += '-';
            spac += ' ';
        }
    }
}

void TMenu::view()
{
    //system("windows1250");
    char c = '/0';
    do
    {
        system("cls");

        cout << endl;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                    FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "  +" << Max << '+' << endl;

        cout << "  |"
                << spac.substr(0, (max - Title.size()) / 2)
                << Title
                << spac.substr(0, max - Title.size() - ((max - Title.size()) / 2))
                << '|' << endl;

        cout << "  +" << Max.substr(0, max) << '+' << endl;

        for (int i = 0; i < List.size(); i ++)
        {
            cout << "  |";
            if (i == index)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            }

            cout << spac.substr(0, (max - List[i].Name.size()) / 2)
                 << List[i].Name
                 << spac.substr(0, (max - (List[i].Name.size()) - (max - List[i].Name.size()) / 2) );

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                    FOREGROUND_GREEN | FOREGROUND_INTENSITY);

            cout << '|' << endl;
        }

        cout << "  +" << Max << "+";

        c = getch();
        if (c == 72 && index > 0) //down
        {
            index --;
        }

        if (c == 80 && index < List.size() - 1) //up
        {
            index ++;
        }
    }
    while (c != 13 && c != 27);

    if (c == 27)
    {
        system("exit");
    }

    if (c  == 13)
    {
        //cout << index << endl; //80 down
        system("cls");
        (*List[index].procedure)();
    }
}

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
