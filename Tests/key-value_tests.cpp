//Libraries
#include <string>


//Header files
#include "tests.h"


//=====================Namespace====================
using namespace std;
//==================================================


//==================Key-Value Test==================
TEST_CASE("Store and retrive a value", "[setKeyValue,getKeyValue]")
{ //Simple key-value store and retireve test
    SECTION("Basic set and get")
    {
        string dbname("myemptydb");
        Database db(Database::CreateDatabase(dbname));

        // We know we have been successful when:-
        // 1. The retrieved value is the same as the stored value
        string key("string");
        string value("defined_value");

        db.InsertKeyValue(key, value);
        REQUIRE(value == db.SearchKeyValue(key));
    }
}
//==================================================