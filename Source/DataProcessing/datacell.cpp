/*
Datacell management file.

This file is resposible for Datacell management.
Datacell is a structure that contais organised
data for easier insertion in the database.

screens.cpp is dependant on this file.
index.cpp is dependant on this file.
database.cpp is dependant on this file.
*/


//Libraries
#include <string>


//Header Files
#include "datacell.h"


//====================Constructor===================
Datacell::Datacell(std::string key, int sorting_key, std::string value) :
    member_key(key),
    member_sorting_key(sorting_key),
    member_value(value)
{;}
//==================================================


//=================Datacell Creator=================
Datacell Datacell::CreateDatacell(std::string key, int sorting_key, std::string value)
{
    return Datacell(key, sorting_key, value);
}
//==================================================


//=================Get Key Function=================
std::string Datacell::GetKey()
{ //Returns datacell key.
    return member_key;
}
//==================================================


//=============Get Sorting Key Function=============
int Datacell::GetSortingKey()
{ //Returns datacell sorting key.
    return member_sorting_key;
}
//==================================================


//=================Get Value Fuction================
std::string Datacell::GetValue()
{ //Returns value stored in the datacell.
    return member_value;
}
//==================================================


//==============Update Values Function==============
void Datacell::UpdateValues(std::string key, int sorting_key, std::string value)
{
    member_key = key;
    member_sorting_key = sorting_key;
    member_value = value;
}
//==================================================