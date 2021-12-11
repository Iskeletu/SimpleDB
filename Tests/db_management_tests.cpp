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

#include<iostream>
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
        std::vector<std::string> files;

        for (const auto & entry : fs::directory_iterator(path))
        { //Gets the list of files within the current directory
            files.push_back(entry.path());
            std::cout << entry.path() << std::endl;
        }
        fs::path temp1(db.GetDirectory() + "/" + dbname + ".db");               //!This will not work on windows.
        fs::path temp2;

        if(files.size() == 1)
        { //Only gives "temp2" a value if there is only a single file in the directory.
            temp2 = fs::path(files[0]);
        }
        
        REQUIRE(temp1 == temp2);                                                //Checks if db2 database directory has only its .db file.

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
        std::vector<std::string> files;

        for (const auto & entry : fs::directory_iterator(path))
        { //Gets the list of files within the current directory
            files.push_back(entry.path());
            std::cout << entry.path() << std::endl;
        }
        fs::path temp1(db2.GetDirectory() + "/" + dbname + ".db");              //!This will not work on windows.
        fs::path temp2;

        if(files.size() == 1)
        { //Only gives "temp2" a value if there is only a single file in the directory.
            temp2 = fs::path(files[0]);
        }
        
        REQUIRE(temp1 == temp2);                                                //Checks if db2 database directory has only its .db file.

        //4. The database folder does not exist after getting deleted.
        db2.Erase();                                                            //Deletes test database via db2 reference.
        REQUIRE(!fs::exists(fs::status(db.GetDirectory())));                    //Check if db2 database direcoty does not exist.
    }
}
//==================================================