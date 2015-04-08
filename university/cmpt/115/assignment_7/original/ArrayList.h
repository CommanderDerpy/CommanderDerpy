//
// Data structure for List ADT, where the data stored are pointers to Elements
//
// Michael Horsch and Ian McQuillan, for CMPT115 2012 WT2, March 2013
//

#include "Element.h"

#ifndef _LIST_H_
#define  _LIST_H_

// a list contains a pointer to the head node and a count
struct List {
  Element *data;
  int count;
  int capacity;
};

//
// the List Operations
//


// CONSTRUCTOR and DESTRUCTOR
// create a new empty list of specified size.
// pre: size is the desired maximum capacity of the list.
// returns: a pointer to newly created List, or NULL if List could not be created.
List *createList(int size);

// destroy an existing list
// pre: a pointer to a List
// post: deallocates List.  Does not deallocate contents! (may cause a memory leak)
void destroyList(List*);


// STATUS
// check whether the list is empty
// pre: a pointer to a List.
// returns: true if List is empty, false otherwise.
bool emptyList(List*);

// return the number of elements in the list
// pre: a pointer to the List.
// returns: number of elements in the List.
int lengthList(List*);



// insert the element into the list at the end of the list
// pre: a pointer to a List, and a pointer to an existing Element.
// post: the Element is placed in the List as long as the list is not full.
// returns: true if successful, false otherwise.
bool insertTail(List*, Element);


// delete the element at the end of the list
// pre: a pointer to a list, and a pointer to an Element
// post: if list is non-empty, it removes the last element, and deallocates memory 
// associated with deleted element.
// returns: true if it deleted something, false otherwise.
bool deleteTail(List* l, Element *e);

#endif
