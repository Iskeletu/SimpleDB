/*
SimpleDB lib.

Intermediary between the functions of the
database and the rest of the program.

Compression/Decompression algorithm files are dependant on this file.
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