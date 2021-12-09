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



TEST_CASE("Crate a database", "[CreateEmptyDB]")
{
    SECTION("Default settings")
    {
        string dbname("test-db");
        Database db(SimpleDB::CreateDB(dbname));

        //We know we have been successful when:-
        //1. We have a valid database reference returned.
        //  - No test -> The above would have errored.
        //2. The database has a folder that exists on the file system.
        REQUIRE(fs::is_directory(fs::status(db.GetDirectory())));

        //3. The database folder is empty (no database files yet).
        const auto &path = fs::directory_iterator(db.GetDirectory());
        REQUIRE(path == end(path));

        //4. The database folder does not exist after getting deleted.
        db.Erase();
        REQUIRE(!fs::exists(fs::status(db.GetDirectory())));
    }
}

TEST_CASE("Load an existing database", "[LoadDB]")
{
    SECTION("Default settings")
    {
        string dbname("test-db");
        Database db(SimpleDB::CreateDB(dbname));

        Database db2(SimpleDB::LoadDB(dbname));

        //We know we have been successful when:-
        //1. We have a valid database reference returned.
        //  - No test -> The above would have errored.
        //2. The database has a folder that exists on the file system.
        REQUIRE(fs::is_directory(fs::status(db2.GetDirectory())));

        //3. The database folder is empty (no database files yet).
        const auto &path = fs::directory_iterator(db2.GetDirectory());
        REQUIRE(path == end(path));

        //Deletes test database
        db2.Erase();
        REQUIRE(!fs::exists(fs::status(db.GetDirectory())));
    }
}