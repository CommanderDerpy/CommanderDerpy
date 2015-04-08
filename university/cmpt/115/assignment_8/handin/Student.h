// file: Student.h
// CMPT 115/117 model solution


#ifndef _STUDENT_H_
#define _STUDENT_H_

class Student {
private:
    char *firstName;  // string
    char *lastName;   // string
    int studentNumber; 
    char *NSID;       // string format aaannn
    float grades[10];         // array
    float mtExam;              // midterm exam grade
    float finalExam;           // final exam grade

public:
	// Algorithm createStudentRecord()
	//   Pre: none
	//   Post: none
	//   Returns: refToStudent, a valid reference to Student c/w all internal references allocated

	Student() ;

	// Algorithm destroyStudentRecord(s)
	//   Pre: s :: refToStudent, a valid Student record reference 
	//   Post: s :: refToStudent, deleted
	//   Returns: nothing


	Student(char* , char* , int , char*, float[10] , float, float) ;

	~Student() ;


	// Algorithm displayStudentRecord(s)
	//   Pre: s :: refToStudent, a valid Student record reference 
	//   Post: All data held in s is displayed on the console screen 
	//   Returns: nothing
	//
	void displayStudentRecord() ;


	// Algorithm changeAssignmentGradeForStudent(s,a,g)
	//   Pre: s :: refToStudent is a valid reference to a student record;
	//        a :: integer between 0 and 9;
	//        g :: float, a valid grade change amount (negative or positive)
	//   Post: The grade for the assignment of the student record has been adjusted by the amount. 
	//   Returns: nothing.

	void changeAssignmentGradeForStudent(int a, float g);

	// Algorithm changeExamGradeForStudent(s,x,e)
	//   Pre: s :: refToStudent, a valid reference to a student record;
	//   x :: character, is either 'M' or 'F';
	//   e :: float, is a valid exam grade change amount (negative or positive)
	//   Post: The grade for the exam of the student record has been adjusted by the amount. 
	//   Returns: nothing.

	void changeExamGradeForStudent(char x, float e) ;

	//Algorithm getGrade
	//Pre: none
	//Post: Does nothing but retrive a value
	//Return: returns the Value requested
	float getGrade(int) ;

	//Algorithm getMTD
	//Pre: none
	//Post: Does nothing but retrive a value
	//Return: returns the Value requested
	float getMT() ;

	//Algorithm getFinal
	//Pre: none
	//Post: Does nothing but retrive a value
	//Return: returns the Value requested
	float getFinal() ;

};


#endif
