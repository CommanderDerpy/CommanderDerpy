/* 
 * Maximilian Gewers 
 * 11163599
 * CMPT - 115 - 02
 * CMPT - 115 - T08
 */
 
#include <iostream>
#include <cstring>
#include <cstddef>
#include "student.h"

using namespace std;


//Pre: none
//Post: none
//Returns: refToStudent, a valid reference to Student c/w all internal references allocated
Student *createStudentRecord() {
	Student* sr = new Student;
	(*sr).NSID = new char[6];
	(*sr).grades = new float[10];
	return sr;
}

//Pre: s :: refToStudent, a valid Student record reference 
//Post: s :: refToStudent, deallocated
//Returns: nothing
void destroyStudentRecord(Student *s) {
  	if (s == NULL) { 
    	return;
  	}
 	if ((*s).firstName != NULL) {
   		delete[] (*s).firstName; 
 	 }
  	if ((*s).lastName != NULL) { 
   	 	delete[] (*s).lastName;
 	 }
 	if ((*s).NSID != NULL) {
  	 	delete[] (*s).NSID; 
 	 }
	if ((*s).grades != NULL) { 
    	delete[] (*s).grades;
  	}
  	delete s;
}

//Pre: s :: refToStudent, a valid Student record reference 
//Post: All data held in s is displayed on the console screen 
//Returns: nothing
void displayStudentRecord(Student *s) {
 	if (s == NULL) { 
 	  return;
 	}
 	cout << "first name: "<< (*s).firstName << endl;
 	cout << "last name: " << (*s).lastName << endl;
 	cout << "Student number: " << (*s).studentNumber << endl; 
	cout << "NSID: " << (*s).NSID << endl;
	for (int i = 0; i < 9; ++i) {
		cout << "Student grade: " << i+1 << " = " << (*s).grades[i] << endl;
	}
	cout << "Grade for Final: " << (*s).finalExam << endl;
	cout << "Grade for Midterm: " << (*s).mtExam << endl;
	//cout << "Final grade is: " << (*s).finalGrade << " / " << (*s).finalLetterGrade << endl;
}


//Pre: none
//Post: data for a valid Student record has been read from the input console 
//Returns: reference to the newly created student record
Student *readStudentRecordFromConsole() {

  	cout << "creating a new student record:" << endl;
  	Student *s = new Student;
  	s = createStudentRecord();

  	char buffer[50];

	cout << "Enter Student's First Name: ";
	cin >> buffer;
	(*s).firstName = strdup(buffer);

	cout << "Enter Student's Last Name: ";
	cin >> buffer;
	(*s).lastName = strdup(buffer);

  	cout << "Enter Student number: ";
  	cin >> (*s).studentNumber;

  	cout << "Enter Student NSID (Format ABC123 / XXX###: ";
  	cin >> buffer;
  	(*s).NSID = strdup(buffer);

  	for (int i = 0; i < 10; ++i) {
		cout << "Enter Student grade for assignment : " << i+1 << endl;
		cin >> (*s).grades[i];
  	}
  	/*
  	cout << "Enter Students Final exam grade: ";
  	cin >> (*s).finalExam;
  	cout << "Enter Students Midterm exam grade: ";
  	cin >> (*s).mtExam;
  	*/
  	return s;
}
 

//Pre: s :: refToStudent is a valid reference to a student record;
    //a :: integer between 0 and 9;
    //g :: float, a valid grade change amount (negative or positive)
//Post: The grade for the assignment of the student record has been adjusted by the amount. 
//Returns: nothing.
void changeAssignmentGradeForStudent(Student *s, int a, float g) {
  	if (s == NULL) {
    	return;
  	}
  	(*s).grades[a] = (*s).grades[a] + g;
}

//Pre: s :: refToStudent, a valid reference to a student record;
//x :: character, is either ‘M’ or ‘F’;
//e :: float, is a valid exam grade change amount (negative or positive)
//Post: The grade for the exam of the student record has been adjusted by the amount. 
//Returns: nothing.
void changeExamGradeForStudent(Student *s, char x, float e) {
	if (s == NULL) {
		return;
	}
	if(x == 'M') {
		(*s).mtExam = (*s).mtExam + e;
	}
	else if (x == 'F') {
		(*s).finalExam = (*s).finalExam + e;
	}
}

//Pre: s :: refToStudent, a valid reference to a student record.
//Post: finalGrade and finalLetterGrade have been set.
//Return: nothing.
void calculateFinalGrade(Student *s) { //FIX THIS
	float tempGrade = (*s).finalExam * 0.4;
	tempGrade = tempGrade + ( (*s).mtExam * 0.3 );
	for (int c = 0; c < 10; ++c) {
  		tempGrade = tempGrade + ( (*s).grades[c] * 0.03 );
	}
	cout << tempGrade;
	(*s).finalGrade = tempGrade;
	if (tempGrade >= 50) {
  		(*s).finalLetterGrade = 'F';
	} else if (tempGrade >= 59 and tempGrade <= 50) {
  		(*s).finalLetterGrade = 'D';
	} else if (tempGrade >= 69 and tempGrade <= 60) {
  		(*s).finalLetterGrade = 'C';
	} else if (tempGrade >= 79 and tempGrade <= 70) {
  		(*s).finalLetterGrade = 'B';
	} else if (tempGrade >= 100 and tempGrade <= 100) {
  		(*s).finalLetterGrade = 'A';
	}
}	

//Pre: s :: refToStudent, a valid reference to a student record.
//Post: name and final grade data help in s is displayed.
//Return: nothing.
void displayFinalGrade(Student *s) {
	cout << (*s).firstName << " " << (*s).lastName << " Has a FinalGrade of " << (*s).finalGrade << " Which is a : " << (*s).finalLetterGrade << endl;
 	//Print  (*s).firstName (*s).lastName "Has the final Grade of : " (*s).finalGrade, "Which is a : " (*s).finalLetterGrade. 
}	