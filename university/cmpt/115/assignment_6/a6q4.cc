#include <iostream>
#include <cstring>
#include <fstream>

#include "NodeList.h"
#include "ListTraversal.h"


using namespace std;

/*
bool isPalindrome(char *candidate, int start, int end){
	if (candidate[start] == candidate[end]) {
		return true;
	} 
	if (candidate[start] != candidate[end]) {
		return false;
	}
	return isPalindrome(candidate, ++start, --end);
}
*/
bool isPalindrome(char *candidate, int start, int end){
	if (candidate[start] == candidate[end]) {
		return isPalindrome(candidate, ++start, --end);
	}
	if (start > end) {
		return true;
	}
	if (candidate[start] != candidate[end]) {
		return false;
	}
	return false;
}



int main(){

  //define filename
	fstream fin1;
  //open file
	fin1.open("a6q4_input.txt", ios::in);
  //create list
	List *Head = createList();
  //read file contents into list
	for (int i = 0; i < 10; ++i) {
		char *c = new char[15];
		fin1 >> c;
		cout << c << endl;
		insertTail(Head, c);
		}
  //close the file
	fin1.close();
  //display number of words read from file:
	int count;
	count = lengthList(Head);
	cout << "Number of worlds are : " << count << endl;
  //create a list traversal
	ListTraversal *traverse = CreateTraversal(Head);
  //traverse list and print only the palindromes
	//cout << "testing word : " << isPalindrome("noon",0,strlen("noon")-1) << endl;
	char buffer[25];
	while (hasNext(traverse)) {
		strcpy(buffer,next(traverse));
		//cout << "In the buffer : " << buffer << endl;
		if (isPalindrome(buffer,0,strlen(buffer)- 1)) {
			cout << "Is a palindrome : " << buffer << endl;
		}
	}

  //cleanup data structures
	/*
	DestroyTraversal(traverse);
	char garbage[25];
	bool foo = false;
	char *boo = new char[15];
	deleteHead(Head,boo);	
	cout << "FOO" << endl;
	destroyList(Head);
	*/
	//lengthList(head)


	DestroyTraversal(traverse);
 	char *data = new char[25];
  	while (lengthList(Head) > 0) {
    	deleteHead(Head,&data);
    	cout << "deleted " << *data << endl;
  	}
  	delete data;
  	//delete[] c;
  
  	destroyList(Head);


	cout << endl << endl << endl << "We are done here!!!" << endl << endl << endl;
	return 0;
}