/*
This file is responsible for all text generation/removal on the terminal.
The main purpose is making the terminal as user-friendly as
a text terminal can be.
Command line interface is dependant on this file.
*/


//Libraries
#include <iostream>


//Header Files
#include "screens.h"


//==================Startup Screen==================
void screens::PrintStartupScreen()
{ //Startup screens, it's only use is to have something to look at when the program is loading (shoudln't take long at all).
    std::cout<<" ____________  ____________  ____________  ____________  ____________  ____________  ____________  ____________  "<<std::endl;
    std::cout<<"|\\____________\\\\____________\\\\____________\\\\____________\\\\____________\\\\____________\\\\____________\\\\____________\\"<<std::endl;
    std::cout<<"\\|____________\\|____________\\|____________\\|____________\\|____________\\|____________\\|____________\\|____________|"<<std::endl<<std::endl;
    std::cout<<"           ________  ___  _____ ______   ________  ___       _______   ________  ________                        "<<std::endl;
    std::cout<<"          |\\   ____\\|\\  \\|\\   _ \\  _   \\|\\   __  \\|\\  \\     |\\  ___ \\ |\\   ___ \\|\\   __  \\                       "<<std::endl;
    std::cout<<"          \\ \\  \\___|\\ \\  \\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\ \\  \\    \\ \\   __/|\\ \\  \\_|\\ \\ \\  \\|\\ /_                      "<<std::endl;
    std::cout<<"           \\ \\_____  \\ \\  \\ \\  \\\\|__| \\  \\ \\   ____\\ \\  \\    \\ \\  \\_|/_\\ \\  \\ \\\\ \\ \\   __  \\                     "<<std::endl;
    std::cout<<"            \\|____|\\  \\ \\  \\ \\  \\    \\ \\  \\ \\  \\___|\\ \\  \\____\\ \\  \\_|\\ \\ \\  \\_\\\\ \\ \\  \\|\\  \\                    "<<std::endl;
    std::cout<<"              ____\\_\\  \\ \\__\\ \\__\\    \\ \\__\\ \\__\\    \\ \\_______\\ \\_______\\ \\_______\\ \\_______\\                   "<<std::endl;
    std::cout<<"             |\\_________\\|__|\\|__|     \\|__|\\|__|     \\|_______|\\|_______|\\|_______|\\|_______|                   "<<std::endl;
    std::cout<<"             \\|_________|                                                                                        "<<std::endl<<std::endl;
    std::cout<<" ____________  ____________  ____________  ____________  ____________  ____________  ____________  ____________  "<<std::endl;
    std::cout<<"|\\____________\\\\____________\\\\____________\\\\____________\\\\____________\\\\____________\\\\____________\\\\____________\\"<<std::endl;
    std::cout<<"\\|____________\\|____________\\|____________\\|____________\\|____________\\|____________\\|____________\\|____________|"<<std::endl<<std::endl<<std::endl;
}
//==================================================


//==================Default Screen==================
void screens::PrintDefaultScreen()
{ //Informational screen show when the program finished startup sequence and aloows user to use the terminal.
    std::cout<<"+----------------------------------------------+"<<std::endl;
    std::cout<<"|     Digite 'help' para mais informações.     |"<<std::endl;
    std::cout<<"+----------------------------------------------+"<<std::endl<<std::endl;
}
//==================================================


//=======================Done=======================
void screens::PrintDone()
{ //Prints a standard "done" message when a command without return successfuly completes.
    std::cout<<"Concluído."<<std::endl<<std::endl;
}
//==================================================


//================Help Command Screen===============
void screens::PrintHelpScreen()
{ //Screen for 'help' command.
    std::cout<<"+----------------------------------------------+"<<std::endl;
    std::cout<<"|  '->' = Uso do comando.                      |"<<std::endl;
    std::cout<<"|  '*'  = Argumento dinsponível.               |"<<std::endl;
    std::cout<<"|                                              |"<<std::endl;
    std::cout<<"|  HELP  ->  Mostra essa tela.                 |"<<std::endl;
    std::cout<<"|    * help                                    |"<<std::endl;
    std::cout<<"|    * simpledb                                |"<<std::endl;
    std::cout<<"|    * clear                                   |"<<std::endl;
    std::cout<<"|    * exit                                    |"<<std::endl;
    std::cout<<"|  SIMPLEDB  ->  Realiza operações no BD.      |"<<std::endl;
    std::cout<<"|    * --insert                                |"<<std::endl;
    std::cout<<"|    * --remove                                |"<<std::endl;
    std::cout<<"|    * --search                                |"<<std::endl;
    std::cout<<"|    * --update                                |"<<std::endl;
    std::cout<<"|    * --list / --revese-list                  |"<<std::endl;
    std::cout<<"|    * --compress                              |"<<std::endl;
    std::cout<<"|    * --decompress                            |"<<std::endl;
    std::cout<<"|  CLEAR  ->  Limpa o histórico de mensagens.  |"<<std::endl;
    std::cout<<"|  EXIT  ->  Fecha o programa.                 |"<<std::endl;
    std::cout<<"|                                              |"<<std::endl;
    std::cout<<"|  Use 'help [comando]' para mais informações. |"<<std::endl;
    std::cout<<"+----------------------------------------------+"<<std::endl<<std::endl;
}
//==================================================


//==========Argumented Help Command Screen==========
void screens::PrintArgumentHelpScreen(std::string argument)
{ //Has one screen for each of the commands that can be used as argument for 'help' command.
    if(argument == "help")
    {
        std::cout<<"+----------------------------------------------+"<<std::endl;
        std::cout<<"|  Comando: 'HELP'                             |"<<std::endl;
        std::cout<<"|    Exibe lista de comandos disponíveis para  |"<<std::endl;
        std::cout<<"|    execução                                  |"<<std::endl;
        std::cout<<"|                                              |"<<std::endl;
        std::cout<<"|  *Aceita os seguintes arugmentos:            |"<<std::endl;
        std::cout<<"|    -> 'HELP': Motra essa tela.               |"<<std::endl;
        std::cout<<"|    -> 'SIMPLEDB': Mostra informações sobre   |"<<std::endl;
        std::cout<<"|    o comando 'simpledb'.                     |"<<std::endl;
        std::cout<<"|    -> 'CLEAR': Mostra informaçãoes sobre o   |"<<std::endl;
        std::cout<<"|    comando 'clear'.                          |"<<std::endl;
        std::cout<<"|    -> 'EXIT': Mostra informaçãoes sobre o    |"<<std::endl;
        std::cout<<"|    comando 'exit'.                           |"<<std::endl;
        std::cout<<"+----------------------------------------------+"<<std::endl<<std::endl;
    }
    else if(argument == "simpledb")
    {
        std::cout<<"+----------------------------------------------+"<<std::endl;
        std::cout<<"|  TODO.                                       |"<<std::endl;
        std::cout<<"+----------------------------------------------+"<<std::endl<<std::endl;
    }
    else if(argument == "clear")
    {
        std::cout<<"+----------------------------------------------+"<<std::endl;
        std::cout<<"|  Comando: 'CLEAR'                            |"<<std::endl;
        std::cout<<"|    Limpa o hitórico de mensagens do termi-   |"<<std::endl;
        std::cout<<"|    nal.                                      |"<<std::endl;
        std::cout<<"|                                              |"<<std::endl;
        std::cout<<"|  *Não aceita argumentos.                     |"<<std::endl;
        std::cout<<"+----------------------------------------------+"<<std::endl<<std::endl;
    }
    else if(argument == "exit")
    {
        std::cout<<"+----------------------------------------------+"<<std::endl;
        std::cout<<"|  Comando: 'EXIT'                             |"<<std::endl;
        std::cout<<"|    Inicializa sequência de finalização e     |"<<std::endl;
        std::cout<<"|    encerra o SimpleDB.                       |"<<std::endl;
        std::cout<<"|                                              |"<<std::endl;
        std::cout<<"|  *Não aceita argumentos.                     |"<<std::endl;
        std::cout<<"+----------------------------------------------+"<<std::endl<<std::endl;
    }
    else
    {
        PrintInvalidHelpScreen(argument);
    }
}
//==================================================


//============Invalid Help Command Screen===========
void screens::PrintInvalidHelpScreen(std::string command)
{ //Default message for invalid 'help' command usage.
    std::cout<<"Nenhuma informação localizada para o comando '"<<command<<"'."<<std::endl;
    std::cout<<"Use 'help' sem argumentos para ver a lisca de comandos disponíveis."<<std::endl<<std::endl;
}
//==================================================


//==============Unknown Command Screen==============
void screens::PrintUnknownCommandScreen(std::string command)
{ //Default message for unknown commands.
    std::cout<<"Comando '"<<command<<"' não reconhecido, digite 'help' para mais informações."<<std::endl<<std::endl;
}
//==================================================


//==============Unknown Argument Screen=============
void screens::PrintUnknownArgumentScreen(std::string command, std::string argument)
{ //Default message for unknown arguments.
    std::cout<<"Argumento '"<<argument<<"' desconhecido para o comando '"<<command<<"'."<<std::endl;
    std::cout<<"Use 'help "<<command<<"' para mais informações."<<std::endl<<std::endl;
}
//==================================================


//===========Insufficient Argument Screen===========
void screens::PrintInsufficientArgumentScreen(std::string command)
{
    std::cout<<"Argumentos insuficientes para o comando '"<<command<<"'."<<std::endl;
    std::cout<<"Use 'help "<<command<<"' para mais informações."<<std::endl<<std::endl;
}
//==================================================


//=============Unknown Expression Screen=============
void screens::PrintUnknownExpressionScreen(std::string command, std::string argument, std::string expression)
{ //Default message for unknown arguments.
    if(expression != "null")
    { //Invalid Expression
        std::cout<<"Expressão '"<<expression<<"' inválida para o argumento '"<<argument<<"'."<<std::endl;
        std::cout<<"Use 'help "<<command<<"' para mais informações."<<std::endl<<std::endl;
    }
    else
    { //Missing Expression
        std::cout<<"Expressão não pode estar em branco para o argumento '"<<argument<<"'."<<std::endl;
        std::cout<<"Use 'help "<<command<<"' para mais informações."<<std::endl<<std::endl;
    }
}
//==================================================


//===============Clear Command Screen===============
void screens::ClearScreen()
{ //Completely aesthetical choice to undo the last command clearing from the terminal.
    system("clear"); //This will not work on windows
    std::cout<<"SimpleDB Terminal > clear"<<std::endl;
    screens::PrintDone();
}
//==================================================


//===============Clear Command Screen===============
void screens::PrintKeyValue(std::string key, std::string value)
{ //Prints values of a key inside the database.
    std::cout<<"'"<<key<<"': {"<<std::endl;
    std::cout<<"\t'"<<value<<"'"<<std::endl;
    std::cout<<'}'<<std::endl<<std::endl;
}
//==================================================