/*
File in work.
*/


//Libraries
#include <filesystem>


//Header Files
#include "dbhandler.h"
#include "huffman.h"
#include "lzw.h"


//=====================Namespace====================
//namespace db = Database;
//namespace fs = std::filesystem;
//==================================================


//=======================TODO=======================
Database::Database(std::string dbname, std::string path)
{

}
//==================================================


//==================Database Crator=================
Database Database::CreateDatabase(std::string dbname)
{
    return Database("test", "test");
}
//==================================================

