//Header definition
#ifndef dbhandler_h_
#define dbhandler_h_


//Libraries
#include <string>


//=====================Namespace====================

//==================================================


//======================Classes=====================
class Database
{
    public:
        Database(std::string dbname, std::string path);

    static Database CreateDatabase(std::string dbname);
};
//==================================================


//=====================Functions====================

//==================================================


#endif