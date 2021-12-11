/*
Database managment file.

All work done in non-compressed database
is handled by this file.

database.cpp is dependant on this file.
*/


//Libraries
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>


//Header Files
#include "database.h"


//Local Reference
std::string basedir("./Data");                                                  //Default directory databases are loaded from.


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
    std::string dbfolder(basedir + "/" + dbname);                               //!This will not work on windows.
    std::string dbfile(dbfolder + "/" + dbname + ".db");                        //!This will not work on windows.

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

    //Creates a new database file and it's reference.
    std::ofstream ofile(dbfile, std::ios::binary);                              //Creates file and open as input and output.
    Database db(dbname, dbfolder);                                              //Creates database reference to previouly created file.

    //Formats as a default blank database file.
    db.member_size = 0;

    size_t string_size = dbname.size();
    ofile.write((char*)&string_size, sizeof(size_t));                      //Inserts size of "dbname" string.
    ofile.write(&dbname[0], string_size);                                       //Inserts "dbname" string.
    ofile.write((char*)&db.member_size, sizeof(int));                           //Inserts database size integer.
    ofile.flush();

    if(!ofile.good())
    { //Throws an exception if writing was not successful.
      throw std::runtime_error("Database::CreateDatabase=writingfailure");
    }

    ofile.close();                                                              //Closes file.


    //Return the new reference.
    return db;
}
//==================================================


//==================Database Reader=================
int ReadDatabase(std::string path, std::string dbname)
{ //This function rturns the amount of key stores inside the database and creates an index file.
    std::ifstream dbfile(path + "/" + dbname + ".db");                          //!This will not work on windows.
    std::ofstream indexfile(path + "/" + dbname + ".index");
    int keycounter = 0;

    //TODO - Database reader

    return keycounter;
}
//==================================================


//==================Database Loader=================
Database Database::LoadDatabase(std::string dbname)
{ //Load and return a reference to an existing database.
    std::string dbfolder(basedir + "/" + dbname);                               //!This will not work on windows.
    std::string dbfile(dbfolder + "/" + dbname + ".db");                        //!This will not work on windows.

    if(fs::is_directory(fs::status(dbfolder)))
    { //Throws a runtime error if the path the function is trying to load the database from does not exist.
        throw std::runtime_error("Database::LoadDatabase=inexistent_path");
    }

    if(fs::exists(dbfile))
    { //Checks if database file exists.

        //TODO - Check if database file is valid

        if(true) //!does not check if file is valid yet
        { //The file exist and it's contents are valid. 
            Database loadeddb(dbname, dbfolder);

            //TODO - check how many key are store on the loaded database
            loadeddb.member_size = ReadDatabase(dbfolder, dbname);
        
            return loadeddb;
        }
        else
        { //The file exist but it's contets are invalid. Throws a runtime error.
            throw std::runtime_error("Database::LoadDatabase=invalid_file");
        }
    }
    else
    { //Throws a runtime error if the database the function is trying to load does no exist.
        throw std::runtime_error("Database::LoadDatabase=inexistent_file");
    }
}
//==================================================


//=================Get Path Function================
std::string Database::GetDirectory()
{ //Returns the full path of the database folder.
    return member_path;
}
//==================================================


//=================Get Name Function================
std::string Database::GetName()
{ //Returns the name of the database folder.
    return member_name;
}
//==================================================


//=================Generete New Key=================
std::string Database::NewUniqueKey(void)
{ //Generates a ney unique key string;
    return("key_" + std::to_string(member_size + 1));
}
//==================================================

#include <iostream>
//=================Insert Key-Value=================
void Database::InsertKeyValue(Datacell* newcell, Database* db)
{ //Creates a folder with a name based on the "key" value and store "value" on it.
    std::string path = (db->GetDirectory() + "/" + db->member_name + ".db");    //!This will not work on windows.

    //Extract cell data to local variables.
    std::string key = newcell->GetKey();
    int sorting_key = newcell->GetSortingKey();
    std::string value = newcell->GetValue();

    //Opens Database file
    std::ofstream ofile(path, std::ios::binary | std::ios::app);                //Opens files as output and set to append to the end of the file.

    //Datacell insertion.
    size_t string_size = key.size();
    ofile.write((char*)&string_size, sizeof(size_t));                           //Inserts size of "key" string.
    ofile.write(&key[0], string_size);                                          //Inserts "key" strig.
    ofile.write((char*)&sorting_key, sizeof(int));                              //Insert sorting key integer.
    string_size = value.size();
    ofile.write((char*)&string_size, sizeof(size_t));                           //Inserts size of "value" string.
    ofile.write(&value[0], string_size);                                        //Inserts "value" string.

    if(!ofile.good())
    { //Throws an exception if writing was not successful.
      throw std::runtime_error("Database::InsertKeyValue=writingfailure");
    }

    ofile.close(); ofile.open(path, std::ios::binary | std::ios::in);           //Reopens file as output and set to not overwrite unwanted data.

    member_size++;
    ofile.seekp(sizeof(size_t) + member_name.size());                           //Sets write location to database size.
    ofile.write((char*)&member_size, sizeof(int));                              //Overwrites database size.
    ofile.close();                                                              //Closes file.
}
//==================================================


//=================Search Key-Value=================
std::string Database::SearchKeyValue(std::string key)
{ //Returns value stored in "key" folder.
    std::string value;

    //TODO

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

/*
!delete
simpledb --insert=<1,aa>
simpledb --insert=<2,bb>
simpledb --insert=<3,cc>
simpledb --insert=<4,dd>
*/