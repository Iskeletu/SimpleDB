#ifndef screens_h_
#define screens_h_


//==========Namespace==========
using namespace std;
//=============================


//==========Functions==========
void PrintStartupScreen();
void PrintDefaultScreen();
void PrintHelpScreen();
void PrintArgumentHelp(string argument);
void PrintInvalidHelp(string command);
void PrintUnknownCommandScreen(string command);
//=============================


#endif