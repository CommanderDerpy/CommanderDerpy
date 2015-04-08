// File: testBSTree.cc
// CMPT 115/117 2014.T2.Lab9
// Puts an object oriented BST implementation through its paces

#include <cstdlib>
#include <iostream>
#include <ctime>

#include "BSTree.h"

using namespace std;


int main() {
  // set up the test data to be inserted
  Element arr[10] = {1, 20, 3, 17, 4, 15, 5, 11, 8, 14};

  // create a tree
  BSTree *t = new BSTree() ;

  // insert test data 
  for (int i=0; i<10; i++) {
    t->insertBST(arr[i]);
  }

  // check the data is in order!
  cout << "\nThe inorder of the binary search tree is: ";
  t->displayInOrder();

  int max = 0;
  max = t->maxDepth();

  // set up testing for searching and sorting
  int dataOut;

  // testing searchBST with something in the test data
  int target = 5;
  if (t->searchBST(target, &dataOut)) {
    cout << "\nFound node " << dataOut << " in the tree" << endl;
  }
  else  {
    cout << "\nCan't find node " << target << " in the tree" << endl;
  }
  
  max = t->maxDepth();

  // testing searchBST with something NOT in the test data
  target = 7;
  if (t->searchBST(target, &dataOut)) {
    cout << "\nFound node " << dataOut << " in the tree" << endl;
  }
  else  {
    cout << "\nCan't find node " << target << " in the tree" << endl;
  }
  

  // testing deleteBST with something in the tree
  target = 11;
  if(t->deleteBST(target, &dataOut)) {
    cout << "\nNode " << dataOut << " was deleted from the tree" << endl;
  }
  else {
    cout << "\nCan't delete node " << target << " from the tree" << endl;
  }
  
  // check it's no longer there
  cout << "\nThe inorder of the binary search tree is: ";
  t->displayInOrder();

  // testing deleteBST with something NOT in the tree
  // keeping target the same as the previous deleteBST call
  if(t->deleteBST(target, &dataOut)) {
    cout << "\nNode " << dataOut << " was deleted from the tree" << endl;
  }
  else {
    cout << "\nCan't delete node " << target << " from the tree" << endl;
  }
  
  // nothing should change
  cout << "\nThe inorder of the binary search tree is: ";
  t->displayInOrder();
  
  // Delete some of the test data
  for (int i = 0; i < 10; i = i + 2) {
    target = arr[i];
    if(t->deleteBST(target, &dataOut)) {
      cout << "\nNode " << dataOut << " was deleted from the tree" << endl;
    }
    else {
      cout << "\nCan't delete node " << target << " from the tree" << endl;
    }
  
    // nothing should change
    cout << "\nThe inorder of the binary search tree is: ";
    t->displayInOrder();
  }

  max = t->maxDepth();

  delete t;
  
  return EXIT_SUCCESS;
}
