//Header definition
#ifndef datacell_h_
#define datacell_h_


//Libraries
#include <string>


//======================Classes=====================
class Datacell
{
    public:
        Datacell(std::string key, int sorting_key, std::string value);

        std::string             GetKey              (void);
        int                     GetSortingKey       (void);
        std::string             GetValue            (void);

        static Datacell         CreateDatacell      (std::string key, int sorting_key, std::string value);

    protected:
        std::string member_key;
        int member_sorting_key;
        std::string member_value;
};
//==================================================


#endif