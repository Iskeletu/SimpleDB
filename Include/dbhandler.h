//Header definition
#ifndef dbhandler_h_
#define dbhandler_h_


//Libraries
#include <string>


//Dependecy
#include "database.h"


//=====================Namespace====================
using namespace std;
//==================================================


//======================Classes=====================
class SimpleDB
{
    public:
        SimpleDB();

        static Database CreateDB(string& dbname);
        static Database LoadDB(string& dbname);
};
//==================================================


//=====================Functions====================
namespace dbh //Short for database handler
{

};
//==================================================


#endif