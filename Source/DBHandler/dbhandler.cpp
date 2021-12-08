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
using namespace std;
namespace fs = std::filesystem;
//==================================================


//=======================TODO=======================
Database::Database(string dbname, string path)
{

}
//==================================================


//==================Database Crator=================
Database Database::CreateDatabase(string dbname)
{
    return Database("test", "test");
}
//==================================================


string Database::GetDirectory(void)
{
    return("test");
}

