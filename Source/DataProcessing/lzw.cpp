/*
LZW compression/decompression file (.lzw).

Responsible for LZW algorithm compression
and decompression.
*/


//Libraries
#include <string>
#include <filesystem>


//Header Files
#include "lzw.h"


//=====================Namespace====================
namespace fs = std::filesystem;
//==================================================


//==================LZW Compression=================
fs::path lzw::compress(std::string db_path)
{ //
    fs::path compressed_file_path((db_path.substr(0, db_path.size()-3)) + ".lzw");

    //TODO

    return compressed_file_path;
}
//==================================================


//=================LZW Decompression================
void lzw::decompress(std::string compressed_file_path)
{ //
    //TODO
}
//==================================================