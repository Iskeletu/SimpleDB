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
        Index(size_t key_size, int key, int sorting_key, size_t value_size, size_t value_position);

        int                             GetSortingKey       (void);

        static std::vector<Index>       CreateIndex         (std::string dbname);
        static std::vector<Index>       LoadIndex           (std::string dbname, std::string dbpath, int dbsize);
        static void                     SortIndex           (std::vector<Index>* dbindex);
        static void                     InsertIndexKey      (std::vector<Index>* dbindex, Datacell* newmember);
        static int                      IsValidKey          (std::vector<Index>* dbindex, int key);
        static void                     RemoveIndexKey      (std::vector<Index>* dbindex, int key);
        static std::vector<int>         GetValuePosition    (std::vector<Index>* dbindex, int key);

        static void PrintIndex (std::vector<Index> loadedindex); //!delete

    protected:
        size_t member_key_size;
        int member_key;
        int member_sorting_key;
        size_t member_value_size;
        size_t member_value_position;
};
//==================================================


#endif