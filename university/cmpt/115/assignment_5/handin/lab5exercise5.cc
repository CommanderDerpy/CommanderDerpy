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

	ifstream nameOfFile;
	nameOfFile.open("input.txt", ios::in);
	char checker;
	int counter = 0;
	while (!nameOfFile.eof()) { // need for assignment
		nameOfFile >> checker;
		if (checker == 'e') {
			counter = counter + 1;
		}
		checker = ' ';
	}
	nameOfFile.close();
	cout << "We had a total of: " << counter << " e's.. wow.. much e.. such wow.. so amaze.." << endl;

	return 0;
}