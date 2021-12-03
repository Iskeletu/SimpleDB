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


//================Expression Verifier===============
bool ExpressionVerifier(string expression, int type)
{ //Analyzes expression and returns true if it is valid.
    //TODO

    return true;
}
//==================================================


//=================Command Formatter================
vector<string> InputFormatter(string input)
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


//=================Argument Formatter================
bool ArgumentFormatter(string *argument, string *expression, int type)
{ //Separates expression for argument.
    string temp = *argument;

    switch(type)
    {
        case 1:
            *expression = temp.erase(0, 8);
            *argument = "--insert";
            break;

        case 2:
            expression = &argument->erase(0, 8);
            *argument = "--remove";
            break;

        case 3:
            expression = &argument->erase(0, 8);
            *argument = "--search";
            break;

        case 4:
            expression = &argument->erase(0, 8);
            *argument = "--update";
            break;
        
        case 5:
            expression = &argument->erase(0, 10);
            *argument = "--compress";
            break;

        case 6:
            expression = &argument->erase(0, 12);
            *argument = "--decompress";
            break;
    }

    return ExpressionVerifier(*expression, type);
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


    //Be prepared for a big if-else block.
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
            string expression;
            bool valid_expression = false;
            string argument = formatted_input[1];

            if(argument.rfind("--insert", 0) == 0)
            {
                valid_expression = ArgumentFormatter(&argument, &expression, 1);
                if (valid_expression)
                {
                    //proceed
                }
                else
                {
                    PrintUnknownExpressionScreen(command, argument, expression);
                }
            }
            else if(argument.rfind("--remove", 0) == 0)
            {
                valid_expression = ArgumentFormatter(&argument, &expression, 2);
                if (valid_expression)
                {
                    //proceed
                }
                else
                {
                    PrintUnknownExpressionScreen(command, argument, expression);
                }
            }
            else if(argument.rfind("--search", 0) == 0)
            {
                valid_expression = ArgumentFormatter(&argument, &expression, 3);
                if (valid_expression)
                {
                    //proceed
                }
                else
                {
                    PrintUnknownExpressionScreen(command, argument, expression);
                }
            }
            else if(argument.rfind("--update", 0) == 0)
            {
                valid_expression = ArgumentFormatter(&argument, &expression, 4);
                if (valid_expression)
                {
                    //proceed
                }
                else
                {
                    PrintUnknownExpressionScreen(command, argument, expression);
                }
            }
            else if(argument.rfind("--list", 0) == 0)
            {
                if(argument == "--list")
                {
                    //proceed
                }
                else
                {
                    string expression = argument.erase(0, 6);
                    PrintUnknownExpressionScreen(command, "--list", expression);
                }
            }
            else if(argument.rfind("--reverse-list", 0) == 0)
            {
                if(argument == "--reverse-list")
                {
                    //proceed
                }
                else
                {
                    string expression = argument.erase(0, 14);
                    PrintUnknownExpressionScreen(command, "--reverse-list", expression);
                }
            }
            else if(argument.rfind("--compress", 0) == 0)
            {
                valid_expression = ArgumentFormatter(&argument, &expression, 5);
                if (valid_expression)
                {
                    //proceed
                }
                else
                {
                    PrintUnknownExpressionScreen(command, argument, expression);
                }
            }
            else if(argument.rfind("--decompress", 0) == 0)
            {
                valid_expression = ArgumentFormatter(&argument, &expression, 5);
                if (valid_expression)
                {
                    //proceed
                }
                else
                {
                    PrintUnknownExpressionScreen(command, argument, expression);
                }
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