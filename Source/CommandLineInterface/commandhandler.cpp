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
#include "index.h"
#include "datacell.h"


//Local Reference
Database cli_db_reference("null", "null", Index::CreateIndex("null"));          //Local reference a database.


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
{ //Formats user input string by separating it at every whitespace and storing in a string vector.
    std::vector<std::string> formatted_command;

    if(user_input.empty() || (user_input.rfind(" ", 0) == 0))
    { //Returns a "null" string if user_input is blank or starts with a blank space.
        formatted_command.push_back("null");                                    //Sets the first string of the formatted command string vector as "null".
        return formatted_command;
    }

    //String formation.
    std::istringstream ss(user_input);
    std::string temp;
    while(ss >> temp)
    {
        formatted_command.push_back(temp);                                      //Stores resultant string into the formatted command string vector.
    }

    return formatted_command;
}
//==================================================


//===============Expression Formatter===============
bool ExpressionFormatter(std::string expression, std::vector<std::string>* formatted_expression)
{ //Formats raw expression string by separating it at every comma and storing in a string vector, returns true if the expression if valid and false if it is invalid.
//Slave function to "ExpressionVerifier".
    bool is_valid = true;

    std::stringstream  ss(expression);
    while (ss.good())
    { //Splits expression string at every comma.
        std::string temp;
        getline(ss, temp, ',');
        
        if(!temp.empty())
        { //Stores "temp" into the current positon of the vector if it is not empty.
            formatted_expression->push_back(temp);                              //Stores resultant string into the formatted expression string vector.
        }
        else
        { //Insert a "null" into the current vector position if there is no data between commas.
            is_valid = false;                                                   //Flags the expression as invalid.
            formatted_expression->push_back("null");                            //Sets the first string of the formatted expression string vector as "null".
        }
    }

    return is_valid;                                                            //Will return true by default if this fuction does not flag as a invalid expression at any point.
}
//==================================================


//================Expression Verifier===============
std::vector<std::string> ExpressionVerifier(std::string* expression, int* type, bool* valid_flag)
{ //Analyzes the expression and return a string vector with the formatted expression parameters if it is valid.
//Slave function to "ArgumentFormmatter".
    std::vector<std::string> formatted_expression;

    if(expression->rfind("=", 0) == 0 && expression->size() > 1)
    { //Initial check, confirms if the expression is formatted correctly for any argument implemented and has enough characters.
        expression->erase(0, 1);                                                //Removes "=" from "expression" string.

        switch(*type)
        { //Third check, confirm if value types are correct and has enough parametes for it's respective argument.
            /*
            Type 1 = expression for '--insert' argument.
            Type 2 = expression for '--remove' and '--search' argument.
            Type 3 = expression for '--update' argument.
            Type 4 = expression for '--list' and '--reverse-list' arguments.
            Type 5 = expression for '--compress' and '--decompress' arguments.
            */
            case 1:
                if((*expression)[0] == '<' && (*expression)[expression->length()-1] == '>')
                { //Checks if expression is formatted correctly for type 1.
                    expression->erase(0, 1); expression->pop_back();            //Removes "<>" from expression;

                    //Confirms if expression has enough parameters for type 1.
                    *valid_flag = ExpressionFormatter(*expression, &formatted_expression);

                    if(formatted_expression.size() != 2)
                    { //Does not have the right amount of parameters for type 1.
                        *valid_flag = false;                                    //Sets valid expression flag to invalid.
                        break;
                    }
                    else
                    { //Confirm if the value types of the parameters are correct for type 1.
                        //Confirms if the first parameter is a positive integer.
                        if(formatted_expression[0].find_first_not_of("0123456789") == std::string::npos)
                        { //Confirms if the first parameter is a positive integer.
                            //Convert first parameter into a integer variable.
                            int parameter_scan = std::stoi(formatted_expression[0]);

                            if(parameter_scan <= 0)
                            { //First parameter is an integer but it's value is not higher than 0.
                                *valid_flag = false;                            //Sets valid expression flag to invalid.
                                break;
                            }
                        }
                        else
                        { //First parameter is not an integer.
                            *valid_flag = false;                                //Sets valid expression flag to invalid.
                            break;
                        }
                        //? Second parameter can be any value.
                    }
                }
                else
                { //Expression is not formatted correctly.
                    formatted_expression.push_back("notformatted");             //Sets the first string of the formatted expression string vector as "notformatted".
                    *valid_flag = false;                                        //Sets valid expression flag to invalid.
                    break;
                }
            break;

            case 2:
                if((*expression)[0] == '<' && (*expression)[expression->length()-1] == '>')
                { //Checks if expression is formatted correctly for type 2.
                    expression->erase(0, 1); expression->pop_back();        //Removes "<>" from expression;

                    //Confirms if expression has enough parameters for type 2.
                    *valid_flag = ExpressionFormatter(*expression, &formatted_expression);

                    if(formatted_expression.size() != 1)
                    { //Does not have the right amount of parameters for type 2.
                        *valid_flag = false;                                    //Sets valid expression flag to invalid.
                        break;
                    }
                    else
                    { //Confirm if the value types of the parameters are correct for type 1.
                        std::string temp = formatted_expression[0];
                        temp.erase(0,4);

                        //Confirms if the parameter is in the "key_*integer*" format.
                        if(temp.empty())
                        { //The parameter does not have enough characters to be valid.
                            *valid_flag = false;                                //Sets valid expression flag to invalid.
                            break;
                        }
                        else if(temp.find_first_not_of("0123456789") == std::string::npos && formatted_expression[0].rfind("key_", 0) == 0)
                        { //Confirms if the parameter is in the right format.
                            //Converts parameter into an integer variable.
                            int parameter_scan = std::stoi(temp);

                            if(parameter_scan <= 0)
                            { //The parameter is formatted correctly but its value is invalid.
                                *valid_flag = false;                            //Sets valid expression flag to invalid.
                                break;
                            }
                        }
                        else
                        { //The parameter is not int the "key_*integer*" format.
                            *valid_flag = false;                                //Sets valid expression flag to invalid.
                            break;
                        }
                    }
                }
                else
                { //Expression is not formatted correctly.
                    formatted_expression.push_back("notformatted");             //Sets the first string of the formatted expression string vector as "notformatted".
                    *valid_flag = false;                                        //Sets valid expression flag to invalid.
                    break;
                }
            break;
            
            case 3:
                if((*expression)[0] == '<' && (*expression)[expression->length()-1] == '>')
                { //Checks if expression is formatted correctly for type 3.
                    expression->erase(0, 1); expression->pop_back();            //Removes "<>" from expression;

                    //Confirms if expression has enough parameters for type 3.
                    *valid_flag = ExpressionFormatter(*expression, &formatted_expression);
                    if(formatted_expression.size() != 3)
                    { //Does not have the right amount of parameters for type 3.
                        *valid_flag = false;                                    //Sets valid expression flag to invalid.
                        break;
                    }
                    else
                    { //Confirm if the value types of the parameters are correct for type 3.
                        std::string temp = formatted_expression[0];
                        temp.erase(0,4);

                        //Confirms if the first parameter is in the "key_*integer*" format.
                        if(temp.empty())
                        { //The parameter does not have enough characters to be valid.
                            *valid_flag = false;                            //Sets valid expression flag to invalid.
                            break;
                        }
                        else if(temp.find_first_not_of("0123456789") == std::string::npos && formatted_expression[0].rfind("key_", 0) == 0)
                        { //Confirms if the parameter is in the right format.
                            //Converts parameter into a integer variable.
                            int parameter_scan = std::stoi(temp);

                            if(parameter_scan <= 0)
                            { //The parameter is formatted correctly but it's value is invalid.
                                *valid_flag = false;                        //Sets valid expression flag to invalid.
                                break;
                            }

                            //Confirms if the second parameter is a non-nule integer.
                            if(formatted_expression[1].find_first_not_of("0123456789") != std::string::npos)
                            { //The second parameter is not an integer.
                                *valid_flag = false;                        //Sets valid expression flag to invalid.
                                break;
                            }
                        }
                        else
                        { //First parameter is not int the "key_*integer*" format.
                            *valid_flag = false;                            //Sets valid expression flag to invalid.
                            break;
                        }
                        //? The third parameter can be any value.
                    }
                }
                else
                { //Expression is not formatted correctly.
                    formatted_expression.push_back("notformatted");         //Sets the first string of the formatted expression string vector as "notformatted".
                    *valid_flag = false;                                    //Sets valid expression flag to invalid.
                }
            break;

            case 4:
                if((*expression)[0] == '<' && (*expression)[expression->length()-1] == '>')
                { //Checks if expression is formatted correctly for type 4.
                    expression->erase(0, 1); expression->pop_back();            //Removes "<>" from expression;

                    //Confirms if expression has enough parameters for type 4.
                    *valid_flag = ExpressionFormatter(*expression, &formatted_expression);
                    if(formatted_expression.size() != 1)
                    { //Does not have the right amount of parameters for type 4.
                        *valid_flag = false;                                    //Sets valid expression flag to invalid.
                        break;
                    }
                    else
                    { //Confirm if the value types of the parameters are correct for type 4.
                        if(formatted_expression[0].rfind("key", 0) == 0 && formatted_expression[0].size() > 4)
                        { //Checks if expression starts with valid characters.
                            formatted_expression[0].erase(0, 3);

                            bool valid_operator = false;
                            char main_operator = ((formatted_expression[0])[0]);
                            char optional_operator = ((formatted_expression[0])[1]);

                            //Operator checker
                            if(main_operator == '=')
                            { //Operator is "=".
                                formatted_expression[0].erase(0, 1);
                                formatted_expression.push_back(formatted_expression[0]);
                                formatted_expression[0] = "=";
                                valid_operator = true;
                            }
                            else if(main_operator == '>' && optional_operator != '=')
                            { //Operator is ">".
                                formatted_expression[0].erase(0, 1);
                                formatted_expression.push_back(formatted_expression[0]);
                                formatted_expression[0] = ">";
                                valid_operator = true;
                            }
                            else if(main_operator == '<' && optional_operator != '=')
                            { //Operator is "<".
                                formatted_expression[0].erase(0, 1);
                                formatted_expression.push_back(formatted_expression[0]);
                                formatted_expression[0] = "<";
                                valid_operator = true;
                            }
                            else if(main_operator == '>' && optional_operator == '=')
                            { //Operator is ">=".
                                formatted_expression[0].erase(0, 2);
                                formatted_expression.push_back(formatted_expression[0]);
                                formatted_expression[0] = ">=";
                                valid_operator = true;
                            }
                            else if(main_operator == '<' && optional_operator == '=')
                            { //Operator is "<=".
                                formatted_expression[0].erase(0, 2);
                                formatted_expression.push_back(formatted_expression[0]);
                                formatted_expression[0] = "<=";
                                valid_operator = true;
                            }
                            else
                            { //Expression does not have a valid operator.
                                //Undoes expression formattion attempt.
                                formatted_expression.clear();
                                formatted_expression.push_back(*expression);
                                *valid_flag = false;                            //Sets valid expression flag to invalid.
                                break;
                            }

                            //Checks if last parameter is a non nule integer.
                            if(formatted_expression[1].find_first_not_of("0123456789") == std::string::npos)
                            { //Last parameter is an integer.
                                int temp = std::stoi(formatted_expression[1]);

                                //Checks if last parameter is higher than 0;
                                if(temp <= 0)
                                { //Last parameter is an integer but is not higher than 0;
                                    //Undoes expression formattion attempt.
                                    formatted_expression.clear();
                                    formatted_expression.push_back(*expression);
                                    *valid_flag = false;                        //Sets valid expression flag to invalid.
                                    break;
                                }
                            }
                            break;
                        }
                        else if(formatted_expression.size() == 0)
                        { //Expression is blank, sets formatted expression first member with a "null" string.
                            *expression = "null";
                            formatted_expression.push_back(*expression);
                            *valid_flag = false;                                //Sets valid expression flag to invalid.
                            break;
                        }
                        else
                        { //Expression is not formatted correctly for type 4.
                            *valid_flag = false;                                //Sets valid expression flag to invalid.
                            break;
                        }
                    }
                }
                else
                { //Expression is not formatted correctly.
                    formatted_expression.push_back("notformatted");             //Sets the first string of the formatted expression string vector as "notformatted".
                    *valid_flag = false;                                        //Sets valid expression flag to invalid.
                    break;
                }
            break;

            case 5:
                formatted_expression.push_back(*expression);                    //Inserts expression into formatted expression string vector.

                //Checks if expression is formatted correctly for type 5.
                if(*expression == "huffman" || *expression == "lzw")
                { //Expresion is valid for type 5.
                    *valid_flag = true;                                     //Sets valid expression flag to valid.
                    break;
                }
                else
                { //Expresion is not valid for type 5.
                    *valid_flag = false;                                    //Sets valid expression flag to invalid.
                    break;
                }
            break;
        }
    }
    else if(expression->empty())
    { //Expression is blank, sets formatted expression first member with a "null" string.
        *expression = "null";
        formatted_expression.push_back(*expression);                            //Sets the first string of the formatted expression string vector as "null".
        *valid_flag = false;                                                    //Sets valid expression flag to invalid.
    }
    else
    { //Expression is not blank but is not formatted correctly. 
        formatted_expression.push_back("notformatted");                         //Sets the first string of the formatted expression string vector as "notformatted".
        *valid_flag = false;                                                    //Sets valid expression flag to invalid.
    }

    return formatted_expression;
}
//==================================================


//================Argument Formatter================
std::vector<std::string> ArgumentFormatter(std::string* argument, std::string* expression, int type, bool* valid_flag)
{ //Separates argument from expression and returns formatted expression.
    /*
    Type 1 = '--insert' argument.
    Type 2 = '--remove' argument.
    Type 3 = '--search' argument.
    Type 4 = '--update' argument.
    Type 5 = '--list' argument.
    Type 6 = '--reverse-list' argument.
    Type 7 = '--compress' argument.
    Type 8 = '--decompress' argument.
    */
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
            type = 2;                                                           //Redefines type for expression verifier.
        break;

        case 4:
            *expression = argument->erase(0, 8);
            *argument = "--update";
            type  = 3;                                                          //Redefines type for expression verifier.
        break;
        
        case 5:
            *expression = argument->erase(0, 6);
            *argument = "--list";
            type = 4;                                                           //Redefines type for expression verifier.
        break;

        case 6:
            *expression = argument->erase(0, 14);
            *argument = "--reverse-list";
            type = 4;                                                           //Redefines type for expression verifier.
        break;

        case 7:
            *expression = argument->erase(0, 10);
            *argument = "--compress";
            type = 5;                                                           //Redefines type for expression verifier.
        break;

        case 8:
            *expression = argument->erase(0, 12);
            *argument = "--decompress";
            type = 5;                                                           //Redefines type for expression verifier.
        break;
    }

    return ExpressionVerifier(expression, &type, valid_flag);
}
//==================================================


//=================Command Processor================
bool cli::ReadCommand(cli::Command command, Database* db)
{ //Reads raw input data from user as a command and calls for related functions.
    cli_db_reference = *db;                                                     //Defines local database reference.

    if(command.member_command_size == 1 && command.member_main_command == "null")
    { //Ends the command reading if user input is blank.
        return false;
    }

    //Command recognition.
    if(command.member_main_command == "help")
    { //'help' command.
        if(command.member_command_size == 1)
        { //'help' command without arguments.
            std::string argument = "null";
            screens::PrintHelpScreen(&argument, 1);
        }
        else if(command.member_command_size == 2)
        { //'help' command has a valid number of arguments.
            if(command.member_full_command[1] == "help")
            { //'help help' command.
                screens::PrintHelpScreen(&(command.member_full_command[1]), 2);
            }
            else if(command.member_full_command[1] == "simpledb")
            { //'help simpledb' command.
                screens::PrintHelpScreen(&(command.member_full_command[1]), 3);
            }
            else if(command.member_full_command[1] == "clear")
            { //'help clear' command.
                screens::PrintHelpScreen(&(command.member_full_command[1]), 4);
            }
            else if(command.member_full_command[1] == "exit")
            { //'help exit' command.
                screens::PrintHelpScreen(&(command.member_full_command[1]), 5);
            }
            else
            { //Unrecognized argument for 'help' command.
                screens::PrintHelpScreen(&(command.member_full_command[1]), 6);
            }
        }
        else
        { //Too many arguments for 'help' command.
            //Sets "argument" as everything after the main command and prints the error message.
            std::string argument = command.member_unformatted_command;
            argument.erase(0, (command.member_main_command.size()+1));
            screens::PrintArgumentErrorScreen(&(command.member_main_command), &argument, 3);
        }
    }
    else if(command.member_main_command == "simpledb")
    { //'simpledb' command.
        if(command.member_command_size == 1)
        { //Insufficient arguments for 'simpledb' command.
            std::string argument = "null";
            screens::PrintArgumentErrorScreen(&(command.member_main_command), &argument, 2);
        }
        else if(command.member_command_size == 2)
        { //'simpledb' command has a valid number of arguments.
            std::string argument = command.member_full_command[1];              //Sets the second member of the full command vector as the argument.
            std::vector<std::string> formatted_expression;                      //Stores the formatted parameters of the expression.
            std::string expression;                                             //Stores the unformatted raw expression.
            bool valid_expression = false;                                      //Flag for checking if the expression is valid, is false by default.

            if(argument.rfind("--insert", 0) == 0)
            { //"--insert" argument.
                //Formats the third member of the command vector as an expression and saves to a previosuly created expression vector.
                formatted_expression = ArgumentFormatter(&argument, &expression, 1, &valid_expression);

                //Checks if expression is valid for "--insert" (has enough and parameters and the right value types).
                if(valid_expression)
                { //Expression is valid for "--insert".
                    int sorting_key = std::stoi(formatted_expression[0]);       //Converts first member of the formatted expression vector to an integer.

                    //Creates Datacell with the values extracted from the expression vector.
                    Datacell newcell = Datacell::CreateDatacell(db->NewUniqueKey(), sorting_key, formatted_expression[1]);
                    db->InsertKeyValue(&newcell);                               //Inserts datacell to database file.

                    screens::PrintDatacell(nullptr, &newcell, 1);               //Confirms insertion in terminal.      
                }
                else
                { //Expression is not valid for "--insert".
                    //Checks what error message needs to be displayed.
                    int type = 1;

                    if(formatted_expression[0] != "notformatted")
                    {
                        if(formatted_expression[0] == "null")
                        { //Missing expression.
                            type++;
                        }
                        else if(formatted_expression.size() < 2)
                        { //Expression has not enough parameters.
                            type = 3;
                        }
                        else if(formatted_expression.size() > 2)
                        { //Expression has more than enough parameters.
                            type = 4;
                        }
                    }

                    //Will call for the generic error message (type 1) if none of the above are true.
                    screens::PrintExpressionErrorScreen(&(command.member_main_command), &argument, &expression, type);
                }
            }
            else if(argument.rfind("--remove", 0) == 0)
            { //"--remove" argument.
                //Formats the third member of the command vector as an expression and saves to a previously created expression vector.
                formatted_expression = ArgumentFormatter(&argument, &expression, 3, &valid_expression);

                //Checks if expression is valid for "--remove" (has enough and parameters and the right value types).
                if(valid_expression)
                { //Expression is valid for "--remove".
                    //Creates Datacell with the key value extracted from the expression vector.
                    Datacell existingcell = Datacell::CreateDatacell(formatted_expression[0], 0, "null");

                    //Completes the Datacell with data from the database file.
                    bool is_successful = dbh::RemoveDBKey(db, &existingcell);

                    //Checks if search was successful.
                    if(is_successful)
                    { //Search was successful, prints value to terminal.
                        screens::PrintDatacell(nullptr, &existingcell, 3);      //Prints successful search to terminal. 
                    }
                    else
                    { //Search was not successful, prints invalid key error.
                        screens::PrintInvalidKeyScreen(&(formatted_expression[0]));
                    }
                }
                else
                { //Expression is not valid for "--search".
                    //Checks what error message needs to be displayed.
                    int type = 1;

                    if(formatted_expression.back() != "notformatted")
                    {
                        if(formatted_expression[0] == "null")
                        { //Missing expression.
                            type = 2;
                        }
                        else if(formatted_expression.size() > 1)
                        { //Expression has more than enough parameters.
                            type = 4;
                        }
                    }

                    //Will call for the generic error message (type 1) if none of the above are true.
                    screens::PrintExpressionErrorScreen(&(command.member_main_command), &argument, &expression, type);
                }
            }
            else if(argument.rfind("--search", 0) == 0)
            { //"--search" argument.
                //Formats the third member of the command vector as an expression and saves to a previously created expression vector.
                formatted_expression = ArgumentFormatter(&argument, &expression, 3, &valid_expression);

                //Checks if expression is valid for "--search (has enough and parameters and the right value types).
                if(valid_expression)
                { //Expression is valid for "--search".
                    //Creates Datacell with the key value extracted from the expression vector.
                    Datacell existingcell = Datacell::CreateDatacell(formatted_expression[0], 0, "null");

                    //Completes the Datacell with data from the database file.
                    bool is_successful = db->SearchKeyValue(&existingcell);

                    //Checks if search was successful.
                    if(is_successful)
                    { //Search was successful, prints value to terminal.
                        screens::PrintDatacell(nullptr, &existingcell, 2);      //Prints successful search to terminal. 
                    }
                    else
                    { //Search was not successful, prints invalid key error.
                        screens::PrintInvalidKeyScreen(&(formatted_expression[0]));
                    }
                }
                else
                { //Expression is not valid for "--search".
                    //Checks what error message needs to be displayed.
                    int type = 1;

                    if(formatted_expression.back() != "notformatted")
                    {
                        if(formatted_expression[0] == "null")
                        { //Missing expression.
                            type = 2;
                        }
                        else if(formatted_expression.size() > 1)
                        { //Expression has more than enough parameters.
                            type = 4;
                        }
                    }

                    //Will call for the generic error message (type 1) if none of the above are true.
                    screens::PrintExpressionErrorScreen(&(command.member_main_command), &argument, &expression, type);
                }
            }
            else if(argument.rfind("--update", 0) == 0)
            { //"--update" argument.
                //Formats the third member of the command vector as an expression and saves to a previously created expression vector.
                formatted_expression = ArgumentFormatter(&argument, &expression, 4, &valid_expression);

                //Checks if expression is valid for "--update (has enough and parameters and the right value types).
                if(valid_expression)
                { //Expression is valid for "--update".
                    //Creates Datacell with the key value extracted from the expression vector and a partially blank datacell with the same key.
                    Datacell newcell = Datacell::CreateDatacell(formatted_expression[0], std::stoi(formatted_expression[1]), formatted_expression[2]);
                    Datacell oldcell = Datacell::CreateDatacell(formatted_expression[0], 0, "null");

                    bool is_successful = db->SearchKeyValue(&oldcell);          //Gets value from updated datacell before update.

                    //Updates key from database file with datacell data if the key search was successful.
                    if(is_successful)
                    {
                        is_successful = dbh::UpdateDBKey(db, &oldcell, &newcell);
                    }

                    //Checks if update was successful.
                    if(is_successful)
                    { //Update was successful, prints values to terminal.
                        screens::PrintDatacell(&oldcell, &newcell, 4);          //Prints successful update to terminal. 
                    }
                    else
                    { //Update was not successful, prints invalid key error.
                        screens::PrintInvalidKeyScreen(&(formatted_expression[0]));
                    }
                }
                else
                { //Expression is not valid for "--update".
                    //Checks what error message needs to be displayed.
                    int type = 1;

                    if(formatted_expression.back() != "notformatted")
                    {
                        if(formatted_expression[0] == "null")
                        { //Missing expression.
                            type = 2;
                        }
                        else if(formatted_expression.size() < 3)
                        { //Expression has not enough parameters.
                            type = 3;
                        }
                        else if(formatted_expression.size() > 3)
                        { //Expression has more than enough parameters.
                            type = 4;
                        }
                    }

                    //Will call for the generic error message (type 1) if none of the above are true.
                    screens::PrintExpressionErrorScreen(&(command.member_main_command), &argument, &expression, type);
                }
            }
            else if(argument.rfind("--list", 0) == 0)
            { //"--list" argument.
                //Formats the third member of the command vector as an expression and saves to a previously created expression vector.
                formatted_expression = ArgumentFormatter(&argument, &expression, 5, &valid_expression);

                //Checks if expression is valid for "--list" (has enough and parameters and the right value types).
                if(valid_expression)
                { //Expression is valid for "--list".
                    int type;

                    if(formatted_expression[0] == "=")
                    {
                        type = 1;
                    }
                    else if(formatted_expression[0] == ">")
                    {
                        type = 2;
                    }
                    else if(formatted_expression[0] == "<")
                    {
                        type = 3;
                    }
                    else if(formatted_expression[0] == ">=")
                    {
                        type = 4;
                    }
                    else if(formatted_expression[0] == "<=")
                    {
                        type = 5;
                    }

                    screens::LogToScreen("Lista para (chave de ordena????o " + formatted_expression[0] + " " + formatted_expression[1] + "):");
                    bool printed = dbh::PrintList(db, std::stoi(formatted_expression[1]), 1, type);

                    //Checks if any datacell was printed to screen,
                    if(!printed)
                    { //No datacell was printed, printd default message to screen.
                        screens::LogToScreen("Nenhuma chave encontada para a express??o informada!");
                    } 
                }
                else
                { //Expression is not valid for "--list".
                    //Checks what error message needs to be displayed.
                    int type = 1;

                    if(formatted_expression.back() != "notformatted")
                    {
                        if(formatted_expression[0] == "null")
                        { //Missing expression.
                            type++;
                        }
                        else if(formatted_expression.size() > 1)
                        { //Expression has more than enough parameters.
                            type = 4;
                        }
                    }

                    //Will call for the generic error message (type 1) if none of the above are true.
                    screens::PrintExpressionErrorScreen(&(command.member_main_command), &argument, &expression, type);
                }
            }
            else if(argument.rfind("--reverse-list", 0) == 0)
            { //"--reverse-list" argument.
                //Formats the third member of the command vector as an expression and saves to a previously created expression vector.
                formatted_expression = ArgumentFormatter(&argument, &expression, 6, &valid_expression);

                //Checks if expression is valid for "--reverse-list" (has enough and parameters and the right value types).
                if(valid_expression)
                { //Expression is valid for "--reverse-list".
                    int type;

                    if(formatted_expression[0] == "=")
                    {
                        type = 1;
                    }
                    else if(formatted_expression[0] == ">")
                    {
                        type = 2;
                    }
                    else if(formatted_expression[0] == "<")
                    {
                        type = 3;
                    }
                    else if(formatted_expression[0] == ">=")
                    {
                        type = 4;
                    }
                    else if(formatted_expression[0] == "<=")
                    {
                        type = 5;
                    }

                    screens::LogToScreen("Lista reversa para (chave de ordena????o " + formatted_expression[0] + " " + formatted_expression[1] + "):");
                    bool printed = dbh::PrintList(db, std::stoi(formatted_expression[1]), 2, type);

                    //Checks if any datacell was printed to screen,
                    if(!printed)
                    { //No datacell was printed, printd default message to screen.
                        screens::LogToScreen("Nenhuma chave encontada para a express??o informada!");
                    }
                    
                }
                else
                { //Expression is not valid for "--reverse-list".
                    //Checks what error message needs to be displayed.
                    int type = 1;

                    if(formatted_expression.back() != "notformatted")
                    {
                        if(formatted_expression[0] == "null")
                        { //Missing expression.
                            type++;
                        }
                        else if(formatted_expression.size() > 1)
                        { //Expression has more than enough parameters.
                            type = 4;
                        }
                    }

                    //Will call for the generic error message (type 1) if none of the above are true.
                    screens::PrintExpressionErrorScreen(&(command.member_main_command), &argument, &expression, type);
                }
            }
            else if(argument.rfind("--compress", 0) == 0)
            { //"--compress" argument.
                //Formats the third member of the command vector as an expression and saves to a previously created expression vector.
                formatted_expression = ArgumentFormatter(&argument, &expression, 7, &valid_expression);

                //Checks if expression is valid for "--compress" (has enough and parameters and the right value types).
                if(valid_expression)
                { //Expression is valid for "--compress".
                    //TODO
                }
                else
                { //Expression is not valid for "--compress".
                    //Checks what error message needs to be displayed.
                    int type = 1;

                    if(formatted_expression.back() != "notformatted")
                    {
                        if(formatted_expression[0] == "null")
                        { //Missing expression.
                            type = 2;
                        }
                        else if(formatted_expression.size() > 1)
                        { //Expression has more than enough parameters.
                            type = 4;
                        }
                    }

                    //Will call for the generic error message (type 1) if none of the above are true.
                    screens::PrintExpressionErrorScreen(&(command.member_main_command), &argument, &expression, type);
                }
            }
            else if(argument.rfind("--decompress", 0) == 0)
            { //"--decompress" argument.
                //Formats the third member of the command vector as an expression and saves to a previously created expression vector.
                formatted_expression = ArgumentFormatter(&argument, &expression, 8, &valid_expression);

                //Checks if expression is valid for "--decompress" (has enough and parameters and the right value types).
                if(valid_expression)
                { //Expression is valid for "--decompress"".
                    //TODO
                }
                else
                { //Expression is not valid for "--decompress".
                    //Checks what error message needs to be displayed.
                    int type = 1;

                    if(formatted_expression.back() != "notformatted")
                    {
                        if(formatted_expression[0] == "null")
                        { //Missing expression.
                            type = 2;
                        }
                        else if(formatted_expression.size() > 1)
                        { //Expression has more than enough parameters.
                            type = 4;
                        }
                    }

                    //Will call for the generic error message (type 1) if none of the above are true.
                    screens::PrintExpressionErrorScreen(&(command.member_main_command), &argument, &expression, type);
                }
            }
            else
            { //Unrecognized argument for 'simpledb' command.
                screens::PrintArgumentErrorScreen(&(command.member_main_command), &argument, 1);
            }
        }
        else
        { //Too many arguments for 'simpledb' command.
            //Sets "argument" as everything after the main command and prints the error message.
            std::string argument = command.member_unformatted_command;
            argument.erase(0, (command.member_main_command.size()+1));
            screens::PrintArgumentErrorScreen(&(command.member_main_command), &argument, 3);
        }
    }
    else if(command.member_main_command == "clear")
    { //'clear' command.
        if(command.member_command_size == 1)
        { //'clear' command without arguments.
            screens::ClearScreen();
        }
        else
        { //Too many arguments for 'clear' command.
            //Sets "argument" as everything after the main command and prints the error message.
            std::string argument = command.member_unformatted_command;
            argument.erase(0, (command.member_main_command.size()+1));
            screens::PrintArgumentErrorScreen(&(command.member_main_command), &argument, 4);
        }
    }
    else if(command.member_main_command == "exit")
    { //'exit' command.
        if(command.member_command_size == 1)
        { //'exit' command without arguments.
            return true;                                                        //Breaks the main loop.
        }
        else
        { //Too many arguments for 'exit' command.
            //Sets "argument" as everything after the main command and prints the error message.
            std::string argument = command.member_unformatted_command;
            argument.erase(0, (command.member_main_command.size()+1));
            screens::PrintArgumentErrorScreen(&(command.member_main_command), &argument, 4);
        }
    }
    else
    { //Unknown command.
        screens::PrintUnknownCommandScreen(&(command.member_main_command));
    }

    return false;                                                               //Continues main loop.
}
//==================================================