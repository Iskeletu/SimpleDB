//Header definition
#ifndef commandhandler_h_
#define commandhandler_h_


//Libraries
#include <string>
#include <vector>


//Dependencies
#include "dbhandler.h"


//======================Classes=====================
class Command
{
    public:
        Command(std::string user_input);

        static std::vector<std::string>     CommandFormatter    (std::string user_input);

        std::string member_unformatted_command;
        std::vector<std::string> member_full_command;
        std::string member_main_command;
        int member_command_size;
};
//==================================================


//=====================Functions====================
namespace cli
{ //Short for "Command Line Interface".
    bool                                    ReadCommand         (Command command, Database* db);
};
//==================================================


#endif