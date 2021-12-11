/*
This file is responsible for all text generation/removal on the terminal.

The main purpose is making the terminal as user-friendly as
a text terminal can be.

commandhandler.cpp is dependant on this file.
*/


//Libraries
#include <iostream>
#include <string>


//Header Files
#include "screens.h"


//==================Startup Screen==================
void screens::PrintStartupScreen()
{ //Startup screen, its only use is to have something to look at when the program is starting up.
    std::cout << " ____________  ____________  ____________  ____________  ____________  ____________  ____________  ____________"                      << std::endl;
    std::cout << "|\\____________\\\\____________\\\\____________\\\\____________\\\\____________\\\\____________\\\\____________\\\\____________\\"    << std::endl;
    std::cout << "\\|____________\\|____________\\|____________\\|____________\\|____________\\|____________\\|____________\\|____________|"            << std::endl << std::endl;
    std::cout << "           ________  ___  _____ ______   ________  ___       _______   ________  ________"                                            << std::endl;
    std::cout << "          |\\   ____\\|\\  \\|\\   _ \\  _   \\|\\   __  \\|\\  \\     |\\  ___ \\ |\\   ___ \\|\\   __  \\"                          << std::endl;
    std::cout << "          \\ \\  \\___|\\ \\  \\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\ \\  \\    \\ \\   __/|\\ \\  \\_|\\ \\ \\  \\|\\ /_"             << std::endl;
    std::cout << "           \\ \\_____  \\ \\  \\ \\  \\\\|__| \\  \\ \\   ____\\ \\  \\    \\ \\  \\_|/_\\ \\  \\ \\\\ \\ \\   __  \\"                << std::endl;
    std::cout << "            \\|____|\\  \\ \\  \\ \\  \\    \\ \\  \\ \\  \\___|\\ \\  \\____\\ \\  \\_|\\ \\ \\  \\_\\\\ \\ \\  \\|\\  \\"           << std::endl;
    std::cout << "              ____\\_\\  \\ \\__\\ \\__\\    \\ \\__\\ \\__\\    \\ \\_______\\ \\_______\\ \\_______\\ \\_______\\"                  << std::endl;
    std::cout << "             |\\_________\\|__|\\|__|     \\|__|\\|__|     \\|_______|\\|_______|\\|_______|\\|_______|"                              << std::endl;
    std::cout << "             \\|_________|"                                                                                                           << std::endl << std::endl;
    std::cout << " ____________  ____________  ____________  ____________  ____________  ____________  ____________  ____________"                      << std::endl;
    std::cout << "|\\____________\\\\____________\\\\____________\\\\____________\\\\____________\\\\____________\\\\____________\\\\____________\\"    << std::endl;
    std::cout << "\\|____________\\|____________\\|____________\\|____________\\|____________\\|____________\\|____________\\|____________|"            << std::endl << std::endl << std::endl;
}
//==================================================


//==================Default Screen==================
void screens::PrintDefaultScreen()
{ //Informational screen shown when SimpleDB finishes starting up.
    std::cout << "+----------------------------------------------+" << std::endl;
    std::cout << "|     Digite 'help' para mais informações.     |" << std::endl;
    std::cout << "+----------------------------------------------+" << std::endl << std::endl;
}
//==================================================


//==============Unknown Command Screen==============
void screens::PrintUnknownCommandScreen(std::string* command)
{ //Default message for unknown commands.
    std::cout << "Erro: Comando '" << *command << "' não reconhecido." << std::endl;
    std::cout << "Use 'help' sem argumentos para ver a lista de comandos disponíveis." << std::endl << std::endl;
}
//==================================================


//==========Argumented Help Command Screen==========
void screens::PrintHelpScreen(std::string* argument, int type)
{ //Has one screen for each of it's arguments, including no argument and invalid argument.
    switch(type)
    {
        /*
        Type 1 = "help" command with no arguments.
        Type 2 = 'help help' command.
        Type 3 = 'help simpledb' command.
        Type 4 = 'help clear' command.
        Type 5 = 'help exit' command.
        Type 6 = Command 'help' has invalid arguments.
        */
        case 1:
            std::cout << "+----------------------------------------------+" << std::endl;
            std::cout << "|  '->' = Uso do comando.                      |" << std::endl;
            std::cout << "|  '*'  = Argumento disponível.                |" << std::endl;
            std::cout << "|                                              |" << std::endl;
            std::cout << "|  HELP  ->  Mostra essa tela.                 |" << std::endl;
            std::cout << "|    * help                                    |" << std::endl;
            std::cout << "|    * simpledb                                |" << std::endl;
            std::cout << "|    * clear                                   |" << std::endl;
            std::cout << "|    * exit                                    |" << std::endl;
            std::cout << "|  SIMPLEDB  ->  Realiza operações no BD.      |" << std::endl;
            std::cout << "|    * --insert                                |" << std::endl;
            std::cout << "|    * --remove                                |" << std::endl;
            std::cout << "|    * --search                                |" << std::endl;
            std::cout << "|    * --update                                |" << std::endl;
            std::cout << "|    * --list / --revese-list                  |" << std::endl;
            std::cout << "|    * --compress                              |" << std::endl;
            std::cout << "|    * --decompress                            |" << std::endl;
            std::cout << "|  CLEAR  ->  Limpa o histórico de mensagens.  |" << std::endl;
            std::cout << "|  EXIT  ->  Fecha o programa.                 |" << std::endl;
            std::cout << "|                                              |" << std::endl;
            std::cout << "|  Use 'help [comando]' para mais informações. |" << std::endl;
            std::cout << "+----------------------------------------------+" << std::endl << std::endl;
        break;

        case 2:
            std::cout << "+----------------------------------------------+" << std::endl;
            std::cout << "|  Comando: 'HELP'                             |" << std::endl;
            std::cout << "|    Exibe a lista de comandos disponíveis pa- |" << std::endl;
            std::cout << "|    ra execução                               |" << std::endl;
            std::cout << "|                                              |" << std::endl;
            std::cout << "|  *Aceita os seguintes argumentos:            |" << std::endl;
            std::cout << "|    -> 'HELP': Motra essa tela.               |" << std::endl;
            std::cout << "|    -> 'SIMPLEDB': Mostra informações sobre   |" << std::endl;
            std::cout << "|    o comando 'simpledb'.                     |" << std::endl;
            std::cout << "|    -> 'CLEAR': Mostra informações sobre o    |" << std::endl;
            std::cout << "|    comando 'clear'.                          |" << std::endl;
            std::cout << "|    -> 'EXIT': Mostra informações sobre o co- |" << std::endl;
            std::cout << "|    mando 'exit'.                             |" << std::endl;
            std::cout << "+----------------------------------------------+" << std::endl << std::endl;
        break;
    
        case 3: //TODO
            std::cout << "+----------------------------------------------+" << std::endl;
            std::cout << "|  TODO.                                       |" << std::endl;
            std::cout << "+----------------------------------------------+" << std::endl << std::endl;
        break;
    
        case 4:
            std::cout << "+----------------------------------------------+" << std::endl;
            std::cout << "|  Comando: 'CLEAR'                            |" << std::endl;
            std::cout << "|    Limpa o hitórico de mensagens do termi-   |" << std::endl;
            std::cout << "|    nal.                                      |" << std::endl;
            std::cout << "|                                              |" << std::endl;
            std::cout << "|  *Não aceita argumentos.                     |" << std::endl;
            std::cout << "+----------------------------------------------+" << std::endl << std::endl;
        break;
    
        case 5:
            std::cout << "+----------------------------------------------+" << std::endl;
            std::cout << "|  Comando: 'EXIT'                             |" << std::endl;
            std::cout << "|    Inicializa sequência de finalização e     |" << std::endl;
            std::cout << "|    encerra o SimpleDB.                       |" << std::endl;
            std::cout << "|                                              |" << std::endl;
            std::cout << "|  *Não aceita argumentos.                     |" << std::endl;
            std::cout << "+----------------------------------------------+" << std::endl<<std::endl;
        break;

        case 6:
            std::cout << "Erro: Nenhuma informação localizada para o comando '" << *argument << "'." << std::endl;
            std::cout << "Use 'help' sem argumentos para ver a lista de comandos disponíveis." << std::endl << std::endl;
        break;
    }
}
//==================================================


//===============Argument Error Screen==============
void screens::PrintArgumentErrorScreen(std::string* command, std::string* argument, int type)
{ //Default messages for errors with arguments.
    switch(type)
    {
        /*
        Type 1 = Unrecognized argument.
        Type 2 = Too few arguments.
        Type 3 = Too many arguments.
        Type 4 = No arguments needed.
        */
        case 1:
            std::cout << "Erro: Argumento '" << *argument << "' não reconhecido para o comando '" << *command << "'." << std::endl;
        break;

        case 2:
            std::cout << "Erro: Argumentos insuficientes para o comando '" << *command << "'." << std::endl;
        break;

        case 3:
            std::cout << "Erro: Argumentos em excesso para o comando '" << *command << "'." << std::endl;
        break;

        case 4:
            std::cout << "Erro: Comando '" << *command << "' não aceita argumentos." << std::endl;
        break;
    }

    std::cout << "Use 'help " << *command << "' para mais informações." << std::endl << std::endl;
}
//==================================================


//===========Expression Error Screen==========
void screens::PrintExpressionErrorScreen(std::string* command, std::string* argument, std::string* expression, int type)
{ //Default messages for errors with expression.
    switch(type)
    {
        /*
        Type 1 = Expression is invalid.
        Type 2 = Expression is missing.
        Type 3 = Too few parameters in expression.
        Type 4 = Too many parameters in expression.
        Type 5 = No expression needed.
        */
        case 1:
            std::cout << "Erro: Expressão '" << *expression << "' é inválida para o argumento '" << *argument << "'." << std::endl;
        break;

        case 2:
            std::cout << "Erro: Expressão não pode estar em branco para o argumento '" << *argument << "'." << std::endl;
        break;

        case 3:
            std::cout << "Erro: Arguemnto '" << *argument << "' requer mais parâmetros na expressão." << std::endl;
        break;

        case 4:
            std::cout << "Erro: Argumento '" << *argument << "' requer menos parâmetros na expressão." << std::endl;
        break;

        case 5:
            std::cout << "Erro: Argumento '" << *argument << "' não aceita expressões." << std::endl;
        break;
    }

    std::cout << "Use 'help " << *command << "' para mais informações." << std::endl << std::endl;
}
//==================================================


//====================Done Screen===================
void screens::PrintDone()
{ //Prints a standard "done" message when a command without return successfuly completes.
    std::cout << "Operação concluída!" << std::endl << std::endl;
}
//==================================================


//===============Clear Command Screen===============
void screens::ClearScreen()
{ //Clears the screen and prints the last command done with a standard "done" message.
    system("clear");                                                            //!This will not work on windows

    std::cout << "SimpleDB Terminal > clear" << std::endl;                      //Completely aesthetical choice to redo the last command.

    screens::PrintDone();
}
//==================================================


//==================Print Datacell==================
void screens::PrintDatacell(Datacell* existingcell)
{ //Prints datacell to screen.
    std::cout << "'" << existingcell->GetKey() << "': [" << std::endl;          //Uses a json-like template.
    std::cout << "\t'Sorting_Key': " << existingcell->GetSortingKey() << "," << std::endl;
    std::cout << "\t'Value': " << existingcell->GetValue() << std::endl;
    std::cout << "]" << std::endl << std::endl;
}
//==================================================


//=================Print Invalid Key================
void screens::PrintInvalidKeyScreen(std::string* key)
{ //Prints a stantdard "invalid key" message for failed update/removal procedures.
    std::cout << "Erro: A chave '" << *key << "' não existe na database!" << std::endl << std::endl;
}
//==================================================