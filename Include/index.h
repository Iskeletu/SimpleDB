//Header definition
#ifndef index_h_
#define index_h_


//Libraries
#include <string>
#include <vector>


//Dependencies
#include "datacell.h"
#include "database.h"


//======================Classes=====================
class Index
{
    public:
        Index(int key, int sorting_key, int header_size, int key_size, int value_size);

        int member_key;

        void                            InsertIndexKey      (Datacell existingcell);
        void                            RemoveIndexKey      (std::string* key);
        void                            OrderIndex          (void);

        static std::vector<Index>       CreateIndex         (Database* db);

    protected:
        int member_sorting_key;
        int member_header_size;
        int member_key_size;
        int member_value_size;
};
//==================================================


#endif