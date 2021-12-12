/*
Test File - Key-Value.

This file is resposible for database
key-value test cases.
*/


//Libraries
#include<string>


//Header Files
#include "catch.hpp"
#include "dbhandler.h"
#include "datacell.h"


//==================Key-Value Test==================
TEST_CASE("Store and retrive a value", "[setKeyValue, getKeyValue]")
{ //Creates a database, store a value and get the value then it compares both and deletes the database.
    SECTION("Basic insert and search")
    {
        std::string dbname("test-db");
        Database db(SimpleDB::CreateDB(dbname));                                //Creates "test-db" database.
        std::string value = "Teste-Value";

        //Creates a insertion cell with predetermined values.
        Datacell testcell = Datacell::CreateDatacell(db.NewUniqueKey(), 1, value);

        // We know we have been successful when:-
        // 1. The retrieved value is the same as the local stored value
        db.InsertKeyValue(&testcell);                                           //Inserts a "value" value into the test database.
        db.SearchKeyValue(&testcell);                                           //Reads value from database to cell.
        REQUIRE(value == testcell.GetValue());                                  //Checks if value stored in database matches with local string values.

        db.Erase();                                                             //Deletes previously created "test-db" database.
    }
}
//==================================================


//==================Key-Value Test==================
TEST_CASE("Store and remove a value", "[setKeyValue, getKeyValue]")
{ //Creates a database, store a value and get the value then it compares both and deletes the database.
    SECTION("Basic inset and delete")
    {
        std::string dbname("test-db");
        Database db(SimpleDB::CreateDB(dbname));                                //Creates "test-db" database.
        std::string value = "Teste-Value";

        //Creates a insertion cell with predetermined values.
        Datacell testcell = Datacell::CreateDatacell(db.NewUniqueKey(), 1, value);

        // We know we have been successful when:-
        // 1. The retrieved value is the same as the stored value
        db.InsertKeyValue(&testcell);                                           //Inserts a "value" value into the test database.
        db.SearchKeyValue(&testcell);                                           //Reads value from database to cell.
        REQUIRE(value == testcell.GetValue());                                  //Checks if value stored in database matches with local string values.

        db.Erase();                                                             //Deletes previously created "test-db" database.
    }
}
//==================================================


//==================Key-Value Test==================
TEST_CASE("Store and update a value", "[setKeyValue, getKeyValue]")
{ //Creates a database, store a value and get the value then it compares both and deletes the database.
    SECTION("Basic insert and update")
    {
        std::string dbname("test-db");
        Database db(SimpleDB::CreateDB(dbname));                                //Creates "test-db" database.
        std::string value = "Teste-Value";

        //Creates a insertion cell with predetermined values.
        Datacell testcell = Datacell::CreateDatacell(db.NewUniqueKey(), 1, value);

        //Inserts datacell to database and change its local value.

        //Updates key in database file to recently edited datacell.

        // We know we have been successful when:-
        // 1. The retrieved value is the same as the local stored value
        db.InsertKeyValue(&testcell);                                           //Inserts a "value" value into the test database.
        db.SearchKeyValue(&testcell);                                           //Reads value from database to cell.
        REQUIRE(value == testcell.GetValue());                                  //Checks if value stored in database matches with local string values.

        db.Erase();                                                             //Deletes previously created "test-db" database.
    }
}
//==================================================