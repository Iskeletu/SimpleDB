#include <iostream>
#include <windows.h>

#include "screens\screens.h"

int main()
{
    SetConsoleOutputCP(65001);

    printlogo();
    system("pause"); system("cls");

    int menu;
    do
    {
        printmainmenu();
        std::cin>>menu;
        system("cls");

        if(menu < 0 || menu > 3)
        {
            printf("Opção inválida!\n\n");
        }
    }while(menu < 0 || menu > 3);

    switch(menu)
    {
        case 0:
            return 0;
            break;

        case 1:
            break;

        case 2:
            break;

        case 3:
            break;
    }
}