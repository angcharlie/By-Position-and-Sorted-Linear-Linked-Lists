// LabListRandom
// CSC 2430 Lab Assignment
// Written by: Charlie Ang	
// Date: 03/09/16

#include <iostream>
#include <iomanip>
#include <cstddef>
#include <limits>
using namespace std;

#include "LabListP.h"
#include "SortedLabList.h" 


void printListClass(char listname[], const ListClass& lst)
{
	cout << listname << ": " << lst.getLength() << " items" << endl;

	int numitems = lst.getLength();
	for (int i = 1; i <= numitems; ++i)
	{
		int val;
		if (lst.retrieve(i, val))
			cout << i << ": " << val << endl;
		else
			cout << "Cannot retrieve item from position " << i << endl;
	}
	cout << endl;
}

void printSortedListClass(char listname[], const SortedListClass& lst)
{
	cout << listname << ": " << lst.getLength() << " items" << endl;

	int numitems = lst.getLength();
	for (int i = 1; i <= numitems; ++i)
	{
		int val;
		if (lst.retrieve(i, val))
			cout << i << ": " << val << endl;
		else
			cout << "Cannot retrieve item from position " << i << endl;
	}
	cout << endl;
}

void printCorrelation(const ListClass& list, const SortedListClass& sortedList, char listname[], char sortedlistname[])
{
	cout << "Correlation between locations of items in " << listname << " and " << sortedlistname << endl;
	int numitems = list.getLength();	//number of items list has
	cout << fixed << showpoint;
	for (int i = 1; i <= numitems; i++)
	{
		int value;
		list.retrieve(i, value);	//retrieve value at i and store it into value variable 
		int corresponding;
		corresponding = sortedList.find(value); //saves index of value in corresponding 
		cout << listname << "[ " << setw(2) << i << "]" << " =    " << value << " --> " << sortedlistname << "[ " << setw(2) << corresponding << "]" << endl;
	}
}

int main()
{
	/////////////////////////////////////////////////
	// setup
	const int N = 10;			// number of items, used only to create initial list of values
	const int range = 101;		// value range. Set to INT_MAX for a list of values from 0 .. 32767

	// Prepare random number generator with initial seed value
	//    and discard the first few data items in the sequence
	srand(1);
	for (int i = 0; i < 5; ++i)
		rand();

	/////////////////////////////////////////////////
	// Greeting
	cout << "Linked List Lab: Implemented by Charlie Ang" << endl;
	cout << "Randomly generate list of " << N << " values and convert into a sorted list" << endl << endl;

	/////////////////////////////////////////////////
	// Create initial "by position" data value list
	ListClass listbyposition;

	for (int i = 1; i <= N; ++i)
	{
		int val = rand() % range;		// produce next random number value
		listbyposition.insert(i, val);  // Put val into list at position i
	}

	// Output initial data list
	printListClass("listbyposition", listbyposition);

	//Inserting value into the sorted list
	SortedListClass test;
	int value;
	for (int i = 1; i <= N; i++)
	{
		listbyposition.retrieve(i,value);	//retrieve the value from listbyposition 
		test.insert(value);	//insert value into the sorted list class
	}
	printSortedListClass("sortedlist", test);	//print out values of sorted list 

	//Printing correlation
	printCorrelation(listbyposition, test, "listbyposition", "sortedlist");

	cout << endl;	//spacing

	SortedListClass myList; //new sortedlistclass variable 
	myList = test;	//using assignment operator=()

	test.remove(1); //remove first item
	test.remove(1);	//remove second item
	int x = -10;
	myList.insert(x);	//insert -10

	cout << "Modified original sortedlist after removing the first two items:" << endl;
	printSortedListClass("sortedlist", test);

	cout << "Modified sortedlistcopy after inserting the value (-10):" << endl;
	printSortedListClass("sortedlistcopy", myList);

	system("pause");
	return(0);
}