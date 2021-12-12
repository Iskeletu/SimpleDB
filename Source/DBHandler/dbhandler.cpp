/*
SimpleDB lib.

Intermediary between the functions of the
database and the rest of the program.

Handles calls to database functions so other files
don't have to do it directly and cause erros.

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
{ //Calls for CreateDatabase function from database.h.
    return Database::CreateDatabase(dbname);
}
//==================================================


//==================SimpleDB Loader=================
Database SimpleDB::LoadDB(std::string& dbname)
{ //Calls for LoadDatabase function from database.h.
    return Database::LoadDatabase(dbname);
}
//==================================================


//================SimpleDB Key Remover==============
bool SimpleDB::RemoveDBKey(Database* db, Datacell* existingcell)
{ //Calls for key removal from database file. 
    return Database::RemoveKeyValue(db, existingcell);
}
//==================================================


//================SimpleDB Key Updater==============
bool SimpleDB::UpdateDBKey(Database* db, Datacell* oldcell, Datacell* newcell)
{ //Calls for key removal from database file then inserts the same key with a different value.
    bool success = Database::RemoveKeyValue(db, oldcell);

    if(success)
    {
        db->InsertKeyValue(newcell);
    }

    return success;
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