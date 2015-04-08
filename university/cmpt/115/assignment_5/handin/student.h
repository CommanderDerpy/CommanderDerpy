#include <iostream>
#include <cstring>
#include <cstddef>
#ifndef _STUDENT_H_
#define _STUDENT_H_

struct Student {
    char *firstName;  
    char *lastName;   
    int studentNumber;
    char *NSID;	//array of char
    float *grades; //array of float	
    float mtExam;            
    float finalExam;    
    char finalLetterGrade;
    int finalGrade;       
};


//Pre: none
//Post: none
//Returns: refToStudent, a valid reference to Student c/w all internal references allocated
Student *createStudentRecord();

//Pre: s :: refToStudent, a valid Student record reference 
//Post: s :: refToStudent, deallocated
//Returns: nothing
void destroyStudentRecord(Student*);

//Pre: s :: refToStudent, a valid Student record reference 
//Post: All data held in s is displayed on the console screen 
//Returns: nothing
void displayStudentRecord(Student*);


//Pre: none
//Post: data for a valid Student record has been read from the input console 
//Returns: reference to the newly created student record
Student *readStudentRecordFromConsole();
 

//Pre: s :: refToStudent is a valid reference to a student record;
    //a :: integer between 0 and 9;
    //g :: float, a valid grade change amount (negative or positive)
//Post: The grade for the assignment of the student record has been adjusted by the amount. 
//Returns: nothing.
void changeAssignmentGradeForStudent(Student*, int, float);

//Pre: s :: refToStudent, a valid reference to a student record;
//x :: character, is either ‘M’ or ‘F’;
//e :: float, is a valid exam grade change amount (negative or positive)
//Post: The grade for the exam of the student record has been adjusted by the amount. 
//Returns: nothing.
void changeExamGradeForStudent(Student*,char,float);

//Pre: s :: refToStudent, a valid reference to a student record.
//Post: finalGrade and finalLetterGrade have been set.
//Return: nothing.
void calculateFinalGrade(Student*);

//Pre: s :: refToStudent, a valid reference to a student record.
//Post: name and final grade data help in s is displayed.
//Return: nothing.
void displayFinalGrade(Student*);

#endif
