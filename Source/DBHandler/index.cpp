/*
Index management file.

This file is resposible for Index management.
Index is a dictory that contais references to
data stored in the database, it's pupose is 
to make file operations on the database much
faster an painless.

database.cpp is dependant on this file
*/


//Libraries
#include <string>
#include <vector>


//Header files
#include "index.h"


//====================Constructor===================
Index::Index(int key, int sorting_key, int header_size, int key_size, int value_size) :
    member_key(key),
    member_sorting_key(sorting_key),
    member_header_size(header_size),
    member_key_size(key_size),
    member_value_size(value_size)
{;}
//==================================================


//===================Index Creator==================
std::vector<Index> Index::CreateIndex(Database* db)
{
    std::string dbname = db->GetName();
    std::vector<Index> dbindex;
    dbindex.push_back(Index(0, 0, dbname.size(), 0, 0));
    return dbindex;
}
//==================================================