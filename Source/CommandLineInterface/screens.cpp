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
    std::cout << "|     Digite 'help' para mais informa????es.     |" << std::endl;
    std::cout << "+----------------------------------------------+" << std::endl << std::endl;
}
//==================================================


//==============Unknown Command Screen==============
void screens::PrintUnknownCommandScreen(std::string* command)
{ //Default message for unknown commands.
    std::cout << "Erro: Comando '" << *command << "' n??o reconhecido." << std::endl;
    std::cout << "Use 'help' sem argumentos para ver a lista de comandos dispon??veis." << std::endl << std::endl;
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
            std::cout << "|  '*'  = Argumento dispon??vel.                |" << std::endl;
            std::cout << "|                                              |" << std::endl;
            std::cout << "|  HELP  ->  Mostra essa tela.                 |" << std::endl;
            std::cout << "|    * help                                    |" << std::endl;
            std::cout << "|    * simpledb                                |" << std::endl;
            std::cout << "|    * clear                                   |" << std::endl;
            std::cout << "|    * exit                                    |" << std::endl;
            std::cout << "|  SIMPLEDB  ->  Realiza opera????es no BD.      |" << std::endl;
            std::cout << "|    * --insert                                |" << std::endl;
            std::cout << "|    * --remove                                |" << std::endl;
            std::cout << "|    * --search                                |" << std::endl;
            std::cout << "|    * --update                                |" << std::endl;
            std::cout << "|    * --list / --revese-list                  |" << std::endl;
            std::cout << "|    * --compress                              |" << std::endl;
            std::cout << "|    * --decompress                            |" << std::endl;
            std::cout << "|  CLEAR  ->  Limpa o hist??rico de mensagens.  |" << std::endl;
            std::cout << "|  EXIT  ->  Fecha o programa.                 |" << std::endl;
            std::cout << "|                                              |" << std::endl;
            std::cout << "|  Use 'help [comando]' para mais informa????es. |" << std::endl;
            std::cout << "+----------------------------------------------+" << std::endl << std::endl;
        break;

        case 2:
            std::cout << "+----------------------------------------------+" << std::endl;
            std::cout << "|  Comando: 'help'                             |" << std::endl;
            std::cout << "|    Exibe a lista de comandos dispon??veis pa- |" << std::endl;
            std::cout << "|    ra execu????o.                              |" << std::endl;
            std::cout << "|                                              |" << std::endl;
            std::cout << "|  *Aceita um dos seguintes argumentos:        |" << std::endl;
            std::cout << "|    -> 'help': Motra essa tela.               |" << std::endl;
            std::cout << "|    -> 'simpledb': Mostra informa????es sobre   |" << std::endl;
            std::cout << "|    o comando 'simpledb'.                     |" << std::endl;
            std::cout << "|    -> 'clear': Mostra informa????es sobre o    |" << std::endl;
            std::cout << "|    comando 'clear'.                          |" << std::endl;
            std::cout << "|    -> 'exit': Mostra informa????es sobre o co- |" << std::endl;
            std::cout << "|    mando 'exit'.                             |" << std::endl;
            std::cout << "+----------------------------------------------+" << std::endl << std::endl;
        break;
    
        case 3:
            std::cout << "+----------------------------------------------+" << std::endl;
            std::cout << "|  Comando: 'SIMPLEDB'                         |" << std::endl;
            std::cout << "|    Realiza opera????s no arquivo do banco de   |" << std::endl;
            std::cout << "|    dados.                                    |" << std::endl;
            std::cout << "|                                              |" << std::endl;
            std::cout << "|  *Requer um dos seguintes argumentos:        |" << std::endl;
            std::cout << "|    -> '--insert': Realiza uma opera????o de    |" << std::endl;
            std::cout << "|    inser????o de chave no arquivo do banco de  |" << std::endl;
            std::cout << "|    dados. Requer uma express??o no formato:   |" << std::endl;
            std::cout << "|      -> '=<[Chave_de_Ordena????o],[String]>'   |" << std::endl;
            std::cout << "|    -> '--remove': Realiza uma opera????o de    |" << std::endl;
            std::cout << "|    remo????o de chave no arquivo do banco de   |" << std::endl;
            std::cout << "|    dados. Requer uma express??o no formato:   |" << std::endl;
            std::cout << "|      -> '=<[Chave]>'                         |" << std::endl;
            std::cout << "|    -> '--search': Realiza uma opera????o de    |" << std::endl;
            std::cout << "|    busca de valor relacionado a uma chave no |" << std::endl;
            std::cout << "|    arquivo do banco de dados. Requer uma ex- |" << std::endl;
            std::cout << "|    press??o no formato:                       |" << std::endl;
            std::cout << "|      -> '=<[Chave]>'                         |" << std::endl;
            std::cout << "|    -> '--update': Realiza uma opera????o de    |" << std::endl;
            std::cout << "|    atualiza????o de valores relacionados a uma |" << std::endl;
            std::cout << "|    chave no arquivo do banco de dados. Re-   |" << std::endl;
            std::cout << "|    quer uma express??o no formato:            |" << std::endl;
            std::cout << "|      -> '=<[Chave]>,[Chave-Ordena????o],-'     |" << std::endl;
            std::cout << "|      [String]>                               |" << std::endl;
            std::cout << "|    -> '--list': Lista as chaves inseridas no |" << std::endl;
            std::cout << "|    arquivo do banco de dados de acordo com o |" << std::endl;
            std::cout << "|    valor de sua chave de ordena????o em ordem  |" << std::endl;
            std::cout << "|    crescente. Requer uma express??o no se-    |" << std::endl;
            std::cout << "|    guinte formato:                           |" << std::endl;
            std::cout << "|      -> '=<key(Operador_Matem??tico)-         |" << std::endl;
            std::cout << "|      [N??mero_Inteiro]'                       |" << std::endl;
            std::cout << "|    -> '--reverse-list': Lista as chaves in-  |" << std::endl;
            std::cout << "|    seridas no arquivo do banco de dados de   |" << std::endl;
            std::cout << "|    acordo com o valor de sua chave de orde-  |" << std::endl;
            std::cout << "|    na????o em ordem decrescente. Requer uma    |" << std::endl;
            std::cout << "|    express??o no seguinte formato:            |" << std::endl;
            std::cout << "|      -> '=<key(Operador_Matem??tico)-         |" << std::endl;
            std::cout << "|      [N??mero_Inteiro]'                       |" << std::endl;
            std::cout << "|    -> '--compress': Comprime o arquivo do    |" << std::endl;
            std::cout << "|    bando de dados de acordo com um dos se-   |" << std::endl;
            std::cout << "|    guintes identificadores:                  |" << std::endl;
            std::cout << "|      -> '=huffman': M??todo de compress??o     |" << std::endl;
            std::cout << "|      Huffman.                                |" << std::endl;
            std::cout << "|      -> '=lzw': M??todo de compress??o LZW.    |" << std::endl;
            std::cout << "|    -> '--decompress': Descomprime um arquivo |" << std::endl;
            std::cout << "|    de banco de dados pr??viamente comprimido  |" << std::endl;
            std::cout << "|    de acordo com um dos seguintes identifi-  |" << std::endl;
            std::cout << "|    cadores:                                  |" << std::endl;
            std::cout << "|      -> '=huffman': M??todo de descompress??o  |" << std::endl;
            std::cout << "|      Huffman.                                |" << std::endl;
            std::cout << "|      -> '=lzw': M??todo de descompress??o LZW. |" << std::endl;
            std::cout << "|                                              |" << std::endl;
            std::cout << "|  *Lista de operadores matem??ticos implemen-  |" << std::endl;
            std::cout << "|  tados:                                      |" << std::endl;
            std::cout << "|    -> (=)                                    |" << std::endl;
            std::cout << "|    -> (>)                                    |" << std::endl;
            std::cout << "|    -> (<)                                    |" << std::endl;
            std::cout << "|    -> (>=)                                   |" << std::endl;
            std::cout << "|    -> (<=)                                   |" << std::endl;
            std::cout << "+----------------------------------------------+" << std::endl << std::endl;
        break;
    
        case 4:
            std::cout << "+----------------------------------------------+" << std::endl;
            std::cout << "|  Comando: 'clear'                            |" << std::endl;
            std::cout << "|    Limpa o hit??rico de mensagens do termi-   |" << std::endl;
            std::cout << "|    nal.                                      |" << std::endl;
            std::cout << "|                                              |" << std::endl;
            std::cout << "|  *N??o aceita argumentos.                     |" << std::endl;
            std::cout << "+----------------------------------------------+" << std::endl << std::endl;
        break;
    
        case 5:
            std::cout << "+----------------------------------------------+" << std::endl;
            std::cout << "|  Comando: 'exit'                             |" << std::endl;
            std::cout << "|    Inicializa sequ??ncia de finaliza????o e     |" << std::endl;
            std::cout << "|    encerra o SimpleDB.                       |" << std::endl;
            std::cout << "|                                              |" << std::endl;
            std::cout << "|  *N??o aceita argumentos.                     |" << std::endl;
            std::cout << "+----------------------------------------------+" << std::endl<<std::endl;
        break;

        case 6:
            std::cout << "Erro: Nenhuma informa????o localizada para o comando '" << *argument << "'." << std::endl;
            std::cout << "Use 'help' sem argumentos para ver a lista de comandos dispon??veis." << std::endl << std::endl;
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
            std::cout << "Erro: Argumento '" << *argument << "' n??o reconhecido para o comando '" << *command << "'." << std::endl;
        break;

        case 2:
            std::cout << "Erro: Argumentos insuficientes para o comando '" << *command << "'." << std::endl;
        break;

        case 3:
            std::cout << "Erro: Argumentos em excesso para o comando '" << *command << "'." << std::endl;
        break;

        case 4:
            std::cout << "Erro: Comando '" << *command << "' n??o aceita argumentos." << std::endl;
        break;
    }

    std::cout << "Use 'help " << *command << "' para mais informa????es." << std::endl << std::endl;
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
            std::cout << "Erro: Express??o '" << *expression << "' ?? inv??lida para o argumento '" << *argument << "'." << std::endl;
        break;

        case 2:
            std::cout << "Erro: Express??o n??o pode estar em branco para o argumento '" << *argument << "'." << std::endl;
        break;

        case 3:
            std::cout << "Erro: Arguemnto '" << *argument << "' requer mais par??metros na express??o." << std::endl;
        break;

        case 4:
            std::cout << "Erro: Argumento '" << *argument << "' requer menos par??metros na express??o." << std::endl;
        break;

        case 5:
            std::cout << "Erro: Argumento '" << *argument << "' n??o aceita express??es." << std::endl;
        break;
    }

    std::cout << "Use 'help " << *command << "' para mais informa????es." << std::endl << std::endl;
}
//==================================================


//====================Done Screen===================
void screens::PrintDone()
{ //Prints a standard "done" message when a command without return successfuly completes.
    std::cout << "Opera????o conclu??da!" << std::endl << std::endl;
}
//==================================================


//==================String Printer==================
void screens::LogToScreen(std::string PrintString)
{ //Prints string to terminal.
    std::cout << PrintString << std::endl << std::endl;
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
void DatacellPrinter(Datacell* datacell)
{ //Prints datacell to screen.
//Slave function to "screesn::PrintDatacell".
    std::cout << "'" << datacell->GetKey() << "': [" << std::endl;          //Uses a json-like template.
    std::cout << "\t'Sorting_Key': " << datacell->GetSortingKey() << "," << std::endl;
    std::cout << "\t'Value': " << datacell->GetValue() << std::endl;
    std::cout << "]" << std::endl << std::endl;
}

void screens::PrintDatacell(Datacell* oldcell, Datacell* existingcell, int type)
{ //calls for DatacellPrinter based on printing type.
    switch(type)
    {
        /*
        Type 1 = Function was called to print an insertion.
        Type 2 = Function was called to print a value search.
        Type 3 = Function was called to print a key removal.
        Type 4 = Function was called to print a key update.
        */
        case 1:
            std::cout << "Inser????o conclu??da:" << std::endl;
        break;

        case 2:
            std::cout << "Resultado da busca:" << std::endl;
        break;

        case 3:
            std::cout << "Chave removida:" << std::endl;
        break;

        case 4:
            std::cout << "Chave atualizada:" << std::endl << std::endl;
            std::cout << "DE:" << std::endl;
            DatacellPrinter(oldcell);
            std::cout << "PARA:" << std::endl;
        break;
    }

    DatacellPrinter(existingcell);
}
//==================================================


//=================Print Invalid Key================
void screens::PrintInvalidKeyScreen(std::string* key)
{ //Prints a stantdard "invalid key" message for failed update/removal procedures.
    std::cout << "Erro: A chave '" << *key << "' n??o existe na database!" << std::endl << std::endl;
}
//==================================================