/* 
 * Maximilian Gewers 
 * 11163599
 * CMPT - 115 - 02
 * CMPT - 115 - T08
 */
 

 /*
 * Point.c
 *  A simple example class
 *  The implementation 
 *
 */

#include "Point.h"
#include <iostream> 
#include <cmath> 

using namespace std;

Point::Point(float xCoord, float yCoord){ 
  x = xCoord; 
  y = yCoord; 
} 

Point::~Point(){ 
  //do nothing , but say something
  cout << "Gozer was here to destroy this Point object!" << endl;
} 


void Point::setX(float newX){ 
  x = newX; 
} 


void Point::setY(float newY){ 
  y = newY; 
} 

float Point::getX(){ 
  return x; 
} 



float Point::getY(){ 
  return y; 
} 

void Point::displacement() {
	float distance = 0;
	float x2 = pow(x,2);
	float y2 = pow(y,2);
	distance = sqrt(y2 + x2);
	cout << "the distance is : " << distance << endl;
}

// end of file
