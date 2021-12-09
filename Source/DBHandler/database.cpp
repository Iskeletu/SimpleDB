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
    std::string basedir("./Data");                                              //Default directory databases are created to.
    std::string dbfolder(basedir + "/" + dbname);                               //This will not work on windows.
    std::string dbfile(dbfolder + "/" + dbname + ".db");                        //This will not work on windows.

    if(!fs::exists(basedir))
    { //Creates the base folder (default = {ProjectRoot}/Data/) if it does not exist.
        fs::create_directory(basedir);
    }

    if(!fs::exists(dbfolder))
    { //Creates database folder if it does not exist.
        fs::create_directory(dbfolder);
    }

    if(!fs::exists(dbfile))
    { //Creates a database file if it does not exist.
        std::ofstream{dbfile};

        //Formats as a default blank database file.
        std::ofstream file;
        file.open(dbfile);
        std::string database_template = (
            "'" + dbname + "': {\n"
            "\n"
            "}"
        );
        file << database_template;
        file.close();
    }

    return Database(dbname, dbfolder);
}
//==================================================


//==================Database Loader=================
Database Database::LoadDatabase(std::string dbname)
{ //Load and return a reference to an existing database.
    std::string basedir("./Data");                                              //Default directory databases are loaded from.
    std::string dbfolder(basedir + "/" + dbname);                               //This will not work on windows.
    std::string dbfile(dbfolder + "/" + dbname + ".db");                        //This will not work on windows.

    if(!fs::exists(dbfile))
    { //Checks if databse exists.
        return Database(dbname, dbfolder);
    }
    else
    { //Returns a null database if the database the function is trying to load does no exist.
        return Database("null", "null");
    }
}
//==================================================


//=================Get Path Function================
std::string Database::GetDirectory()
{ //Returns the full path of the database folder.
    return member_path;
}
//==================================================


//=================Insert Key-Value=================
void Database::InsertKeyValue(Datacell* newcell)
{ //Creates a folder with a name based on the "key" value and store "value" on it.
    std::string key_value_template = (
            "\t'" + newcell->GetKey() + "': [\n"
            "\t\t'Sorting-Key': " + newcell->GetKey() + ",\n"
            "\t\t'Value': " + newcell->GetValue() + "\n"
            "]"
        );

    std::ofstream kvfile;
    kvfile.open(
        member_path + "/" + newcell->GetKey() + "_string.kv", std::ios::out | std::ios::trunc
    );                                                                          //This will not work on windows.
    kvfile << newcell->GetValue();
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