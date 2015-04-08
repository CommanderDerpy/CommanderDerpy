// file: testStudent.cc

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#include "Student.h"

// Algorithm copy(s)
//   Pre: s :: refToChar
//   Post:  memory allocated on heap to store a copy
//   Return: reference to new string

char *copy(char *s) {
  char *temp = new char[strlen(s)+1];
  strcpy(temp,s);
  return temp;
}

// Pre: none
// Post: reads string from console, allocates memory on heap
// Return: reference to string
char *readAndCopyCString() {
  char temp[100];
  cin >> temp;
  char *result = new char[strlen(temp)+1];
  strcpy(result,temp);
  return result;
}

// Algorithm readStudentRecordFromConsole()
//   Pre: none
//   Post: data for a valid Student record has been read from the input console 
//   Returns: reference to the newly created student record

Student *readStudentRecordFromConsole() {
  //Student *s = createStudentRecord();
  cout << "First Name: ";
  //s->firstName = readAndCopyCString(); // used from previous assignment
  char *firstName = readAndCopyCString();

  cout << "Last Name: ";
  //s->lastName = readAndCopyCString();
  char *lastName = readAndCopyCString();

  cout << "Student Number: ";
  //cin >> s->studentNumber; // integer read directly
  int studentNumber;
  cin >> studentNumber;

  cout << "NSID: ";
 //s->NSID = readAndCopyCString(); // could now check if length entered was only 6 characters
  char *nsid = readAndCopyCString();

  float grades[10];
  for (int i = 0; i < 10; i++) {
    cout << "Student grade " << i << ": ";
    //cin >> s->getGrade(i);
    cin >> grades[i];
  }
  cout << "Midterm exam grade: ";
  float mtmark;
  //cin >> s->getMT() ;
  cin >> mtmark;

  cout << "Final exam grade: ";
  //cin >> s->getFinal() ;
  float fmark;
  cin >> fmark;

  Student *dude = new Student(firstName, lastName, studentNumber, nsid, grades, mtmark, fmark);
  return dude;


}

// Algorithm create_TestStudentRecord()
//   Post: creates a student record for testing other functions
//   Return: the reference

Student *create_TestStudentRecord() {
  char f[] = "FIRSTNAME";
  char l[] = "LASTNAME";
  char n[] = "abc123";
  float g[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

  Student *testS = new Student(f, l, 12345678, n, g, 66, 88);

  return testS;
}



void testStudentRecordOperations() {
  int before, before2;

  // does a lot of testing!
  Student *testS = NULL;
  cout << "=============================" << endl;
  cout << "Testing createStudentRecord()" << endl;
  testS = new Student();
  if (testS == NULL) {
    cout << "Create student test failed."  << endl;
    return;
  }
  else {
    cout << "Create student test succeeded." << endl;
  }

  cout << "=============================" << endl;
  cout << "deallocating record" << endl;
  delete testS;
  cout << "deallocation did not fail horribly." << endl;
  // you can't really test deallocation without 
  // looking into the memory manager, so that's 
  // the best we can do

  cout << "=============================" << endl;
  cout << "Testing displayStudentRecord()" << endl;
  cout << "1. Testing call with hard coded data" << endl;
  testS = create_TestStudentRecord();
  testS->displayStudentRecord();
  cout << "does everything look right?" << endl;
  delete testS;

  cout << "=============================" << endl;
  cout << "To test readStudentRecordFromConsole()" << endl;
  cout << "enter data for a student" << endl;
  testS = readStudentRecordFromConsole();
  cout << "Now compare to what gets displayed." << endl;
  testS->displayStudentRecord();
  cout << "does everything look right?" << endl;

  delete testS;

  cout << "=============================" << endl;
  cout << "Testing changeAssignmentGradeForStudent()" << endl;
  cout << "1. Testing call with hard coded data" << endl;
  for (int a = 0; a < 10; a++) {
    testS = create_TestStudentRecord();
    cout << "testing changes to assignment grade at index " << a << endl;
    before = testS->getGrade(a);
    testS->changeAssignmentGradeForStudent(a,1);
    if (testS->getGrade(a) == before + 1) {
      cout << "test passed" << endl;
    }
    else {
      cout << "test did not pass for some reason" << before << " " << testS->getGrade(a)  << endl;
    }
    delete testS;
  }

  cout << "=============================" << endl;
  cout << "Testing changeExamGradeForStudent()" << endl;
  cout << "1. Testing with hard coded data" << endl;
  testS = create_TestStudentRecord();
  cout << "testing changes to midterm grade" << endl;
  before = testS->getMT();
  testS->changeExamGradeForStudent('M',1);
  if (testS->getMT() == before + 1) {
    cout << "test passed" << endl;
  }
  else {
    cout << "test did not pass for some reason" << before << " " << testS->getMT()  << endl;
  }


  cout << "testing changes to final exam grade" << endl;
  before = testS->getFinal();
  testS->changeExamGradeForStudent('F',1);
  if (testS->getFinal() == before + 1) {
    cout << "test passed" << endl;
  }
  else {
    cout << "test did not pass for some reason" << before << " " << testS->getFinal()  << endl;
  }


  cout << "testing nonsense command " << endl;
  before2 = testS->getMT();
  before = testS->getFinal();
  testS->changeExamGradeForStudent('Q',-1);
  if (testS->getFinal() == before && testS->getMT() == before2) {
    cout << "test passed" << endl;
  }
  else {
    cout << "test did not pass for some reason" << testS->getMT() << " " << testS->getFinal()  << endl;
  }

  delete testS;

  cout << "Done testing!" << endl;
}

int main () {
  testStudentRecordOperations();
  return 0; 
}