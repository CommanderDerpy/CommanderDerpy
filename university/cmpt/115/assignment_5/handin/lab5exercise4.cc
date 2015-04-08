/* 
 * Maximilian Gewers 
 * 11163599
 * CMPT - 115 - 02
 * CMPT - 115 - T08
 */
 
#include <iostream>
#include <fstream>

using namespace std;


int main() {

	//declaring a file
	ifstream nameOfFile;
	//open the file
	nameOfFile.open("infile.txt", ios::in);

	//doing stuff
	int first;
	float second;
	char third;
	float last;
	cout << "Opening file.." << endl;
	if (nameOfFile.is_open()) { // chcks if the file is open
		cout << "Opening DONE" << endl;
		nameOfFile >> first;
		nameOfFile >> second;
		nameOfFile >> third;
		nameOfFile >> last;
		cout << "Closing file.." << endl;
		nameOfFile.close();
		cout << "Closing DONE" << endl;
	} else {
		cout << "The File you are trying to open could not be opened.." << endl;
	}

	cout << "And now the testing : " << endl;
	cout << "First: " << first << endl;
	cout << "Second: " << second << endl;
	cout << "Third: " << third << endl;
	cout << "Last: " << last << endl;
	return 0;
}