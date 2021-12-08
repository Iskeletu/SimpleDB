/*
File in work.
*/


//Libraries
#include <iostream>
#include <fstream>
#include <filesystem>


//Header Files
#include "dbhandler.h"
#include "huffman.h"
#include "lzw.h"


//=====================Namespace====================
using namespace std;
namespace fs = std::filesystem;
//==================================================


//====================Initializer====================
Database::Database(string dbname, string path)
    : member_name(dbname), member_path(path)
{
    ;
}
//==================================================


//==================Database Crator=================
Database Database::CreateDatabase(string dbname)
{
    string basedir("../Data");
    string dbfolder(basedir + "/" + dbname); //will not work on windows, must fix

    if(!fs::exists(basedir))
    {
        fs::create_directory(basedir);
    }

    if(!fs::exists(dbfolder))
    {
        fs::create_directory(dbfolder);
    }

    return Database(dbname, dbfolder);
}
//==================================================


//=================Get Path Function================
string Database::GetDirectory(void)
{ //This functions returns the full path of the database file
    return member_path;
}
//==================================================

