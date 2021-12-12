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
    /*
    We know we have been successfull if:

    1- The searched value matches with the local
    comparison variable.
    */
    SECTION("Basic insert and search")
    {
        std::string dbname("test-db");
        Database db(SimpleDB::CreateDB(dbname));                                //Creates "test-db" database.

        //Defines local value for comparison.
        std::string value = "Tested-Value";

        //Creates a insertion cell with predetermined values.
        Datacell testcell = Datacell::CreateDatacell(db.NewUniqueKey(), 1, value);

        db.InsertKeyValue(&testcell);                                           //Inserts datacell to database.
        testcell.UpdateValues(testcell.GetKey(), 1, "null");                    //Changes local datacell value to "null".
        db.SearchKeyValue(&testcell);                                           //Reads value from database to cell.

        REQUIRE(value == testcell.GetValue());                                  //Checks if value stored in database matches with local comparison variable.

        db.Erase();                                                             //Deletes previously created "test-db" database.
    }
}
//==================================================


//==================Key-Value Test==================
TEST_CASE("Store and remove a value", "[setKeyValue, getKeyValue]")
{ //Creates a database, store a value and get the value then it compares both and deletes the database.
    /*
    We know we have been successfull if:

    1 - The search function returns true before
    removing the key. (That means the key pro-
    vided for search is valid).

    2 - The search function returns false after
    removing the key (That means no key stored
    matches with the key value provided for the
    search).
    */
    SECTION("Basic insert and delete")
    {
        std::string dbname("test-db");
        Database db(SimpleDB::CreateDB(dbname));                                //Creates "test-db" database.

        //Creates a datacell for insertion.
        Datacell testcell = Datacell::CreateDatacell(db.NewUniqueKey(), 1, "Tested-Value");

        db.InsertKeyValue(&testcell);                                           //Inserts the datacell to database.

        REQUIRE(db.SearchKeyValue(&testcell));                                  //Checks if search return is true.
        SimpleDB::RemoveDBKey(&db, &testcell);                                  //Removes key from database.
        REQUIRE(!(db.SearchKeyValue(&testcell)));                               //Checks if search return is false.

        db.Erase();                                                             //Deletes previously created "test-db" database.
    }
}
//==================================================


//==================Key-Value Test==================
TEST_CASE("Store and update a value", "[setKeyValue, getKeyValue]")
{ //Creates a database, store a value and get the value then it compares both and deletes the database.
    /*
    We know we have been successfull if:

    1 - the updated value matches with the local 
    comparison variable used for the creation of
    the second datacell.
    */
    SECTION("Basic insert and update")
    {
        std::string dbname("test-db");
        Database db(SimpleDB::CreateDB(dbname));                                //Creates "test-db" database.

        //Defines local values for comparison.
        std::string value1 = "Tested-Value";
        std::string value2 = "Untested-Value";

        //Creates a two datacells with differnet predetermined values.
        Datacell testcell = Datacell::CreateDatacell(db.NewUniqueKey(), 1, value1);
        Datacell untestedcell = Datacell::CreateDatacell(testcell.GetKey(), 1, value2);

        db.InsertKeyValue(&testcell);                                           //Inserts the first datacell to database.
        SimpleDB::UpdateDBKey(&db, &testcell, &untestedcell);                   //Updates key in database file to match the value stored in the second datacell.
        db.SearchKeyValue(&testcell);                                           //Reads value from database to the first datacell.

        REQUIRE(testcell.GetValue() == untestedcell.GetValue());                //Checks if values match.

        db.Erase();                                                             //Deletes previously created "test-db" database.
    }
}
//==================================================