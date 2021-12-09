/*
File in work.
*/


//Libraries
#incldue<string>


//Header files
#include "catch.hpp"
#include "dbhandler.h"


//==================Key-Value Test==================
TEST_CASE("Store and retrive a value", "[setKeyValue,getKeyValue]")
{ //Simple key-value store and retireve test
    SECTION("Basic set and get")
    {
        std::string dbname("test-db");
        Database db(SimpleDB::CreateDB(dbname));

        // We know we have been successful when:-
        // 1. The retrieved value is the same as the stored value
        std::string key("string");
        std::string value("defined_value");
        db.InsertKeyValue(key, value);
        REQUIRE(value == db.SearchKeyValue(key));

        db.Erase();
    }
}
//==================================================