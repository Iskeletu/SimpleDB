//Header definition
#ifndef dbhandler_h_
#define dbhandler_h_


//Libraries
#include <string>


//Dependeies
#include "database.h"
#include "datacell.h"


//======================Classes=====================
class SimpleDB
{
    public:
        SimpleDB();

        static Database     CreateDB                (std::string& dbname);
        static Database     LoadDB                  (std::string& dbname);
        static bool         RemoveDBKey             (Database* db, Datacell* existingcell);
        static bool         UpdateDBKey             (Database* db, Datacell* oldcell, Datacell* newcell);
};
//==================================================


//=====================Functions====================
namespace dbh
{//Short for "Database Handler".
    bool                    CompressDatabase        (Database* db, int* type);
    bool                    DecompressDatabase      (Database* db, int* type);
};
//==================================================


#endif