//Header definition
#ifndef index_h_
#define index_h_


//Libraries
#include <string>
#include <vector>


//Dependencies
#include "datacell.h"


//======================Classes=====================
class Index
{
    public:
        Index(size_t key_size, int key, int sorting_key, size_t value_size);

        void                            RemoveIndexKey      (int key);
        std::vector<int>                GetValuePosition    (int key);
        int                             GetSortingKey       (void);

        static std::vector<Index>       CreateIndex         (std::string dbname);
        static std::vector<Index>       LoadIndex           (std::string dbname, std::string dbpath, int dbsize);
        static void                     InsertIndexKey      (std::vector<Index>* dbindex, Datacell* newmember);
        static void                     SortIndex           (std::vector<Index>* dbindex);
        static void PrintIndex (std::vector<Index> loadedindex);

    protected:
        size_t member_key_size;
        int member_key;
        int member_sorting_key;
        size_t member_value_size;
};
//==================================================


#endif