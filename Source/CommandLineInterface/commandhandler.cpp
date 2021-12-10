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


//Local Reference
Database cli_db_reference("null", "null");                                      //Local reference to the database.


//====================Constructor===================
cli::Command::Command(std::string user_input) :
    member_unformatted_command(user_input), 
    member_full_command(CommandFormatter(user_input)), 
    member_main_command(member_full_command[0]), 
    member_command_size(member_full_command.size())
{;}
//==================================================


//=================Command Formatter================
std::vector<std::string> cli::Command::CommandFormatter(std::string user_input)
{ //Creates a string vector divided by whitespaces from the raw user input.
    std::vector<std::string> formatted_command;

    if(user_input.empty() || (user_input.rfind(" ", 0) == 0))
    { //Returns a "null" string if user_input is blank or starts with a blank space.
        formatted_command.push_back("null");
        return formatted_command;
    }

    std::string temp;
    std::istringstream ss(user_input);

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
    std::stringstream  ss(expression);

    while (ss.good())
    {
        std::string temp;
        getline(ss, temp, ',');

        if(!temp.empty())
        { //Stores "temp" into the current positon of the vector if it is not empty.
            formatted_expression->push_back(temp);
        }
        else
        { //Insert a "null" into the current vector position if there is no data between commas.
            is_valid = false;                                                   //Flags the expression as invalid.
            formatted_expression->push_back("null");
        }
    }

    return is_valid;                                                            //Will return true by default if this fuction does not flag as a invalid expression at any point.
}
//==================================================


//================Expression Verifier===============
std::vector<std::string> ExpressionVerifier(std::string *expression, int type, bool* valid_flag)
{ //Analyzes expression and returns true if it is valid.
    std::vector<std::string> formatted_expression;

    if(expression->rfind("=", 0) == 0)
    { //Checks if expression is formatted correctly for general commands.
        expression->erase(0, 1); //Removes "=" from expression;

        if(expression->length() > 2)
        { //Proceeds if "expression" has more than two charcters.
            switch(type)
            { //Type: 1 = insert | 2 = remove | 3 = search | 4 = update | 5 = compress & decomrpress;
                case 1:
                    if((*expression)[0] == '<' && (*expression)[expression->length()-1] == '>')
                    { //Checks if expression is formatted correctly.
                        expression->erase(0, 1); expression->pop_back();        //Removes "<>" from expression;

                        //Checks if expression is valid and has enough terms for type 1.
                        *valid_flag = ExpressionFormatter(*expression, &formatted_expression);
                        if(formatted_expression.size() != 2)
                        { //Does not have the right amount of parameters.
                            *valid_flag = false;
                        }
                        
                        //Confirms if the first parameter is a positive integer;
                        if(formatted_expression[0].find_first_not_of( "0123456789" ) == std::string::npos)
                        { //The string is an intenger, this checks if it is higher then 0;
                            int prmscan = std::stoi(formatted_expression[0]);

                            if(prmscan <= 0)
                            { //Integer is not higher than 0;
                                *valid_flag = false;
                            }
                        }
                        else
                        { //String is not and integer.
                            *valid_flag = false;
                        }
                    }
                break;

                case 2: //TODO
                    if((*expression)[0] == '<' && (*expression)[expression->length()-1] == '>')
                    { //Checks if expression is formatted correctly.
                        expression->erase(0, 1); expression->pop_back();        //Removes "<>" from expression;

                        //Checks if expression is valid and has enough terms for type 2.
                        *valid_flag = ExpressionFormatter(*expression, &formatted_expression);
                        if(formatted_expression.size() != 1)
                        { //Does not have the right amount of parameters.
                            *valid_flag = false;
                        }
                    }
                break;

                case 3: //TODO
                    if((*expression)[0] == '<' && (*expression)[expression->length()-1] == '>')
                    { //Checks if expression is formatted correctly.
                        expression->erase(0, 1); expression->pop_back();        //Removes "<>" from expression;

                        //Checks if expression is valid and has enough terms for type 3.
                        *valid_flag = ExpressionFormatter(*expression, &formatted_expression);
                        if(formatted_expression.size() != 1)
                        { //Does not have the right amount of parameters.
                            *valid_flag = false;
                        }
                    }
                break;

                case 4: //TODO
                    if((*expression)[0] == '<' && (*expression)[expression->length()-1] == '>')
                    { //Checks if expression is formatted correctly.
                        expression->erase(0, 1); expression->pop_back();        //Removes "<>" from expression;

                        //Checks if expression is valid and has enough terms for type 4.
                        *valid_flag = ExpressionFormatter(*expression, &formatted_expression);
                        if(formatted_expression.size() != 3)
                        { //Does not have the right amount of parameters.
                            *valid_flag = false;
                        }

                        //Confirms if the first parameter is a valid key within the database.
                        if(!dbh::IsValidKey(formatted_expression[0], &cli_db_reference))
                        { //The informed key is not a valid key within the database.
                            *valid_flag = false;
                        }

                        //Confirms if the second parameter is a positive integer;
                        if(formatted_expression[1].find_first_not_of( "0123456789" ) == std::string::npos)
                        { //The string is an intenger, this checks if it is higher then 0;
                            int prmscan = std::stoi(formatted_expression[1]);

                            if(prmscan <= 0)
                            { //Integer is not higher than 0;
                                *valid_flag = false;
                            }
                        }
                        else
                        { //String is not and integer.
                            *valid_flag = false;
                        }
                    }
                break;

                case 5:
                    if(*expression == "huffman" || *expression == "lzw")
                    { //Checks if expression is valid for type 5.
                        *valid_flag = true;
                        formatted_expression.push_back(*expression);
                    }
                    else
                    { //Expression is not a valid string for type 5.
                        *valid_flag = false;
                    }
                break;
            }
        }
    }
    else if(expression->empty())
    { //Sets expression to "null" if it's empty.
        *expression = "null";
        *valid_flag = false;
    }

    return formatted_expression;
}
//==================================================


//================Argument Formatter================
std::vector<std::string> ArgumentFormatter(std::string *argument, std::string* expression, int type, bool* valid_flag)
{ //Separates expression for argument.
    switch(type)
    { //Type: 1 = insert | 2 = remove | 3 = search | 4 = update | 5 = compress | 6 = decompress;
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
bool cli::ReadCommand(cli::Command command, Database* db)
{ //Reads raw input data from user as a command and calls for related functions.
    cli_db_reference = *db;                                                     //Sets local database reference.

    if(command.member_command_size == 1 && command.member_main_command == "null")
    { //Does nothing if user input is blank.
        return false;
    }


    //Command recognition.
    if(command.member_main_command == "help")
    { //'help' command.
        if(command.member_command_size == 1)
        { //Command without arguments.
            screens::PrintHelpScreen();
        }
        else if(command.member_command_size == 2)
        { //Valid argument;
            screens::PrintArgumentHelpScreen(command.member_full_command[1]);

        }
        else
        { //Inalid argument;
            //Sets "argument" as everything after the main command and prints the error message.
            std::string argument = command.member_unformatted_command;
            argument.erase(0, (command.member_main_command.size()+1));
            screens::PrintInvalidHelpScreen(argument);
        }
    }
    else if(command.member_main_command == "simpledb")
    { //'simpledb' command.
        if(command.member_command_size == 1)
        { //Insufficient arguments.
            screens::PrintInsufficientArgumentScreen(command.member_main_command);
        }
        else if(command.member_command_size == 2)
        { //Valid argument.
            std::string argument = command.member_full_command[1];
            std::vector<std::string> formatted_expression;
            std::string expression;
            bool valid_expression = false;

            if(argument.rfind("--insert", 0) == 0)
            { //"--insert" argument.
                formatted_expression = ArgumentFormatter(&argument, &expression, 1, &valid_expression);

                //Checks for valid expression.
                if (valid_expression)
                { //Creates a new datacell with user input and insert to the database.
                    int sorting_key = std::stoi(formatted_expression[0]);
                    Datacell newcell = Datacell::CreateDatacell(db->NewUniqueKey(), sorting_key, formatted_expression[1]);
                    db->InsertKeyValue(&newcell, db);
                    screens::PrintDone();
                }
                else
                {
                    screens::PrintUnknownExpressionScreen(command.member_main_command, argument, expression);
                }
            }
            else if(argument.rfind("--remove", 0) == 0)
            { //"--remove" argument.
                formatted_expression = ArgumentFormatter(&argument, &expression, 2, &valid_expression);

                //Checks for valid expression.
                if (valid_expression)
                {
                    //TODO proceed
                }
                else
                {
                    screens::PrintUnknownExpressionScreen(command.member_main_command, argument, expression);
                }
            }
            else if(argument.rfind("--search", 0) == 0)
            { //"--search" argument.
                formatted_expression = ArgumentFormatter(&argument, &expression, 3, &valid_expression);

                //Checks for valid expression.
                if (valid_expression)
                {
                    //TODO proceed
                }
                else
                {
                    screens::PrintUnknownExpressionScreen(command.member_main_command, argument, expression);
                }
            }
            else if(argument.rfind("--update", 0) == 0)
            { //"--update" argument.
                formatted_expression = ArgumentFormatter(&argument, &expression, 4, &valid_expression);

                //Checks for valid expression.
                if (valid_expression)
                {
                    //TODO proceed
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
                    //TODO proceed
                }
                else
                {
                    //Sets "expression" as everything after the argument and prints the error message.
                    std::string expression = argument.erase(0, 6);
                    screens::PrintUnknownExpressionScreen(command.member_main_command, "--list", expression);
                }
            }
            else if(argument.rfind("--reverse-list", 0) == 0)
            {
                if(argument == "--reverse-list")
                {
                    //TODO proceed
                }
                else
                {
                    //Sets "expression" as everything after the argument and prints the error message.
                    std::string expression = argument.erase(0, 14);
                    screens::PrintUnknownExpressionScreen(command.member_main_command, "--reverse-list", expression);
                }
            }
            else if(argument.rfind("--compress", 0) == 0)
            { //"--compress" argument.
                formatted_expression = ArgumentFormatter(&argument, &expression, 5, &valid_expression);

                //Checks for valid expression.
                if (valid_expression)
                {
                    int type;
                    if(argument == "huffman")
                    {
                        type = 1;
                    }
                    else
                    {
                        type = 2;
                    }

                    bool is_done = db->CompressDatabase(type);
                }
                else
                {
                    screens::PrintUnknownExpressionScreen(command.member_main_command, argument, expression);
                }
            }
            else if(argument.rfind("--decompress", 0) == 0)
            { //"--decompress" argument.
                formatted_expression = ArgumentFormatter(&argument, &expression, 6, &valid_expression);

                //Checks for valid expression.
                if (valid_expression)
                {
                    int type;

                    if(argument == "huffman")
                    {
                        type = 1;
                    }
                    else
                    {
                        type = 2;
                    }

                    bool is_done = db->DecompressDatabase(type);
                }
                else
                {
                    screens::PrintUnknownExpressionScreen(command.member_main_command, argument, expression);
                }
            }
            else
            { //Invalid argument.
                screens::PrintUnknownArgumentScreen(command.member_main_command, argument);
            }
        }
        else
        { //Too mnay arguemnts.
            //Sets "argument" as everything after the main command and prints the error message.
            std::string argument = command.member_unformatted_command;
            argument.erase(0, (command.member_main_command.size()+1));
            screens::PrintUnknownArgumentScreen(command.member_main_command, argument);
        }
    }
    else if(command.member_main_command == "clear")
    { //'clear' command.
        if(command.member_command_size == 1)
        { //Command without arguments.
            screens::ClearScreen();
        }
        else
        { //Inalid argument;
            //Sets "argument" as everything after the main command and prints the error message.
            std::string argument = command.member_unformatted_command;
            argument.erase(0, (command.member_main_command.size()+1));
            screens::PrintUnknownArgumentScreen(command.member_main_command, argument);
        }
    }
    else if(command.member_main_command == "exit")
    { //exit command.
        if(command.member_command_size == 1)
        { //Command without arguments.
            return true;                                                        //Breaks main loop.
        }
        else
        { //Invalid argument.
            //Sets "argument" as everything after the main command and prints the error message.
            std::string argument = command.member_unformatted_command;
            argument.erase(0, (command.member_main_command.size()+1));
            screens::PrintUnknownArgumentScreen(command.member_main_command, argument);
        }
    }
    else
    { //Unknown command.
        screens::PrintUnknownCommandScreen(command.member_main_command);
    }

    return false;                                                               //Continues main loop.
}
//==================================================