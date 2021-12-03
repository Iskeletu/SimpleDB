#include <iostream>


//Header File
#include "screens.h"


//No other namespace will be used in this file
using namespace std;


//==================Startup Screen==================
void PrintStartupScreen()
{ //Startup screens, it's only use is to have something to look at when the program is loading (shoudln't take long at all).
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
//==================================================


//==================Default Screen==================
void PrintDefaultScreen()
{ //Informational screen show when the program finished startup sequence and aloows user to use the terminal.
    cout<<"+----------------------------------------------+"<<endl;
    cout<<"|     Digite 'help' para mais informações.     |"<<endl;
    cout<<"+----------------------------------------------+"<<endl<<endl;
}
//==================================================


//================Help Command Screen===============
void PrintHelpScreen()
{ //Screen for 'help' command.
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
//==================================================


//==========Argumented Help Command Screen==========
void PrintArgumentHelpScreen(string argument)
{ //Has one screen for each of the commands that can be used as argument for 'help' command.
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
//==================================================


//============Invalid Help Command Screen===========
void PrintInvalidHelpScreen(string command)
{ //Default message for invalid 'help' command usage.
    cout<<"Nenhuma informação localizada para o comando '"<<command<<"'."<<endl;
    cout<<"Use 'help' sem argumentos para ver a lisca de comandos disponíveis."<<endl<<endl;
}
//==================================================


//===============Unknow Command Screen==============
void PrintUnknownCommandScreen(string command)
{ //Default message for unknown commands.
    cout<<"Comando '"<<command<<"' não reconhecido, digite 'help' para mais informações."<<endl<<endl;
}
//==================================================


//==============Unknow Argument Screen==============
void PrintUnknownArgumentScreen(string command, string argument)
{ //Default message for unknown arguments.
    cout<<"Argumento '"<<argument<<"' desconhecido para o comando '"<<command<<"'."<<endl;
    cout<<"Use 'help "<<command<<"' para mais informações."<<endl<<endl;
}
//==================================================


//===============Clear Command Screen===============
void ClearScreen()
{ //Completely aesthetical choice to undo the last command clearing from the terminal.
    system("clear");
    cout<<"SimpleDB Terminal > clear"<<endl;
    cout<<"Concluído."<<endl<<endl;
}
//==================================================