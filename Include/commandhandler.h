//Header definition
#ifndef commandhandler_h_
#define commandhandler_h_


//Libraries
#include <string>
#include <vector>


//Dependencies
#include "screens.h"


//=====================Namespace====================
using namespace std;
//==================================================


//======================Classes=====================
class Command
{
    public:
        Command(string user_input);

        string member_unformatted_command;
        vector<string> member_full_command;
        string member_main_command;
        int member_command_size;

    static vector<string> CommandFormatter(string user_input);
};
//==================================================


//=====================Functions====================
namespace cli //Short for "Command Line Interface"
{
    bool ReadCommand(Command command);
};
//==================================================


#endif