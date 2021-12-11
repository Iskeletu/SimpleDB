/*
Quick-Sort algorithm file.

This file is resposible for sorting Index.
This is a quicksort implementantion for
sorting the database index class.
*/


//Libraries
#include <vector>


//Header Files
#include "quicksort.h"


//===================Swap Function==================
void Swap(Index* index1, Index* index2)
{ //Swaps two indices within the index vector.
//Slave function to "Partition".
    Index* temp = index1;
    index1 = index2;
    index2 = temp;
    temp = nullptr;
    free(temp);
}
//==================================================


//================Partition Function================
int Partition(std::vector<Index>* indexvector, int start, int end)
{ //!describe function
//Slave function to "qcks::QuickSort".
	int pivot = end;
	int j = start;

	for(int i = start; i < end; i++)
    {
		if((*indexvector)[i].GetSortingKey() < (*indexvector)[pivot].GetSortingKey())
        {
			Swap(&((*indexvector)[i]), &((*indexvector)[j]));
			++j;
		}
	}
	Swap(&((*indexvector)[j]), &((*indexvector)[pivot]));

	return j;
}
//==================================================


//====================Quick Sort====================
void qcks::QuickSort(std::vector<Index>* dbindex, int start, int end)
{ //Quick-Sort algorithm implementation.
	if(start<end)
    {
		int p = Partition(dbindex, start, end);
		qcks::QuickSort(dbindex, start, (p-1));
		qcks::QuickSort(dbindex, (p+1), end);
	}
	
}
//==================================================