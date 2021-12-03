//Header definition
#ifndef screens_h_
#define screens_h_


//==========Namespace==========
using namespace std;
//=============================


//==========Functions==========
void PrintStartupScreen();
void PrintDefaultScreen();
void PrintHelpScreen();
void PrintArgumentHelpScreen(string argument);
void PrintInvalidHelpScreen(string command);
void PrintUnknownCommandScreen(string command);
void PrintUnknownArgumentScreen(string command, string argument);
void PrintInsufficientArgumentScreen(string command);
void PrintUnknownArgumentScreen(string command, string argument, string expression);
void ClearScreen();
//=============================


#endif