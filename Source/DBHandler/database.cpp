/*
Database managment file.

All work done in non-compressed database
is handled by this file.

Database Handling is dependant on this file.
*/


//Libraries
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>


//Header Files
#include "database.h"
#include "huffman.h"
#include "lzw.h"


//=====================Namespace====================
namespace fs = std::filesystem;
//==================================================


//====================Constructor===================
Database::Database(std::string dbname, std::string path) :
    member_name(dbname),
    member_path(path)
{;}
//==================================================


//=================Database Creator=================
Database Database::CreateDatabase(std::string dbname)
{ //Creates and return a reference to a database.
    std::string basedir("./Data");
    std::string dbfolder(basedir + "/" + dbname);                               //This will not work on windows.

    if(!fs::exists(basedir))
    { //Creates the base folder (default = {ProjectRoot}/Data/) if it does not exist.
        fs::create_directory(basedir);
    }

    if(!fs::exists(dbfolder))
    { //Creates database folder if it does not exist.
        fs::create_directory(dbfolder);
    }

    return Database(dbname, dbfolder);
}
//==================================================


//==================Database Loader=================
Database Database::LoadDatabase(std::string dbname)
{ //Load and return a reference to an existing database.
    std::string basedir("./Data");
    std::string dbfolder(basedir + "/" + dbname);                               //This will not work on windows.
    return Database(dbname, dbfolder);                                          //Assumes database already exists.
}
//==================================================


//=================Get Path Function================
std::string Database::GetDirectory()
{ //Returns the full path of the database folder.
    return member_path;
}
//==================================================


//=================Insert Key-Value=================
void Database::InsertKeyValue(std::string key, std::string value)
{ //Creates a folder with a name based on the "key" value and store "value" on it.
    std::ofstream kvfile;
    kvfile.open(
        member_path + "/" + key + "_string.kv", std::ios::out | std::ios::trunc
    );                                                                          //This will not work on windows.
    kvfile<<value;
    kvfile.close();
}
//==================================================


//=================Search Key-Value=================
std::string Database::SearchKeyValue(std::string key)
{ //Returns value stored in "key" folder.
    std::string value;

    std::ifstream kvfile(member_path + "/" + key + "_string.kv");               //This will not work on windows.
    kvfile.seekg(0, std::ios::end);
    value.reserve(kvfile.tellg());
    kvfile.seekg(0, std::ios::beg);

    value.assign(
        std::istreambuf_iterator<char>(kvfile),
        std::istreambuf_iterator<char>()
    );

    return value;
}
//==================================================


//==================Erase Database==================
void Database::Erase()
{ //Deletes all files and folders related to the database.
    if (fs::exists(member_path))
    {
        fs::remove_all(member_path);
    }
}
//==================================================