/*
SimpleDB lib.
Intermediary between the functions of the
database and the rest of the program.
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
{
    return Database::CreateDatabase(dbname);
}
//==================================================


//==================SimpleDB Loader=================
Database SimpleDB::LoadDB(std::string& dbname)
{
    return Database::LoadDatabase(dbname);
}
//==================================================