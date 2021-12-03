/*
Main file.
Mainly calls for functions from other files and provides raw user input.
*/


//Libraries
#include <iostream>


//Header Files
#include "screens.h"
#include "commandhandler.h"
#include "dbhandler.h"


//===================Main Function==================
int main()
{
    //Variable definition.
    std::string input; //Raw user input.
    bool exit_flag = false; //Main loop exit flag.


    //=================SimpleDB Startup=================
    PrintStartupScreen();
    //TODO load stuff
    std::cout<<"Pressione a tecla enter para proseguir!"<<std::endl; getchar(); system("clear");
    PrintDefaultScreen();
    //==================================================


    //=====================Main loop====================
    while(!exit_flag)
    {
        std::cout<<"SimpleDB Terminal > "; //Deafult text.
        std::getline(std::cin, input); //Reads user input.

        exit_flag = ReadCommand(input); //Checks for exit flag.
    }
    //==================================================


    //TODO save and exit sequence
    return 0;
}
//==================================================