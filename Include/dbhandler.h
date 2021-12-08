//Header definition
#ifndef dbhandler_h_
#define dbhandler_h_


//Libraries
#include <string>


//=====================Namespace====================
using namespace std;
//==================================================


//======================Classes=====================
class Database
{
    public:
        Database(string dbname, string path);

    static Database CreateDatabase(string dbname);
};
//==================================================


//=====================Functions====================

//==================================================


#endif