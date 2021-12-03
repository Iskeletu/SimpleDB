#include <iostream>


//Header inclusion
#include "screens.h"
#include "commandhandler.h"
#include "dbhandler.h"


int main()
{
    //variable definition
    std::string input;
    bool exit_flag = false;


//=================SimpleDB startup=================
    PrintStartupScreen();
    //do load stuff here
    std::cout<<"Pressione a tecla enter para proseguir!"<<std::endl; getchar(); system("clear");
//==================================================


    //Calls for default screen
    PrintDefaultScreen();


//=====================Main loop====================
    while(!exit_flag)
    {
        std::cout<<"SimpleDB Terminal > ";
        std::getline(std::cin, input);

        exit_flag = ReadCommand(input);
    }
//==================================================


//save and exit sequence

    return 0;
}