// file: myTime.cc
// Implementation file for the myTime ADT
//

#include <iostream>
using namespace std;

#include <cstdlib>

#include "myTime.h"



// Algorithm createTime()
//   Post: a newly allocated myTime element is created
//         and initialized to be 0 hours and 0 minutes
//   Return: a pointer to the newly allocated myTime element.
myTime *createTime() {
  myTime *t;
  t = new myTime;
  t->hour = 0;
  t->minute = 0;
  return t;
}


// Algorithm destroyTime(t)
// this will deallocate the myTime data structure from the heap
//   Pre: t is a pointer to a myTime
//   Post: the space consumed by t is released
void destroyTime(myTime *t) {
  delete(t);
}

void printTime(myTime *t) {
	cout << (*t).hour << ":" << (*t).minute;
}
// Algorithm addHour(t)
// this will add one hour to the myTime pointed to by t.
//   Pre: t is a pointer to a myTime
//   Post: the myTime variable has had the hour increased by one,
//         unless it was 23, in which case, it is reset to 0.
void addHour(myTime *t) {
  (*t).hour = ((*t).hour + 1) % 24;//modulo 24 since there is 24 before reset
}

void addMinute(myTime *t) {
  (*t).minute = ((*t).minute + 1) % 60;//modulo 60 since there is 60 before reset
}
// end of file
