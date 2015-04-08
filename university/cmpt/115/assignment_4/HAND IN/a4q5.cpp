/* 
* Maximilian Gewers 
* 11163599
* CMPT - 115 - 02
* CMPT - 115 - T08
*/

#include <iostream>
#include <cstring>

using namespace std;

struct Student {
	char* name;
	int score;
};


//algorithm : getData
//Pre: Student refToarrStu :: array of pointers to student struct
//	aSize :: intenger of size of array
//Post: recives data from the user/text feed to fill the array of ref
//Return: Nothing
void getData(Student *arrStu[], int aSize) {
	char buffer[50];
	for (int c = 0; c < aSize; c++) {
		arrStu[c] = new Student;
		cin >> buffer;
		arrStu[c]->name = strdup(buffer);
		cin >> arrStu[c]->score;
	}
}

//algorithm : getData
//Pre: Student refToarrStu :: array of pointers to student struct
//	aSize :: intenger of size of array
//Post: prints a certain pointer
//Return: Nothing
void ptrData(Student *arrStu[], int aSize, int iS) {
	cout << arrStu[iS]->name << endl << arrStu[iS]->score << endl << endl;
}

int main(int argc, char** argv) {

	int aSize = 0;
	cin >> aSize;
	Student **arrStu = new Student*[aSize];

	getData(arrStu,aSize);
	ptrData(arrStu,aSize,100);

	cout << endl << endl << "We are done here..." << endl;
	return 0;
}