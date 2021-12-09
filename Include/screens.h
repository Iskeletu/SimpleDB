//Header definition
#ifndef screens_h_
#define screens_h_


//Libraries
#include <string>


//=====================Functions====================
namespace screens
{
    //CLI Functions
    void    PrintStartupScreen                  (void);
    void    PrintDefaultScreen                  (void);
    void    PrintDone                           (void);
    void    PrintHelpScreen                     (void);
    void    PrintArgumentHelpScreen             (std::string argument);
    void    PrintInvalidHelpScreen              (std::string command);
    void    PrintUnknownCommandScreen           (std::string command);
    void    PrintUnknownArgumentScreen          (std::string command, std::string argument);
    void    PrintInsufficientArgumentScreen     (std::string command);
    void    PrintUnknownExpressionScreen        (std::string command, std::string argument, std::string expression);
    void    ClearScreen                         (void);

    //Database Functions
    void    PrintKeyValue                       (std::string key, std::string value);
};
//==================================================


#endif