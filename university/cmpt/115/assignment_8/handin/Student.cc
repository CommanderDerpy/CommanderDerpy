// file: Student.cc
// CMPT 115/117 model solution

#include <iostream>
#include <cstring>
using namespace std;

#include "Student.h"

// Algorithm createStudentRecord()
//   Pre: none
//   Post: none
//   Returns: refToStudent, a valid reference to Student c/w all internal references allocated

Student::Student() {
  //Student *sr = new Student;
  firstName = NULL;
  lastName = NULL;
  studentNumber = -99; // invalid number, but recognizable
  NSID = NULL;         // it will be allocated somewhere else
  mtExam = 0;
  finalExam = 0;

  for (int i = 0; i < 10; i++) {
    grades[i] = 0;
  }
}



// Algorithm destroyStudentRecord(s)
//   Pre: s :: refToStudent, a valid Student record reference 
//   Post: s :: refToStudent, deleted
//   Returns: nothing

Student::~Student() {
  /* removed cuz objects
  if (s==NULL) { 
    return;
  }
  */
  if (firstName != NULL) {
    delete[] firstName ;
  }
  if (lastName != NULL) { 
    delete[] lastName;
  }
  if (NSID != NULL) {
    delete[] NSID ;
  }
}

Student::Student(char* _firstName, char* _lastName, int _studentNumber, char* _NSID, float _grades[10], float _mtExam, float _finalExam) {
  firstName = strdup(_firstName);
  lastName = strdup(_lastName);
  studentNumber = _studentNumber;
  NSID = strdup(_NSID);

  for (int i = 0; i < 10; i++) {
    grades[i] = _grades[i];
  }
  mtExam = _mtExam;
  finalExam = _finalExam;
}


// Algorithm displayStudentRecord(s)
//   Pre: s :: refToStudent, a valid Student record reference 
//   Post: All data held in s is displayed on the console screen 
//   Returns: nothing
//
void Student::displayStudentRecord() {
  /* removed cuz objects
  if (s==NULL) { 
    return;
  }
  */
  cout << "+++++++++++++++++++++++++++++++++++++++++++++++" << endl;
  cout << "First Name: " << firstName << endl;
  cout << "Last Name: " << lastName << endl;
  cout << "Student Number: " << studentNumber  << endl;
  cout << "NSID: " << NSID << endl;
  for (int i = 0; i < 10; i++) {
    cout << "Student grade: " << i << " = " << grades[i]  << endl;
  }
  cout << "Midterm exam grade: " << mtExam  << endl;
  cout << "Final exam grade: " << finalExam << endl;
  cout << "+++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}


// Algorithm changeAssignmentGradeForStudent(s,a,g)
//   Pre: s :: refToStudent is a valid reference to a student record;
//        a :: integer between 0 and 9;
//        g :: float, a valid grade change amount (negative or positive)
//   Post: The grade for the assignment of the student record has been adjusted by the amount. 
//   Returns: nothing.

void Student::changeAssignmentGradeForStudent(int a, float g) {
  /* removed cuz objects
  if (s==NULL || a < 0 || a > 9) { 
   return;
  }
  */
 grades[a] = grades[a] + g;
}


// Algorithm changeExamGradeForStudent(s,x,e)
//   Pre: s :: refToStudent, a valid reference to a student record;
//   x :: character, is either 'M' or 'F';
//   e :: float, is a valid exam grade change amount (negative or positive)
//   Post: The grade for the exam of the student record has been adjusted by the amount. 
//   Returns: nothing.

void Student::changeExamGradeForStudent(char x, float e) {
  /* removed cuz objects
  if (s==NULL) {
    return;
  }
  */
  if (x =='M') {
   mtExam = mtExam + e;
  }
  else if (x == 'F') {
   finalExam =finalExam + e;
  }
}

  //Algorithm getGrade
  //Pre: none
  //Post: Does nothing but retrive a value
  //Return: returns the Value requested
  float Student::getGrade(int index) {
    return grades[index];
  }

  //Algorithm getMTD
  //Pre: none
  //Post: Does nothing but retrive a value
  //Return: returns the Value requested
  float Student::Student::getMT() {
      return mtExam;
  }

  //Algorithm getFinal
  //Pre: none
  //Post: Does nothing but retrive a value
  //Return: returns the Value requested
  float Student::getFinal() {
    return finalExam;
  }

// eof
