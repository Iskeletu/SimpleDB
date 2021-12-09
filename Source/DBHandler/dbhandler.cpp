/*
File in work
*/


//Header File
#include "dbhandler.h"


//=====================Namespace====================
using namespace std;
//==================================================


//====================Initializer===================
SimpleDB::SimpleDB()
{
    ;
}
//==================================================


//=================Database Creator=================
Database SimpleDB::CreateDB(string& dbname)
{
    return Database::CreateDatabase(dbname);
}
//==================================================


//==================Database Loader=================
Database SimpleDB::LoadDB(string& dbname)
{
    return Database::LoadDatabase(dbname);
}
//==================================================