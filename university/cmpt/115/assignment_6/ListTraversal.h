//
// ListTraversal.h
// ListTraversal header file
//

#include "NodeList.h"

#ifndef _LISTTRAVERSAL_
#define _LISTTRAVERSAL_


struct ListTraversal {
	Node *nextNode;
};


// The interface (function prototypes for operations)

// This function creates a traversal for a given List.
//   Pre: rList is a reference to a list
//   Post: memory is allocated to store the Traversal
//   Return: a reference to the Traversal record
ListTraversal *CreateTraversal(List *rList);

// This function determines if there are more elements in the list to visit
//   Pre: rTrav is a reference to a List Traversal
//   Post: nothing
//   Return: true, if there are more elements to visit, and false otherwise
bool hasNext(ListTraversal *rTrav);

// This function returns the next element in the list to visit
//   Pre: rTrav is a reference to a List Traversal
//        This function should only be called if hasNext() is true!
//   Post: nothing
//   Return: an Element 
Element next(ListTraversal *rTrav);

// This function deallocates the memory associated with the given Traversal
//  Pre: rTrav is a reference to a Traversal
//  Post: rTrav no longer points to valid traversal
//  Return: Nothing
void DestroyTraversal(ListTraversal *rTrav);

#endif
