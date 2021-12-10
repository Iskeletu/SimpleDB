//Header definition
#ifndef lzw_h_
#define lzw_h_


//Libraries
#include <filesystem>


//Dependencies
#include "dbhandler.h"


//=====================Namespace====================
namespace fs = std::filesystem;
//==================================================


//=====================Functions====================
namespace lzw
{
    bool    compress        (fs::path path);
    bool    decompress      (fs::path path);
};
//==================================================


#endif