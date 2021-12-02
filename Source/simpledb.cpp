#include <iostream>


//Header inclusion
#include "screens.h"
#include "commandhandler.h"
//#include "dbhandler.h"


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
        std::cin>>input;

        if(input == "exit")
        {
            //Save and exit sequence.
            exit_flag = true;
        }
        else
        {
            ReadCommand(input);
        }
    }
//==================================================


    return 0;
}