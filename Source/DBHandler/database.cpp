/*
Database managment file.
All work done in non-compressed database is handled by this file.
*/


//Libraries
#include <iostream>
#include <fstream>
#include <filesystem>


//Header Files
#include "database.h"
#include "huffman.h"
#include "lzw.h"


//=====================Namespace====================
using namespace std;
namespace fs = std::filesystem;
//==================================================


//====================Initializer===================
Database::Database(string dbname, string path)
    : member_name(dbname), member_path(path)
{
    ;
}
//==================================================


//=================Database Creator=================
Database Database::CreateDatabase(string dbname)
{ //Create and return a reference to a database.
    string basedir("./Data");
    string dbfolder(basedir + "/" + dbname); //This will not work on windows

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
Database Database::LoadDatabase(string dbname)
{ //Loads and returns a reference to an existing database.
    string basedir("./Data");
    string dbfolder(basedir + "/" + dbname); //This will not work on windows
    return Database(dbname, dbfolder); //Assumes it already exists
}
//==================================================


//=================Get Path Function================
string Database::GetDirectory()
{ //This functions returns the full path of the database file
    return member_path;
}
//==================================================


//=================Insert Key-Value=================
void Database::InsertKeyValue(string key, string value)
{
    ofstream kvfile;
    kvfile.open(member_path + "/" + key + "_string.kv", ios::out | ios::trunc); //This will not work on windows
    kvfile<<value;
    kvfile.close();
}
//==================================================


//=================Search Key-Value=================
string Database::SearchKeyValue(string key)
{
    string value;

    ifstream kvfile(member_path + "/" + key + "_string.kv");
    kvfile.seekg(0, ios::end);
    value.reserve(kvfile.tellg());
    kvfile.seekg(0, ios::beg);

    value.assign(
        istreambuf_iterator<char>(kvfile),
        istreambuf_iterator<char>()
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