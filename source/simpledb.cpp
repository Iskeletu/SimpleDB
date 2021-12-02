#include <iostream>
#include <stdlib.h>
#include <string>

//Header inclusion
#include "./screens/screens.h"
#include "./commandhandler/commandhandler.h"

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
        std::cout<<"SimpleDB > ";
        std::cin>>input;

        if(input == "exit")
        {
            //Save and exit sequence.

            exit_flag = true;
        }
        else
        {
            //do stuff with command
        }
    }
//==================================================

    return 0;
}