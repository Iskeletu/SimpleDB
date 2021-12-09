//Header definition
#ifndef database_h_
#define database_h_


//Libraries
#include <string>


//Dependencies
#include "datacell.h"


//======================Classes=====================
class Database
{
    public:
        Database(std::string dbname, std::string path);

        std::string         GetDirectory        (void);
        void                InsertKeyValue      (Datacell* newcell, Database* db);
        std::string         SearchKeyValue      (std::string key);
        void                Erase               (void);

        static Database     CreateDatabase      (std::string dbname);
        static Database     LoadDatabase        (std::string dbname);

    protected:
        std::string member_name;
        std::string member_path;
};
//==================================================


#endif