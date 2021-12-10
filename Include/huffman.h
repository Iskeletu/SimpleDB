//Header definition
#ifndef huffman_h_
#define huffman_h_


//Libraries
#include <filesystem>


//Dependencies
#include "dbhandler.h"


//=====================Namespace====================
namespace fs = std::filesystem;
//==================================================


//=====================Functions====================
namespace huffman
{
    bool    compress        (fs::path path);
    bool    decompress      (fs::path path);
};
//==================================================


#endif