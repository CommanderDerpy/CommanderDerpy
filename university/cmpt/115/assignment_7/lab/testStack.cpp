#include <iostream>
#include "Stack.h"

using namespace std;

int main() {

	int size = 5;
	Stack *myStack = new Stack;
	myStack = CreateStack(size);

	int buffer = 0;

	while ( myStack->capacity != myStack->numElements ) {
		cout << "Please eneter a number : ";
		cin >> buffer;
		if (buffer == -999) break;
		PushOntoStack(myStack,buffer);
	}

	//Display Last
	cout << "Last number " << myStack->arr[myStack->numElements-1] << endl;
	//Display numbers of int entered
	cout << "Number of numbers on the stack : " << StackCount(myStack) << endl;
	//Display all int in reverse order
	PrintStack(myStack);

	cout << "We are done here" << endl;
	return 0;
}