/*
Huffman compression/decompression file (.hff).

Responsible for Huffman algorithm compression
and decompression.
*/


//Libraries
#include <string>
#include <filesystem>


//Header Files
#include "huffman.h"


//=====================Namespace====================
namespace fs = std::filesystem;
//==================================================


//===================Huffman Tree===================

//==================================================


//================Huffman Compression===============
fs::path huffman::compress(std::string db_path)
{ //
    fs::path compressed_file_path((db_path.substr(0, db_path.size()-3)) + ".hff");
    
    //TODO

    return compressed_file_path;
}
//==================================================


//===============Huffman Decompression==============
void huffman::decompress(std::string compressed_file_path)
{ //
    //TODO
}
//==================================================