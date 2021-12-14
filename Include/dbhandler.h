//Header definition
#ifndef dbhandler_h_
#define dbhandler_h_


//Libraries
#include <string>


//Dependeies
#include "database.h"
#include "datacell.h"


//=====================Functions====================
namespace dbh
{//Short for "Database Handler".
    Database    CreateDB                (std::string& dbname);
    Database    LoadDB                  (std::string& dbname);
    bool        RemoveDBKey             (Database* db, Datacell* existingcell);
    bool        UpdateDBKey             (Database* db, Datacell* oldcell, Datacell* newcell);
    bool        PrintList               (Database* db, int value, int print_type, int operator_type);
    bool        CompressDatabase        (Database* db, int* type);
    bool        DecompressDatabase      (Database* db, int* type);
};
//==================================================


#endif