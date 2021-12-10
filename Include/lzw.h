//Header definition
#ifndef lzw_h_
#define lzw_h_


//Libraries
#include <string>
#include <filesystem>


//=====================Namespace====================
namespace fs = std::filesystem;
//==================================================


//=====================Functions====================
namespace lzw
{
    fs::path    compress        (std::string db_path);
    void        decompress      (std::string compressed_file_path);
};
//==================================================


#endif