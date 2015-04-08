/* 
 * Maximilian Gewers 
 * 11163599
 * CMPT - 115 - 02
 * CMPT - 115 - T08
 */
 
#include <iostream>
#include <cstring>
#include "ArrayList.h"

using namespace std;

// Algorithm copy(s)
//   Pre: s :: refToChar
//   Post:  memory allocated on heap to store a copy
//   Return: reference to new string

char *copy(char *s) {
  char *temp = new char[strlen(s)+1];
  strcpy(temp,s);
  return temp;
}


void test_ListOperations(){
  
  cout << "testing createList" << endl;
  
  List *myList = createList();
  
  if (myList == NULL){
    cout << "createList failed" << endl;
    return;
  } else{
    cout << "createList succeeded" << endl;
  }

  cout << "testing destroyList" << endl;
  destroyList(myList);
  cout << "testing destroyList succeeded" << endl;

  cout << "testing emptyList with an empty list" << endl;
  myList = createList();
  if (! emptyList(myList)){
    cout << "testing emptyList failed when an empty list was given"<< endl;
    return;
  }

  cout << "testing lengthList with an empty list" << endl;
  if (lengthList(myList) != 0){
    cout << "an empty list should have length 0" << endl;
    return;
  }

  cout << "inserting an element at the tail of the list" << endl;
  char firstElement[] = "first";
  char *toInsert = copy(firstElement);
  if (!(insertTail(myList, toInsert))){
    cout << "insertTail failed to insert first element" << endl;
    return;
  }

  if (emptyList(myList)){
    cout << "testing emptyList failed when a non-empty list was given"<< endl;
    return;
  }

  if (lengthList(myList) != 1){
    cout << "A list with 1 element should have length 1"<< endl;
    return;
  }

  cout << "inserting a second element at the tail of the list" << endl;
  char secondElement[] = "second";
  toInsert = copy(secondElement);
  if (!(insertTail(myList, toInsert))){
    cout << "insertTail failed to insert second element" << endl;
    return;
  }

  if (emptyList(myList)){
    cout << "testing emptyList failed when a non-empty list was given"<< endl;
    return;
  }

  if (lengthList(myList) != 2){
    cout << "A list with 2 elements should have length 2"<< endl;
    return;
  }

  cout << "deleting the tail of the list (going from 2 to 1 elements in the list)" << endl;
  char * retrievedValue;
  deleteTail(myList, &retrievedValue);
  if (strcmp(retrievedValue, secondElement) != 0){
    cout << "wrong value returned when deleting tail of the list" << endl;
    return;
  }
  delete []retrievedValue;

  if (emptyList(myList)){
    cout << "testing emptyList failed when a non-empty list was given"<< endl;
    return;
  }

  if (lengthList(myList) != 1){
    cout << "A list with 1 element should have length 1"<< endl;
    return;
  }

  cout << "deleting the tail of the list (going from 1 to 0 elements in the list)" << endl;
  deleteTail(myList, &retrievedValue);
  if (strcmp(retrievedValue, firstElement) != 0){
    cout << "wrong value returned when deleting tail of the list" << endl;
    return;
  }
  delete []retrievedValue;
  
  if (!emptyList(myList)){
    cout << "testing emptyList failed when a non-empty list was given"<< endl;
    return;
  }

  if (lengthList(myList) != 0){
    cout << "A list with 0 elements should have length 0"<< endl;
    return;
  }

  char words[][6] = {"one", "two", "three", "four", "five", "six",
                          "seven", "eight", "nine", "ten"};
  bool test;
  cout << "inserting 10 elements" << endl;
  for(int i = 0; i < 10; i++){
    toInsert = copy(words[i]);
    test = insertTail(myList, toInsert);
    if (test == false) {
      insertTail(myList, toInsert);
    }
  }

  cout << "deleting 10 elements" << endl;
  cout << "should print the words ten nine eight ... one" << endl;
  for(int i = 0; i < 10; i++){
    deleteTail(myList, &retrievedValue);
    cout << retrievedValue << endl;
    delete []retrievedValue;
  }

  cout << "Testing growList Function" << endl;
  cout << "Returns True if sucess false otherwise" << endl;
  test = false;
  test = growList(myList);
  if (test == true) {
    cout << "Test 1 sucess" << endl;
    for (int i = 0; i < 500; ++i) {
      growList(myList);
    }
    if (myList->capacity == 511) {
      cout << "Test 2 sucess" << endl;
    } else {
      cout << "test 2 FAIL!" << endl;
      cout << "growList Testing sucess! you win!" << endl;
    }
  } else {
    cout << "test 1 FAIL!" << endl;

  }

  destroyList(myList);
  cout << "Testing list operations complete!" << endl;
}

int main(){
  
  test_ListOperations();
  cout << "Testing complete!" << endl;

  return 0;
}