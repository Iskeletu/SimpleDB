/*
This file is responsible for command processing.
It formats raw data inputed by the user as commands that the
rest of the functions can understand, it's the user's bridge
to the database.
*/

//Libraries
//#include <string>
//#include <string_view>
#include <vector>
#include <sstream>


//Header Files
#include "commandhandler.h"
#include "screens.h"


//No other namespace will be used.
using namespace std;


//=================Command Formatter================
vector<string> InputFormatter(std::string input)
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


//=================Command Formatter================
string ArgumentFormatter(std::string input)
{ //Separates expression for argument.
    string expression;
    
    //TODO

    return expression;
}
//==================================================


//=================Command Processor================
bool ReadCommand(string user_input)
{ //Reads raw input from user as command and calls for functions related.
    if(user_input.empty())
    { //Does nothing if input is blank.
        return false;
    }
    
    vector<string> formatted_input = InputFormatter(user_input);
    string command = formatted_input[0]; //Takes the first group of characters before a white space as the main command.
    int command_size = formatted_input.size();

    if(command == "help") //'help' command.
    {
        if(command_size == 1)
        {
            PrintHelpScreen();
        }
        else if(command_size == 2)
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
        if(command_size == 1)
        {
            PrintInsufficientArgumentScreen(command);
        }
        else if(command_size == 2)
        {
            string argument = formatted_input[1];

            if(argument.rfind("--insert", 0) == 0)
            {

            }
            else if(argument.rfind("--remove", 0) == 0)
            {

            }
            else if(argument.rfind("--search", 0) == 0)
            {

            }
            else if(argument.rfind("--update", 0) == 0)
            {

            }
            else if(argument.rfind("--list", 0) == 0)
            {

            }
            else if(argument.rfind("--reverse-list", 0) == 0)
            {

            }
            else if(argument.rfind("--compress", 0) == 0)
            {

            }
            else if(argument.rfind("--decompress", 0) == 0)
            {

            }
            else
            {
                PrintUnknownArgumentScreen(command, argument);
            }
        }
        else
        {
            string argument = user_input;
            argument.erase(0, (command.size()+1));
            PrintUnknownArgumentScreen(command, argument);
        }
    }
    else if(command == "clear") //'clear' command.
    {
        if(command_size == 1)
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
        if(command_size == 1)
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