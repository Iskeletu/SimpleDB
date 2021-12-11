//Header definition
#ifndef quicksort_h_
#define quicksort_h_


//Libraries
#include <vector>


//Dependencies
#include "index.h"


//=====================Functions====================
namespace qcks
{ //Short for "Quick-Sort".
    void QuickSort (std::vector<Index>* dbindex, int start, int end);
};
//==================================================


#endif