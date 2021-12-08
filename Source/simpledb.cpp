/*
Main file.
Mainly calls for functions from other files and provides raw user input.
*/


//Libraries
#include <iostream>
#include <string>


//Header Files
#include "commandhandler.h"


//=====================Namespace====================
using namespace std;
using namespace screens;
using namespace cli;
//==================================================


//===================Main Function==================
int main()
{
    //Variable definition.
    string input; //Raw user input.
    bool exit_flag = false; //Main loop exit flag.


    //=================SimpleDB Startup=================
    PrintStartupScreen();
    cout<<"Carregando database..."<<endl;

    

    cout<<"Pressione a tecla enter para proseguir!"<<endl;
    getchar(); system("clear");
    PrintDefaultScreen();
    //==================================================


    //=====================Main loop====================
    while(!exit_flag)
    {
        cout<<"SimpleDB Terminal > "; //Deafult text.
        getline(cin, input); //Reads user input.

        exit_flag = ReadCommand(input); //Checks for exit flag.
    }
    //==================================================


    //TODO save and exit sequence


    return 0;
}
//==================================================