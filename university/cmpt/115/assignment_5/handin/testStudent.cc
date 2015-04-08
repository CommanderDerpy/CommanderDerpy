/* 
 * Maximilian Gewers 
 * 11163599
 * CMPT - 115 - 02
 * CMPT - 115 - T08
 */

#include <iostream>
#include "student.h"

using namespace std;

//Pre: s :: refToChar
//Post:  memory allocated on heap to store a copy
//Return: reference to new string
char *copy(char *s) {
	int l = strlen(s);
	char *c = new char[l];
	for (int i = 0; i < l; ++i) {
		c[i] = s[i];
	}
	return  c;
}


//Post: creates a test student record
//Pre: Nothing
//Return: the reference
Student *create_TestStudentRecord() {
	Student *testS;
	testS = createStudentRecord();
	char firstName[] = "Firstname";
	(*testS).firstName = copy(firstName);
	char lastName[] = "LASTNAME";
	(*testS).lastName = copy(lastName);
	(*testS).studentNumber = 12345678;
	char NSID[] = "abc123";
	(*testS).NSID = copy(NSID);
	for (int i = 0; i < 9; ++i) {
			(*testS).grades[i] = 9*(i+1);  // increasing values for fun
		}
	//(*testS).mtExam <- 66
	//(*testS).finalExam <- 88
		return testS;
	}

	//TestStudentRecordOperations() { //taken out to be replaced with main for testing
	int main () {
		// does a lot of testing!
		Student *testS = NULL;
		cout << "=============================" << endl;
		cout << "Testing createStudentRecord()" << endl;
		testS = createStudentRecord();
		if (testS == NULL) {
			cout << "Create student test failed."  << endl;
		} else {
			cout << "Create student test succeeded." << endl;
		}
		cout << "=============================" << endl;
		cout << "deallocating record" << endl;
		destroyStudentRecord(testS);
		cout << "deallocation did not fail horribly." << endl;
		// you can't really test deallocation without 
		// looking into the memory manager, so that's 
		// the best we can do

		cout << "=============================" << endl;
		cout << "Testing displayStudentRecord()" << endl;
		cout << "1. Testing call with a null pointer" << endl;
		Student *nullStudent = NULL;
		displayStudentRecord(nullStudent);
		cout << "null pointer test passecout" << endl;
		cout << "2  Testing call with hard coded data" << endl;
		testS = create_TestStudentRecord();
		displayStudentRecord(testS);
		cout << "does everything look right?" << endl;
		destroyStudentRecord(testS);

		cout << "=============================" << endl;
		cout << "To test readStudentRecordFromConsole()" << endl;
		cout << "enter data for a student" << endl;
		testS = readStudentRecordFromConsole();
		cout << "and compare to what gets displayed." << endl;
		displayStudentRecord(testS);
		cout << "does everything look right?" << endl;

		destroyStudentRecord(testS);

		cout << "=============================" << endl;
		cout << "Testing changeAssignmentGradeForStudent()" << endl;
		cout << "1. Testing call with a null pointer" << endl;
		changeAssignmentGradeForStudent(nullStudent,0,10);
		cout << "null pointer test passed" << endl;

		cout << "2. Testing call with hard coded data" << endl;
		//CHANGES mistake a to i 
		int before;
		for (int i = 0; i < 10; ++i) {
			testS = create_TestStudentRecord();
			cout << "testing changes to assignment grade at index " << i << endl;
			before = (*testS).grades[i];
			changeAssignmentGradeForStudent(testS, i, before + 1);
			//changed this prior to th eforum posted (Does the same thing just in a different way)
			if ((*testS).grades[i] == before*2 + 1) {
				cout << "test passed" << endl;
			} else {
				cout << "test did not pass for some reason " << before << " " <<(*testS).grades[3] << endl; 
			}
			destroyStudentRecord(testS);
		}


		cout << "=============================" << endl;
		cout << "Testing changeExamGradeForStudent()" << endl;
		cout << "1. Testing call with a null pointer" << endl;
		changeAssignmentGradeForStudent (nullStudent,0,10);
		cout << "null pointer test passed" << endl;
		cout << "2. Testing with hard coded data" << endl;
		testS = create_TestStudentRecord();
		cout << "testing changes to midterm grade" << endl;
		before = (*testS).mtExam;
		changeExamGradeForStudent(testS,'M',before + 1) ;
		if ((*testS).mtExam == before + 1) {
			cout << "test passed" << endl;
		} else {
			cout << "test did not pass for some reason" << before << (*testS).mtExam;
		}
		cout << "testing changes to final exam grade" << endl;
		before = (*testS).finalExam;
		changeExamGradeForStudent(testS,'F',before + 1);
		if ((*testS).finalExam == before + 1) {
			cout << "test passed" << endl;
		} else {
			cout << "test did not pass for some reason" << before << (*testS).finalExam << endl;
		}

		cout << "testing nonsense command " << endl;
		int before2 = (*testS).mtExam;
		before = (*testS).finalExam;
		changeExamGradeForStudent(testS,'Q',-1);
		if ((*testS).finalExam == before && (*testS).mtExam == before2) {
			cout << "test passed" << endl;
		} else {
			cout << "test did not pass for some reason"  << (*testS).mtExam << (*testS).finalExam << endl; 
		}
		destroyStudentRecord(testS);

		cout << "Done testing!" << endl;
		cout << endl << endl << endl << "We are done here..." << endl;
		return 0;
	}
