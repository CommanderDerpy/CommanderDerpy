//
// Simple Lists: the list contains a pointer to the head node
//
// Ian McQuillan, Christopher Dutchyn, for CMPT115 2013
// Minor modifications for 2014
//   -removed retrieveMatching and deleteMatching
//   - added argument to delete() methods to store the data deleted
//     (helps solve a memory leak)
//


#include "NodeList.h"
#include <cstdlib>
#include <iostream>

using namespace std;


// CONSTRUCTOR and DESTRUCTOR
// create a new empty list
//   Pre: nothing
//   Post: memory is allocated for the new list record
//   Return: a reference to the new list
List *createList() {
  List *l;
  l = new List;
  l->head = NULL;
  l->count = 0;

  return l;
}

// destroy an existing list
//   Pre: l is a valid reference to a list
//   Post: memory for the list record is deallocated
//   Return: nothing
//   Bug: if the Element is not a primitive type, it might not be deallocated! (may cause a memory leak)
void destroyList(List *l) {
  Node* p = l->head;
  while (NULL != p) {
    Node* t = p->next;
    delete p;
    p = t;
  }
  delete l;
}


// STATUS
// check whether a list is empty
//  Pre: l is a valid reference to a list
//  Post: nothing
//  Return: true, if the list is empty, false otherwise
bool emptyList(List *l) {
  return (NULL == l->head);
}

// return the element count of a list
//  Pre: l is a valid reference to a list
//  Post: nothing
//  Return: the number of elements in the list
int lengthList(List *l) {
  return l->count;
}


// insert the element into the list as the tail
//  Pre: l is a valid reference to a list
//       e is an Element to be inserted
//  Post: the list has e at the end
//  Return: true, if the insertion worked, false otherwise
bool insertTail(List *l, Element e) {

  Node* n = new Node;
  if (NULL == n) {
    return false;
  }
  n->data = e;
  n->next = NULL;
  l->count += 1;

  // is the list empty?
  if (NULL == l->head) {
    l->head = n;
    return true;
  }
  
  // add new element to end of list 
  Node* p = l->head;
  if (NULL == p) return false;

  while (NULL != p->next) {
    p = p->next;
  }
  p->next = n;

  return true;
}

// EXTRACTION -- return indicates success or failure
// return the element at the head of the list
//  Pre: l is a valid reference to a list
//       e is a reference to an Element
//  Post: the Element at the head of the list is copied to *e
//  Return: true, if the copy worked, false otherwise
bool head(List *l, Element *e) {
  if (NULL == l->head) {
    return false;
  }
  *e = l->head->data;
  return true;
}

// return the element at the tail of the list
//  Pre: l is a valid reference to a list
//       e is a reference to an Element
//  Post: the Element at the tail of the list is copied to *e
//  Return: true, if the copy worked, false otherwise
bool tail(List *l, Element *e) {
  if (NULL == l->head) {
    return false;
  }
  
  Node* p = l->head;
  if (NULL == p) return false;
  while (NULL != p->next) {
    p = p->next;
  }

  *e = p->data;
  return true;
}



// DELETION -- return indicates success or failure
// delete the element at the head of the list
//  Pre: l is a valid reference to a list
//  Post: the Element at the head of the list is removed from the list
//  Return: true, if the list was not empty, false otherwise
bool deleteHead(List *l, Element *el) {
  if (NULL == l->head) {
    return false;
  }

  l->count -= 1;
  Node *p = l->head;
  l->head = p->next;
  p->next = NULL;
  *el = p->data;
  delete p;
  return true;
}



// end of file
