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
    member_path(path),
    member_size(-1)
{;}
//==================================================


//=================Database Creator=================
Database Database::CreateDatabase(std::string dbname)
{ //Creates and return a reference to a database.
    std::string basedir("./Data");                                              //Default directory databases are created to.
    std::string dbfolder(basedir + "/" + dbname);                               //This will not work on windows.
    std::string dbfile(dbfolder + "/" + dbname + ".db");                        //This will not work on windows.

    if(!fs::exists(basedir))
    { //Creates the base folder (default = .{ProjectRoot}/Data/) if it does not exist.
        fs::create_directory(basedir);
    }

    if(!fs::exists(dbfolder))
    { //Creates database folder if it does not exist.
        fs::create_directory(dbfolder);
    }
    else
    { //Deletes contents in folder if it exits but a database creation was called.
        fs::remove_all(dbfolder);
        fs::create_directory(dbfolder);
    }

    //Creates a new database file.
    std::ofstream file;
    file.open(dbfile);

    //Formats as a default blank database file.
    std::string database_template = (
        "'" + dbname + "': {\n"
        "}"
    );
    file << database_template;

    file.close();                                                           //Closes file.

    //Creates database reference and sets it's size to 0;
    Database db(dbname, dbfolder);
    db.member_size = 0;

    return db;
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


//=================Generete New Key=================
std::string Database::NewUniqueKey(void)
{ //Generates a ney unique key string;
    int key = (member_size + 1);
    return("key_" + std::to_string(key));
}
//==================================================


//=================Insert Key-Value=================
void Database::InsertKeyValue(Datacell* newcell, Database* db)
{ //Creates a folder with a name based on the "key" value and store "value" on it.
    std::string path = (db->GetDirectory() + "/" + db->member_name + ".db");    //This will not work on windows.

    //Database key-value template.
    std::string key_value_template = (
        "\t'" + newcell->GetKey() + "': [\n"
        "\t\t'Sorting_Key': " + std::to_string(newcell->GetSortingKey()) + ",\n"
        "\t\t'Value': " + newcell->GetValue() + "\n"
        "\t]\n"
    );

    //Opens Database file
    std::fstream file;
    file.open(path);

    //Analises the current character to know if this is the first insertion to the database.
    file.seekp(-3, std::ios::end);
    char chscan[1]; file.read(chscan, 1);


    if(chscan[0] == ']')
    { //Checks if it's the firts database key.
        file << ",\n";
    }
    else
    { //Does not add a comma if this is the first key.
        file << "\n";
    }

    //Key insertion.
    file << (key_value_template + "}");

    file.close();                                                               //Closes file.
    member_size++;                                                              //Sets size of the database to one more.
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


//===============Database Compression===============
bool Database::CompressDatabase(int type)
{
    bool is_successful = false;

    switch(type)
    {
        case 1:
            is_successful = huffman::compress(member_path);
        break;

        case 2:
            is_successful = lzw::compress(member_path);
        break;
    }

    return is_successful;
}
//==================================================


//==============Database Decompression==============
bool Database::DecompressDatabase(int type)
{
    bool is_successful = false;

    switch(type)
    {
        case 1:
            is_successful = huffman::compress(member_path);
        break;

        case 2:
            is_successful = lzw::compress(member_path);
        break;
    }

    return is_successful;
}
//==================================================