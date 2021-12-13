/*
Index management file.

This file is resposible for Index management.
Index is a dictory that contais references to
data stored in the database, it's pupose is 
to make file operations on the database much
faster an painless.

Important Note: the first member of the Index 
vector is reserved for header information, it
uses "member_key_size" to store header size and
"member_value_position" to a make a reference to
the end of the file.

database.cpp is dependant on this file.
quicksort.cpp is dependant on this file.
*/


//Libraries
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>


//Header Files
#include "index.h"
#include "quicksort.h"


//=====================Namespace====================
namespace fs = std::filesystem;
//==================================================


//====================Constructor===================
Index::Index(size_t key_size, int key, int sorting_key, size_t value_size, size_t value_position) :
    member_key_size(key_size),
    member_key(key),
    member_sorting_key(sorting_key),
    member_value_size(value_size),
    member_value_position(value_position)
{;}
//==================================================


//===================Get Index Key==================
int Index::GetKey()
{ //Returns the index main key value.
    return member_key;
}
//==================================================


//================Get Key String Size===============
size_t Index::GetKeySize()
{ //Returns the index key string size value.
    return member_key_size;
}
//==================================================


//===============Get Index Sorting Key==============
int Index::GetSortingKey()
{ //Returns the index sorting key value.
    return member_sorting_key;
}
//==================================================


//================Get Value Position================
size_t Index::GetValuePosition()
{ //Returns the value of the position of the value string within the database file.
    return member_value_position;
}
//==================================================

//==================Get Value Size==================
size_t Index::GetValueSize()
{ //Returns the value string size.
    return member_value_size;
}
//==================================================


//===================Index Creator==================
std::vector<Index> Index::CreateIndex(std::string dbname)
{   //Returns a Index vector with the header information as it's first value.
    int header_size = (sizeof(size_t) + dbname.size() + sizeof(int));           //Calculates header size in file.
    std::vector<Index> newindex;
    newindex.push_back(Index(header_size, 0, 0, 0, header_size));               //Sets the first member of the vector with the database header information.
    return newindex;                                                            //Returns previously created Index vector.
}
//==================================================


//===================Index Loader===================
std::vector<Index> Index::LoadIndex(std::string dbname, std::string dbpath, int dbsize)
{   //Returns a complete index for database being loaded.
    int header_size = (sizeof(size_t) + dbname.size() + sizeof(int));           //Calculates header size in file.
    int read_position = header_size;                                            //Sets read position the the first member after the header.

    size_t key_size, value_size;
    int key, sorting_key, value_position;
    std::string temp;

    std::vector<Index> newindex;
    newindex.push_back(Index(header_size, 0, 0, 0, header_size));               //Sets the first member of the vector with the database header information.

    std::ifstream ifile(dbpath, std::ios::binary);                              //Opens database file as input.
    ifile.seekg(read_position);                                                 //Sets files to correct read position

    for(int i = 0; i < dbsize; i++)
    { //Reads every key stored in the database.
        //Reads index data into primary memory.
        ifile.read((char*)&key_size, sizeof(size_t));                           //Reads key size.
        temp.resize(key_size);
        ifile.read(&temp[0], key_size);                                         //Reads key.
        temp.erase(0, 4);                                                       //Remover "key_" from "temp" string for integer conversion.
        key = std::stoi(temp);                                                  //Converts "temp" stroing to an integer.
        ifile.read((char*)&sorting_key, sizeof(int));                           //Reads sorting key.
        ifile.read((char*)&value_size, sizeof(size_t));                         //Reads value size.

        //Calculates value position
        value_position = (read_position + sizeof(size_t) + key_size + sizeof(int) + sizeof(size_t));

        //Skips reading value as it's not necessary for index.
        read_position = (value_position + value_size);
        ifile.seekg(read_position);

        //Appends a new Index to the vector with the current read information.
        newindex.push_back(Index(key_size, key, sorting_key, value_size, value_position));
    }
    ifile.close();                                                              //Closes file.

    newindex[0].member_value_position = read_position;                          //Updates header reference to the end of the file.
    Index::SortIndex(&newindex, 2);                                             //Sorts the fully loaded index vector by sorting key values.

    return newindex;
}
//==================================================


//===================Index Sorter===================
void Index::SortIndex(std::vector<Index>* dbindex, int type)
{ //Calls for index sorting.
    qcks::Sort(dbindex, type);
}
//==================================================


//==================Index Inserter==================
void Index::InsertIndexKey(std::vector<Index>* dbindex, Datacell* newmember)
{ //Appends ans sorts a new member into the database index.
    //Calculates value position within the database file.
    int valuepos = (
        ((*dbindex)[0].member_value_position) +
        sizeof(size_t) +
        ((newmember->GetKey()).size()) +
        sizeof(int) +
        sizeof(size_t)
    );


    dbindex->push_back(Index(                                                   //Appends new member to index vector.
        ((newmember->GetKey()).size()),
        (std::stoi((newmember->GetKey()).erase(0,4))),
        (newmember->GetSortingKey()),
        ((newmember->GetValue()).size()),
        (valuepos)
    ));

    Index::SortIndex(dbindex, 2);                                               //Sorts fully loaded index vector by sorting key values.
    //Updates header reference to end of the file.
}
//==================================================


//=================Valid Key Checker================
int Index::IsValidKey(std::vector<Index>* dbindex, int key)
{ //Returns the position of the key within the Index vector if it exist or -1 if is does not exist.
    int keypos = 0;
    
    while(keypos < dbindex->size())
    {
        if(key == (*dbindex)[keypos].member_key)
        {
            return keypos;
        }

        keypos++;
    }

    return -1;
}
//==================================================


//===================Index Removal==================
void Index::RemoveIndexKey(std::vector<Index>* dbindex, int key)
{
    int keypos = Index::IsValidKey(dbindex, key);

    //Checks if key exits within the index vector.
    if(keypos != -1)
    { //Key exists within the index vector.
        std::swap((*dbindex)[keypos], (*dbindex)[dbindex->size() - 1]);         //Move member to erase to last place in the index vector.
        dbindex->pop_back();                                                    //Deletes the last member of the index vector.
    }
    else
    { //Key does not exists whitin the index vector, throws an exception.
        throw std::runtime_error("Index::RemoveIndexKey=invalidkey");
    }
}
//==================================================