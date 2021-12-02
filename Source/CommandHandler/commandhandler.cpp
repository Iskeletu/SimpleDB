#include <vector>
#include <sstream>


//Header files
#include "commandhandler.h"
#include "screens.h"


//No other namespace will be used.
using namespace std;


//=================Command Formatter================
vector<string> FormatInput(std::string input)
//Creates a string vector divided by whitespaces from the raw user input.
{
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
void ReadCommand(string user_input)
{
    vector<string> formatted_input = FormatInput(user_input);
    string command = formatted_input[0]; //Takes the first group of characters before a white space as the main command.

    if(command == "simpledb")
    {

    }
    else if(command == "help")
    {
        if(formatted_input.size() == 1)
        {
            PrintHelpScreen();
        }
        else if(formatted_input.size() == 2)
        {
            PrintArgumentHelp(formatted_input[1]);

        }
        else
        {
            string argument = user_input;
            argument.erase(0, (command.size()+1));
            PrintInvalidHelp(argument);
        }
    }
    else
    {
        PrintUnknownCommandScreen(command);
    }
    
}
//==================================================