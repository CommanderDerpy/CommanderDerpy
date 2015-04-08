//
// Simple Lists: the list contains a pointer to the head node and a count
//
// Ian McQuillan, for CMPT115 2013 WT2
// Minor modifications for 2014 (mch)
// Minor modifications for 2015 (mch)
//


// change the definition of Element in Element.h 
// depending upon what we want to store in the list
#include "Element.h"

#ifndef _SIMPLE_LIST_
#define _SIMPLE_LIST_

// a node stores data and points to the next node
struct Node {
  Element data;
  Node* next;
};

// a list contains a pointer to the head node and a count. We won't use 
// a tail pointer in this implementation.
struct List {
  Node* head;
  int count;
};


// CONSTRUCTOR and DESTRUCTOR
// create a reference to a new empty list
// create a new empty list
//   Pre: nothing
//   Post: memory is allovcated for the new list record
//   Return: a reference to the new list
List *createList();


// destroy an existing list
//   Pre: l is a valid reference to a list
//   Post: memory for the list record is deallocated
//   Return: nothing
//   Bug: if the Element is not a primitive type, it might not be deallocated! (may cause a memory leak)
void destroyList(List*);


// STATUS
// check whether a list is empty
//  Pre: l is a valid reference to a list
//  Post: nothing
//  Return: true, if the list is empty, false otherwise
bool emptyList(List*);


// return the element count of a list
//  Pre: l is a valid reference to a list
//  Post: nothing
//  Return: the number of elements in the list
int lengthList(List*);


// INSERTION -- return indicates success or failure

// insert the element into the list as the tail
// pre: a reference to a list, Element to insert
// post: the list has a new last Element, with the second parameter.
// returns: true if successful, false otherwise
bool insertTail(List*, Element);

// EXTRACTION -- return indicates success or failure
// return the element at the head of the list
// pre: a reference to a list, a reference to an Element
// post: the list is unchanged, the data in the first position of
// the List is placed into where Element* is pointing at 
// returns: true if successful, false otherwise
bool head(List*, Element*);


// return the element at the tail of the list
// pre: a reference to a list, a reference to an Element
// post: the list is unchanged, the data in the last position of
// the List is placed into where Element* is pointing at 
// returns: true if successful, false otherwise
bool tail(List*, Element*);



// DELETION -- return indicates success or failure
// delete the element at the head of the list
// pre: a reference to a list
// post: the list has the first element removed if possible
// returns: true if successful, false otherwise
bool deleteHead(List* , Element *);


#endif /*_SIMPLE_LIST_*/
 
