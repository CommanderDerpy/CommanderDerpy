/* 
 * Maximilian Gewers 
 * 11163599
 * CMPT - 115 - 02
 * CMPT - 115 - T08
 */
// Implementation of an array-based List ADT
// Michael Horsch and Ian McQuillan, for CMPT115 2012 WT2, March 2013
// Modified by Craig Thompson for CMPT115/117 WT2 2015
//
// This is only a partial implementation of the List ADT.

#include "ArrayList.h"
#include <cstring>
#include <iostream>

using namespace std;

// CONSTRUCTOR and DESTRUCTOR
// create a new empty list of specified size.
// pre: size is the desired maximum capacity of the list.
// returns: a pointer to newly created List, or NULL if List could not be created.
List *createList() {
	int size = 1;
	List *l = new List;
	if (l == NULL) {
	  	return NULL;
	}
	l->data = new Element[size];
	if (l-> data == NULL){
	   delete l; 
	   return NULL;
	}
	//Removed for assignment
l->capacity = size;
l->count = 0;
return l;
}


// destroy an existing list
// pre: a pointer to a List
// post: deallocates List  .  Does not deallocate contents! (may cause a memory leak) 
void destroyList(List* l) {
  delete [] l->data;
  delete l;
}


// STATUS
// check whether the list is empty
// pre: a pointer to a List.
// returns: true if List is empty, false otherwise.
bool emptyList(List* l) {
  return (0 == l->count);
}

// STATUS
// check whether the list is empty
// pre: a pointer to a List.
// returns: true if List is empty, false otherwise.
bool fullList(List* l) {
  return (l->capacity == l->count);
}


// return the number of elements in the list
// pre: a pointer to the List.
// returns: number of elements in the List.
int lengthList(List* l) {
  return l->count;
}


// insert the element into the list at the end of the list
// pre: a pointer to a List, and an element to insert.
// post: the Element is placed in the List as long as long as the list is not full.
// returns: true if successful, false otherwise.
bool insertTail(List* l, Element e) {
	if (fullList( l)) {
		if (!growList( l)) {
			return false;
		}
	}
  	l->data[l->count] = e;
  	l->count++;
  	return true;
}
// delete the element at the end of the list
// pre: a pointer to a list, and a pointer to an Element
// post: if list is non-empty, it removes the last element, and deallocates memory 
// associated with deleted element.
// returns: true if it deleted something, false otherwise.
bool deleteTail(List* l, Element *e) {
  if (emptyList(l)) {
    	return false;
  } else {
    *e = l->data[l->count-1];
    l->count--;
    return e;
  }
}

//Attempt to double the capacity to rList
//Pre: rList :: reference to a list to grow
//Post: capacity of rList has been doubled, list content are unchanged
//Return: True if successful, false otherwise
bool growList(List* l) {
  	Element *data = new Element[l->capacity + 1];

  	if (data == NULL) {
  		return false;
  	}
  	for (int i = 0; i < l->capacity; i++) {
    	data[i] = l->data[i];
	}

  	delete [] l->data;

  	l->data = data;
  	l->capacity++;

  	return true;
}
// eof