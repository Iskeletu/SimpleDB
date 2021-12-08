/*
File in work
*/


//Libraries
#include <filesystem>
#include <string>


//Header files
#include "tests.h"
#include "dbhandler.h"


//=====================Namespace====================
using namespace std;
namespace fs = std::filesystem;
//==================================================



TEST_CASE("db-create", "[createEmptyDB]")
{

    SECTION("Default settings")
    {
        string dbname("myemptydb");
        Database db(Database::CreateDatabase(dbname));

        // We know we have been successful when:-
        // 1. We have a valid database reference returned
        //   - No test -> The above would have errored
        // 2. The DB has a folder that exists on the file system
        cout<<"checking db directory"<<endl;
        REQUIRE(fs::is_directory(fs::status(db.GetDirectory())));
        // C++17 Ref: https://en.cppreference.com/w/cpp/filesystem/is_directory

        // 3. The database folder is empty (no database files yet)
        const auto& p = fs::directory_iterator(db.GetDirectory());
        REQUIRE(p == end(p)); // Should have an empty .indexes folder

        db.Erase();
        REQUIRE(!fs::exists(fs::status(db.GetDirectory())));
    }
}