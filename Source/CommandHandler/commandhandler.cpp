#include <iostream>


//Header files
#include "commandhandler.h"
#include "../Screens/screens.h"


void ReadCommand(std::string user_input)
{
    std::string command;

    command = user_input; //change this

    if(command == "simpledb")
    {

    }
    else if(command == "help")
    {
        PrintHelpScreen();
    }
    else
    {
        PrintUnknownCommandScreen(command);
    }
    
}