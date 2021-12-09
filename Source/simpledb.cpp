/*
Main file.
Mainly calls for functions from other files and provides raw user input.
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
int main()
{
    std::string input; //Raw user input.
    bool exit_flag = false; //Main loop exit flag.
    Command command("null");


    //=================SimpleDB Startup=================
    screens::PrintStartupScreen();
    std::cout<<"Carregando database..."<<std::endl;

    //Load sequence
    std::string dbname = "SimpleDB"; //Standard database name.
    Database db("null", "null"); //Creates blank database reference.
    if(fs::is_directory(fs::status("./Data/SimpleDB")))
    { //Loads db if it's folder exists.
        db = SimpleDB::LoadDB(dbname);
        std::cout<<"Concluído!"<<endl;
    }
    else
    { //Creates a new DB if there is none.
        db = SimpleDB::CreateDB(dbname);
        std::cout<<"Erro: Falha ao carregar database (arquivo inexistente)!"<<endl;
        std::cout<<"Criando database..."<<endl;
        std::cout<<"Concluído!"<<endl;
    }


    std::cout<<"Pressione a tecla enter para proseguir!"<<std::endl;
    std::getline(cin, input); system("clear"); input.clear();
    screens::PrintDefaultScreen();
    //==================================================


    //=====================Main loop====================
    while(!exit_flag)
    {
        std::cout<<"SimpleDB Terminal > "; //Deafult text.
        std::getline(cin, input); //Reads user input.
        command = (input);

        exit_flag = cli::ReadCommand(command, &db); //Checks for exit flag.
    }
    //==================================================


    //TODO save and exit sequence


    return 0;
}
//==================================================