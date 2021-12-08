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
        string GetDirectory(void);
        void InsertKeyValue(string key, string value);
        string SearchKeyValue(string key);

    static Database CreateDatabase(string dbname);

    protected:
        string member_name;
        string member_path;
};
//==================================================


//=====================Functions====================
namespace dbh //Short for database handler
{

};
//==================================================


#endif