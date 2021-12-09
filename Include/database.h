//Header definition
#ifndef database_h_
#define database_h_


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
        void Erase(void);

        static Database CreateDatabase(string dbname);
        static Database LoadDatabase(string dbname);

    protected:
        string member_name;
        string member_path;
};
//==================================================


#endif