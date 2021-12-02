#include <iostream>


//Header File
#include "screens.h"


//No other namespace will be used in this file
using namespace std;


void PrintStartupScreen()
{
    cout<<" ____________  ____________  ____________  ____________  ____________  ____________  ____________  ____________  "<<endl;
    cout<<"|\\____________\\\\____________\\\\____________\\\\____________\\\\____________\\\\____________\\\\____________\\\\____________\\"<<endl;
    cout<<"\\|____________\\|____________\\|____________\\|____________\\|____________\\|____________\\|____________\\|____________|"<<endl<<endl;
    cout<<"           ________  ___  _____ ______   ________  ___       _______   ________  ________                        "<<endl;
    cout<<"          |\\   ____\\|\\  \\|\\   _ \\  _   \\|\\   __  \\|\\  \\     |\\  ___ \\ |\\   ___ \\|\\   __  \\                       "<<endl;
    cout<<"          \\ \\  \\___|\\ \\  \\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\ \\  \\    \\ \\   __/|\\ \\  \\_|\\ \\ \\  \\|\\ /_                      "<<endl;
    cout<<"           \\ \\_____  \\ \\  \\ \\  \\\\|__| \\  \\ \\   ____\\ \\  \\    \\ \\  \\_|/_\\ \\  \\ \\\\ \\ \\   __  \\                     "<<endl;
    cout<<"            \\|____|\\  \\ \\  \\ \\  \\    \\ \\  \\ \\  \\___|\\ \\  \\____\\ \\  \\_|\\ \\ \\  \\_\\\\ \\ \\  \\|\\  \\                    "<<endl;
    cout<<"              ____\\_\\  \\ \\__\\ \\__\\    \\ \\__\\ \\__\\    \\ \\_______\\ \\_______\\ \\_______\\ \\_______\\                   "<<endl;
    cout<<"             |\\_________\\|__|\\|__|     \\|__|\\|__|     \\|_______|\\|_______|\\|_______|\\|_______|                   "<<endl;
    cout<<"             \\|_________|                                                                                        "<<endl<<endl;
    cout<<" ____________  ____________  ____________  ____________  ____________  ____________  ____________  ____________  "<<endl;
    cout<<"|\\____________\\\\____________\\\\____________\\\\____________\\\\____________\\\\____________\\\\____________\\\\____________\\"<<endl;
    cout<<"\\|____________\\|____________\\|____________\\|____________\\|____________\\|____________\\|____________\\|____________|"<<endl<<endl<<endl;
}


void PrintDefaultScreen()
{
    cout<<"+-------------------------------------+"<<endl;
    cout<<"|  Digite help para mais informações  |"<<endl;
    cout<<"+-------------------------------------+"<<endl<<endl;
}


void PrintUnknownCommandScreen()
{
    cout<<"Comando não reconhecido, digite 'help' para mais informações."<<endl<<endl;
}