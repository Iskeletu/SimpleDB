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
    cout<<"+----------------------------------------------+"<<endl;
    cout<<"|     Digite 'help' para mais informações.     |"<<endl;
    cout<<"+----------------------------------------------+"<<endl<<endl;
}

void PrintHelpScreen()
{
    cout<<"+----------------------------------------------+"<<endl;
    cout<<"|  '->' = Uso do comando.                      |"<<endl;
    cout<<"|  '*'  = Argumento dinsponível.               |"<<endl;
    cout<<"|                                              |"<<endl;
    cout<<"|  HELP  ->  Mostra essa tela.                 |"<<endl;
    cout<<"|    * help                                    |"<<endl;
    cout<<"|    * simpledb                                |"<<endl;
    cout<<"|    * clear                                   |"<<endl;
    cout<<"|    * exit                                    |"<<endl;
    cout<<"|  SIMPLEDB  ->  TODO.                         |"<<endl;
    cout<<"|    * --insert                                |"<<endl;
    cout<<"|    * --remove                                |"<<endl;
    cout<<"|    * --search                                |"<<endl;
    cout<<"|    * --update                                |"<<endl;
    cout<<"|    * --list                                  |"<<endl;
    cout<<"|    * --compress                              |"<<endl;
    cout<<"|    * --decompress                            |"<<endl;
    cout<<"|  CLEAR  ->  Limpa o histórico de mensagens.  |"<<endl;
    cout<<"|  EXIT  ->  Fecha o programa.                 |"<<endl;
    cout<<"|                                              |"<<endl;
    cout<<"|  Use 'help [comando]' para mais informações. |"<<endl;
    cout<<"+----------------------------------------------+"<<endl<<endl;
}


void PrintArgumentHelpScreen(string argument)
{
    if(argument == "help")
    {
        cout<<"+----------------------------------------------+"<<endl;
        cout<<"|  Comando: 'HELP'                             |"<<endl;
        cout<<"|    Exibe lista de comandos disponíveis para  |"<<endl;
        cout<<"|    execução                                  |"<<endl;
        cout<<"|                                              |"<<endl;
        cout<<"|  *Aceita os seguintes arugmentos:            |"<<endl;
        cout<<"|    -> 'HELP': Motra essa tela.               |"<<endl;
        cout<<"|    -> 'SIMPLEDB': Mostra informações sobre   |"<<endl;
        cout<<"|    o comando 'simpledb'.                     |"<<endl;
        cout<<"|    -> 'CLEAR': Mostra informaçãoes sobre o   |"<<endl;
        cout<<"|    comando 'clear'.                          |"<<endl;
        cout<<"|    -> 'EXIT': Mostra informaçãoes sobre o    |"<<endl;
        cout<<"|    comando 'exit'.                           |"<<endl;
        cout<<"+----------------------------------------------+"<<endl<<endl;
    }
    else if(argument == "simpledb")
    {
        cout<<"+----------------------------------------------+"<<endl;
        cout<<"|  TODO.                                       |"<<endl;
        cout<<"+----------------------------------------------+"<<endl<<endl;
    }
    else if(argument == "clear")
    {
        cout<<"+----------------------------------------------+"<<endl;
        cout<<"|  Comando: 'CLEAR'                            |"<<endl;
        cout<<"|    Limpa o hitórico de mensagens do termi-   |"<<endl;
        cout<<"|    nal.                                      |"<<endl;
        cout<<"|                                              |"<<endl;
        cout<<"|  *Não aceita argumentos.                     |"<<endl;
        cout<<"+----------------------------------------------+"<<endl<<endl;
    }
    else if(argument == "exit")
    {
        cout<<"+----------------------------------------------+"<<endl;
        cout<<"|  Comando: 'EXIT'                             |"<<endl;
        cout<<"|    Inicializa sequência de finalização e     |"<<endl;
        cout<<"|    encerra o SimpleDB.                       |"<<endl;
        cout<<"|                                              |"<<endl;
        cout<<"|  *Não aceita argumentos.                     |"<<endl;
        cout<<"+----------------------------------------------+"<<endl<<endl;
    }
    else
    {
        PrintInvalidHelpScreen(argument);
    }
}


void PrintInvalidHelpScreen(string command)
{
    cout<<"Nenhuma informação localizada para o comando '"<<command<<"'."<<endl;
    cout<<"Use 'help' sem argumentos para ver a lisca de comandos disponíveis."<<endl<<endl;
}


void PrintUnknownCommandScreen(string command)
{
    cout<<"Comando '"<<command<<"' não reconhecido, digite 'help' para mais informações."<<endl<<endl;
}


void PrintUnknownArgumentScreen(string command, string argument)
{
    cout<<"Argumento '"<<argument<<"' desconhecido para o comando '"<<command<<"'."<<endl;
    cout<<"Use 'help "<<command<<"' para mais informações."<<endl<<endl;
}


void ClearScreen()
{
    system("clear");
    cout<<"SimpleDB Terminal > clear"<<endl;
    cout<<"Concluído."<<endl<<endl;
}