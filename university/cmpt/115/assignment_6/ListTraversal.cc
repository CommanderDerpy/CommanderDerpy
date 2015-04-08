//
// ListTraversal.cc
// ListTraversal implementation file
//

#include <cstdlib>
#include <iostream>

#include "NodeList.h"
#include "ListTraversal.h"

using namespace std;


// This function creates a traversal for a given List.
//   Pre: rList is a reference to a list
//   Post: memory is allocated to store the Traversal
//   Return: a reference to the Traversal record
ListTraversal *CreateTraversal(List *rList) 
{
  ListTraversal *rTrav = new ListTraversal;
  rTrav -> nextNode = rList->head;
  return rTrav;
}


// This function determines if there are more elements in the list to visit
//   Pre: rTrav is a reference to a List Traversal
//   Post: nothing
//   Return: true, if there are more elements to visit, and false otherwise
bool hasNext(ListTraversal *rTrav)
{
  return rTrav -> nextNode != NULL;
}

// This function returns the next element in the list to visit
//   Pre: rTrav is a reference to a List Traversal
//        This function should only be called if hasNext() is true!
//   Post: nothing
//   Return: an Element 
Element next(ListTraversal *rTrav) 
{
  // first, remember the Element we want to return
  Element it = rTrav -> nextNode -> data;
  // but also walk over one step to the next Node.
  rTrav -> nextNode = rTrav -> nextNode -> next;
  // return the Element
  return it;
}

// This function deallocates the memory associated with the given Traversal
//  Pre: rTrav is a reference to a Traversal
//  Post: rTrav no longer points to valid traversal
//  Return: Nothing
void DestroyTraversal(ListTraversal *rTrav)
{
  delete(rTrav);
}

// End of file
