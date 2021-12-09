//Header definition
#ifndef dbhandler_h_
#define dbhandler_h_


//Libraries
#include <string>


//Dependeies
#include "database.h"


//======================Classes=====================
class SimpleDB
{
    public:
        SimpleDB();

        static Database CreateDB(std::string& dbname);
        static Database LoadDB(std::string& dbname);
};
//==================================================


//=====================Functions====================
namespace dbh //Short for database handler
{

};
//==================================================


#endif