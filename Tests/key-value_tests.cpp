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


//==================Key-Value Test==================
TEST_CASE("Store and retrive a value", "[setKeyValue, getKeyValue]")
{ //Creates a database, store a value and get the value then it compares both and deletes the database.
    SECTION("Basic set and get")
    {
        std::string dbname("test-db");
        Database db(SimpleDB::CreateDB(dbname));                                //Creates "test-db" database.

        // We know we have been successful when:-
        // 1. The retrieved value is the same as the stored value
        std::string key("defined_key");
        std::string value("defined_value");
        db.InsertKeyValue(key, value);                                          //Creates a "defined_key" key with "defined_value" value.
        REQUIRE(value == db.SearchKeyValue(key));                               //Checks if value stored in database matches with local string values.

        db.Erase();                                                             //Deletes previously created "test-db" database.
    }
}
//==================================================