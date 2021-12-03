/*
This file is responsible for command processing.
It formats raw data inputed by the user as commands that the
rest of the functions can understand, it's the user's bridge
to the database.
*/

//Libraries
#include <vector>
#include <sstream>


//Header Files
#include "commandhandler.h"
#include "screens.h"


//No other namespace will be used.
using namespace std;


//=================Command Formatter================
vector<string> FormatInput(std::string input)
{ //Creates a string vector divided by whitespaces from the raw user input.
    vector<string> formatted_input;
    string temp;

    istringstream ss(input);

    while(ss >> temp)
    {
        formatted_input.push_back(temp);
    }

    return formatted_input;
}
//==================================================


//=================Command Processor================
bool ReadCommand(string user_input)
{ //Reads raw input from user as command and calls for functions related.
    if(user_input.empty())
    { //Does nothing if input is blank.
        return false;
    }
    
    vector<string> formatted_input = FormatInput(user_input);
    string command = formatted_input[0]; //Takes the first group of characters before a white space as the main command.

    if(command == "help") //'help' command.
    {
        if(formatted_input.size() == 1)
        {
            PrintHelpScreen();
        }
        else if(formatted_input.size() == 2)
        {
            PrintArgumentHelpScreen(formatted_input[1]);

        }
        else
        {
            string argument = user_input;
            argument.erase(0, (command.size()+1));
            PrintInvalidHelpScreen(argument);
        }
    }
    else if(command == "simpledb") //'simpledb' command.
    {
        //TODO
    }
    else if(command == "clear") //'clear' command.
    {
        if(formatted_input.size() == 1)
        {
            ClearScreen();
        }
        else
        {
            string argument = user_input;
            argument.erase(0, (command.size()+1));
            PrintUnknownArgumentScreen(command, argument);
        }
    }
    else if(command == "exit") //'exit command.
    {
        if(formatted_input.size() == 1)
        {
            return true; //Breaks main loop.
        }
        else
        {
            string argument = user_input;
            argument.erase(0, (command.size()+1));
            PrintUnknownArgumentScreen(command, argument);
        }
    }
    else //Unknown command.
    {
        PrintUnknownCommandScreen(command);
    }

    return false; //Continues main loop.
}
//==================================================