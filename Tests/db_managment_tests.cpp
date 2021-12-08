/*
File in work
*/


//Libraries
#include <filesystem>
#include <string>


//Header file
#include "tests.h"


//=====================Namespace====================
using namespace std;
namespace fs = std::filesystem;
//==================================================



TEST_CASE("db-create","[createEmptyDB]")
{

    SECTION("Default settings")
    {
        std::string dbname("myemptydb");
        Database db(Database::CreateDatabase(dbname));

        // We know we have been successful when:-
        // 1. We have a valid database reference returned
        //   - No test -> The above would have errored
        // 2. The DB has a folder that exists on the file system
        std::cout << "checking db directory" << std::endl;
        REQUIRE(fs::is_directory(fs::status(db.GetDirectory())));
        // C++17 Ref: https://en.cppreference.com/w/cpp/filesystem/is_directory

        // 3. The database folder is empty (no database files yet)
        const auto& p = fs::directory_iterator(db.GetDirectory());
        REQUIRE(p == end(p)); // Should have an empty .indexes folder
    }
}