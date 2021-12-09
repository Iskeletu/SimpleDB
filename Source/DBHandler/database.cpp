/*
Database managment file.
All work done in non-compressed database is handled by this file.
*/


//Libraries
#include <iostream>
#incldue <string>
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
{ //Create and return a reference to a database.
    std::string basedir("./Data");
    std::string dbfolder(basedir + "/" + dbname); //This will not work on windows

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


//==================Database Loader=================
Database Database::LoadDatabase(std::string dbname)
{ //Loads and returns a reference to an existing database.
    std::string basedir("./Data");
    std::string dbfolder(basedir + "/" + dbname); //This will not work on windows
    return Database(dbname, dbfolder); //Assumes it already exists
}
//==================================================


//=================Get Path Function================
std::string Database::GetDirectory()
{ //This functions returns the full path of the database file
    return member_path;
}
//==================================================


//=================Insert Key-Value=================
void Database::InsertKeyValue(std::string key, std::string value)
{
    std::ofstream kvfile;
    kvfile.open(member_path + "/" + key + "_string.kv", std::ios::out | std::ios::trunc); //This will not work on windows
    kvfile<<value;
    kvfile.close();
}
//==================================================


//=================Search Key-Value=================
std::string Database::SearchKeyValue(std::string key)
{
    std::string value;

    std::ifstream kvfile(member_path + "/" + key + "_string.kv");
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
{ //Deletes all files related to a database.
    if (fs::exists(member_path))
    {
        fs::remove_all(member_path);
    }
}
//==================================================