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

        int                             GetKey              (void);
        size_t                          GetKeySize          (void);
        int                             GetSortingKey       (void);
        size_t                          GetValuePosition    (void);
        size_t                          GetValueSize        (void);
        

        static std::vector<Index>       CreateIndex         (std::string dbname);
        static std::vector<Index>       LoadIndex           (std::string dbname, std::string dbpath, int dbsize);
        static void                     SortIndex           (std::vector<Index>* dbindex, int type);
        static void                     InsertIndexKey      (std::vector<Index>* dbindex, Datacell* newmember);
        static int                      IsValidKey          (std::vector<Index>* dbindex, int key);
        static void                     RemoveIndexKey      (std::vector<Index>* dbindex, int key);
        static std::vector<int>         SearchKey           (std::vector<Index>* dbindex, int key);

    protected:
        size_t member_key_size;
        int member_key;
        int member_sorting_key;
        size_t member_value_size;
        size_t member_value_position;
};
//==================================================


#endif