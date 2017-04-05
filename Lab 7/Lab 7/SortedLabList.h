// Written by: Charlie Ang	
// Date: 03/09/16
//*********************************************************
// Header file SortedLabList.h for the ADT list.
// Pointer-based implementation.
// The first "position" in a list is position = 1,
//   as implemented in the insert(), remove(), retrieve(),
//   and private ptrTo() methods.
//*********************************************************

//*********************************************************
// The "typedef" below must be configured for the type
//   of data stored in each node in the list
//*********************************************************
//typedef desired - type - of - list - item ListItemType;
typedef int ListItemType;

class SortedListClass
{
public:
	// constructors and destructor:
	SortedListClass();                    // default constructor
	~SortedListClass();                   // destructor

	SortedListClass(const SortedListClass& existingList);    // copy constructor
	SortedListClass& operator=(const SortedListClass& rhs);  // assignment operator

	// list operations:
	bool isEmpty() const;
	int  getLength() const;

	// Methods return true if successful, false otherwise
	bool insert(ListItemType& newItem);

	bool remove(int position);

	bool retrieve(int position, ListItemType& dataItem) const;

	//Find position of an dataItem in the list
	//Return -1 if item is not in the list
	int find(ListItemType& dataItem) const;

private:
	struct ListNode
	{
		ListItemType  item;
		ListNode     *next;
	};

	int       size;  // number of items in list
	ListNode *head;  // pointer to linked list of items

	ListNode *ptrTo(int position) const;
	// Returns a pointer to the node at position (1 .. k) in list
};

