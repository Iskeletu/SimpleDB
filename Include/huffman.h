//Header definition
#ifndef huffman_h_
#define huffman_h_


//Libraries
#include <string>
#include <filesystem>


//=====================Namespace====================
namespace fs = std::filesystem;
//==================================================


//=====================Functions====================
namespace huffman
{
    fs::path    compress        (std::string db_path);
    void        decompress      (std::string compressed_file_path);
};
//==================================================


#endif