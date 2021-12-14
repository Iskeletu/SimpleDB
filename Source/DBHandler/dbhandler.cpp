/*
SimpleDB lib.

Intermediary between the functions of the
database and the rest of the program.

Handles calls to database functions so other files
don't have to do it directly and cause errors.

commandhandler.cpp is dependant on this file.
*/


//Libraries
#include <string>
#include <vector>


//Header Files
#include "dbhandler.h"
#include "index.h"
#include "screens.h"
#include "huffman.h"
#include "lzw.h"


//=================SimpleDB Creator=================
Database dbh::CreateDB(std::string& dbname)
{ //Calls for CreateDatabase function from database.h.
    return Database::CreateDatabase(dbname);
}
//==================================================


//==================SimpleDB Loader=================
Database dbh::LoadDB(std::string& dbname)
{ //Calls for LoadDatabase function from database.h.
    return Database::LoadDatabase(dbname);
}
//==================================================


//================SimpleDB Key Remover==============
bool dbh::RemoveDBKey(Database* db, Datacell* existingcell)
{ //Calls for key removal from database file. 
    return Database::RemoveKeyValue(db, existingcell);
}
//==================================================


//================SimpleDB Key Updater==============
bool dbh::UpdateDBKey(Database* db, Datacell* oldcell, Datacell* newcell)
{ //Calls for key removal from database file then inserts the same key with a different value.
    bool success = Database::RemoveKeyValue(db, oldcell);

    if(success)
    {
        db->InsertKeyValue(newcell);
    }

    return success;
}
//==================================================


//===============SimpleDB List Printer==============
bool dbh::PrintList(Database* db, int value, int print_type, int operator_type)
{ //Selects and prints all data with desired Sorting key value and prints to screen.
    bool printed = false;
    int dbsize = db->GetSize();
    std::vector<Index>* index = db->GetIndex();
    Datacell printcell = Datacell::CreateDatacell("null", 0, "null");
    std::string temp_string;
    int temp_sorting_key;

    if(dbsize > 0)
    { //Searches only if there is data stored in the database.
        switch(print_type)
        {
            /*
            Type 1 = Prints in normal order.
            Type 2 = Printes in reverse order.
            */
            case 1:
                switch(operator_type)
                {
                    /*
                    Type 1 = Operator '='.
                    Type 2 = Operator '>'.
                    Type 3 = Operator '<'.
                    Type 4 = Operator '>='.
                    Type 5 = Operator '<='.
                    */
                    case 1:
                        for(int i = 1; i < dbsize+1; i++)
                        {
                            temp_sorting_key = (*index)[i].GetSortingKey();
                            
                            if(value < temp_sorting_key)
                            { //Index value is out of range expression.
                                break;
                            }
                            else if(value == temp_sorting_key)
                            { //Index sorting key value matches with the desired sorting key range expression.
                                temp_string = ("key_" + std::to_string((*index)[i].GetKey()));
                                printcell.UpdateValues(temp_string, 0, "null");
                                db->SearchKeyValue(&printcell);

                                screens::PrintDatacell(nullptr, &printcell, 0);

                                printed = true;
                            }
                        }
                    break;

                    case 2:
                        for(int i = 1; i < dbsize+1; i++)
                        {
                            temp_sorting_key = (*index)[i].GetSortingKey();

                            if(value < temp_sorting_key)
                            { //Index sorting key value matches with the desired sorting key range expression.
                                temp_string = ("key_" + std::to_string((*index)[i].GetKey()));
                                printcell.UpdateValues(temp_string, 0, "null");
                                db->SearchKeyValue(&printcell);

                                screens::PrintDatacell(nullptr, &printcell, 0);

                                printed = true;
                            }
                        }
                    break;

                    case 3:
                        for(int i = 1; i < dbsize+1; i++)
                        {
                            temp_sorting_key = (*index)[i].GetSortingKey();

                            if(value <= temp_sorting_key)
                            { //Index value is out of range expression.
                                break;
                            }
                            else if(value > temp_sorting_key)
                            { //Index sorting key value matches with the desired sorting key range expression.
                                temp_string = ("key_" + std::to_string((*index)[i].GetKey()));
                                printcell.UpdateValues(temp_string, 0, "null");
                                db->SearchKeyValue(&printcell);

                                screens::PrintDatacell(nullptr, &printcell, 0);

                                printed = true;
                            }
                        }
                    break;

                    case 4:
                        for(int i = 1; i < dbsize+1; i++)
                        {
                            temp_sorting_key = (*index)[i].GetSortingKey();

                            if(value <= temp_sorting_key)
                            { //Index sorting key value matches with the desired sorting key range expression.
                                temp_string = ("key_" + std::to_string((*index)[i].GetKey()));
                                printcell.UpdateValues(temp_string, 0, "null");
                                db->SearchKeyValue(&printcell);

                                screens::PrintDatacell(nullptr, &printcell, 0);

                                printed = true;
                            }
                        }
                    break;

                    case 5:
                        for(int i = 1; i < dbsize+1; i++)
                        {
                            temp_sorting_key = (*index)[i].GetSortingKey();

                            if(value < temp_sorting_key)
                            { //Index value is out of range expression.
                                break;
                            }
                            else if(value >= temp_sorting_key)
                            { //Index sorting key value matches with the desired sorting key range expression.
                                temp_string = ("key_" + std::to_string((*index)[i].GetKey()));
                                printcell.UpdateValues(temp_string, 0, "null");
                                db->SearchKeyValue(&printcell);

                                screens::PrintDatacell(nullptr, &printcell, 0);

                                printed = true;
                            }
                        }
                    break;
                }
            break;
            
            case 2:
                switch(operator_type)
                {
                    /*
                    Type 1 = Operator '='.
                    Type 2 = Operator '>'.
                    Type 3 = Operator '<'.
                    Type 4 = Operator '>='.
                    Type 5 = Operator '<='.
                    */
                    case 1:
                        for(int i = dbsize-1; i > 0; i--)
                        {
                            temp_sorting_key = (*index)[i].GetSortingKey();
                            
                            if(value > temp_sorting_key)
                            { //Index value is out of range expression.
                                break;
                            }
                            else if(value == temp_sorting_key)
                            { //Index sorting key value matches with the desired sorting key range expression.
                                temp_string = ("key_" + std::to_string((*index)[i].GetKey()));
                                printcell.UpdateValues(temp_string, 0, "null");
                                db->SearchKeyValue(&printcell);

                                screens::PrintDatacell(nullptr, &printcell, 0);

                                printed = true;
                            }
                        }
                    break;

                    case 2:
                        for(int i = dbsize-1; i > 0; i--)
                        {
                            temp_sorting_key = (*index)[i].GetSortingKey();

                            if(value >= temp_sorting_key)
                            { //Index value is out of range expression.
                                break;

                            }
                            else if(value < temp_sorting_key)
                            { //Index sorting key value matches with the desired sorting key range expression.
                                temp_string = ("key_" + std::to_string((*index)[i].GetKey()));
                                printcell.UpdateValues(temp_string, 0, "null");
                                db->SearchKeyValue(&printcell);

                                screens::PrintDatacell(nullptr, &printcell, 0);

                                printed = true;
                            }
                        }
                    break;

                    case 3:
                        for(int i = dbsize-1; i > 0; i--)
                        {
                            temp_sorting_key = (*index)[i].GetSortingKey();

                            if(value > temp_sorting_key)
                            { //Index sorting key value matches with the desired sorting key range expression.
                                temp_string = ("key_" + std::to_string((*index)[i].GetKey()));
                                printcell.UpdateValues(temp_string, 0, "null");
                                db->SearchKeyValue(&printcell);

                                screens::PrintDatacell(nullptr, &printcell, 0);

                                printed = true;
                            }
                        }
                    break;

                    case 4:
                        for(int i = dbsize-1; i > 0; i--)
                        {
                            temp_sorting_key = (*index)[i].GetSortingKey();

                            if(value > temp_sorting_key)
                            { //Index value is out of range expression.
                                break;

                            }
                            else if(value <= temp_sorting_key)
                            { //Index sorting key value matches with the desired sorting key range expression.
                                temp_string = ("key_" + std::to_string((*index)[i].GetKey()));
                                printcell.UpdateValues(temp_string, 0, "null");
                                db->SearchKeyValue(&printcell);

                                screens::PrintDatacell(nullptr, &printcell, 0);

                                printed = true;
                            }
                        }
                    break;

                    case 5:
                        for(int i = dbsize-1; i > 0; i--)
                        {
                            temp_sorting_key = (*index)[i].GetSortingKey();

                            if(value >= temp_sorting_key)
                            { //Index sorting key value matches with the desired sorting key range expression.
                                temp_string = ("key_" + std::to_string((*index)[i].GetKey()));
                                printcell.UpdateValues(temp_string, 0, "null");
                                db->SearchKeyValue(&printcell);

                                screens::PrintDatacell(nullptr, &printcell, 0);

                                printed = true;
                            }
                        }
                    break;
                }
            break;
        }
    }

    return printed;
}
//==================================================


//===============Database Compression===============
bool dbh::CompressDatabase(Database* db, int* type)
{ //TODO
    bool is_successful = false;

    switch(*type)
    {
        case 1:
            huffman::compress(db->GetDirectory());
        break;

        case 2:
            lzw::compress(db->GetDirectory());
        break;
    }

    return is_successful;
}
//==================================================


//==============Database Decompression==============
bool dbh::DecompressDatabase(Database* db, int* type)
{ //TODO
    bool is_successful = false;

    switch(*type)
    {
        case 1:
            huffman::decompress(db->GetDirectory());
        break;

        case 2:
            lzw::decompress(db->GetDirectory());
        break;
    }

    *db = Database::LoadDatabase(db->GetName());

    return is_successful;
}
//==================================================