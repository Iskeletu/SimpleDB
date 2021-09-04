#include <iostream>
#include <string>
#include <windows.h>

#include "screens\screens.h"

int main()
{
    //variable definition
    string input;
    bool exit_flag = false;

    //not important, delete after converting to linux
    SetConsoleOutputCP(65001);


//=================SimpleDB startup=================
    PrintStartupScreen();
    //do load stuff here
    system("pause"); system("cls");
//==================================================

    //Calls for default screen
    PrintDefaultScreen();


//=====================Main loop====================
    while(!exit_flag)
    {
        std::cin>>input;
    }
//==================================================

    return 0;
}