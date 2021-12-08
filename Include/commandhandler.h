//Header definition
#ifndef commandhandler_h_
#define commandhandler_h_


//Libraries
#include <string>


//Dependencies
#include "screens.h"


//=====================Namespace====================
using namespace std;
//==================================================


//=====================Functions====================
namespace cli //Short for "Command Line Interface"
{
    bool ReadCommand(string user_input);
};
//==================================================


#endif