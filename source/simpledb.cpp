#include <iostream>
#include <string>
#include <windows.h>

#include "screens\screens.h"

int main()
{
    SetConsoleOutputCP(65001);

    PrintLogo();
    system("pause"); system("cls");

    int menu;

    PrintMainMenu();

    scanf("%d", &menu);

    PrintUnknown();

    return 0;
}