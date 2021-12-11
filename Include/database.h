//Header definition
#ifndef database_h_
#define database_h_


//Libraries
#include <string>


//Dependencies
#include "datacell.h"
#include "index.h"


//======================Classes=====================
class Database
{
    public:
        Database(std::string dbname, std::string path, std::vector<Index> index);

        std::string         GetDirectory            (void);
        std::string         GetName                 (void);
        std::string         NewUniqueKey            (void);
        void                InsertKeyValue          (Datacell* newcell);
        bool                SearchKeyValue          (Datacell* existingcell);
        bool                UpdateKeyValue          (Datacell* existingcell);
        bool                RemoveKeyValue          (Datacell* existingcell);
        void                Erase                   (void);
            void DebugIndex(void); //!delete
        static Database     CreateDatabase          (std::string dbname);
        static Database     LoadDatabase            (std::string dbname);

    protected:
        std::string member_name;
        std::string member_path;
        int member_size;
        int member_last_insertion;
        std::vector<Index> member_index;
};
//==================================================


#endif