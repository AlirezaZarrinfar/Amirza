#include <iostream>
#include <fstream>

using namespace std;
int MainMenu;


void Show_Main_Menu()
{
    cout << "Welcome to this game" << endl;
    cout << "****** Main Menu ******" << endl;
    cout << "1.Sign up" << endl;
    cout << "2.Login" << endl;
}

int Main_Menu_Entrance(int a)
{
    if (a != 1 || a != 2 || a != 3 || a != 4 || a != 5 || a != 6)
    cout << "Please enter the correct number";
    
    else if (a == 1)
    return 1;

    else if (a == 2)
    return 2;

}

int main()
{    
Show_Main_Menu();
cin >> MainMenu;

}