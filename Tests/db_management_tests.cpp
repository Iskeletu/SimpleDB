/*
Test File - DB Managment.

This file is resposible for database
management test cases.
*/


//Libraries
#include <string>
#include <filesystem>


//Header Files
#include "tests.h"
#include "dbhandler.h"


//=====================Namespace====================
namespace fs = std::filesystem;
//==================================================


//================Create-Delete Test================
TEST_CASE("Create and delete a database", "[CreateDatabase, DeleteDatabase]")
{ //Creates a database, checks if it exists then deletes and confirm it does not exist anymore.
    SECTION("Default settings")
    {
        std::string dbname("test-db");
        Database db(SimpleDB::CreateDB(dbname));                                //Creates "test-db" database.

        //We know we have been successful when:-
        //1. We have a valid database reference returned.
        //  - No test -> The above would have errored.
        //2. The database has a folder that exists on the file system.
        REQUIRE(fs::is_directory(fs::status(db.GetDirectory())));               //Checks if database directory exists.

        //3. The database folder has a "dbname".db file.
        const auto &path = fs::directory_iterator(db.GetDirectory());
        REQUIRE(path == end(path));                                             //Checks if database folder has a "dbname".db file. TODO

        //4. The database folder does not exist after getting deleted.
        db.Erase();                                                             //Deletes previously created "test-db" database.
        REQUIRE(!fs::exists(fs::status(db.GetDirectory())));                    //Checks if database directory does not exist.
    }
}
//==================================================


//====================Load Test====================
TEST_CASE("Load an existing database", "[LoadDatabase]")
{ //Creates a database, load into a second reference, checks the database exitence then deletes and confirm it does not exist anymore.
    SECTION("Default settings")
    {
        std::string dbname("test-db");
        Database db(SimpleDB::CreateDB(dbname));                                //Creates "test-db" database.
        Database db2(SimpleDB::LoadDB(dbname));                                 //Load previouly created "test-db" database to db2.

        //We know we have been successful when:-
        //1. We have a valid database reference returned.
        //  - No test -> The above would have errored.
        //2. The database has a folder that exists on the file system.
        REQUIRE(fs::is_directory(fs::status(db2.GetDirectory())));              //Checks if db2 database directory exists.

        //3. The database folder is empty (no database files yet).
        const auto &path = fs::directory_iterator(db2.GetDirectory());
        REQUIRE(path == end(path));                                             //Checks if db2 database directory is empty.

        //4. The database folder does not exist after getting deleted.
        db2.Erase();                                                            //Deletes test database via db2 reference.
        REQUIRE(!fs::exists(fs::status(db.GetDirectory())));                    //Check if db2 database direcoty does not exist.
    }
}
//==================================================