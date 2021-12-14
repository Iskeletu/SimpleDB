/*
Test File - DB Managment.

This file is resposible for database
management test cases.
*/


//Libraries
#include <string>
#include <vector>
#include <filesystem>


//Header Files
#include "tests.h"
#include "dbhandler.h"
#include "datacell.h"


//=====================Namespace====================
namespace fs = std::filesystem;
//==================================================


//===============Create & Delete Test===============
TEST_CASE("Create and delete a database", "[CreateDatabase, DeleteDatabase]")
{ //Creates a database, checks if it exists then deletes and confirm it does not exist anymore.
    /*
    We know we have been successfull if:

    1 - The database has a folder that exists
    on the file system.

    2 - The database folder has only one file.

    3 - The available file is the default
    "dbname".db file.

    4 - The database folder does not exist
    after calling "delete" method.
    */
    SECTION("Default settings")
    {
        std::string dbname("test-db");
        Database db(dbh::CreateDB(dbname));                                     //Creates "test-db" database.

        REQUIRE(fs::is_directory(fs::status(db.GetDirectory())));               //Checks if database directory exists.

        //Gets the list of files within the current directory
        const auto &path = fs::directory_iterator(db.GetDirectory());
        std::vector<std::string> files;
        for (const auto & entry : fs::directory_iterator(path))
        {
            files.push_back(entry.path());
        }

        fs::path dbpath(db.GetDirectory() + "/" + dbname + ".db");              //Manually sets a reference to test database file for comparison

        REQUIRE(files.size() == 1);                                             //Checks if there is onle one file in the directory.
        REQUIRE(files[0] ==  dbpath);                                           //Checks if the files is a "dbname".db file.

        db.Erase();                                                             //Deletes previously created "test-db" database.
        REQUIRE(!fs::exists(fs::status(db.GetDirectory())));                    //Checks if database directory does not exist.
    }
}
//==================================================


//====================Load Test====================
TEST_CASE("Load an existing database", "[LoadDatabase]")
{ //Creates a database, load into a second reference, checks the database exitence then deletes and confirm it does not exist anymore.
    /*
    We know we have been successfull if:

    1 - The loaded database has a valid re-
    ference to an existent file.

    2 - The database folder does not exist
    after calling "delete" method from the
    loaded database.
    */
    SECTION("Default settings")
    {
        std::string dbname("test-db");
        Database db(dbh::CreateDB(dbname));                                     //Creates "test-db" database.
        Database db2(dbh::LoadDB(dbname));                                      //Loads previouly created "test-db" database to db2.

        //Checks if db2 database file exists.
        REQUIRE(fs::exists(fs::status(db2.GetDirectory() + "/" + db2.GetName() + ".db")));

        db2.Erase();                                                            //Deletes test database via db2 reference.
        REQUIRE(!(fs::exists(fs::status(db2.GetDirectory()))));                 //Checks if database directory does not exist.
    }
}
//==================================================