/*
Main file.

Mainly calls for functions from other
files and provides raw user input.
*/


//Libraries
#include <iostream>
#include <string>
#include <filesystem>


//Header Files
#include "screens.h"
#include "commandhandler.h"
#include "dbhandler.h"


//=====================Namespace====================
namespace fs = std::filesystem;
//==================================================


//===================Main Function==================
int main(void)
{
    std::string input;                                                          //Raw user input.
    bool exit_flag = false;                                                     //Main loop exit flag.
    cli::Command command("null");


    //=================SimpleDB Startup=================
    screens::PrintStartupScreen();

    //Load Sequence
    std::string dbname = "SimpleDB";                                            //Standard database name.
    Database db("null", "null", Index::CreateIndex("null"));                    //Creates blank database reference.

    std::cout << "Carregando database..." << std::endl;

    if(fs::exists("./Data/" + dbname + "/" + dbname + ".db"))                    //!This will not work on windows
    { //Loads db into blank reference if it's file exists.
        db = SimpleDB::LoadDB(dbname);

        std::cout << "Concluído!" << std::endl;
    }
    else
    { //Creates a new DB if there is none and loads to blank reference.
        db = SimpleDB::CreateDB(dbname);

        std::cout << "Erro: Falha ao carregar database (arquivo inexistente)!" << std::endl;
        std::cout << "Criando database..." << std::endl;
        std::cout << "Concluído!" << std::endl;
    }

    std::cout << "Pressione a tecla enter para prosseguir!" << std::endl;
    std::getline(std::cin, input); system("clear"); input.clear();              //!This will not work on windows
    screens::PrintDefaultScreen();
    //==================================================


    //=====================Main Loop====================
    while(!exit_flag)
    {
        std::cout << "SimpleDB Terminal > ";                                    //Deafult text.
        std::getline(std::cin, input);                                          //Reads user input.
        command = (input);

        exit_flag = cli::ReadCommand(command, &db);                             //Checks for exit flag.
    }
    //==================================================
}
//==================================================