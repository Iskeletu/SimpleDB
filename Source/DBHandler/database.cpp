/*
Database managment file.

All work done in the non-compressed database
(.db) file is handled by this file.
*/


//Libraries
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>


//Header Files
#include "database.h"


//Local Database Base Direcaroty Reference
const std::string basedir("./Data");                                            //Default directory databases are loaded from.


//=====================Namespace====================
namespace fs = std::filesystem;
//==================================================


//====================Constructor===================
Database::Database(std::string dbname, std::string path, std::vector<Index> index_vector) :
    member_name(dbname),
    member_path(path),
    member_size(-1),
    member_last_insertion(-1),
    member_index(index_vector)
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
    Database db(dbname, dbfolder, Index::CreateIndex(dbname));                  //Creates database reference to previouly created file.

    //Formats as a default blank database file.
    db.member_size = 0;
    db.member_last_insertion = 0;

    size_t string_size = dbname.size();
    ofile.write((char*)&string_size, sizeof(size_t));                           //Inserts size of "dbname" string.
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
void ReadDatabase(Database* db, int* database_size, int* last_insertion, std::vector<Index>* newindex)
{ //This function loads database members store in binary database file to primary memory.
//Slave function to "Database::LoadDatabase".
    std::string dbfile = (db->GetDirectory() + "/" + db->GetName() +".db");      //!This will not work on windows.

    std::ifstream ifile(dbfile, std::ios::binary);                              //Opens file as input.

    //Reads database size.
    size_t string_size;
    ifile.read((char*)&string_size, sizeof(size_t));                            //Gets size of database name string on file.
    ifile.seekg(sizeof(size_t) + string_size);                                  //Sets read location to database size.
    ifile.read((char*)database_size, sizeof(int));                              //Gets database size value.

    //Reads the number of the last inserted key.
    if(*database_size > 0)
    { //The database has at least one key stored.
        std::string key;
        int scan = (sizeof(size_t) + string_size + sizeof(int));                //Sets read location to the first key inserted.

        for(int i = 1; i < *database_size; i++)
        { //Goes to the last key stored.
            ifile.seekg(scan);
            ifile.read((char*)&string_size, sizeof(size_t));
            scan = (scan + sizeof(size_t) + string_size + sizeof(int));
            ifile.seekg(scan);
            ifile.read((char*)&string_size, sizeof(size_t));
            scan = (scan + sizeof(size_t) + string_size);
        }
        ifile.seekg(scan);

        ifile.read((char*)&string_size, sizeof(size_t));                        //Gets size of key string on file.
        key.resize(string_size);
        ifile.read(&key[0], string_size);                                       //Gets value of the last key string from file and store on "key".
        key.erase(0, 4);                                                        //Removes "key_" from "key" string for integer conversion.
        *last_insertion = std::stoi(key);                                       //Defines "last_insertion" as the value of the integer conversion from "key" string.
    }
    else
    { //The database has no keys stored.
        *last_insertion = 0;
    }

    ifile.close();                                                              //Closes file.

    *newindex = Index::LoadIndex(db->GetName(), dbfile, *database_size);        //Generates a complete index for the database. //!(might slow down start up).
}
//==================================================


//==================Database Loader=================
Database Database::LoadDatabase(std::string dbname)
{ //Load and return a reference to an existing database.
    std::string dbfolder(basedir + "/" + dbname);                               //!This will not work on windows.
    std::string dbfile(dbfolder + "/" + dbname + ".db");                        //!This will not work on windows.

    if(!fs::exists(dbfolder))
    { //Throws a runtime error if the path the function is trying to load the database from does not exist.
        throw std::runtime_error("Database::LoadDatabase=inexistent_path");
    }

    if(fs::exists(dbfile))
    { //Checks if database file exists.
        //Checks if file is valid by comparing "dbname" with database name stored on the binary file.
        std::ifstream ifile(dbfile, std::ios::binary);                          //Opens file as input.

        size_t string_size;
        std::string temp;

        ifile.read((char*)&string_size, sizeof(size_t));                        //Gets size of database name string on file.
        temp.resize(string_size);
        ifile.read(&temp[0], string_size);                                      //Gets database name on file.
        ifile.close();                                                          //Closes file.

        if(temp == dbname)
        { //The file exist and it's contents are valid. 
            std::vector<Index> newindex = Index::CreateIndex(dbname);
            Database loadeddb(dbname, dbfolder, newindex);                      //Creates a database reference.

            //Loads relevant members to primary memory.
            int database_size, last_insertion;
            ReadDatabase(&loadeddb, &database_size, &last_insertion, &newindex);
            loadeddb.member_size = database_size;                               //Updates database size.
            loadeddb.member_last_insertion = last_insertion;                    //Updates last insertion value.
            loadeddb.member_index = newindex;                                   //Updates index.
        
            return loadeddb;                                                    //Returns previouly created database reference.
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


//=================Get Name Function================
std::string Database::GetName()
{ //Returns the name of the database folder.
    return member_name;
}
//==================================================


//=================Get Size Function================
int Database::GetSize()
{ //Returns size of the database.
    return member_size;
}
//==================================================


//================Get Index Function================
std::vector<Index>* Database::GetIndex()
{ //Returns the database index.
    return &member_index;
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
    return("key_" + std::to_string(member_last_insertion + 1));
}
//==================================================


//=================Insert Key-Value=================
void Database::InsertKeyValue(Datacell* newcell)
{ //Creates a folder with a name based on the "key" value and store "value" on it.
    std::string path = (member_path + "/" + member_name + ".db");               //!This will not work on windows.

    //Extract cell data to local variables.
    std::string key = newcell->GetKey();
    int sorting_key = newcell->GetSortingKey();
    std::string value = newcell->GetValue();

    //Opens Database file
    std::ofstream ofile(path, std::ios::binary | std::ios::app);                //Opens file as output and set to append to the end of the file.

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

    //Updates value of the last insertion to the database.
    key.erase(0,4);                                                             //Removes "key_" from "key" string for integer conversion.
    member_last_insertion = std::stoi(key);                                     //Defines "member_last_insertion" as the value of the integer conversion from "key" string.
    Index::InsertIndexKey(&member_index, newcell);                              //Updates index.
}
//==================================================


//=================Search Key-Value=================
bool Database::SearchKeyValue(Datacell* existingcell)
{ //Searchs and loads key value from database file, returns true if informed key exists within the database file and false if not.
    //Extracts index vector key location if it exists, recieves -1 if it does not.
    int search_result = Index::IsValidKey(&member_index, stoi((existingcell->GetKey()).erase(0,4)));

    //Checks if key exist within the index file.
    if(search_result != -1)
    { //Key exists, reads value from file and returns true.
        std::string dbfile(member_path + "/" + member_name + ".db");            //!This will not work on windows.
        std::string value; value.resize(member_index[search_result].GetValueSize());

        std::ifstream ifile(dbfile, std::ios::binary);                          //Opes file as input.
        ifile.seekg(member_index[search_result].GetValuePosition());            //Sets read point to desired value.
        ifile.read(&value[0], member_index[search_result].GetValueSize());      //Reads value to "value" string.
        ifile.close();                                                          //Closes file.

        //Updates existing cell.
        existingcell->UpdateValues(existingcell->GetKey(), member_index[search_result].GetSortingKey(), value);

        return true;
    }
    else
    { //Key does not exist, return false.
        return false;
    }
}
//==================================================


//=================Remove Key-Value=================
/*? Complex Function:
This function removes the desied key frpom the index, it then uses
the remaining values to create a temporary (.temp) file with the 
contents of main .db files with the exception of the key deleted.
When the writing is done, this function replaces the existing .db
file with the temporary file, the database then reloads itself
(mainly to update index value positions).
*/
bool Database::RemoveKeyValue(Database* db, Datacell* existingcell)
{ //Deletes an existing key stored inside the database, returns true if informed key exists within the database file and false if not.
    //Local references
    std::string dbname = db->GetName();
    std::string filewithoutextension = ((db->GetDirectory()) + "/" + dbname);      //!This will not work on windows.
    std::vector<Index>* index = db->GetIndex();
    int dbsize = (db->GetSize() - 1);

    //Extracts index vector key location if it exists, recieves -1 if it does not.
    int key = stoi((existingcell->GetKey()).erase(0,4));
    int search_result = Index::IsValidKey(index, key);

    //Checks if key exist within the index file.
    if(search_result != -1)
    { //Key exists, deletes key and its values from file and returns true.
        //? Check function documentation above.
        size_t string_size;
        std::string tempstring;
        int tempint;

        //Opens database file as input and creates temporary file as output.
        std::ifstream ifile((filewithoutextension + ".db"), std::ios::binary);   
        std::ofstream ofile((filewithoutextension + ".temp"), std::ios::binary);

        //Updates datacell information (Same as value search).
        string_size = (*index)[search_result].GetValueSize();
        tempstring.resize(string_size);
        ifile.seekg((*index)[search_result].GetValuePosition());
        ifile.read(&tempstring[0], string_size);
        existingcell->UpdateValues(existingcell->GetKey(), (*index)[search_result].GetSortingKey(), tempstring);

        Index::RemoveIndexKey(index, key);                                      //Removes key from index.
        Index::SortIndex(index, 1);                                             //Sorts index by main key values.

        //Header writing to temporary file (Same as database creation).
        string_size = dbname.size();
        ofile.write((char*)&string_size, sizeof(size_t));
        ofile.write(&dbname[0], string_size);
        ofile.write((char*)&dbsize, sizeof(int));

        for(int i = 1; i < index->size(); i++)
        { //Writes index information to temporary file.
            //Key-value writing to temporary file (Same as key insertion).
            string_size = (*index)[i].GetKeySize();
            ofile.write((char*)&string_size, sizeof(size_t));

            tempstring = ("key_" + std::to_string((*index)[i].GetKey()));
            ofile.write(&tempstring[0], string_size);

            tempint = (*index)[i].GetSortingKey();
            ofile.write((char*)&tempint, sizeof(int));

            string_size = (*index)[i].GetValueSize();
            ofile.write((char*)&string_size, sizeof(size_t));

            tempstring.resize(string_size);
            ifile.seekg((*index)[i].GetValuePosition());
            ifile.read(&tempstring[0], string_size);
            ofile.write(&tempstring[0], string_size);
        }

        //Closes files.
        ifile.close();
        ofile.close();

        //Replaces main database file with the newly generated temporary file.
        fs::rename(filewithoutextension + ".temp", filewithoutextension + ".db");

        *db = Database::LoadDatabase(dbname);
        return true;
    }
    else
    { //Key does not exist, return false.
        return false;
    }
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






//!delete
#include <iostream>
void Database::Debug()
{
    system("clear");
    std::cout << "Normal index." << std::endl;
    Index::PrintIndex(member_index);
    std::cin.get();

    system("clear");
}