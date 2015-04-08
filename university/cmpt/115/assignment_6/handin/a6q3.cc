/* 
 * Maximilian Gewers 
 * 11163599
 * CMPT - 115 - 02
 * CMPT - 115 - T08
 */
#include <iostream>
#include <cstring>

using namespace std;

struct Node {
  int data;
  Node* next;
};

//helper function to create sequences of nodes
Node * arrayToNodeSequence(int arr[], int size){
  Node *prev = NULL;
  Node *cur;
  for (int i = size-1; i >=0; i--){
    cur = new Node;
    cur->data = arr[i];
    cur->next = prev;
    prev = cur;
  }
  return cur;
}

//helper function for display
void printNodes(Node *cur) {
  if (cur == NULL){
    return;
  } else {
    cout << cur->data << endl;
    printNodes(cur->next);
  }
}

//helper function to cleanup node sequences
void deallocateNodeSequence(Node *cur) {
  while (cur != NULL) {
    Node* temp = cur->next;
    delete cur;
    cur = temp;
  }
}

//Above this point there are helper functions *YOU DO NOT NEED TO MODIFY THEM*

//collatz sequence length
//Pre: value is a positive integer
//Return: the length of the collatz sequence, starting from value
int collatz(int value){
  int sequence = 0;
  if (value != 1) {
    if (value %2 == 0) {
      value = value / 2;
    } else {
      value = value*3+1;
    }
    sequence = 1;
    sequence = sequence + collatz(value);
  } 
  //cout << sequence << endl;
  return sequence;
}

//remove nodes containing odd values from a sequence of nodes
//Pre: cur is a reference to a Node
//Post: the sequence of nodes starting with cur has had all nodes containing
//      odd values removed
//Return: a reference to the modified sequence of nodes.
Node * removeOdds(Node *cur) {
  if ( cur == NULL ) {
    return cur;
  } else {
    if (cur->data % 2 != 0) {
      return (removeOdds(cur->next));
    } else {
      cur->next = removeOdds(cur->next);
      return cur;
    }
  }
  return cur;
}

/*
  if ((*cur->next).data % 2 != 0) {
    delete cur->next;
    cur->next = cur->next->next;
    removeOdds(cur->next);
  }
*/

//find and replace one character with another
//Pre: phrase is the cstring to find and replace characters in
//     find is the character to search for
//     replace is the new character to insert in place of 'find'
//     startPos is an index in the array 'phrase', used as the basis for recursion.
void findAndReplace(char *phrase, char find, char replace, int startPos){
  if (startPos != strlen(phrase) - 1) {
    if (phrase[startPos] == find) {
      phrase[startPos] = replace;
    }
    startPos = startPos + 1;
    findAndReplace(phrase,find,replace,startPos);
  }
}


int main(){
  cout << "Start of testing!!" << endl;
  //*YOU DO NOT NEED TO MODIFY THE TESTS PROVIDED HERE*
  cout << "testing collatz function:" << endl;
  if (collatz(1) == 0){
    cout << "PASSED: collatz value for input 1 is correct" << endl;
  } else{
    cout << "FAILED: collatz value for input 1 is not correct" << endl;
  }

  if (collatz(2) == 1){
    cout << "PASSED: collatz value for input 2 is correct" << endl;
  } else{
    cout << "FAILED: collatz value for input 2 is not correct" << endl;
  }

  if (collatz(5) == 5){
    cout << "PASSED: collatz value for input 5 is correct" << endl;
  } else{
    cout << "FAILED: collatz value for input 5 is not correct" << endl;
  }

  if (collatz(27) == 111){
    cout << "PASSED: collatz value for input 27 is correct" << endl;
  } else{
    cout << "FAILED: collatz value for input 27 is not correct" << endl;
  }

  cout << endl;
  cout << "testing removeOdds:" << endl;
  Node *head = NULL;
  cout << "testing with an empty sequence:" << endl;
  cout << "full sequence of nodes: (there should be 0 nodes)" << endl;
  printNodes(head);
  head = removeOdds(head);
  cout << "now with odds removed: (there should be 0 nodes)" << endl;
  printNodes(head);
  
  cout << "testing with a sequence of all odd numbers:" << endl;
  int input1[] = {1,3,5,7};
  head = arrayToNodeSequence(input1, 4);
  cout << "full sequence of nodes:" << endl;
  printNodes(head);
  head = removeOdds(head);
  cout << "now with odds removed: (all values should be removed)" << endl;
  printNodes(head);
  deallocateNodeSequence(head);
  
  cout << "testing with a sequence of all even numbers:" << endl;
  int input2[] = {2,8,4,12,6};
  head = arrayToNodeSequence(input2, 5);
  cout << "full sequence of nodes:" << endl;
  printNodes(head);
  head = removeOdds(head);
  cout << "now with odds removed: (the sequence should be unchanged)" << endl;
  printNodes(head);
  deallocateNodeSequence(head);

  cout << "testing with a sequence of mixed even/odd numbers:" << endl;
  int input3[] = {2,7,5,32,40,1};
  head = arrayToNodeSequence(input3, 6);
  cout << "full sequence of nodes:" << endl;
  printNodes(head);
  head = removeOdds(head);
  cout << "now with odds removed: (only the even values should remain)" << endl;
  printNodes(head);
  deallocateNodeSequence(head);

  cout << endl;
  cout << "testing findAndReplace" << endl;
  char phrase1[] = "I can't let you do that Dave";
  cout << "first phrase: "<< endl;
  cout << phrase1 << endl;
  findAndReplace(phrase1,'t','x',0);
  cout << "after replacing all occurrences of 't' with 'x':" << endl;
  cout << phrase1 << endl;
  
  char phrase2[] = "I Love Recursion!";
  cout << "second phrase: "<< endl;
  cout << phrase2 << endl;
  findAndReplace(phrase2,'q','u',0);
  cout << "after replacing all occurrences of 'q' with 'u' (no change expected):" << endl;
  cout << phrase2 << endl;
  
  cout << "testing complete!" << endl;
}
