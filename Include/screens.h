//Header definition
#ifndef screens_h_
#define screens_h_


//Libraries
#include <string>


//=====================Namespace====================
using namespace std;
//==================================================


//=====================Functions====================
namespace screens
{
    void PrintStartupScreen(void);
    void PrintDefaultScreen(void);
    void PrintHelpScreen(void);
    void PrintArgumentHelpScreen(string argument);
    void PrintInvalidHelpScreen(string command);
    void PrintUnknownCommandScreen(string command);
    void PrintUnknownArgumentScreen(string command, string argument);
    void PrintInsufficientArgumentScreen(string command);
    void PrintUnknownExpressionScreen(string command, string argument, string expression);
    void ClearScreen(void);
};
//==================================================


#endif