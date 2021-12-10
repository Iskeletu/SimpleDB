/*
SimpleDB lib.

Intermediary between the functions of the
database and the rest of the program.

Command line interface is dependant on this file.
*/


//Libraries
#include <string>


//Header Files
#include "dbhandler.h"


//====================Constructor===================
SimpleDB::SimpleDB()
{;}
//==================================================


//=================SimpleDB Creator=================
Database SimpleDB::CreateDB(std::string& dbname)
{ //Calls for CreateDatabase method from database.h.
    return Database::CreateDatabase(dbname);
}
//==================================================


//==================SimpleDB Loader=================
Database SimpleDB::LoadDB(std::string& dbname)
{ //Calls for LoadDatabase method from database.h.
    return Database::LoadDatabase(dbname);
}
//==================================================

#include <iostream>
//=================Valid Key Checker================
bool dbh::IsValidKey (std::string key, Database* db)
{ //Checks if a given string matches with a valid key within the database.
    bool is_valid = false;
    //TODO
    return is_valid;
}
//==================================================