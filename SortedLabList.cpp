//*******************************************************
// Implementation file SortedLabListP.cpp for the ADT list.
// Pointer-based implementation.
//*******************************************************
#include "SortedLabList.h"     // header file
#include <cstddef>        // for NULL
#include <cassert>        // for assert()

SortedListClass::SortedListClass()	  // Default Constructor
	: size(0), head(NULL)
{
}


SortedListClass::~SortedListClass()	// Destructor
{
	bool success;

	while (!isEmpty())
	{
		success = remove(1);  // Repeatedly delete item 1
	}
}


bool SortedListClass::isEmpty() const
{
	return bool(size == 0);
}


int SortedListClass::getLength() const
{
	return size;
}


// Copy Constructor: Make DEEP copy
SortedListClass::SortedListClass(const SortedListClass& existingList)
	: size(existingList.size)
{
	if (existingList.head == NULL)
		head = NULL;  // original list is empty

	else
	{
		// copy first node
		head = new ListNode;
		assert(head != NULL);  // check allocation

		head->item = existingList.head->item;

		// copy rest of list
		ListNode *newPtr = head;  // new list pointer


		// newPtr points to last node in new list
		// origPtr points to nodes in original list
		for (ListNode *origPtr = existingList.head->next;
			origPtr != NULL;
			origPtr = origPtr->next)
		{
			newPtr->next = new ListNode;   // link new node to end of list
			assert(newPtr->next != NULL);
			newPtr = newPtr->next;

			newPtr->item = origPtr->item;  // copy the data
			newPtr->next = NULL;
		}
	}
}

// assignment operator: Make DEEP copy
SortedListClass& SortedListClass::operator=(const SortedListClass& rhs)
{
	// TODO
	// Similar to Copy Constructor, except
	// - Avoid self-assignments such as  “X = X;”
	// - Delete existing this-instance content before 
	//   making this-instance a copy of the rhs instance
	if (this != &rhs)
	{
		delete head;	//delete existing this-instance content before making copy of rhs

		if (rhs.head == NULL)
			head = NULL;  // original list is empty

		else
		{
			// copy first node
			head = new ListNode;
			assert(head != NULL);  // check allocation

			head->item = rhs.head->item;

			// copy rest of list
			ListNode *newPtr = head;  // new list pointer


			// newPtr points to last node in new list
			// origPtr points to nodes in original list
			for (ListNode *origPtr = rhs.head->next;
				origPtr != NULL;
				origPtr = origPtr->next)
			{
				newPtr->next = new ListNode;   // link new node to end of list
				assert(newPtr->next != NULL);
				newPtr = newPtr->next;

				newPtr->item = origPtr->item;  // copy the data
				newPtr->next = NULL;
			}
		}

	}

	return(*this);
}


// ----------------------------------------------------------------------
// Locates a specified node in a linked list.
// Precondition: position is the number of the desired node.
// Postcondition: Returns a pointer to the desired node.
// If position < 1 or position > size (the number of nodes in the list),
//    returns NULL.
// ----------------------------------------------------------------------

SortedListClass::ListNode *SortedListClass::ptrTo(int position) const
{
	if ((position < 1) || (position > size))
		return NULL;

	else  // count from the beginning of the list
	{
		ListNode *cur = head;

		for (int skip = 1; skip < position; ++skip)
			cur = cur->next;

		return cur;
	}
}


bool SortedListClass::retrieve(int position, ListItemType& dataItem) const
{
	bool success = bool((position >= 1) && (position <= size));

	if (success)
	{
		// get pointer to node, then data in node
		ListNode *cur = ptrTo(position);

		dataItem = cur->item;
	}

	return(success);
}



bool SortedListClass::insert(ListItemType& newItem)
{
	//TODO
	//use the by position insert example...but instead just find the right positioin to insert this newItem.

	ListNode *newPtr = new ListNode;	//create new node
	if (newPtr == NULL)
	{
		//throw Exception("List Exception: insert cannot alocate memory");
	}
	else
	{
		size++; //increment size
		newPtr->item = newItem;	//stores the value of newItem in the item field of newPtr

		if (head == NULL)
		{
			//insert node at beginning of list
			newPtr->next = head;
			head = newPtr;
		}
		else
		{
			//find position to insert newItem
			ListNode *cur = head;	//start pointer at head to traverse
			int index = 1;	//keeping track of index
			while (cur->item < newItem)	//while current is less than in value of newItem...find position just after where to insert
			{
				cur = cur->next;	//increment cur
				index++;	//increment index 
			}

			ListNode *prev = ptrTo(index - 1);	//set previous to point to node before where to insert newItem
			newPtr->next = prev->next;	//link new pointer's next to the previous's next
			prev->next = newPtr;	//link previous's next to connect to newPtr
		}
	}

	return true;
}


bool SortedListClass::remove(int position)
{
	ListNode *cur;

	bool success = bool((position >= 1) && (position <= size));

	if (success)
	{
		--size;

		if (position == 1)
		{
			// delete the first node from the list
			cur = head;  // save pointer to node
			head = head->next;
		}

		else
		{
			ListNode *prev = ptrTo(position - 1);

			// delete the node after the node
			//    to which prev points

			cur = prev->next;  // save pointer to node
			prev->next = cur->next;
		}

		// return node to system
		cur->next = NULL;	// safety - remove node from list
		delete cur;
		cur = NULL; 		// safety
	}

	return(success);
}

int SortedListClass::find(ListItemType& dataItem) const
{
	return 0;
}
