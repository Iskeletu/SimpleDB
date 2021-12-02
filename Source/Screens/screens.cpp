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

void PrintHelpScreen()
{
    cout<<"+----------------------------------+"<<endl;
    cout<<"| HELP  ->  Shows this screen.     |"<<endl;
    cout<<"| SIMPLEDB  ->  Shows this screen. |"<<endl;
    cout<<"|    * --insert  ->  TODO          |"<<endl;
    cout<<"|    * --remove  ->  TODO          |"<<endl;
    cout<<"|    * --search  ->  TODO          |"<<endl;
    cout<<"|    * --update  ->  TODO          |"<<endl;
    cout<<"|    * --list  ->  TODO            |"<<endl;
    cout<<"|    * --compress  ->  TODO        |"<<endl;
    cout<<"|    * --decompress  ->  TODO      |"<<endl;
    cout<<"| EXIT  ->  Fecha o programa.      |"<<endl;
    cout<<"+----------------------------------+"<<endl<<endl;
}


void PrintArgumentHelp(string argument)
{
    if(argument == "help")
    {

    }
    else if(argument == "simpledb")
    {

    }
    else if(argument == "exit")
    {
        
    }
    else
    {
        PrintInvalidHelp(argument);
    }
}


void PrintInvalidHelp(string command)
{
    cout<<"Nenhuma informação localizada para o comando '"<<command<<"'."<<endl;
    cout<<"Use 'help' sem argumentos para ver a lisca de comandos disponíveis."<<endl<<endl;
}


void PrintUnknownCommandScreen(string command)
{
    cout<<"Comando '"<<command<<"' não reconhecido, digite 'help' para mais informações."<<endl<<endl;
}