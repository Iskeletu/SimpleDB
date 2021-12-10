/*
SimpleDB lib.

Intermediary between the functions of the
database and the rest of the program.

commandhandler.cpp is dependant on this file.
*/


//Libraries
#include <string>


//Header Files
#include "dbhandler.h"
#include "huffman.h"
#include "lzw.h"


//====================Constructor===================
SimpleDB::SimpleDB()
{;}
//==================================================


//=================SimpleDB Creator=================
Database SimpleDB::CreateDB(std::string& dbname)
{ //Calls for CreateDatabase method from database.h.
    return Database::CreateDatabase(dbname);
}
//==================================================


//==================SimpleDB Loader=================
Database SimpleDB::LoadDB(std::string& dbname)
{ //Calls for LoadDatabase method from database.h.
    return Database::LoadDatabase(dbname);
}
//==================================================

#include <iostream>
//=================Valid Key Checker================
bool dbh::IsValidKey (std::string key, Database* db)
{ //Checks if a given string matches with a valid key within the database.
    bool is_valid = false;
    //TODO
    return is_valid;
}
//==================================================


//===============Database Compression===============
bool dbh::CompressDatabase(Database* db, int* type)
{ //TODO
    bool is_successful = false;

    switch(*type)
    {
        case 1:
            huffman::compress(db->GetDirectory());
        break;

        case 2:
            lzw::compress(db->GetDirectory());
        break;
    }

    return is_successful;
}
//==================================================


//==============Database Decompression==============
bool dbh::DecompressDatabase(Database* db, int* type)
{ //TODO
    bool is_successful = false;

    switch(*type)
    {
        case 1:
            huffman::decompress(db->GetDirectory());
        break;

        case 2:
            lzw::decompress(db->GetDirectory());
        break;
    }

    *db = Database::LoadDatabase(db->GetName());

    return is_successful;
}
//==================================================