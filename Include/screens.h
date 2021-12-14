//Header definition
#ifndef screens_h_
#define screens_h_


//Libraries
#include <string>


//Dependencies
#include "datacell.h"


//=====================Functions====================
namespace screens
{
    //CLI Related Functions
    void    PrintStartupScreen              (void);
    void    PrintDefaultScreen              (void);
    void    PrintUnknownCommandScreen       (std::string* command);
    void    PrintHelpScreen                 (std::string* argument, int type);
    void    PrintArgumentErrorScreen        (std::string* command, std::string* argument, int type);
    void    PrintExpressionErrorScreen      (std::string* command, std::string* argument, std::string* expression, int type);
    void    PrintDone                       (void);
    void    LogToScreen                     (std::string PrintString);
    void    ClearScreen                     (void);

    //Database Related Functions
    void    PrintDatacell                   (Datacell* oldcell, Datacell* existingcell, int type);
    void    PrintInvalidKeyScreen           (std::string* key);
};
//==================================================


#endif