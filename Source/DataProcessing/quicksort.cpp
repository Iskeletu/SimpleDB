/*
Quick-Sort algorithm file.

This file is resposible for sorting Index.
This is a quicksort implementantion for
sorting the database index class.

The algoriths was changed to sort either
by sorting key values or by main key values.
*/


//Libraries
#include <vector>


//Header Files
#include "quicksort.h"


//====================Quick Sort====================
/*
Everything bellow is standard recursive quicksort 
implementaion for C++ with slight changes.
*/
int PartitionSortingKey(std::vector<Index>* indexvector, int start, int end)
{ //Part of Quick-sort implementation, sorting key version.
//Slave function to "QuickSortSortingKey".
	int pivot = end;
	int j = start;

	for(int i = start; i < end; i++)
    {
		if((*indexvector)[i].GetSortingKey() < (*indexvector)[pivot].GetSortingKey())
        {
			std::swap((*indexvector)[i], (*indexvector)[j]);
			++j;
		}
	}
	std::swap((*indexvector)[j], (*indexvector)[pivot]);

	return j;
}
int PartitionMainKey(std::vector<Index>* indexvector, int start, int end)
{ //Part of Quick-sort implementation, main key version.
//Slave function to "QuickSortMainKey".
	int pivot = end;
	int j = start;

	for(int i = start; i < end; i++)
    {
		if((*indexvector)[i].GetKey() < (*indexvector)[pivot].GetKey())
        {
			std::swap((*indexvector)[i], (*indexvector)[j]);
			++j;
		}
	}
	std::swap((*indexvector)[j], (*indexvector)[pivot]);

	return j;
}
void QuickSortSortingKey(std::vector<Index>* indexvector, int start, int end)
{ //Quick-Sort algorithm implementation.
//Slave function to "qckt::Sort".
	if(start < end)
    {
		int p = PartitionSortingKey(indexvector, start, end);
		QuickSortSortingKey(indexvector, start, (p-1));
		QuickSortSortingKey(indexvector, (p+1), end);
	}
}
void QuickSortMainKey(std::vector<Index>* indexvector, int start, int end)
{ //Quick-Sort algorithm implementation.
//Slave function to "qckt::Sort".
	if(start < end)
    {
		int p = PartitionMainKey(indexvector, start, end);
		QuickSortMainKey(indexvector, start, (p-1));
		QuickSortMainKey(indexvector, (p+1), end);
	}
}
//==================================================


//===============Sorting Main Function==============
void qcks::Sort(std::vector<Index>* dbindex, int type)
{ //Calls for different types of sorting methods depending on wich type of sorting was called.
	if(dbindex->size() > 2)
	{ //Does nothing if vector does not have more than one member (header is an exception).
		switch(type)
		{
			/*
			Type 1: Function was called for sorting vector by main key.
			Type 2: Function was called for sorting vector by Sorting key.
			*/
			case 1:
				QuickSortMainKey(dbindex, 1, (dbindex->size() - 1));
			break;

			case 2:
				QuickSortSortingKey(dbindex, 1, (dbindex->size() - 1));
			break;
		}
	}
}
//==================================================