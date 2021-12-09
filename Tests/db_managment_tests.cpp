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
        string dbname("test-db");
        Database db(Database::CreateDatabase(dbname));

        //We know we have been successful when:-
        //1. We have a valid database reference returned.
        //  - No test -> The above would have errored.
        //2. The database has a folder that exists on the file system.
        REQUIRE(fs::is_directory(fs::status(db.GetDirectory())));

        //3. The database folder is empty (no database files yet).
        const auto &path = fs::directory_iterator(db.GetDirectory());
        REQUIRE(path == end(path));

        //4. The database folde does not exist after getting deleted.
        db.Erase();
        REQUIRE(!fs::exists(fs::status(db.GetDirectory())));
    }
}