/*
This file is responsible for the command line interface.
It formats raw data inputed by the user as commands that the
rest of the functions can understand, it's the user's bridge
to the database.
*/


//Libraries
#include <string>
#include <string_view>
#include <sstream>
#include <cstring>


//Header Files
#include "commandhandler.h"
#include "screens.h"


//====================Constructor===================
Command::Command(std::string user_input) :
    member_unformatted_command(user_input), 
    member_full_command(CommandFormatter(user_input)), 
    member_main_command(member_full_command[0]), 
    member_command_size(member_full_command.size())
{;}
//==================================================


//=================Command Formatter================
std::vector<std::string> Command::CommandFormatter(std::string user_input)
{ //Creates a string vector divided by whitespaces from the raw user input.
    vector<string> formatted_command;

    if(user_input.empty() || (user_input.rfind(" ", 0) == 0))
    { //Returns a "null" string if user_input is blank or starts with a blank space.
        formatted_command.push_back("null");
        return formatted_command;
    }

    string temp;
    istringstream ss(user_input);

    while(ss >> temp)
    {
        formatted_command.push_back(temp);
    }

    return formatted_command;
}
//==================================================


//===============Expression Formatter===============
bool ExpressionFormatter(std::string expression, std::vector<std::string>* formatted_expression)
{ //Creates a string vector divided by commas from the raw expression.
    bool is_valid = true;
    stringstream  ss(expression);

    while (ss.good())
    {
        string temp;
        getline(ss, temp, ',');

        if(!temp.empty())
        {
            formatted_expression->push_back(temp);
        }
        else
        { //Insert a "null" into the current vector position if there is no data between commas.
            is_valid = false;
            formatted_expression->push_back("null");
        }
    }

    return is_valid;
}
//==================================================


//================Expression Verifier===============
std::vector<std::string> ExpressionVerifier(std::string *expression, int type, bool* valid_flag)
{ //Analyzes expression and returns true if it is valid.
    vector<string> formatted_expression;

    if(expression->rfind("=", 0) == 0)
    {
        expression->erase(0, 1);
        string temp = *expression;

        if(expression->length() > 2)
        {
            switch(type)
            {
                case 1:
                    if(temp[0] == '<' && temp[temp.length()-1] == '>')
                    {
                        expression->erase(0, 1);
                        expression->pop_back();
                        *valid_flag = ExpressionFormatter(*expression, &formatted_expression);

                        if(formatted_expression.size() != 2)
                        {
                            *valid_flag = false;
                        }
                    }
                break;

                case 2:
                    if(temp[0] == '<' && temp[temp.length()-1] == '>')
                    {
                        expression->erase(0, 1);
                        expression->pop_back();
                        *valid_flag = ExpressionFormatter(*expression, &formatted_expression);

                        if(formatted_expression.size() != 1)
                        {
                            *valid_flag = false;
                        }
                    }
                break;

                case 3:
                    if(temp[0] == '<' && temp[temp.length()-1] == '>')
                    {
                        expression->erase(0, 1);
                        expression->pop_back();
                        *valid_flag = ExpressionFormatter(*expression, &formatted_expression);

                        if(formatted_expression.size() != 1)
                        {
                            *valid_flag = false;
                        }
                    }
                break;

                case 4:
                    if(temp[0] == '<' && temp[temp.length()-1] == '>')
                    {
                        expression->erase(0, 1);
                        expression->pop_back();
                        *valid_flag = ExpressionFormatter(*expression, &formatted_expression);

                        if(formatted_expression.size() != 3)
                        {
                            *valid_flag = false;
                        }
                    }
                break;

                case 5:
                    if(*expression == "huffman" || *expression == "lzw")
                    {
                        *valid_flag = true;
                        formatted_expression.push_back(*expression);
                    }
                break;
            }
        }
    }
    else if(expression->empty())
    {
        *expression = "null";
    }

    return formatted_expression;
}
//==================================================


//================Argument Formatter================
std::vector<std::string> ArgumentFormatter(std::string *argument, std::string *expression, int type, bool* valid_flag)
{ //Separates expression for argument.
    switch(type)
    {
        case 1:
            *expression = argument->erase(0, 8);
            *argument = "--insert";
        break;

        case 2:
            *expression = argument->erase(0, 8);
            *argument = "--remove";
        break;

        case 3:
            *expression = argument->erase(0, 8);
            *argument = "--search";
        break;

        case 4:
            *expression = argument->erase(0, 8);
            *argument = "--update";
        break;
        
        case 5:
            *expression = argument->erase(0, 10);
            *argument = "--compress";
        break;

        case 6:
            *expression = argument->erase(0, 12);
            *argument = "--decompress";
            type--;
        break;
    }

    return ExpressionVerifier(expression, type, valid_flag);
}
//==================================================


//=================Command Processor================
bool cli::ReadCommand(Command command, Database* db)
{ //Reads raw input from user as command and calls for functions related.
    if(command.member_command_size == 1 && command.member_main_command == "null")
    { //Does nothing if input is blank.
        return false;
    }


    //Command recognition.
    if(command.member_main_command == "help") //'help' command.
    {
        if(command.member_command_size == 1)
        {
            screens::PrintHelpScreen();
        }
        else if(command.member_command_size == 2)
        {
            screens::PrintArgumentHelpScreen(command.member_full_command[1]);

        }
        else
        {
            std::string argument = command.member_unformatted_command;
            argument.erase(0, (command.member_main_command.size()+1));
            screens::PrintInvalidHelpScreen(argument);
        }
    }
    else if(command.member_main_command == "simpledb") //'simpledb' command.
    {
        if(command.member_command_size == 1)
        {
            screens::PrintInsufficientArgumentScreen(command.member_main_command);
        }
        else if(command.member_command_size == 2)
        {
            std::string expression;
            bool valid_expression = false;
            std::string argument = command.member_full_command[1];
            std::vector<std::string> formatted_expression;

            if(argument.rfind("--insert", 0) == 0)
            {
                formatted_expression = ArgumentFormatter(&argument, &expression, 1, &valid_expression);

                if (valid_expression)
                {
                    db->InsertKeyValue(formatted_expression[0], formatted_expression[1]);
                    screens::PrintDone();
                }
                else
                {
                    screens::PrintUnknownExpressionScreen(command.member_main_command, argument, expression);
                }
            }
            else if(argument.rfind("--remove", 0) == 0)
            {
                formatted_expression = ArgumentFormatter(&argument, &expression, 2, &valid_expression);
                if (valid_expression)
                {
                    //proceed
                }
                else
                {
                    screens::PrintUnknownExpressionScreen(command.member_main_command, argument, expression);
                }
            }
            else if(argument.rfind("--search", 0) == 0)
            {
                formatted_expression = ArgumentFormatter(&argument, &expression, 3, &valid_expression);
                if (valid_expression)
                {
                    screens::PrintKeyValue(formatted_expression[0], db->SearchKeyValue(formatted_expression[0]));
                }
                else
                {
                    screens::PrintUnknownExpressionScreen(command.member_main_command, argument, expression);
                }
            }
            else if(argument.rfind("--update", 0) == 0)
            {
                formatted_expression = ArgumentFormatter(&argument, &expression, 4, &valid_expression);
                if (valid_expression)
                {
                    //proceed
                }
                else
                {
                    screens::PrintUnknownExpressionScreen(command.member_main_command, argument, expression);
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
                    std::string expression = argument.erase(0, 6);
                    screens::PrintUnknownExpressionScreen(command.member_main_command, "--list", expression);
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
                    std::string expression = argument.erase(0, 14);
                    screens::PrintUnknownExpressionScreen(command.member_main_command, "--reverse-list", expression);
                }
            }
            else if(argument.rfind("--compress", 0) == 0)
            {
                formatted_expression = ArgumentFormatter(&argument, &expression, 5, &valid_expression);
                if (valid_expression)
                {
                    //proceed
                }
                else
                {
                    screens::PrintUnknownExpressionScreen(command.member_main_command, argument, expression);
                }
            }
            else if(argument.rfind("--decompress", 0) == 0)
            {
                formatted_expression = ArgumentFormatter(&argument, &expression, 6, &valid_expression);
                if (valid_expression)
                {
                    //proceed
                }
                else
                {
                    screens::PrintUnknownExpressionScreen(command.member_main_command, argument, expression);
                }
            }
            else
            {
                screens::PrintUnknownArgumentScreen(command.member_main_command, argument);
            }
        }
        else
        {
            std::string argument = command.member_unformatted_command;
            argument.erase(0, (command.member_main_command.size()+1));
            screens::PrintUnknownArgumentScreen(command.member_main_command, argument);
        }
    }
    else if(command.member_main_command == "clear") //'clear' command.
    {
        if(command.member_command_size == 1)
        {
            screens::ClearScreen();
        }
        else
        {
            std::string argument = command.member_unformatted_command;
            argument.erase(0, (command.member_main_command.size()+1));
            screens::PrintUnknownArgumentScreen(command.member_main_command, argument);
        }
    }
    else if(command.member_main_command == "exit") //exit command.
    {
        if(command.member_command_size == 1)
        {
            return true; //Breaks main loop.
        }
        else
        {
            std::string argument = command.member_unformatted_command;
            argument.erase(0, (command.member_main_command.size()+1));
            screens::PrintUnknownArgumentScreen(command.member_main_command, argument);
        }
    }
    else //Unknown command.
    {
        screens::PrintUnknownCommandScreen(command.member_main_command);
    }

    return false; //Continues main loop.
}
//==================================================